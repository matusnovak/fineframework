#include <ffw/graphics.h>
#include <ffw/media.h>

///=============================================================================
class App: public ffw::AppRenderWindow {
public:
    App(){
		mouseDown = false;
	}

    ~App(){
	}

    bool Setup() override {
		// Check if graphics components are compatible with OpenGL
		if(!ffw::Vbo::CheckCompability(this)){
			std::cerr << "OpenGL used on this machine is too old! Vbo is not compatible!" << std::endl; return false;
		}
		if(!ffw::Shader::CheckCompability(this)){
			std::cerr << "OpenGL used on this machine is too old! Shader is not compatible!" << std::endl; return false;
		}
		if(!ffw::Texture2D::CheckCompability(this)){
			std::cerr << "OpenGL used on this machine is too old! Texture2D is not compatible!" << std::endl; return false;
		}
		if(!ffw::Font::CheckCompability(this)){
			std::cerr << "OpenGL used on this machine is too old! Font is not compatible!" << std::endl; return false;
		}

		// Start with mode: lightning
		// mode 2 = lightning
		// mode 1 = solid colors
		// mode 0 = normals
		viewMode = 2;

		// Load font
		// Default font included in FFW
		if(!font.CreateFromData(this, ffw::defaultFont, ffw::defaultFontSize, 18, 72)){
			std::cerr << "Failed to create font!" << std::endl;
			return false;
		}

		// Load shader
		if(!shader.CreateFromFile(this, "", "monkeyshader.vert", "monkeyshader.frag")){
			// Error while loading shader
			std::cerr << "Failed to load monkeyshader.vert & monkeyshader.frag!" << std::endl;
			std::cerr << "Compile log:\n" << shader.GetCompileLog() << std::endl;
			return false;
		}

		// Load texture
		if(!ffw::ReadImage("uvgrid.png", this, &texture)){
			// Error while loading shader
			std::cerr << "Failed to load uvgrid.bmp!" << std::endl;
		}

		// Load OBJ directly into VBO
		if(!ffw::ReadObj("monkey.obj", this, &vbo)){
			std::cerr << "Failed to load monkey.obj!" << std::endl;
			return false;
		}
		
		eyesPos.Set(0.0f, 0.0f, 1.5f);
		RecalculateMatrix();
		return true;
	}

	void RecalculateMatrix() {
		// This is not the most efficient way to calculate 
		// Model-View-Projection
		// We are doing it this way just for the purpose
		// of the example...

		// Get the aspect ratio of the window
		ffw::Vec2i windowSize = this->GetSize();
		float aspectRatio = windowSize.x / float(windowSize.y);
		// Create the projection matrix
		// 60 deg field of view
		// 0.1 near distance of frustum
		// 1000.0 far distance of frustum
		projectionMatrix = ffw::MakeProjectionMatrix(60.0f, aspectRatio, 0.05f, 1000.0f);

		// Set the view matrix
		//viewMatrix = ffw::Mat4x4f(1.0f);
		viewMatrix = ffw::MakeLookAtMatrix(eyesPos, ffw::Vec3f(0.0f, 0.0f, 0.0f), ffw::Vec3f(0.0f, 1.0f, 0.0f));

		// Set the model matrix
		modelMatrix = ffw::Mat4x4f(1.0f);
	}

