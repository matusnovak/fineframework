#include <ffw/math.h>
#define CATCH_CONFIG_MAIN
#include "../catch.hpp"


TEST_CASE("Testing getFileInfo #1", "[FileInfo]") {
	std::string path = "C:/Hello/World.txt";
	auto info = ffw::getFileInfo(path);
	REQUIRE("C:/Hello/" == info.dir);
	REQUIRE("World" == info.base);
	REQUIRE("txt" == info.ext);
}
	
TEST_CASE("Testing getFileInfo #2", "[FileInfo]") {
	std::string path = "C:/Hello/World";
	auto info = ffw::getFileInfo(path);
	REQUIRE("C:/Hello/" == info.dir);
	REQUIRE("World" == info.base);
	REQUIRE("" == info.ext);
}

TEST_CASE("Testing getFileInfo #3", "[FileInfo]") {
	std::string path = "C:/Hello/";
	auto info = ffw::getFileInfo(path);
	REQUIRE("C:/Hello/" == info.dir);
	REQUIRE("" == info.base);
	REQUIRE("" == info.ext);
}

TEST_CASE("Testing getFileInfo #4", "[FileInfo]") {
	std::string path = "C:/Hello/.txt";
	auto info = ffw::getFileInfo(path);
	REQUIRE("C:/Hello/" == info.dir);
	REQUIRE(".txt" == info.base);
	REQUIRE("" == info.ext);
}

TEST_CASE("Testing getFileInfo #5", "[FileInfo]") {
	std::string path = "C:";
	auto info = ffw::getFileInfo(path);
	REQUIRE("C:" == info.dir);
	REQUIRE("" == info.base);
	REQUIRE("" == info.ext);
}

TEST_CASE("Testing getFileInfo #6", "[FileInfo]") {
	std::string path = "/Hello/";
	auto info = ffw::getFileInfo(path);
	REQUIRE("/Hello/" == info.dir);
	REQUIRE("" == info.base);
	REQUIRE("" == info.ext);
}

TEST_CASE("Testing getFileInfo #7", "[FileInfo]") {
	std::string path = "./Hello";
	auto info = ffw::getFileInfo(path);
	REQUIRE("./" == info.dir);
	REQUIRE("Hello" == info.base);
	REQUIRE("" == info.ext);
}

TEST_CASE("Testing getFileInfo #8", "[FileInfo]") {
	std::string path = "../../Hello/";
	auto info = ffw::getFileInfo(path);
	REQUIRE("../../Hello/" == info.dir);
	REQUIRE("" == info.base);
	REQUIRE("" == info.ext);
}

TEST_CASE("Testing getFileInfo #9", "[FileInfo]") {
	std::string path = "image.png";
	auto info  = ffw::getFileInfo(path);
	REQUIRE("" == info.dir);
	REQUIRE("image" == info.base);
	REQUIRE("png" == info.ext);
}

TEST_CASE("Testing getFileInfo #10", "[FileInfo]") {
	std::string path = "C:/Hello/world\\file.txt";
	auto info = ffw::getFileInfo(path);
	REQUIRE("C:/Hello/world\\" == info.dir);
	REQUIRE("file" == info.base);
	REQUIRE("txt" == info.ext);
}