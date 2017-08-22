#include <ffw/gui.h>
#define CATCH_CONFIG_MAIN
#include "../catch.hpp"
#include "nullrenderer.h"

///=============================================================================
TEST_CASE("Gui Units", "[GuiWidget]") {
	ffw::GuiUnits u;

	u = 42.0f;
	REQUIRE(u == 42.0f);
	REQUIRE(u == ffw::guiPixels(42));
	REQUIRE(u != ffw::guiPercent(42));

	u = ffw::guiPercent(25);
	REQUIRE(u != 25.0f);
	REQUIRE(u != ffw::guiPixels(25));
	REQUIRE(u == ffw::guiPercent(25));

	REQUIRE(u.toReal(100.0f) == 25);
	REQUIRE(u.toReal(150.0f) == 37.5f);

	u.setPercent(50.0f);
	REQUIRE(u != 50.0f);
	REQUIRE(u != ffw::guiPixels(50.0f));
	REQUIRE(u == ffw::guiPercent(50.0f));

	u.setPixels(50.0f);
	REQUIRE(u == 50.0f);
	REQUIRE(u == ffw::guiPixels(50.0f));
	REQUIRE(u != ffw::guiPercent(50.0f));

	REQUIRE(u.toReal(100.0f) == 50.0f);
}

///=============================================================================
TEST_CASE("Gui Units 2D", "[GuiWidget]") {
	ffw::GuiUnits2D vec;
	vec.set(20.0f, 40.0f);

	REQUIRE(vec.x == 20.0f);
	REQUIRE(vec.y == 40.0f);

	REQUIRE(vec.x == ffw::guiPixels(20.0f));
	REQUIRE(vec.y == ffw::guiPixels(40.0f));

	vec.set(ffw::guiPercent(25), ffw::guiPercent(50.0f));
	REQUIRE(vec.x != ffw::guiPixels(25));
	REQUIRE(vec.y != ffw::guiPixels(50.0f));

	REQUIRE(vec.x == ffw::guiPercent(25));
	REQUIRE(vec.y == ffw::guiPercent(50.0f));

	REQUIRE(vec.toReal(ffw::Vec2f(200.0f, 200.0f)).x == Approx(50.0f));
	REQUIRE(vec.toReal(ffw::Vec2f(200.0f, 200.0f)).y == Approx(100.0f));

	vec.set(ffw::guiPixels(25), ffw::guiPixels(50.0f));
	REQUIRE(vec.toReal(ffw::Vec2f(200.0f, 200.0f)).x == Approx(25.0f));
	REQUIRE(vec.toReal(ffw::Vec2f(200.0f, 200.0f)).y == Approx(50.0f));
}

///=============================================================================
TEST_CASE("Testing window functionality", "[GuiWidget]") {
	TEST_SETUP_WINDOW(100.0f, 100.0f);

	const auto size = font.getStringSize("Hello", 1.5f);
	REQUIRE(size.x == Approx(5.0f * 8.0f));
	REQUIRE(size.y == Approx(12.0f));
}

///=============================================================================
TEST_CASE("Testing window size", "[GuiWidget]") {
	TEST_SETUP_WINDOW(100.0f, 100.0f);

	TEST_UPDATE_AND_RENDER;

	REQUIRE(gui.getLayout()->getRealSize().x == Approx(100.0f));
	REQUIRE(gui.getLayout()->getRealSize().y == Approx(100.0f));

	REQUIRE(gui.getLayout()->getVisibleContentSize().x == Approx(100.0f));
	REQUIRE(gui.getLayout()->getVisibleContentSize().y == Approx(100.0f));
}

///=============================================================================
TEST_CASE("Basic functionality", "[GuiWidget]") {
	TEST_SETUP_WINDOW(100.0f, 100.0f);
	auto widget = new GuiWidgetNull(&gui);

	REQUIRE(widget->getAlign() == ffw::GuiStyle::Align::TOP_LEFT);
	widget->setAlign(ffw::GuiStyle::Align::CENTER);
	REQUIRE(widget->getAlign() == ffw::GuiStyle::Align::CENTER);

	// set default font to whole window
	GuiFontNull font1;
	font1.create(8);
	gui.setDefaultFont(&font1);
	REQUIRE(widget->getCurrentFont() == &font1);

	// set default font to widget only
	GuiFontNull font2;
	font2.create(8);
	widget->setFont(&font2);
	REQUIRE(widget->getCurrentFont() == &font2);

	widget->setLineHeight(1.2f);
	REQUIRE(widget->getLineHeight() == Approx(1.2f));

	widget->setSize(ffw::guiPercent(100.0f), ffw::guiPercent(50.0f));
	REQUIRE(widget->getSize().x == ffw::guiPercent(100.0f));
	REQUIRE(widget->getSize().y == ffw::guiPercent(50.0f));

	widget->setPadding(0.0f);
	widget->setMargin(0.0f);
	gui.getLayout()->setPadding(5);
	gui.getLayout()->addWidget(widget);

	TEST_UPDATE_AND_RENDER;

	REQUIRE(gui.getLayout()->getRealSize().x == Approx(100.0f));
	REQUIRE(gui.getLayout()->getRealSize().y == Approx(100.0f));

	REQUIRE(gui.getLayout()->getVisibleContentSize().x == Approx(90.0f));
	REQUIRE(gui.getLayout()->getVisibleContentSize().y == Approx(90.0f));

	REQUIRE(widget->getRealSize().x == Approx(90.0f));
	REQUIRE(widget->getRealSize().y == Approx(45));

	REQUIRE(widget->getAbsolutePos().x == Approx(5));
	REQUIRE(widget->getAbsolutePos().y == Approx(5));
}

///=============================================================================
TEST_CASE("Margin in pixels", "[GuiWidget]") {
	TEST_SETUP_WINDOW(100.0f, 100.0f);
	auto widget = new GuiWidgetNull(&gui);
	widget->setSize(ffw::guiPercent(100.0f), ffw::guiPercent(50.0f));

	widget->setPadding(0.0f);
	widget->setMargin(0.0f);
	gui.getLayout()->setPadding(5);
	gui.getLayout()->addWidget(widget);

	TEST_UPDATE_AND_RENDER;

	REQUIRE(widget->getRealSize().x == Approx(90.0f));
	REQUIRE(widget->getRealSize().y == Approx(45));

	widget->setMargin(1, 2, 3, 4);
	REQUIRE(widget->getMargin(0) == 1.0f);
	REQUIRE(widget->getMargin(1) == 2.0f);
	REQUIRE(widget->getMargin(2) == 3.0f);
	REQUIRE(widget->getMargin(3) == 4.0f);

	widget->setMargin(5);
	REQUIRE(widget->getMargin(0) == 5.0f);
	REQUIRE(widget->getMargin(1) == 5.0f);
	REQUIRE(widget->getMargin(2) == 5.0f);
	REQUIRE(widget->getMargin(3) == 5.0f);

	widget->setMarginTop(2);
	widget->setMarginBottom(4);
	REQUIRE(widget->getMargin(0) == 2.0f);
	REQUIRE(widget->getMargin(1) == 5.0f);
	REQUIRE(widget->getMargin(2) == 4.0f);
	REQUIRE(widget->getMargin(3) == 5.0f);

	widget->setMarginRight(1);
	widget->setMarginLeft(3);
	REQUIRE(widget->getMargin(0) == 2.0f);
	REQUIRE(widget->getMargin(1) == 1.0f);
	REQUIRE(widget->getMargin(2) == 4.0f);
	REQUIRE(widget->getMargin(3) == 3.0f);

	REQUIRE(widget->getMarginInPixels(0) == Approx(2.0f));
	REQUIRE(widget->getMarginInPixels(1) == Approx(1.0f));
	REQUIRE(widget->getMarginInPixels(2) == Approx(4.0f));
	REQUIRE(widget->getMarginInPixels(3) == Approx(3.0f));
}

///=============================================================================
TEST_CASE("Margin in percent", "[GuiWidget]") {
	TEST_SETUP_WINDOW(100.0f, 100.0f);
	auto widget = new GuiWidgetNull(&gui);
	widget->setSize(ffw::guiPercent(100.0f), ffw::guiPercent(50.0f));

	widget->setPadding(0.0f);
	widget->setMargin(0.0f);
	gui.getLayout()->setPadding(0.0f);
	gui.getLayout()->addWidget(widget);

	TEST_UPDATE_AND_RENDER;

	REQUIRE(widget->getRealSize().x == Approx(100.0f));
	REQUIRE(widget->getRealSize().y == Approx(50.0f));

	widget->setMargin(ffw::guiPercent(1), ffw::guiPercent(2), ffw::guiPercent(3), ffw::guiPercent(4));
	REQUIRE(widget->getMargin(0) == ffw::guiPercent(1));
	REQUIRE(widget->getMargin(1) == ffw::guiPercent(2));
	REQUIRE(widget->getMargin(2) == ffw::guiPercent(3));
	REQUIRE(widget->getMargin(3) == ffw::guiPercent(4));

	widget->setMargin(ffw::guiPercent(5));
	REQUIRE(widget->getMargin(0) == ffw::guiPercent(5));
	REQUIRE(widget->getMargin(1) == ffw::guiPercent(5));
	REQUIRE(widget->getMargin(2) == ffw::guiPercent(5));
	REQUIRE(widget->getMargin(3) == ffw::guiPercent(5));

	widget->setMarginTop(ffw::guiPercent(2));
	widget->setMarginBottom(ffw::guiPercent(4));
	REQUIRE(widget->getMargin(0) == ffw::guiPercent(2));
	REQUIRE(widget->getMargin(1) == ffw::guiPercent(5));
	REQUIRE(widget->getMargin(2) == ffw::guiPercent(4));
	REQUIRE(widget->getMargin(3) == ffw::guiPercent(5));

	widget->setMarginRight(ffw::guiPercent(1));
	widget->setMarginLeft(ffw::guiPercent(3));
	REQUIRE(widget->getMargin(0) == ffw::guiPercent(2));
	REQUIRE(widget->getMargin(1) == ffw::guiPercent(1));
	REQUIRE(widget->getMargin(2) == ffw::guiPercent(4));
	REQUIRE(widget->getMargin(3) == ffw::guiPercent(3));

	// The widget's parent inner box size is 100x100 (no padding)
	REQUIRE(widget->getMarginInPixels(0) == Approx(100 * 0.02));
	REQUIRE(widget->getMarginInPixels(1) == Approx(100 * 0.01));
	REQUIRE(widget->getMarginInPixels(2) == Approx(100 * 0.04));
	REQUIRE(widget->getMarginInPixels(3) == Approx(100 * 0.03));
}

