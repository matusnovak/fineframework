/*** This file is part of FineFramework project ***/

#include "ffw/graphics/monitors.h"

#include <GLFW/glfw3.h>

///=============================================================================
std::vector<ffw::Monitor> ffw::GetMonitors(){
    int count;
    GLFWmonitor** monitorPtrs = glfwGetMonitors(&count);
    std::vector<Monitor> allMonitors;
    for(int i = 0; i < count; i++){
        allMonitors.push_back(Monitor());

        allMonitors[i].name.assign(glfwGetMonitorName(monitorPtrs[i]));
        glfwGetMonitorPhysicalSize(monitorPtrs[i], &(allMonitors[i].physicalSize.x), &(allMonitors[i].physicalSize.y));
        glfwGetMonitorPos(monitorPtrs[i], &(allMonitors[i].position.x), &(allMonitors[i].position.y));
        const GLFWvidmode* mode = glfwGetVideoMode(monitorPtrs[i]);
        allMonitors[i].resolution.x = mode->width;
        allMonitors[i].resolution.y = mode->height;
        allMonitors[i].bitDepth.x = mode->redBits;
        allMonitors[i].bitDepth.y = mode->greenBits;
        allMonitors[i].bitDepth.z = mode->blueBits;
        allMonitors[i].refreshRate = mode->refreshRate;

        allMonitors[i].ptr = static_cast<void*>(monitorPtrs[i]);
    }
    return allMonitors;
}

///=============================================================================
ffw::Monitor ffw::GetPrimaryMonitor(){
    GLFWmonitor* monitorPtr = glfwGetPrimaryMonitor();
    Monitor primaryMonitor;
    primaryMonitor.name.assign(glfwGetMonitorName(monitorPtr));
    glfwGetMonitorPhysicalSize(monitorPtr, &(primaryMonitor.physicalSize.x), &(primaryMonitor.physicalSize.y));
    glfwGetMonitorPos(monitorPtr, &(primaryMonitor.position.x), &(primaryMonitor.position.y));
    const GLFWvidmode* mode = glfwGetVideoMode(monitorPtr);
    primaryMonitor.resolution.x = mode->width;
    primaryMonitor.resolution.y = mode->height;
    primaryMonitor.bitDepth.x = mode->redBits;
    primaryMonitor.bitDepth.y = mode->greenBits;
    primaryMonitor.bitDepth.z = mode->blueBits;
    primaryMonitor.refreshRate = mode->refreshRate;

    primaryMonitor.ptr = monitorPtr;
    return primaryMonitor;
}

///=============================================================================
std::vector<ffw::MonitorMode> ffw::GetMonitorModes(ffw::Monitor monitor){
    std::vector<MonitorMode> allModes;
    int count;
    const GLFWvidmode* modes = glfwGetVideoModes((GLFWmonitor*)monitor.ptr, &count);

    for(int i = 0; i < count; i++){
        allModes.push_back(MonitorMode());
        allModes[i].resolution.x = modes[i].width;
        allModes[i].resolution.y = modes[i].height;
        allModes[i].bitDepth.x = modes[i].redBits;
        allModes[i].bitDepth.y = modes[i].greenBits;
        allModes[i].bitDepth.z = modes[i].blueBits;
        allModes[i].refreshRate = modes[i].refreshRate;
    }
    return allModes;
}
