#include <gtest/gtest.h>
#include "matrix.h"

TEST(RequiredOperations, ScalarMultiplicationInt) {
    Matrix<int> m(2, 2);
    m[0][0] = 1; m[0][1] = 2;
    m[1][0] = 3; m[1][1] = 4;
    
    Matrix<int> result = m * 2;
    EXPECT_EQ(result[0][0], 2);
    EXPECT_EQ(result[0][1], 4);
    EXPECT_EQ(result[1][0], 6);
    EXPECT_EQ(result[1][1], 8);
}

TEST(RequiredOperations, ScalarMultiplicationDouble) {
    Matrix<double> m(2, 2);
    m[0][0] = 1.5; m[0][1] = 2.5;
    m[1][0] = 3.5; m[1][1] = 4.5;
    
    Matrix<double> result = m * 2.0;
    EXPECT_DOUBLE_EQ(result[0][0], 3.0);
    EXPECT_DOUBLE_EQ(result[0][1], 5.0);
    EXPECT_DOUBLE_EQ(result[1][0], 7.0);
    EXPECT_DOUBLE_EQ(result[1][1], 9.0);
}

TEST(RequiredOperations, ScalarMultiplicationRational) {
    Matrix<Rational> m(2, 1);
    m[0][0] = Rational(1, 2);
    m[1][0] = Rational(2, 3);
    
    Matrix<Rational> result = m * Rational(2, 1);
    EXPECT_EQ(result[0][0], Rational(1, 1));
    EXPECT_EQ(result[1][0], Rational(4, 3));
}

TEST(RequiredOperations, MatrixAdditionInt) {
    Matrix<int> m1(2, 2);
    m1[0][0] = 1; m1[0][1] = 2;
    m1[1][0] = 3; m1[1][1] = 4;
    
    Matrix<int> m2(2, 2);
    m2[0][0] = 5; m2[0][1] = 6;
    m2[1][0] = 7; m2[1][1] = 8;
    
    Matrix<int> result = m1 + m2;
    EXPECT_EQ(result[0][0], 6);
    EXPECT_EQ(result[0][1], 8);
    EXPECT_EQ(result[1][0], 10);
    EXPECT_EQ(result[1][1], 12);
}

TEST(RequiredOperations, MatrixAdditionDouble) {
    Matrix<double> m1(2, 2);
    m1[0][0] = 1.1; m1[0][1] = 2.2;
    m1[1][0] = 3.3; m1[1][1] = 4.4;
    
    Matrix<double> m2(2, 2);
    m2[0][0] = 0.5; m2[0][1] = 0.5;
    m2[1][0] = 0.5; m2[1][1] = 0.5;
    
    Matrix<double> result = m1 + m2;
    EXPECT_DOUBLE_EQ(result[0][0], 1.6);
    EXPECT_DOUBLE_EQ(result[0][1], 2.7);
    EXPECT_DOUBLE_EQ(result[1][0], 3.8);
    EXPECT_DOUBLE_EQ(result[1][1], 4.9);
}

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

TEST(RequiredOperations, MatrixAdditionWrongDimensions) {
    Matrix<int> m1(2, 3);
    Matrix<int> m2(3, 2);
    
    EXPECT_THROW(m1 + m2, std::invalid_argument);
}

TEST(RequiredOperations, MatrixMultiplicationInt) {
    Matrix<int> m1(2, 3);
    m1[0][0] = 1; m1[0][1] = 2; m1[0][2] = 3;
    m1[1][0] = 4; m1[1][1] = 5; m1[1][2] = 6;
    
    Matrix<int> m2(3, 2);
    m2[0][0] = 7;  m2[0][1] = 8;
    m2[1][0] = 9;  m2[1][1] = 10;
    m2[2][0] = 11; m2[2][1] = 12;
    
    Matrix<int> result = m1 * m2;
    EXPECT_EQ(result.getRows(), 2);
    EXPECT_EQ(result.getCols(), 2);
    EXPECT_EQ(result[0][0], 58);   // 1*7 + 2*9 + 3*11 = 58
    EXPECT_EQ(result[0][1], 64);   // 1*8 + 2*10 + 3*12 = 64
    EXPECT_EQ(result[1][0], 139);  // 4*7 + 5*9 + 6*11 = 139
    EXPECT_EQ(result[1][1], 154);  // 4*8 + 5*10 + 6*12 = 154
}

