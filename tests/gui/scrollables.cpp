#include <ffw/graphics.h>
#include <ffw/gui.h>
#define CATCH_CONFIG_MAIN
#include "../catch.hpp"

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
		gui.SetOrientation(ffw::GuiLayout::Orientation::HORIZONTAL);
		gui.SetWrap(true);

		auto scrollable = new ffw::GuiScrollableLayout(&gui, ffw::GuiLayout::Orientation::VERTICAL, true, true);
		scrollable->SetSize(ffw::GuiPercent(46), ffw::GuiPercent(46));
		scrollable->SetMargin(ffw::GuiPercent(2));
		gui.AddWidget(scrollable);

		for (int i = 0; i < 20; i++) {
			auto button = new ffw::GuiButtonToggle(&gui, "Button");
			scrollable->GetInner()->AddWidget(button);
		}

		scrollable = new ffw::GuiScrollableLayout(&gui, ffw::GuiLayout::Orientation::VERTICAL, true, true);
		scrollable->SetSize(ffw::GuiPercent(46), ffw::GuiPercent(46));
		scrollable->SetMargin(ffw::GuiPercent(2));
		scrollable->GetHscroll()->SetIgnoreUserInput(true);
		scrollable->GetVscroll()->SetIgnoreUserInput(true);
		scrollable->GetHscroll()->SetHover(true);
		scrollable->GetVscroll()->SetHover(true);
		gui.AddWidget(scrollable);

		for (int i = 0; i < 20; i++) {
			auto button = new ffw::GuiButtonToggle(&gui, "Button");
			scrollable->GetInner()->AddWidget(button);
		}

		scrollable = new ffw::GuiScrollableLayout(&gui, ffw::GuiLayout::Orientation::VERTICAL, true, true);
		scrollable->SetSize(ffw::GuiPercent(46), ffw::GuiPercent(46));
		scrollable->SetMargin(ffw::GuiPercent(2));
		scrollable->GetHscroll()->SetIgnoreUserInput(true);
		scrollable->GetVscroll()->SetIgnoreUserInput(true);
		scrollable->GetHscroll()->SetFocus(true);
		scrollable->GetVscroll()->SetFocus(true);
		gui.AddWidget(scrollable);

		for (int i = 0; i < 20; i++) {
			auto button = new ffw::GuiButtonToggle(&gui, "Button");
			scrollable->GetInner()->AddWidget(button);
		}

		scrollable = new ffw::GuiScrollableLayout(&gui, ffw::GuiLayout::Orientation::VERTICAL, true, true);
		scrollable->SetSize(ffw::GuiPercent(46), ffw::GuiPercent(46));
		scrollable->SetMargin(ffw::GuiPercent(2));
		scrollable->GetHscroll()->SetDisabled(true);
		scrollable->GetVscroll()->SetDisabled(true);
		gui.AddWidget(scrollable);

		for (int i = 0; i < 20; i++) {
			auto button = new ffw::GuiButtonToggle(&gui, "Button");
			scrollable->GetInner()->AddWidget(button);
		}

		scrollable->SetDisabled(true);

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


TEST_CASE("Gui Scrollables") {
	REQUIRE(ffw::InitGraphics());

	// Instance to our app class
	App app;

	// Set arguments
	ffw::AppRenderWindowArgs args;
	args.size.Set(400, 400);
	args.title = "Test Gui";
	args.samples = 4;

	// Create window
	REQUIRE(app.Create(args, NULL));

	// Run setup
	REQUIRE(app.Setup());

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