#include <ffw/graphics.h>
#include <ffw/gui.h>
#include <ffw/gui/guiwindowopengl.h>
#include <regex>
#include <fstream>
#include <memory>
#include <iostream>

///=============================================================================
class App: public ffw::GLFWRenderWindow {
public:
    App(){
    }

    ~App(){
    }

    bool setup() override {
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

        gui.setTheme(&ffw::GuiThemeSimpleLight::singleton);
        gui.create(this);
        gui.setSize(float(getSize().x), float(getSize().y));
        gui.setPos(0, 0);

        // The last two values indicate start and the end of the unicode
        // table to load.
        // To load ASCII only characters, enter 0 - 0x100
        // To load ASCII and Latin Extended-A, enter 0 - 0x17F
        // See "range" in: https://en.wikipedia.org/wiki/Latin_Extended-A
        if (!fontBold.createFromFile("FreeSansBold.ttf", 12, 72, 0, 0x17F)) {
            std::cout << "Failed to create bold GUI font!" << std::endl;
            return false;
        }
        if (!fontItalic.createFromFile("FreeSansOblique.ttf", 12, 72, 0, 0x17F)) {
            std::cout << "Failed to create italic GUI font!" << std::endl;
            return false;
        }
        if (!fontRegular.createFromFile("FreeSans.ttf", 12, 72, 0, 0x17F)) {
            std::cout << "Failed to create regular GUI font!" << std::endl;
            return false;
        }
        else {
            gui.setDefaultFont(&fontRegular);
        }

        gui.getLayout()->setOrientation(ffw::GuiOrientation::HORIZONTAL);
        gui.getLayout()->setPadding(ffw::guiPixels(0));
        gui.getLayout()->setWrap(true);

        auto scroll = new ffw::GuiScrollableLayout(&gui, ffw::GuiOrientation::HORIZONTAL, false, true);
        scroll->setSize(ffw::guiPercent(100), ffw::guiPercent(100));
        scroll->getInner()->setWrap(true);
        gui.getLayout()->addWidget(scroll);

        auto body = scroll->getInner();

        // Buttons
        {
            auto box = new ffw::GuiBox(&gui, "Buttons", ffw::GuiOrientation::VERTICAL);
            box->setSize(ffw::guiPercent(32.33f), ffw::guiWrap());
            box->setMargin(0, ffw::guiPercent(0.5f), ffw::guiPixels(5), ffw::guiPercent(0.5f));

            auto button = new ffw::GuiButton(&gui, "Normal");
            box->getInner()->addWidget(button);

            button = new ffw::GuiButton(&gui, "Hover");
            button->setHover(true);
            button->setIgnoreUserInput(true);
            box->getInner()->addWidget(button);

            button = new ffw::GuiButton(&gui, "Focus");
            button->setFocus(true);
            button->setIgnoreUserInput(true);
            box->getInner()->addWidget(button);

            button = new ffw::GuiButton(&gui, "Disabled");
            button->setDisabled(true);
            box->getInner()->addWidget(button);

            body->addWidget(box);
        }

        // Toogle buttons
        {
            auto box = new ffw::GuiBox(&gui, "Toggle Buttons", ffw::GuiOrientation::VERTICAL);
            box->setSize(ffw::guiPercent(32.33f), ffw::guiWrap());
            box->setMargin(0, ffw::guiPercent(0.5f), ffw::guiPixels(5), ffw::guiPercent(0.5f));

            auto button = new ffw::GuiButtonToggle(&gui, "Normal");
            box->getInner()->addWidget(button);

            button = new ffw::GuiButtonToggle(&gui, "Hover");
            button->setHover(true);
            button->setIgnoreUserInput(true);
            box->getInner()->addWidget(button);

            button = new ffw::GuiButtonToggle(&gui, "Focus");
            button->setFocus(true);
            button->setIgnoreUserInput(true);
            box->getInner()->addWidget(button);

            button = new ffw::GuiButtonToggle(&gui, "Disabled");
            button->setDisabled(true);
            box->getInner()->addWidget(button);

            body->addWidget(box);
        }

        // Primary buttons
        {
            auto box = new ffw::GuiBox(&gui, "Primary Buttons", ffw::GuiOrientation::VERTICAL);
            box->setSize(ffw::guiPercent(32.33f), ffw::guiWrap());
            box->setMargin(0, ffw::guiPercent(0.5f), ffw::guiPixels(5), ffw::guiPercent(0.5f));

            auto button = new ffw::GuiButtonPrimary(&gui, "Normal");
            box->getInner()->addWidget(button);

            button = new ffw::GuiButtonPrimary(&gui, "Hover");
            button->setHover(true);
            button->setIgnoreUserInput(true);
            box->getInner()->addWidget(button);

            button = new ffw::GuiButtonPrimary(&gui, "Focus");
            button->setFocus(true);
            button->setIgnoreUserInput(true);
            box->getInner()->addWidget(button);

            button = new ffw::GuiButtonPrimary(&gui, "Disabled");
            button->setDisabled(true);
            box->getInner()->addWidget(button);

            body->addWidget(box);
        }

        // Labels
        {
            auto box = new ffw::GuiBox(&gui, "Labels", ffw::GuiOrientation::VERTICAL);
            box->setSize(ffw::guiPercent(32.33f), ffw::guiWrap());
            box->setMargin(0, ffw::guiPercent(0.5f), ffw::guiPixels(5), ffw::guiPercent(0.5f));

            auto label = new ffw::GuiLabel(&gui, "Left align");
            label->setAlign(ffw::GuiAlign::LEFT);
            box->getInner()->addWidget(label);

            label = new ffw::GuiLabel(&gui, "Center align");
            label->setAlign(ffw::GuiAlign::CENTER);
            box->getInner()->addWidget(label);

            label = new ffw::GuiLabel(&gui, "Right align");
            label->setAlign(ffw::GuiAlign::RIGHT);
            box->getInner()->addWidget(label);

            label = new ffw::GuiLabel(&gui, "First line\nSecond line");
            box->getInner()->addWidget(label);

            body->addWidget(box);
        }

        // Radios
        {
            auto box = new ffw::GuiBox(&gui, "Radios", ffw::GuiOrientation::VERTICAL);
            box->setSize(ffw::guiPercent(32.33f), ffw::guiWrap());
            box->setMargin(0, ffw::guiPercent(0.5f), ffw::guiPixels(5), ffw::guiPercent(0.5f));

            auto radio = new ffw::GuiRadio(&gui, "Normal", 0, nullptr);
            box->getInner()->addWidget(radio);

            radio = new ffw::GuiRadio(&gui, "Hover", 0, nullptr);
            radio->setHover(true);
            radio->setIgnoreUserInput(true);
            box->getInner()->addWidget(radio);

            radio = new ffw::GuiRadio(&gui, "Focus", 0, nullptr);
            radio->setFocus(true);
            radio->setIgnoreUserInput(true);
            box->getInner()->addWidget(radio);

            radio = new ffw::GuiRadio(&gui, "Disabled", 0, nullptr);
            radio->setDisabled(true);
            box->getInner()->addWidget(radio);

            body->addWidget(box);
        }

        // Checkboxes
        {
            auto box = new ffw::GuiBox(&gui, "Checkboxes", ffw::GuiOrientation::VERTICAL);
            box->setSize(ffw::guiPercent(32.33f), ffw::guiWrap());
            box->setMargin(0, ffw::guiPercent(0.5f), ffw::guiPixels(5), ffw::guiPercent(0.5f));

            auto checkbox = new ffw::GuiCheckbox(&gui, "Normal");
            box->getInner()->addWidget(checkbox);

            checkbox = new ffw::GuiCheckbox(&gui, "Hover");
            checkbox->setHover(true);
            checkbox->setIgnoreUserInput(true);
            box->getInner()->addWidget(checkbox);

            checkbox = new ffw::GuiCheckbox(&gui, "Focus");
            checkbox->setFocus(true);
            checkbox->setIgnoreUserInput(true);
            box->getInner()->addWidget(checkbox);

            checkbox = new ffw::GuiCheckbox(&gui, "Disabled");
            checkbox->setDisabled(true);
            box->getInner()->addWidget(checkbox);

            body->addWidget(box);
        }

        // Sliders
        {
            auto box = new ffw::GuiBox(&gui, "Horizontal Sliders", ffw::GuiOrientation::VERTICAL);
            box->setSize(ffw::guiPercent(32.33f), ffw::guiWrap());
            box->setMargin(0, ffw::guiPercent(0.5f), ffw::guiPixels(5), ffw::guiPercent(0.5f));

            auto label = new ffw::GuiLabel(&gui, "Normal:");
            box->getInner()->addWidget(label);

            auto slider = new ffw::GuiSlider(&gui, false);
            box->getInner()->addWidget(slider);

            label = new ffw::GuiLabel(&gui, "Normal inversed:");
            box->getInner()->addWidget(label);

            slider = new ffw::GuiSlider(&gui, false);
            slider->setInversed(true);
            box->getInner()->addWidget(slider);

            label = new ffw::GuiLabel(&gui, "Hover:");
            box->getInner()->addWidget(label);

            slider = new ffw::GuiSlider(&gui, false);
            slider->setHover(true);
            slider->setIgnoreUserInput(true);
            box->getInner()->addWidget(slider);

            label = new ffw::GuiLabel(&gui, "Focus:");
            box->getInner()->addWidget(label);

            slider = new ffw::GuiSlider(&gui, false);
            slider->setFocus(true);
            slider->setIgnoreUserInput(true);
            box->getInner()->addWidget(slider);

            label = new ffw::GuiLabel(&gui, "Disabled:");
            box->getInner()->addWidget(label);

            slider = new ffw::GuiSlider(&gui, false);
            slider->setDisabled(true);
            box->getInner()->addWidget(slider);

            body->addWidget(box);
        }

        // Vertical sliders
        {
            auto box = new ffw::GuiBox(&gui, "Vertical Sliders", ffw::GuiOrientation::HORIZONTAL);
            box->setSize(ffw::guiPercent(32.33f), ffw::guiWrap());
            box->setMargin(0, ffw::guiPercent(0.5f), ffw::guiPixels(5), ffw::guiPercent(0.5f));

            auto slider = new ffw::GuiSlider(&gui, true);
            slider->setSize(ffw::guiWrap(), ffw::guiPixels(235));
			slider->setMarginRight(ffw::guiPixels(10));
            box->getInner()->addWidget(slider);

            slider = new ffw::GuiSlider(&gui, true);
            slider->setSize(ffw::guiWrap(), ffw::guiPixels(235));
			slider->setMarginRight(ffw::guiPixels(10));
            slider->setInversed(true);
            box->getInner()->addWidget(slider);

            slider = new ffw::GuiSlider(&gui, true);
            slider->setSize(ffw::guiWrap(), ffw::guiPixels(235));
			slider->setMarginRight(ffw::guiPixels(10));
            slider->setHover(true);
            slider->setIgnoreUserInput(true);
            box->getInner()->addWidget(slider);

            slider = new ffw::GuiSlider(&gui, true);
            slider->setSize(ffw::guiWrap(), ffw::guiPixels(235));
			slider->setMarginRight(ffw::guiPixels(10));
            slider->setFocus(true);
            slider->setIgnoreUserInput(true);
            box->getInner()->addWidget(slider);

            slider = new ffw::GuiSlider(&gui, true);
            slider->setSize(ffw::guiWrap(), ffw::guiPixels(235));
            slider->setDisabled(true);
            box->getInner()->addWidget(slider);

            body->addWidget(box);
        }

        // Scrollbars
        {
            auto box = new ffw::GuiBox(&gui, "Scrollbars", ffw::GuiOrientation::VERTICAL);
            box->setSize(ffw::guiPercent(32.33f), ffw::guiWrap());
            box->setMargin(0, ffw::guiPercent(0.5f), ffw::guiPixels(5), ffw::guiPercent(0.5f));

            auto label = new ffw::GuiLabel(&gui, "Normal:");
            box->getInner()->addWidget(label);

            auto scrollbar = new ffw::GuiScrollBar(&gui, false);
            box->getInner()->addWidget(scrollbar);

            label = new ffw::GuiLabel(&gui, "Hover:");
            box->getInner()->addWidget(label);

            scrollbar = new ffw::GuiScrollBar(&gui, false);
            scrollbar->setHover(true);
            scrollbar->setIgnoreUserInput(true);
            box->getInner()->addWidget(scrollbar);

            label = new ffw::GuiLabel(&gui, "Focus:");
            box->getInner()->addWidget(label);

            scrollbar = new ffw::GuiScrollBar(&gui, false);
            scrollbar->setFocus(true);
            scrollbar->setIgnoreUserInput(true);
            box->getInner()->addWidget(scrollbar);

            label = new ffw::GuiLabel(&gui, "Disabled:");
            box->getInner()->addWidget(label);

            scrollbar = new ffw::GuiScrollBar(&gui, false);
            scrollbar->setDisabled(true);
            box->getInner()->addWidget(scrollbar);

            body->addWidget(box);
        }

        // Image viewer
        {
            auto box = new ffw::GuiBox(&gui, "Image Viewer", ffw::GuiOrientation::VERTICAL);
            box->setSize(ffw::guiPercent(32.33f), ffw::guiWrap());
            box->setMargin(0, ffw::guiPercent(0.5f), ffw::guiPixels(5), ffw::guiPercent(0.5f));

            // 360x240 RGB (8-bit per channel)
            std::unique_ptr<unsigned char> pixels(new unsigned char[360 * 240 * 3]);
            std::ifstream input("owl.raw", std::ios::in | std::ios::binary);

            // Checks needs to be done but none are written,
            // just for the purpose of the example
            input.read((char*)pixels.get(), 360 * 240 * 3);

            // Custom GuiImageOpenGL wrapper around GuiImage interface
            image.create(360, 240, GL_RGB8, GL_RGB, GL_UNSIGNED_BYTE);
            image.setPixels(0, 0, 0, 360, 240, pixels.get());

            auto viewer = new ffw::GuiImageViewer(&gui, &image);
            box->getInner()->addWidget(viewer);

            auto label = new ffw::GuiLabel(&gui, "Subsection:");
            box->getInner()->addWidget(label);

            viewer = new ffw::GuiImageViewer(&gui, &image);
            box->getInner()->addWidget(viewer);
            viewer->setSize(ffw::guiPixels(80), ffw::guiWrap());
            viewer->setSubsection(140, 40, 130, 80);
            viewer->setMirror(true, false);

            body->addWidget(box);
        }

        // Text Input
        {
            auto box = new ffw::GuiBox(&gui, "Text Input", ffw::GuiOrientation::VERTICAL);
            box->setSize(ffw::guiPercent(32.33f), ffw::guiWrap());
            box->setMargin(0, ffw::guiPercent(0.5f), ffw::guiPixels(5), ffw::guiPercent(0.5f));

            auto label = new ffw::GuiLabel(&gui, "Normal:");
            box->getInner()->addWidget(label);

            auto input = new ffw::GuiTextInput(&gui, false, true);
            input->setValue("Hello World!");
            box->getInner()->addWidget(input);

            label = new ffw::GuiLabel(&gui, "Hover:");
            box->getInner()->addWidget(label);

            input = new ffw::GuiTextInput(&gui, false, true);
            input->setValue("Hello World!");
            input->setHover(true);
            input->setIgnoreUserInput(true);
            box->getInner()->addWidget(input);

            label = new ffw::GuiLabel(&gui, "Focus:");
            box->getInner()->addWidget(label);

            input = new ffw::GuiTextInput(&gui, false, true);
            input->setValue("Hello World!");
            input->setFocus(true);
            input->setIgnoreUserInput(true);
            box->getInner()->addWidget(input);

            label = new ffw::GuiLabel(&gui, "Disabled:");
            box->getInner()->addWidget(label);

            input = new ffw::GuiTextInput(&gui, false, true);
            input->setValue("Hello World!");
            input->setDisabled(true);
            box->getInner()->addWidget(input);

            body->addWidget(box);
        }

        // Text Input
        {
            auto box = new ffw::GuiBox(&gui, "Text Inpuut with regex", ffw::GuiOrientation::VERTICAL);
            box->setSize(ffw::guiPercent(32.33f), ffw::guiWrap());
            box->setMargin(0, ffw::guiPercent(0.5f), ffw::guiPixels(5), ffw::guiPercent(0.5f));

            auto label = new ffw::GuiLabel(&gui, "Integers:");
            box->getInner()->addWidget(label);

            auto input = new ffw::GuiTextInput(&gui, false, true);
            input->setValue("-0123");
            // Zero or one '-' following by any number of digits
            input->setMatch("^-?[0-9]*$");
            box->getInner()->addWidget(input);

            label = new ffw::GuiLabel(&gui, "Decimals:");
            box->getInner()->addWidget(label);

            input = new ffw::GuiTextInput(&gui, false, true);
            input->setValue("-0.6662");
            // Zero or one '-' following by any number of digits
            // then zero or one dot then again, any digit.
            input->setMatch("^-?[0-9]*\\.?[0-9]*$");
            box->getInner()->addWidget(input);

            label = new ffw::GuiLabel(&gui, "Capitals:");
            box->getInner()->addWidget(label);

            input = new ffw::GuiTextInput(&gui, false, true);
            input->setValue("HELLO WORLD");
            // Any capital character and whitespace
            input->setMatch("[A-Z\\s]*");
            box->getInner()->addWidget(input);

            label = new ffw::GuiLabel(&gui, "No special characters:");
            box->getInner()->addWidget(label);

            input = new ffw::GuiTextInput(&gui, false, true);
            input->setValue("Hello World");
            // Any capital or lowercase character including digit and whitespace
            input->setMatch("[A-Z|a-z|0-9|\\s]*");
            box->getInner()->addWidget(input);

            body->addWidget(box);
        }

        // Text Input Multiline
        {
            auto box = new ffw::GuiBox(&gui, "Multiline Text Input", ffw::GuiOrientation::VERTICAL);
            box->setSize(ffw::guiPercent(32.33f), ffw::guiWrap());
            box->setMargin(0, ffw::guiPercent(0.5f), ffw::guiPixels(5), ffw::guiPercent(0.5f));

            auto area = new ffw::GuiTextInput(&gui, true);
            // UTF-8 encoded string...
            area->setValue("\x4C\xC5\x8F\xC5\x99\xC4\x95\x6D\x20\x69\x70\xC5\xA1\xC3\xBA\x6D\x20\x64\xC5\x91\x6C\xC5\x91\x72\x20\xC5\xA1\x69\x74\x20\xC4\x83\x6D\xC4\x95\x74\x2C\x20\xC4\x8D\xC3\xB4\x6E\xC5\xA1\x65\xC4\x8D\x74\x65\x74\xC3\xBA\xC5\x99\x20\xC3\xA4\x64\x69\x70\x69\x73\x63\x69\x6E\x67\x20\x65\xC4\xBE\x69\x74\x2E\n\nEtiam cursus odio ut dui malesuada imperdiet.\n\nNullam ac augue volutpat, aliquam ante sit amet, efficitur ipsum.");
            box->getInner()->addWidget(area);

            body->addWidget(box);
        }

        // Text Area
        {
            auto box = new ffw::GuiBox(&gui, "Text Area", ffw::GuiOrientation::VERTICAL);
            box->setSize(ffw::guiPercent(32.33f), ffw::guiWrap());
            box->setMargin(0, ffw::guiPercent(0.5f), ffw::guiPixels(5), ffw::guiPercent(0.5f));

            auto area = new ffw::GuiScrollableTextInput(&gui);
            area->setSize(ffw::guiPercent(100), ffw::guiPixels(80));
            area->setValue("Lorem ipsum dolor sit amet, consectetur adipiscing elit.\nEtiam cursus odio ut dui malesuada imperdiet.\nLorem ipsum dolor sit amet, consectetur adipiscing elit.\nEtiam cursus odio ut dui malesuada imperdiet.");
            box->getInner()->addWidget(area);

            area = new ffw::GuiScrollableTextInput(&gui);
            area->setSize(ffw::guiPercent(100), ffw::guiPixels(80));
            area->setDisabled(true);
            area->setValue("Lorem ipsum dolor sit amet, consectetur adipiscing elit.\nEtiam cursus odio ut dui malesuada imperdiet.\nLorem ipsum dolor sit amet, consectetur adipiscing elit.\nEtiam cursus odio ut dui malesuada imperdiet.");
            box->getInner()->addWidget(area);

            body->addWidget(box);
        }

        // List
        {
            auto box = new ffw::GuiBox(&gui, "Lists", ffw::GuiOrientation::VERTICAL);
            box->setSize(ffw::guiPercent(32.33f), ffw::guiWrap());
            box->setMargin(0, ffw::guiPercent(0.5f), ffw::guiPixels(5), ffw::guiPercent(0.5f));

            auto list = new ffw::GuiList(&gui);
            list->setSize(ffw::guiPercent(100), ffw::guiPixels(75));
            list->addItem("First");
            auto item = list->addItem("Second");
            item->setDisabled(true);
            auto selected = list->addItem("Third");
            list->addItem("Fourth");
            list->addItem("Fifth");
            list->setSelected(selected);
            box->getInner()->addWidget(list);

            list = new ffw::GuiList(&gui);
            list->setSize(ffw::guiPercent(100), ffw::guiPixels(75));
            list->addItem("First");
            list->addItem("Second");
            list->addItem("Third");
            list->addItem("Fourth");
            list->addItem("Fifth");
            list->setDisabled(true);
            box->getInner()->addWidget(list);

            body->addWidget(box);
        }

        // Switch
        {
            auto box = new ffw::GuiBox(&gui, "Switch", ffw::GuiOrientation::VERTICAL);
            box->setSize(ffw::guiPercent(32.33f), ffw::guiWrap());
            box->setMargin(0, ffw::guiPercent(0.5f), ffw::guiPixels(5), ffw::guiPercent(0.5f));

            auto label = new ffw::GuiLabel(&gui, "Normal:");
            box->getInner()->addWidget(label);

            auto button = new ffw::GuiSwitch(&gui);
            box->getInner()->addWidget(button);

            label = new ffw::GuiLabel(&gui, "Hover:");
            box->getInner()->addWidget(label);

            button = new ffw::GuiSwitch(&gui);
            button->setHover(true);
            button->setIgnoreUserInput(true);
            box->getInner()->addWidget(button);

            label = new ffw::GuiLabel(&gui, "Focus:");
            box->getInner()->addWidget(label);

            button = new ffw::GuiSwitch(&gui);
            button->setFocus(true);
            button->setIgnoreUserInput(true);
            box->getInner()->addWidget(button);

            label = new ffw::GuiLabel(&gui, "Disabled:");
            box->getInner()->addWidget(label);

            button = new ffw::GuiSwitch(&gui);
            button->setDisabled(true);
            box->getInner()->addWidget(button);

            body->addWidget(box);
        }

        // Progress bar
        {
            auto box = new ffw::GuiBox(&gui, "Progress Bar", ffw::GuiOrientation::VERTICAL);
            box->setSize(ffw::guiPercent(32.33f), ffw::guiWrap());
            box->setMargin(0, ffw::guiPercent(0.5f), ffw::guiPixels(5), ffw::guiPercent(0.5f));

            auto label = new ffw::GuiLabel(&gui, "Normal 0%:");
            box->getInner()->addWidget(label);

            auto progress = new ffw::GuiProgressBar(&gui);
            progress->setValue(0);
            box->getInner()->addWidget(progress);

            label = new ffw::GuiLabel(&gui, "Normal 50%:");
            box->getInner()->addWidget(label);

            progress = new ffw::GuiProgressBar(&gui);
            progress->setValue(50);
            box->getInner()->addWidget(progress);

            label = new ffw::GuiLabel(&gui, "Normal 100%:");
            box->getInner()->addWidget(label);

            progress = new ffw::GuiProgressBar(&gui);
            progress->setValue(75);
            box->getInner()->addWidget(progress);

            label = new ffw::GuiLabel(&gui, "Disabled 50%:");
            box->getInner()->addWidget(label);

            progress = new ffw::GuiProgressBar(&gui);
            progress->setValue(50);
            progress->setDisabled(true);
            box->getInner()->addWidget(progress);

            body->addWidget(box);
        }

        // Progress circle
        {
            auto box = new ffw::GuiBox(&gui, "Progress Circle", ffw::GuiOrientation::VERTICAL);
            box->setSize(ffw::guiPercent(32.33f), ffw::guiWrap());
            box->setMargin(0, ffw::guiPercent(0.5f), ffw::guiPixels(5), ffw::guiPercent(0.5f));

            auto label = new ffw::GuiLabel(&gui, "Normal 75%:");
            box->getInner()->addWidget(label);

            auto progress = new ffw::GuiProgressCircle(&gui);
            progress->setValue(75);
            box->getInner()->addWidget(progress);

            label = new ffw::GuiLabel(&gui, "Disabled 33%:");
            box->getInner()->addWidget(label);

            progress = new ffw::GuiProgressCircle(&gui);
            progress->setValue(33);
            progress->setDisabled(true);
            box->getInner()->addWidget(progress);

            body->addWidget(box);
        }

        // Scrollable
        {
            auto box = new ffw::GuiBox(&gui, "Scrollable", ffw::GuiOrientation::VERTICAL);
            box->setSize(ffw::guiPercent(32.33f), ffw::guiWrap());
            box->setMargin(0, ffw::guiPercent(0.5f), ffw::guiPixels(5), ffw::guiPercent(0.5f));

            auto scrollable = new ffw::GuiScrollableLayout(&gui, ffw::GuiOrientation::VERTICAL, true, true);
            scrollable->setSize(ffw::guiPercent(100), ffw::guiPixels(200));
            box->getInner()->addWidget(scrollable);

            for (int i = 0; i < 8; i++) {
                auto button = new ffw::GuiButton(&gui, "Button");
                scrollable->getInner()->addWidget(button);
            }

            body->addWidget(box);
        }

        // Tabs
        {
            auto box = new ffw::GuiBox(&gui, "Tabs", ffw::GuiOrientation::VERTICAL);
            box->setSize(ffw::guiPercent(32.33f), ffw::guiWrap());
            box->setMargin(0, ffw::guiPercent(0.5f), ffw::guiPixels(5), ffw::guiPercent(0.5f));

            auto tabs = new ffw::GuiTabs(&gui);
            box->getInner()->addWidget(tabs);

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

            body->addWidget(box);
        }

        // Text
        {
            auto box = new ffw::GuiBox(&gui, "Text", ffw::GuiOrientation::VERTICAL);
            box->setSize(ffw::guiPercent(32.33f), ffw::guiWrap());
            box->setMargin(0, ffw::guiPercent(0.5f), ffw::guiPixels(5), ffw::guiPercent(0.5f));

            auto text = new ffw::GuiText(&gui);
            box->getInner()->addWidget(text);

            text->addParagraph("This is a text widget which can have");
            text->addParagraph("Multiple paragraphs with different colors", ffw::rgb(0xFF0000), &fontRegular);
            text->addParagraph("Or different colors and fonts too!", ffw::rgb(0x0000FF), &fontBold);
            text->addParagraph("Italics too!", ffw::rgb(0x33FF33), &fontItalic);

            body->addWidget(box);
        }

        return true;
    }

    void render() override {
        this->beginFrame();

        gui.update();
        gui.poolEvents();
        gui.render();

        // Uncomment this to see what's being updated
        // and what isn't
        // this->setDrawColor(ffw::rgba(0x00000001));
        // this->drawRectangle(0, 0, getSize().x, getSize().y);

        this->endFrame();
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
        gui.injectMousePos(float(mousex), float(mousey));
    }

    void mouseScrollEvent(int scroll) override {
        gui.injectScroll(0, float(scroll));
    }

    void mouseButtonEvent(ffw::MouseButton button, ffw::Mode mode) override {
        gui.injectMouseButton(button, mode);
    }

    void windowResizedEvent(int width, int height) override {
        gui.setSize(float(width), float(height));
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
    return 0;
}
