#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>


typedef struct{
    char nome[100];
    char instituicao[100];
}Autor;

typedef struct{
    int identificador;
    char titulo[100];
    Autor autores[5];
    int ano;
    int numAutores;
    int edicao;
    char editora[100];
}Livro;

typedef struct{
    int identificador;
    char nome[100];
    char endereco[100];
    long long int telefone;
}Usuario;

typedef struct{
    int dia, mes, ano;
}Data;

typedef struct{
    Data dataInicio;
    Data dataFim;
    int idUsuario;
    int idLivro;
}Reserva;

typedef struct no{
    Livro livro;
    struct no *proximoLivro;
    Usuario usuario;
    struct no *proximoUsuario;
    Reserva reserva;
    struct no *proximoReserva; //ponteiro para o proximo valor
}No;

typedef struct{//um ponteiro para um no
    No *inicioLivro;
    No *inicioUsuario;
    No *inicioReserva;
}Lista;

void criar_lista(Lista *lista){
    lista->inicioLivro = NULL;
    lista->inicioUsuario = NULL;
    lista->inicioReserva = NULL;
}
//funcao para incluir usuario
void incluirUsuario(Lista *lista, Usuario usuario){
No *novo = malloc(sizeof(No));
     if(novo){
        novo->usuario = usuario;
        novo->proximoUsuario = lista->inicioUsuario;
        lista->inicioUsuario = novo;
        printf("\nUsuário inserido com sucesso!\n");
     }else{
        printf("\nErro ao alocar memória.\n");
    }
}
//funcao para excluir usuario
void excluirUsuario(Lista *lista, int identificador){
No *atual = lista->inicioUsuario, *anterior = NULL;

    while (atual && atual->usuario.identificador != identificador) {
        anterior = atual;
        atual = atual->proximoUsuario;
    }

    if (atual) {
        if (anterior == NULL) {
            lista->inicioUsuario = atual->proximoUsuario;
        }
        else
        {
            anterior->proximoUsuario = atual->proximoUsuario;
        }
        free(atual);
        printf("\nUsuário com ID %d excluído com sucesso!\n", identificador);
        }
        else
        {
        printf("\nUsuário com ID %d não encontrado.\n", identificador);
        }
}
//relatorio das informacoes do usuario
void exibirInformacoesUsuario(Usuario *usuario){
    printf("\n\tInformações do Usuário com ID %d: ", usuario->identificador);
    printf("\n\tNome: %s", usuario->nome);
    printf("\tEndereço: %s", usuario->endereco);
    printf("\tTelefone: %lld\n", usuario->telefone);
}

//funcao para alterar informacoes do usuario
void alterarUsuario(Lista *lista, int identificador){
No *atual = lista->inicioUsuario;

    while(atual){
        if(atual->usuario.identificador == identificador){
            int op;

            do{
                exibirInformacoesUsuario(&atual->usuario);

                printf("\n\tOpções para alteração:");
                printf("\n\t1 - Nome");
                printf("\n\t2 - Endereço");
                printf("\n\t3 - Telefone");
                printf("\n\t0 - Sair");

                printf("\n\tDigite o campo que deseja alterar: ");
                scanf("%d", &op);
                getchar();

        switch(op){
        case 1:
                printf("Digite um novo nome: ");
                fgets(atual->usuario.nome, 100, stdin);
                break;
        case 2:
                printf("Digite um novo endereço: ");
                fgets(atual->usuario.endereco, 100, stdin);
                break;
        case 3:
                printf("Digite um novo telefone: ");
                scanf("%lld", &atual->usuario.telefone);
                break;
        case 0:
                break;
        default:
                printf("\nOpção inválida.\n");
                break;
}
}while(op != 0);

            printf("\nInformações alteradas com sucesso!\n");
            return;
        }
        else
        {
        atual = atual->proximoUsuario;
        }
    }
    printf("\nUsuário com ID %d não encontrado.\n", identificador);
}
//funcao para imprimir informacoes do usuario
void imprimirListaUsuario(Lista lista){
No *no = lista.inicioUsuario;

    printf("\n\tLista de usuários: \n");
    while(no){ //diferente de null
        printf("\n\tID: %d", no->usuario.identificador);
        printf("\n\tNOME: %s", no->usuario.nome);
        printf("\tENDEREÇO: %s", no->usuario.endereco);
        printf("\tTELEFONE: %lld\n", no->usuario.telefone);
        no = no->proximoUsuario; //vai para o proximo no da lista
    }
    printf("\n\n");
}

