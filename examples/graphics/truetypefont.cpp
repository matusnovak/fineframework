#include <ffw/graphics.h>
#define NUM_OF_FONTS (8)

///=============================================================================
class App: public ffw::GLFWRenderWindow {
public:
    App(){
    }

    ~App(){
    }

    bool setup() override {
        std::cout << "Window setup!" << std::endl;

        for(int i = 0; i < NUM_OF_FONTS; i++){
            if(!fonts[i].createFromFile("FreeSans.ttf", 14 + i*2, 72)){
                std::cerr << "Failed to create font from: \'FreeSans.ttf\' File is missing?" << std::endl;
                return false;
            }
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

        this->setDrawColor(ffw::rgb(0xFF0000)); // Red color

        int height = 0;
        for(int i = 0; i < NUM_OF_FONTS; i++){
            this->setDrawColor(ffw::rgb(255 - i*(256 / NUM_OF_FONTS), i*(256 / NUM_OF_FONTS), 0));
            this->drawString(10, 10 + height, &fonts[i], "Lorem ipsum dolor sit amet, consectetur adipiscing elit.");
            // Line height is a simple formula of (height * weight)
            // wehre height is the height of the font
            // and weight is line spacing (1.0 and more)
            height += int(fonts[i].getSizePixels() * 1.5f);
        }

        this->endFrame();
    }

    void close() override {
        std::cout << "Window is closing!" << std::endl;
        for(int i = 0; i < NUM_OF_FONTS; i++) {
            fonts[i].destroy();
        }
    }

    void windowCloseEvent() override {
        std::cout << "Window close button pressed!" << std::endl;
        this->shouldClose(true);
    }

private:
    ffw::TrueTypeFont fonts[NUM_OF_FONTS];
};

///=============================================================================
int main(int argc, char *argv[]){
    // Instance to our app class
    App app;

    // set arguments
    ffw::GLFWRenderWindowArgs args;
    args.size.set(800, 400);
    args.title = "True Type Font Example";

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
