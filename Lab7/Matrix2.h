#ifndef CPP_LABS_MATRIX2_H
#define CPP_LABS_MATRIX2_H


#include <vector>

class Matrix2 {
public:
    class Row {
    public:
        int &operator[](int i);
        Row(int numOfColumns);
        std::vector<int> columns;
    };

    Matrix2(int numOfRows, int numOfColumns);
    bool checkInitialized(int i, int j);
    void multAndAddTo(int src, int dst, int k);
    void print();

    Row &operator[](int i);


    virtual ~Matrix2();

private:
    int numOfRows;
    int numOfColumns;
    std::vector<Row*> rows;

};


#endif //CPP_LABS_MATRIX2_H
