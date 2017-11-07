/* This file is part of FineFramework project */
#ifndef FFW_GUI_LIST
#define FFW_GUI_LIST
#include "guiscrollable.h"
namespace ffw {
	/**
	* @ingroup gui
	*/
	class FFW_API GuiList : public GuiScrollableLayout {
	public:
		class Item;
		class FFW_API Value {
		public:
			Value(GuiList* list);
			~Value();
			void setValue(int value);
			int getValue() const;
			void assign(GuiList::Item* item);
			void remove(GuiList::Item* item);
			void clearAllExcept(const GuiList::Item* item);
			void reset();
			size_t getNumOfassigned() const;
		private:
			std::vector<GuiList::Item*> items;
			int value;
			GuiList* parent;
		};
		class FFW_API Item : public GuiWidget {
		public:
			Item(GuiWindow* context, const std::string& label, int base, GuiList::Value* group);
			Item(GuiWindow* context, const std::wstring& label, int base, GuiList::Value* group);
			virtual ~Item();
			void setLabel(const std::wstring& label);
			const std::wstring& getLabel() const;
			inline int getBaseValue() const {
				return base;
			}
			bool isSelected() const;
			void assignValue(bool value);
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
			std::wstring label;
			int base;
			GuiList::Value* group;
		};

		GuiList(GuiWindow* context);
		virtual ~GuiList();
		GuiList::Item* addItem(const std::string& label);
		GuiList::Item* addItem(const std::wstring& label);
		void deleteAllItems();
		bool deleteItem(const GuiList::Item* item);
		void setSelected(int index);
		void resetSelected();
		void setSelected(const GuiList::Item* item);
		GuiList::Item* getSelectedItem() const;
		void eventThemeChanged(const GuiTheme* theme) override;
	private:
		GuiList::Value group;
		int counter;
	};
}
#endif
