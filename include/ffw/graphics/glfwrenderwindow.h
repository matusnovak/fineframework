/* This file is part of FineFramework project */
#ifndef FFW_GLFW_RENDER_WINDOW
#define FFW_GLFW_RENDER_WINDOW
#include "renderwindow.h"
#include "monitors.h"

namespace ffw {
	struct FFW_API GLFWRenderWindowArgs{
		ffw::Vec2i pos = ffw::Vec2i(-1, -1);
		ffw::Vec2i size = ffw::Vec2i(400, 400);
		std::string title;
		ImageBuffer* icon;
		bool resizable = true;
		bool border = true;
		bool maximize = true;
		bool floating = false;
		bool focused = true;
		bool visible = true;
		int samples = 0;
	};	
	/**
	 * @ingroup graphics
	 */
	class FFW_API GLFWRenderWindow: public RenderWindow {
    public:
		static std::vector<Monitor> GetMonitors();
		static Monitor GetPrimaryMonitor();
		static std::vector<Monitor::Mode> GetMonitorModes(Monitor monitor);

        GLFWRenderWindow();
        virtual ~GLFWRenderWindow();
		void SetPos(int posx, int posy) override;
		void SetSize(int width, int height) override;
		ffw::Vec2i GetPos() const override;
		ffw::Vec2i GetSize() const override;
		bool Create(const GLFWRenderWindowArgs& args, GLFWRenderWindow* other, Monitor* monitor = NULL);
		void SetWindowedMode();
		void SetWindowedMode(int posx, int posy, int width, int height);
		void SetFullscreen(const Monitor* monitor);
		void Destroy() override;
		bool ShouldRender() const override;
		void RenderFrame() override;
		void PoolEvents() override;
		void WaitForEvents() override;
		bool IsInitialized() const override;
        void* GetGlextFunc(const std::string& functionname) const override;
        bool IsGlextFuncPresent(const std::string& functionname) const override;
		RenderCollection* Renderer() override;
		const RenderExtensions* Glext() const override;
        void SetSwapInterval(int interval);
		void ShouldClose(bool close) override;
		void Show() override;
		void Hide() override;
		void Iconify() override;
		void Restore() override;
		void Maximize() override;
		void SetSingleBufferMode(bool enabled) override;
		// Disable copy operator and copy constructor
        GLFWRenderWindow& operator = (const GLFWRenderWindow&) = delete;
        GLFWRenderWindow(const GLFWRenderWindow&) = delete;
		GLFWRenderWindow(GLFWRenderWindow&& other);
		GLFWRenderWindow& operator = (GLFWRenderWindow&& other);
		struct windowCallback;
		friend struct windowCallback;
	protected:
		virtual bool Setup() = 0;
		virtual void Render() = 0;
		virtual void Close() = 0;
		virtual void TextInputEvent(unsigned int c);
        virtual void KeyPressedEvent(ffw::Key key, ffw::Mode mode);
        virtual void MouseMovedEvent(int mousex, int mousey);
        virtual void MouseScrollEvent(int scroll);
        virtual void MouseButtonEvent(ffw::MouseButton button, ffw::Mode mode);
        virtual void WindowResizedEvent(int width, int height);
        virtual void WindowMovedEvent(int posx, int posy);
        virtual void WindowCloseEvent();
        virtual void WindowFocusEvent(bool focus);
        virtual void FilesDroppedEvent(std::vector<std::string> filelist);
    private:
		bool SetupContext();
		void DestroyWindowData();
		class impl;
		impl* pimpl;
    };
};

#endif
