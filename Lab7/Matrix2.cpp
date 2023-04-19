#include "Matrix2.h"
#include <climits>
#include <iostream>

Matrix2::Matrix2(int numOfRows, int numOfColumns) : numOfRows(numOfRows), numOfColumns(numOfColumns){
    rows = std::vector<Row*>(numOfRows);
    for(int i = 0; i < numOfRows; i++){
        rows[i] = new Row(numOfColumns);
    }
}


Matrix2::Row::Row(int numOfColumns) {
    columns = std::vector<int>(numOfColumns, INT_MAX);
}

int &Matrix2::Row::operator[](int i) {
    if (this->columns[i] == INT_MAX){
        this->columns[i] = 0;
    }
    return this->columns[i];
}

Matrix2::Row &Matrix2::operator[](int i){
    return *rows[i];
}

bool Matrix2::checkInitialized(int i, int j) {
    if(rows[i]->columns[j] == INT_MAX){
        return false;
    } else {
        return true;
    }
}

void Matrix2::multAndAddTo(int src, int dst, int k) {
    for(int i = 0; i < numOfColumns; ++i){
        rows[dst]->columns[i] += rows[src]->columns[i] * k;
    }
}

void Matrix2::print() {
    for(int i = 0; i < numOfRows; ++i){
        for(int j = 0; j < numOfColumns; ++j){
            std::cout << rows[i]->columns[j] << " ";
        }
        std::cout << std::endl;
    }
}

Matrix2::~Matrix2() {
    for(int i = 0; i < numOfRows; i++){
        delete rows[i];
    }
}
