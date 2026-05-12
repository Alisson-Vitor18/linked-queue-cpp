#pragma once
#include <memory>

template<typename T>
class Queue {
    private:
        struct Node {
            T value;
            std::unique_ptr<Node> next;

            //Construtor da classe Node
            Node(const T& value
                ,std::unique_ptr<Node> next = nullptr);
        }
        std::unique_ptr<Node> head = nullptr;
        std::unique_ptr<Node> tail = nullptr;
        size_t size_queue = 0;

    public: 
        //Construtor da classe queue
        Queue();

        //Verifica se a fila está vazia
        bool empty() const;

        //Enfileira um novo valor na fila
        void enqueue(const T& value);

        //Remove um valor no início da fila
        void dequeue();

        //Imprime a fila
        void print(const std::ostream& os) const;

        //Retorna o início da fila
        T& head();

        //Retorna o tamanho da fila
        std::size_t size() const;
};