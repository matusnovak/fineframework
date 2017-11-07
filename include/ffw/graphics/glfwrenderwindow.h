/* This file is part of FineFramework project */
#ifndef FFW_GLFW_RENDER_WINDOW
#define FFW_GLFW_RENDER_WINDOW
#include "../math/vec2.h"
#include "renderwindow.h"
#include "monitors.h"

namespace ffw {
	struct FFW_API GLFWRenderWindowArgs{
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
		const ImageBuffer* icon = NULL;
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
		static std::vector<Monitor::Mode> getMonitorModes(Monitor monitor);

        GLFWRenderWindow();
        virtual ~GLFWRenderWindow();
		void setPos(int posx, int posy) override;
		void setSize(int width, int height) override;
		ffw::Vec2i getPos() const override;
		ffw::Vec2i getSize() const override;
		/**
		* @brief Creates the window
		* @param args Arguments and hints for the window
		* @param other If another window is provided, their OpenGL context will be shared, otherwise NULL
		* @param monitor If a monitor is provided, the window will be fullscreen
		* @return Will return false if:
		*     - The window \c has already been created \c
		*     - The target size (width or height) defined by args is zero or less
		*     - The GLFW failed due to missing OpenGL or there is no display to output to (running in terminal only)
		*     - The \e OS OpenGL version \e is less than 1.1
		*     - The \a target \a size is not supported by the \b monitor \b (only when fullscreen)
		*/
		bool create(const GLFWRenderWindowArgs& args, GLFWRenderWindow* other, Monitor* monitor = NULL);
		/**
		* @brief Sets the window into windowed mode, if the window was in maximized mode
		*/
		void setWindowedMode();
		/**
		* @brief Sets the window into windowed mode with specific size and position
		*/
		void setWindowedMode(int posx, int posy, int width, int height);
		/**
		* @brief Sets the window into fullscreen mode
		* @details You will need to change the size of the window with setSize() 
		*/
		void setFullscreen(const Monitor* monitor);
		/**
		* @brief Destroys the window and it's context
		*/
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
