/**
 * @file functions.c
 * @brief Implementação das funções de negócio do sistema SGEF.
 *
 * @details Este arquivo contém as funções responsáveis por cadastrar,
 * buscar, excluir produtos, validar compras, controlar entrada de
 * estoque e exibir produtos com estoque baixo.
 *
 * @author Gabrielly
 * @date 2026
 * @version 1.0
 */

#include <stdio.h>
#include <string.h>

#include "functions.h"

/**
 * @brief Busca o índice de um produto no banco de dados pelo código.
 *
 * @param db Ponteiro para o banco de dados.
 * @param codigo Código do produto a ser buscado.
 *
 * @return int Índice do produto no array, ou -1 se não encontrado.
 */
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

/**
 * @brief Valida e cadastra um produto no banco de dados.
 *
 * @details Verifica código, duplicidade, nome, preço, quantidade,
 * categoria e limite de produtos antes de cadastrar.
 *
 * @param db Ponteiro para o banco de dados.
 * @param produto Estrutura Produto com os dados a cadastrar.
 *
 * @return char* Mensagem de sucesso ou de erro correspondente.
 */
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

/**
 * @brief Exibe todos os produtos cadastrados no banco de dados.
 *
 * @details Imprime no console código, nome, preço, quantidade
 * e categoria de cada produto. Se não houver produtos, exibe aviso.
 *
 * @param db Ponteiro para o banco de dados.
 *
 * @return void
 */
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

/**
 * @brief Exclui um produto do banco de dados pelo código.
 *
 * @details Remove o produto e reorganiza o array para não deixar
 * posições vazias.
 *
 * @param db Ponteiro para o banco de dados.
 * @param codigo Código do produto a ser excluído.
 *
 * @return char* Mensagem de sucesso ou erro se não encontrado.
 */
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

/**
 * @brief Valida e realiza uma compra, reduzindo o estoque.
 *
 * @param db Ponteiro para o banco de dados.
 * @param codigo Código do produto a ser comprado.
 * @param quantidadeDesejada Quantidade que se deseja comprar.
 *
 * @return char* Mensagem de sucesso ou erro (produto não encontrado
 * ou quantidade insuficiente).
 */
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

/**
 * @brief Registra entrada de estoque para um produto existente.
 *
 * @param db Ponteiro para o banco de dados.
 * @param codigo Código do produto que receberá a entrada.
 * @param quantidadeEntrada Quantidade a ser adicionada ao estoque.
 *
 * @return char* Mensagem de sucesso ou erro (quantidade inválida
 * ou produto não encontrado).
 */
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

/**
 * @brief Exibe produtos com quantidade abaixo de um limite definido.
 *
 * @param db Ponteiro para o banco de dados.
 * @param limite Valor mínimo de quantidade. Produtos abaixo disso
 * são exibidos como estoque baixo.
 *
 * @return void
 */
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


