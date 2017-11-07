/**
 * @defgroup media media - Image and 3D object file loaders/savers
 * @brief Provides classes for reading and writing image files and
 * loadinf of 3D OBJ files.
 * @details Provides functions and classes to load and save image files 
 * such as PNG, JPG, PBM, BMP, TIF, TGA, and loading OBJ (3D objects) 
 * as well. Uses following third party libraries: 
 * [libjpeg](http://www.ijg.org/), 
 * [libpng](http://www.libpng.org/pub/png/libpng.html), 
 * [libtiff](http://www.libtiff.org/), 
 * and [libz](http://www.zlib.net/)
 */
#ifndef FFW_GUI_MODULE
#define FFW_GUI_MODULE
#include "media/ddsloader.h"
#include "media/ddssaver.h"
#include "media/pngloader.h"
#include "media/pngsaver.h"
#include "media/jpgloader.h"
#include "media/jpgsaver.h"
#include "media/bmploader.h"
#include "media/bmpsaver.h"
#include "media/pbmloader.h"
#include "media/pbmsaver.h"
#include "media/tgaloader.h"
#include "media/tgasaver.h"
#include "media/tifloader.h"
#include "media/tifsaver.h"
#include "media/imageutils.h"
#include "media/objloader.h"
#endif