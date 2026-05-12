# Fila Encadeada em C++

Este projeto implementa uma fila encadeada em C++ utilizando templates, permitindo o armazenamento genérico de dados. O objetivo é estudar estruturas de dados em C++, também será feito uso da `std::queue` da STL a fins de demonstração.

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

## Complexidade dos métodos implementados

| Método  | Complexidade |
|----|----|              |
| Enqueue |     O(1)     |
| Dequeue |     O(1)     |
| Empty   |     O(1)     |
| Size    |     O(1)     |
| Print   |     O(n)     |

> Onde `n` representa a quantidade de elementos presentes na fila./

---

## Como executar 

```bash
g++ main.cpp -Iincludes -o program
./program
```