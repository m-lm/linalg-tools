#ifndef MATRIX
#define MATRIX
#include <vector>

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
        Matrix mult(int scalar); // scalar multiplication
        Matrix mult(Matrix& other); // matrix multiplication
        std::vector< std::vector <int> > data; // 2D matrix of ints
};

#endif