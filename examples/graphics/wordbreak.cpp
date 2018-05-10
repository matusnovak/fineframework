#include <ffw/graphics.h>
#include <iostream>

static const std::string loremIpsum = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Nulla quis erat sed est dictum tincidunt. Suspendisse potenti. Suspendisse consectetur ex aliquam tristique tincidunt. Etiam blandit, purus quis accumsan dapibus, nisi turpis consequat ante, in dapibus diam lorem a magna. Suspendisse molestie vulputate nisi in vehicula. Morbi risus elit, consequat quis venenatis eget, semper at risus. Etiam eu lectus quam.\n\nSuspendisse accumsan laoreet accumsan. In eu augue ac ligula lobortis imperdiet in ac lectus. Ut laoreet ullamcorper dui vel tempor. Vivamus vulputate lacinia metus nec venenatis. Nam tristique elit et elit molestie convallis. Etiam suscipit diam quis massa condimentum, ac viverra dui rhoncus. Phasellus et odio ac orci consectetur cursus a sit amet metus. Aliquam mi tortor, scelerisque consectetur ullamcorper ut, ultricies a orci. Duis at mollis sem. Donec vulputate a nisl eget interdum. Sed iaculis sit amet magna sit amet faucibus. Praesent mattis tincidunt turpis nec consequat. Pellentesque quis ex velit. Nulla ultrices ut nibh ut tempor.";

///=============================================================================
class App : public ffw::GLFWRenderWindow {
public:
    App() {
    }

    ~App() {
    }

    bool setup() override {
        if (!font.createFromFile("FreeSans.ttf", 14, 72)) {
            std::cerr << "Failed to create font from: \'FreeSans.ttf\' File is missing?" << std::endl;
            return false;
        }

        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

        textSize = font.getStringSize(loremIpsum, float(getSize().x) - 20.0f);
        textSize = textSize.ceil(); // Round it up so it is pixel perfect

        return true;
    }

    void render() override {
        this->beginFrame();
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        this->setDrawColor(ffw::rgb(0xFF0000)); // Red color
        this->setStrokeMode();
        this->drawRectangle(10.0f, 10.0f, textSize.x, textSize.y);

        this->setDrawColor(ffw::rgb(0xFFFFFF)); // White color
        this->setFillMode();
        this->drawStringBox(10.0f, 10.0f, &font, loremIpsum, float(getSize().x) - 20.0f);
        this->endFrame();
    }

    void close() override {
        std::cout << "Window is closing!" << std::endl;
    }

    void windowCloseEvent() override {
        std::cout << "Window close button pressed!" << std::endl;
        this->shouldClose(true);
    }

    void mouseMovedEvent(int mousex, int mousey) override {
        mousePos.set(mousex, mousey);
    }

    void windowResizedEvent(int width, int height) override {
        textSize = font.getStringSize(loremIpsum, float(width) - 20.0f);
        textSize = textSize.ceil(); // Round it up so it is pixel perfect
    }

private:
    ffw::TrueTypeFont font;
    ffw::Vec2i mousePos;
    ffw::Vec2f textSize;
};

///=============================================================================
int main(int argc, char *argv[]) {
    // Instance to our app class
    App app;

    // set arguments
    ffw::GLFWRenderWindowArgs args;
    args.size.set(500, 500);
    args.title = "Word Break Example";
    args.samples = 4;

    // create window
    if (!app.create(args, NULL)) {
        std::cerr << "Failed to create window!" << std::endl;
        return 1;
    }

    // Run setup
    if (!app.setup()) {
        std::cerr << "Failed to setup window!" << std::endl;
        return 1;
    }

    // The main window loop
    while (app.shouldRender()) {
        app.renderFrame();
        app.waitForEvents();
    }

    // destroy window, this will delete all graphics data used by the window.
    // Must be called after the setup and before the graphics
    // is terminated
    app.destroy();
}
