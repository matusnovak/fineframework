/* This file is part of FineFramework project */
#ifndef FFW_MEDIA_PBM_LOADER
#define FFW_MEDIA_PBM_LOADER
#include "imageloader.h"
#include <fstream>

namespace ffw {
	/**
	 * @ingroup media
	 */
	class FFW_API PbmLoader: public ImageReader {
	public:
		PbmLoader();
		PbmLoader(const PbmLoader& other) = delete;
		PbmLoader(PbmLoader&& other);
		void swap(PbmLoader& other);
		PbmLoader& operator = (const PbmLoader& other) = delete;
		PbmLoader& operator = (PbmLoader&& other);
		virtual ~PbmLoader();

		bool Open(const std::string& path) override;
		size_t ReadRow(void* dest) override;
		virtual void Close();

	private:
		ffw::SwapWrapper<std::fstream> input;
	};
}

inline void swap(ffw::PbmLoader& first, ffw::PbmLoader& second){
	first.swap(second);
}

#endif