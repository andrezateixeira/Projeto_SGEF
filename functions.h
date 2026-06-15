/**
 * @file functions.h
 * @brief Declaração das funções de gerenciamento do sistema de estoque.
 *
 * @details Este arquivo contém os protótipos das funções responsáveis por manipular
 * o estoque, incluindo validação, cadastro, exclusão, compras e relatórios.
 * @author Allisson
 * @date 2026
 * @version 1.0
 *
 */
#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "database.h"

/**
 * @brief Busca o índice de um produto no banco de dados através do código.
 *
 * @param db Ponteiro para a estrutura do banco de dados.
 * @param codigo Código identificador do produto a ser buscado.
 * @return int O índice do produto se for encontrado, ou -1 caso não exista.
 *
 * @note Função essencial para validações de existência de produtos.
 */
int buscarIndiceProduto(Database *db, int codigo);
/**
 * @brief Valida os dados para o cadastro de um novo produto.
 *
 * @param db Ponteiro para a estrutura do banco de dados.
 * @param produto Estrutura contendo os dados do produto a ser validado.
 * @return char* Retorna uma string com a mensagem de erro ou "SUCESSO".
 *
 * @note Verifica critérios como código negativo, duplicado, nome vazio e preços inválidos.
 */
char* validarCadastroProduto(Database *db, Produto produto);
/**
 * @brief Exibe na tela a listagem de todos os produtos cadastrados.
 *
 * @param db Ponteiro para a estrutura do banco de dados.
 * @return void
 *
 * @note Mostra formatado o código, nome, quantidade e preço de cada item.
 */
void mostrarProdutos(Database *db);
/**
 * @brief Realiza a exclusão lógica ou física de um produto do sistema.
 *
 * @param db Ponteiro para a estrutura do banco de dados.
 * @param codigo Código do produto que será removido.
 * @return char* Retorna uma string confirmando a exclusão ou apontando erro.
 *
 * @note Caso o produto não exista, deve retornar um erro específico.
 */
char* excluirProduto(Database *db, int codigo);
/**
 * @brief Valida se uma operação de compra pode ser realizada.
 *
 * @param db Ponteiro para a estrutura do banco de dados.
 * @param codigo Código do produto que se deseja comprar.
 * @param quantidadeDesejada Quantidade que o cliente deseja adquirir.
 * @return char* Retorna "SUCESSO" ou o erro correspondente (ex: estoque insuficiente).
 *
 * @note Verifica se o produto existe e se há estoque suficiente antes de abater.
 */
char* validarCompra(Database *db,int codigo,int quantidadeDesejada);
/**
 * @brief Realiza a entrada/reposição de estoque de um produto existente.
 *
 * @param db Ponteiro para a estrutura do banco de dados.
 * @param codigo Código do produto que receberá as novas unidades.
 * @param quantidadeEntrada Quantidade de itens a ser somada ao estoque atual.
 * @return char* Retorna uma string de sucesso ou mensagem de erro.
 *
 * @note A quantidade de entrada deve ser estritamente positiva.
 */
char* entradaEstoque(Database *db, int codigo,int quantidadeEntrada);
/**
 * @brief Exibe uma listagem com os produtos que estão abaixo do limite estipulado.
 *
 * @param db Ponteiro para a estrutura do banco de dados.
 * @param limite Quantidade mínima usada como linha de corte para o alerta.
 * @return void
 *
 * @note Caso nenhum produto esteja abaixo do limite, exibe uma mensagem informativa.
 */
void mostrarProdutosEstoqueBaixo(Database *db, int limite);

#endif
