#include <ffw/math.h>
#define CATCH_CONFIG_MAIN
#include "../catch.hpp"

class DummyFont {
public:
    DummyFont() {
        
    }
    ~DummyFont() {
        
    }
    float getCharAdvance(wchar_t chr) const {
        (void)chr;
        return 8.0f;
    }
};

DummyFont dummyFont;

TEST_CASE("Hello World") {
    const auto str = "Hello World";
    auto wrapper = ffw::TextWrapper<char>(str, str + 11);

    std::string result = "";
    while(const auto token = wrapper.next(&dummyFont, 100.0f)) {
        result += std::string(token.str, token.len) + "\n";
    }

    REQUIRE(result == "Hello World\n");

    // Next call must fail
    REQUIRE(!(wrapper.next(&dummyFont, 100.0f)));
}

TEST_CASE("One character") {
    const auto str = "A";
    auto wrapper = ffw::TextWrapper<char>(str, str + 1);

    std::string result = "";
    while (const auto token = wrapper.next(&dummyFont, 100.0f)) {
        result += std::string(token.str, token.len) + "\n";
    }

    REQUIRE(result == "A\n");

    // Next call must fail
    REQUIRE(!(wrapper.next(&dummyFont, 100.0f)));
}

TEST_CASE("Empty string") {
    const auto str = "";
    auto wrapper = ffw::TextWrapper<char>(str, str + 0);

    // Call must fail
    REQUIRE(!(wrapper.next(&dummyFont, 100.0f)));
}

TEST_CASE("Split into two") {
    const auto str = "Hello World";
    auto wrapper = ffw::TextWrapper<char>(str, str + 11);

    auto token0 = wrapper.next(&dummyFont, 40.0f);
    REQUIRE(token0);
    REQUIRE(std::string(token0.str, token0.len) == "Hello ");
    REQUIRE(token0.width == Approx(6 * 8.0f));

    auto token1 = wrapper.next(&dummyFont, 40.0f);
    REQUIRE(token1);
    REQUIRE(std::string(token1.str, token1.len) == "World");
    REQUIRE(token1.width == Approx(5 * 8.0f));

    // Next call must fail
    REQUIRE(!(wrapper.next(&dummyFont, 40.0f)));
}

TEST_CASE("Split into two more spaces") {
    const auto str = "     Hello     World     ";
    auto wrapper = ffw::TextWrapper<char>(str, str + 25);

    auto token0 = wrapper.next(&dummyFont, 40.0f);
    REQUIRE(token0);
    REQUIRE(std::string(token0.str, token0.len) == "     ");
    REQUIRE(token0.width == Approx(5 * 8.0f));

    auto token1 = wrapper.next(&dummyFont, 40.0f);
    REQUIRE(token1);
    REQUIRE(std::string(token1.str, token1.len) == "Hello     ");
    REQUIRE(token1.width == Approx(10 * 8.0f));

    auto token2 = wrapper.next(&dummyFont, 40.0f);
    REQUIRE(token2);
    REQUIRE(std::string(token2.str, token2.len) == "World     ");
    REQUIRE(token2.width == Approx(10 * 8.0f));

    // Next call must fail
    REQUIRE(!(wrapper.next(&dummyFont, 40.0f)));
}

TEST_CASE("Split long words without whitespace") {
    const auto str = "HelloWorld";
    auto wrapper = ffw::TextWrapper<char>(str, str + 10);

    auto token0 = wrapper.next(&dummyFont, 40.0f);
    REQUIRE(token0);
    REQUIRE(std::string(token0.str, token0.len) == "Hello");
    REQUIRE(token0.width == Approx(5 * 8.0f));

    auto token1 = wrapper.next(&dummyFont, 40.0f);
    REQUIRE(token1);
    REQUIRE(std::string(token1.str, token1.len) == "World");
    REQUIRE(token1.width == Approx(5 * 8.0f));

    // Next call must fail
    REQUIRE(!(wrapper.next(&dummyFont, 40.0f)));
}

