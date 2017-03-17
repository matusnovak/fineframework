/* This file is part of FineFramework project */
#ifndef FFW_MEDIA_PBM_SAVER
#define FFW_MEDIA_PBM_SAVER
#include "imagesaver.h"
#include <fstream>

namespace ffw {
	/**
	 * @ingroup media
	 */
	class FFW_API PbmSaver: public ImageWriter {
	public:
		PbmSaver();
		PbmSaver(const PbmSaver& other) = delete;
		PbmSaver(PbmSaver&& other);
		void swap(PbmSaver& other);
		PbmSaver& operator = (const PbmSaver& other) = delete;
		PbmSaver& operator = (PbmSaver&& other);
		virtual ~PbmSaver();

		bool open(const std::string& path, int width, int height, ffw::ImageType type, int quality = 100) override;
		size_t writeRow(const void* src) override;
		bool writeFooter() override;
		virtual void close();

	private:
		ffw::SwapWrapper<std::fstream> output;
	};
}

inline void swap(ffw::PbmSaver& first, ffw::PbmSaver& second){
	first.swap(second);
}

#endif