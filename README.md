📚 Sistema de Gerenciamento de Biblioteca
Este projeto em linguagem C implementa um sistema de gerenciamento de biblioteca simples baseado em listas encadeadas. O sistema permite cadastrar, alterar, listar e excluir usuários, livros e reservas de forma dinâmica via terminal, utilizando menus interativos.

-Estrutura do Projeto
Usuários: Cadastro com ID, nome, endereço e telefone.
Livros: Armazenam ID, título, até 5 autores (com nome e instituição), ano, edição e editora.
Reservas: Associações entre usuários e livros, com datas de início e fim.

-Funcionalidades Implementadas
Cadastro de usuários, livros e reservas.
Alteração de dados de usuários, livros (inclusive autores) e reservas.
Exclusão de registros (com validação por ID).
Relatórios listando todos os usuários, livros e reservas cadastrados.
Gerenciamento de memória dinâmica, evitando vazamentos.
Interface por menus no terminal, facilitando a navegação.

-Estruturas de Dados Utilizadas
Listas encadeadas separadas para:
Usuários
Livros
Reservas

Cada tipo possui ponteiros independentes dentro de uma struct principal Lista, otimizando a organização do sistema.

-Como Executar?
Compile o código com:
        gcc -o biblioteca main.c
Execute:
        ./biblioteca
