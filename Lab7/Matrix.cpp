//
// Created by artm on 17.4.23.
//

#include "Matrix.h"
#include <bits/stdc++.h>

Matrix::Matrix(int rows, int cols) : rows_(rows), cols_(cols){
    create();
}


void Matrix::create(){
    this->pointer = new int**[rows_];
    for(int i = 0; i < rows_; i++){
        this->pointer[i] = nullptr;
    }
}

bool Matrix::checkAlloc(int x, int y) {
    if (!(pointer[x] == nullptr || pointer[x][y] == nullptr)){
        return true;
    }
    return false;
}

void Matrix::setValue(int value, int x, int y){
    if (this->pointer[x] == nullptr){
        this->pointer[x] = new int*[cols_];
        for (int i = 0; i < cols_; i++){
            this->pointer[x][i] = nullptr;
        }
        int* valuePtr = new int[1];
        *valuePtr = value;
        this->pointer[x][y] = valuePtr;
    } else if (this->pointer[x][y] == nullptr){
        int* valuePtr = new int[1];
        *valuePtr = value;
        this->pointer[x][y] = valuePtr;
    } else {
        int* valuePtr = new int[1];
        *valuePtr = value;
        delete this->pointer[x][y];
        this->pointer[x][y] = valuePtr;
    }
}

int Matrix::getValue(int x, int y) {
    if (!(this->pointer[x] == nullptr || this->pointer[x][y] == nullptr)){
        int* val = this->pointer[x][y];
        return *val;
    } else {
        setValue(0, x, y);
        return 0;
    }
}

void Matrix::multiplyRowAndSumTo(int row1, int row2, int x) {
    for(int i = 0; i < cols_; i++){
        int mult = getValue(row1, i) * x;
        setValue(mult + getValue(row2, i),row2,i);
        //std::cout << getValue(row2, i) << " ";
    }
}

Matrix::~Matrix() {
    for(int i = 0; i < rows_; i ++){
        for (int j = 0; j < cols_; j++){
            delete this->pointer[i][j];
        }
        delete this->pointer[i];
    }
    delete this->pointer;
};

/*
void Matrix::allocSpace(){
    pointer = new int*[rows_];
    for(int i = 0; i < rows_;i++){
        pointer[i] = new int[cols_];
    }
}*/
