#include <stdio.h>
#include <string.h>
#include "minunit.h"
#include "functions.h"
#include "database.h"

MU_TEST(test_validar_codigo_negativo) {
    int resultado = stub_codigo_invalido(-5);
    mu_assert(
        resultado == 1,
        "Erro: Codigo negativo deveria ser invalido"
    );
    
    resultado = stub_codigo_invalido(10);
    mu_assert(
        resultado == 0,
        "Erro: Codigo positivo deveria ser valido"
    );
}

MU_TEST_SUITE(test_suite) {
	MU_RUN_TEST(test_validar_codigo_negativo);
}

int casosTestes(void) {
    printf("\n INICIANDO TESTES UNIT?RIOS\n");    
    MU_RUN_SUITE(test_suite);
    MU_REPORT();
    
    return MU_EXIT_CODE;
}

