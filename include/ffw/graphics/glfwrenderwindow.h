/* This file is part of FineFramework project */
#ifndef FFW_GLFW_RENDER_WINDOW
#define FFW_GLFW_RENDER_WINDOW

#include "../math/vec2.h"
#include "renderwindow.h"
#include "monitors.h"

namespace ffw {
    struct FFW_API GLFWRenderWindowArgs {
        /**
        * @brief Position of the window, set to [-1, -1] for the OS to decide
        */
        ffw::Vec2i pos = ffw::Vec2i(-1, -1);
        /**
        * @brief Size of the window
        */
        ffw::Vec2i size = ffw::Vec2i(400, 400);
        /**
        * @brief UTF-8 encoded title
        */ 
        std::string title;
        /**
        * @brief Pointer to an icon image buffer
        */
        const ImageBuffer* icon = nullptr;
        /**
        * @brief Can the user resize the window?
        */
        bool resizable = true;
        /**
        * @brief Does the window have a border?
        */
        bool border = true;
        /**
        * @brief Can the user maximize the window?
        */
        bool maximize = true;
        /**
        * @brief Should the window be always on top?
        */
        bool floating = false;
        /**
        * @brief Should the window be automatically focused on creation?
        */
        bool focused = true;
        /**
        * @brief Should the window be visible?
        */
        bool visible = true;
        /**
        * @brief Antialiasing samples, has to be in power of two
        */
        int samples = 0;
        /**
        * @brief Should the window initialize drawing API?
        */
        bool initDrawing = true;
    };    
    /**
     * @ingroup graphics
     */
    class FFW_API GLFWRenderWindow: public RenderWindow, public RenderContext {
    public:
        /**
        * @brief Returns a vector of all physical monitors available
        */
        static std::vector<Monitor> getMonitors();
        /**
        * @brief Returns the primary monitor defined by the OS
        */
        static Monitor getPrimaryMonitor();
        /**
        * @brief Returns all possible modes for the given monitor
        */
        static std::vector<Monitor::Mode> getMonitorModes(const Monitor& monitor);
        GLFWRenderWindow();
        GLFWRenderWindow(const GLFWRenderWindow&) = delete;
        GLFWRenderWindow(GLFWRenderWindow&& other) NOEXCEPT;
        virtual ~GLFWRenderWindow();
        /**
         * @brief Sets the position of the window relative to the framebuffer
         * @note This function must only be called from the main thread.
         */
        void setPos(int posx, int posy) override;
        /**
         * @brief Sets the size of the window's framebuffer
         * @note This function must only be called from the main thread.
         */
        void setSize(int width, int height) override;
        /**
         * @brief Returns the position of the window relative to the framebuffer (not relative to
         * the OS specific border around the window)
         */
        ffw::Vec2i getPos() const override;
        /**
         * @brief Returns the size of the window's framebuffer (does not include the OS specific 
         * border)
         */
        ffw::Vec2i getSize() const override;
        /**
        * @brief Creates the window
        * @param args    Arguments and hints for the window
        * @param other   If another window is provided, their OpenGL context will be shared, 
        *                otherwise NULL
        * @param monitor If a monitor is provided, the window will be fullscreen
        * @note This function must only be called from the main thread.
        * @return Will return false if:
        *     - The window \c has already been created \c
        *     - The target size (width or height) defined by args is zero or less
        *     - The GLFW failed due to missing OpenGL or there is no display to output to 
        *       (running in terminal only)
        *     - The \e OS OpenGL version \e is less than 1.1
        *     - The \a target \a size is not supported by the \b monitor \b (only when fullscreen)
        *     - The Microsoft GDI software OpenGL implementation is the only one available.
        *     - Some X11 window managers will not respect the placement of initially hidden windows.
        */
        bool create(const GLFWRenderWindowArgs& args, GLFWRenderWindow* other, Monitor* monitor = nullptr);
        /**
        * @brief Sets the window into windowed mode, if the window was in maximized mode
        * @note This function must only be called from the main thread.
        * @details This function sets the window in windowed mode. This function does not update
        * the height, width, or position. Instead, it uses the last size and position before
        * entering fullscreen mode.
        */
        void setWindowedMode() const;
        /**
        * @brief Sets the window into windowed mode with specific size and position
        * @note This function must only be called from the main thread.
        * @details This function sets the window in windowed mode. This function also updates
        * the widh, height, and position.
        */
        void setWindowedMode(int posx, int posy, int width, int height) const;
        /**
        * @brief Sets the window into fullscreen mode
        * @note This function must only be called from the main thread.
        * @details This function sets the monitor that the window uses for full screen mode. 
        * When setting a monitor, this function updates the width, height and refresh rate of 
        * the desired video mode and switches to the video mode closest to it. 
        * The window position is ignored when setting a monitor.
        */
        void setFullscreen(const Monitor* monitor) const;
        /**
        * @brief Destroys the window and its context
        * @note This function must only be called from the main thread.
        */
        void destroy() override;
        /**
         * @brief Returns true if shouldClose() has been set to true
         */
        bool shouldRender() const override;
        /**
         * @brief Renders the frame by setting up the context and calling protected method render()
         * @details This function makes the OpenGL or OpenGL ES context of the specified window 
         * current on the calling thread. A context can only be made current on a single thread 
         * at a time and each thread can have only a single current context at a time.
         * This function also calls glViewport with the current window's framebuffer size.
         */
        void renderFrame() override;
        /**
         * @brief Processes all user events 
         * @details This function processes only those events that are already in the event queue 
         * and then returns immediately. Processing events will cause the window and input callbacks 
         * associated with those events to be called. On some platforms, a window move, resize will
         * cause event processing to block. This is due to how event processing is designed on those 
         * platforms. You can use the window refresh callback to redraw the contents of your window 
         * when necessary during such operations.
         */
        void poolEvents() override;
        /**
        * @brief Waits for user events and processes them all
        * @note This function must only be called from the main thread.
        * @details This function puts the calling thread to sleep until at least one event is 
        * available in the event queue. Once one or more events are available, it behaves exactly 
        * like poolEvents, i.e. the events in the queue are processed and the function then returns 
        * immediately. Processing events will cause the window and input callbacks associated with 
        * those events to be called. Since not all events are associated with callbacks, 
        * this function may return without a callback having been called even if you are monitoring 
        * all callbacks. On some platforms, a window move, resize or menu operation will cause 
        * event processing to block. This is due to how event processing is designed on those 
        * platforms. You can use the window refresh callback to redraw the contents 
        * of your window when necessary during such operations.
        */
        void waitForEvents() override;
        /**
         * @brief Returns true if the window has been initialized
         * @note This function must only be called from the main thread.
         */
        bool isInitialized() const override;
        /**
         * @brief Returns the address of the specified function for the current context.
         * @details This function returns the address of the specified OpenGL or OpenGL ES 
         * core or extension function, if it is supported by the current context. 
         * A context must be current on the calling thread. Calling this function without
         * a current context will cause a GLFW_NO_CURRENT_CONTEXT error.
         * @code
         * PFNGLACTIVETEXTUREPROC myGlActiveTexture = getGlextFunc("glActiveTexture");
         * if (myGlActiveTexture != nullptr) {
         *     std::cout << "myGlActiveTexture is loaded" << std::endl;
         * }
         * @endcode
         */
        void* getGlextFunc(const std::string& name) const override;
        /**
         * @brief Returns wheter given GL extension is supported.
         */
        bool isGlextExtSupported(const std::string& name) const override;
        /**
         * @brief Sets swap interval (enables or disables V-sync)
         * @note This function must only be called from the main thread.
         */
        void setSwapInterval(int interval) const;
        /**
         * @brief Sets the internal should close flag
         * @details This function sets the swap interval for the current OpenGL or 
         * OpenGL ES context, i.e. the number of screen updates to wait from the time 
         * glfwSwapBuffers was called before swapping the buffers and returning. This is 
         * sometimes called vertical synchronization, vertical retrace synchronization or 
         * just vsync.
         */
        void shouldClose(bool close) override;
        /**
         * @brief Makes the window visible
         * @details This function makes the specified window visible if it was previously hidden. 
         * If the window is already visible or is in full screen mode, this function 
         * does nothing.
         * @note This function must only be called from the main thread.
         */
        void show() override;
        /**
         * @brief Makes the window hidden
         * @details This function hides the specified window if it was previously visible.
         * If the window is already hidden or is in full screen mode, this function 
         * does nothing.
         * @note This function must only be called from the main thread.
         */
        void hide() override;
        /**
         * @brief Iconifies the specified window
         * @details This function iconifies (minimizes) the specified window if it was previously 
         * restored. If the window is already iconified, this function does nothing.If the 
         * specified window is a full screen window, the original monitor resolution is restored 
         * until the window is restored.
         * @note This function must only be called from the main thread.
         */
        void iconify() override;
        /**
         * @brief Restores the specified window
         * @details This function restores the specified window if it was previously iconified 
         * (minimized) or maximized. If the window is already restored, this function does nothing.
         * If the specified window is a full screen window, the resolution chosen for the window 
         * is restored on the selected monitor.
         * @note This function must only be called from the main thread.
         */
        void restore() override;
        /**
         * @brief Maximizes the specified window
         * @details This function maximizes the specified window if it was previously not
         * maximized. If the window is already maximized, this function does nothing. 
         * If the specified window is a full screen window, this function does nothing.
         * @note This function must only be called from the main thread.
         */
        void maximize() override;
        /**
         * @brief Sets single buffer mode
         * @details In single buffer mode, no back and front buffer swapping is done. Instead,
         * glFlush and glFinish is used.
         * @note This function must only be called from the main thread.
         */
        void setSingleBufferMode(bool enabled) override;
        GLFWRenderWindow& operator = (const GLFWRenderWindow&) = delete;
        GLFWRenderWindow& operator = (GLFWRenderWindow&& other) NOEXCEPT;
        struct WindowCallback;
        friend struct WindowCallback;
    protected:
        /**
        * @brief Called only once when the window is set up
        */
        virtual bool setup() = 0;
        /**
        * @brief Called every time the frame is being rendered
        */
        virtual void render() = 0;
        /**
        * @brief Called only once when the window is being destroyed
        */
        virtual void close() = 0;
        /**
        * @brief Called when the user presses a key to type text (unicode only)
        */
        virtual void textInputEvent(unsigned int c);
        /**
        * @brief Called when the user presses a physical key
        */
        virtual void keyPressedEvent(ffw::Key key, ffw::Mode mode);
        /**
        * @brief Called when the user moves a mouse
        */
        virtual void mouseMovedEvent(int mousex, int mousey);
        /**
        * @brief Called when the user scrolls down or up
        */
        virtual void mouseScrollEvent(int scroll);
        /**
        * @brief Called when the user presses a mouse button
        */ 
        virtual void mouseButtonEvent(ffw::MouseButton button, ffw::Mode mode);
        /**
        * @brief Called when the window is resized to a new size
        */
        virtual void windowResizedEvent(int width, int height);
        /**
        * @brief Called when the window is moved to a new position
        */
        virtual void windowMovedEvent(int posx, int posy);
        /**
        * @brief Called when the user presses the [X] button on the window
        */
        virtual void windowCloseEvent();
        /**
        * @brief Called when the window will gain or looses focus
        */
        virtual void windowFocusEvent(bool focus);
        /**
        * @brief Called when the user drags and drops one or multiple files
        * @note UTF-8 enabled
        */
        virtual void filesDroppedEvent(std::vector<std::string> filelist);
    private:
        bool setupContext();
        void destroyWindowData();
        class impl;
        impl* pimpl;
    };
};

#endif
