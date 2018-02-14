#include <ffw/graphics.h>

///=============================================================================
class App: public ffw::GLFWRenderWindow {
public:
    App(){
    }

    ~App(){
    }

    bool setup() override {
        std::cout << "Window setup!" << std::endl;

        ffw::Texture2D first;
        ffw::Texture2D second;

        std::swap(first, second);

        return true;
    }

    void render() override {
        this->beginFrame();
        this->setDrawColor(ffw::rgb(0xFF0000)); // Red color
        this->drawRectangle(10, 10, getSize().x-20, getSize().y-20);
        this->endFrame();
    }

    void close() override {
        std::cout << "Window is closing!" << std::endl;
    }

    void textInputEvent(unsigned int C) override {

    }

    void keyPressedEvent(ffw::Key key, ffw::Mode mode) override {
        if(mode == ffw::Mode::PRESSED)
            std::cout << "Key pressed: " << int(key) << std::endl;
    }

    void mouseMovedEvent(int mousex, int mousey) override {
        std::cout << "Mouse moved to: " << mousex << "x" << mousey << std::endl;
    }

    void mouseScrollEvent(int scroll) override {
        std::cout << "Mouse scroll: " << scroll << std::endl;
    }

    void mouseButtonEvent(ffw::MouseButton button, ffw::Mode mode) override {
        if(mode == ffw::Mode::PRESSED){
            switch(button){
                case ffw::MouseButton::LEFT: std::cout << "Left mouse button pressed!" << std::endl; break;
                case ffw::MouseButton::MIDDLE: std::cout << "middle mouse button pressed!" << std::endl; break;
                case ffw::MouseButton::RIGHT: std::cout << "Right mouse button pressed!" << std::endl; break;
                default: break;
            }
        }
    }

    void windowResizedEvent(int width, int height) override {
        std::cout << "Window resized to: " << width << "x" << height << std::endl;
    }

    void windowMovedEvent(int windowx, int windowy) override {
        std::cout << "Window moved to: " << windowx << "x" << windowy << std::endl;
    }

    void windowFocusEvent(bool focus) override {
        if(focus)std::cout << "Focus gained!" << std::endl;
        else std::cout << "Focus lost!" << std::endl;
    }

    void windowCloseEvent() override {
        std::cout << "Window close button pressed!" << std::endl;
        this->shouldClose(true);
    }

    void filesDroppedEvent(std::vector<std::string> filelist) override {
        std::cout << "Files dropped: " << std::endl;
        for(const auto& file : filelist){
            std::cout << "\t\'" << file << "\'" << std::endl;
        }
    }

};

///=============================================================================
int main(int argc, char *argv[]){
    // Instance to our app class
    App app;

    // set arguments
    ffw::GLFWRenderWindowArgs args;
    args.size.set(400, 400);
    args.title = "Empty Example";

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