///=============================================================================
TEST_CASE("Padding in pixels", "[GuiWidget]") {
	TEST_SETUP_WINDOW(100.0f, 100.0f);
	auto widget = new GuiWidgetNull(&gui);
	widget->setSize(ffw::guiPercent(100.0f), ffw::guiPercent(50.0f));

	widget->setPadding(0.0f);
	widget->setMargin(0.0f);
	gui.getLayout()->setPadding(5);
	gui.getLayout()->addWidget(widget);

	TEST_UPDATE_AND_RENDER;

	REQUIRE(widget->getRealSize().x == Approx(90.0f));
	REQUIRE(widget->getRealSize().y == Approx(45));

	widget->setPadding(1, 2, 3, 4);
	REQUIRE(widget->getPadding(0) == 1.0f);
	REQUIRE(widget->getPadding(1) == 2.0f);
	REQUIRE(widget->getPadding(2) == 3.0f);
	REQUIRE(widget->getPadding(3) == 4.0f);

	widget->setPadding(5);
	REQUIRE(widget->getPadding(0) == 5.0f);
	REQUIRE(widget->getPadding(1) == 5.0f);
	REQUIRE(widget->getPadding(2) == 5.0f);
	REQUIRE(widget->getPadding(3) == 5.0f);

	widget->setPaddingTop(2);
	widget->setPaddingBottom(4);
	REQUIRE(widget->getPadding(0) == 2.0f);
	REQUIRE(widget->getPadding(1) == 5.0f);
	REQUIRE(widget->getPadding(2) == 4.0f);
	REQUIRE(widget->getPadding(3) == 5.0f);

	widget->setPaddingRight(1);
	widget->setPaddingLeft(3);
	REQUIRE(widget->getPadding(0) == 2.0f);
	REQUIRE(widget->getPadding(1) == 1.0f);
	REQUIRE(widget->getPadding(2) == 4.0f);
	REQUIRE(widget->getPadding(3) == 3.0f);

	REQUIRE(widget->getPaddingInPixels(0) == Approx(2.0f));
	REQUIRE(widget->getPaddingInPixels(1) == Approx(1.0f));
	REQUIRE(widget->getPaddingInPixels(2) == Approx(4.0f));
	REQUIRE(widget->getPaddingInPixels(3) == Approx(3.0f));
}

///=============================================================================
TEST_CASE("Padding in percent", "[GuiWidget]") {
	TEST_SETUP_WINDOW(100.0f, 100.0f);
	auto widget = new GuiWidgetNull(&gui);
	widget->setSize(ffw::guiPercent(100.0f), ffw::guiPercent(50.0f));

	widget->setPadding(0.0f);
	widget->setMargin(0.0f);
	gui.getLayout()->setPadding(0.0f);
	gui.getLayout()->addWidget(widget);

	TEST_UPDATE_AND_RENDER;

	REQUIRE(widget->getRealSize().x == Approx(100.0f));
	REQUIRE(widget->getRealSize().y == Approx(50.0f));

	widget->setPadding(ffw::guiPercent(1), ffw::guiPercent(2), ffw::guiPercent(3), ffw::guiPercent(4));
	REQUIRE(widget->getPadding(0) == ffw::guiPercent(1));
	REQUIRE(widget->getPadding(1) == ffw::guiPercent(2));
	REQUIRE(widget->getPadding(2) == ffw::guiPercent(3));
	REQUIRE(widget->getPadding(3) == ffw::guiPercent(4));

	widget->setPadding(ffw::guiPercent(5));
	REQUIRE(widget->getPadding(0) == ffw::guiPercent(5));
	REQUIRE(widget->getPadding(1) == ffw::guiPercent(5));
	REQUIRE(widget->getPadding(2) == ffw::guiPercent(5));
	REQUIRE(widget->getPadding(3) == ffw::guiPercent(5));

	widget->setPaddingTop(ffw::guiPercent(2));
	widget->setPaddingBottom(ffw::guiPercent(4));
	REQUIRE(widget->getPadding(0) == ffw::guiPercent(2));
	REQUIRE(widget->getPadding(1) == ffw::guiPercent(5));
	REQUIRE(widget->getPadding(2) == ffw::guiPercent(4));
	REQUIRE(widget->getPadding(3) == ffw::guiPercent(5));

	widget->setPaddingRight(ffw::guiPercent(1));
	widget->setPaddingLeft(ffw::guiPercent(3));
	REQUIRE(widget->getPadding(0) == ffw::guiPercent(2));
	REQUIRE(widget->getPadding(1) == ffw::guiPercent(1));
	REQUIRE(widget->getPadding(2) == ffw::guiPercent(4));
	REQUIRE(widget->getPadding(3) == ffw::guiPercent(3));

	// The widget's parent inner box size is 100x100 (no padding)
	REQUIRE(widget->getPaddingInPixels(0) == Approx(50 * 0.02));
	REQUIRE(widget->getPaddingInPixels(1) == Approx(100 * 0.01));
	REQUIRE(widget->getPaddingInPixels(2) == Approx(50 * 0.04));
	REQUIRE(widget->getPaddingInPixels(3) == Approx(100 * 0.03));
}

///=============================================================================
TEST_CASE("Changing the size", "[GuiWidget]") {
	TEST_SETUP_WINDOW(100.0f, 100.0f);
	auto widget = new GuiWidgetNull(&gui);
	widget->setSize(ffw::guiPercent(100.0f), ffw::guiPercent(50.0f));

	widget->setPadding(0.0f);
	widget->setMargin(0.0f);
	gui.getLayout()->setPadding(0.0f);
	gui.getLayout()->addWidget(widget);

	SECTION("set the size of the widget first") {
		// First run, always invalidate and update
		// the real size
		widget->setSize(ffw::guiPercent(100.0f), ffw::guiPercent(50.0f));

		TEST_UPDATE_AND_RENDER;

		REQUIRE(widget->getRealSize().x == Approx(100.0f));
		REQUIRE(widget->getRealSize().y == Approx(50.0f));

		// Second run, should update the real size
		widget->setSize(ffw::guiPercent(100.0f), ffw::guiPercent(100.0f));

		TEST_UPDATE_AND_RENDER;

		REQUIRE(widget->getRealSize().x == Approx(100.0f));
		REQUIRE(widget->getRealSize().y == Approx(100.0f));
	}

	SECTION("set the size of the window first") {
		// First run, always invalidate and update
		// the real size
		widget->setSize(ffw::guiPercent(100.0f), ffw::guiPercent(50.0f));

		TEST_UPDATE_AND_RENDER;

		REQUIRE(widget->getRealSize().x == Approx(100.0f));
		REQUIRE(widget->getRealSize().y == Approx(50.0f));

		// Second run, should update the real size
		// But this time update the window
		gui.getLayout()->setSize(ffw::guiPixels(200.0f), ffw::guiPixels(200.0f));

		TEST_UPDATE_AND_RENDER;

		REQUIRE(widget->getRealSize().x == Approx(200.0f));
		REQUIRE(widget->getRealSize().y == Approx(100.0f));
	}
}

