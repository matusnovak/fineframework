/*** This file is part of FineFramework project ***/

#include "ffw/graphics/apprenderwindow.h"
#include "ffw/graphics/extensions.h"
#include "ffw/graphics/monitors.h"
#include <GLFW/glfw3.h>
#include <memory>
#include <string.h>

///=============================================================================
ffw::AppWindowIcon::AppWindowIcon(const unsigned char* Pixels, int Width, int Height){
	pixels = NULL;
	width = 0;
	height = 0;
	CreateFromData(Pixels, Width, Height);
}

///=============================================================================
ffw::AppWindowIcon::AppWindowIcon(){
	pixels = NULL;
	width = 0;
	height = 0;
}

///=============================================================================
ffw::AppWindowIcon::AppWindowIcon(AppWindowIcon&& Other):pixels(Other.pixels),width(Other.width),height(Other.height){
	Other.pixels = NULL;
	Other.width = 0;
	Other.height = 0;
}

///=============================================================================
ffw::AppWindowIcon::~AppWindowIcon(){
	Destroy();
}

///=============================================================================
bool ffw::AppWindowIcon::CreateFromData(const unsigned char* Pixels, int Width, int Height){
	pixels = new unsigned char[Width * Height * 4];
	memcpy(pixels, Pixels, Width * Height * 4);
	width = Width;
	height = Height;
	return true;
}

///=============================================================================
bool ffw::AppWindowIcon::IsCreated() const{
	return (pixels != NULL);
}

///=============================================================================
void ffw::AppWindowIcon::Destroy(){
	if(pixels != NULL){
		delete[] pixels;
		pixels = NULL;
		width = 0;
		height = 0;
	}
}

///=============================================================================
void ffw::AppWindowIcon::swap(ffw::AppWindowIcon& Other){
	std::swap(pixels, Other.pixels);
	std::swap(width, Other.width);
	std::swap(height, Other.height);
}

///=============================================================================
ffw::AppWindowIcon& ffw::AppWindowIcon::operator = (AppWindowIcon&& Other){
	if(this != &Other){
		::swap(*this, Other);
	}
	return *this;
}

///=============================================================================
void FFW_API swap(ffw::AppWindowIcon& First, ffw::AppWindowIcon& Second){
	First.swap(Second);
}

///=============================================================================
bool ffw::InitGraphics(){
    if(glfwInit() == GL_TRUE)return true;
	return false;
}

///=============================================================================
void ffw::TerminateGraphics(){
    glfwTerminate();
}

