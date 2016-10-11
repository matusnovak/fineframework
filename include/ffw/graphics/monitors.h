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
    struct Monitor{
        std::string name;
        Vec2i resolution;
        Vec3i bitDepth;
        int refreshRate;
        Vec2i position;
        Vec2i physicalSize;
        void* ptr = NULL;
    };
	/**
	 * @ingroup graphics
	 */
    struct MonitorMode{
        Vec2i resolution;
        Vec3i bitDepth;
        int refreshRate;
    };
	/**
	 * @ingroup graphics
	 */
    std::vector<Monitor> FFW_API GetMonitors();
	/**
	 * @ingroup graphics
	 */
    Monitor FFW_API GetPrimaryMonitor();
	/**
	 * @ingroup graphics
	 */
    std::vector<MonitorMode> FFW_API GetMonitorModes(Monitor monitor);
};
#endif
