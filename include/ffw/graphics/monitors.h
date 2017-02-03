/* This file is part of FineFramework project */
#ifndef FFW_GL_MONITORS
#define FFW_GL_MONITORS
#include "../config.h"
#include "../math.h"
#include <string>
#include <vector>

namespace ffw{
	/**
	 * @ingroup graphics
	 */
    struct Monitor {
		struct Mode {
			Vec2i resolution;
			Vec3i bitDepth;
			int refreshRate;
		};
        std::string name;
        Vec2i resolution;
        Vec3i bitDepth;
        int refreshRate;
        Vec2i position;
        Vec2i physicalSize;
        void* ptr = NULL;
    };
};
#endif
