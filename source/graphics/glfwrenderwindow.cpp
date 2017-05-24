/*** This file is part of FineFramework project ***/

#include "ffw/graphics/glfwrenderwindow.h"
#include "ffw/graphics/monitors.h"
#include <GLFW/glfw3.h>
#include <memory>

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
	bool Init() {
		if (counter == 0) {
			auto result = glfwInit();
			if(!result) {
				std::cerr << "Failed to iniailize GLFW graphics!" << std::endl;
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
	if(!graphicsInitializer.Init()) {
		return std::vector<ffw::Monitor>();
	}
	
	int cnt;
	GLFWmonitor** monitorPtrs = glfwGetMonitors(&cnt);
	std::vector<Monitor> allMonitors;
	for (int i = 0; i < cnt; i++) {
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
ffw::Monitor ffw::GLFWRenderWindow::getPrimaryMonitor() {
	if (!graphicsInitializer.Init()) {
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
std::vector<ffw::Monitor::Mode> ffw::GLFWRenderWindow::getMonitorModes(ffw::Monitor monitor) {
	std::vector<Monitor::Mode> allModes;
	int cnt;
	const GLFWvidmode* modes = glfwGetVideoModes((GLFWmonitor*)monitor.ptr, &cnt);

	for (int i = 0; i < cnt; i++) {
		allModes.push_back(Monitor::Mode());
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
static bool InitGraphics(){
	static bool initialized = false;
	if (!initialized) {
		if (glfwInit() != GL_TRUE)return false;
		initialized = true;
		return true;
	} else {
		return true;
	}
}

///=============================================================================
static void TerminateGraphics(){
	static bool terminated = false;
	if(!terminated) {
		terminated = true;
		glfwTerminate();
	}
}

///=============================================================================
struct ffw::GLFWRenderWindow::windowCallback{
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
void ffw::GLFWRenderWindow::windowCallback::keyPressedCB(GLFWwindow* windowContext, int key, int scancode, int action, int mods){
    (void)scancode;
    (void)mods;
    ffw::GLFWRenderWindow* windowPtr = static_cast<ffw::GLFWRenderWindow*>(glfwGetWindowUserPointer(windowContext));
    windowPtr->keyPressedEvent(static_cast<ffw::Key>(key), static_cast<ffw::Mode>(action));
}

///=============================================================================
void ffw::GLFWRenderWindow::windowCallback::textInputCB(GLFWwindow* windowContext, unsigned int key){
    ffw::GLFWRenderWindow* windowPtr = static_cast<ffw::GLFWRenderWindow*>(glfwGetWindowUserPointer(windowContext));
    windowPtr->textInputEvent(key);
}

///=============================================================================
void ffw::GLFWRenderWindow::windowCallback::mouseMovedCB(GLFWwindow* windowContext, double xpos, double ypos){
	ffw::GLFWRenderWindow* windowPtr = static_cast<ffw::GLFWRenderWindow*>(glfwGetWindowUserPointer(windowContext));
    windowPtr->mouseMovedEvent(int(xpos), int(ypos));
}

///=============================================================================
void ffw::GLFWRenderWindow::windowCallback::mouseButtonPressedCB(GLFWwindow* windowContext, int button, int action, int mods){
    (void)mods;
    ffw::GLFWRenderWindow* windowPtr = static_cast<ffw::GLFWRenderWindow*>(glfwGetWindowUserPointer(windowContext));
    windowPtr->mouseButtonEvent(static_cast<ffw::MouseButton>(button), static_cast<ffw::Mode>(action));
}

///=============================================================================
void ffw::GLFWRenderWindow::windowCallback::mouseScrolledCB(GLFWwindow* windowContext, double xoffset, double yoffset){
    (void)xoffset;
    ffw::GLFWRenderWindow* windowPtr = static_cast<ffw::GLFWRenderWindow*>(glfwGetWindowUserPointer(windowContext));
    windowPtr->mouseScrollEvent(int(yoffset));
}

///=============================================================================
void ffw::GLFWRenderWindow::windowCallback::windowShouldCloseCB(GLFWwindow* windowContext){
    ffw::GLFWRenderWindow* windowPtr = static_cast<ffw::GLFWRenderWindow*>(glfwGetWindowUserPointer(windowContext));
    windowPtr->windowCloseEvent();
}

///=============================================================================
void ffw::GLFWRenderWindow::windowCallback::windowMovedCB(GLFWwindow* windowContext, int xpos, int ypos){
    ffw::GLFWRenderWindow* windowPtr = static_cast<ffw::GLFWRenderWindow*>(glfwGetWindowUserPointer(windowContext));
    windowPtr->windowMovedEvent(xpos, ypos);
}

///=============================================================================
void ffw::GLFWRenderWindow::windowCallback::windowResizedCB(GLFWwindow* windowContext, int width, int height){
    ffw::GLFWRenderWindow* windowPtr = static_cast<ffw::GLFWRenderWindow*>(glfwGetWindowUserPointer(windowContext));
    windowPtr->windowResizedEvent(width, height);
}

///=============================================================================
void ffw::GLFWRenderWindow::windowCallback::windowFocusCB(GLFWwindow* windowContext, int focus){
    ffw::GLFWRenderWindow* windowPtr = static_cast<ffw::GLFWRenderWindow*>(glfwGetWindowUserPointer(windowContext));
	windowPtr->windowFocusEvent(focus == 1 ? true : false);
}

///=============================================================================
void ffw::GLFWRenderWindow::windowCallback::filesFroppedCB(GLFWwindow* windowContext, int cnt, const char** files){
    ffw::GLFWRenderWindow* windowPtr = static_cast<ffw::GLFWRenderWindow*>(glfwGetWindowUserPointer(windowContext));
    std::vector<std::string> fileList;
    fileList.resize(cnt);
    for(int i = 0; i < cnt; i++){
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
	pimpl->otherWindow = NULL;
	pimpl->windowHandle = NULL;
	pimpl->closed = true;
	pimpl->singleBuffer = false;
}

///=============================================================================
ffw::GLFWRenderWindow::GLFWRenderWindow(GLFWRenderWindow&& Other):pimpl(Other.pimpl){
	Other.pimpl = NULL;
}

///=============================================================================
ffw::GLFWRenderWindow& ffw::GLFWRenderWindow::operator = (GLFWRenderWindow&& Other){
	if(&Other != this){
		delete pimpl;
		pimpl = Other.pimpl;
		Other.pimpl = NULL;
	}
	return *this;
}

///=============================================================================
ffw::GLFWRenderWindow::~GLFWRenderWindow(){
	if(pimpl != NULL){
		destroyWindowData();
		delete pimpl;
	}
}

///=============================================================================
void ffw::GLFWRenderWindow::setPos(int posx, int posy){
	if(!pimpl->initialized)return;
	glfwSetWindowPos(pimpl->windowHandle, posx, posy);
}

///=============================================================================
void ffw::GLFWRenderWindow::setSize(int width, int height){
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
	glfwGetWindowSize(pimpl->windowHandle, &size.x, &size.y);
	return size;
}

///=============================================================================
bool ffw::GLFWRenderWindow::create(const ffw::GLFWRenderWindowArgs& args, ffw::GLFWRenderWindow* other, ffw::Monitor* targetMonitor){
	if(pimpl->initialized)return false;
	if(args.size.x < 0 || args.size.y < 0)return false;

	if (!graphicsInitializer.Init())return false;

	glfwWindowHint(GLFW_RESIZABLE, args.resizable);
    glfwWindowHint(GLFW_DECORATED, args.border);
    glfwWindowHint(GLFW_AUTO_ICONIFY, args.maximize);
    glfwWindowHint(GLFW_FLOATING, args.floating);
    glfwWindowHint(GLFW_FOCUSED, args.focused);
	glfwWindowHint(GLFW_SAMPLES, args.samples);
    glfwWindowHint(GLFW_VISIBLE, args.visible);
	//glfwWindowHint(GLFW_DOUBLEBUFFER, !Args.singleBuffer);

	GLFWwindow* parentWindowHandle = NULL;
	GLFWmonitor* monitor = NULL;
	pimpl->otherWindow = other;

	if(other != NULL)parentWindowHandle = other->pimpl->windowHandle;

    if(targetMonitor != NULL)monitor = static_cast<GLFWmonitor*>(targetMonitor->ptr);

    GLFWwindow* newWindowContext = glfwCreateWindow(args.size.x, args.size.y, args.title.c_str(), monitor, parentWindowHandle);

	if(args.pos.x != -1 && args.pos.y != -1)
		glfwSetWindowPos(newWindowContext, args.pos.x, args.pos.y);

    if(newWindowContext == NULL){
        return false;
    }

	if (args.icon != NULL && args.icon->isAllocated()) {
		GLFWimage image;
		image.width = args.icon->getWidth();
		image.height = args.icon->getHeight();
		image.pixels = (unsigned char*)args.icon->getPtr();

		glfwSetWindowIcon(newWindowContext, 1, &image);
	}

	glfwSetWindowUserPointer    (newWindowContext, this);
    glfwSetKeyCallback          (newWindowContext, ffw::GLFWRenderWindow::windowCallback::keyPressedCB);
    glfwSetCursorPosCallback    (newWindowContext, ffw::GLFWRenderWindow::windowCallback::mouseMovedCB);
    glfwSetMouseButtonCallback  (newWindowContext, ffw::GLFWRenderWindow::windowCallback::mouseButtonPressedCB);
    glfwSetCharCallback         (newWindowContext, ffw::GLFWRenderWindow::windowCallback::textInputCB);
    glfwSetScrollCallback       (newWindowContext, ffw::GLFWRenderWindow::windowCallback::mouseScrolledCB);
    glfwSetWindowPosCallback    (newWindowContext, ffw::GLFWRenderWindow::windowCallback::windowMovedCB);
	glfwSetWindowSizeCallback   (newWindowContext, ffw::GLFWRenderWindow::windowCallback::windowResizedCB);
    glfwSetWindowCloseCallback  (newWindowContext, ffw::GLFWRenderWindow::windowCallback::windowShouldCloseCB);
    glfwSetWindowFocusCallback  (newWindowContext, ffw::GLFWRenderWindow::windowCallback::windowFocusCB);
    glfwSetDropCallback         (newWindowContext, ffw::GLFWRenderWindow::windowCallback::filesFroppedCB);

	pimpl->initialized = true;
	pimpl->windowHandle = newWindowContext;
	pimpl->closed = false;

	if(!setupContext()){
		destroy();
		return false;
	}
	glfwSwapInterval(1);
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	return true;
}

///=============================================================================
void ffw::GLFWRenderWindow::setWindowedMode(){
	if(pimpl->initialized){
		const auto& s = pimpl->sizeBeforeFillscreen;
		glfwSetWindowMonitor(pimpl->windowHandle, NULL, s.x, s.y, s.z, s.w, GLFW_DONT_CARE);
	}
}

///=============================================================================
void ffw::GLFWRenderWindow::setWindowedMode(int posx, int posy, int width, int height){
	if(pimpl->initialized){
		glfwSetWindowMonitor(pimpl->windowHandle, NULL, posx, posy, width, height, GLFW_DONT_CARE);
	}
}

///=============================================================================
void ffw::GLFWRenderWindow::setFullscreen(const Monitor* monitor){
	if(pimpl->initialized && monitor != NULL){
		pimpl->sizeBeforeFillscreen.set(getPos().x, getPos().y, getSize().x, getSize().y);
		glfwSetWindowMonitor(pimpl->windowHandle, NULL, 0, 0, monitor->resolution.x, monitor->resolution.y, monitor->refreshRate);
	}
}

///=============================================================================
static void* getProcaddress(const char* str){
	return (void*)glfwGetProcAddress(str);
}

///=============================================================================
bool ffw::GLFWRenderWindow::setupContext(){
	glfwMakeContextCurrent(pimpl->windowHandle);
	this->loadExtensions(&getProcaddress);
	return this->compileShaders();
}

///=============================================================================
void ffw::GLFWRenderWindow::destroyWindowData(){
	if(pimpl->windowHandle != NULL){
		glfwDestroyWindow(pimpl->windowHandle);
		pimpl->windowHandle = NULL;
	}
}

///=============================================================================
void ffw::GLFWRenderWindow::shouldClose(bool close){
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
	//glViewport(0, 0, size.x, size.y);

	/*glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, size.x, size.y, 0, -1, 1);*/
	this->setViewport(0, 0, size.x, size.y);

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
	if(!pimpl->initialized)return NULL;
	return (void*)glfwGetProcAddress(name.c_str());
}

///=============================================================================
bool ffw::GLFWRenderWindow::isGlextExtSupported(const std::string& name) const {
	if(!pimpl->initialized)return false;
	return (glfwExtensionSupported(name.c_str()) == GLFW_TRUE);
}

///=============================================================================
void ffw::GLFWRenderWindow::setSwapInterval(int Interval){
	if(!pimpl->initialized)return;
	glfwSwapInterval(Interval);
}

///=============================================================================
void ffw::GLFWRenderWindow::setSingleBufferMode(bool Enabled){
	pimpl->singleBuffer = Enabled;
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
