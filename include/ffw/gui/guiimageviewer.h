/* This file is part of FineFramework project */
#ifndef FFW_GUI_IMAGE_VIEWER
#define FFW_GUI_IMAGE_VIEWER
#include "guiwidget.h"
namespace ffw {
	/**
	* @ingroup gui
	*/
	class FFW_API GuiImageViewer : public GuiWidget {
	public:
		GuiImageViewer(GuiWindow* context, const GuiImage* image);
		virtual ~GuiImageViewer();
		void setImage(const GuiImage* image);
		void setSubsection(int posx, int posy, int width, int height);
		void setMirror(bool mirrorX, bool mirrorY);
		inline const GuiImage* getImage() const {
			return img;
		}
		inline const ffw::Vec4i getSubsection() const {
			return sub;
		}
		inline const ffw::Vec2<bool> getMirror() const {
			return mirror;
		}
		void setLabel(const std::wstring& label);
		const std::wstring& getLabel() const;
		ffw::Vec2f getMinimumWrapSize() override;
	private:
		void eventRender(const ffw::Vec2f& contentoffset, const ffw::Vec2f& contentsize) override;
		void eventPos(const ffw::Vec2f& pos) override;
		void eventSize(const ffw::Vec2f& size) override;
		void eventHover(bool gained) override;
		void eventFocus(bool gained) override;
		void eventMouse(const ffw::Vec2f& pos) override;
		bool eventScroll(const ffw::Vec2f& scroll) override;
		void eventMouseButton(ffw::MouseButton button, ffw::Mode mode) override;
		void eventText(wchar_t chr) override;
		void eventKey(ffw::Key key, ffw::Mode mode) override;
		void eventDisabled(bool disabled) override;
		virtual void eventThemeChanged(const GuiTheme* theme) override;
		const GuiImage* img;
		ffw::Vec4i sub;
		ffw::Vec2<bool> mirror;
		std::wstring label;
	};
}
#endif
