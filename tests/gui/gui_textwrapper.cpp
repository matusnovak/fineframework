#include <ffw/gui.h>
#define CATCH_CONFIG_MAIN
#include "../catch.hpp"
#include "nullrenderer.h"

///=============================================================================
TEST_CASE("Text wrapping") {
    ffw::GuiTextWrapper text;

    GuiFontNull font1;
    font1.create(8);

    REQUIRE(font1.getStringSize("0123456789").x == 80.0f);

    SECTION("80px width, no wrapping should happen"){
        REQUIRE(text.getParagraphs().size() == 0.0f);

        text.addParagraph();
        text.section(ffw::Color(), &font1);
        text.append(L"0123456789");
        text.recalculate(80.0f);

        REQUIRE(text.getParagraphs().size() == 1);
        REQUIRE(text.getParagraphs()[0].getSections().size() == 1);
        REQUIRE(text.getParagraphs()[0].getTokens().size() == 1);
    }

    SECTION("40px width, wrap in two equal length lines") {
        text.addParagraph();
        text.section(ffw::Color(), &font1);
        text.append(L"0123456789");
        text.recalculate(40.0f);

        REQUIRE(text.getParagraphs()[0].getTokens().size() == 2);
        REQUIRE(text.getParagraphs()[0].getTokens()[0].first == 5);
        REQUIRE(text.getParagraphs()[0].getTokens()[1].first == 10.0f);
    }

    SECTION("20px width, wrap in five equal length lines") {
        text.addParagraph();
        text.section(ffw::Color(), &font1);
        text.append(L"0123456789");
        text.recalculate(20.0f);

        REQUIRE(text.getParagraphs()[0].getTokens().size() == 5);
        REQUIRE(text.getParagraphs()[0].getTokens()[0].first == 2);
        REQUIRE(text.getParagraphs()[0].getTokens()[1].first == 4);
        REQUIRE(text.getParagraphs()[0].getTokens()[2].first == 6);
        REQUIRE(text.getParagraphs()[0].getTokens()[3].first == 8);
        REQUIRE(text.getParagraphs()[0].getTokens()[4].first == 10.0f);
    }

    SECTION("33px width, wrap in four equal length lines") {
        text.addParagraph();
        text.section(ffw::Color(), &font1);
        text.append(L"0123456789");
        text.recalculate(33);

        REQUIRE(text.getParagraphs()[0].getTokens().size() == 3);
        REQUIRE(text.getParagraphs()[0].getTokens()[0].first == 4);
        REQUIRE(text.getParagraphs()[0].getTokens()[1].first == 8);
        REQUIRE(text.getParagraphs()[0].getTokens()[2].first == 10.0f);
    }
}

