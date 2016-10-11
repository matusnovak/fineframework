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

		for(int i = 0; i < 8; i++){
			if(!freesans[i].CreateFromFile(this, "FreeSans.ttf", 14 + i*2, 72)){
				system("ls");
				std::cerr << "Failed to create font from: \'FreeSans.ttf\' File is missing?" << std::endl;
				return false;
			}
		}

		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

		return true;
	}

    void Render() override {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		ffw::SetDrawColor(ffw::Rgb(0xFF0000)); // Red color

		int height = 0;
		for(int i = 0; i < 8; i++){
			ffw::SetDrawColor(ffw::Rgb(255 - i*32, i*32, 0));
			ffw::DrawString(10, 10 + height, &freesans[i], "Lorem ipsum dolor sit amet, consectetur adipiscing elit.");
			height += freesans[i].GetLineHeight();
		}
	}

    void Close() override {
		std::cout << "Window is closing!" << std::endl;
	}

    void WindowCloseEvent() override {
		std::cout << "Window close button pressed!" << std::endl;
		this->ShouldClose(true);
	}

private:
	ffw::Font freesans[8];
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
	args.size.Set(800, 400);
	args.title = "Font Example";

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
		system("pause");
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
