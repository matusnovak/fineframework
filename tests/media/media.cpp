#include "../units.h"
#include <ffw/media.h>
#include <fstream>
#include <memory>

static size_t GetFileSize(std::fstream& stream){
	stream.seekg(0, std::ios::end);   
	size_t size = (size_t)stream.tellg();
	stream.seekg(0, std::ios::beg);
	return size;
}

static void LoadAllPixels(ffw::ImageReader* img, unsigned char* dst){
	while(!img->Eof()){
		//std::cout << "LoadAllPixels offset: " << (img->GetRowOffset() * img->GetStrideSize()) << " size: " << img->GetStrideSize() << std::endl;
		void* ptr = &dst[img->GetRowOffset() * img->GetStrideSize()];
		if(!img->ReadRow(ptr)){
			std::cerr << "Error while reading row: " << img->GetRowOffset() << std::endl;
			return;
		}
	}
}

static void SaveAllPixels(ffw::ImageWriter* img, const unsigned char* src){
	while(!img->Eof()){
		const void* ptr = &src[img->GetRowOffset() * img->GetStrideSize()];
		if(!img->WriteRow(ptr)){
			std::cerr << "Error while writing row: " << img->GetRowOffset() << std::endl;
			return;
		}
	}
	img->WriteFooter();
}

