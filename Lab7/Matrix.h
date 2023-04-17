//
// Created by artm on 17.4.23.
//

/*17 Целочисленная матрица размера m n, часть
элементов которой может иметь
«неопределённое» значение. Предполагается, что
при создании матрицы все её элементы не
определены. Они становятся определены только
после присваивания им целочисленного значения.
Для матрицы должны быть реализованы
следующие операции:
1. проверка, определён ли элемент с
индексами (i; j);
2. получение ссылки на элемент с индексами
(i; j) (получение ссылки на неопределённый
элемент автоматически присваивает ему
нулевое значение);
3. умножение строки матрицы на число и
прибавление результата к другой строке.
Конструктор матрицы должен принимать в
качестве параметров её размеры m и n.*/

#ifndef CPP_LABS_MATRIX_H
#define CPP_LABS_MATRIX_H


class Matrix {
    public:
    Matrix(int, int);
    virtual ~Matrix();

    int rows_;
    int cols_;
    int ***pointer;

    void allocSpace();
    void create();
    bool checkAlloc(int, int);

    void setValue(int,int,int);
    int getValue(int, int);

    void multiplyRowAndSumTo(int, int,int);

    inline int& operator()(int x, int y) { return *pointer[x][y]; }
};


#endif //CPP_LABS_MATRIX_H
