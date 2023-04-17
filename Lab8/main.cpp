#include <iostream>
#include "PQueue.h"

int main() {
    PriorityQueue<int, 10> test;
    for(int i = 0; i <=9 ; i++){
        test.Enqueue(i);
    }
    std::cout << test.PeekMin() << std::endl;
    std::cout << test.DequeueMax() << std::endl;
    std::cout << test.PeekMax() << std::endl;
    std::cout << test.PeekMin() << std::endl;
    test.Enqueue(-5);
    std::cout << test.DequeueMin() << std::endl;
    test.Enqueue(100);
    std::cout << test.PeekMax() << std::endl;

    test.Enqueue(105);
    return 0;
}
