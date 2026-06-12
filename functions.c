#include <stdio.h>
#include <string.h>
#include "functions.h"
#include "database.h"

char* validarCadastroProduto(
    int codigo,
    char nome[],
    float preco,
    int quantidade,
    char categoria,
    int codigos[],
    int qtdProdutos
) {
    if (codigo < 0) {
        return "ERRO: codigo invalido";
    }

    for (i = 0; i < qtdProdutos; i++) {
        if (codigos[i] == codigo) {
            return "ERRO: codigo ja cadastrado";
        }
    }

    if (strlen(nome) == 0) {
        return "ERRO: nome invalido";
    }

    if (preco <= 0) {
        return "ERRO: preco invalido";
    }

    if (quantidade < 0) {
        return "ERRO: quantidade invalida";
    }

    if (categoria != 'A' && categoria != 'H' && categoria != 'M' && categoria != 'C' && categoria != 'E') {
        return "ERRO: categoria invalida";
    }

    return "Cadastro realizado com sucesso";
}



