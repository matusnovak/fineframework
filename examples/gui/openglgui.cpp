#include <ffw/graphics.h>
#include <ffw/gui.h>

///=============================================================================
class App: public ffw::AppRenderWindow {
public:
    App(){
		font = NULL;
	}

    ~App(){
	}

	void WidgetEvent(ffw::GuiEvent e){
		if (e.widget == myRadio && e.type == ffw::GuiEvent::Type::CHANGED) {
			std::cout << "Radio group value changed to: " << e.data.changed.value << std::endl;
		}
	}

    bool Setup() override {
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

		gui.Create(this);
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

		gui.SetPadding(5);

		auto topLayout = new ffw::GuiHorizontalLayout(&gui);
		topLayout->SetSize(ffw::GuiPercent(100), ffw::GuiPercent(50));
		topLayout->SetPadding(5);

		auto bottomLayout = new ffw::GuiHorizontalLayout(&gui);
		bottomLayout->SetSize(ffw::GuiPercent(100), ffw::GuiPercent(50));
		bottomLayout->SetPadding(5);

		gui.AddWidget(topLayout);
		gui.AddWidget(bottomLayout);

		// Copy default style from window for GuiLayout widget
		static ffw::GuiStyleGroup customStyle = gui.GetTheme()->GetByWidget<ffw::GuiLayout>();
		customStyle.normal.border.size = 1;
		customStyle.normal.border.color = ffw::Rgba(0xADADAD80);

		// Top Column #1 - Buttons and Toggle Buttons
		auto column = new ffw::GuiLayout(&gui, ffw::GuiLayout::Orientation::VERTICAL);
		column->SetSize(ffw::GuiPercent(25), ffw::GuiPercent(100));
		column->SetPadding(5);
		column->SetStyleGroup(&customStyle);
		topLayout->AddWidget(column);

		auto label = new ffw::GuiLabel(&gui, "Buttons:");
		column->AddWidget(label);

		auto button = new ffw::GuiButton(&gui, "Button #1");
		button->SetAlign(ffw::GuiAlign::LEFT);
		button->AddEventCallback(&App::WidgetEvent, this);
		column->AddWidget(button);

		button = new ffw::GuiButton(&gui, "Button #2");
		button->SetAlign(ffw::GuiAlign::CENTER);
		button->AddEventCallback(&App::WidgetEvent, this);
		column->AddWidget(button);

		button = new ffw::GuiButton(&gui, "Button #3");
		button->SetAlign(ffw::GuiAlign::RIGHT);
		column->AddWidget(button);

		label = new ffw::GuiLabel(&gui, "Toggle Buttons:");
		column->AddWidget(label);

		auto buttontoggle = new ffw::GuiButtonToggle(&gui, "Button Toggle #1");
		//buttontoggle->Style().normal.textcolor = ffw::Rgb(0xFF0000);
		column->AddWidget(buttontoggle);

		buttontoggle = new ffw::GuiButtonToggle(&gui, "Button Toggle #2");
		//buttontoggle->Style().normal.textcolor = ffw::Rgb(0x00FF00);
		column->AddWidget(buttontoggle);

		buttontoggle = new ffw::GuiButtonToggle(&gui, "Button Toggle #3");
		//buttontoggle->Style().normal.textcolor = ffw::Rgb(0x0000FF);
		column->AddWidget(buttontoggle);

		label = new ffw::GuiLabel(&gui, "Switch:");
		column->AddWidget(label);

		/*auto switchbtn = new ffw::GuiSwitch(&gui);
		switchbtn->SetValue(true);
		column->AddWidget(switchbtn);

		switchbtn = new ffw::GuiSwitch(&gui);
		switchbtn->SetSize(ffw::GuiUnits::Pixels(50), ffw::GuiUnits::Pixels(16));
		column->AddWidget(switchbtn);*/

		// Top Column #2 - Checkboxes and Radios
		column = new ffw::GuiLayout(&gui, ffw::GuiLayout::Orientation::HORIZONTAL);
		column->SetSize(ffw::GuiPercent(25), ffw::GuiPercent(100));
		column->SetStyleGroup(&customStyle);
		column->SetPadding(5);
		column->SetWrap(true);
		topLayout->AddWidget(column);

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
		// You need to assign a SetOnValueChangedCallback
		// only to one radio from the group.
		// The callback will be internally linked between all radios.
		// This does not apply for SetOnClickCallback!
		radio->AddEventCallback(&App::WidgetEvent, this);
		myRadio = radio;
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
		label->SetSize(ffw::GuiPercent(100), ffw::GuiPixels(30));
		label->SetAlign(ffw::GuiAlign::BOTTOM_CENTER);
		//label->Style().normal.textcolor = ffw::Rgb(0xCC4444);
		//label->Style().normal.backgroundcolor = ffw::Rgba(0xCC44441F);
		//label->Style().normal.background = true;
		column->AddWidget(label);

		label = new ffw::GuiLabel(&gui, "Label #2");
		label->SetSize(ffw::GuiWrap(), ffw::GuiWrap());
		//label->Style().normal.textcolor = ffw::Rgb(0x44CC44);
		//label->Style().normal.backgroundcolor = ffw::Rgba(0x44CC441F);
		//label->Style().normal.background = true;
		column->AddWidget(label);

		label = new ffw::GuiLabel(&gui, "Label #3");
		label->SetSize(ffw::GuiWrap(), ffw::GuiWrap());
		//label->Style().normal.textcolor = ffw::Rgb(0x4444CC);
		//label->Style().normal.backgroundcolor = ffw::Rgba(0x4444CC1F);
		//label->Style().normal.background = true;
		column->AddWidget(label);

		label = new ffw::GuiLabel(&gui, "Label #4");
		label->SetSize(ffw::GuiWrap(), ffw::GuiWrap());
		//label->Style().normal.backgroundcolor = ffw::Rgba(0x4444441F);
		//label->Style().normal.background = true;
		column->AddWidget(label);

		return true;
	}

    void Render() override {
        gui.Update();
		gui.PoolEvents();
		gui.Render();
		// Uncomment this to see what's being updated
		// and what isn't
		//ffw::SetDrawColor(ffw::Rgba(0x00000001));
		//ffw::DrawRectangle(0, 0, GetSize().x, GetSize().y);
	}

    void Close() override {
		gui.Destroy();
		if(font != NULL)delete font;
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
	ffw::GuiWindowOpenGL gui;
	ffw::GuiFont* font;
	ffw::GuiRadio* myRadio;
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
