#include <ffw/graphics.h>
#include <ffw/gui.h>

///=============================================================================
class App: public ffw::AppRenderWindow {
public:
    App(){
	}

    ~App(){
	}

	void WidgetEvent(ffw::GuiEvent e){
		if(e.widget == mySlider && e.type == ffw::GuiEventType::CHANGED){
			mySliderLabel->SetLabel(ffw::ValToWstring(e.data.changed.value));
		}
	}

    bool Setup() override {
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

		backend.Create(this);
		gui.SetBackend(&backend);
		gui.SetSize(GetSize().x, GetSize().y);
		gui.SetPos(0, 0);

		// The last two characters indicate start and the end of the unicode
		// table to load.
		// To load ASCII only characters, enter 0 - 0x100
		// To load ASCII and Latin Extended-A, enter 0 - 0x17F
		// See "Range" in: https://en.wikipedia.org/wiki/Latin_Extended-A
		font = gui.CreateFontFromFile("FreeSans.ttf", 12, 72, 0, 0x17F);
		if(font == NULL){
			std::cout << "Failed to create GUI font!" << std::endl;
		} else {
			gui.SetDefaultFont(font);
		}

		auto topLayout = new ffw::GuiHorizontalLayout(&gui);
		topLayout->SetSize(ffw::GuiUnits::Percent(100), ffw::GuiUnits::Percent(50));
		topLayout->Style().normal.bordercolor[2] = ffw::Rgb(0xFF0000);
		topLayout->Style().normal.bordersize[2] = 1;
		topLayout->SetPadding(5);

		auto bottomLayout = new ffw::GuiHorizontalLayout(&gui);
		bottomLayout->SetSize(ffw::GuiUnits::Percent(100), ffw::GuiUnits::Percent(50));
		bottomLayout->Style().normal.bordercolor[2] = ffw::Rgb(0x0000FF);
		bottomLayout->Style().normal.bordersize[2] = 1;
		bottomLayout->SetPadding(5);

		gui.SetPadding(5);
		gui.AddWidget(topLayout);
		gui.AddWidget(bottomLayout);

		// Top Column #1 - Buttons and Toggle Buttons
		auto column = new ffw::GuiLayout(&gui, ffw::GuiLayout::Orientation::VERTICAL);
		column->SetSize(ffw::GuiUnits::Percent(25), ffw::GuiUnits::Percent(100));
		column->Style().normal.bordercolor[1] = ffw::Rgb(0x999999);
		column->Style().normal.bordersize[1] = 1;
		column->SetPadding(5);

		auto label = new ffw::GuiLabel(&gui, "Buttons:");
		column->AddWidget(label);

		auto button = new ffw::GuiButton(&gui, "Button #1");
		button->SetAlign(ffw::GuiAlign::LEFT);
		column->AddWidget(button);

		button = new ffw::GuiButton(&gui, "Button #2");
		button->SetAlign(ffw::GuiAlign::CENTER);
		column->AddWidget(button);

		button = new ffw::GuiButton(&gui, "Button #3");
		button->SetAlign(ffw::GuiAlign::RIGHT);
		column->AddWidget(button);

		label = new ffw::GuiLabel(&gui, "Toggle Buttons:");
		column->AddWidget(label);

		auto buttontoggle = new ffw::GuiButtonToggle(&gui, "Button Toggle #1");
		buttontoggle->Style().normal.textcolor = ffw::Rgb(0xFF0000);
		column->AddWidget(buttontoggle);

		buttontoggle = new ffw::GuiButtonToggle(&gui, "Button Toggle #2");
		buttontoggle->Style().normal.textcolor = ffw::Rgb(0x00FF00);
		column->AddWidget(buttontoggle);

		buttontoggle = new ffw::GuiButtonToggle(&gui, "Button Toggle #3");
		buttontoggle->Style().normal.textcolor = ffw::Rgb(0x0000FF);
		column->AddWidget(buttontoggle);

		topLayout->AddWidget(column);

		// Top Column #2 - Checkboxes and Radios
		column = new ffw::GuiLayout(&gui, ffw::GuiLayout::Orientation::HORIZONTAL);
		column->SetSize(ffw::GuiUnits::Percent(25), ffw::GuiUnits::Percent(100));
		column->Style().normal.bordercolor[1] = ffw::Rgb(0x999999);
		column->Style().normal.bordersize[1] = 1;
		column->SetPadding(5);
		column->SetWrap(true);

		label = new ffw::GuiLabel(&gui, "Checkboxes:");
		column->AddWidget(label);

		auto checkbox = new ffw::GuiCheckbox(&gui, "Checkbox #1");
		column->AddWidget(checkbox);

		checkbox = new ffw::GuiCheckbox(&gui, "Checkbox #2");
		column->AddWidget(checkbox);

		checkbox = new ffw::GuiCheckbox(&gui, "Checkbox #3");
		button->SetAlign(ffw::GuiAlign::RIGHT);
		column->AddWidget(checkbox);

		label = new ffw::GuiLabel(&gui, "Radios:");
		column->AddWidget(label);

		auto radio = new ffw::GuiRadio(&gui, "Radio #1", 1, NULL);
		column->AddWidget(radio);

		// Passing other radio as 4th parameters makes them linked
		// e.g. They will react to each other
		radio = new ffw::GuiRadio(&gui, "Radio #2", 2, radio);
		column->AddWidget(radio);

		radio = new ffw::GuiRadio(&gui, "Radio #3", 3, radio);
		column->AddWidget(radio);

		label = new ffw::GuiLabel(&gui, "Labels:");
		column->AddWidget(label);

		label = new ffw::GuiLabel(&gui, "Label #1");
		label->SetSize(label->GetSize().x, ffw::GuiUnits::Pixels(30));
		label->SetAlign(ffw::GuiAlign::BOTTOM_CENTER);
		label->Style().normal.textcolor = ffw::Rgb(0xCC4444);
		label->Style().normal.backgroundcolor = ffw::Rgba(0xCC44441F);
		label->Style().normal.background = true;
		column->AddWidget(label);

		label = new ffw::GuiLabel(&gui, "Label #2");
		label->SetSize(ffw::GuiUnits::Wrap(), ffw::GuiUnits::Wrap());
		label->Style().normal.textcolor = ffw::Rgb(0x44CC44);
		label->Style().normal.backgroundcolor = ffw::Rgba(0x44CC441F);
		label->Style().normal.background = true;
		column->AddWidget(label);

		label = new ffw::GuiLabel(&gui, "Label #3");
		label->SetSize(ffw::GuiUnits::Wrap(), ffw::GuiUnits::Wrap());
		label->Style().normal.textcolor = ffw::Rgb(0x4444CC);
		label->Style().normal.backgroundcolor = ffw::Rgba(0x4444CC1F);
		label->Style().normal.background = true;
		column->AddWidget(label);

		label = new ffw::GuiLabel(&gui, "Label #4");
		label->SetSize(ffw::GuiUnits::Wrap(), ffw::GuiUnits::Wrap());
		label->Style().normal.backgroundcolor = ffw::Rgba(0x4444441F);
		label->Style().normal.background = true;
		column->AddWidget(label);

		topLayout->AddWidget(column);

		// Top Column #3 - Two Columns
		// We will size everything to 50% so two widgets can be put
		// into one row
		// The SetWrap is necessary!
		column = new ffw::GuiLayout(&gui, ffw::GuiLayout::Orientation::HORIZONTAL);
		column->SetSize(ffw::GuiUnits::Percent(25), ffw::GuiUnits::Percent(100));
		column->Style().normal.bordercolor[1] = ffw::Rgb(0x999999);
		column->Style().normal.bordersize[1] = 1;
		column->SetPadding(5);
		column->SetWrap(true);

		label = new ffw::GuiLabel(&gui, "Two columns 40% / 60%:");
		column->AddWidget(label);

		label = new ffw::GuiLabel(&gui, "Input:");
		label->SetSize(ffw::GuiUnits::Percent(40), ffw::GuiUnits::Wrap());
		label->SetAlign(ffw::GuiAlign::RIGHT);
		label->SetPadding(0, 5, 5, 0);
		column->AddWidget(label);

		auto input = new ffw::GuiTextEdit(&gui, "Abcdefg", false);
		input->SetSize(ffw::GuiUnits::Percent(60), ffw::GuiUnits::Wrap());
		column->AddWidget(input);

		label = new ffw::GuiLabel(&gui, "Checkbox:");
		label->SetSize(ffw::GuiUnits::Percent(40), ffw::GuiUnits::Wrap());
		label->SetAlign(ffw::GuiAlign::RIGHT);
		label->SetPadding(0, 5, 5, 0);
		column->AddWidget(label);

		checkbox = new ffw::GuiCheckbox(&gui, "Abcdefg");
		checkbox->SetSize(ffw::GuiUnits::Percent(60), ffw::GuiUnits::Wrap());
		column->AddWidget(checkbox);

		label = new ffw::GuiLabel(&gui, "Button:");
		label->SetSize(ffw::GuiUnits::Percent(40), ffw::GuiUnits::Wrap());
		label->SetAlign(ffw::GuiAlign::RIGHT);
		label->SetPadding(0, 5, 5, 0);
		column->AddWidget(label);

		button = new ffw::GuiButton(&gui, "Abcdefg");
		button->SetSize(ffw::GuiUnits::Percent(60), ffw::GuiUnits::Wrap());
		column->AddWidget(button);

		label = new ffw::GuiLabel(&gui, "Slider:");
		label->SetSize(ffw::GuiUnits::Percent(40), ffw::GuiUnits::Wrap());
		label->SetAlign(ffw::GuiAlign::RIGHT);
		label->SetPadding(0, 5, 5, 0);
		column->AddWidget(label);

		// Slider can have its "thickness" auto wrapped
		// For example below, when dealing with horizontal slider,
		// we set the width to 60% and height to wrap.
		// Wrap is determined by the size of the slider's button
		// which can be set by slider->SetButtonSize()
		auto slider = new ffw::GuiSlider(&gui, false);
		slider->SetSize(ffw::GuiUnits::Percent(60), ffw::GuiUnits::Wrap());
		slider->SetOnValueChangedCallback(&App::WidgetEvent, this);
		mySlider = slider;
		column->AddWidget(slider);

		label = new ffw::GuiLabel(&gui, "Value:");
		label->SetSize(ffw::GuiUnits::Percent(40), ffw::GuiUnits::Wrap());
		label->SetAlign(ffw::GuiAlign::RIGHT);
		label->SetPadding(0, 5, 5, 0);
		column->AddWidget(label);

		// This label will update based on the slider
		label = new ffw::GuiLabel(&gui, "50");
		label->SetSize(ffw::GuiUnits::Percent(60), ffw::GuiUnits::Wrap());
		mySliderLabel = label;
		column->AddWidget(label);

		label = new ffw::GuiLabel(&gui, "Vertical\nSlider:");
		label->SetSize(ffw::GuiUnits::Percent(40), ffw::GuiUnits::Wrap());
		label->SetAlign(ffw::GuiAlign::RIGHT);
		label->SetPadding(0, 5, 5, 0);
		column->AddWidget(label);

		// The same idea goes for the vertical slider (notice the second 
		// parameter in the constructor). However, we need to set fixed height.
		slider = new ffw::GuiSlider(&gui, true);
		slider->SetSize(ffw::GuiUnits::Wrap(), ffw::GuiUnits::Pixels(100));
		slider->SetInversed(true);
		slider->SetColor(ffw::Rgb(0xAA4444));
		column->AddWidget(slider);

		topLayout->AddWidget(column);

		// Top Column #4 - Text Area
		column = new ffw::GuiLayout(&gui, ffw::GuiLayout::Orientation::VERTICAL);
		column->SetSize(ffw::GuiUnits::Percent(25), ffw::GuiUnits::Percent(100));
		column->SetPadding(5);

		label = new ffw::GuiLabel(&gui, "Text Area:");
		column->AddWidget(label);

		input = new ffw::GuiTextEdit(&gui, "Lorem ipsum dolor sit amet, consectetur adipiscing elit.\n\nDonec porttitor turpis purus, id fringilla nulla.\n", true);
		input->SetSize(ffw::GuiUnits::Percent(100), ffw::GuiUnits::Pixels(200));
		column->AddWidget(input);

		topLayout->AddWidget(column);

		// Bottom Column #1 - Scrollbars
		column = new ffw::GuiLayout(&gui, ffw::GuiLayout::Orientation::VERTICAL);
		column->SetSize(ffw::GuiUnits::Percent(25), ffw::GuiUnits::Percent(100));
		column->Style().normal.bordercolor[1] = ffw::Rgb(0x999999);
		column->Style().normal.bordersize[1] = 1;
		column->SetPadding(5);

		label = new ffw::GuiLabel(&gui, "Scrollbars:");
		column->AddWidget(label);

		auto scroll = new ffw::GuiScrollbar(&gui, false);
		column->AddWidget(scroll);

		scroll = new ffw::GuiScrollbar(&gui, true);
		scroll->SetSize(ffw::GuiUnits::Pixels(15), ffw::GuiUnits::Pixels(100));
		column->AddWidget(scroll);

		bottomLayout->AddWidget(column);

		// Bottom Column #2 - Scrollable
		column = new ffw::GuiLayout(&gui, ffw::GuiLayout::Orientation::VERTICAL);
		column->SetSize(ffw::GuiUnits::Percent(25), ffw::GuiUnits::Percent(100));
		column->Style().normal.bordercolor[1] = ffw::Rgb(0x999999);
		column->Style().normal.bordersize[1] = 1;
		column->SetPadding(5);

		label = new ffw::GuiLabel(&gui, "Scrollable:");
		column->AddWidget(label);

		auto scrollable = new ffw::GuiScrollable(&gui, ffw::GuiLayout::Orientation::VERTICAL, true, true);
		scrollable->SetSize(ffw::GuiUnits::Percent(100), ffw::GuiUnits::Pixels(150));
		column->AddWidget(scrollable);

		for(int i = 0; i < 16; i++){
			auto btn = new ffw::GuiButton(&gui, "Button #" + ffw::ValToString(i));
			btn->SetSize(ffw::GuiUnits::Pixels(200), ffw::GuiUnits::Pixels(20));
			scrollable->AddWidget(btn);
		}

		bottomLayout->AddWidget(column);

		return true;
	}

