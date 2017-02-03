/* This file is part of FineFramework project */
#ifndef FFW_LOAD_SAVE_CSV
#define FFW_LOAD_SAVE_CSV
#include "../config.h"
#include "../math.h"

#include <fstream>

namespace ffw{
	/**
	* @ingroup data
	*/
	class FFW_API CsvLoader{
	public:
		CsvLoader();
		~CsvLoader();

		bool OpenFromData(const std::string& input, char delim = ',', char quote = '\"');
		bool OpenFromFile(const std::string& path, char delim = ',', char quote = '\"');
		bool IsOpen() const;
		void Close();

		std::string GetRowRaw();
		ffw::Array GetRow(bool convert = true);

		bool Eof() const;

		static ffw::Array Tokenize(const std::string& str, size_t begin, size_t end, bool convert = true, char delim = ',', char quote = '\"');

	private:
		const std::string* stream;
		size_t pos;
		std::ifstream file;
		char del;
		char quot;
	};
	/**
	* @ingroup data
	*/
	bool FFW_API LoadCsv(const std::string& path, ffw::Array& output);
	/**
	* @ingroup data
	*/
	ffw::Array FFW_API DecodeCsv(const std::string& input);
};
#endif