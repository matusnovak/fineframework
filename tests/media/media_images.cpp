#include <ffw/media.h>
#include <fstream>
#include <memory>
#define CATCH_CONFIG_MAIN
#include "../catch.hpp"


static size_t getFileSize(std::fstream& stream){
	stream.seekg(0, std::ios::end);   
	size_t size = (size_t)stream.tellg();
	stream.seekg(0, std::ios::beg);
	return size;
}

static void LoadAllPixels(ffw::ImageReader* img, unsigned char* dst){
	while(!img->eof()){
		//std::cout << "LoadAllPixels offset: " << (img->getRowOffset() * img->getStrideSize()) << " size: " << img->getStrideSize() << std::endl;
		void* ptr = &dst[img->getRowOffset() * img->getStrideSize()];
		if(!img->readRow(ptr)){
			std::cerr << "Error while reading row: " << img->getRowOffset() << std::endl;
			return;
		}
	}
}

static void SaveAllPixels(ffw::ImageWriter* img, const unsigned char* src){
	while(!img->eof()){
		const void* ptr = &src[img->getRowOffset() * img->getStrideSize()];
		if(!img->writeRow(ptr)){
			std::cerr << "Error while writing row: " << img->getRowOffset() << std::endl;
			return;
		}
	}
	img->writeFooter();
}

static float ComparePixels(unsigned char* first, unsigned char* second, size_t size){
	size_t cnt = 0;
	for(size_t i = 0; i < size; i++){
		if(std::abs(first[i] - second[i]) < 255*0.05)cnt++;
	}
	return float(cnt) / float(size);
}

