#include <gtest/gtest.h>
#include "../src/domain/entities/Addition.h"
#include "../src/domain/entities/Number.h"

TEST(AdditionTest, EvaluateSumsPositiveNumbers) {
    INumber left(3.0);
    INumber right(2.0);
    IAddition add(&left, &right);

    EXPECT_DOUBLE_EQ(add.evaluate(), 5.0);
}

TEST(AdditionTest, EvaluateWithNegativeNumbers) {
    INumber left(-3.0);
    INumber right(2.0);
    IAddition add(&left, &right);

    EXPECT_DOUBLE_EQ(add.evaluate(), -1.0);
}
