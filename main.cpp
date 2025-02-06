#include <iostream>
#include <vector>
#include "matrix.h"

void unittest() {
    Matrix original;
    std::cout << "Transposition" << std::endl;
    std::vector<int> v1 = {1,3};
    std::vector<int> v2 = {2,1};
    std::vector<int> v3 = {7,7};
    original.data = {v1,v2,v3};
    original.display();
    Matrix transposed = original.transpose();
    transposed.display();

    std::cout << "Addition" << std::endl;
    Matrix original2;
    std::vector<int> b1 = {3,4,9};
    std::vector<int> b2 = {2,8,0};
    original2.data = {b1,b2};
    original2.display();
    Matrix added = transposed.add(original2);
    Matrix added2 = transposed + original2;
    added.display();
    added2.display();

    std::cout << "Multiplication" << std::endl;
    Matrix multed = added.multiply(3);
    multed.display();

    Matrix multed2 = original.multiply(transposed);
    Matrix multed3 = original * transposed;
    multed2.display();
    multed3.display();

    std::cout << "Kronecker" << std::endl;
    Matrix kronned = original.kronecker(added);
    kronned.display();

    std::cout << "Row Concatenation" << std::endl;
    Matrix new1;
    new1.data = {v1, v2};
    new1.display();
    original2.display();
    Matrix concatted = new1.row_concat(original2);
    concatted.display();

}

int main() {
    unittest();
    return 0;
}
