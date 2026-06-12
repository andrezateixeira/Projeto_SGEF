#ifndef DATABASE_H
#define DATABASE_H

#define MAX_PRODUTOS 30

typedef struct {
    int codigos[MAX_PRODUTOS];
    char nomes[MAX_PRODUTOS][30];
    float precos[MAX_PRODUTOS];
    int quantidades[MAX_PRODUTOS];
    char categorias[MAX_PRODUTOS];
    int qtdProdutos;
} EstoqueDB;

extern EstoqueDB db;


#endif

