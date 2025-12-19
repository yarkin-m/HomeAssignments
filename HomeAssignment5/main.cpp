/*
 *   Yarkin Makar
 *   st141442@student.spbu.ru
 *   Assignment 5
 */
#include <iostream>
#include "matrix.h"

int main() {

    Matrix<int> A(2, 2);
    A[0][0] = 2; A[0][1] = 4;
    A[1][0] = 3; A[1][1] = 5;
    
    std::cout << "Матрица A:\n" << A << "\n\n";
    
    std::cout << "Умножение на скаляр (A * 3):\n" << (A * 3) << "\n\n";
    
    Matrix<int> B(2, 2);
    B[0][0] = 1; B[0][1] = 1;
    B[1][0] = 1; B[1][1] = 1;
    
    std::cout << "Матрица B:\n" << B << "\n\n";
    std::cout << "Сложение матриц (A + B):\n" << (A + B) << "\n\n";

    Matrix<int> C(2, 2);
    C[0][0] = 1; C[0][1] = 2;
    C[1][0] = 0; C[1][1] = 1;
    
    std::cout << "Матрица C:\n" << C << "\n\n";
    std::cout << "Умножение матриц (A * C):\n" << (A * C) << "\n\n";
    
    std::cout << "Транспонирование A:\n" << A.transpose() << "\n";
    
    return 0;
}