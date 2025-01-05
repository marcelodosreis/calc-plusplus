#include <gtest/gtest.h>
#include "../src/domain/entities/Addition.h"
#include "../src/domain/entities/Number.h"

TEST(AdditionTest, EvaluateSumsPositiveNumbers) {
    Number left(3.0);
    Number right(2.0);
    Addition add(&left, &right);

    EXPECT_DOUBLE_EQ(add.evaluate(), 5.0);
}

TEST(AdditionTest, EvaluateWithNegativeNumbers) {
    Number left(-3.0);
    Number right(2.0);
    Addition add(&left, &right);

    EXPECT_DOUBLE_EQ(add.evaluate(), -1.0);
}