///=============================================================================
TEST_CASE("Text wrapping with whitespace") {
    ffw::GuiTextWrapper text;

    GuiFontNull font1;
    font1.create(8);

    REQUIRE(font1.getStringSize("0123456789").x == 80.0f);

    SECTION("80px width, no wrapping should happen") {
        REQUIRE(text.getParagraphs().size() == 0.0f);

        text.addParagraph();
        text.section(ffw::Color(), &font1);
        text.append(L"012 456 89");
        text.recalculate(80.0f);

        REQUIRE(text.getParagraphs().size() == 1);
        REQUIRE(text.getParagraphs()[0].getSections().size() == 1);
        REQUIRE(text.getParagraphs()[0].getTokens().size() == 1);
    }

    SECTION("50px width, wrap in two lines") {
        text.addParagraph();
        text.section(ffw::Color(), &font1);
        text.append(L"012 456 89");
        text.recalculate(50.0f);

        REQUIRE(text.getParagraphs()[0].getTokens().size() == 2);
        REQUIRE(text.getParagraphs()[0].getTokens()[0].first == 4);
        REQUIRE(text.getParagraphs()[0].getTokens()[1].first == 10.0f);
    }

    SECTION("24px width, wrap in three lines") {
        text.addParagraph();
        text.section(ffw::Color(), &font1);
        text.append(L"012 456 89");
        text.recalculate(24);

        REQUIRE(text.getParagraphs()[0].getTokens().size() == 3);
        REQUIRE(text.getParagraphs()[0].getTokens()[0].first == 4);
        REQUIRE(text.getParagraphs()[0].getTokens()[1].first == 8);
        REQUIRE(text.getParagraphs()[0].getTokens()[2].first == 10.0f);
    }

    SECTION("24px width, wrap in two lines") {
        text.addParagraph();
        text.section(ffw::Color(), &font1);
        text.append(L"012    789");
        text.recalculate(24);

        REQUIRE(text.getParagraphs()[0].getTokens().size() == 2);
        REQUIRE(text.getParagraphs()[0].getTokens()[0].first == 7);
        REQUIRE(text.getParagraphs()[0].getTokens()[1].first == 10.0f);
    }

    SECTION("24px width, wrap in two lines") {
        text.addParagraph();
        text.section(ffw::Color(), &font1);
        text.append(L"012    789          ");
        text.recalculate(24);

        REQUIRE(text.getParagraphs()[0].getTokens().size() == 2);
        REQUIRE(text.getParagraphs()[0].getTokens()[0].first == 7);
        REQUIRE(text.getParagraphs()[0].getTokens()[1].first == 20.0f);
    }
}

///=============================================================================
TEST_CASE("Text wrapping with multiple fonts") {
    ffw::GuiTextWrapper text;

    GuiFontNull font1;
    font1.create(8);

    GuiFontNull font2;
    font2.create(12);

    GuiFontNull font3;
    font3.create(16);

    REQUIRE(font1.getStringSize("0123456789", 1.0f).x == 80.0f);
    REQUIRE(font2.getStringSize("0123456789", 1.0f).x == 120.0f);
    REQUIRE(font3.getStringSize("0123456789", 1.0f).x == 160.0f);

    REQUIRE(font1.getStringSize("0123456789", 1.0f).y == 8);
    REQUIRE(font2.getStringSize("0123456789", 1.0f).y == 12);
    REQUIRE(font3.getStringSize("0123456789", 1.0f).y == 16);

    SECTION("80px width, two sections, wrap in two lines") {
        text.addParagraph();

        text.section(ffw::Color(), &font1);
        text.append(L"01234"); // 40px width

        text.section(ffw::Color(), &font2);
        text.append(L"56789"); // 60px width, should split in 3*12 + 2*12 between 7-8

        text.recalculate(80.0f);

        REQUIRE(text.getParagraphs()[0].getTokens().size() == 2);
        REQUIRE(text.getParagraphs()[0].getTokens()[0].first == 8);
        REQUIRE(text.getParagraphs()[0].getTokens()[1].first == 10.0f);
    }

    SECTION("80px width, two sections, wrap in three lines") {
        text.addParagraph();

        text.section(ffw::Color(), &font1);
        text.append(L"0123456789"); // 80px width

        text.section(ffw::Color(), &font3);
        text.append(L"0123456789"); // 160px width, should split exactly at middle

        text.recalculate(80.0f);

        REQUIRE(text.getParagraphs()[0].getTokens().size() == 3);
        REQUIRE(text.getParagraphs()[0].getTokens()[0].first == 10.0f);
        REQUIRE(text.getParagraphs()[0].getTokens()[1].first == 15);
        REQUIRE(text.getParagraphs()[0].getTokens()[2].first == 20.0f);
    }

    SECTION("40px width, three sections, wrap in three lines") {
        text.addParagraph();

        text.section(ffw::Color(), &font1);
        text.append(L"012"); // 24px width

        text.section(ffw::Color(), &font2);
        text.append(L"345"); // 36px width

        text.section(ffw::Color(), &font3);
        text.append(L"678"); // 48px width

        text.recalculate(40.0f);

        REQUIRE(text.getParagraphs()[0].getTokens().size() == 3);
        REQUIRE(text.getParagraphs()[0].getTokens()[0].first == 4);
        REQUIRE(text.getParagraphs()[0].getTokens()[1].first == 7);
        REQUIRE(text.getParagraphs()[0].getTokens()[2].first == 9);
    }
}