//funcao para incluir livro
void incluirLivro(Lista *lista, Livro livro){
No *novo = malloc(sizeof(No));
    if(novo){
        novo->livro = livro;
        novo->proximoLivro = lista->inicioLivro;
        lista->inicioLivro = novo;

    printf("\nLivro %d inserido com sucesso!\n", livro.identificador);
}   else
    {
    printf("\nErro ao alocar memória.\n");
    }

}
//relatorio das informacoes do livro
void exibirInformacoesLivro(Livro *livro){
    printf("\n\tInformações do Livro com ID %d: ", livro->identificador);
    printf("\n\tTítulo: %s", livro->titulo);

    printf("\tAutores: \n");
    for(int i = 0; i < livro->numAutores; i++){
    printf("\t %d - %s", i+1, livro->autores[i].nome);
    printf("\t Instituição: %s", livro->autores[i].instituicao);
    }
    printf("\tAno: %d", livro->ano);
    printf("\n\tEdição: %d", livro->edicao);
    printf("\n\tEditora: %s\n", livro->editora);
}
//funcao para alterar informacoes do livro
void alterarLivro(Lista *lista, int idLivro){
    No *atual = lista->inicioLivro;

    while(atual){
    if(atual->livro.identificador == idLivro){
    int op;
            do{
                exibirInformacoesLivro(&atual->livro);

                printf("\n\tOpções para alteração:");
                printf("\n\t1 - Título");
                printf("\n\t2 - Autor");
                printf("\n\t3 - Ano");
                printf("\n\t4 - Edição");
                printf("\n\t5 - Editora");
                printf("\n\t0 - Sair");

                printf("\n\tDigite o campo que deseja alterar: ");
                scanf("%d", &op);
                getchar();

                switch(op){
                case 1:
                    printf("\nDigite um novo título: ");
                    fgets(atual->livro.titulo,100, stdin);

                    break;
                case 2:
                    for(int i = 0; i < atual->livro.numAutores; i++){
                    printf("\nDigite um novo autor: ");
                    fgets(atual->livro.autores[i].nome, 100, stdin );
                    atual->livro.autores[i].nome[strcspn(atual->livro.autores[i].nome, "\n")] = '\0';

                    printf("\nDigite uma nova instituição: ");
                    fgets(atual->livro.autores[i].instituicao, 100, stdin);
                    }
                    break;
                case 3:
                    printf("\nDigite um novo ano: ");
                    scanf("%d", &atual->livro.ano);
                    break;
                case 4:
                    printf("\nDigite uma nova edição: ");
                    scanf("%d", &atual->livro.edicao);
                    break;
                case 5:
                    printf("\nDigite uma nova editora: ");
                    fgets(atual->livro.editora, 100, stdin);
                    break;
                case 0:
                    break;
                default:
                    printf("\nOpção inválida.\n");
                    break;
}
}while(op != 0);

        printf("\nInformações alteradas com sucesso!\n");
        return;
        }
        else
        {
            atual = atual->proximoLivro;
        }
    }
    printf("\nUsuário com ID %d não encontrado.\n", idLivro);
}
//funcao para excluir informacoes do livro
void excluirLivro(Lista *lista, int identificador){
No *atual = lista->inicioLivro, *anterior = NULL;

    while (atual && atual->livro.identificador != identificador) {
        anterior = atual;
        atual = atual->proximoLivro;
    }

    if (atual) {
        if (anterior == NULL) {
            lista->inicioLivro = atual->proximoLivro;
        }
        else
        {
            anterior->proximoLivro = atual->proximoLivro;
        }
        free(atual);
        printf("\nLivro com ID %d excluído com sucesso!\n", identificador);
    }
        else
    {
        printf("\nLivro com ID %d não encontrado.\n", identificador);
    }
}
//funcao para imprimir informacoes do livro
void imprimirListaLivro(Lista lista){
No *no = lista.inicioLivro;

    printf("\n\tLista de livros:\n");
    while(no){ //diferente de null
        printf("\n\tID: %d", no->livro.identificador);
        printf("\n\tTítulo: %s", no->livro.titulo);
        printf("\tAno: %d", no->livro.ano);
        printf("\n\tEdição: %d", no->livro.edicao);
        printf("\n\tEditora: %s", no->livro.editora);

        printf("\tAutores:\n");
        for(int i = 0; i < no->livro.numAutores; i++){
                printf("\t  %s - %s", no->livro.autores[i].nome, no->livro.autores[i].instituicao);
        }
        no = no->proximoLivro; //vai para o proximo no da lista
    }
    printf("\n\n");
}
//funcao para incluir informacoes da reserva
void incluirReserva(Lista *lista, Reserva reserva){
No *novo = malloc(sizeof(No));
    if(novo){
        novo->reserva = reserva;
        novo->proximoReserva = lista->inicioReserva;
        lista->inicioReserva = novo;
        printf("\nReserva realizada com sucesso!\n");
    }
    else
    {
        printf("\nErro ao alocar memoria.\n");
    }
}
//funcao para excluir informacoes da reserva
void excluirReserva(Lista *lista, int idUsuario){
No *atual = lista->inicioReserva, *anterior = NULL;

    while (atual && atual->reserva.idUsuario != idUsuario) {
        anterior = atual;
        atual = atual->proximoReserva;
    }

    if (atual) {
        if (anterior == NULL) {
            lista->inicioReserva = atual->proximoReserva;
        }
        else
        {
            anterior->proximoReserva = atual->proximoReserva;
        }
        free(atual);
        printf("\nReserva do usuário com ID %d excluída com sucesso!\n", idUsuario);
    } else {
        printf("\nReserva do usuário com ID %d não encontrada.\n", idUsuario);
    }
}
//funcao para exibir informacoes da reserva
void exibirReserva(Reserva *reserva){
    printf("\n\tInformações da Reserva com id %d: \n", reserva->idUsuario);
    printf("\n\tData de início: %d / %d / %d", reserva->dataInicio.dia, reserva->dataInicio.mes, reserva->dataInicio.ano);
    printf("\n\tData de fim: %d / %d / %d\n", reserva->dataFim.dia, reserva->dataFim.mes, reserva->dataFim.ano);
}
//funcao para alterar informacoes da reserva
void alterarReserva(Lista *lista, int idUsuario){
No *atual = lista->inicioReserva;

    while(atual){
        if(atual->reserva.idUsuario == idUsuario){
            int op;

            do{
                exibirReserva(&atual->reserva);

                printf("\n\tOpções para alteracao:");
                printf("\n\t1 - Data de início");
                printf("\n\t2 - Data de fim");
                printf("\n\t0 - Sair");

                printf("\nDigite o campo que deseja alterar: ");
                scanf("%d", &op);

                switch(op){
                case 1:
                    printf("Digite um nova data de início(dd/mm/aaaa): ");
                    scanf("%d%d%d", &atual->reserva.dataInicio.dia, &atual->reserva.dataInicio.mes, &atual->reserva.dataInicio.ano);
                    break;
                case 2:
                    printf("Digite um nova data de fim(dd/mm/aaaa): ");
                    scanf("%d%d%d", &atual->reserva.dataFim.dia, &atual->reserva.dataFim.mes, &atual->reserva.dataFim.ano);
                    break;
                case 0:
                    break;

                default:
                    printf("\nOpcão inválida.\n");
                    break;
                }

            }while(op != 0);

            printf("\nInformações alteradas com sucesso!\n");
            return;
        }else{
            atual = atual->proximoReserva;
        }
    }
    printf("\nUsuário com ID %d não encontrado.\n", idUsuario);
}
//funcao para imprimir as informacoes da reserva
void imprimirListaReserva(Lista lista){
    No *no = lista.inicioReserva;

    printf("\n\tLista de reservas: ");
    while(no){ //diferente de null
        printf("\n\t ID do usuário: %d\n", no->reserva.idUsuario);
        printf("\t ID do livro: %d\n", no->reserva.idLivro);
        printf("\t Data de início: %d / %d / %d\n", no->reserva.dataInicio.dia, no->reserva.dataInicio.mes, no->reserva.dataInicio.ano);
        printf("\t Data de Fim: %d / %d / %d\n", no->reserva.dataFim.dia, no->reserva.dataFim.mes, no->reserva.dataFim.ano);

        no = no->proximoReserva; //vai para o proximo no da lista
    }
    printf("\n\n");
}
void liberar_memoriaUsuario(Lista *lista) {
    No *atual = lista->inicioUsuario;
    while (atual) {
        No *prox = atual->proximoUsuario;
        free(atual);
        atual = prox;
    }
}
void liberar_memoriaLivro(Lista *lista) {
    No *atual = lista->inicioLivro;
    while (atual) {
        No *prox = atual->proximoLivro;
        free(atual);
        atual = prox;
    }
}
void liberar_memoriaReserva(Lista *lista) {
//funcao para excluir autor do livro
    No *atual = lista->inicioReserva;
    while (atual) {
        No *prox = atual->proximoReserva;
        free(atual);
        atual = prox;
    }
}
void excluirAutorLivro(Lista *lista, int idLivro) {
    No *atual = lista->inicioLivro;


    while (atual) {
        if (atual->livro.identificador == idLivro) {
            int numAutores = atual->livro.numAutores;

            // Exibir os autores do livro
            for (int i = 0; i < numAutores; i++) {
                printf("%d - %s\n", i + 1, atual->livro.autores[i].nome);
            }

            int opcao;
                printf("Digite o número do autor que deseja excluir (0 para ir): ");
                scanf("%d", &opcao);

            if (opcao >= 1 && opcao <= numAutores) {
                // Deslocar os autores para preencher a posição excluída
            for (int i = opcao - 1; i < numAutores - 1; i++) {
                strcpy(atual->livro.autores[i].nome, atual->livro.autores[i + 1].nome);
                strcpy(atual->livro.autores[i].instituicao, atual->livro.autores[i + 1].instituicao);
                }

                // Atualizar o número de autores
                atual->livro.numAutores--;

                printf("Autor excluído com sucesso!\n");
            } else if (opcao != 0) {
                printf("Opção inválida!\n");
            }
    return;
        } else {
            atual = atual->proximoLivro;
        }
    }
    printf("Livro com ID %d não encontrado.\n", idLivro);
}

