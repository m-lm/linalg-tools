#ifndef MATRIX
#define MATRIX
#include <vector>

// Note: prefer to use nonvoid functions to avoid in-place mutation
class Matrix {
    protected:
    public:
        Matrix();
        virtual ~Matrix();
        int height();
        int width();
        void display();
        void resize(int r, int c);
        Matrix transpose();
        Matrix add(Matrix& other);
        Matrix multiply(int scalar); // scalar multiplication
        Matrix multiply(Matrix& other); // matrix multiplication
        Matrix hadamard(Matrix& other); // hadamard multiplication
        Matrix kronecker(Matrix& other); // kronecker multiplication
        Matrix row_concat(Matrix& other);
        std::vector< std::vector <int> > data; // 2D matrix of ints
};

#endif