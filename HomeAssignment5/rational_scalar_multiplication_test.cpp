#include <gtest/gtest.h>
#include "matrix.h"

TEST(RequiredOperations, ScalarMultiplicationRational) {
    Matrix<Rational> m(2, 1);
    m[0][0] = Rational(1, 2);
    m[1][0] = Rational(2, 3);
    
    Matrix<Rational> result = m * Rational(2, 1);
    EXPECT_EQ(result[0][0], Rational(1, 1));
    EXPECT_EQ(result[1][0], Rational(4, 3));
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}