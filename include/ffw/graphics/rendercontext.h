/* This file is part of FineFramework project */
#ifndef FFW_RENDER_CONTEXT
#define FFW_RENDER_CONTEXT
namespace ffw {
    class RenderContext;
};
#include "../config.h"
#include "../constants.h"
#include "../math.h"
#include "extensions.h"
#include <string>

namespace ffw {
	/**
	 * @ingroup graphics
	 */
    class FFW_API RenderContext {
    public:
        virtual void* GetGlextFunc(const std::string& FunctionName) const = 0;
        virtual bool IsGlextFuncPresent(const std::string& FunctionName) const = 0;
        virtual void SetSwapInterval(int Interval) = 0;
        virtual const GlextStruct* Glext() const = 0;
    };
}
#endif
