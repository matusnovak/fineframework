#include <ffw/graphics.h>
#include <ffw/gui.h>
#define CATCH_CONFIG_MAIN
#include "../catch.hpp"
///=============================================================================
class App : public ffw::GLFWRenderWindow {
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

		static ffw::GuiStyleGroup style1 = ffw::GuiTheme::Windows.GetStyleGroup("GUI_LAYOUT");
		style1.normal.background.color = ffw::Rgba(0x00000080);
		style1.normal.background.type = ffw::GuiStyle::Background::Type::SIMPLE;
		style1.normal.border.size = 10;
		style1.normal.border.color[0] = ffw::Rgb(0xFF0000);
		style1.normal.border.color[1] = ffw::Rgb(0x00FF00);
		style1.normal.border.color[2] = ffw::Rgb(0x0000FF);
		style1.normal.border.color[3] = ffw::Rgb(0xFF00FF);

		auto layout = new ffw::GuiVerticalLayout(&gui);
		layout->SetSize(ffw::GuiPercent(50), ffw::GuiPercent(20));
		layout->SetStyleGroup(&style1);
		gui.AddWidget(layout);

		static ffw::GuiStyleGroup style2 = style1;
		style2.normal.border.radius = 25;

		layout = new ffw::GuiVerticalLayout(&gui);
		layout->SetSize(ffw::GuiPercent(50), ffw::GuiPercent(20));
		layout->SetStyleGroup(&style2);
		gui.AddWidget(layout);

		static ffw::GuiStyleGroup style3 = style1;
		style3.normal.border.radius = 5;
		style3.normal.border.size = 15;

		layout = new ffw::GuiVerticalLayout(&gui);
		layout->SetSize(ffw::GuiPercent(50), ffw::GuiPercent(20));
		layout->SetStyleGroup(&style3);
		gui.AddWidget(layout);

		static ffw::GuiStyleGroup style4 = style1;
		style4.normal.border.radius = 0;
		style4.normal.border.size[0] = 5;
		style4.normal.border.size[1] = 10;
		style4.normal.border.size[2] = 15;
		style4.normal.border.size[3] = 20;

		layout = new ffw::GuiVerticalLayout(&gui);
		layout->SetSize(ffw::GuiPercent(50), ffw::GuiPercent(20));
		layout->SetStyleGroup(&style4);
		gui.AddWidget(layout);

		static ffw::GuiStyleGroup style5 = style1;
		style5.normal.border.radius = 20;
		style5.normal.border.size[0] = 10;
		style5.normal.border.size[1] = 0;
		style5.normal.border.size[2] = 10;
		style5.normal.border.size[3] = 0;

		layout = new ffw::GuiVerticalLayout(&gui);
		layout->SetSize(ffw::GuiPercent(50), ffw::GuiPercent(20));
		layout->SetStyleGroup(&style5);
		gui.AddWidget(layout);

		static ffw::GuiStyleGroup style6 = style1;
		style6.normal.border.radius = 20;
		style6.normal.border.size[0] = 0;
		style6.normal.border.size[1] = 10;
		style6.normal.border.size[2] = 0;
		style6.normal.border.size[3] = 10;

		layout = new ffw::GuiVerticalLayout(&gui);
		layout->SetSize(ffw::GuiPercent(50), ffw::GuiPercent(20));
		layout->SetStyleGroup(&style6);
		gui.AddWidget(layout);

		static ffw::GuiStyleGroup style7 = style1;
		style7.normal.border.radius = 20;
		style7.normal.border.size[0] = 10;
		style7.normal.border.size[1] = 25;
		style7.normal.border.size[2] = 10;
		style7.normal.border.size[3] = 25;

		layout = new ffw::GuiVerticalLayout(&gui);
		layout->SetSize(ffw::GuiPercent(50), ffw::GuiPercent(20));
		layout->SetStyleGroup(&style7);
		gui.AddWidget(layout);

		static ffw::GuiStyleGroup style8 = style1;
		style8.normal.border.radius = 20;
		style8.normal.border.size[0] = 25;
		style8.normal.border.size[1] = 10;
		style8.normal.border.size[2] = 25;
		style8.normal.border.size[3] = 10;

		layout = new ffw::GuiVerticalLayout(&gui);
		layout->SetSize(ffw::GuiPercent(50), ffw::GuiPercent(20));
		layout->SetStyleGroup(&style8);
		gui.AddWidget(layout);

		static ffw::GuiStyleGroup style9 = style1;
		style9.normal.border.radius = 20;
		style9.normal.border.size = 10;
		style9.normal.border.color = ffw::Rgb(0xFF0000);

		layout = new ffw::GuiVerticalLayout(&gui);
		layout->SetSize(ffw::GuiPercent(50), ffw::GuiPercent(20));
		layout->SetStyleGroup(&style9);
		gui.AddWidget(layout);

		static ffw::GuiStyleGroup style10 = style1;
		style10.normal.border.radius = 10;
		style10.normal.border.size = 20;
		style10.normal.border.color = ffw::Rgb(0xFF0000);

		layout = new ffw::GuiVerticalLayout(&gui);
		layout->SetSize(ffw::GuiPercent(50), ffw::GuiPercent(20));
		layout->SetStyleGroup(&style10);
		gui.AddWidget(layout);

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

TEST_CASE("Gui Borders") {
	// Instance to our app class
	App app;

	// Set arguments
	ffw::GLFWRenderWindowArgs args;
	args.size.Set(600, 400);
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
}