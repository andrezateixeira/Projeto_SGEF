/**
 * @file database_stub.h
 * @brief Declaração de funções stub para simulação do banco de dados nos testes.
 *
 * @details Este arquivo contém os protótipos das funções que criam cenários controlados 
 * de banco de dados (vazio, com um produto ou múltiplos produtos) para isolar os testes unitários.
 * @author Allisson
 * @date 2026
 * @version 1.0
 *
 */

#ifndef DATABASE_STUB_H
#define DATABASE_STUB_H

#include "database.h"

/**
 * @brief Cria e inicializa um stub de banco de dados totalmente vazio.
 *
 * @return Database Retorna uma estrutura Database preenchida com zero produtos.
 *
 * @note Utilizado para testar cenários de erro, como buscar produtos em uma base vazia.
 */
Database criarDatabaseStubVazio();

/**
 * @brief Cria e inicializa um stub de banco de dados contendo exatamente um produto cadastrado.
 *
 * @return Database Retorna uma estrutura Database com apenas 1 produto inicializado.
 *
 * @note Ideal para validar cadastros duplicados ou exclusão de único item.
 */
Database criarDatabaseStubComUmProduto();

/**
 * @brief Cria e inicializa um stub de banco de dados contendo dois produtos pré-cadastrados.
 *
 * @return Database Retorna uma estrutura Database preenchida com 2 produtos distintos.
 *
 * @note Utilizado para testar listagens, paginações ou cenários comuns de consulta.
 */
Database criarDatabaseStubComDoisProdutos();

#endif