    void Render() override {
		// Blending is needed by the font
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		// Enable depth test
		glEnable(GL_DEPTH_TEST);
		// Begin shader program
		shader.Bind();
		// Bind monkey object
		vbo.Bind();
		// Bind grid texture
		texture.Bind();
		// Set uniforms and attribute pointers
		// Set the texture sampler to 0 (GL_TEXTURE0)
		shader.SetUniform1i(shader.GetUniformLocation("sampler"), 0);
		// Set the position attribute to length 3 starting at position 0 in the vertex buffer
		// Each vertex has 8 floats total: {Px, Py, Pz, Nx, Ny, Nz, U, V}
		// Where P is position, N is normal and UV are texture coordinates
		shader.SetAttributePointerf(shader.GetAttributeLocation("position"), 3, 8*sizeof(float), (void*)(0*sizeof(float)));
		// Set the normal attribute to length 3 starting at position 3 in the vertex buffer
		shader.SetAttributePointerf(shader.GetAttributeLocation("normals"), 3, 8*sizeof(float), (void*)(3*sizeof(float)));
		// Set the texture coordinates attribute to length 2 starting at position 6 in the vertex buffer
		shader.SetAttributePointerf(shader.GetAttributeLocation("texCoords"), 2, 8*sizeof(float), (void*)(6*sizeof(float)));
		// Set the model, view and projection matrices
		shader.SetUniformMatrix4fv(shader.GetUniformLocation("model"), &modelMatrix[0], 1);
		shader.SetUniformMatrix4fv(shader.GetUniformLocation("view"), &viewMatrix[0], 1);
		shader.SetUniformMatrix4fv(shader.GetUniformLocation("projection"), &projectionMatrix[0], 1);
		// Set integer uniform mode
		// Used to switch between the normal color, solid color, or lightning
		shader.SetUniform1i(shader.GetUniformLocation("mode"), viewMode);
		// Draw whole object
		shader.DrawArrays(GL_TRIANGLES, 0, vbo.GetSize()/24);
		// Stop object shader
		shader.Unbind();
		vbo.Unbind();
		// Disable depth test
		// Depth test needs to be disabled in order to
		// draw user interface or any other 2D graphics components
		glDisable(GL_DEPTH_TEST);

		// Draw debug information
		ffw::SetDrawColor(ffw::Rgb(0xFFFFFF));
		ffw::DrawString(10, 10, &font, "Keyboard shortcuts:\n'Q' - Show normals\n'W' - Albedo\n'E' - Lightning");
	}

    void Close() override {
		font.Destroy();
		texture.Destroy();
		shader.Destroy();
		vbo.Destroy();
		int viewMode = 2;
	}

    void TextInputEvent(unsigned int c) override {
	}

    void KeyPressedEvent(ffw::Key key, ffw::Mode mode) override {
		if(mode == ffw::Mode::PRESSED){
			switch(key){
				case ffw::Key::Q: viewMode = 0; break;
				case ffw::Key::W: viewMode = 1; break;
				case ffw::Key::E: viewMode = 2; break;
			};
		}
	}

    void MouseMovedEvent(int mousex, int mousey) override {
		if(mouseDown){
			int diff = mousex - oldmousex;
			oldmousex = mousex;

			eyesPos = eyesPos.RotateY(-diff);
			RecalculateMatrix();
		} else {
			oldmousex = mousex;
		}
	}

    void MouseScrollEvent(int scroll) override {
	}

    void MouseButtonEvent(ffw::MouseButton button, ffw::Mode mode) override {
		if(mode == ffw::Mode::PRESSED)mouseDown = true;
		else mouseDown = false;
	}

    void WindowResizedEvent(int width, int height) override {
		RecalculateMatrix();
	}

    void WindowMovedEvent(int windowx, int windowy) override {
	}

    void WindowFocusEvent(bool focus) override {
	}

    void WindowCloseEvent() override {
		this->ShouldClose(true);
	}

    void FilesDroppedEvent(std::vector<std::string> filelist) override {
	}

private:
	// Object vertex buffer
    ffw::Vbo vbo;
    // Object shader
    ffw::Shader shader;
    // Grid texture
    ffw::Texture2D texture;
    // Model, view and projection matrices used in shader
    ffw::Mat4x4f projectionMatrix;
	ffw::Mat4x4f viewMatrix;
	ffw::Mat4x4f modelMatrix;
	// Font
	ffw::Font font;
	ffw::Vec3f eyesPos;
	bool mouseDown;
	int oldmousex;

    int viewMode;
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
		system("pause");
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
