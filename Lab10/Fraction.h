#ifndef CPP_LABS_FRACTION_H
#define CPP_LABS_FRACTION_H


#include <ostream>
#include <iterator>

class Fractions {
public:
    class fraction {
    public:
        fraction();

        fraction(int num, int denom);

        friend std::ostream &operator<<(std::ostream &os, const fraction &fraction);

        int num;
        int denom;
        int nod;
    };

    int n;
    fraction *array;

    Fractions(int n);

    fraction &operator[](int i);
    static int NOD(int a, int b);

    void print();

    struct Iterator {
        using iterator_category = std::forward_iterator_tag;
        using difference_type = std::ptrdiff_t;
        using value_type = fraction;
        using pointer = fraction *;  // or also value_type*
        using reference = int &; // or also value_type&
        Iterator(pointer ptr) : m_ptr(ptr) {}

        reference operator*() const { return (*m_ptr).nod; }

        pointer operator->() { return m_ptr; }

        Iterator &operator++() {
            m_ptr++;
            return *this;
        }

        Iterator operator++(int) {
            Iterator tmp = *this;
            ++(*this);
            return tmp;
        }

        friend bool operator==(const Iterator &a, const Iterator &b) { return a.m_ptr == b.m_ptr; };

        friend bool operator!=(const Iterator &a, const Iterator &b) { return a.m_ptr != b.m_ptr; };

    private:
        pointer m_ptr;
    };

    Iterator begin() { return Iterator(&array[0]); }

    Iterator end() {
        return Iterator(&array[n]);
    };

};
#endif //CPP_LABS_FRACTION_H
