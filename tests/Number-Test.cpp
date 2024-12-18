#include <gtest/gtest.h>
#include "../src/domain/entities/Number.cpp"

TEST(NumberTest, EvaluateReturnsValue) {
    INumber num(5.0);
    EXPECT_DOUBLE_EQ(num.evaluate(), 5.0);
}

TEST(NumberTest, NegativeValue) {
    INumber num(-5.0);
    EXPECT_DOUBLE_EQ(num.evaluate(), -5.0);
}
