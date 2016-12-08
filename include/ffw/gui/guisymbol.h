/* This file is part of FineFramework project */
#ifndef FFW_GUI_SYMBOL
#define FFW_GUI_SYMBOL
#include "../config.h"
#include "../math.h"
#include <memory>
namespace ffw {
	/**
	 * @ingroup gui
	 */
	class GuiSymbol{
	public:
		GuiSymbol();
		GuiSymbol(const std::initializer_list<ffw::Vec2f>& verts);
		virtual ~GuiSymbol();
		const ffw::Vec2f* Get() const;
		size_t Size() const;

		static GuiSymbol ArrowTop;
		static GuiSymbol ArrowBottom;
		static GuiSymbol ArrowLeft;
		static GuiSymbol ArrowRight;
	protected:
		std::shared_ptr<ffw::Vec2f> vertices;
		size_t total;
	};
}
#endif
