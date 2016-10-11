#include <ffw/graphics.h>

///=============================================================================
class App: public ffw::AppRenderWindow {
public:
    App(){
	}

    ~App(){
	}

    bool Setup() override {
		std::cout << "Window setup!" << std::endl;
		return true;
	}

    void Render() override {
		ffw::SetDrawColor(ffw::Rgb(0xFF0000)); // Red color
		ffw::DrawRectangle(10, 10, GetSize().x-20, GetSize().y-20);
	}

    void Close() override {
		std::cout << "Window is closing!" << std::endl;
	}

    void TextInputEvent(unsigned int C) override {

	}

    void KeyPressedEvent(ffw::Key key, ffw::Mode mode) override {
		if(mode == ffw::Mode::PRESSED)
			std::cout << "Key pressed: " << key << std::endl;
	}

    void MouseMovedEvent(int mousex, int mousey) override {
		std::cout << "Mouse moved to: " << mousex << "x" << mousey << std::endl;
	}

    void MouseScrollEvent(int scroll) override {
		std::cout << "Mouse scroll: " << scroll << std::endl;
	}

    void MouseButtonEvent(ffw::MouseButton button, ffw::Mode mode) override {
		if(mode == ffw::Mode::PRESSED){
			switch(button){
				case ffw::MouseButton::LEFT: std::cout << "Left mouse button pressed!" << std::endl; break;
				case ffw::MouseButton::MIDDLE: std::cout << "Middle mouse button pressed!" << std::endl; break;
				case ffw::MouseButton::RIGHT: std::cout << "Right mouse button pressed!" << std::endl; break;
				default: break;
			}
		}
	}

    void WindowResizedEvent(int width, int height) override {
		std::cout << "Window resized to: " << width << "x" << height << std::endl;
	}

    void WindowMovedEvent(int windowx, int windowy) override {
		std::cout << "Window moved to: " << windowx << "x" << windowy << std::endl;
	}

    void WindowFocusEvent(bool focus) override {
		if(focus)std::cout << "Focus gained!" << std::endl;
		else std::cout << "Focus lost!" << std::endl;
	}

    void WindowCloseEvent() override {
		std::cout << "Window close button pressed!" << std::endl;
		this->ShouldClose(true);
	}

    void FilesDroppedEvent(std::vector<std::string> filelist) override {
        std::cout << "Files dropped: " << std::endl;
        for(const auto& file : filelist){
            std::cout << "\t\'" << file << "\'" << std::endl;
        }
	}

};

///=============================================================================
int main(int argc, char *argv[]){
	// Initialize graphics
    if(!ffw::InitGraphics()){
        std::cerr << "Failed to initialize graphics!" << std::endl;
		return 1;
	}

	// Instance to our app class
	App app;

	// Set arguments
	ffw::AppRenderWindowArgs args;
	args.size.Set(400, 400);
	args.title = "Empty Example";

	// Create window
	if(!app.Create(args, NULL)){
		std::cerr << "Failed to create window!" << std::endl;
		ffw::TerminateGraphics();
		return 1;
	}

	// Run setup
	if(!app.Setup()){
		std::cerr << "Failed to setup window!" << std::endl;
		ffw::TerminateGraphics();
		return 1;
	}

	// The main window loop
	while(app.ShouldRender()){
		app.RenderFrame();
		app.PoolEvents();
	}

	// Destroy window, this will delete all graphics data used by the window.
	// Must be called after the setup and before the graphics
	// is terminated
	app.Destroy();

    // Needs to be called at the end of the program if ffw::initGraphics() succeeds
    ffw::TerminateGraphics();
	return 0;
}
