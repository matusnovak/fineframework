/*** This file is part of FineFramework project ***/

#include "ffw/gui/guisymbol.h"

ffw::GuiSymbol ffw::GuiSymbol::ArrowTop({
	{0.5f, 0.0f}, {0.5f, 0.0f}, {1.0f, 1.0f}, {0.0f, 1.0f}
});
ffw::GuiSymbol ffw::GuiSymbol::ArrowBottom({
	{0.0f, 0.0f}, {1.0f, 0.0f}, {0.5f, 1.0f}, {0.5f, 1.0f}
});
ffw::GuiSymbol ffw::GuiSymbol::ArrowLeft({
	{0.0f, 0.5f}, {0.0f, 0.5f}, {1.0f, 0.0f}, {1.0f, 1.0f}
});
ffw::GuiSymbol ffw::GuiSymbol::ArrowRight({
	{0.0f, 0.0f}, {1.0f, 0.5f}, {1.0f, 0.5f}, {0.0f, 1.0f}
});

///=============================================================================
ffw::GuiSymbol::GuiSymbol(){
	vertices = NULL;
}

///=============================================================================
ffw::GuiSymbol::GuiSymbol(const std::initializer_list<ffw::Vec2f>& verts){
	total = verts.size();
	vertices = std::shared_ptr<ffw::Vec2f>(new ffw::Vec2f[total]);

	size_t c = 0;
	for(const auto& vert : verts){
		vertices.get()[c] = vert;
		c++;
	}
}

///=============================================================================
ffw::GuiSymbol::~GuiSymbol(){
}

///=============================================================================
size_t ffw::GuiSymbol::Size() const {
	return total;
}

///=============================================================================
const ffw::Vec2f* ffw::GuiSymbol::Get() const {
	return vertices.get();
}