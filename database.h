/**
 * @file database.h
 * @brief Biblioteca simples de operações matemáticas.
 *
 * @details Este arquivo contém funções básicas para realizar soma e divisão de dois números.
 * @author Malu
 * @date 2026
 * @version 1.0
 *
 */
 
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

/**
 * @brief Realiza a soma de dois números inteiros
 *
 * @param codigo O primeiro valor inteiro
 * @return int O resultado da soma entre @v1 e @v2
 *
 * @note Os parâmetros podem ser positivos ou negativos
 */
 
int stub_buscar_indice_produto(int codigo);

/**
 * @brief Realiza a soma de dois números inteiros
 *
 * @param codigo O primeiro valor inteiro
 * @return int O resultado da soma entre @v1 e @v2
 *
 * @note Os parâmetros podem ser positivos ou negativos
 */
 
int stub_codigo_invalido(int codigo);

/**
 * @brief Realiza a soma de dois números inteiros
 *
 * @param codigo O primeiro valor inteiro
 * @return int O resultado da soma entre @v1 e @v2
 *
 * @note Os parâmetros podem ser positivos ou negativos
 */
  
int stub_codigo_duplicado(int codigo);
/**
 * @brief Realiza a soma de dois números inteiros
 *
 * @param nome O primeiro valor inteiro
 * @return int O resultado da soma entre @v1 e @v2
 *
 * @note Os parâmetros podem ser positivos ou negativos
 */
 
 
int stub_nome_invalido(char nome[]);
/**
 * @brief Realiza a soma de dois números inteiros
 *
 * @param preco O primeiro valor inteiro
 * @return int O resultado da soma entre @v1 e @v2
 *
 * @note Os parâmetros podem ser positivos ou negativos
 */
 
int stub_preco_invalido(float preco);
/**
 * @brief Realiza a soma de dois números inteiros
 *
 * @param quantidade O primeiro valor inteiro
 * @return int O resultado da soma entre @v1 e @v2
 *
 * @note Os parâmetros podem ser positivos ou negativos
 */

int stub_quantidade_invalido(int quantidade);
/**
 * @brief Realiza a soma de dois números inteiros
 *
 * @param categoria O primeiro valor inteiro
 * @return int O resultado da soma entre @v1 e @v2
 *
 * @note Os parâmetros podem ser positivos ou negativos
 */
 
int stub_categoria_invalido(char categoria);
/**
 * @brief Realiza a soma de dois números inteiros
 *
 * @param codigo O primeiro valor inteiro
 * @param quantidadeEntrada O segundo valor inteiro
 * @return int O resultado da soma entre @v1 e @v2
 *
 * @note Os parâmetros podem ser positivos ou negativos
 */
 
int stub_entrada_estoque(int codigo, int quantidadeEntrada);

/**
 * @brief Realiza a soma de dois números inteiros
 *
 * @param limite O primeiro valor inteiro
 * @return int O resultado da soma entre @v1 e @v2
 *
 * @note Os parâmetros podem ser positivos ou negativos
 */
 
int stub_mostrar_produtos_estoque_baixo(int limite);

#endif

