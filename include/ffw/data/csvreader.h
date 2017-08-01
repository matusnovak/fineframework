/* This file is part of FineFramework project */
#ifndef FFW_LOAD_SAVE_CSV
#define FFW_LOAD_SAVE_CSV
#include "../config.h"
#include "../math/var.h"
#include <fstream>

namespace ffw{
	/**
	* @ingroup data
	* @ref doc/markdown/tutorial-csv.md
	*/
	class FFW_API CsvLoader{
	public:
		CsvLoader();
		~CsvLoader();
		/**
		* @brief Opens CSV from data (string)
		* @return Returns true on success
		*/
		bool openFromData(const std::string& input, char delim = ',', char quote = '\"');
		/**
		* @brief Opens CSV from file
		*/
		bool openFromFile(const std::string& path, char delim = ',', char quote = '\"');
		bool isOpen() const;
		void close();

		std::string getRowRaw();
		ffw::Array getRow(bool convert = true);

		bool eof() const;

		static ffw::Array tokenize(const std::string& str, size_t begin, size_t end, bool convert = true, char delim = ',', char quote = '\"');

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
	ffw::Array FFW_API decodeCsvFile(const std::string& path);
	/**
	* @ingroup data
	*/
	ffw::Array FFW_API decodeCsv(const std::string& input);
};
#endif