///=============================================================================
TEST_CASE("Changing the size and position #1", "[GuiWidget]") {
	TEST_SETUP_WINDOW(100.0f, 100.0f);

	auto layout = new ffw::GuiHorizontalLayout(&gui);
	layout->setSize(ffw::guiPercent(100.0f), ffw::guiPercent(100.0f));
	layout->setMargin(0.0f);
	layout->setPadding(0.0f);

	gui.getLayout()->addWidget(layout);

	GuiWidgetNull* widget[2];
	widget[0] = new GuiWidgetNull(&gui);
	widget[1] = new GuiWidgetNull(&gui);
	widget[0]->setSize(ffw::guiPercent(50.0f), ffw::guiPercent(100.0f));
	widget[1]->setSize(ffw::guiPercent(50.0f), ffw::guiPercent(100.0f));
	widget[0]->setMargin(0.0f);
	widget[0]->setPadding(0.0f);
	widget[1]->setMargin(0.0f);
	widget[1]->setPadding(0.0f);

	layout->addWidget(widget[0]);
	layout->addWidget(widget[1]);

	TEST_UPDATE_AND_RENDER;

	// getLayout should be 100x100 pixels
	// and each widget should be 50x100 pixels

	REQUIRE(layout->getRealSize().x == Approx(100.0f));
	REQUIRE(layout->getRealSize().y == Approx(100.0f));

	REQUIRE(widget[0]->getRealSize().x == Approx(50.0f));
	REQUIRE(widget[0]->getRealSize().y == Approx(100.0f));

	REQUIRE(widget[1]->getRealSize().x == Approx(50.0f));
	REQUIRE(widget[1]->getRealSize().y == Approx(100.0f));

	SECTION("Changing the size of the layout should change childrens' sizes") {
		layout->setSize(ffw::guiPercent(100.0f), ffw::guiPercent(50.0f));

		TEST_UPDATE_AND_RENDER;

		REQUIRE(layout->getRealSize().x == Approx(100.0f));
		REQUIRE(layout->getRealSize().y == Approx(50.0f));

		REQUIRE(widget[0]->getRealSize().x == Approx(50.0f));
		REQUIRE(widget[0]->getRealSize().y == Approx(50.0f));

		REQUIRE(widget[1]->getRealSize().x == Approx(50.0f));
		REQUIRE(widget[1]->getRealSize().y == Approx(50.0f));
	}

	SECTION("Changing the size of the layout should change childrens' abs positions") {
		layout->setSize(ffw::guiPercent(100.0f), ffw::guiPercent(50.0f));

		TEST_UPDATE_AND_RENDER;

		REQUIRE(layout->getRealSize().x == Approx(100.0f));
		REQUIRE(layout->getRealSize().y == Approx(50.0f));

		REQUIRE(widget[0]->getAbsolutePos().x == Approx(0.0f));
		REQUIRE(widget[0]->getAbsolutePos().y == Approx(0.0f));

		REQUIRE(widget[1]->getAbsolutePos().x == Approx(50.0f));
		REQUIRE(widget[1]->getAbsolutePos().y == Approx(0.0f));
	}

	SECTION("Changing the size of one child should not affter size of the other one") {
		widget[0]->setSize(ffw::guiPercent(20.0f), ffw::guiPercent(100.0f));
		// the other child stays at X: 50% Y: 100%

		TEST_UPDATE_AND_RENDER;

		REQUIRE(layout->getRealSize().x == Approx(100.0f));
		REQUIRE(layout->getRealSize().y == Approx(100.0f));

		REQUIRE(widget[0]->getRealSize().x == Approx(20.0f));
		REQUIRE(widget[0]->getRealSize().y == Approx(100.0f));

		REQUIRE(widget[1]->getRealSize().x == Approx(50.0f));
		REQUIRE(widget[1]->getRealSize().y == Approx(100.0f));
	}

	SECTION("Changing the size of one child should affter position of the other one") {
		widget[0]->setSize(ffw::guiPercent(20.0f), ffw::guiPercent(100.0f));
		// the other child stays at X: 50% Y: 100%

		TEST_UPDATE_AND_RENDER;

		REQUIRE(layout->getRealSize().x == Approx(100.0f));
		REQUIRE(layout->getRealSize().y == Approx(100.0f));

		REQUIRE(widget[0]->getAbsolutePos().x == Approx(0.0f));
		REQUIRE(widget[0]->getAbsolutePos().y == Approx(0.0f));

		REQUIRE(widget[1]->getAbsolutePos().x == Approx(20.0f));
		REQUIRE(widget[1]->getAbsolutePos().y == Approx(0.0f));
	}
}

///=============================================================================
TEST_CASE("Changing the size and position #2", "[GuiWidget]") {
	TEST_SETUP_WINDOW(100.0f, 100.0f);

	ffw::GuiHorizontalLayout* layout[3];
	GuiWidgetNull* widget[4][2];

	layout[0] = new ffw::GuiHorizontalLayout(&gui);
	layout[0]->setSize(ffw::guiPercent(100.0f), ffw::guiPercent(100.0f));
	layout[0]->setMargin(0.0f);
	layout[0]->setPadding(0.0f);
	gui.getLayout()->addWidget(layout[0]);

	layout[1] = new ffw::GuiHorizontalLayout(&gui);
	layout[1]->setSize(ffw::guiPercent(50.0f), ffw::guiPercent(100.0f));
	layout[1]->setMargin(0.0f);
	layout[1]->setPadding(0.0f);
	layout[1]->setWrap(true);
	layout[0]->addWidget(layout[1]);

	layout[2] = new ffw::GuiHorizontalLayout(&gui);
	layout[2]->setSize(ffw::guiPercent(50.0f), ffw::guiPercent(100.0f));
	layout[2]->setMargin(0.0f);
	layout[2]->setPadding(0.0f);
	layout[2]->setWrap(true);
	layout[0]->addWidget(layout[2]);

	for(int l = 0; l < 2; l++) {
		for(int w = 0; w < 4; w++) {
			widget[w][l] = new GuiWidgetNull(&gui);
			widget[w][l]->setSize(ffw::guiPercent(50.0f), ffw::guiPercent(50.0f));
			widget[w][l]->setMargin(0.0f);
			layout[l+1]->addWidget(widget[w][l]);
		}
	}

	TEST_UPDATE_AND_RENDER;

	// First run must set both sizes
	REQUIRE(layout[1]->getRealSize().x == Approx(50.0f));
	REQUIRE(layout[1]->getRealSize().y == Approx(100.0f));

	REQUIRE(layout[2]->getRealSize().x == Approx(50.0f));
	REQUIRE(layout[2]->getRealSize().y == Approx(100.0f));
		
	for (int l = 0; l < 2; l++) {
		for (int w = 0; w < 4; w++) {
			REQUIRE(widget[w][l]->getRealSize().x == Approx(25));
			REQUIRE(widget[w][l]->getRealSize().y == Approx(50.0f));
		}
	}

	SECTION("changing the size of one child should affect position of the other one") {
		layout[1]->setSize(ffw::guiPercent(30.0f), ffw::guiPercent(100.0f));

		TEST_UPDATE_AND_RENDER;

		REQUIRE(layout[1]->getRealSize().x == Approx(30.0f));
		REQUIRE(layout[1]->getRealSize().y == Approx(100.0f));

		REQUIRE(layout[2]->getRealSize().x == Approx(50.0f));
		REQUIRE(layout[2]->getRealSize().y == Approx(100.0f));

		REQUIRE(layout[2]->getRealPos().x == Approx(30.0f));
		REQUIRE(layout[2]->getRealPos().y == Approx(0.0f));
	}

	SECTION("changing the size of one grand-child should affect its neighbours") {
		widget[0][1]->setSize(ffw::guiPercent(25), ffw::guiPercent(50.0f));

		TEST_UPDATE_AND_RENDER;

		// layout must stay same
		REQUIRE(layout[1]->getRealSize().x == Approx(50.0f));
		REQUIRE(layout[1]->getRealSize().y == Approx(100.0f));

		// relative position of the right neighbour must change
		// window's width is 100
		// left layout is 50
		// 25% from 50 is 12.5 -> to int -> 12
		REQUIRE(widget[1][1]->getRealPos().x == Approx(12.5f));
		REQUIRE(widget[1][1]->getRealPos().y == Approx(0.0f));

		// all other neighbours are unchanged
		REQUIRE(widget[2][1]->getRealPos().x == Approx(0.0f));
		REQUIRE(widget[2][1]->getRealPos().y == Approx(50.0f));

		REQUIRE(widget[3][1]->getRealPos().x == Approx(25));
		REQUIRE(widget[3][1]->getRealPos().y == Approx(50.0f));
	}
}

///=============================================================================
TEST_CASE("Changing the padding and margin", "[GuiWidget]") {
	TEST_SETUP_WINDOW(100.0f, 100.0f);

	auto layout = new ffw::GuiHorizontalLayout(&gui);
	layout->setSize(ffw::guiPercent(100.0f), ffw::guiPercent(100.0f));
	layout->setMargin(0.0f);
	layout->setPadding(0.0f);

	gui.getLayout()->addWidget(layout);

	GuiWidgetNull* widget[2];
	widget[0] = new GuiWidgetNull(&gui);
	widget[1] = new GuiWidgetNull(&gui);
	widget[0]->setSize(ffw::guiPercent(50.0f), ffw::guiPercent(100.0f));
	widget[1]->setSize(ffw::guiPercent(50.0f), ffw::guiPercent(100.0f));
	widget[0]->setMargin(0.0f);
	widget[0]->setPadding(0.0f);
	widget[1]->setMargin(0.0f);
	widget[1]->setPadding(0.0f);

	layout->addWidget(widget[0]);
	layout->addWidget(widget[1]);

	TEST_UPDATE_AND_RENDER;

	// getLayout should be 100x100 pixels
	// and each widget should be 50x100 pixels

	REQUIRE(layout->getRealSize().x == Approx(100.0f));
	REQUIRE(layout->getRealSize().y == Approx(100.0f));

	REQUIRE(widget[0]->getRealSize().x == Approx(50.0f));
	REQUIRE(widget[0]->getRealSize().y == Approx(100.0f));

	REQUIRE(widget[1]->getRealSize().x == Approx(50.0f));
	REQUIRE(widget[1]->getRealSize().y == Approx(100.0f));

	SECTION("changing the layout's padding") {
		layout->setPadding(5);
		// Now the inner size is 90x90 px

		TEST_UPDATE_AND_RENDER;

		REQUIRE(widget[0]->getRealSize().x == Approx(45));
		REQUIRE(widget[0]->getRealSize().y == Approx(90.0f));

		REQUIRE(widget[1]->getRealSize().x == Approx(45));
		REQUIRE(widget[1]->getRealSize().y == Approx(90.0f));

		REQUIRE(widget[0]->getRealPos().x == Approx(0.0f));
		REQUIRE(widget[0]->getRealPos().y == Approx(0.0f));

		REQUIRE(widget[1]->getRealPos().x == Approx(45));
		REQUIRE(widget[1]->getRealPos().y == Approx(0.0f));
	}

	SECTION("changing the widgets's margin") {
		widget[0]->setMargin(0.0f, 5, 0.0f, 0.0f);
		// Second widget must move to right by 5 pixels

		TEST_UPDATE_AND_RENDER;

		REQUIRE(widget[0]->getRealSize().x == Approx(50.0f));
		REQUIRE(widget[0]->getRealSize().y == Approx(100.0f));

		REQUIRE(widget[1]->getRealSize().x == Approx(50.0f));
		REQUIRE(widget[1]->getRealSize().y == Approx(100.0f));

		REQUIRE(widget[0]->getRealPos().x == Approx(0.0f));
		REQUIRE(widget[0]->getRealPos().y == Approx(0.0f));

		REQUIRE(widget[1]->getRealPos().x == Approx(55.0f));
		REQUIRE(widget[1]->getRealPos().y == Approx(0.0f));
	}
}


