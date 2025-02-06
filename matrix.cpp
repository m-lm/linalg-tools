#include <iostream>
#include "matrix.h"

Matrix::Matrix() {
}

Matrix::~Matrix() {
}

Matrix Matrix::operator+(const Matrix& other) {
    return this->add(other);
}

Matrix Matrix::operator*(const Matrix& other) {
    return this->multiply(other);
}

int Matrix::rows() const {
    // Get number of rows
    return this->data.size();
}

int Matrix::columns() const {
    // Get number of columns
    return this->data[0].size();
}

void Matrix::display() const {
    // Display the matrix data
    const int spacing = 5; // based on largest number's digits
    for (int i = 0; i < this->rows(); i++) {
        for (int j = 0; j < this->columns(); j++) {
            std::cout << this->data[i][j] << std::string(spacing - std::to_string(this->data[i][j]).length() % spacing, ' ');
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void Matrix::resize(int r, int c) {
    // Populate data matrix using specified row and column dimensions
    this->data.clear();
    for (int i = 0; i < r; i++) {
        this->data.push_back({});
        for (int j = 0; j < c; j++) {
            this->data[i].push_back(0);
        }
    }
}

Matrix Matrix::transpose() {
    // Transpose matrix from nxm to mxn; columns as rows and vice-versa
    Matrix result;
    result.resize(this->columns(), this->rows()); // note the dimension switch
    for (int i = 0; i < this->rows(); i++) {
        for (int j = 0; j < this->columns(); j++) {
            result.data[j][i] = this->data[i][j];
        }
    }
    return result;
}

Matrix Matrix::add(const Matrix& other) {
    if (other.rows() != this->rows() || other.columns() != this->columns()) {
        throw std::runtime_error("ERROR: Cannot add inequal matrices");
    }
    Matrix result;
    result.resize(this->rows(), this->columns());
    for (int i = 0; i < this->rows(); i++) {
        for (int j = 0; j < this->columns(); j++) {
            result.data[i][j] = this->data[i][j] + other.data[i][j];        
        }
    }
    return result;
}

Matrix Matrix::multiply(const int scalar) {
    // Multiply the elements of a matrix by a scalar constant
    Matrix result;
    result.resize(this->rows(), this->columns());
    for (int i = 0; i < this->rows(); i++) {
        for (int j = 0; j < this->columns(); j++) {
            result.data[i][j] = this->data[i][j] * scalar;
        }
    }
    return result;
}

Matrix Matrix::multiply(const Matrix& other) {
    // Multiply two matrices together, left-to-right (object X argument)
    // todo: implement strassen
    if (this->columns() != other.rows()) {
        // operand matrices must be in form of (nxm) X (mxp) = (nxp) w.r.t dimensions
        throw std::runtime_error("ERROR: Cannot multiply incongruent matrices");
    }
    Matrix result;
    result.resize(this->rows(), other.columns());
    for (int i = 0; i < result.rows(); i++) {
        for (int j = 0; j < result.columns(); j++) {
            int sum = 0;
            for (int k = 0; k < this->columns(); k++) {
                sum += this->data[i][k] * other.data[k][j];
            }
            result.data[i][j] = sum;
        }
    }
    return result;
}

Matrix Matrix::hadamard(const Matrix& other) {
    // Like matrix addition but multiply
    if (other.rows() != this->rows() || other.columns() != this->columns()) {
        throw std::runtime_error("ERROR: Cannot Hadamard multiply inequal matrices");
    }
    Matrix result;
    result.resize(this->rows(), this->columns());
    for (int i = 0; i < this->rows(); i++) {
        for (int j = 0; j < this->columns(); j++) {
            result.data[i][j] = this->data[i][j] * other.data[i][j];        
        }
    }
    return result;
}

Matrix Matrix::kronecker(const Matrix& other) {
    // Iterative matrix multiplication without summation
    Matrix result;
    result.resize(this->rows() * other.rows(), this->columns() * other.columns());
    for (int i = 0; i < this->rows(); i++) {
        for (int j = 0; j < this->columns(); j++) {
            for (int k = 0; k < other.rows(); k++) {
                for (int l = 0; l < other.columns(); l++) {
                    result.data[i * other.rows() + k][j * other.columns() + l] = this->data[i][j] * other.data[k][l];        
                }
            }
        }
    }
    return result;
}

Matrix Matrix::row_concat(const Matrix& other) {
    if (this->rows() != other.rows()) {
        // needs same number of rows
        throw std::runtime_error("ERROR: Cannot horizontally concatenate matrices with different row sizes");
    }
    Matrix result;
    result.resize(this->rows(), other.columns() + this->columns());
    for (int i = 0; i < this->rows(); i++) {
        for (int j = 0; j < this->columns(); j++) {
            result.data[i][j] = this->data[i][j];
        }
        for (int j = 0; j < other.columns(); j++) {
            result.data[i][j + this->columns()] = other.data[i][j];
        }
    }
    return result;
}