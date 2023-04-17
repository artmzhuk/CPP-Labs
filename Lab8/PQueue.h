#ifndef CPP_LAB2_PQUEUE_H
#define CPP_LAB2_PQUEUE_H

#include <vector>
#include <iostream>

template<typename T, int N>
class PriorityQueue {
private:
    std::vector<T> data;
    int maxN;

    void heapify(int i){
        int left = 2*i;
        int right = 2*i+1;
        int size = data.size();
        int largest = i;
        if (left <= size && data[left] > data[largest])
            largest = left;
        if (right <= size && data[right]> data[largest])
            largest = right;
        if (largest!= i){
            T tmp = data[i];
            data[i] = data[largest];
            data[largest] = tmp;
            heapify(largest);
        }
    }
public:
    PriorityQueue(){
        maxN = N;
    }
    void Enqueue(T item) {
        if(data.size() == maxN){
            std::cout << "Reached max capacity\n";
            return;
        }
        data.push_back(item);
        int lastIndex = data.size() - 1;

        while (lastIndex > 0) {
            int indexMiddle = (lastIndex - 1) / 2;
            if (data[lastIndex] <= data[indexMiddle])
                break;
            T tmp = data[lastIndex];
            data[lastIndex] = data[indexMiddle];
            data[indexMiddle] = tmp;
            lastIndex = indexMiddle;
        }
    }


    T Dequeue() {
        int li = data.size() - 1;
        T frontItem = data[0];
        data[0] = data[li];
        data.pop_back();
        heapify(0);
        return frontItem;
    }


    T Peek() {
        T frontItem = data[0];
        return frontItem;
    }

};


#endif //CPP_LAB2_PQUEUE_H
