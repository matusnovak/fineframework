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

		bool Open(const std::string& path, int width, int height, ffw::ImageType type, int quality = 100) override;
		size_t WriteRow(const void* src) override;
		bool WriteFooter() override;
		virtual void Close();

	private:
		std::fstream output;
	};
}

#endif