Example: Gui All Widgets
-----------------------------------------

![Screenshot](example-gui-all-widgets.jpg)

The purpose of this example is to show all pre-defined GUI widgets inside of the fine gui module. This example uses OpenGL as an backend engine. The ffw::GuiWindowOpenGL class is provided for the user but **has to be manually included as `#include <ffw/gui/guiwindowopengl.h>` after importing graphics module.** The user is free to choose any backend they wishes to use. To implement one, follow ffw::GuiBackend and ffw::GuiWindowOpenGL documentation.

**Requires finegraphics, finegui, and finemath module to run**

@include ../examples/gui/guiallwidgets.cpp