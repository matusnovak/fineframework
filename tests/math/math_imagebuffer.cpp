#include <ffw/math/imagebuffer.h>
#include "../catch.hpp"

TEST_CASE("Testing coverImage #1", "[Math]") {
    ffw::Vec4i result = ffw::coverImage(1000, 1000, 1000, 500);
    REQUIRE(result.x == 0);
    REQUIRE(result.y == -250);
    REQUIRE(result.z == 1000);
    REQUIRE(result.w == 1000);
}

TEST_CASE("Testing coverImage #2", "[Math]") {
    ffw::Vec4i result = ffw::coverImage(1000, 1000, 500, 250);
    REQUIRE(result.x == 0);
    REQUIRE(result.y == -125);
    REQUIRE(result.z == 500);
    REQUIRE(result.w == 500);
}

TEST_CASE("Testing coverImage #3", "[Math]") {
    ffw::Vec4i result = ffw::coverImage(1000, 500, 1920, 1080);
    REQUIRE(result.x == -120);
    REQUIRE(result.y == 0);
    REQUIRE(result.z == 2160);
    REQUIRE(result.w == 1080);
}

TEST_CASE("Testing coverImage #4", "[Math]") {
    ffw::Vec4i result = ffw::coverImage(500, 1000, 1920, 1080);
    REQUIRE(result.x == 0);
    REQUIRE(result.y == -1380);
    REQUIRE(result.z == 1920);
    REQUIRE(result.w == 3840);
}

TEST_CASE("Testing containImage #1", "[Math]") {
    ffw::Vec4i result = ffw::containImage(1000, 1000, 1000, 500);
    REQUIRE(result.x == 250);
    REQUIRE(result.y == 0);
    REQUIRE(result.z == 500);
    REQUIRE(result.w == 500);
}

TEST_CASE("Testing containImage #2", "[Math]") {
    ffw::Vec4i result = ffw::containImage(1000, 1000, 500, 250);
    REQUIRE(result.x == 125);
    REQUIRE(result.y == 0);
    REQUIRE(result.z == 250);
    REQUIRE(result.w == 250);
}

TEST_CASE("Testing containImage #3", "[Math]") {
    ffw::Vec4i result = ffw::containImage(1000, 500, 1920, 1080);
    REQUIRE(result.x == 0);
    REQUIRE(result.y == 60);
    REQUIRE(result.z == 1920);
    REQUIRE(result.w == 960);
}

TEST_CASE("Testing containImage #4", "[Math]") {
    ffw::Vec4i result = ffw::containImage(500, 1000, 1920, 1080);
    REQUIRE(result.x == 690);
    REQUIRE(result.y == 0);
    REQUIRE(result.z == 540);
    REQUIRE(result.w == 1080);
}

TEST_CASE("Testing ImageBuffer", "[Math]") {
    ffw::ImageBuffer buffer;
    buffer.allocate(256, 256, ffw::ImageType::GRAYSCALE_8, NULL, 9);

    auto base = buffer.getPtr();

    REQUIRE(buffer.getWidth() == 256);
    REQUIRE(buffer.getHeight() == 256);
    REQUIRE(buffer.getDepth() == 0);

    REQUIRE(buffer.getWidth(0) == 256);
    REQUIRE(buffer.getHeight(0) == 256);
    REQUIRE(buffer.getDepth(0) == 0);

    REQUIRE(buffer.getWidth(1) == 128);
    REQUIRE(buffer.getHeight(1) == 128);
    REQUIRE(buffer.getDepth(1) == 0);

    REQUIRE(buffer.getWidth(2) == 64);
    REQUIRE(buffer.getHeight(2) == 64);
    REQUIRE(buffer.getDepth(2) == 0);

    REQUIRE(buffer.getWidth(3) == 32);
    REQUIRE(buffer.getHeight(3) == 32);
    REQUIRE(buffer.getDepth(3) == 0);

    REQUIRE(buffer.getWidth(4) == 16);
    REQUIRE(buffer.getHeight(4) == 16);
    REQUIRE(buffer.getDepth(4) == 0);

    REQUIRE(buffer.getWidth(5) == 8);
    REQUIRE(buffer.getHeight(5) == 8);
    REQUIRE(buffer.getDepth(5) == 0);

    REQUIRE(buffer.getWidth(6) == 4);
    REQUIRE(buffer.getHeight(6) == 4);
    REQUIRE(buffer.getDepth(6) == 0);

    REQUIRE(buffer.getWidth(7) == 2);
    REQUIRE(buffer.getHeight(7) == 2);
    REQUIRE(buffer.getDepth(7) == 0);

    REQUIRE(buffer.getWidth(8) == 1);
    REQUIRE(buffer.getHeight(8) == 1);
    REQUIRE(buffer.getDepth(8) == 0);

    REQUIRE(buffer.getWidth(9) == 0);
    REQUIRE(buffer.getHeight(9) == 0);
    REQUIRE(buffer.getDepth(9) == 0);

    REQUIRE(int(buffer.getPtr() - base) == 0);
    REQUIRE(int(buffer.getMipMapPtr(0) - base) == 0);
    REQUIRE(int(buffer.getMipMapPtr(1) - base) == 256 * 256);
    REQUIRE(int(buffer.getMipMapPtr(2) - base) == 256 * 256 + 128 * 128);
    REQUIRE(int(buffer.getMipMapPtr(3) - base) == 256 * 256 + 128 * 128 + 64 * 64);
    REQUIRE(int(buffer.getMipMapPtr(4) - base) == 256 * 256 + 128 * 128 + 64 * 64 + 32 * 32);
    REQUIRE(int(buffer.getMipMapPtr(5) - base) == 256 * 256 + 128 * 128 + 64 * 64 + 32 * 32 + 16 * 16);
    REQUIRE(int(buffer.getMipMapPtr(6) - base) == 256 * 256 + 128 * 128 + 64 * 64 + 32 * 32 + 16 * 16 + 8 * 8);
    REQUIRE(int(buffer.getMipMapPtr(7) - base) == 256 * 256 + 128 * 128 + 64 * 64 + 32 * 32 + 16 * 16 + 8 * 8 + 4 * 4);
    REQUIRE(int(buffer.getMipMapPtr(8) - base) == 256 * 256 + 128 * 128 + 64 * 64 + 32 * 32 + 16 * 16 + 8 * 8 + 4 * 4 + 2 * 2);
}