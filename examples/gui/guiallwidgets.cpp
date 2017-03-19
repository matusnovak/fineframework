#include <ffw/graphics.h>
#include <ffw/gui.h>
#include <ffw/gui/guiwindowopengl.h>
#include <chrono>
#include <thread>
#include <regex>
#include <fstream>

///=============================================================================
class App: public ffw::GLFWRenderWindow {
public:
    App(){
	}

    ~App(){
	}

	void widgetEvent(ffw::GuiEvent e){
	}

	ffw::GuiLayout* makeBox(ffw::GuiWindow* window, ffw::GuiLayout* parent, const std::string& str) {
		auto box = new ffw::GuiVerticalLayout(&gui);
		box->setSize(ffw::guiPercent(33), ffw::guiWrap());
		box->setPadding(5);
		parent->addWidget(box);

		auto label = new ffw::GuiLabel(window, str);
		box->addWidget(label);

		auto layout = new ffw::GuiVerticalLayout(window);
		layout->setStyleGroup(&boxStyle);
		layout->setSize(ffw::guiPercent(100), ffw::guiWrap());
		layout->setPadding(5);
		box->addWidget(layout);

		return layout;
    }

	bool setup() override {
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

		gui.setTheme(&ffw::GuiTheme::simpleLight);
		gui.create(this);
		gui.setSize(getSize().x, getSize().y);
		gui.setPos(0, 0);

		// The last two values indicate start and the end of the unicode
		// table to load.
		// To load ASCII only characters, enter 0 - 0x100
		// To load ASCII and Latin Extended-A, enter 0 - 0x17F
		// See "range" in: https://en.wikipedia.org/wiki/Latin_Extended-A
		if (!fontBold.createFromFile(this, "FreeSansBold.ttf", 12, 72, 0, 0x17F)) {
			std::cout << "Failed to create GUI font!" << std::endl;
		}
		if (!fontItalic.createFromFile(this, "FreeSansOblique.ttf", 12, 72, 0, 0x17F)) {
			std::cout << "Failed to create GUI font!" << std::endl;
		}
		if (!fontRegular.createFromFile(this, "FreeSans.ttf", 12, 72, 0, 0x17F)) {
			std::cout << "Failed to create GUI font!" << std::endl;
		}
		else {
			gui.setDefaultFont(&fontRegular);
		}

		boxStyle = gui.getTheme()->getStyleGroup("GUI_LAYOUT");
		boxStyle.normal.border.color = ffw::rgba(0x80808050);
		boxStyle.normal.border.size = 1;

		gui.getLayout()->setPadding(0);

		auto scroll = new ffw::GuiScrollableLayout(&gui, ffw::GuiLayout::Orientation::HORIZONTAL, false, true);
		scroll->setSize(ffw::guiPercent(100), ffw::guiPercent(100));
		gui.getLayout()->addWidget(scroll);
		scroll->getInner()->setWrap(true);

		// Buttons
		{
			auto box = makeBox(&gui, scroll->getInner(), "Button");

			auto button = new ffw::GuiButton(&gui, "Normal");
			box->addWidget(button);

			button = new ffw::GuiButton(&gui, "Hover");
			button->setHover(true);
			button->setIgnoreUserInput(true);
			box->addWidget(button);

			button = new ffw::GuiButton(&gui, "Focus");
			button->setFocus(true);
			button->setIgnoreUserInput(true);
			box->addWidget(button);

			button = new ffw::GuiButton(&gui, "Disabled");
			button->setDisabled(true);
			box->addWidget(button);
		}

		// Toogle buttons
		{
			auto box = makeBox(&gui, scroll->getInner(), "Toggle Button");

			auto button = new ffw::GuiButtonToggle(&gui, "Normal");
			box->addWidget(button);

			button = new ffw::GuiButtonToggle(&gui, "Hover");
			button->setHover(true);
			button->setIgnoreUserInput(true);
			box->addWidget(button);

			button = new ffw::GuiButtonToggle(&gui, "Focus");
			button->setFocus(true);
			button->setIgnoreUserInput(true);
			box->addWidget(button);

			button = new ffw::GuiButtonToggle(&gui, "Disabled");
			button->setDisabled(true);
			box->addWidget(button);
		}

		// Primary Buttons
		{
			auto box = makeBox(&gui, scroll->getInner(), "Primary Button");

			auto button = new ffw::GuiButtonPrimary(&gui, "Normal");
			box->addWidget(button);

			button = new ffw::GuiButtonPrimary(&gui, "Hover");
			button->setHover(true);
			button->setIgnoreUserInput(true);
			box->addWidget(button);

			button = new ffw::GuiButtonPrimary(&gui, "Focus");
			button->setFocus(true);
			button->setIgnoreUserInput(true);
			box->addWidget(button);

			button = new ffw::GuiButtonPrimary(&gui, "Disabled");
			button->setDisabled(true);
			box->addWidget(button);
		}

		// Labels
		{
			auto box = makeBox(&gui, scroll->getInner(), "Labels");

			auto label = new ffw::GuiLabel(&gui, "Left align");
			label->setAlign(ffw::GuiStyle::Align::LEFT);
			box->addWidget(label);

			label = new ffw::GuiLabel(&gui, "Center align");
			label->setAlign(ffw::GuiStyle::Align::CENTER);
			box->addWidget(label);

			label = new ffw::GuiLabel(&gui, "Right align");
			label->setAlign(ffw::GuiStyle::Align::RIGHT);
			box->addWidget(label);

			label = new ffw::GuiLabel(&gui, "First line\nSecond line");
			box->addWidget(label);
		}

		// Radios
		{
			auto box = makeBox(&gui, scroll->getInner(), "Radio");

			auto radio = new ffw::GuiRadio(&gui, "Normal", 0, NULL);
			box->addWidget(radio);

			radio = new ffw::GuiRadio(&gui, "Hover", 0, NULL);
			radio->setHover(true);
			radio->setIgnoreUserInput(true);
			box->addWidget(radio);

			radio = new ffw::GuiRadio(&gui, "Focus", 0, NULL);
			radio->setFocus(true);
			radio->setIgnoreUserInput(true);
			box->addWidget(radio);

			radio = new ffw::GuiRadio(&gui, "Disabled", 0, NULL);
			radio->setDisabled(true);
			box->addWidget(radio);
		}

		// Checkboxes
		{
			auto box = makeBox(&gui, scroll->getInner(), "Checkbox");

			auto checkbox = new ffw::GuiCheckbox(&gui, "Normal");
			box->addWidget(checkbox);

			checkbox = new ffw::GuiCheckbox(&gui, "Hover");
			checkbox->setHover(true);
			checkbox->setIgnoreUserInput(true);
			box->addWidget(checkbox);

			checkbox = new ffw::GuiCheckbox(&gui, "Focus");
			checkbox->setFocus(true);
			checkbox->setIgnoreUserInput(true);
			box->addWidget(checkbox);

			checkbox = new ffw::GuiCheckbox(&gui, "Disabled");
			checkbox->setDisabled(true);
			box->addWidget(checkbox);
		}

		// Sliders
		{
			auto box = makeBox(&gui, scroll->getInner(), "Horizontal Sliders");

			auto label = new ffw::GuiLabel(&gui, "Normal:");
			box->addWidget(label);

			auto slider = new ffw::GuiSlider(&gui, false);
			box->addWidget(slider);

			label = new ffw::GuiLabel(&gui, "Normal inversed:");
			box->addWidget(label);

			slider = new ffw::GuiSlider(&gui, false);
			slider->setInversed(true);
			box->addWidget(slider);

			label = new ffw::GuiLabel(&gui, "Hover:");
			box->addWidget(label);

			slider = new ffw::GuiSlider(&gui, false);
			slider->setHover(true);
			slider->setIgnoreUserInput(true);
			box->addWidget(slider);

			label = new ffw::GuiLabel(&gui, "Focus:");
			box->addWidget(label);

			slider = new ffw::GuiSlider(&gui, false);
			slider->setFocus(true);
			slider->setIgnoreUserInput(true);
			box->addWidget(slider);

			label = new ffw::GuiLabel(&gui, "Disabled:");
			box->addWidget(label);

			slider = new ffw::GuiSlider(&gui, false);
			slider->setDisabled(true);
			box->addWidget(slider);
		}

		// Vertical sliders
		{
			auto box = makeBox(&gui, scroll->getInner(), "Vertical Sliders");
			box->setSize(box->getSize().x, ffw::guiPixels(235));
			box->setOrientation(ffw::GuiLayout::Orientation::HORIZONTAL);

			auto slider = new ffw::GuiSlider(&gui, true);
			box->addWidget(slider);

			slider = new ffw::GuiSlider(&gui, true);
			slider->setInversed(true);
			box->addWidget(slider);

			slider = new ffw::GuiSlider(&gui, true);
			slider->setHover(true);
			slider->setIgnoreUserInput(true);
			box->addWidget(slider);

			slider = new ffw::GuiSlider(&gui, true);
			slider->setFocus(true);
			slider->setIgnoreUserInput(true);
			box->addWidget(slider);

			slider = new ffw::GuiSlider(&gui, true);
			slider->setDisabled(true);
			box->addWidget(slider);
		}

		// Scrollbars
		{
			auto box = makeBox(&gui, scroll->getInner(), "Scrollbars");
			box->setSize(box->getSize().x, ffw::guiPixels(235));
			box->setOrientation(ffw::GuiLayout::Orientation::HORIZONTAL);
			box->setWrap(true);

			auto label = new ffw::GuiLabel(&gui, "Normal:");
			box->addWidget(label);

			auto scrollbar = new ffw::GuiScrollBar(&gui, false);
			box->addWidget(scrollbar);

			label = new ffw::GuiLabel(&gui, "Hover:");
			box->addWidget(label);

			scrollbar = new ffw::GuiScrollBar(&gui, false);
			scrollbar->setHover(true);
			scrollbar->setIgnoreUserInput(true);
			box->addWidget(scrollbar);

			label = new ffw::GuiLabel(&gui, "Focus:");
			box->addWidget(label);

			scrollbar = new ffw::GuiScrollBar(&gui, false);
			scrollbar->setFocus(true);
			scrollbar->setIgnoreUserInput(true);
			box->addWidget(scrollbar);

			label = new ffw::GuiLabel(&gui, "Disabled:");
			box->addWidget(label);

			scrollbar = new ffw::GuiScrollBar(&gui, false);
			scrollbar->setDisabled(true);
			box->addWidget(scrollbar);
		}

		// Scrollbars
		{
			auto box = makeBox(&gui, scroll->getInner(), "Image Viewer");
			box->setSize(box->getSize().x, ffw::guiPixels(198));
			box->setOrientation(ffw::GuiLayout::Orientation::HORIZONTAL);
			box->setWrap(true);

			// 360x240 RGB (8-bit per channel)
			std::unique_ptr<unsigned char> pixels(new unsigned char[360 * 240 * 3]);
			std::ifstream input("owl.raw", std::ios::in | std::ios::binary);

			// Checks needs to be done but none are written,
			// just for the purpose of the example
			input.read((char*)pixels.get(), 360 * 240 * 3);

			// Custom GuiImageOpenGL wrapper around GuiImage interface
			image.create(this, 360, 240, GL_RGB8, GL_RGB, GL_UNSIGNED_BYTE);
			image.setPixels(0, 0, 0, 360, 240, pixels.get());
			
			auto viewer = new ffw::GuiImageViewer(&gui, &image);
			box->addWidget(viewer);

			auto label = new ffw::GuiLabel(&gui, "Subsection:");
			box->addWidget(label);

			viewer = new ffw::GuiImageViewer(&gui, &image);
			box->addWidget(viewer);
			viewer->setSize(ffw::guiPixels(80), ffw::guiWrap());
			viewer->setSubsection(140, 40, 130, 80);
			viewer->setMirror(true, false);
		}

		// Text Input
		{
			auto box = makeBox(&gui, scroll->getInner(), "Text Input");

			auto label = new ffw::GuiLabel(&gui, "Normal:");
			box->addWidget(label);

			auto input = new ffw::GuiTextInput(&gui, false, true);
			input->setValue(L"Hello World!");
			box->addWidget(input);

			label = new ffw::GuiLabel(&gui, "Hover:");
			box->addWidget(label);

			input = new ffw::GuiTextInput(&gui, false, true);
			input->setValue(L"Hello World!");
			input->setHover(true);
			input->setIgnoreUserInput(true);
			box->addWidget(input);

			label = new ffw::GuiLabel(&gui, "Focus:");
			box->addWidget(label);

			input = new ffw::GuiTextInput(&gui, false, true);
			input->setValue(L"Hello World!");
			input->setFocus(true);
			input->setIgnoreUserInput(true);
			box->addWidget(input);

			label = new ffw::GuiLabel(&gui, "Disabled:");
			box->addWidget(label);

			input = new ffw::GuiTextInput(&gui, false, true);
			input->setValue(L"Hello World!");
			input->setDisabled(true);
			box->addWidget(input);
		}

		// Text Input
		{
			auto box = makeBox(&gui, scroll->getInner(), "Text Input + match");

			auto label = new ffw::GuiLabel(&gui, "Integers:");
			box->addWidget(label);

			auto input = new ffw::GuiTextInput(&gui, false, true);
			input->setValue(L"-0123");
			// Zero or one '-' following by any number of digits
			input->setMatch(L"^-?[0-9]*$");
			box->addWidget(input);

			label = new ffw::GuiLabel(&gui, "Decimals:");
			box->addWidget(label);

			input = new ffw::GuiTextInput(&gui, false, true);
			input->setValue(L"-0.6662");
			// Zero or one '-' following by any number of digits
			// then zero or one dot then again, any digit.
			input->setMatch(L"^-?[0-9]*\\.?[0-9]*$");
			box->addWidget(input);

			label = new ffw::GuiLabel(&gui, "Capitals:");
			box->addWidget(label);

			input = new ffw::GuiTextInput(&gui, false, true);
			input->setValue(L"HELLO WORLD");
			// Any capital character and whitespace
			input->setMatch(L"[A-Z\\s]*");
			box->addWidget(input);

			label = new ffw::GuiLabel(&gui, "No special characters:");
			box->addWidget(label);

			input = new ffw::GuiTextInput(&gui, false, true);
			input->setValue(L"Hello World");
			// Any capital or lowercase character including digit and whitespace
			input->setMatch(L"[A-Z|a-z|0-9|\\s]*");
			box->addWidget(input);
		}

		// Text Input Multiline
		{
			auto box = makeBox(&gui, scroll->getInner(), "Multiline Text Input");

			auto area = new ffw::GuiTextInput(&gui, true, true);
			area->setValue(L"Lorem ipsum dolor sit amet, consectetur adipiscing elit.\nEtiam cursus odio ut dui malesuada imperdiet.\nNullam ac augue volutpat, aliquam ante sit amet, efficitur ipsum.");
			box->addWidget(area);
		}

		// Text Area
		{
			auto box = makeBox(&gui, scroll->getInner(), "Text Area");

			auto area = new ffw::GuiTextArea(&gui, true);
			area->setSize(ffw::guiPercent(100), ffw::guiPixels(75));
			area->setValue(L"Lorem ipsum dolor sit amet, consectetur adipiscing elit.\nEtiam cursus odio ut dui malesuada imperdiet. ");
			box->addWidget(area);

			area = new ffw::GuiTextArea(&gui, true);
			area->setSize(ffw::guiPercent(100), ffw::guiPixels(75));
			area->setDisabled(true);
			area->setValue(L"Lorem ipsum dolor sit amet, consectetur adipiscing elit.\nEtiam cursus odio ut dui malesuada imperdiet. ");
			box->addWidget(area);
		}

		// List
		{
			auto box = makeBox(&gui, scroll->getInner(), "List");

			auto list = new ffw::GuiList(&gui);
			list->setSize(ffw::guiPercent(100), ffw::guiPixels(75));
			list->addItem("First");
			auto item = list->addItem("Second");
			item->setDisabled(true);
			auto selected = list->addItem("Third");
			list->addItem("Fourth");
			list->addItem("Fifth");
			list->setSelected(selected);
			box->addWidget(list);

			list = new ffw::GuiList(&gui);
			list->setSize(ffw::guiPercent(100), ffw::guiPixels(75));
			list->addItem("First");
			list->addItem("Second");
			list->addItem("Third");
			list->addItem("Fourth");
			list->addItem("Fifth");
			list->setDisabled(true);
			box->addWidget(list);
		}

		// Switch
		{
			auto box = makeBox(&gui, scroll->getInner(), "Switch");

			auto label = new ffw::GuiLabel(&gui, "Normal:");
			box->addWidget(label);

			auto button = new ffw::GuiSwitch(&gui);
			box->addWidget(button);

			label = new ffw::GuiLabel(&gui, "Hover:");
			box->addWidget(label);

			button = new ffw::GuiSwitch(&gui);
			button->setHover(true);
			button->setIgnoreUserInput(true);
			box->addWidget(button);

			label = new ffw::GuiLabel(&gui, "Focus:");
			box->addWidget(label);

			button = new ffw::GuiSwitch(&gui);
			button->setFocus(true);
			button->setIgnoreUserInput(true);
			box->addWidget(button);

			label = new ffw::GuiLabel(&gui, "Disabled:");
			box->addWidget(label);

			button = new ffw::GuiSwitch(&gui);
			button->setDisabled(true);
			box->addWidget(button);
		}

		// Progress bar
		{
			auto box = makeBox(&gui, scroll->getInner(), "Progress Bar");

			auto label = new ffw::GuiLabel(&gui, "Normal 0%:");
			box->addWidget(label);

			auto progress = new ffw::GuiProgressBar(&gui);
			progress->setValue(0);
			box->addWidget(progress);

			label = new ffw::GuiLabel(&gui, "Normal 50%:");
			box->addWidget(label);

			progress = new ffw::GuiProgressBar(&gui);
			progress->setValue(50);
			box->addWidget(progress);

			label = new ffw::GuiLabel(&gui, "Normal 100%:");
			box->addWidget(label);

			progress = new ffw::GuiProgressBar(&gui);
			progress->setValue(75);
			box->addWidget(progress);

			label = new ffw::GuiLabel(&gui, "Disabled 50%:");
			box->addWidget(label);

			progress = new ffw::GuiProgressBar(&gui);
			progress->setValue(50);
			progress->setDisabled(true);
			box->addWidget(progress);
		}

		// Progress circle
		{
			auto box = makeBox(&gui, scroll->getInner(), "Progress Circle");

			auto label = new ffw::GuiLabel(&gui, "Normal 75%:");
			box->addWidget(label);

			auto progress = new ffw::GuiProgressCircle(&gui);
			progress->setValue(75);
			box->addWidget(progress);

			label = new ffw::GuiLabel(&gui, "Disabled 33%:");
			box->addWidget(label);

			progress = new ffw::GuiProgressCircle(&gui);
			progress->setValue(33);
			progress->setDisabled(true);
			box->addWidget(progress);
		}

		// Scrollable
		{
			auto box = makeBox(&gui, scroll->getInner(), "Scrollable");

			auto scrollable = new ffw::GuiScrollableLayout(&gui, ffw::GuiLayout::Orientation::VERTICAL, true, true);
			box->addWidget(scrollable);

			for (int i = 0; i < 8; i++) {
				auto button = new ffw::GuiButton(&gui, "Button");
				scrollable->getInner()->addWidget(button);
			}
		}

		// Tabs
		{
			auto box = makeBox(&gui, scroll->getInner(), "Tabs");

			auto tabs = new ffw::GuiTabs(&gui);
			box->addWidget(tabs);

			auto layout = new ffw::GuiVerticalLayout(&gui);
			tabs->addTab("First", layout);

			layout->addWidget(new ffw::GuiLabel(&gui, "This is the first tab."));
			layout->addWidget(new ffw::GuiLabel(&gui, "You can put any widget\nin here!\n\nWorks like a charm!"));

			layout = new ffw::GuiVerticalLayout(&gui);
			tabs->addTab("Second", layout);

			layout->addWidget(new ffw::GuiLabel(&gui, "This is the second tab."));
			layout->addWidget(new ffw::GuiLabel(&gui, "With some more text.\nWith some more text.\nWith some more text.\nWith some more text.\n"));

			layout = new ffw::GuiVerticalLayout(&gui);
			tabs->addTab("Third", layout);

			layout->addWidget(new ffw::GuiLabel(&gui, "This is the last tab.\nWith extra button:"));
			layout->addWidget(new ffw::GuiButton(&gui, "button"));
		}

		// Rich Text
		{
			auto box = makeBox(&gui, scroll->getInner(), "Rich Text");

			auto richText = new ffw::GuiRichText(&gui);
			box->addWidget(richText);
			
			richText->addParagraph();
			richText->addSectionDefault();
			richText->addText(L"This is a rich text widget which can have ");
			richText->addSection(ffw::rgb(0xFF0000), NULL);
			richText->addText(L"different ");
			richText->addSection(ffw::rgb(0x0000FF), NULL);
			richText->addText(L"colors ");
			richText->addSectionDefault();
			richText->addText(L"and wraps based on whitespace!");

			richText->addParagraph();
			richText->addSectionDefault();
			richText->addText(L"And even can have ");
			richText->addSection(&fontBold);
			richText->addText(L"different fonts ");
			richText->addSection(ffw::rgb(0x007F00), &fontItalic);
			richText->addText(L"or even with colors!");
		}

		return true;
	}

