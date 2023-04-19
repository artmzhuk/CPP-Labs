#include <iostream>
#include "Matrix.h"
#include "Matrix2.h"

int main() {
    Matrix2 mat(3, 3);
    mat.print();

    std::cout << (mat.checkInitialized(1, 1) ? "true" : "false") << std::endl;
    std::cout << mat[1][1] << std::endl;
    std::cout << (mat.checkInitialized(1, 1) ? "true" : "false") << std::endl;

    mat.print();

/*

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
*/
    return 0;
}
