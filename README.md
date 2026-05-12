![C++](https://img.shields.io/badge/C%2B%2B-17-blue)

# Fila Encadeada em C++

Este projeto implementa uma fila encadeada em C++ utilizando templates, permitindo o armazenamento genérico de dados. O objetivo é estudar estruturas de dados em C++. Também é demonstrado o uso da `std::queue` da STL para fins de comparação e demonstração.

---

## O que é uma fila encadeada

Filas encadeadas são estruturas de dados que seguem o princípio FIFO (First In, First Out — Primeiro a Entrar, Primeiro a Sair). Elas são amplamente utilizadas na programação em diversas situações do dia a dia, como:

- Sistemas de impressão
- Filas de atendimento em servidores
- Processamento de tarefas assíncronas
- Gerenciamento de requisições HTTP
- Matchmaking em jogos online
- Busca em largura (BFS) em grafos e árvores

Entre muitas outras aplicações importantes no desenvolvimento de software.

### Por que usar estruturas encadeadas?

O principal objetivo de utilizar estruturas encadeadas é a flexibilidade de tamanho, já que não é necessário definir previamente um limite fixo de elementos. Dessa forma, a estrutura pode crescer dinamicamente conforme a necessidade da aplicação, desde que haja memória disponível no sistema.

---

## Funcionalidades 

- Enqueue (insere elementos)
- Dequeue (remove elementos)
- Empty (verifica se está vazia)
- Print (mostra a fila atual)
- Front (retorna o primeiro elemento da fila)
- Size (retorna o tamanho da fila)

---

## Tecnologias utilizadas

- C++
- Templates
- Smart pointers (`std::unique_ptr`)
- Estruturas de dados encadeadas
- STL (`std::queue`)

---

## Complexidade dos métodos implementados

| Método  | Complexidade |
|----------|---------------|
| Enqueue | O(1) |
| Dequeue | O(1) |
| Empty   | O(1) |
| Size    | O(1) |
| Print   | O(n) |

> Onde `n` representa a quantidade de elementos presentes na fila.

---

## Como executar 

```bash
g++ main.cpp -Iincludes -o program
./program
```
---

## Exemplo de uso da implementação própria

```cpp 
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
```

### Saída esperada

```bash
Fila...

[10, 20, 30, 40, 50]
Tamanho: 5

Removendo valor 10 da fila...

Fila...

[20, 30, 40, 50]
Tamanho: 4

Removendo valor 20 da fila...

Fila...

[30, 40, 50]
Tamanho: 3
```

---

## Gerenciamento de memória

Esta implementação utiliza `std::unique_ptr` para gerenciamento automático de memória, seguindo os princípios de RAII (*Resource Acquisition Is Initialization*).

Por utilizar smart pointers da STL, não é necessário liberar memória manualmente com `delete`, já que a destruição dos nós ocorre automaticamente quando deixam de ser utilizados. Dessa forma, a implementação se torna mais segura e reduz o risco de vazamentos de memória (*memory leaks*).

---

## Verificação com Valgrind

O projeto também foi testado com o **Valgrind**, uma ferramenta amplamente utilizada em sistemas Linux para detectar problemas relacionados ao gerenciamento de memória em aplicações C e C++.

Com o Valgrind é possível identificar:
- Vazamentos de memória (*memory leaks*)
- Uso de memória não inicializada
- Acessos inválidos à memória
- Problemas relacionados à desalocação de memória

### Compilando e executando com Valgrind

```bash
g++ src/main.cpp -Iincludes -g -o program
valgrind --leak-check=full ./program
```

### Saída esperada

```bash
==2901== Memcheck, a memory error detector
==2901== Copyright (C) 2002-2022, and GNU GPL'd, by Julian Seward et al.
==2901== Using Valgrind-3.22.0 and LibVEX; rerun with -h for copyright info
==2901== Command: ./program
==2901== 
Fila...

[10, 20, 30, 40, 50]
Tamanho: 5

Removendo valor 10 da fila...

Fila...

[20, 30, 40, 50]
Tamanho: 4

Removendo valor 20 da fila...

Fila...

[30, 40, 50]
Tamanho: 3
==2901== 
==2901== HEAP SUMMARY:
==2901==     in use at exit: 0 bytes in 0 blocks
==2901==   total heap usage: 7 allocs, 7 frees, 74,832 bytes allocated
==2901== 
==2901== All heap blocks were freed -- no leaks are possible
==2901== 
==2901== For lists of detected and suppressed errors, rerun with: -s
==2901== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```

O resultado acima demonstra que, mesmo após a utilização dos métodos implementados, toda a memória alocada foi liberada corretamente, sem ocorrência de vazamentos de memória.

---

## Sobre a std::queue (C++ STL)

A linguagem C++ já fornece uma implementação pronta de fila através da `std::queue`, presente na Standard Template Library (STL). Essa estrutura é amplamente utilizada em aplicações reais, oferecendo uma interface simples e eficiente para operações FIFO (First In, First Out).

No desenvolvimento do dia a dia, o uso de estruturas prontas fornecidas pela linguagem costuma ser a melhor escolha, já que elas são amplamente testadas, otimizadas e facilitam a manutenção do código.

---

### Exemplo de uso com a std::queue

```cpp
#include <iostream>
#include <queue>

void print_queue(std::queue<int> queue);

int main() {
    std::queue<int> queue;

    // Enqueue
    queue.push(10);
    queue.push(20);
    queue.push(30);
    queue.push(40);
    queue.push(50);

    // Front
    std::cout << "Primeiro elemento: "
              << queue.front() << std::endl;

    std::cout << "Último elemento: "
              << queue.back() << std::endl;

    // Size
    std::cout << "Tamanho: "
              << queue.size() << std::endl;

    // Dequeue
    std::cout << "\nElemento removido: "
              << queue.front() << std::endl;

    queue.pop();

    std::cout << "Novo tamanho: "
              << queue.size() << std::endl;

    // Print
    std::cout << "\nFila:" << std::endl;
    print_queue(queue);

    return 0;
}

void print_queue(std::queue<int> queue) {
    bool first = true;

    std::cout << "[";

    while (!queue.empty()) {
        if (!first) {
            std::cout << ", ";
        }

        std::cout << queue.front();
        queue.pop();

        first = false;
    }

    std::cout << "]" << std::endl;
}
```

### Saída esperada

```bash
Primeiro elemento: 10
Último elemento: 50
Tamanho: 5

Elemento removido: 10
Novo tamanho: 4

Fila:
[20, 30, 40, 50]
```

---

## Objetivo do projeto
Este projeto foi desenvolvido **exclusivamente para fins de estudo e demonstração**, com o objetivo de entender como estruturas encadeadas podem ser implementadas em C++.

---

## Conclusão

Embora a implementação própria seja importante para fins educacionais, em projetos reais é sempre recomendado utilizar ferramentas prontas como a `std::queue`, que oferecem maior confiabilidade, manutenção simplificada e integração com o ecossistema da linguagem.

---

## Autor

Desenvolvido por **Alisson Vitor Pereira Barbosa**