///=============================================================================
struct ffw::AppRenderWindow::windowCallback{
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
void ffw::AppRenderWindow::windowCallback::keyPressedCB(GLFWwindow* windowContext, int key, int scancode, int action, int mods){
    (void)scancode;
    (void)mods;
    ffw::AppRenderWindow* windowPtr = static_cast<ffw::AppRenderWindow*>(glfwGetWindowUserPointer(windowContext));
    windowPtr->KeyPressedEvent(static_cast<ffw::Key>(key), static_cast<ffw::Mode>(action));
}

///=============================================================================
void ffw::AppRenderWindow::windowCallback::textInputCB(GLFWwindow* windowContext, unsigned int key){
    ffw::AppRenderWindow* windowPtr = static_cast<ffw::AppRenderWindow*>(glfwGetWindowUserPointer(windowContext));
    windowPtr->TextInputEvent(key);
}

///=============================================================================
void ffw::AppRenderWindow::windowCallback::mouseMovedCB(GLFWwindow* windowContext, double xpos, double ypos){
	ffw::AppRenderWindow* windowPtr = static_cast<ffw::AppRenderWindow*>(glfwGetWindowUserPointer(windowContext));
    windowPtr->MouseMovedEvent(int(xpos), int(ypos));
}

///=============================================================================
void ffw::AppRenderWindow::windowCallback::mouseButtonPressedCB(GLFWwindow* windowContext, int button, int action, int mods){
    (void)mods;
    ffw::AppRenderWindow* windowPtr = static_cast<ffw::AppRenderWindow*>(glfwGetWindowUserPointer(windowContext));
    windowPtr->MouseButtonEvent(static_cast<ffw::MouseButton>(button), static_cast<ffw::Mode>(action));
}

///=============================================================================
void ffw::AppRenderWindow::windowCallback::mouseScrolledCB(GLFWwindow* windowContext, double xoffset, double yoffset){
    (void)xoffset;
    ffw::AppRenderWindow* windowPtr = static_cast<ffw::AppRenderWindow*>(glfwGetWindowUserPointer(windowContext));
    windowPtr->MouseScrollEvent(int(yoffset));
}

///=============================================================================
void ffw::AppRenderWindow::windowCallback::windowShouldCloseCB(GLFWwindow* windowContext){
    ffw::AppRenderWindow* windowPtr = static_cast<ffw::AppRenderWindow*>(glfwGetWindowUserPointer(windowContext));
    windowPtr->WindowCloseEvent();
}

///=============================================================================
void ffw::AppRenderWindow::windowCallback::windowMovedCB(GLFWwindow* windowContext, int xpos, int ypos){
    ffw::AppRenderWindow* windowPtr = static_cast<ffw::AppRenderWindow*>(glfwGetWindowUserPointer(windowContext));
    windowPtr->WindowMovedEvent(xpos, ypos);
}

///=============================================================================
void ffw::AppRenderWindow::windowCallback::windowResizedCB(GLFWwindow* windowContext, int width, int height){
    ffw::AppRenderWindow* windowPtr = static_cast<ffw::AppRenderWindow*>(glfwGetWindowUserPointer(windowContext));
    windowPtr->WindowResizedEvent(width, height);
}

///=============================================================================
void ffw::AppRenderWindow::windowCallback::windowFocusCB(GLFWwindow* windowContext, int focus){
    ffw::AppRenderWindow* windowPtr = static_cast<ffw::AppRenderWindow*>(glfwGetWindowUserPointer(windowContext));
	windowPtr->WindowFocusEvent(focus == 1 ? true : false);
}

///=============================================================================
void ffw::AppRenderWindow::windowCallback::filesFroppedCB(GLFWwindow* windowContext, int count, const char** files){
    ffw::AppRenderWindow* windowPtr = static_cast<ffw::AppRenderWindow*>(glfwGetWindowUserPointer(windowContext));
    std::vector<std::string> fileList;
    fileList.resize(count);
    for(int i = 0; i < count; i++){
        fileList[i].assign(files[i]);
    }
    windowPtr->FilesDroppedEvent(fileList);
}

///=============================================================================
class ffw::AppRenderWindow::impl{
public:
	ffw::AppRenderWindow* otherWindow;
	GLFWwindow* windowHandle;
	ffw::GlextStruct extensions;
	ffw::Vec4i sizeBeforeFillscreen;
	bool setupDone;
	bool initialized;
	bool closed;
	bool singleBuffer;
};

///=============================================================================
ffw::AppRenderWindow::AppRenderWindow():pimpl(new impl){
    pimpl->initialized = false;
	pimpl->setupDone = false;
	pimpl->otherWindow = NULL;
	pimpl->windowHandle = NULL;
	pimpl->closed = true;
	pimpl->singleBuffer = false;
}

///=============================================================================
ffw::AppRenderWindow::AppRenderWindow(AppRenderWindow&& Other):pimpl(Other.pimpl){
	Other.pimpl = NULL;
}

///=============================================================================
ffw::AppRenderWindow& ffw::AppRenderWindow::operator = (AppRenderWindow&& Other){
	if(&Other != this){
		delete pimpl;
		pimpl = Other.pimpl;
		Other.pimpl = NULL;
	}
	return *this;
}

///=============================================================================
ffw::AppRenderWindow::~AppRenderWindow(){
	if(pimpl != NULL){
		DestroyWindowData();
		delete pimpl;
	}
}

///=============================================================================
void ffw::AppRenderWindow::SetPos(int posx, int posy){
	if(!pimpl->initialized)return;
	glfwSetWindowPos(pimpl->windowHandle, posx, posy);
}

///=============================================================================
void ffw::AppRenderWindow::SetSize(int width, int height){
	if(!pimpl->initialized)return;
	glfwSetWindowSize(pimpl->windowHandle, width, height);
}

///=============================================================================
ffw::Vec2i ffw::AppRenderWindow::GetPos() const {
	ffw::Vec2i pos;
	if(!pimpl->initialized)return pos;
	glfwGetWindowPos(pimpl->windowHandle, &pos.x, &pos.y);
	return pos;
}

///=============================================================================
ffw::Vec2i ffw::AppRenderWindow::GetSize() const {
	ffw::Vec2i size;
	if(!pimpl->initialized)return size;
	glfwGetWindowSize(pimpl->windowHandle, &size.x, &size.y);
	return size;
}

///=============================================================================
bool ffw::AppRenderWindow::Create(const ffw::AppRenderWindowArgs& args, ffw::AppRenderWindow* other){
	if(pimpl->initialized)return false;
	if(args.size.x < 0 || args.size.y < 0)return false;

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

    if(args.monitor != NULL)monitor = static_cast<GLFWmonitor*>(args.monitor->ptr);

    GLFWwindow* newWindowContext = glfwCreateWindow(args.size.x, args.size.y, args.title.c_str(), monitor, parentWindowHandle);

	if(args.pos.x != -1 && args.pos.y != -1)
		glfwSetWindowPos(newWindowContext, args.pos.x, args.pos.y);

    if(newWindowContext == NULL){
        return false;
    }

	if(args.icon.IsCreated()){
		GLFWimage image;
		image.width = args.icon.getWidth();
		image.height = args.icon.getHeight();
		image.pixels = (unsigned char*)args.icon.getPixels();

#ifdef FFW_WINDOWS
		glfwSetWindowIcon(newWindowContext, 1, &image);
#endif
	}

	glfwSetWindowUserPointer    (newWindowContext, this);
    glfwSetKeyCallback          (newWindowContext, ffw::AppRenderWindow::windowCallback::keyPressedCB);
    glfwSetCursorPosCallback    (newWindowContext, ffw::AppRenderWindow::windowCallback::mouseMovedCB);
    glfwSetMouseButtonCallback  (newWindowContext, ffw::AppRenderWindow::windowCallback::mouseButtonPressedCB);
    glfwSetCharCallback         (newWindowContext, ffw::AppRenderWindow::windowCallback::textInputCB);
    glfwSetScrollCallback       (newWindowContext, ffw::AppRenderWindow::windowCallback::mouseScrolledCB);
    glfwSetWindowPosCallback    (newWindowContext, ffw::AppRenderWindow::windowCallback::windowMovedCB);
	glfwSetWindowSizeCallback   (newWindowContext, ffw::AppRenderWindow::windowCallback::windowResizedCB);
    glfwSetWindowCloseCallback  (newWindowContext, ffw::AppRenderWindow::windowCallback::windowShouldCloseCB);
    glfwSetWindowFocusCallback  (newWindowContext, ffw::AppRenderWindow::windowCallback::windowFocusCB);
    glfwSetDropCallback         (newWindowContext, ffw::AppRenderWindow::windowCallback::filesFroppedCB);

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
void ffw::AppRenderWindow::SetWindowedMode(){
#ifdef FFW_WINDOWS
	if(pimpl->initialized){
		const auto& s = pimpl->sizeBeforeFillscreen;
		glfwSetWindowMonitor(pimpl->windowHandle, NULL, s.x, s.y, s.z, s.w, GLFW_DONT_CARE);
	}
#endif
}

///=============================================================================
void ffw::AppRenderWindow::SetWindowedMode(int posx, int posy, int width, int height){
#ifdef FFW_WINDOWS
	if(pimpl->initialized){
		glfwSetWindowMonitor(pimpl->windowHandle, NULL, posx, posy, width, height, GLFW_DONT_CARE);
	}
#endif
}

///=============================================================================
void ffw::AppRenderWindow::SetFullscreen(const Monitor& monitor){
#ifdef FFW_WINDOWS
	if(pimpl->initialized){
		pimpl->sizeBeforeFillscreen.Set(GetPos().x, GetPos().y, GetSize().x, GetSize().y);
		glfwSetWindowMonitor(pimpl->windowHandle, NULL, 0, 0, monitor.resolution.x, monitor.resolution.y, monitor.refreshRate);
	}
#endif
}

///=============================================================================
static void* getProcAddress(const char* str){
	return (void*)glfwGetProcAddress(str);
}

///=============================================================================
bool ffw::AppRenderWindow::SetupContext(){
	glfwMakeContextCurrent(pimpl->windowHandle);

	pimpl->extensions.Init(&getProcAddress);
	return true;
}

///=============================================================================
void ffw::AppRenderWindow::DestroyWindowData(){
	if(pimpl->windowHandle != NULL){
		glfwDestroyWindow(pimpl->windowHandle);
		pimpl->windowHandle = NULL;
	}
}

///=============================================================================
void ffw::AppRenderWindow::ShouldClose(bool close){
	pimpl->closed = close;
}

///=============================================================================
void ffw::AppRenderWindow::Destroy(){
	if(pimpl->initialized){
		Close();
	}
	DestroyWindowData();
	pimpl->initialized = false;
	pimpl->closed = true;
}

///=============================================================================
void ffw::AppRenderWindow::RenderFrame(){
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
void ffw::AppRenderWindow::PoolEvents(){
	glfwPollEvents();
}

///=============================================================================
void ffw::AppRenderWindow::WaitForEvents(){
	glfwWaitEvents();
}

///=============================================================================
bool ffw::AppRenderWindow::IsInitialized() const {
	return pimpl->initialized;
}

///=============================================================================
bool ffw::AppRenderWindow::ShouldRender() const {
	return !pimpl->closed;
}

///=============================================================================
void ffw::AppRenderWindow::Show(){
	glfwShowWindow(pimpl->windowHandle);
}

///=============================================================================
void ffw::AppRenderWindow::Hide(){
	glfwHideWindow(pimpl->windowHandle);
}

///=============================================================================
void ffw::AppRenderWindow::Iconify(){
	glfwIconifyWindow(pimpl->windowHandle);
}

///=============================================================================
void ffw::AppRenderWindow::Restore(){
	glfwRestoreWindow(pimpl->windowHandle);
}

///=============================================================================
void ffw::AppRenderWindow::Maximize(){
#ifdef FFW_WINDOWS
	glfwMaximizeWindow(pimpl->windowHandle);
#endif
}

///=============================================================================
void* ffw::AppRenderWindow::GetGlextFunc(const std::string& FunctionName) const {
	if(!pimpl->initialized)return NULL;
	return (void*)glfwGetProcAddress(FunctionName.c_str());
}

///=============================================================================
bool ffw::AppRenderWindow::IsGlextFuncPresent(const std::string& FunctionName) const {
	if(!pimpl->initialized)return false;
	return (GetGlextFunc(FunctionName) != NULL);
}

///=============================================================================
void ffw::AppRenderWindow::SetSwapInterval(int Interval){
	if(!pimpl->initialized)return;
	glfwSwapInterval(Interval);
}

///=============================================================================
const ffw::GlextStruct* ffw::AppRenderWindow::Glext() const {
	return &pimpl->extensions;
}

///=============================================================================
void ffw::AppRenderWindow::SetSingleBufferMode(bool Enabled){
	pimpl->singleBuffer = Enabled;
}

///=============================================================================
void ffw::AppRenderWindow::TextInputEvent(unsigned int c){(void)c;}
void ffw::AppRenderWindow::KeyPressedEvent(ffw::Key key, ffw::Mode mode){(void)key; (void)mode;}
void ffw::AppRenderWindow::MouseMovedEvent(int mousex, int mousey){(void)mousex; (void)mousey;}
void ffw::AppRenderWindow::MouseScrollEvent(int scroll){(void)scroll;}
void ffw::AppRenderWindow::MouseButtonEvent(ffw::MouseButton button, ffw::Mode mode){(void)button; (void)mode;}
void ffw::AppRenderWindow::WindowResizedEvent(int width, int height){(void)width; (void)height;}
void ffw::AppRenderWindow::WindowMovedEvent(int posx, int posy){(void)posx; (void)posy;}
void ffw::AppRenderWindow::WindowCloseEvent(){}
void ffw::AppRenderWindow::WindowFocusEvent(bool focus){(void)focus;}
void ffw::AppRenderWindow::FilesDroppedEvent(std::vector<std::string> filelist){(void)filelist;}
