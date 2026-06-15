#ifndef DATABASE_H
#define DATABASE_H

#define MAX_PRODUTOS 20

typedef struct {
    int codigo;
    char nome[30];
    float preco;
    int quantidade;
    char categoria;
} Produto;

typedef struct {
    Produto produtos[MAX_PRODUTOS];
    int qtdProdutos;
} Database;

Database criarDatabase(void);

#endif
