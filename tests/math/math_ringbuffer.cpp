#include <ffw/math.h>
#define CATCH_CONFIG_MAIN
#include "../catch.hpp"

TEST_CASE("Testing RingBuffer", "[RingBuffer]") {
    ffw::RingBuffer<int> buffer;

    REQUIRE(buffer.getSize() == 0);
    REQUIRE(buffer.back() == NULL);
    REQUIRE(buffer.range() == 0);

    buffer.create(8);

    REQUIRE(buffer.getSize() == 0);
    REQUIRE(buffer.back() == NULL);
    REQUIRE(buffer.range() == 8);

    REQUIRE(buffer.push(1) == true);
    REQUIRE(*buffer.back() == 1);
    REQUIRE(buffer.push(2) == true);
    REQUIRE(*buffer.back() == 1);
    REQUIRE(buffer.push(3) == true);
    REQUIRE(buffer.push(4) == true);
    REQUIRE(buffer.push(5) == true);
    REQUIRE(buffer.push(6) == true);
    REQUIRE(buffer.push(7) == true);
    REQUIRE(buffer.push(8) == true);
    REQUIRE(*buffer.back() == 1);
    REQUIRE(buffer.push(9) != true);
    REQUIRE(*buffer.back() == 1);

    for (int i = 1; i < 9; i++) {
        REQUIRE(*buffer.back() == i);
        int popped;
        REQUIRE(buffer.pop(&popped) == true);
        REQUIRE(popped == i);
        REQUIRE(buffer.getSize() == (8 - i));
    }

    REQUIRE(buffer.getSize() == 0);
    REQUIRE(buffer.back() == NULL);
    REQUIRE(buffer.range() == 8);


    REQUIRE(buffer.push(42) == true);
    REQUIRE(buffer.getSize() == 1);
    buffer.reset();

    REQUIRE(buffer.getSize() == 0);
    REQUIRE(buffer.back() == NULL);
    REQUIRE(buffer.range() == 8);

    buffer.clear();
    REQUIRE(buffer.getSize() == 0);
    REQUIRE(buffer.back() == NULL);
    REQUIRE(buffer.range() == 0);
}