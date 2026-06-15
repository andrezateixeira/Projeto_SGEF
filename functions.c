#include <stdio.h>
#include <string.h>

#include "functions.h"

int buscarIndiceProduto( Database *db, int codigo){
	int i;
    for(i = 0; i < db->qtdProdutos; i++)
    {
        if(db->produtos[i].codigo == codigo)
        {
            return i;
        }
    }
    return -1;
}

char* validarCadastroProduto( Database *db, Produto produto){
    if(produto.codigo < 0)
    {
        return "ERRO: codigo invalido";
    }

    if(buscarIndiceProduto(db,produto.codigo) != -1)
    {
        return "ERRO: codigo ja cadastrado";
    }

    if(strlen(produto.nome) == 0)
    {
        return "ERRO: nome invalido";
    }

    if(produto.preco <= 0)
    {
        return "ERRO: preco invalido";
    }

    if(produto.quantidade < 0)
    {
        return "ERRO: quantidade invalida";
    }

	if(produto.categoria != 'A' && produto.categoria != 'C' && produto.categoria != 'E' && produto.categoria != 'H' && produto.categoria != 'M')
    {
        return "ERRO: categoria invalida";
    }

    if(db->qtdProdutos >= MAX_PRODUTOS)
    {
        return "ERRO: limite de produtos atingido";
    }

    db->produtos[db->qtdProdutos] = produto;
    db->qtdProdutos++;

    return "Cadastro realizado com sucesso";
}

void mostrarProdutos(Database *db)
{
    if(db->qtdProdutos == 0)
    {
        printf("Nenhum produto cadastrado.\n");
        return;
    }

	int i;
    for(i = 0; i < db->qtdProdutos; i++)
    {
        Produto p = db->produtos[i];

        printf("\nProduto %d\n", i + 1);
        printf("Codigo: %d\n", p.codigo);
        printf("Nome: %s\n", p.nome);
        printf("Preco: %.2f\n", p.preco);
        printf("Quantidade: %d\n", p.quantidade);
        printf("Categoria: %c\n", p.categoria);
    }
}

char* excluirProduto(Database *db, int codigo){
    int posicao = buscarIndiceProduto(db, codigo);

    if(posicao == -1){
        return "ERRO: Produto nao encontrado";
    }

	int i;
    for(i = posicao; i < db->qtdProdutos - 1; i++){
        db->produtos[i] = db->produtos[i + 1];
    }

    db->qtdProdutos--;
    
    return "Produto excluido com sucesso";
}

char* validarCompra(Database *db, int codigo, int quantidadeDesejada){
    int posicao = buscarIndiceProduto(db, codigo);

    if(posicao == -1){
        return "ERRO: Produto nao encontrado";
    }

    if(db->produtos[posicao].quantidade< quantidadeDesejada){
        return "ERRO: Quantidade insuficiente em estoque";
    }

    db->produtos[posicao].quantidade -=quantidadeDesejada;

    return "Compra realizada com sucesso";
}

char* entradaEstoque(Database *db, int codigo, int quantidadeEntrada){
    if(quantidadeEntrada <= 0){
        return "ERRO: Quantidade invalida para entrada";
    }

    int posicao =
        buscarIndiceProduto(
            db,
            codigo
        );

    if(posicao == -1)
    {
        return "ERRO: Produto nao encontrado";
    }

    db->produtos[posicao].quantidade +=
        quantidadeEntrada;

    return "Entrada realizada com sucesso";
}

void mostrarProdutosEstoqueBaixo(Database *db, int limite){
    int encontrou = 0;
	int i;
    for(i = 0; i < db->qtdProdutos; i++)
    {
        if(db->produtos[i].quantidade < limite){
            printf("Codigo: %d Nome: %s Quantidade: %d\n", db->produtos[i].codigo, db->produtos[i].nome, db->produtos[i].quantidade);

            encontrou = 1;
        }
    }

    if(!encontrou){
        printf("Nenhum produto com estoque baixo.\n");
    }
}


