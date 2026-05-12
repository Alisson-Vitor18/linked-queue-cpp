#pragma once

#include <memory>
#include <ostream>
#include <cstddef>

template<typename T>
class Queue {
    private:
        struct Node {
            T value;
            std::unique_ptr<Node> next;

            //Construtor da classe Node
            Node(const T& value
                ,std::unique_ptr<Node> next = nullptr);
        };
        std::unique_ptr<Node> head = nullptr;
        Node* tail = nullptr;
        std::size_t size_queue = 0;

    public: 
        //Construtor da classe queue
        Queue() = default;

        //Verifica se a fila está vazia
        bool empty() const;

        //Enfileira um novo valor na fila
        void enqueue(const T& value);

        //Remove um valor no início da fila
        void dequeue();

        //Imprime a fila
        void print(std::ostream& os) const;

        // Retorna o início da fila, permitindo modificar
        T& front();

        // Retorna o início da fila apenas para leitura
        const T& front() const;

        //Retorna o tamanho da fila
        std::size_t size() const;
};

#include "queue.tpp"