#include <gtest/gtest.h>
#include "matrix.h"

TEST(RequiredOperations, MatrixAdditionRational) {
    Matrix<Rational> m1(2, 1);
    m1[0][0] = Rational(1, 2);
    m1[1][0] = Rational(1, 3);
    
    Matrix<Rational> m2(2, 1);
    m2[0][0] = Rational(1, 4);
    m2[1][0] = Rational(1, 5);
    
    Matrix<Rational> result = m1 + m2;
    EXPECT_EQ(result[0][0], Rational(3, 4));
    EXPECT_EQ(result[1][0], Rational(8, 15));
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}