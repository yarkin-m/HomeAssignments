/*
 *   Yarkin Makar
 *   st141442@student.spbu.ru
 *   Assignment 5
 */
#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <vector>
#include <stdexcept>
#include "rational.h"

template<typename T>
class Matrix {
private:
    std::vector<std::vector<T>> data;
    size_t rows;
    size_t cols;

public:

    Matrix();
    Matrix(size_t r, size_t c, const T& value = T());
    Matrix(const std::vector<std::vector<T>>& d);
    Matrix(const Matrix& other);
    Matrix(Matrix&& other) noexcept;
    ~Matrix();
    
    
    Matrix& operator=(const Matrix& other);
    Matrix& operator=(Matrix&& other) noexcept;
    

    size_t getRows() const;
    size_t getCols() const;
    

    std::vector<T>& operator[](size_t index);
    const std::vector<T>& operator[](size_t index) const;
    T& at(size_t row, size_t col);
    const T& at(size_t row, size_t col) const;
    

    Matrix operator*(const T& scalar) const;
    Matrix& operator*=(const T& scalar);

    Matrix operator+(const Matrix& other) const;
    Matrix& operator+=(const Matrix& other);

    Matrix operator-(const Matrix& other) const;
    Matrix& operator-=(const Matrix& other);
    
    Matrix operator*(const Matrix& other) const;
    

    Matrix transpose() const;
    

    bool operator==(const Matrix& other) const;
    bool operator!=(const Matrix& other) const;
    

    static Matrix identity(size_t n);
    static Matrix zeros(size_t rows, size_t cols);
    bool isSquare() const;
    

    template<typename U>
    friend Matrix<U> operator*(const U& scalar, const Matrix<U>& matrix);
    
    template<typename U>
    friend std::ostream& operator<<(std::ostream& os, const Matrix<U>& matrix);
};


template<typename T>
Matrix<T> operator*(const T& scalar, const Matrix<T>& matrix) {
    return matrix * scalar;
}


template<typename T>
std::ostream& operator<<(std::ostream& os, const Matrix<T>& matrix) {
    for (size_t i = 0; i < matrix.rows; ++i) {
        for (size_t j = 0; j < matrix.cols; ++j) {
            os << matrix.data[i][j];
            if (j < matrix.cols - 1) {
                os << " ";
            }
        }
        if (i < matrix.rows - 1) {
            os << std::endl;
        }
    }
    return os;
}


template<typename T>
Matrix<T>::Matrix() : rows(0), cols(0) {}


template<typename T>
Matrix<T>::Matrix(size_t r, size_t c, const T& value) : rows(r), cols(c) {
    data.resize(rows, std::vector<T>(cols, value));
}

template<typename T>
Matrix<T>::Matrix(const std::vector<std::vector<T>>& d) : data(d) {
    rows = d.size();
    if (rows > 0) {
        cols = d[0].size();
        for (size_t i = 1; i < rows; ++i) {
            if (d[i].size() != cols) {
                throw std::invalid_argument("All rows must have the same length");
            }
        }
    } else {
        cols = 0;
    }
}

template<typename T>
Matrix<T>::Matrix(const Matrix& other) 
    : data(other.data), rows(other.rows), cols(other.cols) {}

template<typename T>
Matrix<T>::Matrix(Matrix&& other) noexcept 
    : data(std::move(other.data)), rows(other.rows), cols(other.cols) {
    other.rows = 0;
    other.cols = 0;
}

template<typename T>
Matrix<T>::~Matrix() = default;



template<typename T>
Matrix<T>& Matrix<T>::operator=(const Matrix& other) {
    if (this != &other) {
        data = other.data;
        rows = other.rows;
        cols = other.cols;
    }
    return *this;
}

template<typename T>
Matrix<T>& Matrix<T>::operator=(Matrix&& other) noexcept {
    if (this != &other) {
        data = std::move(other.data);
        rows = other.rows;
        cols = other.cols;
        other.rows = 0;
        other.cols = 0;
    }
    return *this;
}



