/* This file is part of FineFramework project */
#ifndef FFW_MEDIA_JPG_SAVER
#define FFW_MEDIA_JPG_SAVER
#include "imagesaver.h"

namespace ffw {
	/**
	 * @ingroup media
	 */
	class FFW_API JpgSaver: public ImageWriter {
	public:
		JpgSaver();
		JpgSaver(const JpgSaver& other) = delete;
		JpgSaver(JpgSaver&& other);
		void swap(JpgSaver& other);
		JpgSaver& operator = (const JpgSaver& other) = delete;
		JpgSaver& operator = (JpgSaver&& other);
		virtual ~JpgSaver();

		bool Open(const std::string& path, int width, int height, ffw::ImageType type, int quality = 100) override;
		size_t WriteRow(const void* src) override;
		bool WriteFooter() override;
		virtual void Close();

	private:
		struct jpg_struct_s;
		jpg_struct_s* jpg_struct;
		bool cInfoInit;
		bool compressInit;
		FILE* output;
	};
}

#endif