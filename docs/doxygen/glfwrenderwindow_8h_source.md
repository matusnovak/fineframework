---
search: false
---

# glfwrenderwindow.h File Reference

**[Go to the documentation of this file.](glfwrenderwindow_8h.md)**
Source: `include/ffw/graphics/glfwrenderwindow.h`

    
    
    
    
    
    
    
    
    
    
    
    
    
```cpp
/* This file is part of FineFramework project */
#ifndef FFW_GLFW_RENDER_WINDOW
#define FFW_GLFW_RENDER_WINDOW
#include "../math/vec2.h"
#include "renderwindow.h"
#include "monitors.h"

namespace ffw {
    struct FFW_API GLFWRenderWindowArgs{
        ffw::Vec2i pos = ffw::Vec2i(-1, -1);
        ffw::Vec2i size = ffw::Vec2i(400, 400);
        std::string title;
        const ImageBuffer* icon = NULL;
        bool resizable = true;
        bool border = true;
        bool maximize = true;
        bool floating = false;
        bool focused = true;
        bool visible = true;
        int samples = 0;
        bool initDrawing = true;
    };    
    class FFW_API GLFWRenderWindow: public RenderWindow, public RenderContext {
    public:
        static std::vector<Monitor> getMonitors();
        static Monitor getPrimaryMonitor();
        static std::vector<Monitor::Mode> getMonitorModes(Monitor monitor);

        GLFWRenderWindow();
        virtual ~GLFWRenderWindow();
        void setPos(int posx, int posy) override;
        void setSize(int width, int height) override;
        ffw::Vec2i getPos() const override;
        ffw::Vec2i getSize() const override;
        bool create(const GLFWRenderWindowArgs& args, GLFWRenderWindow* other, Monitor* monitor = NULL);
        void setWindowedMode();
        void setWindowedMode(int posx, int posy, int width, int height);
        void setFullscreen(const Monitor* monitor);
        void destroy() override;
        bool shouldRender() const override;
        void renderFrame() override;
        void poolEvents() override;
        void waitForEvents() override;
        bool isInitialized() const override;
        void* getGlextFunc(const std::string& name) const override;
        bool isGlextExtSupported(const std::string& name) const override;
        void setSwapInterval(int interval);
        void shouldClose(bool close) override;
        void show() override;
        void hide() override;
        void iconify() override;
        void restore() override;
        void maximize() override;
        void setSingleBufferMode(bool enabled) override;
        // Disable copy operator and copy constructor
        GLFWRenderWindow& operator = (const GLFWRenderWindow&) = delete;
        GLFWRenderWindow(const GLFWRenderWindow&) = delete;
        GLFWRenderWindow(GLFWRenderWindow&& other);
        GLFWRenderWindow& operator = (GLFWRenderWindow&& other);
        struct windowCallback;
        friend struct windowCallback;
    protected:
        virtual bool setup() = 0;
        virtual void render() = 0;
        virtual void close() = 0;
        virtual void textInputEvent(unsigned int c);
        virtual void keyPressedEvent(ffw::Key key, ffw::Mode mode);
        virtual void mouseMovedEvent(int mousex, int mousey);
        virtual void mouseScrollEvent(int scroll);
        virtual void mouseButtonEvent(ffw::MouseButton button, ffw::Mode mode);
        virtual void windowResizedEvent(int width, int height);
        virtual void windowMovedEvent(int posx, int posy);
        virtual void windowCloseEvent();
        virtual void windowFocusEvent(bool focus);
        virtual void filesDroppedEvent(std::vector<std::string> filelist);
    private:
        bool setupContext();
        void destroyWindowData();
        class impl;
        impl* pimpl;
    };
};

#endif
```


    
  