TEST(RequiredOperations, MatrixMultiplicationDouble) {
    Matrix<double> m1(1, 2);
    m1[0][0] = 0.5; m1[0][1] = 0.5;
    
    Matrix<double> m2(2, 1);
    m2[0][0] = 2.0;
    m2[1][0] = 4.0;
    
    Matrix<double> result = m1 * m2;
    EXPECT_EQ(result.getRows(), 1);
    EXPECT_EQ(result.getCols(), 1);
    EXPECT_DOUBLE_EQ(result[0][0], 3.0);  // 0.5*2.0 + 0.5*4.0 = 3.0
}

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

TEST(RequiredOperations, MatrixMultiplicationWrongDimensions) {
    Matrix<int> m1(2, 3);
    Matrix<int> m2(2, 3);  // Несовместимые размеры
    
    EXPECT_THROW(m1 * m2, std::invalid_argument);
}

TEST(RequiredOperations, TransposeInt) {
    Matrix<int> m(2, 3);
    m[0][0] = 1; m[0][1] = 2; m[0][2] = 3;
    m[1][0] = 4; m[1][1] = 5; m[1][2] = 6;
    
    Matrix<int> transposed = m.transpose();
    EXPECT_EQ(transposed.getRows(), 3);
    EXPECT_EQ(transposed.getCols(), 2);
    
    EXPECT_EQ(transposed[0][0], 1);
    EXPECT_EQ(transposed[0][1], 4);
    EXPECT_EQ(transposed[1][0], 2);
    EXPECT_EQ(transposed[1][1], 5);
    EXPECT_EQ(transposed[2][0], 3);
    EXPECT_EQ(transposed[2][1], 6);
}

TEST(RequiredOperations, TransposeDouble) {
    Matrix<double> m(1, 3);
    m[0][0] = 1.5; m[0][1] = 2.5; m[0][2] = 3.5;
    
    Matrix<double> transposed = m.transpose();
    EXPECT_EQ(transposed.getRows(), 3);
    EXPECT_EQ(transposed.getCols(), 1);
    
    EXPECT_DOUBLE_EQ(transposed[0][0], 1.5);
    EXPECT_DOUBLE_EQ(transposed[1][0], 2.5);
    EXPECT_DOUBLE_EQ(transposed[2][0], 3.5);
}

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

TEST(RequiredOperations, AllRequiredTypesSupported) {
    EXPECT_NO_THROW({
        Matrix<int> intMat(2, 2);
        intMat = intMat * 2 + intMat;
        intMat.transpose();
    });
    
    EXPECT_NO_THROW({
        Matrix<double> doubleMat(2, 2);
        doubleMat = doubleMat * 2.0 + doubleMat;
        doubleMat.transpose();
    });
    
    EXPECT_NO_THROW({
        Matrix<Rational> rationalMat(2, 2);
        rationalMat = rationalMat * Rational(2, 1) + rationalMat;
        rationalMat.transpose();
    });
}

TEST(RequiredOperations, RationalInvariantPreserved) {
    Matrix<Rational> m1(2, 2);
    m1[0][0] = Rational(2, 4); 
    m1[0][1] = Rational(3, 6);  
    m1[1][0] = Rational(4, 8);  
    m1[1][1] = Rational(6, 12); 
    
    Matrix<Rational> m2 = m1 * Rational(2, 1);
    EXPECT_EQ(m2[0][0].getC(), 1);        
    EXPECT_EQ(m2[0][0].getZ(), 1);         
    
    Matrix<Rational> sum = m1 + m1;
    EXPECT_EQ(sum[0][0].getC(), 1);       
    EXPECT_EQ(sum[0][0].getZ(), 1);        
    
    Matrix<Rational> transposed = m1.transpose();
    EXPECT_EQ(transposed[0][0].getC(), 1); 
    EXPECT_EQ(transposed[0][0].getZ(), 2);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}