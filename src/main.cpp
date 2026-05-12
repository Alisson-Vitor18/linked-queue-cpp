#include <iostream>
#include "queue.hpp"

int main() {
    Queue<int> queue;

    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);
    queue.enqueue(40);
    queue.enqueue(50);

    std::cout << "Removendo valor " << queue.front() << " da fila..." << std::endl;
    queue.dequeue();

    queue.print(std::cout);

    return 0;
}