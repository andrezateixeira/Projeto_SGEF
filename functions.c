/**
 * @file functions.c
 * @brief Biblioteca simples de operações matemáticas.
 *
 * @details Este arquivo contém funções básicas para realizar soma e divisão de dois números.
 * @author Malu
 * @date 2026
 * @version 1.0
 *
 */

#include <stdio.h>
#include <string.h>
#include "functions.h"
#include "database.h"

int i;

/**
 * @brief Realiza a soma de dois números inteiros
 *
 * @param codigo O primeiro valor inteiro
 * @return int O resultado da soma entre @v1 e @v2
 *
 * @note Os parâmetros podem ser positivos ou negativos
 */
 
int buscarIndiceProduto(int codigo) {
    int i;
    for (i = 0; i < db.qtdProdutos; i++) {
        if (db.codigos[i] == codigo) {
            return i; 
        }
    }
    return -1; 
}

/**
 * @brief Realiza a soma de dois números inteiros
 *
 * @param codigo O primeiro valor inteiro
 * @param nome O segundo valor inteiro
 * @param preco O primeiro valor inteiro
 * @param quantidade O segundo valor inteiro
 * @param categoria O primeiro valor inteiro
 * @param codigos O segundo valor inteiro
 * @param qtdProdutos O primeiro valor inteiro
 * @return char* O resultado da soma entre @v1 e @v2
 *
 * @note Os parâmetros podem ser positivos ou negativos
 */

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

char* entradaEstoque(int codigo, int quantidadeEntrada) {
    if (quantidadeEntrada <= 0) {
        return "ERRO: Quantidade invalida para entrada";
    }
    
    int posicao = buscarIndiceProduto(codigo);
    
    if (posicao == -1) {
        return "ERRO: Produto nao encontrado";
    }
    
    db.quantidades[posicao] += quantidadeEntrada;
    
    return "Entrada realizada com sucesso";
}

void mostrarProdutosEstoqueBaixo(int limite) {
    int encontrou = 0;
    printf("\n=== PRODUTOS COM ESTOQUE BAIXO (menor que %d) ===\n", limite);
    for(i = 0; i < db.qtdProdutos; i++) {
        if(db.quantidades[i] < limite) {
            printf("Codigo: %d, Nome: %s, Quantidade: %d\n", 
                   db.codigos[i], db.nomes[i], db.quantidades[i]);
            encontrou = 1;
        }
    }
    if(encontrou != 1) {
        printf("Nenhum produto com estoque baixo.\n");
    }
}