template<class Loader, class Saver>
static void TestImage(
	const std::string& name,
	const std::string& ext,
	int bitDepth,
	int bitsPerPixels,
	ffw::ImageType format,
	int width,
	int height,
	int stride,
	int numOfChannels,
	float compare = 0.85
	){

	std::unique_ptr<Loader> input(new Loader);
	
	REQUIRE(input->isOpen() == false);
	REQUIRE(input->getBitDepth() == 0);
	REQUIRE(input->getBitsPerPixel() == 0);
	REQUIRE(input->getImageType() == ffw::ImageType::INVALID);
	REQUIRE(input->getHeight() == 0);
	REQUIRE(input->getWidth() == 0);
	REQUIRE(input->getStrideSize() == 0);
	REQUIRE(input->getRowOffset() == 0);
	REQUIRE(input->getNumberOfChannels() == 0);

	REQUIRE(input->open("imgs/" + name + "." + ext));

	REQUIRE(input->isOpen() == true);
	REQUIRE(input->getImageType() == format);
	REQUIRE(input->getBitDepth() == bitDepth);
	REQUIRE(input->getBitsPerPixel() == bitsPerPixels);
	REQUIRE(input->getHeight() == height);
	REQUIRE(input->getWidth() == width);
	REQUIRE(input->getStrideSize() == stride);
	REQUIRE(input->getRowOffset() == 0);
	REQUIRE(input->getNumberOfChannels() == numOfChannels);

	std::fstream raw;
	raw.open("imgs/" + name + ".raw", std::ios::in | std::ios::binary);
	REQUIRE(raw);

	size_t size = getFileSize(raw);

	//TEST_EQUAL(size, height * stride);

	std::unique_ptr<unsigned char> rawbytes(new unsigned char[size]);
	std::unique_ptr<unsigned char> imgbytes(new unsigned char[size]);

	// Read RAW image
	raw.read((char*)rawbytes.get(), size);
	raw.close();

	// Read PNG image
	LoadAllPixels(input.get(), imgbytes.get());

	// compare pixels
	float factor = ComparePixels(rawbytes.get(), imgbytes.get(), size);

	std::fstream out(name + ".tmp." + ext + ".raw", std::ios::out | std::ios::trunc | std::ios::binary);
	out.write((char*)imgbytes.get(), height * stride);
	out.close();

	// Test if two image buffers are at least 95% same
	if(factor < compare){
		std::cerr << "Similarity between " << ("imgs/" + name + ".raw") << " and " << ("imgs/" + name + "." + ext) << " is too low: " << factor << std::endl;
		REQUIRE(false);
	}

	input->close();

	REQUIRE(input->isOpen() == false);
	REQUIRE(input->getBitDepth() == 0);
	REQUIRE(input->getBitsPerPixel() == 0);
	REQUIRE(input->getImageType() == ffw::ImageType::INVALID);
	REQUIRE(input->getHeight() == 0);
	REQUIRE(input->getWidth() == 0);
	REQUIRE(input->getStrideSize() == 0);
	REQUIRE(input->getRowOffset() == 0);
	REQUIRE(input->getNumberOfChannels() == 0);

	std::unique_ptr<Saver> output(new Saver);

	REQUIRE(output->isOpen() == false);
	REQUIRE(output->getBitDepth() == 0);
	REQUIRE(output->getBitsPerPixel() == 0);
	REQUIRE(output->getImageType() == ffw::ImageType::INVALID);
	REQUIRE(output->getHeight() == 0);
	REQUIRE(output->getWidth() == 0);
	REQUIRE(output->getStrideSize() == 0);
	REQUIRE(output->getRowOffset() == 0);
	REQUIRE(output->getNumberOfChannels() == 0);

	REQUIRE(output->open(name + ".tmp." + ext, width, height, format, 100) == true);

	REQUIRE(output->isOpen() == true);
	REQUIRE(output->getImageType() == format);
	REQUIRE(output->getBitDepth() == bitDepth);
	REQUIRE(output->getBitsPerPixel() == bitsPerPixels);
	REQUIRE(output->getHeight() == height);
	REQUIRE(output->getWidth() == width);
	REQUIRE(output->getStrideSize() == stride);
	REQUIRE(output->getRowOffset() == 0);
	REQUIRE(output->getNumberOfChannels() == numOfChannels);

	// Save all pixels
	SaveAllPixels(output.get(), rawbytes.get());
	
	output->close();

	REQUIRE(output->isOpen() == false);
	REQUIRE(output->getBitDepth() == 0);
	REQUIRE(output->getBitsPerPixel() == 0);
	REQUIRE(output->getImageType() == ffw::ImageType::INVALID);
	REQUIRE(output->getHeight() == 0);
	REQUIRE(output->getWidth() == 0);
	REQUIRE(output->getStrideSize() == 0);
	REQUIRE(output->getRowOffset() == 0);
	REQUIRE(output->getNumberOfChannels() == 0);

	// Load all pixels back and compare them once more
	REQUIRE(input->open(name + ".tmp." + ext));
	REQUIRE(input->isOpen() == true);
	REQUIRE(input->getBitDepth() == bitDepth);
	REQUIRE(input->getBitsPerPixel() == bitsPerPixels);
	REQUIRE(input->getImageType() == format);
	REQUIRE(input->getHeight() == height);
	REQUIRE(input->getWidth() == width);
	REQUIRE(input->getStrideSize() == stride);
	REQUIRE(input->getRowOffset() == 0);
	REQUIRE(input->getNumberOfChannels() == numOfChannels);

	// Read PNG image
	LoadAllPixels(input.get(), imgbytes.get());

	// compare pixels
	factor = ComparePixels(rawbytes.get(), imgbytes.get(), size);

	// Test if two image buffers are at least 95% same
	if(factor < compare){
		std::cerr << "Similarity between " << ("imgs/" + name + ".raw") << " and temporary saved image is too low: " << factor << std::endl;
		REQUIRE(false);
	}

	input->close();
}

TEST_CASE("Load Image", "[readImage]"){
	unsigned char* pixels;
	int width;
	int height;
	ffw::ImageType format;

	REQUIRE(ffw::readImage("imgs/RGB_ALPHA_8888.png", (void**)&pixels, &width, &height, &format));

	REQUIRE(pixels != NULL);
	REQUIRE(width == 181);
	REQUIRE(height == 141);
	REQUIRE(format == ffw::ImageType::RGB_ALPHA_8888);

	delete[] pixels;
}

