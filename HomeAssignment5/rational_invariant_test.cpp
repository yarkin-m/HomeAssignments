#include <gtest/gtest.h>
#include "matrix.h"

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