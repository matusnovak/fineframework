/* This file is part of FineFramework project */
#ifndef FFW_RENDERBUFFER
#define FFW_RENDERBUFFER
#include "../config.h"
#include "renderextensionsgl.h"

namespace ffw {
	/**
	 * @ingroup graphics
	 */
	class FFW_API Renderbuffer {
    public:
        Renderbuffer();
		Renderbuffer(const Renderbuffer& other) = delete;
		Renderbuffer(Renderbuffer&& other);
		void swap(Renderbuffer& other);
        virtual ~Renderbuffer();
        inline bool isCreated() const {
			return loaded_;
		}
        void destroy();
        void bind() const;
        void unbind() const;
        unsigned int getHandle() const {
			return buffer_;
		}
        inline int getWidth() const {
			return width_;
		}
        inline int getHeight() const {
			return height_;
		}
        inline unsigned int getInternalFormat() const {
			return internalformat_;
		}
		inline int getSamples() const {
			return samples_;
        }

		Renderbuffer& operator = (const Renderbuffer& other) = delete;
		Renderbuffer& operator = (Renderbuffer&& other);
    protected:
        bool loaded_;
        unsigned int internalformat_;
        unsigned int buffer_;
        int width_;
        int height_;
		int samples_;
        const RenderExtensions* gl_;
    };
};

inline void swap(ffw::Renderbuffer& first, ffw::Renderbuffer& second) {
	first.swap(second);
}
#endif
