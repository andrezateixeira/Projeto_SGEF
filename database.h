/**
 * @file database.h
 * @brief Definição das estruturas principais de dados para o sistema de estoque.
 *
 * @details Este arquivo define a estrutura de um Produto, a estrutura do Banco de Dados
 * local (baseado em vetor estático) e as constantes de limite do sistema.
 * @author Allisson
 * @date 2026
 * @version 1.0
 *
 */

#ifndef DATABASE_H
#define DATABASE_H

/**
 * @def MAX_PRODUTOS
 * @brief Define a capacidade máxima de produtos que o banco de dados pode armazenar.
 */
#define MAX_PRODUTOS 20

/**
 * @struct Produto
 * @brief Estrutura que representa um produto no sistema de estoque.
 */
typedef struct {
    int codigo;         /**< Código identificador único do produto (numérico). */
    char nome[30];      /**< Nome ou descrição do produto (máximo 29 caracteres + \0). */
    float preco;        /**< Preço unitário de venda do produto. */
    int quantidade;     /**< Quantidade atual disponível em estoque. */
    char categoria;     /**< Caractere que define a categoria do produto (ex: 'A', 'B'). */
} Produto;

/**
 * @struct Database
 * @brief Estrutura que simula o banco de dados em memória.
 */
typedef struct {
    Produto produtos[MAX_PRODUTOS]; /**< Vetor/array contendo os produtos cadastrados. */
    int qtdProdutos;                 /**< Contador de produtos atualmente armazenados na base. */
} Database;

/**
 * @brief Cria e inicializa um banco de dados zerado.
 *
 * @return Database Retorna uma estrutura Database com a quantidade de produtos inicializada em 0.
 *
 * @note Deve ser chamada no início do programa principal (main) antes de qualquer operação.
 */
Database criarDatabase(void);

#endif