///=============================================================================
TEST_CASE("Changing the padding and margin #2", "[GuiWidget]") {
	TEST_SETUP_WINDOW(100.0f, 100.0f);

	ffw::GuiHorizontalLayout* layout[3];
	GuiWidgetNull* widget[4][2];

	layout[0] = new ffw::GuiHorizontalLayout(&gui);
	layout[0]->setSize(ffw::guiPercent(100.0f), ffw::guiPercent(100.0f));
	layout[0]->setMargin(0.0f);
	layout[0]->setPadding(0.0f);
	gui.getLayout()->addWidget(layout[0]);

	layout[1] = new ffw::GuiHorizontalLayout(&gui);
	layout[1]->setSize(ffw::guiPercent(50.0f), ffw::guiPercent(100.0f));
	layout[1]->setMargin(0.0f);
	layout[1]->setPadding(0.0f);
	layout[1]->setWrap(true);
	layout[0]->addWidget(layout[1]);

	layout[2] = new ffw::GuiHorizontalLayout(&gui);
	layout[2]->setSize(ffw::guiPercent(50.0f), ffw::guiPercent(100.0f));
	layout[2]->setMargin(0.0f);
	layout[2]->setPadding(0.0f);
	layout[2]->setWrap(true);
	layout[0]->addWidget(layout[2]);

	for (int l = 0; l < 2; l++) {
		for (int w = 0; w < 4; w++) {
			widget[w][l] = new GuiWidgetNull(&gui);
			widget[w][l]->setSize(ffw::guiPercent(50.0f), ffw::guiPercent(50.0f));
			widget[w][l]->setMargin(0.0f);
			layout[l + 1]->addWidget(widget[w][l]);
		}
	}

	TEST_UPDATE_AND_RENDER;

	// First run must set both sizes
	REQUIRE(layout[1]->getRealSize().x == Approx(50.0f));
	REQUIRE(layout[1]->getRealSize().y == Approx(100.0f));

	REQUIRE(layout[2]->getRealSize().x == Approx(50.0f));
	REQUIRE(layout[2]->getRealSize().y == Approx(100.0f));

	for (int l = 0; l < 2; l++) {
		for (int w = 0; w < 4; w++) {
			REQUIRE(widget[w][l]->getRealSize().x == Approx(25.0f));
			REQUIRE(widget[w][l]->getRealSize().y == Approx(50.0f));
		}
	}

	SECTION("changing the padding of the main layout") {
		layout[0]->setPadding(5);

		TEST_UPDATE_AND_RENDER;

		REQUIRE(layout[1]->getRealSize().x == Approx(45.0f));
		REQUIRE(layout[1]->getRealSize().y == Approx(90.0f));

		REQUIRE(layout[2]->getRealSize().x == Approx(45.0f));
		REQUIRE(layout[2]->getRealSize().y == Approx(90.0f));

		for (int l = 0; l < 2; l++) {
			for (int w = 0; w < 4; w++) {
				REQUIRE(widget[w][l]->getRealSize().x == Approx(22.5f));
				REQUIRE(widget[w][l]->getRealSize().y == Approx(45.0f));
			}
		}
	}
}

///=============================================================================
TEST_CASE("Wrapping size #1", "[GuiWidget]") {
	TEST_SETUP_WINDOW(100.0f, 100.0f);

	auto layout = new ffw::GuiVerticalLayout(&gui);
	layout->setSize(ffw::guiPercent(100.0f), ffw::guiWrap());
	layout->setMargin(0.0f);
	layout->setPadding(0.0f);
	gui.getLayout()->addWidget(layout);

	auto widget = new GuiWidgetNull(&gui);
	widget->setSize(ffw::guiPercent(100.0f), ffw::guiWrap());
	widget->setMargin(0.0f);
	widget->setPadding(0.0f);
	layout->addWidget(widget);

	TEST_UPDATE_AND_RENDER;

	REQUIRE(layout->getRealSize().x == Approx(100.0f));
	REQUIRE(layout->getRealSize().y == Approx(0.0f));

	widget->setSize(ffw::guiPercent(100.0f), ffw::guiPixels(20.0f));

	TEST_UPDATE_AND_RENDER;

	REQUIRE(layout->getRealSize().x == Approx(100.0f));
	REQUIRE(layout->getRealSize().y == Approx(20.0f));

	widget = new GuiWidgetNull(&gui);
	widget->setSize(ffw::guiPercent(100.0f), ffw::guiPixels(20.0f));
	widget->setMargin(0.0f);
	widget->setPadding(0.0f);
	layout->addWidget(widget);

	TEST_UPDATE_AND_RENDER;

	REQUIRE(layout->getRealSize().x == Approx(100.0f));
	REQUIRE(layout->getRealSize().y == Approx(40.0f));
}

///=============================================================================
TEST_CASE("Wrapping size #2", "[GuiWidget]") {
	TEST_SETUP_WINDOW(100.0f, 100.0f);

	auto layout = new ffw::GuiHorizontalLayout(&gui);
	layout->setSize(ffw::guiWrap(), ffw::guiPercent(100.0f));
	layout->setMargin(0.0f);
	layout->setPadding(0.0f);
	gui.getLayout()->addWidget(layout);

	auto widget = new GuiWidgetNull(&gui);
	widget->setSize(ffw::guiWrap(), ffw::guiPercent(100.0f));
	widget->setMargin(0.0f);
	widget->setPadding(0.0f);
	layout->addWidget(widget);

	TEST_UPDATE_AND_RENDER;

	REQUIRE(layout->getRealSize().x == Approx(0.0f));
	REQUIRE(layout->getRealSize().y == Approx(100.0f));

	widget->setSize(ffw::guiPixels(20.0f), ffw::guiPercent(100.0f));

	TEST_UPDATE_AND_RENDER;

	REQUIRE(layout->getRealSize().x == Approx(20.0f));
	REQUIRE(layout->getRealSize().y == Approx(100.0f));

	widget = new GuiWidgetNull(&gui);
	widget->setSize(ffw::guiPixels(20.0f), ffw::guiPercent(100.0f));
	widget->setMargin(0.0f);
	widget->setPadding(0.0f);
	layout->addWidget(widget);

	TEST_UPDATE_AND_RENDER;

	REQUIRE(layout->getRealSize().x == Approx(40.0f));
	REQUIRE(layout->getRealSize().y == Approx(100.0f));
}

///=============================================================================
TEST_CASE("Wrapping size #3", "[GuiWidget]") {
	TEST_SETUP_WINDOW(100.0f, 100.0f);

	auto outer = new ffw::GuiVerticalLayout(&gui);
	outer->setSize(ffw::guiPercent(100.0f), ffw::guiWrap());
	outer->setMargin(0.0f);
	outer->setPadding(0.0f);
	gui.getLayout()->addWidget(outer);

	auto inner = new ffw::GuiVerticalLayout(&gui);
	inner->setSize(ffw::guiPercent(100.0f), ffw::guiWrap());
	inner->setMargin(0.0f);
	inner->setPadding(0.0f);
	outer->addWidget(inner);

	auto widget = new GuiWidgetNull(&gui);
	widget->setSize(ffw::guiPercent(100.0f), ffw::guiWrap());
	widget->setMargin(0.0f);
	widget->setPadding(0.0f);
	inner->addWidget(widget);

	TEST_UPDATE_AND_RENDER;

	REQUIRE(outer->getRealSize().x == Approx(100.0f));
	REQUIRE(outer->getRealSize().y == Approx(0.0f));

	widget->setSize(ffw::guiPercent(100.0f), ffw::guiPixels(50.0f));

	TEST_UPDATE_AND_RENDER;

	REQUIRE(outer->getRealSize().x == Approx(100.0f));
	REQUIRE(outer->getRealSize().y == Approx(50.0f));
}

