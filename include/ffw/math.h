/**
 * @defgroup math math - Math functions and data types
 * @brief From basic up to advanced math function and 
 * additional data types such as vectors, matrices, and more
 * @details This module is header only, it does not need to 
 * be compiled, and is used by all modules listed here. Contains 
 * various math functions (calculating angles, creating 
 * model-view-projection matrices, colour management, UTF-8 to 
 * wide string conversion) and also provides several new types
 * (2D, 3D, and 4D vectors, matrices, ring buffers, quaternions, 
 * and more).
 */
#ifndef FFW_MATH_MODULE
#define FFW_MATH_MODULE
#include "math/functions.h"
#include "math/quaternion.h"
#include "math/vec2.h"
#include "math/vec3.h"
#include "math/vec4.h"
#include "math/vecx.h"
#include "math/mat4.h"
#include "math/color.h"
#include "math/any.h"
#include "math/tokenizer.h"
#include "math/stringmath.h"
#include "math/ringbuffer.h"
#include "math/imagebuffer.h"
#include "math/mvp.h"
#include "math/textwrapper.h"
#endif
