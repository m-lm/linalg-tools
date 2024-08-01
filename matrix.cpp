#include <iostream>
#include "matrix.h"

Matrix::Matrix() {
}

Matrix::~Matrix() {
}

int Matrix::size() {
    return this->data.size();
}

void Matrix::display() {
    // Display the matrix data
    for (int i = 0; i < this->data.size(); i++) {
        for (int j = 0; j < this->data[0].size(); j++) {
            std::cout << this->data[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void Matrix::resize(int r, int c) {
    // Populate data matrix using row and column dimensions
    this->data.clear();
    for (int i = 0; i < r; i++) {
        this->data.push_back({});
        for (int j = 0; j < c; j++) {
            this->data[i].push_back(0);
        }
    }
}

Matrix Matrix::transpose() {
    // n x m to m x n
    Matrix matrix_T;
    matrix_T.resize(this->data[0].size(), this->data.size()); // note the dimension switch
    for (int i = 0; i < this->data.size(); i++) {
        for (int j = 0; j < this->data[0].size(); j++) {
            matrix_T.data[j][i] = this->data[i][j];
        }
    }
    if (matrix_T.size() == this->data[0].size() && matrix_T.data[0].size() == this->data.size()) {
        return matrix_T;
    }
    else {
        throw std::runtime_error("ERROR: Matrix sizes mismatch after transpose");
    }
}

Matrix Matrix::add(Matrix& other) {
}

Matrix Matrix::mult(int scalar) {
}

Matrix Matrix::mult(Matrix& other) {
}