///=============================================================================
TEST_CASE("Offset", "[GuiWidget]") {
	TEST_SETUP_WINDOW(100.0f, 100.0f);

	auto layout = new ffw::GuiVerticalLayout(&gui);
	layout->setSize(ffw::guiPercent(100.0f), ffw::guiPercent(100.0f));
	layout->setMargin(0.0f);
	layout->setPadding(10.0f);
	gui.getLayout()->addWidget(layout);

	auto widget = new GuiWidgetNull(&gui);
	widget->setSize(ffw::guiPercent(100.0f), ffw::guiPercent(25));
	widget->setMargin(0.0f);
	widget->setPadding(0.0f);
	layout->addWidget(widget);

	TEST_UPDATE_AND_RENDER;

	REQUIRE(widget->getRealSize().x == Approx(80.0f));
	REQUIRE(widget->getRealSize().y == Approx(20.0f));

	REQUIRE(widget->getRealPos().x == Approx(0.0f));
	REQUIRE(widget->getRealPos().y == Approx(0.0f));

	REQUIRE(widget->getVisibleContentPos().x == Approx(0.0f));
	REQUIRE(widget->getVisibleContentPos().y == Approx(0.0f));

	REQUIRE(widget->getInnerContentPos().x == Approx(0.0f));
	REQUIRE(widget->getInnerContentPos().y == Approx(0.0f));

	REQUIRE(widget->getAbsolutePos().x == Approx(10.0f));
	REQUIRE(widget->getAbsolutePos().y == Approx(10.0f));

	layout->setOffset(ffw::Vec2f(10.0f, 20.0f));

	TEST_UPDATE_AND_RENDER;

	REQUIRE(widget->getRealSize().x == Approx(80.0f));
	REQUIRE(widget->getRealSize().y == Approx(20.0f));

	REQUIRE(widget->getRealPos().x == Approx(0.0f));
	REQUIRE(widget->getRealPos().y == Approx(0.0f));

	REQUIRE(layout->getVisibleContentPos().x == Approx(10.0f));
	REQUIRE(layout->getVisibleContentPos().y == Approx(10.0f));

	REQUIRE(layout->getInnerContentPos().x == Approx(20.0f));
	REQUIRE(layout->getInnerContentPos().y == Approx(30.0f));

	REQUIRE(widget->getAbsolutePos().x == Approx(20.0f));
	REQUIRE(widget->getAbsolutePos().y == Approx(30.0f));

	layout->setOffset(ffw::Vec2f(10.0f, -20.0f));

	TEST_UPDATE_AND_RENDER;

	REQUIRE(widget->getRealSize().x == Approx(80.0f));
	REQUIRE(widget->getRealSize().y == Approx(20.0f));

	REQUIRE(widget->getRealPos().x == Approx(0.0f));
	REQUIRE(widget->getRealPos().y == Approx(0.0f));

	REQUIRE(layout->getVisibleContentPos().x == Approx(10.0f));
	REQUIRE(layout->getVisibleContentPos().y == Approx(10.0f));

	REQUIRE(layout->getInnerContentPos().x == Approx(20.0f));
	REQUIRE(layout->getInnerContentPos().y == Approx(-10.0f));

	REQUIRE(widget->getAbsolutePos().x == Approx(20.0f));
	REQUIRE(widget->getAbsolutePos().y == Approx(-10.0f));

	gui.getLayout()->setPadding(10.0f);

	TEST_UPDATE_AND_RENDER;

	REQUIRE(widget->getRealSize().x == Approx(60.0f));
	REQUIRE(widget->getRealSize().y == Approx(15));

	REQUIRE(widget->getRealPos().x == Approx(0.0f));
	REQUIRE(widget->getRealPos().y == Approx(0.0f));

	REQUIRE(layout->getVisibleContentPos().x == Approx(10.0f));
	REQUIRE(layout->getVisibleContentPos().y == Approx(10.0f));

	REQUIRE(layout->getInnerContentPos().x == Approx(20.0f));
	REQUIRE(layout->getInnerContentPos().y == Approx(-10.0f));

	REQUIRE(widget->getAbsolutePos().x == Approx(30.0f));
	REQUIRE(widget->getAbsolutePos().y == Approx(0.0f));
}

///=============================================================================
TEST_CASE("Wrapping layout #1", "[GuiWidget]") {
	TEST_SETUP_WINDOW(100.0f, 100.0f);

	gui.getLayout()->setWrap(false);
	gui.getLayout()->setOrientation(ffw::GuiLayout::Orientation::HORIZONTAL);

	GuiWidgetNull* widgets[4];
	for(int i = 0; i < 4; i++) {
		widgets[i] = new GuiWidgetNull(&gui);
		widgets[i]->setSize(ffw::guiPercent(100.0f), ffw::guiPercent(25));
		widgets[i]->setPadding(0.0f);
		widgets[i]->setMargin(0.0f);
		gui.getLayout()->addWidget(widgets[i]);
	}

	TEST_UPDATE_AND_RENDER;

	REQUIRE(widgets[0]->getRealPos().x == Approx(0.0f));
	REQUIRE(widgets[0]->getRealPos().y == Approx(0.0f));

	REQUIRE(widgets[1]->getRealPos().x == Approx(100.0f));
	REQUIRE(widgets[1]->getRealPos().y == Approx(0.0f));

	REQUIRE(widgets[2]->getRealPos().x == Approx(200.0f));
	REQUIRE(widgets[2]->getRealPos().y == Approx(0.0f));

	REQUIRE(widgets[3]->getRealPos().x == Approx(300.0f));
	REQUIRE(widgets[3]->getRealPos().y == Approx(0.0f));

	gui.getLayout()->setWrap(true);

	TEST_UPDATE_AND_RENDER;

	REQUIRE(widgets[0]->getRealPos().x == Approx(0.0f));
	REQUIRE(widgets[0]->getRealPos().y == Approx(0.0f));

	REQUIRE(widgets[1]->getRealPos().x == Approx(0.0f));
	REQUIRE(widgets[1]->getRealPos().y == Approx(25));

	REQUIRE(widgets[2]->getRealPos().x == Approx(0.0f));
	REQUIRE(widgets[2]->getRealPos().y == Approx(50.0f));

	REQUIRE(widgets[3]->getRealPos().x == Approx(0.0f));
	REQUIRE(widgets[3]->getRealPos().y == Approx(75));
}

///=============================================================================
TEST_CASE("Wrapping layout #2", "[GuiWidget]") {
	TEST_SETUP_WINDOW(100.0f, 100.0f);

	gui.getLayout()->setWrap(false);
	gui.getLayout()->setOrientation(ffw::GuiLayout::Orientation::VERTICAL);

	GuiWidgetNull* widgets[4];
	for (int i = 0; i < 4; i++) {
		widgets[i] = new GuiWidgetNull(&gui);
		widgets[i]->setSize(ffw::guiPercent(25), ffw::guiPercent(100.0f));
		widgets[i]->setPadding(0.0f);
		widgets[i]->setMargin(0.0f);
		gui.getLayout()->addWidget(widgets[i]);
	}

	TEST_UPDATE_AND_RENDER;

	REQUIRE(widgets[0]->getRealPos().x == Approx(0.0f));
	REQUIRE(widgets[0]->getRealPos().y == Approx(0.0f));

	REQUIRE(widgets[1]->getRealPos().x == Approx(0.0f));
	REQUIRE(widgets[1]->getRealPos().y == Approx(100.0f));

	REQUIRE(widgets[2]->getRealPos().x == Approx(0.0f));
	REQUIRE(widgets[2]->getRealPos().y == Approx(200.0f));

	REQUIRE(widgets[3]->getRealPos().x == Approx(0.0f));
	REQUIRE(widgets[3]->getRealPos().y == Approx(300.0f));

	gui.getLayout()->setWrap(true);

	TEST_UPDATE_AND_RENDER;

	REQUIRE(widgets[0]->getRealPos().x == Approx(0.0f));
	REQUIRE(widgets[0]->getRealPos().y == Approx(0.0f));

	REQUIRE(widgets[1]->getRealPos().x == Approx(25));
	REQUIRE(widgets[1]->getRealPos().y == Approx(0.0f));

	REQUIRE(widgets[2]->getRealPos().x == Approx(50.0f));
	REQUIRE(widgets[2]->getRealPos().y == Approx(0.0f));

	REQUIRE(widgets[3]->getRealPos().x == Approx(75));
	REQUIRE(widgets[3]->getRealPos().y == Approx(0.0f));
}


///=============================================================================
TEST_CASE("hide and show", "[GuiWidget]") {
	TEST_SETUP_WINDOW(100.0f, 100.0f);

	gui.getLayout()->setOrientation(ffw::GuiLayout::Orientation::VERTICAL);

	GuiWidgetNull* widgets[4];
	for (int i = 0; i < 4; i++) {
		widgets[i] = new GuiWidgetNull(&gui);
		widgets[i]->setSize(ffw::guiPercent(100.0f), ffw::guiPercent(25));
		widgets[i]->setPadding(0.0f);
		widgets[i]->setMargin(0.0f);
		gui.getLayout()->addWidget(widgets[i]);
	}

	TEST_UPDATE_AND_RENDER;

	REQUIRE(widgets[0]->getRealPos().x == Approx(0.0f));
	REQUIRE(widgets[0]->getRealPos().y == Approx(0.0f));

	REQUIRE(widgets[1]->getRealPos().x == Approx(0.0f));
	REQUIRE(widgets[1]->getRealPos().y == Approx(25));

	REQUIRE(widgets[2]->getRealPos().x == Approx(0.0f));
	REQUIRE(widgets[2]->getRealPos().y == Approx(50.0f));

	REQUIRE(widgets[3]->getRealPos().x == Approx(0.0f));
	REQUIRE(widgets[3]->getRealPos().y == Approx(75));

	widgets[1]->setHidden(true);

	TEST_UPDATE_AND_RENDER;

	REQUIRE(widgets[0]->getRealPos().x == Approx(0.0f));
	REQUIRE(widgets[0]->getRealPos().y == Approx(0.0f));

	REQUIRE(widgets[2]->getRealPos().x == Approx(0.0f));
	REQUIRE(widgets[2]->getRealPos().y == Approx(25));

	REQUIRE(widgets[3]->getRealPos().x == Approx(0.0f));
	REQUIRE(widgets[3]->getRealPos().y == Approx(50.0f));

	widgets[2]->setHidden(true);

	TEST_UPDATE_AND_RENDER;

	REQUIRE(widgets[0]->getRealPos().x == Approx(0.0f));
	REQUIRE(widgets[0]->getRealPos().y == Approx(0.0f));

	REQUIRE(widgets[3]->getRealPos().x == Approx(0.0f));
	REQUIRE(widgets[3]->getRealPos().y == Approx(25));

	widgets[1]->setHidden(false);

	TEST_UPDATE_AND_RENDER;

	REQUIRE(widgets[0]->getRealPos().x == Approx(0.0f));
	REQUIRE(widgets[0]->getRealPos().y == Approx(0.0f));

	REQUIRE(widgets[1]->getRealPos().x == Approx(0.0f));
	REQUIRE(widgets[1]->getRealPos().y == Approx(25));

	REQUIRE(widgets[3]->getRealPos().x == Approx(0.0f));
	REQUIRE(widgets[3]->getRealPos().y == Approx(50.0f));

	widgets[2]->setHidden(false);

	TEST_UPDATE_AND_RENDER;

	REQUIRE(widgets[0]->getRealPos().x == Approx(0.0f));
	REQUIRE(widgets[0]->getRealPos().y == Approx(0.0f));

	REQUIRE(widgets[1]->getRealPos().x == Approx(0.0f));
	REQUIRE(widgets[1]->getRealPos().y == Approx(25));

	REQUIRE(widgets[2]->getRealPos().x == Approx(0.0f));
	REQUIRE(widgets[2]->getRealPos().y == Approx(50.0f));

	REQUIRE(widgets[3]->getRealPos().x == Approx(0.0f));
	REQUIRE(widgets[3]->getRealPos().y == Approx(75));
}

