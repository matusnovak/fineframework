/* This file is part of FineFramework project */
#ifndef FFW_GUI_LIST
#define FFW_GUI_LIST
#include "guiscrollable.h"
namespace ffw {
	/**
	* @ingroup gui
	*/
	class FFW_API GuiList : public GuiScrollable {
	public:
		class Item;
		class FFW_API Value {
		public:
			Value(GuiList* list);
			~Value();
			void SetValue(int value);
			int GetValue() const;
			void Assign(GuiList::Item* item);
			void Remove(GuiList::Item* item);
			void ClearAllExcept(const GuiList::Item* item);
			void Reset();
			size_t GetNumOfAssigned() const;
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
			void SetLabel(const std::wstring& label);
			const std::wstring& GetLabel() const;
			inline int GetBaseValue() const {
				return base;
			}
			bool IsSelected() const;
			void AssignValue(bool value);
			ffw::Vec2i GetMinimumWrapSize() const override;
		private:
			void EventRender(const ffw::Vec2i& contentoffset, const ffw::Vec2i& contentsize) override;
			void EventPos(const ffw::Vec2i& pos) override;
			void EventSize(const ffw::Vec2i& size) override;
			void EventHover(bool gained) override;
			void EventFocus(bool gained) override;
			void EventMouse(const ffw::Vec2i& pos) override;
			void EventMouseButton(ffw::MouseButton button, ffw::Mode mode) override;
			void EventText(wchar_t chr) override;
			void EventKey(ffw::Key key, ffw::Mode mode) override;
			void EventDisabled(bool disabled) override;
			virtual void EventThemeChanged(const GuiTheme* theme) override;
			std::wstring label;
			int base;
			GuiList::Value* group;
		};

		GuiList(GuiWindow* context);
		virtual ~GuiList();
		GuiList::Item* AddItem(const std::string& label);
		GuiList::Item* AddItem(const std::wstring& label);
		void DeleteAllItems();
		bool DeleteItem(const GuiList::Item* item);
		void SetSelected(int index);
		void ResetSelected();
		void SetSelected(const GuiList::Item* item);
		GuiList::Item* GetSelectedItem() const;
		void EventThemeChanged(const GuiTheme* theme) override;
	private:
		GuiList::Value group;
		int counter;
	};
}
#endif