TEST_CASE("Ignore empty strings") {
    SECTION("nullptr") {
        const char* str = nullptr;
        auto wrapper = ffw::TextWrapper<char>(str, str + 0);

        REQUIRE(!(wrapper.next(&dummyFont, 40.0f)));
    }

    SECTION("empty string") {
        const char* str = "";
        auto wrapper = ffw::TextWrapper<char>(str, str + 0);

        REQUIRE(!(wrapper.next(&dummyFont, 40.0f)));
    }
}

TEST_CASE("Split two with hardcoded newline") {
    const auto str = "Hello\nWorld";
    auto wrapper = ffw::TextWrapper<char>(str, str + 11);

    auto token0 = wrapper.next(&dummyFont, 40.0f);
    REQUIRE(token0);
    REQUIRE(std::string(token0.str, token0.len) == "Hello");
    REQUIRE(token0.width == Approx(5 * 8.0f));

    auto token1 = wrapper.next(&dummyFont, 40.0f);
    REQUIRE(token1);
    REQUIRE(*token1.str == '\n');
    REQUIRE(token1.len == 0);

    auto token2 = wrapper.next(&dummyFont, 40.0f);
    REQUIRE(token2);
    REQUIRE(std::string(token2.str, token2.len) == "World");
    REQUIRE(token2.width == Approx(5 * 8.0f));

    // Next call must fail
    REQUIRE(!(wrapper.next(&dummyFont, 40.0f)));
}

TEST_CASE("Multiple newlines must return empty tokens") {
    const auto str = "Hello\n\n\nWorld\n";
    auto wrapper = ffw::TextWrapper<char>(str, str + 14);

    auto token0 = wrapper.next(&dummyFont, 40.0f);
    REQUIRE(token0);
    REQUIRE(std::string(token0.str, token0.len) == "Hello");
    REQUIRE(token0.width == Approx(5 * 8.0f));

    auto token1 = wrapper.next(&dummyFont, 40.0f);
    REQUIRE(token1);
    REQUIRE(token1.len == 0);

    auto token2 = wrapper.next(&dummyFont, 40.0f);
    REQUIRE(token2);
    REQUIRE(token2.len == 0);

    auto token3 = wrapper.next(&dummyFont, 40.0f);
    REQUIRE(token3);
    REQUIRE(token3.len == 0);

    auto token4 = wrapper.next(&dummyFont, 40.0f);
    REQUIRE(token4);
    REQUIRE(std::string(token4.str, token4.len) == "World");
    REQUIRE(token4.width == Approx(5 * 8.0f));

    auto token5 = wrapper.next(&dummyFont, 40.0f);
    REQUIRE(token5);
    REQUIRE(token5.len == 0);

    // Next call must fail
    REQUIRE(!(wrapper.next(&dummyFont, 40.0f)));
}

TEST_CASE("Split into multiple") {
    const std::string str = "Hello World 12345 ABCDE";
    auto wrapper = ffw::TextWrapper<char>(&str[0], &str[0] + str.size());

    auto token0 = wrapper.next(&dummyFont, 88.0f);
    REQUIRE(token0);
    REQUIRE(std::string(token0.str, token0.len) == "Hello World ");
    REQUIRE(token0.width == Approx(12 * 8.0f));

    auto token1 = wrapper.next(&dummyFont, 88.0f);
    REQUIRE(token1);
    REQUIRE(std::string(token1.str, token1.len) == "12345 ABCDE");
    REQUIRE(token1.width == Approx(11 * 8.0f));

    // Next call must fail
    REQUIRE(!(wrapper.next(&dummyFont, 88.0f)));
}

TEST_CASE("Split into multiple 2") {
    const std::string str = "Hello World 12345 ABCDE     FGHIJ   MNO";
    auto wrapper = ffw::TextWrapper<char>(&str[0], &str[0] + str.size());

    auto token0 = wrapper.next(&dummyFont, 88.0f);
    REQUIRE(token0);
    REQUIRE(std::string(token0.str, token0.len) == "Hello World ");
    REQUIRE(token0.width == Approx(12 * 8.0f));

    auto token1 = wrapper.next(&dummyFont, 88.0f);
    REQUIRE(token1);
    REQUIRE(std::string(token1.str, token1.len) == "12345 ABCDE     ");
    REQUIRE(token1.width == Approx(16 * 8.0f));

    auto token2 = wrapper.next(&dummyFont, 88.0f);
    REQUIRE(token2);
    REQUIRE(std::string(token2.str, token2.len) == "FGHIJ   MNO");
    REQUIRE(token2.width == Approx(11 * 8.0f));

    // Next call must fail
    REQUIRE(!(wrapper.next(&dummyFont, 88.0f)));
}