///=============================================================================
TEST_CASE("Mouse position #1", "[GuiWidget]") {
	TEST_SETUP_WINDOW(100.0f, 100.0f);

	auto layout = new ffw::GuiVerticalLayout(&gui);
	layout->setSize(ffw::guiPercent(100.0f), ffw::guiPercent(100.0f));
	layout->setMargin(0.0f);
	layout->setPadding(10.0f);
	gui.getLayout()->addWidget(layout);

	auto widget = new GuiWidgetNull(&gui);
	widget->setSize(ffw::guiPercent(100.0f), ffw::guiPercent(25));
	widget->setMargin(0.0f);
	widget->setPadding(0.0f);
	layout->addWidget(widget);

	gui.injectMousePos(15, 25);

	TEST_UPDATE_AND_RENDER;

	// Originally at [15, 25]
	// but the padding moves it by [-10.0f, -10]
	REQUIRE(widget->getMousePos().x == 5);
	REQUIRE(widget->getMousePos().y == 15);

	layout->setOffset(ffw::Vec2i(2, 5));

	gui.injectMousePos(15, 25);

	TEST_UPDATE_AND_RENDER;

	// Offset moves it further by [-2, -5]
	REQUIRE(widget->getMousePos().x == 3);
	REQUIRE(widget->getMousePos().y == 10.0f);
}

///=============================================================================
TEST_CASE("Mouse position and mouse button", "[GuiWidget]") {
	TEST_SETUP_WINDOW(100.0f, 100.0f);

	auto layout = new ffw::GuiVerticalLayout(&gui);
	layout->setSize(ffw::guiPercent(100.0f), ffw::guiPercent(100.0f));
	layout->setMargin(0.0f);
	layout->setPadding(10.0f);
	gui.getLayout()->addWidget(layout);

	GuiWidgetNull* widgets[4];

	for (int i = 0; i < 4; i++) {
		widgets[i] = new GuiWidgetNull(&gui);
		widgets[i]->setSize(ffw::guiPercent(100.0f), ffw::guiPercent(25));
		widgets[i]->setMargin(0.0f);
		widgets[i]->setPadding(0.0f);
		layout->addWidget(widgets[i]);
	}

	gui.injectMousePos(15, 25);

	TEST_UPDATE_AND_RENDER;

	REQUIRE(widgets[0]->getMousePos().x == 5);
	REQUIRE(widgets[0]->getMousePos().y == 15);

	REQUIRE(widgets[0]->hasHover() == true);
	REQUIRE(widgets[1]->hasHover() == false);
	REQUIRE(widgets[2]->hasHover() == false);
	REQUIRE(widgets[3]->hasHover() == false);

	gui.injectMousePos(25, 35);

	TEST_UPDATE_AND_RENDER;

	REQUIRE(widgets[0]->getMousePos().x == 5);
	REQUIRE(widgets[0]->getMousePos().y == 15);

	REQUIRE(widgets[1]->getMousePos().x == 15);
	REQUIRE(widgets[1]->getMousePos().y == 5);

	REQUIRE(widgets[0]->hasHover() == false);
	REQUIRE(widgets[1]->hasHover() == true);
	REQUIRE(widgets[2]->hasHover() == false);
	REQUIRE(widgets[3]->hasHover() == false);

	REQUIRE(widgets[0]->hasFocus() == false);
	REQUIRE(widgets[1]->hasFocus() == false);
	REQUIRE(widgets[2]->hasFocus() == false);
	REQUIRE(widgets[3]->hasFocus() == false);

	gui.injectMouseButton(ffw::MouseButton::LEFT, ffw::Mode::PRESSED);

	TEST_UPDATE_AND_RENDER;

	REQUIRE(widgets[0]->getMousePos().x == 5);
	REQUIRE(widgets[0]->getMousePos().y == 15);

	REQUIRE(widgets[1]->getMousePos().x == 15);
	REQUIRE(widgets[1]->getMousePos().y == 5);

	REQUIRE(widgets[0]->hasHover() == false);
	REQUIRE(widgets[1]->hasHover() == true);
	REQUIRE(widgets[2]->hasHover() == false);
	REQUIRE(widgets[3]->hasHover() == false);

	REQUIRE(widgets[0]->hasFocus() == false);
	REQUIRE(widgets[1]->hasFocus() == true);
	REQUIRE(widgets[2]->hasFocus() == false);
	REQUIRE(widgets[3]->hasFocus() == false);

	gui.injectMousePos(25, 55);

	TEST_UPDATE_AND_RENDER;

	REQUIRE(widgets[2]->getMousePos().x == 15);
	REQUIRE(widgets[2]->getMousePos().y == 5);

	REQUIRE(widgets[0]->hasHover() == false);
	REQUIRE(widgets[1]->hasHover() == false);
	REQUIRE(widgets[2]->hasHover() == true);
	REQUIRE(widgets[3]->hasHover() == false);

	REQUIRE(widgets[0]->hasFocus() == false);
	REQUIRE(widgets[1]->hasFocus() == true);
	REQUIRE(widgets[2]->hasFocus() == false);
	REQUIRE(widgets[3]->hasFocus() == false);

	gui.injectMouseButton(ffw::MouseButton::LEFT, ffw::Mode::RELEASED);

	TEST_UPDATE_AND_RENDER;

	REQUIRE(widgets[2]->getMousePos().x == 15);
	REQUIRE(widgets[2]->getMousePos().y == 5);

	REQUIRE(widgets[0]->hasHover() == false);
	REQUIRE(widgets[1]->hasHover() == false);
	REQUIRE(widgets[2]->hasHover() == true);
	REQUIRE(widgets[3]->hasHover() == false);

	REQUIRE(widgets[0]->hasFocus() == false);
	REQUIRE(widgets[1]->hasFocus() == true);
	REQUIRE(widgets[2]->hasFocus() == false);
	REQUIRE(widgets[3]->hasFocus() == false);

	gui.injectMouseButton(ffw::MouseButton::LEFT, ffw::Mode::PRESSED);

	TEST_UPDATE_AND_RENDER;

	REQUIRE(widgets[2]->getMousePos().x == 15);
	REQUIRE(widgets[2]->getMousePos().y == 5);

	REQUIRE(widgets[0]->hasHover() == false);
	REQUIRE(widgets[1]->hasHover() == false);
	REQUIRE(widgets[2]->hasHover() == true);
	REQUIRE(widgets[3]->hasHover() == false);

	REQUIRE(widgets[0]->hasFocus() == false);
	REQUIRE(widgets[1]->hasFocus() == false);
	REQUIRE(widgets[2]->hasFocus() == true);
	REQUIRE(widgets[3]->hasFocus() == false);
}

///=============================================================================
TEST_CASE("Event hover", "[GuiWidget]") {
	TEST_SETUP_WINDOW(100.0f, 100.0f);
	GuiEventCatcher events;

	auto layout = new ffw::GuiVerticalLayout(&gui);
	layout->setSize(ffw::guiPercent(100.0f), ffw::guiPercent(100.0f));
	layout->setMargin(0.0f);
	layout->setPadding(10.0f);
	gui.getLayout()->addWidget(layout);

	GuiWidgetNull* widgets[4];

	for (int i = 0; i < 4; i++) {
		widgets[i] = new GuiWidgetNull(&gui);
		widgets[i]->setSize(ffw::guiPercent(100.0f), ffw::guiPercent(25));
		widgets[i]->setMargin(0.0f);
		widgets[i]->setPadding(0.0f);
		widgets[i]->addEventCallback(&GuiEventCatcher::widgetEvent, &events);
		layout->addWidget(widgets[i]);
	}

	gui.injectMousePos(15, 25);

	TEST_UPDATE_AND_RENDER;

	REQUIRE(widgets[0]->getMousePos().x == 5);
	REQUIRE(widgets[0]->getMousePos().y == 15);

	REQUIRE(events.count(ffw::GuiEvent::Type::HOVER, widgets[0]) == 1);
	REQUIRE(events.count(ffw::GuiEvent::Type::HOVER, widgets[1]) == 0.0f);
	REQUIRE(events.count(ffw::GuiEvent::Type::HOVER, widgets[2]) == 0.0f);
	REQUIRE(events.count(ffw::GuiEvent::Type::HOVER, widgets[3]) == 0.0f);

	REQUIRE(events.get(ffw::GuiEvent::Type::HOVER, widgets[0]).data.hover.gained == true);

	events.reset();
	gui.injectMousePos(25, 35);

	TEST_UPDATE_AND_RENDER;

	REQUIRE(widgets[0]->getMousePos().x == 5);
	REQUIRE(widgets[0]->getMousePos().y == 15);

	REQUIRE(widgets[1]->getMousePos().x == 15);
	REQUIRE(widgets[1]->getMousePos().y == 5);

	REQUIRE(events.count(ffw::GuiEvent::Type::HOVER, widgets[0]) == 1);
	REQUIRE(events.count(ffw::GuiEvent::Type::HOVER, widgets[1]) == 1);
	REQUIRE(events.count(ffw::GuiEvent::Type::HOVER, widgets[2]) == 0.0f);
	REQUIRE(events.count(ffw::GuiEvent::Type::HOVER, widgets[3]) == 0.0f);

	REQUIRE(events.get(ffw::GuiEvent::Type::HOVER, widgets[0]).data.hover.gained == false);
	REQUIRE(events.get(ffw::GuiEvent::Type::HOVER, widgets[1]).data.hover.gained == true);
}

