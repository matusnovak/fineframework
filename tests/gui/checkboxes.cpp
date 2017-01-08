#include "../units.h"
#include <ffw/graphics.h>
#include <ffw/gui.h>

///=============================================================================
class App : public ffw::AppRenderWindow {
public:
	App() {
	}

	~App() {
	}

	void WidgetEvent(ffw::GuiEvent e) {
	}

	bool Setup() override {
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

		gui.Create(this);
		gui.SetSize(GetSize().x, GetSize().y);
		gui.SetPos(0, 0);

		// The last two values indicate start and the end of the unicode
		// table to load.
		// To load ASCII only characters, enter 0 - 0x100
		// To load ASCII and Latin Extended-A, enter 0 - 0x17F
		// See "Range" in: https://en.wikipedia.org/wiki/Latin_Extended-A
		font = gui.CreateFontFromFile("FreeSans.ttf", 12, 72, 0, 0x17F);
		if (font == NULL) {
			std::cout << "Failed to create GUI font!" << std::endl;
		}
		else {
			gui.SetDefaultFont(font);
		}

		gui.SetPadding(10);
		gui.SetOrientation(ffw::GuiLayout::Orientation::VERTICAL);
		gui.SetWrap(false);

		auto checkbox = new ffw::GuiCheckbox(&gui, "Normal");
		checkbox->SetSize(ffw::GuiPercent(100), ffw::GuiPercent(20));
		checkbox->SetMargin(0, 0, ffw::GuiPercent(5), 0);
		gui.AddWidget(checkbox);

		checkbox = new ffw::GuiCheckbox(&gui, "Hover");
		checkbox->SetSize(ffw::GuiPercent(100), ffw::GuiPercent(20));
		checkbox->SetMargin(0, 0, ffw::GuiPercent(5), 0);
		checkbox->SetIgnoreUserInput(true);
		checkbox->SetHover(true);
		gui.AddWidget(checkbox);

		checkbox = new ffw::GuiCheckbox(&gui, "Active");
		checkbox->SetSize(ffw::GuiPercent(100), ffw::GuiPercent(20));
		checkbox->SetMargin(0, 0, ffw::GuiPercent(5), 0);
		checkbox->SetIgnoreUserInput(true);
		checkbox->SetFocus(true);
		gui.AddWidget(checkbox);

		checkbox = new ffw::GuiCheckbox(&gui, "Disabled");
		checkbox->SetSize(ffw::GuiPercent(100), ffw::GuiPercent(20));
		checkbox->SetMargin(0, 0, ffw::GuiPercent(5), 0);
		checkbox->SetDisabled(true);
		gui.AddWidget(checkbox);

		return true;
	}

	void Render() override {
		gui.Update();
		gui.PoolEvents();
		gui.Render();
	}

	void Close() override {
		gui.Destroy();
		delete font;
	}

	void TextInputEvent(unsigned int c) override {
		gui.InjectText(c);
	}

	void KeyPressedEvent(ffw::Key key, ffw::Mode mode) override {
		gui.InjectKey(key, mode);
	}

	void MouseMovedEvent(int mousex, int mousey) override {
		gui.InjectMousePos(mousex, mousey);
	}

	void MouseButtonEvent(ffw::MouseButton button, ffw::Mode mode) override {
		gui.InjectMouseButton(button, mode);
	}

	void WindowResizedEvent(int width, int height) override {
		gui.SetSize(width, height);
		gui.Redraw();
	}

	void WindowCloseEvent() override {
		this->ShouldClose(true);
	}

private:
	ffw::GuiWindowOpenGL gui;
	ffw::GuiFont* font;
};

TEST(Gui, Checkboxes) {
	if (!ffw::InitGraphics()) {
		TEST_FAIL_MSG("Failed to initialize graphics!");
	}

	// Instance to our app class
	App app;

	// Set arguments
	ffw::AppRenderWindowArgs args;
	args.size.Set(200, 180);
	args.title = "Test Gui Checkboxes";
	args.samples = 4;

	// Create window
	if (!app.Create(args, NULL)) {
		TEST_FAIL_MSG("Failed to create window!");
		ffw::TerminateGraphics();
	}

	// Run setup
	if (!app.Setup()) {
		TEST_FAIL_MSG("Failed to setup window!");
		ffw::TerminateGraphics();
	}

	app.SetSingleBufferMode(true);

	// The main window loop
	while (app.ShouldRender()) {
		app.RenderFrame();
		app.WaitForEvents();
	}

	// Destroy window, this will delete all graphics data used by the window.
	// Must be called after the setup and before the graphics
	// is terminated
	app.Destroy();

	// Needs to be called at the end of the program if ffw::initGraphics() succeeds
	ffw::TerminateGraphics();
}