#include <ffw/graphics.h>
#include <ffw/math.h>
#include <iostream>

///=============================================================================
class App : public ffw::GLFWRenderWindow {
public:
    App() {
        rotStep = 0;
    }

    ~App() {
    }

    bool setup() override {
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        glClearColor(0.3f, 0.3f, 0.3f, 1.0f);

        return true;
    }

    void drawBranch(const ffw::Vec2f& pos, float dir, float add, int steps, float length) {
        if (steps <= 0)return;
        
        this->setStrokeSize(steps);
        ffw::Vec2f end = pos + ffw::Vec2f(length, 0).rotate(dir);
        this->drawLine(pos.x, pos.y, end.x, end.y);

        drawBranch(end, dir - add, add, steps - 1, length * 0.9f);
        drawBranch(end, dir + add, add, steps - 1, length * 0.9f);
    }

    void render() override {
        this->beginFrame();
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // In the moddile horizontally
        // 1 fourth from the bottom vertically
        auto pos = ffw::Vec2f(float(this->getSize().x / 2), float(this->getSize().y - this->getSize().y / 4));
        int length = std::min(this->getSize().x, this->getSize().y) / 10;

        this->setDrawColor(ffw::rgb(255, 255, 255));
        drawBranch(pos, 270.0f, rotStep, 10, length);
        this->endFrame();
    }

    void close() override {
    }

    void textInputEvent(unsigned int C) override {

    }

    void keyPressedEvent(ffw::Key key, ffw::Mode mode) override {
    }

    void mouseMovedEvent(int mousex, int mousey) override {
        rotStep = ffw::remap((double)mousex, 0.0, (double)this->getSize().x, 0.0, 90.0);
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
    float rotStep;
};

///=============================================================================
int main(int argc, char *argv[]) {
    // Instance to our app class
    App app;

    // set arguments
    ffw::GLFWRenderWindowArgs args;
    args.size.set(800, 600);
    args.title = "Tree Example";
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
    return 0;
}