static float ComparePixels(unsigned char* first, unsigned char* second, size_t size){
	size_t count = 0;
	for(size_t i = 0; i < size; i++){
		if(std::abs(first[i] - second[i]) < 255*0.05)count++;
	}
	return float(count) / float(size);
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
	
	TEST_EQUAL(input->IsOpen(), false);
	TEST_EQUAL(input->GetBitDepth(), 0);
	TEST_EQUAL(input->GetBitsPerPixel(), 0);
	TEST_EQUAL(input->GetFormat(), ffw::ImageType::INVALID);
	TEST_EQUAL(input->GetHeight(), 0);
	TEST_EQUAL(input->GetWidth(), 0);
	TEST_EQUAL(input->GetStrideSize(), 0);
	TEST_EQUAL(input->GetRowOffset(), 0);
	TEST_EQUAL(input->GetNumberOfChannels(), 0);

	TEST_TRUE(input->Open("imgs/" + name + "." + ext));

	TEST_EQUAL(input->IsOpen(), true);
	TEST_EQUAL(input->GetFormat(), format);
	TEST_EQUAL(input->GetBitDepth(), bitDepth);
	TEST_EQUAL(input->GetBitsPerPixel(), bitsPerPixels);
	TEST_EQUAL(input->GetHeight(), height);
	TEST_EQUAL(input->GetWidth(), width);
	TEST_EQUAL(input->GetStrideSize(), stride);
	TEST_EQUAL(input->GetRowOffset(), 0);
	TEST_EQUAL(input->GetNumberOfChannels(), numOfChannels);

	std::fstream raw;
	raw.open("imgs/" + name + ".raw", std::ios::in | std::ios::binary);
	if(!raw)TEST_FAIL;

	size_t size = GetFileSize(raw);

	//TEST_EQUAL(size, height * stride);

	std::unique_ptr<unsigned char> rawbytes(new unsigned char[size]);
	std::unique_ptr<unsigned char> imgbytes(new unsigned char[size]);

	// Read RAW image
	raw.read((char*)rawbytes.get(), size);
	raw.close();

	// Read PNG image
	LoadAllPixels(input.get(), imgbytes.get());

	// Compare pixels
	float factor = ComparePixels(rawbytes.get(), imgbytes.get(), size);

	std::fstream out(name + ".tmp." + ext + ".raw", std::ios::out | std::ios::trunc | std::ios::binary);
	out.write((char*)imgbytes.get(), height * stride);
	out.close();

	// Test if two image buffers are at least 95% same
	if(factor < compare){
		std::cerr << "Similarity between " << ("imgs/" + name + ".raw") << " and " << ("imgs/" + name + "." + ext) << " is too low: " << factor << std::endl;
		TEST_FAIL;
	}

	input->Close();

	TEST_EQUAL(input->IsOpen(), false);
	TEST_EQUAL(input->GetBitDepth(), 0);
	TEST_EQUAL(input->GetBitsPerPixel(), 0);
	TEST_EQUAL(input->GetFormat(), ffw::ImageType::INVALID);
	TEST_EQUAL(input->GetHeight(), 0);
	TEST_EQUAL(input->GetWidth(), 0);
	TEST_EQUAL(input->GetStrideSize(), 0);
	TEST_EQUAL(input->GetRowOffset(), 0);
	TEST_EQUAL(input->GetNumberOfChannels(), 0);

	std::unique_ptr<Saver> output(new Saver);

	TEST_EQUAL(output->IsOpen(), false);
	TEST_EQUAL(output->GetBitDepth(), 0);
	TEST_EQUAL(output->GetBitsPerPixel(), 0);
	TEST_EQUAL(output->GetFormat(), ffw::ImageType::INVALID);
	TEST_EQUAL(output->GetHeight(), 0);
	TEST_EQUAL(output->GetWidth(), 0);
	TEST_EQUAL(output->GetStrideSize(), 0);
	TEST_EQUAL(output->GetRowOffset(), 0);
	TEST_EQUAL(output->GetNumberOfChannels(), 0);

	TEST_TRUE(output->Open(name + ".tmp." + ext, width, height, format, 100) == true);

	TEST_EQUAL(output->IsOpen(), true);
	TEST_EQUAL(output->GetFormat(), format);
	TEST_EQUAL(output->GetBitDepth(), bitDepth);
	TEST_EQUAL(output->GetBitsPerPixel(), bitsPerPixels);
	TEST_EQUAL(output->GetHeight(), height);
	TEST_EQUAL(output->GetWidth(), width);
	TEST_EQUAL(output->GetStrideSize(), stride);
	TEST_EQUAL(output->GetRowOffset(), 0);
	TEST_EQUAL(output->GetNumberOfChannels(), numOfChannels);

	// Save all pixels
	SaveAllPixels(output.get(), rawbytes.get());
	
	output->Close();

	TEST_EQUAL(output->IsOpen(), false);
	TEST_EQUAL(output->GetBitDepth(), 0);
	TEST_EQUAL(output->GetBitsPerPixel(), 0);
	TEST_EQUAL(output->GetFormat(), ffw::ImageType::INVALID);
	TEST_EQUAL(output->GetHeight(), 0);
	TEST_EQUAL(output->GetWidth(), 0);
	TEST_EQUAL(output->GetStrideSize(), 0);
	TEST_EQUAL(output->GetRowOffset(), 0);
	TEST_EQUAL(output->GetNumberOfChannels(), 0);

	// Load all pixels back and compare them once more
	TEST_TRUE(input->Open(name + ".tmp." + ext));
	TEST_EQUAL(input->IsOpen(), true);
	TEST_EQUAL(input->GetBitDepth(), bitDepth);
	TEST_EQUAL(input->GetBitsPerPixel(), bitsPerPixels);
	TEST_EQUAL(input->GetFormat(), format);
	TEST_EQUAL(input->GetHeight(), height);
	TEST_EQUAL(input->GetWidth(), width);
	TEST_EQUAL(input->GetStrideSize(), stride);
	TEST_EQUAL(input->GetRowOffset(), 0);
	TEST_EQUAL(input->GetNumberOfChannels(), numOfChannels);

	// Read PNG image
	LoadAllPixels(input.get(), imgbytes.get());

	// Compare pixels
	factor = ComparePixels(rawbytes.get(), imgbytes.get(), size);

	// Test if two image buffers are at least 95% same
	if(factor < compare){
		std::cerr << "Similarity between " << ("imgs/" + name + ".raw") << " and temporary saved image is too low: " << factor << std::endl;
		TEST_FAIL;
	}

	input->Close();
}

