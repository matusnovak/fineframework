/* This file is part of FineFramework project */
#include "ffw/config.h"
#include "ffw/math/imagebuffer.h"

///=============================================================================
ffw::FileInfo ffw::GetFileInfo(const std::string& path) {
	if (path.size() == 0)return FileInfo();

	std::string basename;
	std::string dirname;
	std::string extension;

	size_t slash = std::min(path.find_last_of('\\'), path.find_last_of('/'));
	if (slash == std::string::npos) {
		// Check if drive
		if (path.size() == 2 && path[1] == ':') {
			dirname = path;
		}
		else {
			// Split name only
			size_t dot = path.find_last_of('.');

			if (dot == std::string::npos) {
				basename = path;

			}
			else {
				basename = path.substr(0, dot);
				extension = path.substr(dot + 1, path.size() - dot - 1);
			}
		}
	}
	else {
		// Split dir and name
		dirname = path.substr(0, slash + 1);
		size_t dot = path.find_last_of('.');

		if (dot != std::string::npos && dot > slash) {
			if (dot == slash + 1) {
				basename = path.substr(slash + 1, path.size() - slash - 1);
			}
			else {
				basename = path.substr(slash + 1, path.size() - slash - 1 - (path.size() - dot - 1) - 1);
				extension = path.substr(dot + 1, path.size() - dot - 1);
			}
		}
		else {
			basename = path.substr(slash + 1, path.size() - slash - 1);
		}
	}

	return FileInfo(basename, dirname, extension);
}

///=============================================================================
size_t ffw::WstrToUtf8(std::string* Str, const std::wstring& Wstr) {
	size_t total = 0;
	for (size_t i = 0; i < Wstr.size(); i++) {
		const auto& w = Wstr[i];
		// Only byte sequence
		if (w <= 0x007F) {
			if (Str != NULL && Str->size() > total) {
				(*Str)[total + 0] = char(w & 0x007F);
			}
			total += 1;
		}
		// Two byte sequence
		else if (w <= 0x7FF) {
			if (Str != NULL && Str->size() > total + 1) {
				(*Str)[total + 0] = 0xC0 | char((w & 0x0FC0) >> 6);
				(*Str)[total + 1] = 0x80 | char((w & 0x003F));
			}
			total += 2;
		}
		// Three byte sequence
		else if (w <= 0xFFFF) {
			if (Str != NULL && Str->size() > total + 2) {
				(*Str)[total + 0] = 0xE0 | char((w & 0xF000) >> 12);
				(*Str)[total + 1] = 0x80 | char((w & 0x0FC0) >> 6);
				(*Str)[total + 2] = 0x80 | char((w & 0x003F));
			}
			total += 3;
		}
		// Four byte sequence
		else if (w <= 0x1FFFFF) {
			if (Str != NULL && Str->size() > total + 3) {
				(*Str)[total + 0] = 0xF0 | char((w & 0x1C0000) >> 18);
				(*Str)[total + 1] = 0x80 | char((w & 0x03F000) >> 12);
				(*Str)[total + 2] = 0x80 | char((w & 0x000FC0) >> 6);
				(*Str)[total + 3] = 0x80 | char((w & 0x00003F));
			}
			total += 4;
		}
		// Five byte sequence
		else if (w <= 0x3FFFFFF) {
			if (Str != NULL && Str->size() > total + 3) {
				(*Str)[total + 0] = 0xF8 | char((w & 0x3000000) >> 24);
				(*Str)[total + 1] = 0x80 | char((w & 0x0FC0000) >> 18);
				(*Str)[total + 2] = 0x80 | char((w & 0x003F000) >> 12);
				(*Str)[total + 3] = 0x80 | char((w & 0x0000FC0) >> 6);
				(*Str)[total + 4] = 0x80 | char((w & 0x000003F));
			}
			total += 5;
		}
		// Six byte sequence
		else if (w <= 0x7FFFFFFF) {
			if (Str != NULL && Str->size() > total + 3) {
				(*Str)[total + 0] = 0xFC | char((w & 0x40000000) >> 30);
				(*Str)[total + 1] = 0x80 | char((w & 0x3F000000) >> 24);
				(*Str)[total + 2] = 0x80 | char((w & 0x00FC0000) >> 18);
				(*Str)[total + 3] = 0x80 | char((w & 0x0003F000) >> 12);
				(*Str)[total + 4] = 0x80 | char((w & 0x00000FC0) >> 6);
				(*Str)[total + 5] = 0x80 | char((w & 0x0000003F));
			}
			total += 6;
		}
	}
	return total;
}

///=============================================================================
size_t ffw::Utf8ToWstr(std::wstring* Wstr, const std::string& Str) {
	size_t total = 0;
	wchar_t w = 0;
	unsigned char bytes = 0;
	unsigned char sequence = 0;
	for (size_t i = 0; i < Str.size(); i++) {
		const auto& c = Str[i];
		// One byte in the sequence...
		if (!(c & 0x80)) {
			bytes = 0;
			sequence = 0;
			//w = c;
		}
		// Multiple bytes in the sequence...
		else {
			unsigned char b = 0x80;
			bytes = 0;
			while ((c & b) && bytes < 8) {
				bytes++;
				b = b >> 1;
			}
			if (bytes > 1)sequence = bytes;
		}
		// First byte 110x xxxx sequence of two bytes
		if (bytes == 2 && sequence == 2) {
			w = (c & 0x1F) << 6;
			sequence--;
		}
		// First byte 1110 xxxx  sequence of three bytes
		else if (bytes == 3 && sequence == 3) {
			w = (c & 0x0F) << 12;
			sequence--;
		}
		// First byte 1111 0xxx  sequence of four bytes
		else if (bytes == 4 && sequence == 4) {
			w = (c & 0x07) << 18;
			sequence--;
		}
		// First byte 1111 10xx  sequence of five bytes
		else if (bytes == 5 && sequence == 5) {
			w = (c & 0x03) << 24;
			sequence--;
		}
		// First byte 1111 110x  sequence of six bytes
		else if (bytes == 6 && sequence == 6) {
			w = (c & 0x01) << 30;
			sequence--;
		}
		// Continuing byte 10xx xxxx
		else if (bytes == 1 && sequence > 0) {
			w |= (c & 0x3F) << ((sequence - 1) * 6);
			sequence--;
			// We have reached the end of the sequence
			if (sequence == 0) {
				if (Wstr != NULL && Wstr->size() > total) {
					(*Wstr)[total] = w;
				}
				total++;
			}
		}
		// No sequence
		else {
			w = c;
			if (Wstr != NULL && Wstr->size() > total) {
				(*Wstr)[total] = w;
			}
			total++;
			//wstr.push_back(w);
		}
	}
	return total;
}

#if defined(FFW_WINDOWS)
///=============================================================================
std::string ffw::WstrToAnsi(const std::wstring& Str) {
	int size = WideCharToMultiByte(CP_ACP, 0, Str.c_str(), Str.size(), NULL, 0, NULL, NULL);
	std::string out(size, ' ');
	WideCharToMultiByte(CP_ACP, 0, Str.c_str(), Str.size(), &out[0], size, 0, 0);
	return out;
}

///=============================================================================
std::wstring ffw::AnsiToWstr(const std::string& Str) {
	int size = MultiByteToWideChar(CP_ACP, 0, Str.c_str(), Str.size(), NULL, 0);
	std::wstring out(size, L' ');
	MultiByteToWideChar(CP_ACP, 0, Str.c_str(), Str.size(), &out[0], size);
	return out;
}
#endif