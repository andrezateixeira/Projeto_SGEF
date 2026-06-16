/**
 * @file database_stub.c
 * @brief Stubs de banco de dados para uso nos testes unitários.
 *
 * @details Este arquivo contém funções stub que simulam diferentes
 * estados do banco de dados, permitindo testar as funções do sistema
 * sem depender de dados reais.
 *
 * @author Gabrielly
 * @date 2026
 * @version 1.0
 */

#include "database_stub.h"

/**
 * @brief Cria um banco de dados stub genérico vazio.
 *
 * @return Database Estrutura Database com qtdProdutos igual a zero.
 */
Database criarDatabaseStub(void)
{
    Database db;
    db.qtdProdutos = 0;
    return db;
}

/**
 * @brief Cria um banco de dados stub sem nenhum produto cadastrado.
 *
 * @details Usado em testes que precisam de um banco de dados limpo
 * como ponto de partida.
 *
 * @return Database Estrutura Database vazia com qtdProdutos igual a zero.
 */
Database criarDatabaseStubVazio() {
    Database db;
    db.qtdProdutos = 0;
    return db;
}

/**
 * @brief Cria um banco de dados stub com um produto pré-cadastrado.
 *
 * @details Simula um banco com o produto de código 11, nome "A",
 * preço 10, quantidade 5 e categoria 'A'. Usado em testes de
 * duplicidade e busca.
 *
 * @return Database Estrutura Database com 1 produto cadastrado.
 */
Database criarDatabaseStubComUmProduto() {
    Database db;

    db.qtdProdutos = 1;

    db.produtos[0].codigo = 11;
    db.produtos[0].nome[0] = 'A';
    db.produtos[0].nome[1] = '\0';
    db.produtos[0].preco = 10;
    db.produtos[0].quantidade = 5;
    db.produtos[0].categoria = 'A';

    return db;
}

/**
 * @brief Cria um banco de dados stub com dois produtos pré-cadastrados.
 *
 * @details Simula um banco com produtos de códigos 1 e 2.
 * Usado em testes que exigem mais de um produto no banco.
 *
 * @return Database Estrutura Database com 2 produtos cadastrados.
 */
Database criarDatabaseStubComDoisProdutos() {
    Database db;

    db.qtdProdutos = 2;

    db.produtos[0].codigo = 1;
    db.produtos[1].codigo = 2;

    return db;
}