TEST_CASE("Load Image Buffer", "[readImage]"){
	ffw::ImageBuffer image;
	REQUIRE(ffw::readImage("imgs/RGB_ALPHA_8888.png", image));
	REQUIRE(image.getWidth() == 181);
	REQUIRE(image.getHeight() == 141);
	REQUIRE(image.getImageType() == ffw::ImageType::RGB_ALPHA_8888);
}

TEST_CASE("PNG_GRAYSCALE_8", "[PNG]"){
	TestImage<ffw::PngLoader, ffw::PngSaver>("GRAYSCALE_8", "png", 8, 8, ffw::ImageType::GRAYSCALE_8, 181, 141, 181 * 1, 1);
}

TEST_CASE("PNG_GRAYSCALE_16", "[PNG]"){
	TestImage<ffw::PngLoader, ffw::PngSaver>("GRAYSCALE_16", "png", 16, 16, ffw::ImageType::GRAYSCALE_16, 181, 141, 181 * 2, 1);
}

TEST_CASE("PNG_GRAYSCALE_ALPHA_8", "[PNG]"){
	TestImage<ffw::PngLoader, ffw::PngSaver>("GRAYSCALE_ALPHA_8", "png", 8, 16, ffw::ImageType::GRAYSCALE_ALPHA_8, 181, 141, 181 * 2, 2);
}

TEST_CASE("PNG_GRAYSCALE_ALPHA_16", "[PNG]"){
	TestImage<ffw::PngLoader, ffw::PngSaver>("GRAYSCALE_ALPHA_16", "png", 16, 32, ffw::ImageType::GRAYSCALE_ALPHA_16, 181, 141, 181 * 4, 2);
}

TEST_CASE("PNG_RGB_888", "[PNG]"){
	TestImage<ffw::PngLoader, ffw::PngSaver>("RGB_888", "png", 8, 24, ffw::ImageType::RGB_888, 181, 141, 181 * 3, 3);
}

TEST_CASE("PNG_RGB_161616", "[PNG]"){
	TestImage<ffw::PngLoader, ffw::PngSaver>("RGB_161616", "png", 16, 48, ffw::ImageType::RGB_161616, 181, 141, 181 * 6, 3);
}

TEST_CASE("PNG_RGB_ALPHA_8888", "[PNG]"){
	TestImage<ffw::PngLoader, ffw::PngSaver>("RGB_ALPHA_8888", "png", 8, 32, ffw::ImageType::RGB_ALPHA_8888, 181, 141, 181 * 4, 4);
}

TEST_CASE("PNG_RGB_ALPHA_16161616", "[PNG]"){
	TestImage<ffw::PngLoader, ffw::PngSaver>("RGB_ALPHA_16161616", "png", 16, 64, ffw::ImageType::RGB_ALPHA_16161616, 181, 141, 181 * 8, 4);
}

TEST_CASE("JPG_GRAYSCALE_8", "[JPG]"){
	TestImage<ffw::JpgLoader, ffw::JpgSaver>("GRAYSCALE_8", "jpg", 8, 8, ffw::ImageType::GRAYSCALE_8, 181, 141, 181 * 1, 1);
}

TEST_CASE("JPG_RGB_888", "[JPG]"){
	TestImage<ffw::JpgLoader, ffw::JpgSaver>("RGB_888", "jpg", 8, 24, ffw::ImageType::RGB_888, 181, 141, 181 * 3, 3);
}

TEST_CASE("BMP_BITMAP_1", "[BMP]"){
	TestImage<ffw::BmpLoader, ffw::BmpSaver>("BITMAP_1", "bmp", 1, 1, ffw::ImageType::BITMAP_1, 181, 141, 23, 1);
}

