/* This file is part of FineFramework project */
#ifndef FFW_GL_MONITORS
#define FFW_GL_MONITORS
#include "../config.h"
#include "../math/vec3.h"
#include <string>
#include <vector>

namespace ffw{
	/**
	 * @ingroup graphics
	 */
    struct Monitor {
		struct Mode {
			/**
			* @brief Resolution
			*/
			Vec2i resolution;
			/**
			* @brief Bith depth
			* @details
			*     - .x = RED
			*     - .y = GREEN
			*     - .z = BLUE
			*/
			Vec3i bitDepth;
			/**
			* @brief The prefered refresh rate (V-sync)
			*/
			int refreshRate;
		};
		/**
		* @brief Name of the physical monitor
		*/
        std::string name;
		/**
		* @brief The current resolution
		*/
        Vec2i resolution;
		/**
		* @brief The current bith depth
		* @details
		*     - .x = RED
		*     - .y = GREEN
		*     - .z = BLUE
		*/
        Vec3i bitDepth;
		/**
		* @brief The current refresh rate (V-sync)
		*/
        int refreshRate;
		/**
		* @brief The relative position to the primary monitor, in pixels
		*/
        Vec2i position;
		/**
		* @brief The physical size of the monitor in millimeters
		*/
        Vec2i physicalSize;
		/**
		* @brief GLFW specific pointer
		*/
        void* ptr = NULL;
    };
};
#endif
