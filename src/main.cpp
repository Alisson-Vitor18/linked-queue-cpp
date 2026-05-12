#include <iostream>
#include "queue.hpp"

int main() {
    Queue<int> queue;

    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);
    queue.enqueue(40);
    queue.enqueue(50);

    std::cout << "Fila...\n" << std::endl;
    queue.print(std::cout);
    std::cout << "Tamanho: " << queue.size() << std::endl;

    std::cout << "\nRemovendo valor " << queue.front() << " da fila..." << std::endl;
    queue.dequeue();

    std::cout << std::endl;

    std::cout << "Fila...\n" << std::endl;
    queue.print(std::cout);
    std::cout << "Tamanho: " << queue.size() << std::endl;

    std::cout << "\nRemovendo valor " << queue.front() << " da fila..." << std::endl;
    queue.dequeue();

    std::cout << std::endl;

    std::cout << "Fila...\n" << std::endl;
    queue.print(std::cout);
    std::cout << "Tamanho: " << queue.size() << std::endl;

    return 0;
}