TEST(ImageIO, LoadImage){
	unsigned char* pixels;
	int width;
	int height;
	ffw::ImageType format;

	TEST_TRUE(ffw::ReadImage("imgs/RGB_ALPHA_8888.png", (void**)&pixels, &width, &height, &format));

	TEST_TRUE(pixels != NULL);
	TEST_EQUAL(width, 181);
	TEST_EQUAL(height, 141);
	TEST_EQUAL(format, ffw::ImageType::RGB_ALPHA_8888);

	delete[] pixels;
}

TEST(ImageIO, LoadImageBuffer){
	ffw::ImageBuffer image;
	TEST_FALSE(ffw::ReadImage("imgs/RGB_ALPHA_8888.png", NULL));

	TEST_TRUE(ffw::ReadImage("imgs/RGB_ALPHA_8888.png", &image));
	TEST_EQUAL(image.GetWidth(), 181);
	TEST_EQUAL(image.GetHeight(), 141);
	TEST_EQUAL(image.GetFormat(), ffw::ImageType::RGB_ALPHA_8888);
}

TEST(ImageIO, PNG_GRAYSCALE_8){
	TestImage<ffw::PngLoader, ffw::PngSaver>("GRAYSCALE_8", "png", 8, 8, ffw::ImageType::GRAYSCALE_8, 181, 141, 181 * 1, 1);
}

TEST(ImageIO, PNG_GRAYSCALE_16){
	TestImage<ffw::PngLoader, ffw::PngSaver>("GRAYSCALE_16", "png", 16, 16, ffw::ImageType::GRAYSCALE_16, 181, 141, 181 * 2, 1);
}

TEST(ImageIO, PNG_GRAYSCALE_ALPHA_8){
	TestImage<ffw::PngLoader, ffw::PngSaver>("GRAYSCALE_ALPHA_8", "png", 8, 16, ffw::ImageType::GRAYSCALE_ALPHA_8, 181, 141, 181 * 2, 2);
}

TEST(ImageIO, PNG_GRAYSCALE_ALPHA_16){
	TestImage<ffw::PngLoader, ffw::PngSaver>("GRAYSCALE_ALPHA_16", "png", 16, 32, ffw::ImageType::GRAYSCALE_ALPHA_16, 181, 141, 181 * 4, 2);
}

TEST(ImageIO, PNG_RGB_888){
	TestImage<ffw::PngLoader, ffw::PngSaver>("RGB_888", "png", 8, 24, ffw::ImageType::RGB_888, 181, 141, 181 * 3, 3);
}

TEST(ImageIO, PNG_RGB_161616){
	TestImage<ffw::PngLoader, ffw::PngSaver>("RGB_161616", "png", 16, 48, ffw::ImageType::RGB_161616, 181, 141, 181 * 6, 3);
}

TEST(ImageIO, PNG_RGB_ALPHA_8888){
	TestImage<ffw::PngLoader, ffw::PngSaver>("RGB_ALPHA_8888", "png", 8, 32, ffw::ImageType::RGB_ALPHA_8888, 181, 141, 181 * 4, 4);
}

TEST(ImageIO, PNG_RGB_ALPHA_16161616){
	TestImage<ffw::PngLoader, ffw::PngSaver>("RGB_ALPHA_16161616", "png", 16, 64, ffw::ImageType::RGB_ALPHA_16161616, 181, 141, 181 * 8, 4);
}

TEST(ImageIO, JPG_GRAYSCALE_8){
	TestImage<ffw::JpgLoader, ffw::JpgSaver>("GRAYSCALE_8", "jpg", 8, 8, ffw::ImageType::GRAYSCALE_8, 181, 141, 181 * 1, 1);
}

TEST(ImageIO, JPG_RGB_888){
	TestImage<ffw::JpgLoader, ffw::JpgSaver>("RGB_888", "jpg", 8, 24, ffw::ImageType::RGB_888, 181, 141, 181 * 3, 3);
}

