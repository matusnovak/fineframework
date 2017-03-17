#include <ffw/graphics.h>
#include <fstream>

#define TEXTURE_SIZE (512*512*3)
static unsigned char pixels[TEXTURE_SIZE];

///=============================================================================
class App: public ffw::GLFWRenderWindow {
public:
    App(){
	}

    ~App(){
	}

    bool setup() override {
		std::cout << "Window setup!" << std::endl;

		if (!font.createFromFile(this, "FreeSans.ttf", 16, 72)) {
			std::cerr << "Failed to create font from: \'FreeSans.ttf\' File is missing?" << std::endl;
			return false;
		}

		std::ifstream input("grid-rgb8.raw", std::ios::in | std::ios::binary);
		if (!input) {
			std::cerr << "Failed to open 'grid-rgb8.raw' File is missing?" << std::endl;
			return false;
		}

		if(!texture.create(this, 512, 512, GL_RGB8, GL_RGB, GL_UNSIGNED_BYTE)) {
			std::cerr << "Failed to create texture!" << std::endl;
			return false;
		}

		// We expect 512 * 512 * 3 bytes, we should check for the file size first.
		// For the purpose of the example we are not going to do checks.
		input.read((char*)pixels, TEXTURE_SIZE);
		input.close();

		texture.setPixels(0, 0, 0, 512, 512, pixels);

		// Required for font blending
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

		// Background color
		glClearColor(0.3f, 0.3f, 0.3f, 1.0f);

		return true;
	}

    void render() override {
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		this->setDrawColor(ffw::rgb(0xFFFFFF)); // White color

		// In OpenGL, textures are mirrored vertically
		this->drawString(10, 5, &font, "Original image:");
		this->drawTexture2D(10, 30, 256, 256, &texture);

		// Zoomed image
		this->drawString(10, 291, &font, "Zoomed:");
		if(mousePos.x >= 10 && mousePos.x <= 266 && mousePos.y >= 30 && mousePos.y <= 286) {
			ffw::Vec2i offset;
			offset.x = ffw::remap(mousePos.x, 10, 266, 0, 512);
			offset.y = ffw::remap(mousePos.y, 30, 286, 0, 512);
			this->drawTexture2DSub(10, 316, 256, 256, &texture, offset.x - 16, offset.y - 16, 32, 32);
		} 
		else {
			this->drawString(10, 291 + 128, &font, "Hover over original\nimage for zoom");
		}

		// [256, 256] subsection at pos [0, 0]
		this->drawString(276, 5, &font, "Left top corner:");
		this->drawTexture2DSubMirror(276, 30, 256, 256, &texture, 0, 0, 256, 256, false, false);

		// [256, 256] subsection at pos [256, 0]
		this->drawString(542, 5, &font, "Right top corner:");
		this->drawTexture2DSubMirror(542, 30, 256, 256, &texture, 256, 0, 256, 256, false, false);

		// [256, 256] subsection at pos [0, 256] mirrored horizontally
		this->drawString(276, 291, &font, "Left bottom mirrored:");
		this->drawTexture2DSubMirror(276, 316, 256, 256, &texture, 0, 256, 256, 256, true, false);

		// [256, 256] subsection at pos [256, 256] mirrored vertically
		this->drawString(542, 291, &font, "Right bottom mirrored:");
		this->drawTexture2DSubMirror(542, 316, 256, 256, &texture, 256, 256, 256, 256, false, true);
	}

    void close() override {
		texture.destroy();
	}

    void textInputEvent(unsigned int C) override {
	}

    void keyPressedEvent(ffw::Key key, ffw::Mode mode) override {
	}

    void mouseMovedEvent(int mousex, int mousey) override {
		mousePos.set(mousex, mousey);
	}

    void mouseScrollEvent(int scroll) override {
	}

    void mouseButtonEvent(ffw::MouseButton button, ffw::Mode mode) override {
	}

    void windowResizedEvent(int width, int height) override {
	}

    void windowMovedEvent(int windowx, int windowy) override {
	}

    void windowFocusEvent(bool focus) override {
	}

    void windowCloseEvent() override {
		this->shouldClose(true);
	}

    void filesDroppedEvent(std::vector<std::string> filelist) override {
	}
private:
	ffw::TrueTypeFont font;
	ffw::Texture2D texture;
	ffw::Vec2i mousePos;
};

///=============================================================================
int main(int argc, char *argv[]){
	// Instance to our app class
	App app;

	// set arguments
	ffw::GLFWRenderWindowArgs args;
	args.size.set(800, 600);
	args.title = "Texture Subsection Example";

	// create window
	if(!app.create(args, NULL)){
		std::cerr << "Failed to create window!" << std::endl;
		return 1;
	}

	// Run setup
	if(!app.setup()){
		std::cerr << "Failed to setup window!" << std::endl;
		return 1;
	}

	// The main window loop
	while(app.shouldRender()){
		app.renderFrame();
		app.poolEvents();
	}

	// destroy window, this will delete all graphics data used by the window.
	// Must be called after the setup and before the graphics
	// is terminated
	app.destroy();
	return 0;
}
