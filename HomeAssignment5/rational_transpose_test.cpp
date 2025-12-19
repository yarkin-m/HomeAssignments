#include <gtest/gtest.h>
#include "matrix.h"

TEST(RequiredOperations, TransposeRational) {
    Matrix<Rational> m(2, 2);
    m[0][0] = Rational(1, 2); m[0][1] = Rational(2, 3);
    m[1][0] = Rational(3, 4); m[1][1] = Rational(4, 5);
    
    Matrix<Rational> transposed = m.transpose();
    EXPECT_EQ(transposed[0][0], Rational(1, 2));
    EXPECT_EQ(transposed[0][1], Rational(3, 4));
    EXPECT_EQ(transposed[1][0], Rational(2, 3));
    EXPECT_EQ(transposed[1][1], Rational(4, 5));
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}