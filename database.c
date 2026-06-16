/**
 * @file database.c
 * @brief Implementação da estrutura de banco de dados do sistema SGEF.
 *
 * @details Este arquivo contém a função responsável por inicializar
 * a estrutura de dados principal do sistema de gerenciamento de estoque.
 *
 * @author Gabrielly
 * @date 2026
 * @version 1.0
 */
 
 #include "database.h"

/**
 * @brief Cria e inicializa um banco de dados vazio.
 *
 * @details Inicializa e retorna uma estrutura Database com quantidade
 * de produtos zerada, pronta para uso no sistema.
 *
 * @return Database Uma estrutura Database inicializada e vazia.
 */
Database criarDatabase(void) {
    Database db;
    db.qtdProdutos = 0;
    return db;
}


