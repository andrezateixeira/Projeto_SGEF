#include <stdio.h>
#include <string.h>
#include "functions.h"
#include "database.h"

int i;

int buscarIndiceProduto(int codigo) {
    int i;
    for (i = 0; i < db.qtdProdutos; i++) {
        if (db.codigos[i] == codigo) {
            return i; 
        }
    }
    return -1; 
}

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

    if (categoria != 'A' && categoria != 'C' && categoria != 'E' && categoria != 'H' && categoria != 'M') {
        return "ERRO: categoria invalida";
    }

	db.codigos[db.qtdProdutos] = codigo;
    strcpy(db.nomes[db.qtdProdutos], nome);
    db.precos[db.qtdProdutos] = preco;
    db.quantidades[db.qtdProdutos] = quantidade;
    db.categorias[db.qtdProdutos] = categoria;
    db.qtdProdutos++;

    return "Cadastro realizado com sucesso";
}

void mostrarProdutos() {
    if(db.qtdProdutos == 0) {
        printf("Nenhum produto cadastrado.\n");
    } else {
        printf("\nPRODUTOS CADASTRADOS:\n");
        for(i = 0; i < db.qtdProdutos; i++) {
            printf("\nProduto %d\n", i + 1);
            printf("Codigo: %d\n", db.codigos[i]);
            printf("Nome: %s\n", db.nomes[i]);
            printf("Preco: R$ %.2f\n", db.precos[i]);
            printf("Quantidade: %d\n", db.quantidades[i]);
            printf("Categoria: %c\n", db.categorias[i]);
        }
    }
}

char* excluirProduto(int codigo) {
    int i;
    int posicao = buscarIndiceProduto(codigo);
    
    if (posicao == -1) {
        return "ERRO: Produto nao encontrado";
    }
    
    for (i = posicao; i < db.qtdProdutos - 1; i++) {
        db.codigos[i] = db.codigos[i + 1];
        strcpy(db.nomes[i], db.nomes[i + 1]);
        db.precos[i] = db.precos[i + 1];
        db.quantidades[i] = db.quantidades[i + 1];
        db.categorias[i] = db.categorias[i + 1];
    }
    
    db.qtdProdutos--;
    
    return "Produto excluido com sucesso";
}

char* validarCompra(int codigo, int quantidadeDesejada) {
    int posicao = buscarIndiceProduto(codigo);
    
    if (posicao == -1) {
        return "ERRO: Produto nao encontrado";
    }
    
    if (db.quantidades[posicao] < quantidadeDesejada) {
        return "ERRO: Quantidade insuficiente em estoque";
    }
    
    db.quantidades[posicao] -= quantidadeDesejada;
    
    return "Compra realizada com sucesso";
}
