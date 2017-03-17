/* This file is part of FineFramework project */
#ifndef FFW_GUI_TEXT_WRAPPER
#define FFW_GUI_TEXT_WRAPPER
#include "guifont.h"

namespace ffw {
	/**
	* @ingroup gui
	*/
	class FFW_API GuiTextWrapper {
	public:
		struct Section {
		public:
			size_t pos;
			ffw::Color color;
			const ffw::GuiFont* font;
		};

		class FFW_API Paragraph {
		public:
			Paragraph();
			virtual ~Paragraph();
			inline const std::wstring& getText() const {
				return text;
			}
			inline const std::vector<Section>& getSections() const {
				return sections;
			}
			inline const std::vector<std::pair<size_t, int>>& getTokens() const {
				return tokens;
			}
			inline int getTotalHeight() const {
				return totalHeight;
			}
			void append(const std::wstring& str);
			void section(const ffw::Color& color, const ffw::GuiFont* font);
			void recalculate(int width);
		protected:
			std::wstring text;
			std::vector<Section> sections;
			std::vector<std::pair<size_t, int>> tokens;
			int totalHeight;
		};

		class FFW_API Stepper {
		public:
			Stepper(const Paragraph& paragraph);
			virtual ~Stepper();
			bool hasNext() const;
			bool getNext();
			inline const wchar_t* getPtr() const {
				return ptr;
			}
			inline size_t getLength() const {
				return length;
			}
			inline int getHeight() const {
				return height;
			}
			inline const ffw::GuiFont* getFont() const {
				return font;
			}
			inline const ffw::Color& getColor() const {
				return color;
			}
			inline bool isNewline() const {
				return newline;
			}
		private:
			const std::wstring& text;
			const std::vector<Section>& sections;
			const std::vector<std::pair<size_t, int>>& tokens;
			size_t current;
			size_t nextToken;
			size_t nextSection;
			const wchar_t* ptr;
			size_t length;
			int height;
			const ffw::GuiFont* font;
			ffw::Color color;
			size_t last;
			bool newline;
		};
		
		GuiTextWrapper();
		virtual ~GuiTextWrapper();
		void setValue(const std::wstring& str, const ffw::Color& color, const ffw::GuiFont* font);
		const std::wstring getValue() const;
		inline void addParagraph() {
			paragraphs.push_back(Paragraph());
		}
		void recalculate(int width);
		inline void append(const std::wstring& str) {
			if (paragraphs.size() != 0)paragraphs.back().append(str);
		}
		void section(const ffw::Color& color, const ffw::GuiFont* font) {
			if (paragraphs.size() != 0)paragraphs.back().section(color, font);
		}
		inline const std::vector<Paragraph>& getParagraphs() const {
			return paragraphs;
		}
		inline std::vector<Paragraph>& getParagraphs() {
			return paragraphs;
		}
	protected:
		std::vector<Paragraph> paragraphs;
	};
}
#endif
