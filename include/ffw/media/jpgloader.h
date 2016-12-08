/* This file is part of FineFramework project */
#ifndef FFW_MEDIA_JPG_LOADER
#define FFW_MEDIA_JPG_LOADER
#include "imageloader.h"

namespace ffw {
	/**
	 * @ingroup media
	 */
	class FFW_API JpgLoader: public ImageReader {
	public:
		JpgLoader();
		JpgLoader(const JpgLoader& other) = delete;
		JpgLoader(JpgLoader&& other);
		void swap(JpgLoader& other);
		JpgLoader& operator = (const JpgLoader& other) = delete;
		JpgLoader& operator = (JpgLoader&& other);
		virtual ~JpgLoader();

		bool Open(const std::string& path) override;
		size_t ReadRow(void* dest) override;
		virtual void Close();

	private:
		struct jpg_struct_s;
		jpg_struct_s* jpg_struct;
		bool cInfoInit;
		bool decompressInit;
		FILE* input;
	};
}

#endif