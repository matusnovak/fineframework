/* This file is part of FineFramework project */
#ifndef FFW_GL_MONITORS
#define FFW_GL_MONITORS
#include "../config.h"
#include "../math.h"
#include <string>
#include <vector>

namespace ffw{
    struct Monitor{
        std::string name;
        Vec2i resolution;
        Vec3i bitDepth;
        int refreshRate;
        Vec2i position;
        Vec2i physicalSize;
        void* ptr = NULL;
    };
    struct MonitorMode{
        Vec2i resolution;
        Vec3i bitDepth;
        int refreshRate;
    };
    std::vector<Monitor> FFW_API GetMonitors();
    Monitor FFW_API GetPrimaryMonitor();
    std::vector<MonitorMode> FFW_API GetMonitorModes(Monitor monitor);
};
#endif
