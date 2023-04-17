#include <iostream>
#include "PQueue.h"

int main() {
    PriorityQueue<int, 10> test;
    for(int i = 0; i <=9 ; i++){
        test.Enqueue(i);
    }
    std::cout << test.Peek() << std::endl;
    test.Dequeue();
    std::cout << test.Peek() << std::endl;
    test.Enqueue(10);
    std::cout << test.Peek() << std::endl;

    test.Enqueue(10);
    return 0;
}
