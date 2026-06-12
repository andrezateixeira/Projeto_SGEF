#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "database.h"

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


#endif

