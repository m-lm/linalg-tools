#include <iostream>
#include <vector>
#include "matrix.h"

void unittest() {
    Matrix original;
    std::vector<int> v1 = {1,3};
    std::vector<int> v2 = {2,1};
    std::vector<int> v3 = {7,7};
    original.data = {v1,v2,v3};
    original.display();
    Matrix transposed = original.transpose();
    transposed.display();
}

int main() {
    unittest();
    return 0;
}