TEST_CASE("Split into multiple using line break opportunity") {
    const std::string str = "Hello-World-12345-ABCDE-FGHIJ---";
    auto wrapper = ffw::TextWrapper<char>(&str[0], &str[0] + str.size());

    auto token0 = wrapper.next(&dummyFont, 104.0f);
    REQUIRE(token0);
    REQUIRE(std::string(token0.str, token0.len) == "Hello-World-");
    REQUIRE(token0.width == Approx(12 * 8.0f));

    auto token1 = wrapper.next(&dummyFont, 104.0f);
    REQUIRE(token1);
    REQUIRE(std::string(token1.str, token1.len) == "12345-ABCDE-");
    REQUIRE(token1.width == Approx(12 * 8.0f));

    auto token2 = wrapper.next(&dummyFont, 104.0f);
    REQUIRE(token2);
    REQUIRE(std::string(token2.str, token2.len) == "FGHIJ---");
    REQUIRE(token2.width == Approx(8 * 8.0f));

    // Next call must fail
    REQUIRE(!(wrapper.next(&dummyFont, 88.0f)));
}

TEST_CASE("Test windows new lines r + n") {
    const std::string str = "Hello\r\nWorld";
    auto wrapper = ffw::TextWrapper<char>(&str[0], &str[0] + str.size());

    auto token0 = wrapper.next(&dummyFont, 40.0f);
    REQUIRE(token0);
    REQUIRE(std::string(token0.str, token0.len) == "Hello");
    REQUIRE(token0.width == Approx(5 * 8.0f));

    auto token1 = wrapper.next(&dummyFont, 40.0f);
    REQUIRE(token1);
    REQUIRE(token1.len == 0);

    auto token2 = wrapper.next(&dummyFont, 40.0f);
    REQUIRE(token2);
    REQUIRE(std::string(token2.str, token2.len) == "World");
    REQUIRE(token2.width == Approx(5 * 8.0f));

    // Next call must fail
    REQUIRE(!(wrapper.next(&dummyFont, 40.0f)));
}

TEST_CASE("Test windows new lines n + r") {
    const std::string str = "Hello\n\rWorld";
    auto wrapper = ffw::TextWrapper<char>(&str[0], &str[0] + str.size());

    auto token0 = wrapper.next(&dummyFont, 40.0f);
    REQUIRE(token0);
    REQUIRE(std::string(token0.str, token0.len) == "Hello");
    REQUIRE(token0.width == Approx(5 * 8.0f));

    auto token1 = wrapper.next(&dummyFont, 40.0f);
    REQUIRE(token1);
    REQUIRE(token1.len == 0);

    auto token2 = wrapper.next(&dummyFont, 40.0f);
    REQUIRE(token2);
    REQUIRE(std::string(token2.str, token2.len) == "World");
    REQUIRE(token2.width == Approx(5 * 8.0f));

    // Next call must fail
    REQUIRE(!(wrapper.next(&dummyFont, 40.0f)));
}

TEST_CASE("Test windows new lines r + n with wider width") {
    const std::string str = "Hello\r\nWorld";
    auto wrapper = ffw::TextWrapper<char>(&str[0], &str[0] + str.size());

    auto token0 = wrapper.next(&dummyFont, 1000.0f);
    REQUIRE(token0);
    REQUIRE(std::string(token0.str, token0.len) == "Hello");
    REQUIRE(token0.width == Approx(5 * 8.0f));

    auto token1 = wrapper.next(&dummyFont, 1000.0f);
    REQUIRE(token1);
    REQUIRE(token1.len == 0);

    auto token2 = wrapper.next(&dummyFont, 1000.0f);
    REQUIRE(token2);
    REQUIRE(std::string(token2.str, token2.len) == "World");
    REQUIRE(token2.width == Approx(5 * 8.0f));

    // Next call must fail
    REQUIRE(!(wrapper.next(&dummyFont, 1000.0f)));
}

