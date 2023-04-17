#ifndef CPP_LAB2_PQUEUE_H
#define CPP_LAB2_PQUEUE_H

#include <vector>
#include <iostream>

template<typename T, int N>
class PriorityQueue {
private:
    std::vector<T> data;
    int maxN;
    bool isMax;

    bool compare(int i, int j) {
        if (isMax)
            return data[i] > data[j];
        else return data[i] < data[j];
    }

    void heapify(int i) {
        int leftChild;
        int rightChild;
        int largestChild;
        int heapSize = data.size();

        while (true) {
            leftChild = 2 * i + 1;
            rightChild = 2 * i + 2;
            largestChild = i;

            if (leftChild < heapSize && compare(leftChild, largestChild)) {
                largestChild = leftChild;
            }

            if (rightChild < heapSize && compare(rightChild, largestChild)) {
                largestChild = rightChild;
            }

            if (largestChild == i) {
                break;
            }

            int temp = data[i];
            data[i] = data[largestChild];
            data[largestChild] = temp;
            i = largestChild;
        }
    }

    void changeHeap(bool isMaxPassed) {
        if (isMaxPassed) {
            isMax = false;
            for (int i = (data.size() - 2) / 2; i >= 0; --i) {
                heapify(i);
            }
        } else {
            isMax = true;
            for (int i = (data.size() - 2) / 2; i >= 0; --i) {
                heapify(i);
            }
        }
    }

public:
    PriorityQueue() {
        isMax = true;
        maxN = N;
    }

    void Enqueue(T item) {
        if (data.size() == maxN) {
            std::cout << "Reached max capacity\n";
            return;
        }

        data.push_back(item);
        int i = data.size() - 1;
        int parent = (i - 1) / 2;

        while (i > 0 && !compare(parent, i) ){
            int temp = data[i];
            data[i] = data[parent];
            data[parent] = temp;
            i = parent;
            parent = (i - 1) / 2;
        }

    }


    T DequeueMax() {
        if (!isMax) {
            changeHeap(isMax);
        }
        T frontItem = data[0];
        data[0] = data[data.size() - 1];
        data.pop_back();
        heapify(0);
        return frontItem;
    }

    T DequeueMin() {
        if (isMax) {
            changeHeap(isMax);
        }
        T frontItem = data[0];
        data[0] = data[data.size() - 1];
        data.pop_back();
        heapify(0);
        return frontItem;
    }

    T PeekMax() {
        if (!isMax) {
            changeHeap(isMax);
        }
        return data[0];
    }

    T PeekMin() {
        if (isMax) {
            changeHeap(isMax);
        }
        return data[0];
    }
};


#endif //CPP_LAB2_PQUEUE_H