TEST(ImageIO, BMP_BITMAP_1){
	TestImage<ffw::BmpLoader, ffw::BmpSaver>("BITMAP_1", "bmp", 1, 1, ffw::ImageType::BITMAP_1, 181, 141, 23, 1);
}

TEST(ImageIO, BMP_GRAYSCALE_4){
	TestImage<ffw::BmpLoader, ffw::BmpSaver>("GRAYSCALE_4", "bmp", 4, 4, ffw::ImageType::GRAYSCALE_4, 181, 141, 91, 1);
}

TEST(ImageIO, BMP_GRAYSCALE_8){
	TestImage<ffw::BmpLoader, ffw::BmpSaver>("GRAYSCALE_8", "bmp", 8, 8, ffw::ImageType::GRAYSCALE_8, 181, 141, 181 * 1, 1);
}

TEST(ImageIO, BMP_RGB_888){
	TestImage<ffw::BmpLoader, ffw::BmpSaver>("RGB_888", "bmp", 8, 24, ffw::ImageType::RGB_888, 181, 141, 181 * 3, 3);
}

TEST(ImageIO, BMP_RGB_ALPHA_8888){
	TestImage<ffw::BmpLoader, ffw::BmpSaver>("RGB_ALPHA_8888", "bmp", 8, 32, ffw::ImageType::RGB_ALPHA_8888, 181, 141, 181 * 4, 4, 0.75);
}

TEST(ImageIO, PBM_GRAYSCALE_8){
	TestImage<ffw::PbmLoader, ffw::PbmSaver>("GRAYSCALE_8", "pbm", 8, 8, ffw::ImageType::GRAYSCALE_8, 181, 141, 181 * 1, 1);
}

TEST(ImageIO, PBM_GRAYSCALE_16){
	TestImage<ffw::PbmLoader, ffw::PbmSaver>("GRAYSCALE_16", "pbm", 16, 16, ffw::ImageType::GRAYSCALE_16, 181, 141, 181 * 2, 1);
}

TEST(ImageIO, PBM_GRAYSCALE_32){
	TestImage<ffw::PbmLoader, ffw::PbmSaver>("GRAYSCALE_32", "pbm", 32, 32, ffw::ImageType::GRAYSCALE_32, 181, 141, 181 * 4, 1);
}

TEST(ImageIO, PBM_RGB_888){
	TestImage<ffw::PbmLoader, ffw::PbmSaver>("RGB_888", "pbm", 8, 24, ffw::ImageType::RGB_888, 181, 141, 181 * 3, 3);
}

TEST(ImageIO, PBM_RGB_161616){
	TestImage<ffw::PbmLoader, ffw::PbmSaver>("RGB_161616", "pbm", 16, 48, ffw::ImageType::RGB_161616, 181, 141, 181 * 6, 3);
}

TEST(ImageIO, PBM_RGB_323232){
	TestImage<ffw::PbmLoader, ffw::PbmSaver>("RGB_323232", "pbm", 32, 96, ffw::ImageType::RGB_323232, 181, 141, 181 * 12, 3);
}

TEST(ImageIO, TGA_GRAYSCALE_8){
	TestImage<ffw::TgaLoader, ffw::TgaSaver>("GRAYSCALE_8", "tga", 8, 8, ffw::ImageType::GRAYSCALE_8, 181, 141, 181 * 1, 1);
}

TEST(ImageIO, TGA_RGB_ALPHA_5551){
	TestImage<ffw::TgaLoader, ffw::TgaSaver>("RGB_ALPHA_5551", "tga", 5, 16, ffw::ImageType::RGB_ALPHA_5551, 181, 141, 181 * 2, 4);
}

TEST(ImageIO, TGA_RGB_888){
	TestImage<ffw::TgaLoader, ffw::TgaSaver>("RGB_888", "tga", 8, 24, ffw::ImageType::RGB_888, 181, 141, 181 * 3, 3);
}

