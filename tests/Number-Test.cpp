#include <gtest/gtest.h>
#include "../src/domain/entities/Number.h"

TEST(NumberTest, EvaluateReturnsValue) {
    Number num(5.0);
    EXPECT_DOUBLE_EQ(num.evaluate(), 5.0);
}

TEST(NumberTest, NegativeValue) {
    Number num(-5.0);
    EXPECT_DOUBLE_EQ(num.evaluate(), -5.0);
}
