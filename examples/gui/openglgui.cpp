#include <ffw/graphics.h>
#include <ffw/gui.h>

///=============================================================================
class App: public ffw::AppRenderWindow {
public:
    App(){
	}

    ~App(){
	}

	void WidgetCallback(ffw::GuiEvent e){
		if(e.widget->GetID() == 1){
			std::cout << "BTN 1" << std::endl;
		} else if(e.widget->GetID() == 2){
			std::cout << "BTN 2" << std::endl;
		} else if(e.widget->GetID() >= 3 && e.widget->GetID() <= 5){
			std::cout << "RADIO: " << e.widget->GetID() << " value: " << dynamic_cast<ffw::GuiRadio*>(e.widget)->GetValue() << std::endl;
		} else {
			std::cout << "UNKNOWN: " << e.widget->GetID() << std::endl;
		}
	}

    bool Setup() override {
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

		backend.Create(this);
		gui.SetBackend(&backend);
		gui.SetSize(GetSize().x, GetSize().y);
		gui.SetPos(0, 0);

		font = gui.CreateFontFromFile("FreeSans.ttf", 12, 72);
		if(font == NULL){
			std::cout << "Failed to create GUI font!" << std::endl;
		} else {
			gui.SetDefaultFont(font);
		}

		auto layout = new ffw::GuiLayout(&gui, ffw::GuiLayout::Orientation::VERTICAL);
		layout->SetSize(ffw::GuiUnits::Percent(100), ffw::GuiUnits::Percent(100));
		//layout->SetPadding(10);
		//layout->style.normal.border = true;
		layout->style.normal.bordercolor = ffw::Rgb(0xFF0000);
		gui.AddWidget(layout);

		auto column = new ffw::GuiLayout(&gui, ffw::GuiLayout::Orientation::VERTICAL);
		lay = column;
		column->SetSize(ffw::GuiUnits::Wrap(), ffw::GuiUnits::Wrap());
		column->SetMargin(10);
		column->SetPadding(10);
		column->style.normal.border = true;
		column->style.normal.bordersize = 1;
		column->style.normal.bordercolor = ffw::Rgb(0x00FF00);
		layout->AddWidget(column);

		auto layer = new ffw::GuiLayout(&gui, ffw::GuiLayout::Orientation::VERTICAL);
		//lay = layer;
		layer->SetSize(ffw::GuiUnits::Wrap(), ffw::GuiUnits::Wrap());
		layer->SetPadding(15);
		layer->style.normal.border = true;
		layer->style.normal.bordercolor = ffw::Rgb(0x0000FF);
		layer->style.normal.borderradius = 20;
		layer->style.normal.bordersize = 2;
		column->AddWidget(layer);

		auto button = new ffw::GuiButton(&gui, "Button #1");
		button->SetID(1);
		btn = button;
		button->SetOnClickCallback(&App::WidgetCallback, this);
		layer->AddWidget(button);

		auto checkbox = new ffw::GuiCheckbox(&gui, "Checkbox #1");
		checkbox->SetID(2);
		checkbox->SetOnClickCallback(&App::WidgetCallback, this);
		layer->AddWidget(checkbox);

		auto radio = new ffw::GuiRadio(&gui, "Radio #1", 1);
		radio->SetID(3);
		radio->SetOnClickCallback(&App::WidgetCallback, this);
		layer->AddWidget(radio);

		radio = new ffw::GuiRadio(&gui, "Radio #2", 2, radio);
		radio->SetID(4);
		radio->SetOnClickCallback(&App::WidgetCallback, this);
		layer->AddWidget(radio);

		radio = new ffw::GuiRadio(&gui, "Radio #3", 3, radio);
		radio->SetID(5);
		radio->SetOnClickCallback(&App::WidgetCallback, this);
		layer->AddWidget(radio);

		/*auto text = new ffw::GuiTextArea(&gui, "First Line\r\nSecond line\r\nThird Line\r\n\r\nEnd of line");
		text->SetSize(200, 200);
		text->SetID(5);
		layer->AddWidget(text);*/

		/*auto progressbar = new ffw::GuiProgressBar(&gui, "Downloading...");
		progressbar->SetSize(200, 20);
		progressbar->SetID(6);
		layer->AddWidget(progressbar);*/

		auto slider = new ffw::GuiSlider(&gui, true);
		slider->SetSize(200, ffw::GuiUnits::Wrap());
		layer->AddWidget(slider);

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
		auto offset = lay->GetOffset();
		offset.x += scroll*5;
		lay->SetOffset(offset);
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
	ffw::GuiButton* btn;
	ffw::GuiLayout* lay;
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