template<typename T>
size_t Matrix<T>::getRows() const {
    return rows;
}

template<typename T>
size_t Matrix<T>::getCols() const {
    return cols;
}



template<typename T>
std::vector<T>& Matrix<T>::operator[](size_t index) {
    if (index >= rows) {
        throw std::out_of_range("Row index out of range");
    }
    return data[index];
}

template<typename T>
const std::vector<T>& Matrix<T>::operator[](size_t index) const {
    if (index >= rows) {
        throw std::out_of_range("Row index out of range");
    }
    return data[index];
}


template<typename T>
T& Matrix<T>::at(size_t row, size_t col) {
    if (row >= rows || col >= cols) {
        throw std::out_of_range("Index out of range");
    }
    return data[row][col];
}

template<typename T>
const T& Matrix<T>::at(size_t row, size_t col) const {
    if (row >= rows || col >= cols) {
        throw std::out_of_range("Index out of range");
    }
    return data[row][col];
}



template<typename T>
Matrix<T> Matrix<T>::operator*(const T& scalar) const {
    Matrix result(rows, cols);
    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < cols; ++j) {
            result.data[i][j] = data[i][j] * scalar;
        }
    }
    return result;
}

template<typename T>
Matrix<T>& Matrix<T>::operator*=(const T& scalar) {
    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < cols; ++j) {
            data[i][j] *= scalar;
        }
    }
    return *this;
}

template<typename T>
Matrix<T> Matrix<T>::operator+(const Matrix& other) const {
    if (rows != other.rows || cols != other.cols) {
        throw std::invalid_argument("Matrix dimensions must match for addition");
    }
    
    Matrix result(rows, cols);
    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < cols; ++j) {
            result.data[i][j] = data[i][j] + other.data[i][j];
        }
    }
    return result;
}

template<typename T>
Matrix<T>& Matrix<T>::operator+=(const Matrix& other) {
    if (rows != other.rows || cols != other.cols) {
        throw std::invalid_argument("Matrix dimensions must match for addition");
    }
    
    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < cols; ++j) {
            data[i][j] += other.data[i][j];
        }
    }
    return *this;
}

template<typename T>
Matrix<T> Matrix<T>::operator-(const Matrix& other) const {
    if (rows != other.rows || cols != other.cols) {
        throw std::invalid_argument("Matrix dimensions must match for subtraction");
    }
    
    Matrix result(rows, cols);
    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < cols; ++j) {
            result.data[i][j] = data[i][j] - other.data[i][j];
        }
    }
    return result;
}

template<typename T>
Matrix<T>& Matrix<T>::operator-=(const Matrix& other) {
    if (rows != other.rows || cols != other.cols) {
        throw std::invalid_argument("Matrix dimensions must match for subtraction");
    }
    
    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < cols; ++j) {
            data[i][j] -= other.data[i][j];
        }
    }
    return *this;
}

template<typename T>
Matrix<T> Matrix<T>::operator*(const Matrix& other) const {
    if (cols != other.rows) {
        throw std::invalid_argument(
            "Number of columns in first matrix must equal number of rows in second matrix"
        );
    }
    
    Matrix result(rows, other.cols);
    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < other.cols; ++j) {
            T sum = T();
            for (size_t k = 0; k < cols; ++k) {
                sum += data[i][k] * other.data[k][j];
            }
            result.data[i][j] = sum;
        }
    }
    return result;
}


template<typename T>
Matrix<T> Matrix<T>::transpose() const {
    Matrix result(cols, rows);
    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < cols; ++j) {
            result.data[j][i] = data[i][j];
        }
    }
    return result;
}


template<typename T>
bool Matrix<T>::operator==(const Matrix& other) const {
    if (rows != other.rows || cols != other.cols) {
        return false;
    }
    
    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < cols; ++j) {
            if (data[i][j] != other.data[i][j]) {
                return false;
            }
        }
    }
    return true;
}

template<typename T>
bool Matrix<T>::operator!=(const Matrix& other) const {
    return !(*this == other);
}

#endif 