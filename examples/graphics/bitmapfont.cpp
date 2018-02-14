#include <ffw/graphics.h>
#include <fstream>
#include <cstring>
#define NUM_OF_LINES (8)
#define TEXTURE_SIZE (512*512*4)

// There values are extracted from the image ubuntu-mono-rgba8.raw
#define CHAR_WIDTH 24
#define CHAR_HEIGHT 30
#define CHAR_ADVANCE 16
#define CHAR_BEARING 23

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

        // Load ubuntu-mono-rgba8.raw image
        // We use *.RAW format for the purpose of the example
        std::ifstream input("ubuntu-mono-rgba8.raw", std::ios::in | std::ios::binary);
        if(!input) {
            std::cerr << "Failed to open 'ubuntu-mono-rgba8.raw' File is missing?" << std::endl;
            return false;
        }

        // Check file size
        input.seekg(0, std::ios::end);
        size_t size = (size_t)input.tellg();
        if(size != TEXTURE_SIZE) {
            std::cerr << "File 'ubuntu-mono-rgba8.raw' has wrong size! Expected 512x512 pixels RGB_ALPHA_8888!" << std::endl;
            return false;
        }

        memset(pixels, 0xCC, TEXTURE_SIZE);

        // Load pixels
        input.seekg(0, std::ios::beg);
        input.read((char*)pixels, TEXTURE_SIZE);

        // Load font 28pt at 72 DPI
        // Chars starting from 0 to 255
        if(!font.createFromData(pixels, 512, 512, ffw::ImageType::RGB_ALPHA_8888, 28, 72, 0, 255)){
            std::cerr << "Failed to create font from pixel data!" << std::endl;
            return false;
        }

        // Fill data
        // Since the font is mono (Ubuntu Mono Regular) then all characters have the same data!
        // It is up to the user how the data is filled. There is no prefered container/data set!
        for(int i = 0; i < 256; i++) {
            int y = i / 16;
            int x = i - (y * 16);
            auto chr = ffw::BitmapFont::Char();
            chr.x = x * 32;
            chr.y = y * 32;
            chr.width = CHAR_WIDTH;
            chr.height = CHAR_HEIGHT;
            chr.advance = CHAR_ADVANCE;
            chr.bearingX = 0;
            chr.bearingY = CHAR_BEARING;
            font.setCharData((wchar_t)i, chr);
        }

        if(!font.updateBuffer()) {
            std::cerr << "Finalizing font data failed!" << std::endl;
            return false;
        }

        // Required for font blending
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

        // Background color
        glClearColor(0.9f, 0.9f, 0.9f, 1.0f);

        return true;
    }

    void render() override {
        this->beginFrame();

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        int height = 0;
        for(int i = 0; i < NUM_OF_LINES; i++){
            this->setDrawColor(ffw::rgb(255 - i*(256 / NUM_OF_LINES), i*(256 / NUM_OF_LINES), 0));
            this->drawString(10, 10 + height, &font, "Lorem ipsum dolor sit amet, consectetur adipiscing elit.");
            // Line height is a simple formula of (height * weight)
            // wehre height is the height of the font
            // and weight is line spacing (1.0 and more)
            height += int(font.getSizePixels() * 1.5f);
        }

        this->endFrame();
    }

    void close() override {
        std::cout << "Window is closing!" << std::endl;
        font.destroy();
    }

    void windowCloseEvent() override {
        std::cout << "Window close button pressed!" << std::endl;
        this->shouldClose(true);
    }

private:
    ffw::BitmapFont font;
};

///=============================================================================
int main(int argc, char *argv[]){
    // Instance to our app class
    App app;

    // set arguments
    ffw::GLFWRenderWindowArgs args;
    args.size.set(800, 400);
    args.title = "Bitmap Font Example";

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
}
