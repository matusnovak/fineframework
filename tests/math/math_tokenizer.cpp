#include <ffw/math/stringmath.h>
#include "../catch.hpp"

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