///=============================================================================
TEST_CASE("Event focus", "[GuiWidget]") {
	TEST_SETUP_WINDOW(100.0f, 100.0f);
	GuiEventCatcher events;

	auto layout = new ffw::GuiVerticalLayout(&gui);
	layout->setSize(ffw::guiPercent(100.0f), ffw::guiPercent(100.0f));
	layout->setMargin(0.0f);
	layout->setPadding(10.0f);
	gui.getLayout()->addWidget(layout);

	GuiWidgetNull* widgets[4];

	for (int i = 0; i < 4; i++) {
		widgets[i] = new GuiWidgetNull(&gui);
		widgets[i]->setSize(ffw::guiPercent(100.0f), ffw::guiPercent(25));
		widgets[i]->setMargin(0.0f);
		widgets[i]->setPadding(0.0f);
		widgets[i]->addEventCallback(&GuiEventCatcher::widgetEvent, &events);
		layout->addWidget(widgets[i]);
	}

	gui.injectMousePos(15, 25);
	gui.injectMouseButton(ffw::MouseButton::LEFT, ffw::Mode::PRESSED);

	TEST_UPDATE_AND_RENDER;

	REQUIRE(events.count(ffw::GuiEvent::Type::HOVER, widgets[0]) == 1);
	REQUIRE(events.count(ffw::GuiEvent::Type::HOVER, widgets[1]) == 0.0f);
	REQUIRE(events.count(ffw::GuiEvent::Type::HOVER, widgets[2]) == 0.0f);
	REQUIRE(events.count(ffw::GuiEvent::Type::HOVER, widgets[3]) == 0.0f);

	REQUIRE(events.count(ffw::GuiEvent::Type::FOCUS, widgets[0]) == 1);
	REQUIRE(events.count(ffw::GuiEvent::Type::FOCUS, widgets[1]) == 0.0f);
	REQUIRE(events.count(ffw::GuiEvent::Type::FOCUS, widgets[2]) == 0.0f);
	REQUIRE(events.count(ffw::GuiEvent::Type::FOCUS, widgets[3]) == 0.0f);

	REQUIRE(events.get(ffw::GuiEvent::Type::FOCUS, widgets[0]).data.focus.gained == true);

	events.reset();
	gui.injectMousePos(25, 35);
	gui.injectMouseButton(ffw::MouseButton::LEFT, ffw::Mode::RELEASED);

	TEST_UPDATE_AND_RENDER;

	REQUIRE(events.count(ffw::GuiEvent::Type::FOCUS, widgets[0]) == 0.0f);
	REQUIRE(events.count(ffw::GuiEvent::Type::FOCUS, widgets[1]) == 0.0f);
	REQUIRE(events.count(ffw::GuiEvent::Type::FOCUS, widgets[2]) == 0.0f);
	REQUIRE(events.count(ffw::GuiEvent::Type::FOCUS, widgets[3]) == 0.0f);

	events.reset();
	gui.injectMouseButton(ffw::MouseButton::LEFT, ffw::Mode::PRESSED);

	TEST_UPDATE_AND_RENDER;

	REQUIRE(events.count(ffw::GuiEvent::Type::FOCUS, widgets[0]) == 1);
	REQUIRE(events.count(ffw::GuiEvent::Type::FOCUS, widgets[1]) == 1);
	REQUIRE(events.count(ffw::GuiEvent::Type::FOCUS, widgets[2]) == 0.0f);
	REQUIRE(events.count(ffw::GuiEvent::Type::FOCUS, widgets[3]) == 0.0f);

	REQUIRE(events.get(ffw::GuiEvent::Type::FOCUS, widgets[0]).data.focus.gained == false);
	REQUIRE(events.get(ffw::GuiEvent::Type::FOCUS, widgets[1]).data.focus.gained == true);
}

///=============================================================================
TEST_CASE("Event state", "[GuiWidget]") {
	TEST_SETUP_WINDOW(100.0f, 100.0f);
	GuiEventCatcher events;

	auto layout = new ffw::GuiVerticalLayout(&gui);
	layout->setSize(ffw::guiPercent(100.0f), ffw::guiPercent(100.0f));
	layout->setMargin(0.0f);
	layout->setPadding(10.0f);
	gui.getLayout()->addWidget(layout);

	GuiWidgetNull* widgets[4];

	for (int i = 0; i < 4; i++) {
		widgets[i] = new GuiWidgetNull(&gui);
		widgets[i]->setSize(ffw::guiPercent(100.0f), ffw::guiPercent(25));
		widgets[i]->setMargin(0.0f);
		widgets[i]->setPadding(0.0f);
		widgets[i]->addEventCallback(&GuiEventCatcher::widgetEvent, &events);
		layout->addWidget(widgets[i]);
	}

	TEST_UPDATE_AND_RENDER;

	REQUIRE(events.count(ffw::GuiEvent::Type::STATE, widgets[0]) == 0.0f);
	REQUIRE(events.count(ffw::GuiEvent::Type::STATE, widgets[1]) == 0.0f);
	REQUIRE(events.count(ffw::GuiEvent::Type::STATE, widgets[2]) == 0.0f);
	REQUIRE(events.count(ffw::GuiEvent::Type::STATE, widgets[3]) == 0.0f);

	widgets[0]->setDisabled(true);
	events.reset();
	TEST_UPDATE_AND_RENDER;

	REQUIRE(events.count(ffw::GuiEvent::Type::STATE, widgets[0]) == 1);
	REQUIRE(events.count(ffw::GuiEvent::Type::STATE, widgets[1]) == 0.0f);
	REQUIRE(events.count(ffw::GuiEvent::Type::STATE, widgets[2]) == 0.0f);
	REQUIRE(events.count(ffw::GuiEvent::Type::STATE, widgets[3]) == 0.0f);

	REQUIRE(events.get(ffw::GuiEvent::Type::STATE, widgets[0]).data.state.disabled == true);

	widgets[0]->setDisabled(false);
	events.reset();
	TEST_UPDATE_AND_RENDER;

	REQUIRE(events.count(ffw::GuiEvent::Type::STATE, widgets[0]) == 1);
	REQUIRE(events.count(ffw::GuiEvent::Type::STATE, widgets[1]) == 0.0f);
	REQUIRE(events.count(ffw::GuiEvent::Type::STATE, widgets[2]) == 0.0f);
	REQUIRE(events.count(ffw::GuiEvent::Type::STATE, widgets[3]) == 0.0f);

	REQUIRE(events.get(ffw::GuiEvent::Type::STATE, widgets[0]).data.state.disabled == false);

	widgets[0]->setDisabled(false);
	events.reset();
	TEST_UPDATE_AND_RENDER;

	REQUIRE(events.count(ffw::GuiEvent::Type::STATE, widgets[0]) == 0.0f);
	REQUIRE(events.count(ffw::GuiEvent::Type::STATE, widgets[1]) == 0.0f);
	REQUIRE(events.count(ffw::GuiEvent::Type::STATE, widgets[2]) == 0.0f);
	REQUIRE(events.count(ffw::GuiEvent::Type::STATE, widgets[3]) == 0.0f);
}

///=============================================================================
TEST_CASE("Event input", "[GuiWidget]") {
	TEST_SETUP_WINDOW(100.0f, 100.0f);
	GuiEventCatcher events;

	auto layout = new ffw::GuiVerticalLayout(&gui);
	layout->setSize(ffw::guiPercent(100.0f), ffw::guiPercent(100.0f));
	layout->setMargin(0.0f);
	layout->setPadding(10.0f);
	gui.getLayout()->addWidget(layout);

	GuiWidgetNull* widgets[4];

	for (int i = 0; i < 4; i++) {
		widgets[i] = new GuiWidgetNull(&gui);
		widgets[i]->setSize(ffw::guiPercent(100.0f), ffw::guiPercent(25));
		widgets[i]->setMargin(0.0f);
		widgets[i]->setPadding(0.0f);
		widgets[i]->addEventCallback(&GuiEventCatcher::widgetEvent, &events);
		layout->addWidget(widgets[i]);
	}

	gui.injectText('A');

	TEST_UPDATE_AND_RENDER;

	REQUIRE(events.count(ffw::GuiEvent::Type::INPUT, widgets[0]) == 0.0f);
	REQUIRE(events.count(ffw::GuiEvent::Type::INPUT, widgets[1]) == 0.0f);
	REQUIRE(events.count(ffw::GuiEvent::Type::INPUT, widgets[2]) == 0.0f);
	REQUIRE(events.count(ffw::GuiEvent::Type::INPUT, widgets[3]) == 0.0f);

	events.reset();
	gui.injectText('A');
	gui.injectMousePos(15, 25);
	TEST_UPDATE_AND_RENDER;

	REQUIRE(events.count(ffw::GuiEvent::Type::INPUT, widgets[0]) == 0.0f);
	REQUIRE(events.count(ffw::GuiEvent::Type::INPUT, widgets[1]) == 0.0f);
	REQUIRE(events.count(ffw::GuiEvent::Type::INPUT, widgets[2]) == 0.0f);
	REQUIRE(events.count(ffw::GuiEvent::Type::INPUT, widgets[3]) == 0.0f);

	events.reset();
	gui.injectText('A');
	gui.injectMouseButton(ffw::MouseButton::LEFT, ffw::Mode::PRESSED);
	TEST_UPDATE_AND_RENDER;

	REQUIRE(events.count(ffw::GuiEvent::Type::INPUT, widgets[0]) == 1);
	REQUIRE(events.count(ffw::GuiEvent::Type::INPUT, widgets[1]) == 0.0f);
	REQUIRE(events.count(ffw::GuiEvent::Type::INPUT, widgets[2]) == 0.0f);
	REQUIRE(events.count(ffw::GuiEvent::Type::INPUT, widgets[3]) == 0.0f);

	REQUIRE(events.get(ffw::GuiEvent::Type::INPUT, widgets[0]).data.input.chr == 'A');

	events.reset();
	gui.injectText('A');
	gui.injectMouseButton(ffw::MouseButton::LEFT, ffw::Mode::RELEASED);
	TEST_UPDATE_AND_RENDER;

	REQUIRE(events.count(ffw::GuiEvent::Type::INPUT, widgets[0]) == 1);
	REQUIRE(events.count(ffw::GuiEvent::Type::INPUT, widgets[1]) == 0.0f);
	REQUIRE(events.count(ffw::GuiEvent::Type::INPUT, widgets[2]) == 0.0f);
	REQUIRE(events.count(ffw::GuiEvent::Type::INPUT, widgets[3]) == 0.0f);

	REQUIRE(events.get(ffw::GuiEvent::Type::INPUT, widgets[0]).data.input.chr == 'A');

	events.reset();
	gui.injectText('A');
	gui.injectMousePos(15, 0);
	gui.injectMouseButton(ffw::MouseButton::LEFT, ffw::Mode::PRESSED);
	TEST_UPDATE_AND_RENDER;

	REQUIRE(events.count(ffw::GuiEvent::Type::INPUT, widgets[0]) == 0.0f);
	REQUIRE(events.count(ffw::GuiEvent::Type::INPUT, widgets[1]) == 0.0f);
	REQUIRE(events.count(ffw::GuiEvent::Type::INPUT, widgets[2]) == 0.0f);
	REQUIRE(events.count(ffw::GuiEvent::Type::INPUT, widgets[3]) == 0.0f);
}