TEST(ImageIO, TGA_RGB_ALPHA_8888){
	TestImage<ffw::TgaLoader, ffw::TgaSaver>("RGB_ALPHA_8888", "tga", 8, 32, ffw::ImageType::RGB_ALPHA_8888, 181, 141, 181 * 4, 4);
}

TEST(ImageIO, TIF_GRAYSCALE_8){
	TestImage<ffw::TifLoader, ffw::TifSaver>("GRAYSCALE_8", "tif", 8, 8, ffw::ImageType::GRAYSCALE_8, 181, 141, 181 * 1, 1);
}

TEST(ImageIO, TIF_GRAYSCALE_16){
	TestImage<ffw::TifLoader, ffw::TifSaver>("GRAYSCALE_16", "tif", 16, 16, ffw::ImageType::GRAYSCALE_16, 181, 141, 181 * 2, 1);
}

TEST(ImageIO, TIF_GRAYSCALE_32){
	TestImage<ffw::TifLoader, ffw::TifSaver>("GRAYSCALE_32", "tif", 32, 32, ffw::ImageType::GRAYSCALE_32, 181, 141, 181 * 4, 1);
}

TEST(ImageIO, TIF_GRAYSCALE_ALPHA_8){
	TestImage<ffw::TifLoader, ffw::TifSaver>("GRAYSCALE_ALPHA_8", "tif", 8, 16, ffw::ImageType::GRAYSCALE_ALPHA_8, 181, 141, 181 * 2, 2, 0.10);
}

TEST(ImageIO, TIF_GRAYSCALE_ALPHA_16){
	TestImage<ffw::TifLoader, ffw::TifSaver>("GRAYSCALE_ALPHA_16", "tif", 16, 32, ffw::ImageType::GRAYSCALE_ALPHA_16, 181, 141, 181 * 4, 2, 0.10);
}

/*TEST(ImageIO, TIF_GRAYSCALE_ALPHA_32){
	TestImage<ffw::TifLoader, ffw::TifSaver>("GRAYSCALE_ALPHA_32", "tif", 32, 64, ffw::ImageType::GRAYSCALE_ALPHA_32, 181, 141, 181 * 8, 2);
}*/

TEST(ImageIO, TIF_RGB_888){
	TestImage<ffw::TifLoader, ffw::TifSaver>("RGB_888", "tif", 8, 24, ffw::ImageType::RGB_888, 181, 141, 181 * 3, 3);
}

TEST(ImageIO, TIF_RGB_161616){
	TestImage<ffw::TifLoader, ffw::TifSaver>("RGB_161616", "tif", 16, 48, ffw::ImageType::RGB_161616, 181, 141, 181 * 6, 3);
}

TEST(ImageIO, TIF_RGB_323232){
	TestImage<ffw::TifLoader, ffw::TifSaver>("RGB_323232", "tif", 32, 96, ffw::ImageType::RGB_323232, 181, 141, 181 * 12, 3);
}

TEST(ImageIO, TIF_RGB_ALPHA_8888){
	TestImage<ffw::TifLoader, ffw::TifSaver>("RGB_ALPHA_8888", "tif", 8, 32, ffw::ImageType::RGB_ALPHA_8888, 181, 141, 181 * 4, 4, 0.60);
}

TEST(ImageIO, TIF_RGB_ALPHA_16161616){
	TestImage<ffw::TifLoader, ffw::TifSaver>("RGB_ALPHA_16161616", "tif", 16, 64, ffw::ImageType::RGB_ALPHA_16161616, 181, 141, 181 * 8, 4, 0.60);
}

TEST(ImageIO, TIF_RGB_ALPHA_32323232){
	TestImage<ffw::TifLoader, ffw::TifSaver>("RGB_ALPHA_32323232", "tif", 32, 128, ffw::ImageType::RGB_ALPHA_32323232, 181, 141, 181 * 16, 4, 0.60);
}