    void render() override {
        gui.update();
		gui.poolEvents();
		gui.render();
		// Uncomment this to see what's being updated
		// and what isn't
		// this->setDrawColor(ffw::rgba(0x00000001));
		// this->drawRectangle(0, 0, getSize().x, getSize().y);
	}

    void close() override {
		gui.destroy();
		fontRegular.destroy();
		fontItalic.destroy();
		fontBold.destroy();
	}

    void textInputEvent(unsigned int c) override {
		gui.injectText(c);
	}

    void keyPressedEvent(ffw::Key key, ffw::Mode mode) override {
		gui.injectKey(key, mode);
	}

    void mouseMovedEvent(int mousex, int mousey) override {
		gui.injectMousePos(mousex, mousey);
	}

    void mouseScrollEvent(int scroll) override {
	}

    void mouseButtonEvent(ffw::MouseButton button, ffw::Mode mode) override {
		gui.injectMouseButton(button, mode);
	}

    void windowResizedEvent(int width, int height) override {
		gui.setSize(width, height);
		gui.redraw();
	}

    void windowMovedEvent(int windowx, int windowy) override {
	}

    void windowFocusEvent(bool focus) override {
	}

    void windowCloseEvent() override {
		this->shouldClose(true);
	}

    void filesDroppedEvent(std::vector<std::string> filelist) override {
	}

private:
	ffw::GuiWindowOpenGL gui;
	ffw::GuiFontOpenGL fontRegular;
	ffw::GuiFontOpenGL fontItalic;
	ffw::GuiFontOpenGL fontBold;
	ffw::GuiStyleGroup boxStyle;
	ffw::GuiImageOpenGL image;
};

///=============================================================================
int main(int argc, char *argv[]){
	// Instance to our app class
	App app;

	// set arguments
	ffw::GLFWRenderWindowArgs args;
	args.size.set(600, 600);
	args.title = "Example GUI With OpenGL";
	args.samples = 4;

	// create window
	if(!app.create(args, NULL)){
		std::cerr << "Failed to create window!" << std::endl;
		return 1;
	}

	// Run setup
	if(!app.setup()){
		std::cerr << "Failed to setup window!" << std::endl;
		return 1;
	}

	app.setSingleBufferMode(true);

	// The main window loop
	while(app.shouldRender()){
		app.renderFrame();
		app.waitForEvents();
		//std::this_thread::sleep_for(std::chrono::milliseconds(10));
	}

	// destroy window, this will delete all graphics data used by the window.
	// Must be called after the setup and before the graphics
	// is terminated
	app.destroy();

    // Needs to be called at the end of the program if ffw::initGraphics() succeeds
	system("pause");
	return 0;
}
