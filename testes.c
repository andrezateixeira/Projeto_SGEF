#include <stdio.h>
#include <string.h>
#include "minunit.h"
#include "functions.h"
#include "database.h"
#include "database_stub.h"

MU_TEST(test_codigo_negativo) {
    Database db = criarDatabaseStubVazio();
    Produto p = {-5, "Arroz", 10, 1, 'A'};

    char *resultado = validarCadastroProduto(&db, p);

    mu_assert(
        strcmp(resultado, "ERRO: codigo invalido") == 0,
        "Codigo negativo deveria ser invalido"
    );
}

MU_TEST(test_codigo_duplicado) {
    Database db = criarDatabaseStubComUmProduto();
    Produto p = {11, "Feijao", 10, 1, 'A'};

    char *resultado = validarCadastroProduto(&db, p);

    mu_assert(
        strcmp(resultado, "ERRO: codigo ja cadastrado") == 0,
        "Codigo duplicado deveria ser rejeitado"
    );
}

MU_TEST(test_preco_negativo) {
    Database db = criarDatabaseStubVazio();
    Produto p = {1, "Farinha", -10, 25, 'A'};

    char *resultado = validarCadastroProduto(&db, p);

    mu_assert(
        strcmp(resultado, "ERRO: preco invalido") == 0,
        "Preco negativo deveria ser invalido"
    );
}

MU_TEST_SUITE(test_suite) {
	MU_RUN_TEST(test_codigo_negativo);
	MU_RUN_TEST(test_codigo_duplicado);
	MU_RUN_TEST(test_preco_negativo);
}

int casosTestes(void) {
    printf("\n INICIANDO TESTES UNIT?RIOS\n");    
    MU_RUN_SUITE(test_suite);
    MU_REPORT();
    
    return MU_EXIT_CODE;
}

