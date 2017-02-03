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
		if (e.type == ffw::GuiEvent::Type::INPUT) {
			std::cout << "Character was added: " << (char)e.data.input.chr << std::endl;
		}
		if (e.type == ffw::GuiEvent::Type::CLICKED) {
			std::cout << "Widget was selected: " << e.widget << std::endl;
		}
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
		gui.SetWrap(false);

		{
			auto layout = new ffw::GuiVerticalLayout(&gui);
			layout->SetPadding(5);
			layout->SetSize(ffw::GuiPercent(50), ffw::GuiPercent(100));
			gui.AddWidget(layout);

			auto textinput = new ffw::GuiTextInput(&gui);
			textinput->AddEventCallback(&App::WidgetEvent, this);
			textinput->SetValue(L"Hello World!");
			layout->AddWidget(textinput);

			textinput = new ffw::GuiTextInput(&gui);
			textinput->AddEventCallback(&App::WidgetEvent, this);
			textinput->AddRangeLimit('0', '9');
			textinput->AddListOfLimits({ '.', '-', '+' });
			textinput->SetValue(L"01234");
			layout->AddWidget(textinput);

			textinput = new ffw::GuiTextInput(&gui);
			textinput->AddEventCallback(&App::WidgetEvent, this);
			textinput->AddRangeLimit('A', 'Z');
			textinput->SetValue(L"UPPER CASE ONLY");
			textinput->AddListOfLimits({ ' ' });
			layout->AddWidget(textinput);
		}

		{
			auto layout = new ffw::GuiVerticalLayout(&gui);
			layout->SetPadding(5);
			layout->SetSize(ffw::GuiPercent(50), ffw::GuiPercent(100));
			gui.AddWidget(layout);

			auto textinput = new ffw::GuiTextArea(&gui);
			textinput->SetSize(ffw::GuiPercent(100), ffw::GuiPercent(100));
			textinput->AddEventCallback(&App::WidgetEvent, this);
			textinput->SetValue(L"Hello World!");
			layout->AddWidget(textinput);
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


TEST_CASE("Gui Text Edits") {
	// Instance to our app class
	App app;

	// Set arguments
	ffw::GLFWRenderWindowArgs args;
	args.size.Set(400, 180);
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