#include <gtest/gtest.h>
#include "matrix.h"

TEST(RequiredOperations, MatrixMultiplicationRational) {
    Matrix<Rational> m1(2, 2);
    m1[0][0] = Rational(1, 2); m1[0][1] = Rational(1, 3);
    m1[1][0] = Rational(2, 3); m1[1][1] = Rational(3, 4);
    
    Matrix<Rational> m2(2, 1);
    m2[0][0] = Rational(1, 1);
    m2[1][0] = Rational(2, 1);
    
    Matrix<Rational> result = m1 * m2;
    EXPECT_EQ(result[0][0], Rational(7, 6));  // (1/2)*1 + (1/3)*2 = 1/2 + 2/3 = 7/6
    EXPECT_EQ(result[1][0], Rational(13, 6)); // (2/3)*1 + (3/4)*2 = 2/3 + 3/2 = 13/6
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}