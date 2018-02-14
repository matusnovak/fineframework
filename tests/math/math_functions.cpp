#include <ffw/math.h>
#define CATCH_CONFIG_MAIN
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

TEST_CASE("Testing string tokenizer #1", "[Math]") {
    std::string str = "  Hello  World! This    is a  sentence...   ";
    const auto tokens = ffw::getTokens(str, " ");
    REQUIRE(tokens.size() == 6);
    REQUIRE(tokens.size() == ffw::getTokensNum(str, " "));
    REQUIRE(tokens[0] == "Hello");
    REQUIRE(tokens[1] == "World!");
    REQUIRE(tokens[2] == "This");
    REQUIRE(tokens[3] == "is");
    REQUIRE(tokens[4] == "a");
    REQUIRE(tokens[5] == "sentence...");
}

TEST_CASE("Testing string tokenizer #2", "[Math]") {
    std::string str = "  Hello  World! This    is a  sentence...   ";
    const auto tokens = ffw::getTokens(str, ' ');
    REQUIRE(tokens.size() == 6);
    REQUIRE(tokens.size() == ffw::getTokensNum(str, ' '));
    REQUIRE(tokens[0] == "Hello");
    REQUIRE(tokens[1] == "World!");
    REQUIRE(tokens[2] == "This");
    REQUIRE(tokens[3] == "is");
    REQUIRE(tokens[4] == "a");
    REQUIRE(tokens[5] == "sentence...");
}

TEST_CASE("Testing string tokenizer #3", "[Math]") {
    std::string str = " Hello  World! This is a  sentence...   ";
    const auto tokens = ffw::getTokens(str, "  ");
    REQUIRE(tokens.size() == 4);
    REQUIRE(tokens.size() == ffw::getTokensNum(str, "  "));
    REQUIRE(tokens[0] == " Hello");
    REQUIRE(tokens[1] == "World! This is a");
    REQUIRE(tokens[2] == "sentence...");
    REQUIRE(tokens[3] == " ");
}

TEST_CASE("Testing string tokenizer #4", "[Math]") {
    std::string str = " Hello  World! This is a  sentence...  ";
    const auto tokens = ffw::getTokens(str, "  ");
    REQUIRE(tokens.size() == 3);
    REQUIRE(tokens.size() == ffw::getTokensNum(str, "  "));
    REQUIRE(tokens[0] == " Hello");
    REQUIRE(tokens[1] == "World! This is a");
    REQUIRE(tokens[2] == "sentence...");
}

TEST_CASE("Testing string tokenizer #5", "[Math]") {
    std::string str = "        ";
    const auto tokens = ffw::getTokens(str, "  ");
    REQUIRE(tokens.size() == 0);
    REQUIRE(tokens.size() == ffw::getTokensNum(str, "  "));
}

TEST_CASE("Testing string tokenizer #6", "[Math]") {
    std::string str = "         ";
    const auto tokens = ffw::getTokens(str, "  ");
    REQUIRE(tokens.size() == 1);
    REQUIRE(tokens.size() == ffw::getTokensNum(str, "  "));
    REQUIRE(tokens[0] == " ");
}

TEST_CASE("Testing string tokenizer #7", "[Math]") {
    std::string str = "DELIMHelloDELIMWorldDELIMDELIMWhat";
    const auto tokens = ffw::getTokens(str, "DELIM");
    REQUIRE(tokens.size() == 3);
    REQUIRE(tokens[0] == "Hello");
    REQUIRE(tokens[1] == "World");
    REQUIRE(tokens[2] == "What");
}

TEST_CASE("Testing string tokenizer #8", "[Math]") {
    std::string str = "DELIMDELIMDELIMDELIMDELIMDELIMDELIM";
    const auto tokens = ffw::getTokens(str, "DELIM");
    REQUIRE(tokens.size() == 0);
}


TEST_CASE("Testing string tokenizer #9", "[Math]") {
    std::string str = "Hello World!";
    ffw::Tokenizer<char> tokenizer(str, " ");
    REQUIRE(tokenizer.hasNext() == true);
    REQUIRE(tokenizer.getNext() == "Hello");
    REQUIRE(tokenizer.hasNext() == true);
    REQUIRE(tokenizer.getNext() == "World!");
    REQUIRE(tokenizer.hasNext() == false);
    REQUIRE(tokenizer.getNext() == "");
}

TEST_CASE("Testing string tokenizer #10", "[Math]") {
    std::string str = "Hello World!";
    ffw::Tokenizer<char> tokenizer(str, "  ");
    REQUIRE(tokenizer.hasNext() == true);
    REQUIRE(tokenizer.getNext() == "Hello World!");
    REQUIRE(tokenizer.hasNext() == false);
    REQUIRE(tokenizer.getNext() == "");
}

TEST_CASE("Testing string tokenizer #11", "[Math]") {
    std::string str = "Hello  World!";
    ffw::Tokenizer<char> tokenizer(str, "  ");
    REQUIRE(tokenizer.hasNext() == true);
    REQUIRE(tokenizer.getNext() == "Hello");
    REQUIRE(tokenizer.hasNext() == true);
    REQUIRE(tokenizer.getNext() == "World!");
    REQUIRE(tokenizer.hasNext() == false);
    REQUIRE(tokenizer.getNext() == "");
}

TEST_CASE("Testing string tokenizer #12", "[Math]") {
    std::string str = "     Hello        World!     ";
    ffw::Tokenizer<char> tokenizer(str, " ");
    REQUIRE(tokenizer.hasNext() == true);
    REQUIRE(tokenizer.getNext() == "Hello");
    REQUIRE(tokenizer.hasNext() == true);
    REQUIRE(tokenizer.getNext() == "World!");
    REQUIRE(tokenizer.hasNext() == false);
    REQUIRE(tokenizer.getNext() == "");
}

TEST_CASE("Testing string tokenizer #13", "[Math]") {
    std::string str = "     Hello        World!   Example  ";
    ffw::Tokenizer<char> tokenizer(str, " ");
    REQUIRE(tokenizer.hasNext() == true);
    REQUIRE(tokenizer.getNext() == "Hello");
    REQUIRE(tokenizer.hasNext() == true);
    REQUIRE(tokenizer.skipNext() == true);
    REQUIRE(tokenizer.hasNext() == true);
    REQUIRE(tokenizer.getNext() == "Example");
    REQUIRE(tokenizer.hasNext() == false);
    REQUIRE(tokenizer.getNext() == "");
}

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
    REQUIRE(int(buffer.getMipMapPtr(1) - base) == 256*256);
    REQUIRE(int(buffer.getMipMapPtr(2) - base) == 256*256 + 128*128);
    REQUIRE(int(buffer.getMipMapPtr(3) - base) == 256*256 + 128*128 + 64*64);
    REQUIRE(int(buffer.getMipMapPtr(4) - base) == 256*256 + 128*128 + 64*64 + 32*32);
    REQUIRE(int(buffer.getMipMapPtr(5) - base) == 256*256 + 128*128 + 64*64 + 32*32 + 16*16);
    REQUIRE(int(buffer.getMipMapPtr(6) - base) == 256*256 + 128*128 + 64*64 + 32*32 + 16*16 + 8*8);
    REQUIRE(int(buffer.getMipMapPtr(7) - base) == 256*256 + 128*128 + 64*64 + 32*32 + 16*16 + 8*8 + 4*4);
    REQUIRE(int(buffer.getMipMapPtr(8) - base) == 256*256 + 128*128 + 64*64 + 32*32 + 16*16 + 8*8 + 4*4 + 2*2);
}