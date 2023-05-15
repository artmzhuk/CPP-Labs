#ifndef CPP_LABS_SEQ_H
#define CPP_LABS_SEQ_H

#include <vector>
#include <ostream>
#include <iostream>

template<typename T, int N>
class Seq {
public:
    Seq(){
        maxN = N;
    };
    void add(T x) {
        if (data.size() < maxN){
            data.push_back(x);
            std::sort(data.begin(), data.end());
        } else {
            std::cout << "Reached max capacity (" << maxN << ")\n";
        }
    }

    void operator*(int x){
        for (int i = 0; i < data.size(); ++i){
            data[i] *= x;
        }
    }


    void operator+(Seq x){
        this->data.insert(this->data.end(), x.data.begin(), x.data.end());
        std::sort(this->data.begin(), this->data.end());
    }

    T &operator[](int i){
        return data[i];
    }

    friend std::ostream &operator<<(std::ostream &os, const Seq &seq) {
        for (int i = 0; i < seq.data.size(); i++){
            os << seq.data[i] << " ";
        }
        os << "\n";
        return os;
    }

    std::vector<T> data;
private:
    int maxN;
};


#endif //CPP_LABS_SEQ_H
