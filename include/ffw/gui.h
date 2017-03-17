/**
 * @defgroup gui gui - Graphical User Interface
 * @brief Render engine independent graphic user interface 
 *
 * This module provides functions and classes to create and manage
 * GUI widgets and windows. This module does not use a specific
 * rendering backend. Instead, it provides an interface, which
 * can is provided for the user to implement any rendering
 * engine backend.
 */
#ifndef FFW_GUI_MODULE
#define FFW_GUI_MODULE
#include "gui/guibackend.h"
#include "gui/guibutton.h"
#include "gui/guibuttontoggle.h"
#include "gui/guicheckbox.h"
#include "gui/guifont.h"
#include "gui/guiimage.h"
#include "gui/guiimageviewer.h"
#include "gui/guilabel.h"
#include "gui/guilayout.h"
#include "gui/guilist.h"
#include "gui/guiprogressbar.h"
#include "gui/guiprogresscircle.h"
#include "gui/guiradio.h"
#include "gui/guirichtext.h"
#include "gui/guiscrollable.h"
#include "gui/guiscrollbar.h"
#include "gui/guislider.h"
#include "gui/guiswitch.h"
#include "gui/guitab.h"
#include "gui/guitextedit.h"
#include "gui/guitextwrapper.h"
#include "gui/guiwidget.h"
#include "gui/guiwindow.h"
#endif