/*** This file is part of FineFramework project ***/
#define FFW_DO_NOT_EXPORT_GL_PROC 1
#include "ffw/graphics/glfwrenderwindow.h"
#include "ffw/graphics/monitors.h"
#include "ffw/math/imagebuffer.h"
#include <GLFW/glfw3.h>

class GraphicsInitializer {
public:
    GraphicsInitializer() {
        counter = 0;
    }
    ~GraphicsInitializer() {
        if(counter >= 1) {
            glfwTerminate();
        }
    }
    bool init() {
        if (counter == 0) {
            const auto result = glfwInit();
            if(!result) {
                return false;
            }
        }
        counter++;
        return true;
    }
private:
    size_t counter;
};

static GraphicsInitializer graphicsInitializer;

///=============================================================================
std::vector<ffw::Monitor> ffw::GLFWRenderWindow::getMonitors() {
    if(!graphicsInitializer.init()) {
        return std::vector<ffw::Monitor>();
    }
    
    int cnt;
    GLFWmonitor** monitorPtrs = glfwGetMonitors(&cnt);
    std::vector<Monitor> allMonitors;
    for (int i = 0; i < cnt; i++) {
        allMonitors.emplace_back(Monitor());

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
ffw::Monitor ffw::GLFWRenderWindow::getPrimaryMonitor() {
    if (!graphicsInitializer.init()) {
        return ffw::Monitor();
    }
    
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
std::vector<ffw::Monitor::Mode> ffw::GLFWRenderWindow::getMonitorModes(const ffw::Monitor& monitor) {
    std::vector<Monitor::Mode> allModes;
    int cnt;
    const GLFWvidmode* modes = glfwGetVideoModes(reinterpret_cast<GLFWmonitor*>(monitor.ptr), &cnt);

    for (int i = 0; i < cnt; i++) {
        allModes.emplace_back(Monitor::Mode());
        allModes[i].resolution.x = modes[i].width;
        allModes[i].resolution.y = modes[i].height;
        allModes[i].bitDepth.x = modes[i].redBits;
        allModes[i].bitDepth.y = modes[i].greenBits;
        allModes[i].bitDepth.z = modes[i].blueBits;
        allModes[i].refreshRate = modes[i].refreshRate;
    }
    return allModes;
}

///=============================================================================
struct ffw::GLFWRenderWindow::WindowCallback{
    static void keyPressedCB            (GLFWwindow* windowContext, int key, int scancode, int action, int mods);
    static void textInputCB             (GLFWwindow* windowContext, unsigned int key);
    static void mouseMovedCB            (GLFWwindow* windowContext, double xpos, double ypos);
    static void mouseButtonPressedCB    (GLFWwindow* windowContext, int button,int action, int mods);
    static void mouseScrolledCB         (GLFWwindow* windowContext, double xoffset, double yoffset);
    static void windowShouldCloseCB     (GLFWwindow* windowContext);
    static void windowMovedCB           (GLFWwindow* windowContext, int xpos, int ypos);
    static void windowResizedCB         (GLFWwindow* windowContext, int width, int height);
    static void windowFocusCB           (GLFWwindow* windowContext, int focus);
    static void filesFroppedCB          (GLFWwindow* windowContext, int cnt, const char** files);
};

///=============================================================================
void ffw::GLFWRenderWindow::WindowCallback::keyPressedCB(GLFWwindow* windowContext, const int key, const int scancode, const int action, const int mods){
    (void)scancode;
    (void)mods;
    GLFWRenderWindow* windowPtr = static_cast<ffw::GLFWRenderWindow*>(glfwGetWindowUserPointer(windowContext));
    windowPtr->keyPressedEvent(static_cast<ffw::Key>(key), static_cast<ffw::Mode>(action));
}

///=============================================================================
void ffw::GLFWRenderWindow::WindowCallback::textInputCB(GLFWwindow* windowContext, const unsigned int key){
    GLFWRenderWindow* windowPtr = static_cast<ffw::GLFWRenderWindow*>(glfwGetWindowUserPointer(windowContext));
    windowPtr->textInputEvent(key);
}

///=============================================================================
void ffw::GLFWRenderWindow::WindowCallback::mouseMovedCB(GLFWwindow* windowContext, const double xpos, const double ypos){
    GLFWRenderWindow* windowPtr = static_cast<ffw::GLFWRenderWindow*>(glfwGetWindowUserPointer(windowContext));
    windowPtr->mouseMovedEvent(int(xpos), int(ypos));
}

///=============================================================================
void ffw::GLFWRenderWindow::WindowCallback::mouseButtonPressedCB(GLFWwindow* windowContext, const int button, const int action, const int mods){
    (void)mods;
    GLFWRenderWindow* windowPtr = static_cast<ffw::GLFWRenderWindow*>(glfwGetWindowUserPointer(windowContext));
    windowPtr->mouseButtonEvent(static_cast<ffw::MouseButton>(button), static_cast<ffw::Mode>(action));
}

///=============================================================================
void ffw::GLFWRenderWindow::WindowCallback::mouseScrolledCB(GLFWwindow* windowContext, const double xoffset, const double yoffset){
    (void)xoffset;
    GLFWRenderWindow* windowPtr = static_cast<ffw::GLFWRenderWindow*>(glfwGetWindowUserPointer(windowContext));
    windowPtr->mouseScrollEvent(int(yoffset));
}

///=============================================================================
void ffw::GLFWRenderWindow::WindowCallback::windowShouldCloseCB(GLFWwindow* windowContext){
    GLFWRenderWindow* windowPtr = static_cast<ffw::GLFWRenderWindow*>(glfwGetWindowUserPointer(windowContext));
    windowPtr->windowCloseEvent();
}

///=============================================================================
void ffw::GLFWRenderWindow::WindowCallback::windowMovedCB(GLFWwindow* windowContext, const int xpos, const int ypos){
    GLFWRenderWindow* windowPtr = static_cast<ffw::GLFWRenderWindow*>(glfwGetWindowUserPointer(windowContext));
    windowPtr->windowMovedEvent(xpos, ypos);
}

///=============================================================================
void ffw::GLFWRenderWindow::WindowCallback::windowResizedCB(GLFWwindow* windowContext, const int width, const int height){
    GLFWRenderWindow* windowPtr = static_cast<ffw::GLFWRenderWindow*>(glfwGetWindowUserPointer(windowContext));
    windowPtr->windowResizedEvent(width, height);
}

///=============================================================================
void ffw::GLFWRenderWindow::WindowCallback::windowFocusCB(GLFWwindow* windowContext, const int focus){
    GLFWRenderWindow* windowPtr = static_cast<ffw::GLFWRenderWindow*>(glfwGetWindowUserPointer(windowContext));
    windowPtr->windowFocusEvent(focus == 1);
}

///=============================================================================
void ffw::GLFWRenderWindow::WindowCallback::filesFroppedCB(GLFWwindow* windowContext, const int cnt, const char** files){
    GLFWRenderWindow* windowPtr = static_cast<ffw::GLFWRenderWindow*>(glfwGetWindowUserPointer(windowContext));
    std::vector<std::string> fileList;
    fileList.resize(cnt);
    for(auto i = 0; i < cnt; i++){
        fileList[i].assign(files[i]);
    }
    windowPtr->filesDroppedEvent(fileList);
}

///=============================================================================
class ffw::GLFWRenderWindow::impl{
public:
    ffw::GLFWRenderWindow* otherWindow;
    GLFWwindow* windowHandle;
    ffw::Vec4i sizeBeforeFillscreen;
    bool setupDone;
    bool initialized;
    bool closed;
    bool singleBuffer;
};

///=============================================================================
ffw::GLFWRenderWindow::GLFWRenderWindow():pimpl(new impl){
    pimpl->initialized = false;
    pimpl->setupDone = false;
    pimpl->otherWindow = nullptr;
    pimpl->windowHandle = nullptr;
    pimpl->closed = true;
    pimpl->singleBuffer = false;
}

///=============================================================================
ffw::GLFWRenderWindow::GLFWRenderWindow(GLFWRenderWindow&& Other) NOEXCEPT :pimpl(Other.pimpl){
    Other.pimpl = nullptr;
}

///=============================================================================
ffw::GLFWRenderWindow& ffw::GLFWRenderWindow::operator = (GLFWRenderWindow&& Other) NOEXCEPT {
    if(&Other != this){
        delete pimpl;
        pimpl = Other.pimpl;
        Other.pimpl = nullptr;
    }
    return *this;
}

///=============================================================================
ffw::GLFWRenderWindow::~GLFWRenderWindow(){
    if(pimpl != nullptr){
        destroyWindowData();
        delete pimpl;
    }
}

///=============================================================================
void ffw::GLFWRenderWindow::setPos(const int posx, const int posy){
    if(!pimpl->initialized)return;
    glfwSetWindowPos(pimpl->windowHandle, posx, posy);
}

///=============================================================================
void ffw::GLFWRenderWindow::setSize(const int width, const int height){
    if(!pimpl->initialized)return;
    glfwSetWindowSize(pimpl->windowHandle, width, height);
}

///=============================================================================
ffw::Vec2i ffw::GLFWRenderWindow::getPos() const {
    ffw::Vec2i pos;
    if(!pimpl->initialized)return pos;
    glfwGetWindowPos(pimpl->windowHandle, &pos.x, &pos.y);
    return pos;
}

///=============================================================================
ffw::Vec2i ffw::GLFWRenderWindow::getSize() const {
    ffw::Vec2i size;
    if(!pimpl->initialized)return size;
    glfwGetFramebufferSize(pimpl->windowHandle, &size.x, &size.y);
    return size;
}

///=============================================================================
bool ffw::GLFWRenderWindow::create(const ffw::GLFWRenderWindowArgs& args, ffw::GLFWRenderWindow* other, ffw::Monitor* targetMonitor){
    if(pimpl->initialized)return false;
    if(args.size.x < 0 || args.size.y < 0)return false;

    if (!graphicsInitializer.init())return false;

    glfwWindowHint(GLFW_RESIZABLE, args.resizable);
    glfwWindowHint(GLFW_DECORATED, args.border);
    glfwWindowHint(GLFW_AUTO_ICONIFY, args.maximize);
    glfwWindowHint(GLFW_FLOATING, args.floating);
    glfwWindowHint(GLFW_FOCUSED, args.focused);
    glfwWindowHint(GLFW_SAMPLES, args.samples);
    glfwWindowHint(GLFW_VISIBLE, args.visible);
    //glfwWindowHint(GLFW_DOUBLEBUFFER, !Args.singleBuffer);

    GLFWwindow* parentWindowHandle = nullptr;
    GLFWmonitor* monitor = nullptr;
    pimpl->otherWindow = other;

    if(other != nullptr)parentWindowHandle = other->pimpl->windowHandle;

    if(targetMonitor != nullptr)monitor = static_cast<GLFWmonitor*>(targetMonitor->ptr);

    GLFWwindow* newWindowContext = glfwCreateWindow(args.size.x, args.size.y, args.title.c_str(), monitor, parentWindowHandle);

    if(args.pos.x != -1 && args.pos.y != -1)
        glfwSetWindowPos(newWindowContext, args.pos.x, args.pos.y);

    if(newWindowContext == nullptr){
        return false;
    }

    if (args.icon != nullptr && args.icon->isAllocated()) {
        GLFWimage image;
        image.width = args.icon->getWidth();
        image.height = args.icon->getHeight();
        image.pixels = const_cast<unsigned char*>(args.icon->getPtr());

        glfwSetWindowIcon(newWindowContext, 1, &image);
    }

    glfwSetWindowUserPointer    (newWindowContext, this);
    glfwSetKeyCallback          (newWindowContext, WindowCallback::keyPressedCB);
    glfwSetCursorPosCallback    (newWindowContext, WindowCallback::mouseMovedCB);
    glfwSetMouseButtonCallback  (newWindowContext, WindowCallback::mouseButtonPressedCB);
    glfwSetCharCallback         (newWindowContext, WindowCallback::textInputCB);
    glfwSetScrollCallback       (newWindowContext, WindowCallback::mouseScrolledCB);
    glfwSetWindowPosCallback    (newWindowContext, WindowCallback::windowMovedCB);
    glfwSetWindowSizeCallback   (newWindowContext, WindowCallback::windowResizedCB);
    glfwSetWindowCloseCallback  (newWindowContext, WindowCallback::windowShouldCloseCB);
    glfwSetWindowFocusCallback  (newWindowContext, WindowCallback::windowFocusCB);
    glfwSetDropCallback         (newWindowContext, WindowCallback::filesFroppedCB);

    pimpl->initialized = true;
    pimpl->windowHandle = newWindowContext;
    pimpl->closed = false;

    if(!setupContext()){
        destroy();
        return false;
    }

    if(args.initDrawing && !this->initDrawing()) {
        destroy();
        return false;
    }

    glfwSwapInterval(1);
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    return true;
}

///=============================================================================
void ffw::GLFWRenderWindow::setWindowedMode() const {
    if(pimpl->initialized){
        const auto& s = pimpl->sizeBeforeFillscreen;
        glfwSetWindowMonitor(pimpl->windowHandle, nullptr, s.x, s.y, s.z, s.w, GLFW_DONT_CARE);
    }
}

///=============================================================================
void ffw::GLFWRenderWindow::setWindowedMode(const int posx, const int posy, const int width, const int height) const {
    if(pimpl->initialized){
        glfwSetWindowMonitor(pimpl->windowHandle, nullptr, posx, posy, width, height, GLFW_DONT_CARE);
    }
}

///=============================================================================
void ffw::GLFWRenderWindow::setFullscreen(const Monitor* monitor) const {
    if(pimpl->initialized && monitor != nullptr){
        pimpl->sizeBeforeFillscreen.set(getPos().x, getPos().y, getSize().x, getSize().y);
        glfwSetWindowMonitor(pimpl->windowHandle, nullptr, 0, 0, monitor->resolution.x, monitor->resolution.y, monitor->refreshRate);
    }
}

///=============================================================================
static void* getProcaddress(const char* str){
    return reinterpret_cast<void*>(glfwGetProcAddress(str));
}

///=============================================================================
bool ffw::GLFWRenderWindow::setupContext() {
    glfwMakeContextCurrent(pimpl->windowHandle);
    loadGlCoreArb(&getProcaddress);
    return true;
}

///=============================================================================
void ffw::GLFWRenderWindow::destroyWindowData() {
    if(pimpl->windowHandle != nullptr){
        glfwDestroyWindow(pimpl->windowHandle);
        pimpl->windowHandle = nullptr;
    }
}

///=============================================================================
void ffw::GLFWRenderWindow::shouldClose(const bool close){
    pimpl->closed = close;
}

///=============================================================================
void ffw::GLFWRenderWindow::destroy(){
    if(pimpl->initialized){
        close();
    }
    destroyWindowData();
    pimpl->initialized = false;
    pimpl->closed = true;
}

///=============================================================================
void ffw::GLFWRenderWindow::renderFrame(){
    if(!pimpl->initialized)return;

    glfwMakeContextCurrent(pimpl->windowHandle);

    if(pimpl->singleBuffer){
        glDrawBuffer(GL_FRONT);
    }

    ffw::Vec2i size;
    glfwGetWindowSize(pimpl->windowHandle, &size.x, &size.y);

    glViewport(0, 0, size.x, size.y);

    this->render();

    if(pimpl->singleBuffer){
        glFlush();
        glFinish();
    } else {
        glfwSwapBuffers(pimpl->windowHandle);
    }
}

///=============================================================================
void ffw::GLFWRenderWindow::poolEvents(){
    glfwPollEvents();
}

///=============================================================================
void ffw::GLFWRenderWindow::waitForEvents(){
    glfwWaitEvents();
}

///=============================================================================
bool ffw::GLFWRenderWindow::isInitialized() const {
    return pimpl->initialized;
}

///=============================================================================
bool ffw::GLFWRenderWindow::shouldRender() const {
    return !pimpl->closed;
}

///=============================================================================
void ffw::GLFWRenderWindow::show(){
    glfwShowWindow(pimpl->windowHandle);
}

///=============================================================================
void ffw::GLFWRenderWindow::hide(){
    glfwHideWindow(pimpl->windowHandle);
}

///=============================================================================
void ffw::GLFWRenderWindow::iconify(){
    glfwIconifyWindow(pimpl->windowHandle);
}

///=============================================================================
void ffw::GLFWRenderWindow::restore(){
    glfwRestoreWindow(pimpl->windowHandle);
}

///=============================================================================
void ffw::GLFWRenderWindow::maximize(){
#ifdef FFW_WINDOWS
    glfwMaximizeWindow(pimpl->windowHandle);
#endif
}

///=============================================================================
void* ffw::GLFWRenderWindow::getGlextFunc(const std::string& name) const {
    if(!pimpl->initialized)return nullptr;
    return reinterpret_cast<void*>(glfwGetProcAddress(name.c_str()));
}

///=============================================================================
bool ffw::GLFWRenderWindow::isGlextExtSupported(const std::string& name) const {
    if(!pimpl->initialized)return false;
    return (glfwExtensionSupported(name.c_str()) == GLFW_TRUE);
}

///=============================================================================
void ffw::GLFWRenderWindow::setSwapInterval(const int interval) const {
    if(!pimpl->initialized)return;
    glfwSwapInterval(interval);
}

///=============================================================================
void ffw::GLFWRenderWindow::setSingleBufferMode(const bool enabled) {
    pimpl->singleBuffer = enabled;
}

///=============================================================================
void ffw::GLFWRenderWindow::textInputEvent(unsigned int c){(void)c;}
void ffw::GLFWRenderWindow::keyPressedEvent(ffw::Key key, ffw::Mode mode){(void)key; (void)mode;}
void ffw::GLFWRenderWindow::mouseMovedEvent(int mousex, int mousey){(void)mousex; (void)mousey;}
void ffw::GLFWRenderWindow::mouseScrollEvent(int scroll){(void)scroll;}
void ffw::GLFWRenderWindow::mouseButtonEvent(ffw::MouseButton button, ffw::Mode mode){(void)button; (void)mode;}
void ffw::GLFWRenderWindow::windowResizedEvent(int width, int height){(void)width; (void)height;}
void ffw::GLFWRenderWindow::windowMovedEvent(int posx, int posy){(void)posx; (void)posy;}
void ffw::GLFWRenderWindow::windowCloseEvent(){}
void ffw::GLFWRenderWindow::windowFocusEvent(bool focus){(void)focus;}
void ffw::GLFWRenderWindow::filesDroppedEvent(std::vector<std::string> filelist){(void)filelist;}
