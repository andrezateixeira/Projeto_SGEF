#include <stdio.h>
#include <string.h>
#include "minunit.h"
#include "functions.h"
#include "database.h"

void setup() {
    stub_inicializarDB();
    stub_adicionarProduto(1, "Produto A", 10.50, 100, 'A');
    stub_adicionarProduto(2, "Produto B", 20.00, 5, 'B');
    stub_adicionarProduto(3, "Produto C", 15.75, 0, 'C');
}

MU_TEST_SUITE(test_suite) {

}

int casosTestes(void) {
    printf("\n INICIANDO TESTES UNIT?RIOS\n");    
    MU_RUN_SUITE(test_suite);
    MU_REPORT();
    
    return MU_EXIT_CODE;
}