TEST_CASE("Test windows new lines n + r with wider width") {
    const std::string str = "Hello\n\rWorld";
    auto wrapper = ffw::TextWrapper<char>(&str[0], &str[0] + str.size());

    auto token0 = wrapper.next(&dummyFont, 1000.0f);
    REQUIRE(token0);
    REQUIRE(std::string(token0.str, token0.len) == "Hello");
    REQUIRE(token0.width == Approx(5 * 8.0f));

    auto token1 = wrapper.next(&dummyFont, 1000.0f);
    REQUIRE(token1);
    REQUIRE(token1.len == 0);

    auto token2 = wrapper.next(&dummyFont, 1000.0f);
    REQUIRE(token2);
    REQUIRE(std::string(token2.str, token2.len) == "World");
    REQUIRE(token2.width == Approx(5 * 8.0f));

    // Next call must fail
    REQUIRE(!(wrapper.next(&dummyFont, 1000.0f)));
}

TEST_CASE("Last carriage return") {
    const std::string str = "Hello\n\rWorld\r";
    auto wrapper = ffw::TextWrapper<char>(&str[0], &str[0] + str.size());

    auto token0 = wrapper.next(&dummyFont, 40.0f);
    REQUIRE(token0);
    REQUIRE(std::string(token0.str, token0.len) == "Hello");
    REQUIRE(token0.width == Approx(5 * 8.0f));

    auto token1 = wrapper.next(&dummyFont, 40.0f);
    REQUIRE(token1);
    REQUIRE(token1.len == 0);

    auto token2 = wrapper.next(&dummyFont, 40.0f);
    REQUIRE(token2);
    REQUIRE(std::string(token2.str, token2.len) == "World\r");
    REQUIRE(token2.width == Approx(5 * 8.0f));

    // Next call must fail
    REQUIRE(!(wrapper.next(&dummyFont, 40.0f)));
}

TEST_CASE("Split into two extened latin") {
    const std::string str = "\x48\xC3\xA9\xC4\xBE\xC4\xBE\xC3\xB4 \x57\xC3\xB4\xC5\x99\xC4\xBE\xC4\x8F";
    auto wrapper = ffw::TextWrapper<char>(&str[0], &str[0] + str.size());

    auto token0 = wrapper.next(&dummyFont, 40.0f);
    REQUIRE(token0);
    REQUIRE(std::string(token0.str, token0.len) == "\x48\xC3\xA9\xC4\xBE\xC4\xBE\xC3\xB4 ");
    REQUIRE(token0.width == Approx(6 * 8.0f));

    auto token1 = wrapper.next(&dummyFont, 40.0f);
    REQUIRE(token1);
    REQUIRE(std::string(token1.str, token1.len) == "\x57\xC3\xB4\xC5\x99\xC4\xBE\xC4\x8F");
    REQUIRE(token1.width == Approx(5 * 8.0f));

    // Next call must fail
    REQUIRE(!(wrapper.next(&dummyFont, 40.0f)));
}

TEST_CASE("Split into two wchar_t") {
    const std::wstring str = L"Hello World";
    auto wrapper = ffw::TextWrapper<wchar_t>(&str[0], &str[0] + str.size());

    auto token0 = wrapper.next(&dummyFont, 40.0f);
    REQUIRE(token0);
    REQUIRE(std::wstring(token0.str, token0.len) == L"Hello ");
    REQUIRE(token0.width == Approx(6 * 8.0f));

    auto token1 = wrapper.next(&dummyFont, 40.0f);
    REQUIRE(token1);
    REQUIRE(std::wstring(token1.str, token1.len) == L"World");
    REQUIRE(token1.width == Approx(5 * 8.0f));

    // Next call must fail
    REQUIRE(!(wrapper.next(&dummyFont, 40.0f)));
}

