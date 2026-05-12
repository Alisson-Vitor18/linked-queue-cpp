#include <stdexcept>

template<typename T>
Queue<T>::Node::Node(const T& value, std::unique_ptr<Node> next) 
    : value(value), next(std::move(next)) {}

template<typename T>
bool Queue<T>::empty() const {
    return this->size_queue == 0;
}

template<typename T>
void Queue<T>::enqueue(const T& value) {
    auto new_node = std::make_unique<Node>(value);

    if(empty()) {
        this->head = std::move(new_node);
        this->tail = this->head.get();     
    } else {
        this->tail->next = std::move(new_node);
        this->tail = this->tail->next.get();
    }

    this->size_queue++;
}

template<typename T>
void Queue<T>::dequeue() {
    if(empty()) {
        throw std::runtime_error("A fila está vazia, não é possível remover!");
    }
    this->head = std::move(this->head->next);
    if(this->head == nullptr) {
        this->tail = nullptr;
    }

    this->size_queue--;
}

template<typename T>
void Queue<T>::print(std::ostream& os) const {
    const Node* current = this->head.get();
    bool first = true;

    os << "[";
    for(; current != nullptr; current = current->next.get()) {
        if(!first) os << ", ";
        os << current->value;
        first = false;
    }
    os << "]\n";
}

template<typename T>
T& Queue<T>::front() {
    if(empty()) {
        throw std::runtime_error("A fila está vazia!");
    }

    return this->head->value;
}

template<typename T>
const T& Queue<T>::front() const {
    if(empty()) {
        throw std::runtime_error("A fila está vazia!");
    }
    
    return this->head->value;
}

template<typename T>
std::size_t Queue<T>::size() const {
    return this->size_queue;
}