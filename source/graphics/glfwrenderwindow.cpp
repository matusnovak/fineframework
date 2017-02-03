/*** This file is part of FineFramework project ***/

#include "ffw/graphics/glfwrenderwindow.h"
#include "ffw/graphics/monitors.h"
#include "ffw/graphics/rendercollectiongl1.h"
#include "ffw/graphics/rendercollectiongl3.h"
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
std::vector<ffw::Monitor> ffw::GLFWRenderWindow::GetMonitors() {
	int count;
	GLFWmonitor** monitorPtrs = glfwGetMonitors(&count);
	std::vector<Monitor> allMonitors;
	for (int i = 0; i < count; i++) {
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
ffw::Monitor ffw::GLFWRenderWindow::GetPrimaryMonitor() {
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
std::vector<ffw::Monitor::Mode> ffw::GLFWRenderWindow::GetMonitorModes(ffw::Monitor monitor) {
	std::vector<Monitor::Mode> allModes;
	int count;
	const GLFWvidmode* modes = glfwGetVideoModes((GLFWmonitor*)monitor.ptr, &count);

	for (int i = 0; i < count; i++) {
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
	static void filesFroppedCB          (GLFWwindow* windowContext, int count, const char** files);
};

///=============================================================================
void ffw::GLFWRenderWindow::windowCallback::keyPressedCB(GLFWwindow* windowContext, int key, int scancode, int action, int mods){
    (void)scancode;
    (void)mods;
    ffw::GLFWRenderWindow* windowPtr = static_cast<ffw::GLFWRenderWindow*>(glfwGetWindowUserPointer(windowContext));
    windowPtr->KeyPressedEvent(static_cast<ffw::Key>(key), static_cast<ffw::Mode>(action));
}

///=============================================================================
void ffw::GLFWRenderWindow::windowCallback::textInputCB(GLFWwindow* windowContext, unsigned int key){
    ffw::GLFWRenderWindow* windowPtr = static_cast<ffw::GLFWRenderWindow*>(glfwGetWindowUserPointer(windowContext));
    windowPtr->TextInputEvent(key);
}

///=============================================================================
void ffw::GLFWRenderWindow::windowCallback::mouseMovedCB(GLFWwindow* windowContext, double xpos, double ypos){
	ffw::GLFWRenderWindow* windowPtr = static_cast<ffw::GLFWRenderWindow*>(glfwGetWindowUserPointer(windowContext));
    windowPtr->MouseMovedEvent(int(xpos), int(ypos));
}

///=============================================================================
void ffw::GLFWRenderWindow::windowCallback::mouseButtonPressedCB(GLFWwindow* windowContext, int button, int action, int mods){
    (void)mods;
    ffw::GLFWRenderWindow* windowPtr = static_cast<ffw::GLFWRenderWindow*>(glfwGetWindowUserPointer(windowContext));
    windowPtr->MouseButtonEvent(static_cast<ffw::MouseButton>(button), static_cast<ffw::Mode>(action));
}

///=============================================================================
void ffw::GLFWRenderWindow::windowCallback::mouseScrolledCB(GLFWwindow* windowContext, double xoffset, double yoffset){
    (void)xoffset;
    ffw::GLFWRenderWindow* windowPtr = static_cast<ffw::GLFWRenderWindow*>(glfwGetWindowUserPointer(windowContext));
    windowPtr->MouseScrollEvent(int(yoffset));
}

///=============================================================================
void ffw::GLFWRenderWindow::windowCallback::windowShouldCloseCB(GLFWwindow* windowContext){
    ffw::GLFWRenderWindow* windowPtr = static_cast<ffw::GLFWRenderWindow*>(glfwGetWindowUserPointer(windowContext));
    windowPtr->WindowCloseEvent();
}

///=============================================================================
void ffw::GLFWRenderWindow::windowCallback::windowMovedCB(GLFWwindow* windowContext, int xpos, int ypos){
    ffw::GLFWRenderWindow* windowPtr = static_cast<ffw::GLFWRenderWindow*>(glfwGetWindowUserPointer(windowContext));
    windowPtr->WindowMovedEvent(xpos, ypos);
}

///=============================================================================
void ffw::GLFWRenderWindow::windowCallback::windowResizedCB(GLFWwindow* windowContext, int width, int height){
    ffw::GLFWRenderWindow* windowPtr = static_cast<ffw::GLFWRenderWindow*>(glfwGetWindowUserPointer(windowContext));
    windowPtr->WindowResizedEvent(width, height);
}

///=============================================================================
void ffw::GLFWRenderWindow::windowCallback::windowFocusCB(GLFWwindow* windowContext, int focus){
    ffw::GLFWRenderWindow* windowPtr = static_cast<ffw::GLFWRenderWindow*>(glfwGetWindowUserPointer(windowContext));
	windowPtr->WindowFocusEvent(focus == 1 ? true : false);
}

///=============================================================================
void ffw::GLFWRenderWindow::windowCallback::filesFroppedCB(GLFWwindow* windowContext, int count, const char** files){
    ffw::GLFWRenderWindow* windowPtr = static_cast<ffw::GLFWRenderWindow*>(glfwGetWindowUserPointer(windowContext));
    std::vector<std::string> fileList;
    fileList.resize(count);
    for(int i = 0; i < count; i++){
        fileList[i].assign(files[i]);
    }
    windowPtr->FilesDroppedEvent(fileList);
}

///=============================================================================
class ffw::GLFWRenderWindow::impl{
public:
	ffw::GLFWRenderWindow* otherWindow;
	GLFWwindow* windowHandle;
	std::shared_ptr<ffw::RenderCollection> renderer;
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
	pimpl->renderer = NULL;
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
		DestroyWindowData();
		delete pimpl;
	}
}

///=============================================================================
void ffw::GLFWRenderWindow::SetPos(int posx, int posy){
	if(!pimpl->initialized)return;
	glfwSetWindowPos(pimpl->windowHandle, posx, posy);
}

///=============================================================================
void ffw::GLFWRenderWindow::SetSize(int width, int height){
	if(!pimpl->initialized)return;
	glfwSetWindowSize(pimpl->windowHandle, width, height);
}

///=============================================================================
ffw::Vec2i ffw::GLFWRenderWindow::GetPos() const {
	ffw::Vec2i pos;
	if(!pimpl->initialized)return pos;
	glfwGetWindowPos(pimpl->windowHandle, &pos.x, &pos.y);
	return pos;
}

///=============================================================================
ffw::Vec2i ffw::GLFWRenderWindow::GetSize() const {
	ffw::Vec2i size;
	if(!pimpl->initialized)return size;
	glfwGetWindowSize(pimpl->windowHandle, &size.x, &size.y);
	return size;
}

///=============================================================================
bool ffw::GLFWRenderWindow::Create(const ffw::GLFWRenderWindowArgs& args, ffw::GLFWRenderWindow* other, ffw::Monitor* targetMonitor){
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

	/*if(args.icon.IsCreated()){
		GLFWimage image;
		image.width = args.icon.getWidth();
		image.height = args.icon.getHeight();
		image.pixels = (unsigned char*)args.icon.getPixels();

#ifdef FFW_WINDOWS
		glfwSetWindowIcon(newWindowContext, 1, &image);
#endif
	}*/

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

	if(!SetupContext()){
		Destroy();
		return false;
	}
	glfwSwapInterval(1);
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	return true;
}

///=============================================================================
void ffw::GLFWRenderWindow::SetWindowedMode(){
#ifdef FFW_WINDOWS
	if(pimpl->initialized){
		const auto& s = pimpl->sizeBeforeFillscreen;
		glfwSetWindowMonitor(pimpl->windowHandle, NULL, s.x, s.y, s.z, s.w, GLFW_DONT_CARE);
	}
#endif
}

///=============================================================================
void ffw::GLFWRenderWindow::SetWindowedMode(int posx, int posy, int width, int height){
#ifdef FFW_WINDOWS
	if(pimpl->initialized){
		glfwSetWindowMonitor(pimpl->windowHandle, NULL, posx, posy, width, height, GLFW_DONT_CARE);
	}
#endif
}

///=============================================================================
void ffw::GLFWRenderWindow::SetFullscreen(const Monitor* monitor){
#ifdef FFW_WINDOWS
	if(pimpl->initialized && monitor != NULL){
		pimpl->sizeBeforeFillscreen.Set(GetPos().x, GetPos().y, GetSize().x, GetSize().y);
		glfwSetWindowMonitor(pimpl->windowHandle, NULL, 0, 0, monitor->resolution.x, monitor->resolution.y, monitor->refreshRate);
	}
#endif
}

///=============================================================================
static void* getProcAddress(const char* str){
	return (void*)glfwGetProcAddress(str);
}

///=============================================================================
bool ffw::GLFWRenderWindow::SetupContext(){
	glfwMakeContextCurrent(pimpl->windowHandle);

	// Try OpenGL 3.x first
	pimpl->renderer.reset(new RenderCollectionGL3());
	pimpl->renderer->Init(&getProcAddress);
	if(pimpl->renderer->Compile()) {
		return true;
	}

	// OpenGL 3.x failed, try OpenGL 1.x
	pimpl->renderer.reset(new RenderCollectionGL1());
	pimpl->renderer->Init(&getProcAddress);
	if (pimpl->renderer->Compile()) {
		return true;
	}

	return false;
}

///=============================================================================
void ffw::GLFWRenderWindow::DestroyWindowData(){
	if(pimpl->windowHandle != NULL){
		glfwDestroyWindow(pimpl->windowHandle);
		pimpl->windowHandle = NULL;
	}
}

///=============================================================================
void ffw::GLFWRenderWindow::ShouldClose(bool close){
	pimpl->closed = close;
}

///=============================================================================
void ffw::GLFWRenderWindow::Destroy(){
	if(pimpl->initialized){
		Close();
	}
	DestroyWindowData();
	pimpl->initialized = false;
	pimpl->closed = true;
}

///=============================================================================
void ffw::GLFWRenderWindow::RenderFrame(){
	if(!pimpl->initialized)return;

	glfwMakeContextCurrent(pimpl->windowHandle);

	if(pimpl->singleBuffer){
		glDrawBuffer(GL_FRONT);
	}

	ffw::Vec2i size;
	glfwGetWindowSize(pimpl->windowHandle, &size.x, &size.y);
	glViewport(0, 0, size.x, size.y);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, size.x, size.y, 0, -1, 1);

	this->Render();

	if(pimpl->singleBuffer){
		glFlush();
		glFinish();
	} else {
		glfwSwapBuffers(pimpl->windowHandle);
	}
}

///=============================================================================
void ffw::GLFWRenderWindow::PoolEvents(){
	glfwPollEvents();
}

///=============================================================================
void ffw::GLFWRenderWindow::WaitForEvents(){
	glfwWaitEvents();
}

///=============================================================================
bool ffw::GLFWRenderWindow::IsInitialized() const {
	return pimpl->initialized;
}

///=============================================================================
bool ffw::GLFWRenderWindow::ShouldRender() const {
	return !pimpl->closed;
}

///=============================================================================
void ffw::GLFWRenderWindow::Show(){
	glfwShowWindow(pimpl->windowHandle);
}

///=============================================================================
void ffw::GLFWRenderWindow::Hide(){
	glfwHideWindow(pimpl->windowHandle);
}

///=============================================================================
void ffw::GLFWRenderWindow::Iconify(){
	glfwIconifyWindow(pimpl->windowHandle);
}

///=============================================================================
void ffw::GLFWRenderWindow::Restore(){
	glfwRestoreWindow(pimpl->windowHandle);
}

///=============================================================================
void ffw::GLFWRenderWindow::Maximize(){
#ifdef FFW_WINDOWS
	glfwMaximizeWindow(pimpl->windowHandle);
#endif
}

///=============================================================================
void* ffw::GLFWRenderWindow::GetGlextFunc(const std::string& FunctionName) const {
	if(!pimpl->initialized)return NULL;
	return (void*)glfwGetProcAddress(FunctionName.c_str());
}

///=============================================================================
bool ffw::GLFWRenderWindow::IsGlextFuncPresent(const std::string& FunctionName) const {
	if(!pimpl->initialized)return false;
	return (GetGlextFunc(FunctionName) != NULL);
}

///=============================================================================
void ffw::GLFWRenderWindow::SetSwapInterval(int Interval){
	if(!pimpl->initialized)return;
	glfwSwapInterval(Interval);
}

///=============================================================================
ffw::RenderCollection* ffw::GLFWRenderWindow::Renderer() {
	return pimpl->renderer.get();
}

///=============================================================================
const ffw::RenderExtensions* ffw::GLFWRenderWindow::Glext() const {
	return pimpl->renderer.get();
}

///=============================================================================
void ffw::GLFWRenderWindow::SetSingleBufferMode(bool Enabled){
	pimpl->singleBuffer = Enabled;
}

///=============================================================================
void ffw::GLFWRenderWindow::TextInputEvent(unsigned int c){(void)c;}
void ffw::GLFWRenderWindow::KeyPressedEvent(ffw::Key key, ffw::Mode mode){(void)key; (void)mode;}
void ffw::GLFWRenderWindow::MouseMovedEvent(int mousex, int mousey){(void)mousex; (void)mousey;}
void ffw::GLFWRenderWindow::MouseScrollEvent(int scroll){(void)scroll;}
void ffw::GLFWRenderWindow::MouseButtonEvent(ffw::MouseButton button, ffw::Mode mode){(void)button; (void)mode;}
void ffw::GLFWRenderWindow::WindowResizedEvent(int width, int height){(void)width; (void)height;}
void ffw::GLFWRenderWindow::WindowMovedEvent(int posx, int posy){(void)posx; (void)posy;}
void ffw::GLFWRenderWindow::WindowCloseEvent(){}
void ffw::GLFWRenderWindow::WindowFocusEvent(bool focus){(void)focus;}
void ffw::GLFWRenderWindow::FilesDroppedEvent(std::vector<std::string> filelist){(void)filelist;}