TEST_CASE("BMP_GRAYSCALE_4", "[BMP]"){
	TestImage<ffw::BmpLoader, ffw::BmpSaver>("GRAYSCALE_4", "bmp", 4, 4, ffw::ImageType::GRAYSCALE_4, 181, 141, 91, 1);
}

TEST_CASE("BMP_GRAYSCALE_8", "[BMP]"){
	TestImage<ffw::BmpLoader, ffw::BmpSaver>("GRAYSCALE_8", "bmp", 8, 8, ffw::ImageType::GRAYSCALE_8, 181, 141, 181 * 1, 1);
}

TEST_CASE("BMP_RGB_888", "[BMP]"){
	TestImage<ffw::BmpLoader, ffw::BmpSaver>("RGB_888", "bmp", 8, 24, ffw::ImageType::RGB_888, 181, 141, 181 * 3, 3);
}

TEST_CASE("BMP_RGB_ALPHA_8888", "[BMP]"){
	TestImage<ffw::BmpLoader, ffw::BmpSaver>("RGB_ALPHA_8888", "bmp", 8, 32, ffw::ImageType::RGB_ALPHA_8888, 181, 141, 181 * 4, 4, 0.75);
}

TEST_CASE("PBM_GRAYSCALE_8", "[PBM]"){
	TestImage<ffw::PbmLoader, ffw::PbmSaver>("GRAYSCALE_8", "pbm", 8, 8, ffw::ImageType::GRAYSCALE_8, 181, 141, 181 * 1, 1);
}

TEST_CASE("PBM_GRAYSCALE_16", "[PBM]"){
	TestImage<ffw::PbmLoader, ffw::PbmSaver>("GRAYSCALE_16", "pbm", 16, 16, ffw::ImageType::GRAYSCALE_16, 181, 141, 181 * 2, 1);
}

TEST_CASE("PBM_GRAYSCALE_32", "[PBM]"){
	TestImage<ffw::PbmLoader, ffw::PbmSaver>("GRAYSCALE_32", "pbm", 32, 32, ffw::ImageType::GRAYSCALE_32, 181, 141, 181 * 4, 1);
}

TEST_CASE("PBM_RGB_888", "[PBM]"){
	TestImage<ffw::PbmLoader, ffw::PbmSaver>("RGB_888", "pbm", 8, 24, ffw::ImageType::RGB_888, 181, 141, 181 * 3, 3);
}

TEST_CASE("PBM_RGB_161616", "[PBM]"){
	TestImage<ffw::PbmLoader, ffw::PbmSaver>("RGB_161616", "pbm", 16, 48, ffw::ImageType::RGB_161616, 181, 141, 181 * 6, 3);
}

TEST_CASE("PBM_RGB_323232", "[PBM]"){
	TestImage<ffw::PbmLoader, ffw::PbmSaver>("RGB_323232", "pbm", 32, 96, ffw::ImageType::RGB_323232, 181, 141, 181 * 12, 3);
}

TEST_CASE("TGA_GRAYSCALE_8", "[TGA]"){
	TestImage<ffw::TgaLoader, ffw::TgaSaver>("GRAYSCALE_8", "tga", 8, 8, ffw::ImageType::GRAYSCALE_8, 181, 141, 181 * 1, 1);
}

TEST_CASE("TGA_RGB_ALPHA_5551", "[TGA]"){
	TestImage<ffw::TgaLoader, ffw::TgaSaver>("RGB_ALPHA_5551", "tga", 5, 16, ffw::ImageType::RGB_ALPHA_5551, 181, 141, 181 * 2, 4);
}

TEST_CASE("TGA_RGB_888", "[TGA]"){
	TestImage<ffw::TgaLoader, ffw::TgaSaver>("RGB_888", "tga", 8, 24, ffw::ImageType::RGB_888, 181, 141, 181 * 3, 3);
}