///=============================================================================
TEST_CASE("Text wrapping with multiple fonts and heights") {
    ffw::GuiTextWrapper text;

    GuiFontNull font1;
    font1.create(8);

    GuiFontNull font2;
    font2.create(12);

    GuiFontNull font3;
    font3.create(16);

    REQUIRE(font1.getStringSize("0123456789", 1.0f).x == 80.0f);
    REQUIRE(font2.getStringSize("0123456789", 1.0f).x == 120.0f);
    REQUIRE(font3.getStringSize("0123456789", 1.0f).x == 160.0f);

    REQUIRE(font1.getStringSize("0123456789", 1.0f).y == 8);
    REQUIRE(font2.getStringSize("0123456789", 1.0f).y == 12);
    REQUIRE(font3.getStringSize("0123456789", 1.0f).y == 16);

    SECTION("80px width, one font, one line, no wrapping") {
        text.addParagraph();

        text.section(ffw::Color(), &font1);
        text.append(L"0123456789"); // 80px width

        text.recalculate(80.0f);

        REQUIRE(text.getParagraphs()[0].getTokens().size() == 1);
        REQUIRE(text.getParagraphs()[0].getTokens()[0].second == 8);
    }

    SECTION("40px width, one font, two lines") {
        text.addParagraph();

        text.section(ffw::Color(), &font1);
        text.append(L"0123456789"); // 80px width

        text.recalculate(40.0f);

        REQUIRE(text.getParagraphs()[0].getTokens().size() == 2);
        REQUIRE(text.getParagraphs()[0].getTokens()[0].second == 8);
        REQUIRE(text.getParagraphs()[0].getTokens()[1].second == 8);
    }

    SECTION("80px width, two fonts, two lines") {
        text.addParagraph();

        text.section(ffw::Color(), &font1);
        text.append(L"01234"); // 40px width

        text.section(ffw::Color(), &font3);
        text.append(L"56789"); // 80px width

        text.recalculate(80.0f);

        REQUIRE(text.getParagraphs()[0].getTokens().size() == 2);

        REQUIRE(text.getParagraphs()[0].getTokens()[0].first == 7);
        REQUIRE(text.getParagraphs()[0].getTokens()[1].first == 10.0f);

        REQUIRE(text.getParagraphs()[0].getTokens()[0].second == 16);
        REQUIRE(text.getParagraphs()[0].getTokens()[1].second == 16);
    }

    SECTION("40px width, two fonts, two lines") {
        text.addParagraph();

        text.section(ffw::Color(), &font1);
        text.append(L"01234"); // 40px width

        text.section(ffw::Color(), &font3);
        text.append(L"56"); // 24px width

        text.recalculate(40.0f);

        REQUIRE(text.getParagraphs()[0].getTokens().size() == 2);

        REQUIRE(text.getParagraphs()[0].getTokens()[0].first == 5);
        REQUIRE(text.getParagraphs()[0].getTokens()[1].first == 7);

        REQUIRE(text.getParagraphs()[0].getTokens()[0].second == 8);
        REQUIRE(text.getParagraphs()[0].getTokens()[1].second == 16);
    }
}

