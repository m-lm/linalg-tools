#ifndef MATRIX
#define MATRIX
#include <vector>

// Note: prefer to use nonvoid functions to avoid in-place mutation
class Matrix {
    protected:
    public:
        Matrix();
        virtual ~Matrix();
        Matrix operator+(const Matrix& other);
        Matrix operator*(const Matrix& other);
        int rows() const;
        int columns() const;
        void display() const;
        void resize(int r, int c);
        Matrix transpose();
        Matrix add(const Matrix& other);
        Matrix multiply(const int scalar); // scalar multiplication
        Matrix multiply(const Matrix& other); // matrix multiplication
        Matrix hadamard(const Matrix& other); // hadamard multiplication
        Matrix kronecker(const Matrix& other); // kronecker multiplication
        Matrix row_concat(const Matrix& other);
        std::vector< std::vector <int> > data; // 2D matrix of ints
};

#endif