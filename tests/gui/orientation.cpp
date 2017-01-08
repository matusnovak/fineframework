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

		gui.SetOrientation(ffw::GuiLayout::Orientation::HORIZONTAL);
		gui.SetWrap(true);

		static ffw::GuiStyleGroup customStyle = gui.GetTheme()->GetStyleGroup("GUI_LABEL");
		customStyle.normal.background = ffw::GuiSimpleBackground(ffw::Rgb(0xAAAAAA));

		auto vlayout = new ffw::GuiVerticalLayout(&gui);
		vlayout->SetSize(ffw::GuiPercent(50), ffw::GuiPercent(50));
		vlayout->SetWrap(true);
		gui.AddWidget(vlayout);

		for (int i = 0; i < 20; i++) {
			auto label = new ffw::GuiLabel(&gui, "Hello World!");
			label->SetSize(ffw::GuiWrap(), ffw::GuiWrap());
			label->SetStyleGroup(&customStyle);
			vlayout->AddWidget(label);
		}

		auto hlayout = new ffw::GuiHorizontalLayout(&gui);
		hlayout->SetSize(ffw::GuiPercent(50), ffw::GuiPercent(50));
		hlayout->SetWrap(true);
		gui.AddWidget(hlayout);

		for (int i = 0; i < 20; i++) {
			auto label = new ffw::GuiLabel(&gui, "Hello World!");
			label->SetSize(ffw::GuiWrap(), ffw::GuiWrap());
			label->SetStyleGroup(&customStyle);
			hlayout->AddWidget(label);
		}

		auto flayout = new ffw::GuiFixedLayout(&gui);
		flayout->SetSize(ffw::GuiPercent(50), ffw::GuiPercent(50));
		gui.AddWidget(flayout);

		for (int i = 0; i < 5; i++) {
			auto label = new ffw::GuiLabel(&gui, "Hello World!");
			label->SetSize(ffw::GuiPercent(20), ffw::GuiPercent(20));
			label->SetPos(ffw::GuiPercent(i * 20), ffw::GuiPercent(i * 20));
			label->SetStyleGroup(&customStyle);
			flayout->AddWidget(label);
		}

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

TEST(Gui, Orientation) {
	if (!ffw::InitGraphics()) {
		TEST_FAIL_MSG("Failed to initialize graphics!");
	}

	// Instance to our app class
	App app;

	// Set arguments
	ffw::AppRenderWindowArgs args;
	args.size.Set(600, 600);
	args.title = "Test Gui Orientation";
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