    void Render() override {
        gui.Update();
		gui.PoolEvents();
		gui.Render();
	}

    void Close() override {
		gui.Destroy();
		backend.Destroy();
		delete font;
	}

    void TextInputEvent(unsigned int c) override {
		gui.InjectText(c);
	}

    void KeyPressedEvent(ffw::Key key, ffw::Mode mode) override {
		gui.InjectKey(key, mode);
		/*if(mode == ffw::Mode::PRESSED){
			if(key == ffw::Key::A){
				//btn->SetSize(btn->GetSize().x, ffw::GuiUnits::Pixels(40));
				gui.FindByID<ffw::GuiRadio>(3)->SetValue(1);
			}
			if(key == ffw::Key::S){
				//btn->SetSize(btn->GetSize().x, ffw::GuiUnits::Wrap());
				gui.FindByID<ffw::GuiRadio>(3)->SetValue(3);
			}
			if(key == ffw::Key::D){
				//btn->SetSize(btn->GetSize().x, ffw::GuiUnits::Wrap());
				gui.FindByID<ffw::GuiRadio>(3)->SetValue(0);
			}
		}*/
	}

    void MouseMovedEvent(int mousex, int mousey) override {
		gui.InjectMousePos(mousex, mousey);
	}

    void MouseScrollEvent(int scroll) override {
	}

    void MouseButtonEvent(ffw::MouseButton button, ffw::Mode mode) override {
		gui.InjectMouseButton(button, mode);
	}

    void WindowResizedEvent(int width, int height) override {
		gui.SetSize(width, height);
		gui.Redraw();
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
	ffw::GuiWindow gui;
	ffw::GuiBackendOpenGL backend;
	ffw::GuiFont* font;
	ffw::GuiSlider* mySlider;
	ffw::GuiLabel* mySliderLabel;
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
	args.size.Set(800, 600);
	args.title = "Example GUI With OpenGL";
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
