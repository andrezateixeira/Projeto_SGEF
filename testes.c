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

MU_TEST_SUITE(test_suite) {
	MU_RUN_TEST(test_codigo_negativo);
}

int casosTestes(void) {
    printf("\n INICIANDO TESTES UNIT?RIOS\n");    
    MU_RUN_SUITE(test_suite);
    MU_REPORT();
    
    return MU_EXIT_CODE;
}

