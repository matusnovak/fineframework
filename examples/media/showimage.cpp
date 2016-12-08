#include <ffw/graphics.h>
#include <ffw/media.h>

#define STRING_TO_SHOW "Drop image file here"

///=============================================================================
class App: public ffw::AppRenderWindow {
public:
    App(){
	}

    ~App(){
	}

    bool Setup() override {
		// Blending is needed by the font
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		
		// Checks if 2D texture is supported by render context.
		// The render context uses highest OpenGL version of that is 
		// available by video card.
		if(!ffw::Texture2D::CheckCompability(this)){
			std::cerr << "OpenGL used on this machine is too old! Texture2D is not compatible!" << std::endl;
			return false;
		}

		if(!ffw::Font::CheckCompability(this)){
			std::cerr << "OpenGL used on this machine is too old! Font is not compatible!" << std::endl;
			return false;
		}

		if(!font.CreateFromData(this, ffw::defaultFont, ffw::defaultFontSize, 18, 96)){
			std::cerr << "Failed to create font!" << std::endl;
			return false;
		}

		textSize = font.GetStringSize(STRING_TO_SHOW);
		
		return true;
	}

    void Render() override {
		if(imagePath != ""){
			// Clear the window
			ffw::SetDrawColor(ffw::Rgb(0x000000));
			ffw::DrawRectangle(0, 0, this->GetSize().x, this->GetSize().y);
			ffw::SetDrawColor(ffw::Rgb(0xFFFFFF));
			
			texture.Destroy();

			// To understand exactly (or to create your own) image loader for textures,
			// see function "ReadImage", which accepts Texture2D, 
			// in file "fineframework/include/ffw/media/imageutils.h"
			if(!ffw::ReadImage(imagePath, this, &texture)){
				std::cerr << "Image: " << imagePath << " failed to load!" << std::endl;
			}
			imagePath = "";
		}

		if(texture.IsCreated()){
			// Finds dimension so the texture can fit into the window
			// contain image - finds a largets size and position of an image
			//                 that can fit into the area.
			// cover image - finds a largets size and position of an image
			//               that will fill entire area with no space left.
			// You can see live demo of CSS equivalent at:
			// http://www.w3schools.com/cssref/playit.asp?filename=playcss_background-size&preval=contain
			ffw::Vec4i ret = ffw::ContainImage(texture.GetWidth(), texture.GetHeight(), this->GetSize().x, this->GetSize().y);
			//ffw::vec4i ret = ffw::CoverImage(texture.GetWidth(), texture.GetHeight(), this->GetSize().x, this->GetSize().y);

			// Draw texture mirrored
			// Do not forget that the texture mapping starts from lower left bottom.
			// Positive Y of texture mapping coordinate system is up.
			// Positive Y of window coordinate system is down.
			// Therefore, we need to draw texture mirrored vertically.
			ffw::DrawTexture2D(ret.x, ret.y, ret.z, ret.w, &texture);
		} else {
			ffw::Vec2i textPos = this->GetSize()/2 - textSize/2;
			ffw::DrawString(textPos.x, textPos.y, &font, STRING_TO_SHOW);
		}
	}

    void Close() override {
		font.Destroy();
		texture.Destroy();
	}

    void TextInputEvent(unsigned int c) override {
	}

    void KeyPressedEvent(ffw::Key key, ffw::Mode mode) override {
	}

    void MouseMovedEvent(int mousex, int mousey) override {
	}

    void MouseScrollEvent(int scroll) override {
	}

    void MouseButtonEvent(ffw::MouseButton button, ffw::Mode mode) override {
	}

    void WindowResizedEvent(int width, int height) override {
	}

    void WindowMovedEvent(int windowx, int windowy) override {
	}

    void WindowFocusEvent(bool focus) override {
	}

    void WindowCloseEvent() override {
		this->ShouldClose(true);
	}

    void FilesDroppedEvent(std::vector<std::string> filelist) override {
		// There will be always at least one item in the vector
		imagePath = filelist[0];
	}

private:
	ffw::Texture2D texture;
	ffw::Font font;
	ffw::Vec2i textSize;
    std::string imagePath;
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
	args.title = "Example Show Image";
	args.samples = 4;

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

	app.SetSingleBufferMode(true);

	// The main window loop
	while(app.ShouldRender()){
		app.RenderFrame();
		app.WaitForEvents();
	}

	// Destroy window, this will delete all graphics data used by the window.
	// Must be called after the setup and before the graphics
	// is terminated
	app.Destroy();

    // Needs to be called at the end of the program if ffw::initGraphics() succeeds
    ffw::TerminateGraphics();
	return 0;
}
