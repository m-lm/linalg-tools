#include <iostream>
#include "matrix.h"

Matrix::Matrix() {
}

Matrix::~Matrix() {
}

int Matrix::height() {
    return this->data.size();
}

int Matrix::width() {
    return this->data[0].size();

}

void Matrix::display() {
    // Display the matrix data
    for (int i = 0; i < this->height(); i++) {
        for (int j = 0; j < this->width(); j++) {
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
    Matrix result;
    result.resize(this->width(), this->height()); // note the dimension switch
    for (int i = 0; i < this->height(); i++) {
        for (int j = 0; j < this->width(); j++) {
            result.data[j][i] = this->data[i][j];
        }
    }
    if (result.height() == this->width() && result.width() == this->height()) {
        return result;
    }
    else {
        throw std::runtime_error("ERROR: Matrix sizes mismatch after transpose");
    }
}

Matrix Matrix::add(Matrix& other) {
    if (other.height() != this->height() || other.width() != this->width()) {
        throw std::runtime_error("ERROR: Cannot add inequal matrices");
    }
    Matrix result;
    result.resize(this->height(), this->width()); // note the dimension switch
    for (int i = 0; i < this->height(); i++) {
        for (int j = 0; j < this->width(); j++) {
            result.data[i][j] = this->data[i][j] + other.data[i][j];        
        }
    }
    return result;
}

Matrix Matrix::mult(int scalar) {
    Matrix result;
    result.resize(this->height(), this->width()); // note the dimension switch
    for (int i = 0; i < this->height(); i++) {
        for (int j = 0; j < this->width(); j++) {
            result.data[i][j] = this->data[i][j] * scalar;
        }
    }
    return result;
}

Matrix Matrix::mult(Matrix& other) {
    // todo: implement strassen
    if (this->width() != other.height()) {
        throw std::runtime_error("ERROR: Cannot multiply incongruent matrices");
    }
    Matrix result;
    result.resize(this->height(), other.width());
    for (int i = 0; i < result.height(); i++) {
        for (int j = 0; j < result.width(); j++) {
            int sum = 0;
            for (int k = 0; k < this->width(); k++) {
                sum += this->data[i][k] * other.data[k][j];
            }
            result.data[i][j] = sum;
        }
    }
    return result;
}
