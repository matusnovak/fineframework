#include <ffw/math/vec2.h>
#include <ffw/math/vec3.h>
#include <ffw/math/vec4.h>
#include <ffw/math/color.h>
#include <ffw/math/functions.h>
#include "../catch.hpp"

TEST_CASE("Testing lerp", "[Math]") {
    // lerp
    REQUIRE(ffw::lerp(0.0f, 10.0f, 0.5f) == Approx(5.0f));
    REQUIRE(ffw::lerp(-20.0, 10.0, 0.5) == Approx(-5.0));
}

TEST_CASE("Testing dot", "[Math]") {
    // dot product
    REQUIRE(ffw::dot(
        ffw::Vec2d(1.5, 0.0),
        ffw::Vec2d(1.0, 0.0))
        == Approx(3.0 / 2.0));

    REQUIRE(ffw::dot(
        ffw::Vec3d(0.0, 1.5, 0.0),
        ffw::Vec3d(1.0, 1.0, 0.0))
        == Approx(3.0 / 2.0));

    REQUIRE(ffw::dot(
        ffw::Vec4d(0.0, 1.5, 2.0, 0.0),
        ffw::Vec4d(0.0, 1.0, 0.5, 0.0))
        == Approx(5.0 / 2.0));
}

TEST_CASE("Testing cross", "[Math]") {
    // cross product
    REQUIRE(ffw::cross(
        ffw::Vec3f(2.0f, 3.0f, 4.0f),
        ffw::Vec3f(-2.0f, 0.0f, 7.0f))
        == ffw::Vec3f(21.0f, -22.0f, 6.0f));

    REQUIRE(ffw::cross(
        ffw::Vec3f(1.0f, 0.0f, 0.0f),
        ffw::Vec3f(0.0f, 1.0f, 0.0f))
        == ffw::Vec3f(0.0f, 0.0f, 1.0f));
}

TEST_CASE("Testing distance", "[Math]") {
    // distance
    REQUIRE(ffw::distance(
        ffw::Vec2f(7.0f, 4.0f),
        ffw::Vec2f(-2.0f, 5.0f))
        == Approx(9.0554f));

    REQUIRE(ffw::distance(
        ffw::Vec3f(7.0f, 4.0f, -9.0f),
        ffw::Vec3f(-2.0f, 5.0f, 1.0f))
        == Approx(13.490738f));

    REQUIRE(ffw::distance(
        ffw::Vec4f(1.0f, 7.0f, 4.0f, -9.0f),
        ffw::Vec4f(-1.0f, -2.0f, 5.0f, 1.0f))
        == Approx(13.63818f));
}

TEST_CASE("Testing middle", "[Math]") {
    // middle
    REQUIRE(ffw::middle(
        ffw::Vec2f(3.0f, 0.0f),
        ffw::Vec2f(-3.0f, 1.0f))
        == ffw::Vec2f(0.0f, 0.5f));

    REQUIRE(ffw::middle(
        ffw::Vec3f(3.0f, 0.0f, -2.0f),
        ffw::Vec3f(-3.0f, 1.0f, -5.0f))
        == ffw::Vec3f(0.0f, 0.5f, -3.5f));

    REQUIRE(ffw::middle(
        ffw::Vec4f(3.0f, 0.0f, -2.0f, 0.0f),
        ffw::Vec4f(-3.0f, 1.0f, -5.0f, 100.f))
        == ffw::Vec4f(0.0f, 0.5f, -3.5f, 50.0f));
}