///=============================================================================
TEST_CASE("Text wrapping with multiple fonts and whitespaces") {
    ffw::GuiTextWrapper text;

    GuiFontNull font1;
    font1.create(8);

    GuiFontNull font2;
    font2.create(12);

    GuiFontNull font3;
    font3.create(16);

    REQUIRE(font1.getStringSize("0123456789", 1.0f).x == 80.0f);
    REQUIRE(font2.getStringSize("0123456789", 1.0f).x == 120.0f);
    REQUIRE(font3.getStringSize("0123456789", 1.0f).x == 160.0f);

    REQUIRE(font1.getStringSize("0123456789", 1.0f).y == 8);
    REQUIRE(font2.getStringSize("0123456789", 1.0f).y == 12);
    REQUIRE(font3.getStringSize("0123456789", 1.0f).y == 16);

    SECTION("80px width, two fonts, two lines") {
        text.addParagraph();

        text.section(ffw::Color(), &font1);
        text.append(L"01234    "); // 80px width

        text.section(ffw::Color(), &font3);
        text.append(L"90123"); // 80px width

        text.recalculate(80.0f);

        REQUIRE(text.getParagraphs()[0].getTokens().size() == 2);

        REQUIRE(text.getParagraphs()[0].getTokens()[0].first == 9);
        REQUIRE(text.getParagraphs()[0].getTokens()[1].first == 14);

        REQUIRE(text.getParagraphs()[0].getTokens()[0].second == 8);
        REQUIRE(text.getParagraphs()[0].getTokens()[1].second == 16);
    }

    SECTION("80px width, two fonts, two lines") {
        text.addParagraph();

        text.section(ffw::Color(), &font1);
        text.append(L"01234"); // 40px width

        text.section(ffw::Color(), &font3);
        text.append(L"   89012"); // 80px width

        text.recalculate(80.0f);

        REQUIRE(text.getParagraphs()[0].getTokens().size() == 2);

        REQUIRE(text.getParagraphs()[0].getTokens()[0].first == 8);
        REQUIRE(text.getParagraphs()[0].getTokens()[1].first == 13);

        REQUIRE(text.getParagraphs()[0].getTokens()[0].second == 16);
        REQUIRE(text.getParagraphs()[0].getTokens()[1].second == 16);
    }
}

