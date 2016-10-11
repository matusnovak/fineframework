/* This file is part of FineFramework project */
#ifndef FFW_APP_RENDER_WINDOW
#define FFW_APP_RENDER_WINDOW
#include "rendercontext.h"
#include "monitors.h"

namespace ffw {
	/**
	 * @ingroup graphics
	 */
	class FFW_API AppWindowIcon {
	public:
		AppWindowIcon(const unsigned char* Pixels, int Width, int Height);
		AppWindowIcon();
		AppWindowIcon(const AppWindowIcon& Other) = delete;
		AppWindowIcon(AppWindowIcon&& Other);
		~AppWindowIcon();
		bool CreateFromData(const unsigned char* Pixels, int Width, int Height);
		bool IsCreated() const;
		void Destroy();
		inline int getWidth() const {return width;}
		inline int getHeight() const {return height;}
		inline unsigned char* getPixels() {return pixels;}
		inline const unsigned char* getPixels() const {return pixels;}
		AppWindowIcon& operator = (AppWindowIcon&& Other);
		AppWindowIcon& operator = (const AppWindowIcon& Other) = delete;
		void swap(ffw::AppWindowIcon& Other);
	private:
		int width;
		int height;
		unsigned char* pixels;
	};
	/**
	 * @ingroup graphics
	 */
    bool FFW_API InitGraphics();
	/**
	 * @ingroup graphics
	 */
	void FFW_API TerminateGraphics();
	/**
	 * @ingroup graphics
	 */
	struct FFW_API AppRenderWindowArgs{
		ffw::Vec2i pos = ffw::Vec2i(-1, -1);
		ffw::Vec2i size = ffw::Vec2i(400, 400);
		std::string title;
		AppWindowIcon icon;
		bool resizable = true;
		bool border = true;
		bool maximize = true;
		bool floating = false;
		bool focused = true;
		bool visible = true;
		int samples = 0;
		ffw::Monitor* monitor = NULL;
	};	
	/**
	 * @ingroup graphics
	 */
	class FFW_API AppRenderWindow: public RenderContext {
    public:
        AppRenderWindow();
        virtual ~AppRenderWindow();
		void SetPos(int posx, int posy);
		void SetSize(int width, int height);
		ffw::Vec2i GetPos() const;
		ffw::Vec2i GetSize() const;
		bool Create(const AppRenderWindowArgs& args, AppRenderWindow* other);
		void SetWindowedMode();
		void SetWindowedMode(int posx, int posy, int width, int height);
		void SetFullscreen(const Monitor& Monitor);
		void Destroy();
		bool ShouldRender() const;
		void RenderFrame();
		void PoolEvents();
		void WaitForEvents();
		bool IsInitialized() const;
        void* GetGlextFunc(const std::string& functionname) const override;
        bool IsGlextFuncPresent(const std::string& functionname) const override;
        void SetSwapInterval(int interval) override;
        const GlextStruct* Glext() const override;
		void ShouldClose(bool close);
		void Show();
		void Hide();
		void Iconify();
		void Restore();
		void Maximize();
		void SetSingleBufferMode(bool enabled);
		// Disable copy operator and copy constructor
        AppRenderWindow& operator = (const AppRenderWindow&) = delete;
        AppRenderWindow(const AppRenderWindow&) = delete;
		AppRenderWindow(AppRenderWindow&& other);
		AppRenderWindow& operator = (AppRenderWindow&& other);
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
extern void FFW_API swap(ffw::AppWindowIcon& First, ffw::AppWindowIcon& Second);
#endif