TEST_CASE("Do not split if width is negative") {
    const std::wstring str = L"Hello World\n12345 ABCDE";
    auto wrapper = ffw::TextWrapper<wchar_t>(&str[0], &str[0] + str.size());

    auto token0 = wrapper.next(&dummyFont, -1.0f);
    REQUIRE(token0);
    REQUIRE(std::wstring(token0.str, token0.len) == L"Hello World");
    REQUIRE(token0.width == Approx(11 * 8.0f));

    auto token1 = wrapper.next(&dummyFont, -1.0f);
    REQUIRE(token1);
    REQUIRE(token1.len == 0);

    auto token2 = wrapper.next(&dummyFont, -1.0f);
    REQUIRE(token2);
    REQUIRE(std::wstring(token2.str, token2.len) == L"12345 ABCDE");
    REQUIRE(token2.width == Approx(11 * 8.0f));

    // Next call must fail
    REQUIRE(!(wrapper.next(&dummyFont, -1.0f)));
}

TEST_CASE("Lorem Ipsum") {
    const std::string str = "Lorem ipsum  dolor sit amet";
    auto wrapper = ffw::TextWrapper<char>(&str[0], &str[0] + str.size());

    auto token0 = wrapper.next(&dummyFont, 15 * 8.0f);
    REQUIRE(token0);
    REQUIRE(std::string(token0.str, token0.len) == "Lorem ipsum  ");
    REQUIRE(token0.width == Approx(13 * 8.0f));

    auto token1 = wrapper.next(&dummyFont, 15 * 8.0f);
    REQUIRE(token1);
    REQUIRE(std::string(token1.str, token1.len) == "dolor sit amet");
    REQUIRE(token1.width == Approx(14 * 8.0f));

    // Next call must fail
    REQUIRE(!(wrapper.next(&dummyFont, 15 * 8.0f)));
}

TEST_CASE("Opportunity wrap 1") {
    const std::string str = "Lorem ipsum.  Dolor sit amet.";
    auto wrapper = ffw::TextWrapper<char>(&str[0], &str[0] + str.size());

    auto token0 = wrapper.next(&dummyFont, 15 * 8.0f);
    REQUIRE(token0);
    REQUIRE(std::string(token0.str, token0.len) == "Lorem ipsum.  ");
    REQUIRE(token0.width == Approx(14 * 8.0f));

    auto token1 = wrapper.next(&dummyFont, 15 * 8.0f);
    REQUIRE(token1);
    REQUIRE(std::string(token1.str, token1.len) == "Dolor sit amet.");
    REQUIRE(token1.width == Approx(15 * 8.0f));

    // Next call must fail
    REQUIRE(!(wrapper.next(&dummyFont, 15 * 8.0f)));
}

TEST_CASE("Opportunity wrap 2") {
    const std::string str = "Lorem ipsum.  Dolor sit amet.";
    auto wrapper = ffw::TextWrapper<char>(&str[0], &str[0] + str.size());

    auto token0 = wrapper.next(&dummyFont, 13 * 8.0f);
    REQUIRE(token0);
    REQUIRE(std::string(token0.str, token0.len) == "Lorem ipsum.  ");
    REQUIRE(token0.width == Approx(14 * 8.0f));

    auto token1 = wrapper.next(&dummyFont, 13 * 8.0f);
    REQUIRE(token1);
    REQUIRE(std::string(token1.str, token1.len) == "Dolor sit ");
    REQUIRE(token1.width == Approx(10 * 8.0f));

    auto token2 = wrapper.next(&dummyFont, 13 * 8.0f);
    REQUIRE(token2);
    REQUIRE(std::string(token2.str, token2.len) == "amet.");
    REQUIRE(token2.width == Approx(5 * 8.0f));

    // Next call must fail
    REQUIRE(!(wrapper.next(&dummyFont, 13 * 8.0f)));
}

