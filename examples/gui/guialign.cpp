#include <ffw/graphics.h>
#include <ffw/gui.h>
#include <ffw/gui/guiwindowopengl.h>
#include <regex>
#include <fstream>
#include <memory>

static const std::pair<ffw::GuiAlign, std::string> alignTypes[] = {
    {ffw::GuiAlign::TOP_LEFT, "TOP_LEFT"},
    {ffw::GuiAlign::TOP_CENTER, "TOP_CENTER"},
    {ffw::GuiAlign::TOP_RIGHT, "TOP_RIGHT"},
    {ffw::GuiAlign::LEFT, "LEFT"},
    {ffw::GuiAlign::CENTER, "CENTER"},
    {ffw::GuiAlign::RIGHT, "RIGHT"},
    {ffw::GuiAlign::BOTTOM_LEFT, "BOTTOM_LEFT"},
    {ffw::GuiAlign::BOTTOM_CENTER, "BOTTOM_CENTER"},
    {ffw::GuiAlign::BOTTOM_RIGHT, "BOTTOM_RIGHT"},
};

///=============================================================================
class App: public ffw::GLFWRenderWindow {
public:
    App(){
    }

    ~App(){
    }

    void widgetEvent(ffw::GuiEvent e){
    }

    ffw::GuiLayout* makeBox(ffw::GuiWindow* window, ffw::GuiLayout* parent, const std::string& str) {
        auto box = new ffw::GuiVerticalLayout(&gui);
        box->setSize(ffw::guiPercent(33.33333f), ffw::guiWrap());
        box->setPadding(5);
        parent->addWidget(box);

        auto label = new ffw::GuiLabel(window, str);
        box->addWidget(label);

        auto layout = new ffw::GuiVerticalLayout(window);
        layout->setStyleGroup(&boxStyle);
        layout->setSize(ffw::guiPercent(100), ffw::guiWrap());
        layout->setPadding(5);
        box->addWidget(layout);

        return layout;
    }

    bool setup() override {
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        // PLEASE READ!!!
        // If you get artefacts around the font letters, uncomment "glBlendFuncSeparate"
        // and remove the "glBlendFunc" above!
        // glBlendFuncSeparate(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA, GL_ONE, GL_ONE_MINUS_SRC_ALPHA);

        gui.setTheme(&ffw::GuiThemeSimpleLight::singleton);
        gui.create(this);
        gui.setSize(float(getSize().x), float(getSize().y));
        gui.setPos(0, 0);

        boxStyle = gui.getTheme()->layout.self;
        boxStyle.normal.border.color = ffw::rgba(0x80808050);
        boxStyle.normal.border.size = 1;

        gui.getLayout()->setPadding(ffw::guiPixels(10.0f));
        gui.getLayout()->setWrap(true);
        gui.getLayout()->setOrientation(ffw::GuiOrientation::HORIZONTAL);

        if (!font.createFromFile("FreeSans.ttf", 12, 72, 0, 0x17F)) {
            std::cout << "Failed to create GUI font!" << std::endl;
        }
        else {
            gui.setDefaultFont(&font);
        }

        for(int i = 0; i < 9; i++) {
            auto align = ffw::GuiAlign(alignTypes[i].first);
            const std::string& str = alignTypes[i].second;

            auto box = new ffw::GuiHorizontalLayout(&gui);
            box->setWrap(true);
            box->setSize(ffw::guiPercent(33.333f), ffw::guiPercent(33.333f));
            box->setAlign(align);
            box->setStyleGroup(&boxStyle);
            box->setPadding(ffw::guiPixels(5.0f));

            auto label = new ffw::GuiLabel(&gui, str);
            label->setSize(ffw::guiWrap(), ffw::guiWrap());
            label->setMargin(ffw::guiPixels(5.0f));
            box->addWidget(label);

            auto first = new ffw::GuiButton(&gui, "Button #1");
            first->setSize(ffw::guiPixels(60.0f), ffw::guiPixels(25.0f));
            first->setMargin(ffw::guiPixels(5.0f));
            box->addWidget(first);

            auto second = new ffw::GuiButton(&gui, "Button #2");
            second->setSize(ffw::guiPixels(60.0f), ffw::guiPixels(25.0f));
            second->setMargin(ffw::guiPixels(5.0f));
            box->addWidget(second);

            auto third = new ffw::GuiButton(&gui, "Button #2");
            third->setSize(ffw::guiPixels(100.0f), ffw::guiPixels(25.0f));
            third->setMargin(ffw::guiPixels(5.0f));
            box->addWidget(third);

            gui.getLayout()->addWidget(box);
        }

        return true;
    }

    void render() override {
        this->beginFrame();

        gui.update();
        gui.poolEvents();
        gui.render();
        // Uncomment this to see what's being updated and what is not
        // this->setDrawColor(ffw::rgba(0x00000001));
        // this->drawRectangle(0, 0, getSize().x, getSize().y);

        this->endFrame();
    }

    void close() override {
        gui.destroy();
        font.destroy();
    }

    void textInputEvent(unsigned int c) override {
        gui.injectText(c);
    }

    void keyPressedEvent(ffw::Key key, ffw::Mode mode) override {
        gui.injectKey(key, mode);
    }

    void mouseMovedEvent(int mousex, int mousey) override {
        gui.injectMousePos(float(mousex), float(mousey));
    }

    void mouseScrollEvent(int scroll) override {
        gui.injectScroll(0, float(scroll));
    }

    void mouseButtonEvent(ffw::MouseButton button, ffw::Mode mode) override {
        gui.injectMouseButton(button, mode);
    }

    void windowResizedEvent(int width, int height) override {
        gui.setSize(float(width), float(height));
        gui.redraw();
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
    ffw::GuiWindowOpenGL gui;
    ffw::GuiFontOpenGL font;
    ffw::GuiWidget::Style boxStyle;
    ffw::GuiImageOpenGL image;
};

///=============================================================================
int main(int argc, char *argv[]){
    // Instance to our app class
    App app;

    // set arguments
    ffw::GLFWRenderWindowArgs args;
    args.size.set(600, 600);
    args.title = "Example GUI With OpenGL";
    args.samples = 4;

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

    app.setSingleBufferMode(true);

    // The main window loop
    while(app.shouldRender()){
        app.renderFrame();
        app.waitForEvents();
        //std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }

    // destroy window, this will delete all graphics data used by the window.
    // Must be called after the setup and before the graphics
    // is terminated
    app.destroy();
    return 0;
}