///=============================================================================
TEST_CASE("Default focus", "[GuiWidget]") {
	TEST_SETUP_WINDOW(100.0f, 100.0f);

	auto layout = new ffw::GuiVerticalLayout(&gui);
	layout->setSize(ffw::guiPercent(100.0f), ffw::guiPercent(100.0f));
	layout->setMargin(0.0f);
	layout->setPadding(10.0f);
	gui.getLayout()->addWidget(layout);

	auto widget = new GuiWidgetNull(&gui);
	widget->setSize(ffw::guiPercent(100.0f), ffw::guiPercent(25));
	widget->setMargin(0.0f);
	widget->setPadding(0.0f);
	layout->addWidget(widget);

	TEST_UPDATE_AND_RENDER;

	REQUIRE(widget->hasFocus() == false);

	gui.injectMousePos(15, 25);
	gui.injectMouseButton(ffw::MouseButton::LEFT, ffw::Mode::PRESSED);

	TEST_UPDATE_AND_RENDER;

	REQUIRE(widget->hasFocus() == true);

	gui.injectMouseButton(ffw::MouseButton::LEFT, ffw::Mode::RELEASED);

	TEST_UPDATE_AND_RENDER;

	REQUIRE(widget->hasFocus() == true);

	gui.injectMousePos(15, 55);
	gui.injectMouseButton(ffw::MouseButton::LEFT, ffw::Mode::PRESSED);

	TEST_UPDATE_AND_RENDER;

	REQUIRE(widget->hasFocus() == false);

	gui.injectMouseButton(ffw::MouseButton::LEFT, ffw::Mode::RELEASED);

	TEST_UPDATE_AND_RENDER;

	REQUIRE(widget->hasFocus() == false);
}

///=============================================================================
TEST_CASE("Sticky focus", "[GuiWidget]") {
	TEST_SETUP_WINDOW(100.0f, 100.0f);

	auto layout = new ffw::GuiVerticalLayout(&gui);
	layout->setSize(ffw::guiPercent(100.0f), ffw::guiPercent(100.0f));
	layout->setMargin(0.0f);
	layout->setPadding(10.0f);
	gui.getLayout()->addWidget(layout);

	auto widget = new GuiWidgetNullSticky(&gui);
	widget->setSize(ffw::guiPercent(100.0f), ffw::guiPercent(25));
	widget->setMargin(0.0f);
	widget->setPadding(0.0f);
	layout->addWidget(widget);

	TEST_UPDATE_AND_RENDER;

	REQUIRE(widget->hasFocus() == false);

	gui.injectMousePos(15, 25);
	gui.injectMouseButton(ffw::MouseButton::LEFT, ffw::Mode::PRESSED);

	TEST_UPDATE_AND_RENDER;

	REQUIRE(widget->hasFocus() == true);

	gui.injectMouseButton(ffw::MouseButton::LEFT, ffw::Mode::RELEASED);

	TEST_UPDATE_AND_RENDER;

	REQUIRE(widget->hasFocus() == true);

	gui.injectMousePos(15, 55);
	gui.injectMouseButton(ffw::MouseButton::LEFT, ffw::Mode::PRESSED);

	TEST_UPDATE_AND_RENDER;

	REQUIRE(widget->hasFocus() == true);

	gui.injectMouseButton(ffw::MouseButton::LEFT, ffw::Mode::RELEASED);

	TEST_UPDATE_AND_RENDER;

	REQUIRE(widget->hasFocus() == true);
}


///=============================================================================
TEST_CASE("Drop focus", "[GuiWidget]") {
	TEST_SETUP_WINDOW(100.0f, 100.0f);

	auto layout = new ffw::GuiVerticalLayout(&gui);
	layout->setSize(ffw::guiPercent(100.0f), ffw::guiPercent(100.0f));
	layout->setMargin(0.0f);
	layout->setPadding(10.0f);
	gui.getLayout()->addWidget(layout);

	auto widget = new GuiWidgetNullDrop(&gui);
	widget->setSize(ffw::guiPercent(100.0f), ffw::guiPercent(25));
	widget->setMargin(0.0f);
	widget->setPadding(0.0f);
	layout->addWidget(widget);

	TEST_UPDATE_AND_RENDER;

	REQUIRE(widget->hasFocus() == false);

	gui.injectMousePos(15, 25);
	gui.injectMouseButton(ffw::MouseButton::LEFT, ffw::Mode::PRESSED);

	TEST_UPDATE_AND_RENDER;

	REQUIRE(widget->hasFocus() == true);

	gui.injectMouseButton(ffw::MouseButton::LEFT, ffw::Mode::RELEASED);

	TEST_UPDATE_AND_RENDER;

	REQUIRE(widget->hasFocus() == false);

	gui.injectMousePos(15, 55);
	gui.injectMouseButton(ffw::MouseButton::LEFT, ffw::Mode::PRESSED);

	TEST_UPDATE_AND_RENDER;

	REQUIRE(widget->hasFocus() == false);

	gui.injectMouseButton(ffw::MouseButton::LEFT, ffw::Mode::RELEASED);

	TEST_UPDATE_AND_RENDER;

	REQUIRE(widget->hasFocus() == false);
}

///=============================================================================
TEST_CASE("Toggle focus", "[GuiWidget]") {
	TEST_SETUP_WINDOW(100.0f, 100.0f);

	auto layout = new ffw::GuiVerticalLayout(&gui);
	layout->setSize(ffw::guiPercent(100.0f), ffw::guiPercent(100.0f));
	layout->setMargin(0.0f);
	layout->setPadding(10.0f);
	gui.getLayout()->addWidget(layout);

	auto widget = new GuiWidgetNullToggle(&gui);
	widget->setSize(ffw::guiPercent(100.0f), ffw::guiPercent(25));
	widget->setMargin(0.0f);
	widget->setPadding(0.0f);
	layout->addWidget(widget);

	TEST_UPDATE_AND_RENDER;

	REQUIRE(widget->hasFocus() == false);

	gui.injectMousePos(15, 25);
	gui.injectMouseButton(ffw::MouseButton::LEFT, ffw::Mode::PRESSED);

	TEST_UPDATE_AND_RENDER;

	REQUIRE(widget->hasFocus() == true);

	gui.injectMouseButton(ffw::MouseButton::LEFT, ffw::Mode::RELEASED);

	TEST_UPDATE_AND_RENDER;

	REQUIRE(widget->hasFocus() == true);

	gui.injectMousePos(15, 55);
	gui.injectMouseButton(ffw::MouseButton::LEFT, ffw::Mode::PRESSED);

	TEST_UPDATE_AND_RENDER;

	REQUIRE(widget->hasFocus() == true);

	gui.injectMouseButton(ffw::MouseButton::LEFT, ffw::Mode::RELEASED);

	TEST_UPDATE_AND_RENDER;

	REQUIRE(widget->hasFocus() == true);

	gui.injectMousePos(15, 25);
	gui.injectMouseButton(ffw::MouseButton::LEFT, ffw::Mode::PRESSED);

	TEST_UPDATE_AND_RENDER;

	REQUIRE(widget->hasFocus() == false);
}

///=============================================================================
TEST_CASE("Text wrapping", "[GuiTextWrapper]") {
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
TEST_CASE("Text wrapping with whitespace", "[GuiTextWrapper]") {
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
TEST_CASE("Text wrapping with multiple fonts", "[GuiTextWrapper]") {
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
TEST_CASE("Text wrapping with multiple fonts and heights", "[GuiTextWrapper]") {
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
TEST_CASE("Text wrapping with multiple fonts and whitespaces", "[GuiTextWrapper]") {
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
TEST_CASE("Text wrapping stepper", "[GuiTextWrapper]") {
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