int main(){
    Lista lista;
    criar_lista(&lista);
    setlocale(LC_ALL, "Portuguese");

    Livro livro;
    Usuario usuario;
    Reserva reserva;

    int opcao, op1, op2, op3, op4, id;

    do{
            printf("Escolha uma opção: \n");
            printf("1 - Usuário\n");
            printf("2 - Livro\n");
            printf("3 - Reserva\n");
            printf("4 - Relatórios\n");
            printf("5 - Sair\n");

            scanf("%d", &opcao);


    switch(opcao){
    case 1: //usuario
        do{
            printf("1 - Incluir usuário\n");
            printf("2 - Excluir usuário\n");
            printf("3 - Alterar informação do usuário\n");
            printf("0 - Sair\n");

            scanf("%d", &op1);

        switch(op1){
        case 1: //incluir usuario
            printf("Digite o ID do Usuário: \n");
            scanf("%d", &usuario.identificador);
            getchar();
            printf("Digite o nome: \n");
            fgets(usuario.nome, 100, stdin);
            printf("Digite o endereço: \n");
            fgets(usuario.endereco, 100, stdin);
            printf("Digite o telefone: \n");
            scanf("%lld", &usuario.telefone);

            incluirUsuario(&lista, usuario);
            system("pause");
            system("cls");
            break;
        case 2: //excluir usuario
            printf("Digite o ID do usuário que deseja excluir: ");
            scanf("%d", &id);
            excluirUsuario(&lista, id);
            system("pause");
            system("cls");
            break;
        case 3: //alterar usuario
            printf("Digite o ID do usuário que deseja alterar informações: ");
            scanf("%d", &id);
            alterarUsuario(&lista, id);
            system("pause");
            system("cls");
            break;
        case 0: //sair
            break;

}
}
while(op1 != 0);
break;

     case 2: //livro
            do{
            printf("\nEscolha uma opção: \n");
            printf("\n1 - Incluir livro");
            printf("\n2 - Excluir livro");
            printf("\n3 - Alterar informações do livro");
            printf("\n4 - Excluir autor do livro");
            printf("\n0 - Sair\n");

            scanf("%d", &op2);

            switch(op2){

        case 1: //incluir livro
            printf("\nDigite o ID do livro:\n");
            scanf("%d", &livro.identificador);
            getchar();

            printf("\nDigite o título do livro:\n");
            fgets(livro.titulo, 100, stdin);

            printf("\nQuantos autores o livro possui?\n");
            scanf("%d", &livro.numAutores);
            getchar();

                for(int i = 0; i < livro.numAutores; i++){

                printf("\nDigite o autor %d do livro:\n", i + 1);
                fgets(livro.autores[i].nome, 100, stdin);
                livro.autores[i].nome[strcspn(livro.autores[i].nome, "\n")] = '\0';

                printf("\nDigite a instituição do autor %d: \n", i + 1);
                fgets(livro.autores[i].instituicao, 100, stdin);
}
            printf("\nDigite o ano do livro:\n");
            scanf("%d", &livro.ano);

            printf("\nDigite a edição do livro:\n");
            scanf("%d", &livro.edicao);
            getchar();

            printf("\nDigite a editora do livro:\n");
            fgets(livro.editora, 100, stdin);

            incluirLivro(&lista, livro);
            system("pause");
            system("cls");
            break;

        case 2: //excluir livro
            printf("\nDigite o ID do livro que deseja excluir: ");
            scanf("%d", &id);
            excluirLivro(&lista, id);
            system("pause");
            system("cls");
            break;

        case 3: //alterar livro
            printf("\nDigite o ID do livro que deseja alterar as informações: ");
            scanf("%d", &id);
            alterarLivro(&lista, id);
            system("pause");
            system("cls");
            break;

        case 4: //excluir autor do livro
            printf("\nDigite o ID do livro do qual deseja excluir um autor:\n");
            scanf("%d", &id);

            excluirAutorLivro(&lista, id);

            system("pause");
            system("cls");
            break;
        // ...
        case 0: //sair
            break;

        default:
            printf("\nOpção inválida.");
            break;
}
}
while(op2 != 0);
break;

    case 3: //reserva
         do{
            printf("\n\tEscolha uma opção:");
            printf("\n\t1 - Incluir Reserva");
            printf("\n\t2 - Excluir Reserva");
            printf("\n\t3 - Alterar Reserva");
            printf("\n\t0 - Sair\n");

            scanf("%d", &op3);

        switch(op3){

        case 1: //incluir reserva

            printf("Digite o ID do Usuário: \n");
            scanf("%d", &reserva.idUsuario);
            getchar();
            printf("Digite o ID do livro: \n");
            scanf("%d", &reserva.idLivro);
            printf("Digite a data de início (dd/mm/aaaa): \n");
            scanf("%d%d%d", &reserva.dataInicio.dia, &reserva.dataInicio.mes, &reserva.dataInicio.ano);
            printf("Digite a data de fim (dd/mm/aaaa): \n");
            scanf("%d%d%d", &reserva.dataFim.dia, &reserva.dataFim.mes, &reserva.dataFim.ano);

            incluirReserva(&lista, reserva);
            system("pause");
            system("cls");
            break;

        case 2: //excluir reserva
            printf("Digite o ID do usuário da reserva que deseja excluir: ");
            scanf("%d", &id);
            excluirReserva(&lista, id);
            system("pause");
            system("cls");
            break;

        case 3: //alterar reserva
            printf("\nDigite o ID do usuário que deseja alterar a reserva: ");
            scanf("%d", &id);
            alterarReserva(&lista, id);
            system("pause");
            system("cls");
            break;
        case 0: //sair
            break;
        default:
            printf("\nOpção inválida.");
            break;
}
}
while(op3 != 0);
break;

    case 4: //exibir informacoes
         do{
            printf("\n\tEscolha uma opção:");
            printf("\n\t1 - Lista de Usuários");
            printf("\n\t2 - Lista de Livros");
            printf("\n\t3 - Lista de Reservas");
            printf("\n\t0 - Sair\n");

            scanf("%d", &op4);

        switch(op4){
        case 1: //informacoes usuario
            imprimirListaUsuario(lista);
            system("pause");
            system("cls");
            break;
        case 2: //informacoes livro
            imprimirListaLivro(lista);
            system("pause");
            system("cls");
            break;
        case 3: //informacoes reserva
            imprimirListaReserva(lista);
            system("pause");
            system("cls");
            break;

        case 0: //sair
            break;
        default:
            printf("\nOpção inválida.");
            break;
            }

}
while(op4 != 0);
break;

    case 5:
    break;

    default:
    printf("\nOpção inválida.");

     }
}while(opcao != 5);

    liberar_memoriaUsuario(&lista);
    liberar_memoriaLivro(&lista);
    liberar_memoriaReserva(&lista);

 return 0;
}
