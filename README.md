# 📚 Sistema de Gerenciamento de Biblioteca em C

Este projeto é uma aplicação em linguagem **C** que simula um **sistema de biblioteca**, permitindo o gerenciamento de **usuários**, **livros** e **reservas** utilizando **listas encadeadas**. É uma solução simples, feita para fins educacionais, com interface via **linha de comando (terminal)**.

## Objetivo

Desenvolver um sistema que organize e manipule dados de forma eficiente, praticando conceitos como:

- Estruturas (`struct`)
- Listas encadeadas
- Alocação dinâmica de memória (`malloc` e `free`)
- Funções modularizadas
- Entrada e saída formatada de dados
- Organização de menus interativos

---

## Funcionalidades

### 👤 Usuários
- Cadastrar novo usuário
- Alterar informações (nome, endereço, telefone)
- Excluir usuário
- Listar todos os usuários cadastrados

### 📕 Livros
- Cadastrar livro com até 5 autores
- Alterar informações (título, autores, ano, edição, editora)
- Excluir livro
- Excluir autor específico de um livro
- Listar todos os livros cadastrados

### 📅 Reservas
- Criar reserva associando um usuário a um livro com data de início e fim
- Alterar datas de uma reserva
- Excluir reserva
- Listar todas as reservas realizadas

---

## Estrutura do Código

O projeto utiliza uma `struct` principal chamada `Lista`, que armazena três ponteiros para listas encadeadas independentes de:

- `Livro`
- `Usuario`
- `Reserva`

Cada operação (inserção, remoção, alteração e exibição) foi modularizada em funções específicas, garantindo **legibilidade** e **manutenção facilitada**.

---

## ⚙️ Como Compilar e Executar

### Requisitos
- Compilador C (GCC, Clang etc.)

### Compilação e Execução
```bash
gcc -o biblioteca main.c
./biblioteca