TEST_CASE("TGA_RGB_ALPHA_8888", "[TGA]"){
	TestImage<ffw::TgaLoader, ffw::TgaSaver>("RGB_ALPHA_8888", "tga", 8, 32, ffw::ImageType::RGB_ALPHA_8888, 181, 141, 181 * 4, 4);
}

TEST_CASE("TIF_GRAYSCALE_8", "[TIF]"){
	TestImage<ffw::TifLoader, ffw::TifSaver>("GRAYSCALE_8", "tif", 8, 8, ffw::ImageType::GRAYSCALE_8, 181, 141, 181 * 1, 1);
}

TEST_CASE("TIF_GRAYSCALE_16", "[TIF]"){
	TestImage<ffw::TifLoader, ffw::TifSaver>("GRAYSCALE_16", "tif", 16, 16, ffw::ImageType::GRAYSCALE_16, 181, 141, 181 * 2, 1);
}

TEST_CASE("TIF_GRAYSCALE_32", "[TIF]"){
	TestImage<ffw::TifLoader, ffw::TifSaver>("GRAYSCALE_32", "tif", 32, 32, ffw::ImageType::GRAYSCALE_32, 181, 141, 181 * 4, 1);
}

TEST_CASE("TIF_GRAYSCALE_ALPHA_8", "[TIF]"){
	TestImage<ffw::TifLoader, ffw::TifSaver>("GRAYSCALE_ALPHA_8", "tif", 8, 16, ffw::ImageType::GRAYSCALE_ALPHA_8, 181, 141, 181 * 2, 2, 0.10f);
}

TEST_CASE("TIF_GRAYSCALE_ALPHA_16", "[TIF]"){
	TestImage<ffw::TifLoader, ffw::TifSaver>("GRAYSCALE_ALPHA_16", "tif", 16, 32, ffw::ImageType::GRAYSCALE_ALPHA_16, 181, 141, 181 * 4, 2, 0.10f);
}

/*TEST_CASE(TIF_GRAYSCALE_ALPHA_32){
	TestImage<ffw::TifLoader, ffw::TifSaver>("GRAYSCALE_ALPHA_32", "tif", 32, 64, ffw::ImageType::GRAYSCALE_ALPHA_32, 181, 141, 181 * 8, 2);
}*/

TEST_CASE("TIF_RGB_888", "[TIF]"){
	TestImage<ffw::TifLoader, ffw::TifSaver>("RGB_888", "tif", 8, 24, ffw::ImageType::RGB_888, 181, 141, 181 * 3, 3);
}

TEST_CASE("TIF_RGB_161616", "[TIF]"){
	TestImage<ffw::TifLoader, ffw::TifSaver>("RGB_161616", "tif", 16, 48, ffw::ImageType::RGB_161616, 181, 141, 181 * 6, 3);
}

TEST_CASE("TIF_RGB_323232", "[TIF]"){
	TestImage<ffw::TifLoader, ffw::TifSaver>("RGB_323232", "tif", 32, 96, ffw::ImageType::RGB_323232, 181, 141, 181 * 12, 3);
}

TEST_CASE("TIF_RGB_ALPHA_8888", "[TIF]"){
	TestImage<ffw::TifLoader, ffw::TifSaver>("RGB_ALPHA_8888", "tif", 8, 32, ffw::ImageType::RGB_ALPHA_8888, 181, 141, 181 * 4, 4, 0.60f);
}

TEST_CASE("TIF_RGB_ALPHA_16161616", "[TIF]"){
	TestImage<ffw::TifLoader, ffw::TifSaver>("RGB_ALPHA_16161616", "tif", 16, 64, ffw::ImageType::RGB_ALPHA_16161616, 181, 141, 181 * 8, 4, 0.60f);
}

TEST_CASE("TIF_RGB_ALPHA_32323232", "[TIF]"){
	TestImage<ffw::TifLoader, ffw::TifSaver>("RGB_ALPHA_32323232", "tif", 32, 128, ffw::ImageType::RGB_ALPHA_32323232, 181, 141, 181 * 16, 4, 0.60f);
}