TEST_CASE("Opportunity wrap 3") {
    const std::string str = "Lorem ipsum  Dolor sit amet.";
    auto wrapper = ffw::TextWrapper<char>(&str[0], &str[0] + str.size());

    auto token0 = wrapper.next(&dummyFont, 11 * 8.0f);
    REQUIRE(token0);
    REQUIRE(std::string(token0.str, token0.len) == "Lorem ipsum  ");
    REQUIRE(token0.width == Approx(13 * 8.0f));

    auto token1 = wrapper.next(&dummyFont, 12 * 8.0f);
    REQUIRE(token1);
    REQUIRE(std::string(token1.str, token1.len) == "Dolor sit ");
    REQUIRE(token1.width == Approx(10 * 8.0f));

    auto token2 = wrapper.next(&dummyFont, 12 * 8.0f);
    REQUIRE(token2);
    REQUIRE(std::string(token2.str, token2.len) == "amet.");
    REQUIRE(token2.width == Approx(5 * 8.0f));

    // Next call must fail
    REQUIRE(!(wrapper.next(&dummyFont, 12 * 8.0f)));
}

TEST_CASE("Opportunity wrap 4") {
    const std::string str = "Lorem ipsum.  Dolor sit amet.";
    auto wrapper = ffw::TextWrapper<char>(&str[0], &str[0] + str.size());

    auto token0 = wrapper.next(&dummyFont, 11 * 8.0f);
    REQUIRE(token0);
    REQUIRE(std::string(token0.str, token0.len) == "Lorem ");
    REQUIRE(token0.width == Approx(6 * 8.0f));

    auto token1 = wrapper.next(&dummyFont, 12 * 8.0f);
    REQUIRE(token1);
    REQUIRE(std::string(token1.str, token1.len) == "ipsum.  ");
    REQUIRE(token1.width == Approx(8 * 8.0f));

    auto token2 = wrapper.next(&dummyFont, 12 * 8.0f);
    REQUIRE(token2);
    REQUIRE(std::string(token2.str, token2.len) == "Dolor sit ");
    REQUIRE(token2.width == Approx(10 * 8.0f));

    auto token3 = wrapper.next(&dummyFont, 12 * 8.0f);
    REQUIRE(token3);
    REQUIRE(std::string(token3.str, token3.len) == "amet.");
    REQUIRE(token3.width == Approx(5 * 8.0f));

    // Next call must fail
    REQUIRE(!(wrapper.next(&dummyFont, 12 * 8.0f)));
}

TEST_CASE("Multiple lines with whitespace") {
    const std::string str = "Lorem\n   \n\nIpsum";
    auto wrapper = ffw::TextWrapper<char>(&str[0], &str[0] + str.size());

    auto token0 = wrapper.next(&dummyFont, -1.0f);
    REQUIRE(token0);
    REQUIRE(std::string(token0.str, token0.len) == "Lorem");
    REQUIRE(token0.width == Approx(5 * 8.0f));

    auto token1 = wrapper.next(&dummyFont, -1.0f);
    REQUIRE(token1);
    REQUIRE(*token1.str == '\n');

    auto token2 = wrapper.next(&dummyFont, -1.0f);
    REQUIRE(token2);
    REQUIRE(std::string(token2.str, token2.len) == "   ");
    REQUIRE(token2.width == Approx(3 * 8.0f));

    auto token3 = wrapper.next(&dummyFont, -1.0f);
    REQUIRE(token3);
    REQUIRE(*token3.str == '\n');

    auto token4 = wrapper.next(&dummyFont, -1.0f);
    REQUIRE(token4);
    REQUIRE(*token4.str == '\n');

    auto token5 = wrapper.next(&dummyFont, -1.0f);
    REQUIRE(token5);
    REQUIRE(std::string(token5.str, token5.len) == "Ipsum");
    REQUIRE(token5.width == Approx(5 * 8.0f));

    // Next call must fail
    REQUIRE(!(wrapper.next(&dummyFont, -1.0f)));
}

TEST_CASE("Whitespace") {
    const std::string str = "    ";
    auto wrapper = ffw::TextWrapper<char>(&str[0], &str[0] + str.size());

    auto token0 = wrapper.next(&dummyFont, -1.0f);
    REQUIRE(token0);
    REQUIRE(std::string(token0.str, token0.len) == "    ");
    REQUIRE(token0.width == Approx(4 * 8.0f));

    // Next call must fail
    REQUIRE(!(wrapper.next(&dummyFont, -1.0f)));
}