///=============================================================================
TEST_CASE("Text wrapping stepper") {
    ffw::GuiTextWrapper text;

    GuiFontNull font1;
    font1.create(8);

    REQUIRE(font1.getStringSize("0123456789", 1.0f).x == 80.0f);
    REQUIRE(font1.getStringSize("0123456789", 1.0f).y == 8);

    SECTION("80px width, one font, two lines") {
        text.addParagraph();

        text.section(ffw::rgb(0xFF0000), &font1);
        text.append(L"01234567890123456789");

        text.recalculate(80.0f);

        REQUIRE(text.getParagraphs()[0].getTokens().size() == 2);
        REQUIRE(text.getParagraphs()[0].getTokens()[0].first == 10.0f);
        REQUIRE(text.getParagraphs()[0].getTokens()[1].first == 20.0f);

        ffw::GuiTextWrapper::Stepper stepper(text.getParagraphs()[0]);

        REQUIRE(stepper.hasNext() == true);
        REQUIRE(stepper.getNext() == true);

        REQUIRE(stepper.getColor() == ffw::rgb(0xFF0000));
        REQUIRE(stepper.getFont() == &font1);
        REQUIRE(stepper.getHeight() == 8);
        REQUIRE(stepper.getLength() == 10.0f);
        REQUIRE(stepper.getPtr() == &text.getParagraphs()[0].getText()[0]);

        REQUIRE(stepper.hasNext() == true);
        REQUIRE(stepper.getNext() == true);

        REQUIRE(stepper.getColor() == ffw::rgb(0xFF0000));
        REQUIRE(stepper.getFont() == &font1);
        REQUIRE(stepper.getHeight() == 8);
        REQUIRE(stepper.getLength() == 10.0f);
        REQUIRE(stepper.getPtr() == &text.getParagraphs()[0].getText()[10]);

        REQUIRE(stepper.hasNext() == false);
        REQUIRE(stepper.getNext() == false);
    }

    SECTION("80px width, one font, two lines and whitespace") {
        text.addParagraph();

        text.section(ffw::rgb(0xFF0000), &font1);
        text.append(L"0123456789   0123456789");

        text.recalculate(80.0f);

        REQUIRE(text.getParagraphs()[0].getTokens().size() == 2);
        REQUIRE(text.getParagraphs()[0].getTokens()[0].first == 13);
        REQUIRE(text.getParagraphs()[0].getTokens()[1].first == 23);

        ffw::GuiTextWrapper::Stepper stepper(text.getParagraphs()[0]);

        REQUIRE(stepper.hasNext() == true);
        REQUIRE(stepper.getNext() == true);

        REQUIRE(stepper.getColor() == ffw::rgb(0xFF0000));
        REQUIRE(stepper.getFont() == &font1);
        REQUIRE(stepper.getHeight() == 8);
        REQUIRE(stepper.getLength() == 13);
        REQUIRE(stepper.getPtr() == &text.getParagraphs()[0].getText()[0]);

        REQUIRE(stepper.hasNext() == true);
        REQUIRE(stepper.getNext() == true);

        REQUIRE(stepper.getColor() == ffw::rgb(0xFF0000));
        REQUIRE(stepper.getFont() == &font1);
        REQUIRE(stepper.getHeight() == 8);
        REQUIRE(stepper.getLength() == 10.0f);
        REQUIRE(stepper.getPtr() == &text.getParagraphs()[0].getText()[13]);

        REQUIRE(stepper.hasNext() == false);
        REQUIRE(stepper.getNext() == false);
    }

    SECTION("40px width, one font, two lines and whitespace") {
        text.addParagraph();

        text.section(ffw::rgb(0xFF0000), &font1);
        text.append(L"0123456789   01234567");

        text.section(ffw::rgb(0x0000FF), &font1);
        text.append(L"89");

        text.recalculate(40.0f);

        REQUIRE(text.getParagraphs()[0].getTokens().size() == 4);
        REQUIRE(text.getParagraphs()[0].getTokens()[0].first == 5);
        REQUIRE(text.getParagraphs()[0].getTokens()[1].first == 13);
        REQUIRE(text.getParagraphs()[0].getTokens()[2].first == 18);
        REQUIRE(text.getParagraphs()[0].getTokens()[3].first == 23);

        ffw::GuiTextWrapper::Stepper stepper(text.getParagraphs()[0]);

        REQUIRE(stepper.hasNext() == true);
        REQUIRE(stepper.getNext() == true);

        REQUIRE(stepper.getLength() == 5);
        REQUIRE(stepper.getPtr() == &text.getParagraphs()[0].getText()[0]);
        REQUIRE(stepper.getColor() == ffw::rgb(0xFF0000));
        REQUIRE(stepper.getFont() == &font1);
        REQUIRE(stepper.getHeight() == 8);

        REQUIRE(stepper.hasNext() == true);
        REQUIRE(stepper.getNext() == true);

        REQUIRE(stepper.getLength() == 8);
        REQUIRE(stepper.getPtr() == &text.getParagraphs()[0].getText()[5]);
        REQUIRE(stepper.getColor() == ffw::rgb(0xFF0000));
        REQUIRE(stepper.getFont() == &font1);
        REQUIRE(stepper.getHeight() == 8);

        REQUIRE(stepper.hasNext() == true);
        REQUIRE(stepper.getNext() == true);

        REQUIRE(stepper.getLength() == 5);
        REQUIRE(stepper.getPtr() == &text.getParagraphs()[0].getText()[13]);
        REQUIRE(stepper.getColor() == ffw::rgb(0xFF0000));
        REQUIRE(stepper.getFont() == &font1);
        REQUIRE(stepper.getHeight() == 8);

        REQUIRE(stepper.hasNext() == true);
        REQUIRE(stepper.getNext() == true);

        REQUIRE(stepper.getLength() == 3);
        REQUIRE(stepper.getPtr() == &text.getParagraphs()[0].getText()[18]);
        REQUIRE(stepper.getColor() == ffw::rgb(0xFF0000));
        REQUIRE(stepper.getFont() == &font1);
        REQUIRE(stepper.getHeight() == 8);

        REQUIRE(stepper.hasNext() == true);
        REQUIRE(stepper.getNext() == true);

        REQUIRE(stepper.getLength() == 2);
        REQUIRE(stepper.getPtr() == &text.getParagraphs()[0].getText()[21]);
        REQUIRE(stepper.getColor() == ffw::rgb(0x0000FF));
        REQUIRE(stepper.getFont() == &font1);
        REQUIRE(stepper.getHeight() == 8);

        REQUIRE(stepper.hasNext() == false);
        REQUIRE(stepper.getNext() == false);
    }

    SECTION("480px width with empty section at the end") {
        text.addParagraph();

        text.section(ffw::rgb(0xFF0000), &font1);
        text.append(L"0123456789");

        text.section(ffw::rgb(0x0000FF), &font1);
        text.append(L"");

        text.recalculate(80.0f);

        REQUIRE(text.getParagraphs()[0].getTokens().size() == 1);
        REQUIRE(text.getParagraphs()[0].getTokens()[0].first == 10.0f);

        ffw::GuiTextWrapper::Stepper stepper(text.getParagraphs()[0]);

        REQUIRE(stepper.hasNext() == true);
        REQUIRE(stepper.getNext() == true);

        REQUIRE(stepper.getLength() == 10.0f);
        REQUIRE(stepper.getPtr() == &text.getParagraphs()[0].getText()[0]);
        REQUIRE(stepper.getColor() == ffw::rgb(0xFF0000));
        REQUIRE(stepper.getFont() == &font1);
        REQUIRE(stepper.getHeight() == 8);

        REQUIRE(stepper.hasNext() == true);
        REQUIRE(stepper.getNext() == true);

        REQUIRE(stepper.getLength() == 0.0f);
        REQUIRE(stepper.getPtr() == &text.getParagraphs()[0].getText()[10]);
        REQUIRE(stepper.getColor() == ffw::rgb(0x0000FF));
        REQUIRE(stepper.getFont() == &font1);
        REQUIRE(stepper.getHeight() == 8);

        REQUIRE(stepper.hasNext() == false);
        REQUIRE(stepper.getNext() == false);
    }

    SECTION("480px width with empty section at the beginning") {
        text.addParagraph();

        text.section(ffw::rgb(0x0000FF), &font1);
        text.append(L"");

        text.section(ffw::rgb(0xFF0000), &font1);
        text.append(L"0123456789");

        text.recalculate(80.0f);

        REQUIRE(text.getParagraphs()[0].getTokens().size() == 1);
        REQUIRE(text.getParagraphs()[0].getTokens()[0].first == 10.0f);

        ffw::GuiTextWrapper::Stepper stepper(text.getParagraphs()[0]);

        REQUIRE(stepper.hasNext() == true);
        REQUIRE(stepper.getNext() == true);

        REQUIRE(stepper.getLength() == 0.0f);
        REQUIRE(stepper.getPtr() == &text.getParagraphs()[0].getText()[0]);
        REQUIRE(stepper.getColor() == ffw::rgb(0x0000FF));
        REQUIRE(stepper.getFont() == &font1);
        REQUIRE(stepper.getHeight() == 8);

        REQUIRE(stepper.hasNext() == true);
        REQUIRE(stepper.getNext() == true);

        REQUIRE(stepper.getLength() == 10.0f);
        REQUIRE(stepper.getPtr() == &text.getParagraphs()[0].getText()[0]);
        REQUIRE(stepper.getColor() == ffw::rgb(0xFF0000));
        REQUIRE(stepper.getFont() == &font1);
        REQUIRE(stepper.getHeight() == 8);

        REQUIRE(stepper.hasNext() == false);
        REQUIRE(stepper.getNext() == false);
    }
}
