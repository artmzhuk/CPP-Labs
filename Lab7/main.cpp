#include <iostream>
#include "Matrix.h"

int main() {
    Matrix mat(5,5);



    for(int i = 0; i < mat.rows_; i++){
        for(int j = 0; j < mat.cols_; j++){
            mat.setValue(1, i, j);
            std::cout << mat.getValue(i, j) << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
    mat.multiplyRowAndSumTo(1, 2, 2);

    for(int i = 0; i < mat.rows_; i++){
        for(int j = 0; j < mat.cols_; j++){
            std::cout << mat.getValue(i, j) << " ";
        }
        std::cout << std::endl;
    }

    std::cout << std::endl;
    mat.multiplyRowAndSumTo(2, 3, 2);

    for(int i = 0; i < mat.rows_; i++){
        for(int j = 0; j < mat.cols_; j++){
            std::cout << mat.getValue(i, j) << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
