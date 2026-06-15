/**
 * @file testes.c
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
#include "minunit.h"
#include "functions.h"
#include "database.h"

/**
 * @brief Realiza a soma de dois números inteiros
 *
 * @note Os parâmetros podem ser positivos ou negativos
 */
 
void setup() {
    stub_inicializarDB();
    stub_adicionarProduto(1, "Produto A", 10.50, 100, 'A');
    stub_adicionarProduto(2, "Produto B", 20.00, 5, 'B');
    stub_adicionarProduto(3, "Produto C", 15.75, 0, 'C');
}

MU_TEST_SUITE(test_suite) {

}

/**
 * @brief Realiza a soma de dois números inteiros
 *
 * @return int O resultado da soma entre @v1 e @v2
 *
 * @note Os parâmetros podem ser positivos ou negativos
 */
int casosTestes(void) {
    printf("\n INICIANDO TESTES UNIT?RIOS\n");    
    MU_RUN_SUITE(test_suite);
    MU_REPORT();
    
    return MU_EXIT_CODE;
}

