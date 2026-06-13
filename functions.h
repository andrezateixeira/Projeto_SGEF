#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include "database.h"

int buscarIndiceProduto(int codigo);
char* validarCadastroProduto(
    int codigo,
    char nome[],
    float preco,
    int quantidade,
    char categoria,
    int codigos[],
    int qtdProdutos
);

void mostrarProdutos(void);
char* excluirProduto(int codigo);
char* validarCompra(int codigo, int quantidadeDesejada);


#endif