TEST_CASE("Testing normalize", "[Math]") {
    // normalize
    {
        auto v = ffw::Vec2f(1.0f, 2.0f).normalize();
        REQUIRE(v == ffw::normalize(ffw::Vec2f(1.0f, 2.0f)));
    }

    {
        auto v = ffw::Vec3f(-2.0f, 7.0f, 3.0f).normalize();
        REQUIRE(v == ffw::normalize(ffw::Vec3f(-2.0f, 7.0f, 3.0f)));
    }

    {
        auto v = ffw::Vec4f(-2.0f, 7.0f, 3.0f, -1.0f).normalize();
        REQUIRE(v == ffw::normalize(ffw::Vec4f(-2.0f, 7.0f, 3.0f, -1.0f)));
    }

    {
        auto v = ffw::Color(1.7f, 0.5f, 3.1f, 0.2f).normalize();
        REQUIRE(v == ffw::normalize(ffw::Color(1.7f, 0.5f, 3.1f, 0.2f)));
    }
}

TEST_CASE("Testing angle", "[Math]") {
    // angle
    REQUIRE(ffw::angle(
        ffw::Vec2f(1.0f, 0.0f),
        ffw::Vec2f(0.0f, 1.0f))
        == Approx(90.0f));

    REQUIRE(ffw::angle(
        ffw::Vec2f(0.707f, 0.707f),
        ffw::Vec2f(0.0f, 1.0f))
        == Approx(45.0f));

    REQUIRE(ffw::angleRad(
        ffw::Vec2f(1.0f, 0.0f),
        ffw::Vec2f(0.0f, 1.0f))
        == Approx(90.0f * DEG_TO_RAD));

    REQUIRE(ffw::angleRad(
        ffw::Vec2f(0.707f, 0.707f),
        ffw::Vec2f(0.0f, 1.0f))
        == Approx(45.0f * DEG_TO_RAD));

    REQUIRE(ffw::angle(
        ffw::Vec3f(-1.0f, 2.0f, 3.0f),
        ffw::Vec3f(4.0f, 5.0f, 6.0f))
        == Approx(43.03190f));

    REQUIRE(ffw::angleRad(
        ffw::Vec3f(-1.0f, 2.0f, 3.0f),
        ffw::Vec3f(4.0f, 5.0f, 6.0f))
        == Approx(43.03190f * DEG_TO_RAD));
}

TEST_CASE("Testing clamp", "[Math]") {
    // clamp
    REQUIRE(ffw::clamp(4.2f, 0.0f, 1.0f) == Approx(1.0f));
    REQUIRE(ffw::clamp(4.2f, -5.0f, 0.7f) == Approx(0.7f));
    REQUIRE(ffw::clamp(0.1f, -5.0f, 0.7f) == Approx(0.1f));
    REQUIRE(ffw::clamp(4.2f, -5.0f, -4.7f) == Approx(-4.7f));
}

TEST_CASE("Testing remap", "[Math]") {
    // remap
    REQUIRE(ffw::remap(100.0f, 100.0f, 1000.0f, 1.0f, 20.0f) == Approx(1.0f));
    REQUIRE(ffw::remap(50.0f, -100.0f, 100.0f, 0.0f, 10.0f) == Approx(7.5f));
    REQUIRE(ffw::remap(1500.0f, 0.0f, 1000.0f, 0.0f, 10.0f) == Approx(15.0f));
    REQUIRE(ffw::remap(100.0f, 500.0f, 1000.0f, 5.0f, 10.0f) == Approx(1.0f));
}

TEST_CASE("Testing nextPowerOfTwo", "[Math]") {
    // NextPowerOfTwo
    REQUIRE(ffw::nextPowOfTwo(2) == 2);
    REQUIRE(ffw::nextPowOfTwo(3) == 4);
    REQUIRE(ffw::nextPowOfTwo(7) == 8);
    REQUIRE(ffw::nextPowOfTwo(15) == 16);
    REQUIRE(ffw::nextPowOfTwo(4096) == 4096);
}

TEST_CASE("Testing byteSwap", "[Math]") {
    // ByteSwap
    REQUIRE(ffw::byteSwap16(0xFFAA) == 0xAAFF);
    REQUIRE(ffw::byteSwap32(0xFFAABBCCUL) == 0xCCBBAAFFUL);
    REQUIRE(ffw::byteSwap64(0xFFAABBCC11223344ULL) == 0x44332211CCBBAAFFULL);
}
