#include <stdio.h>
#include <string.h>
#include "database.h"

EstoqueDB db;

/**
 * @brief Inicializa o banco de dados do sistema.
 *
 * @details Define a quantidade de produtos cadastrados como zero,
 * preparando o banco para uso nos testes.
 *
 * @return Não retorna nenhum valor.
 */
void stub_inicializarDB(void) {
    db.qtdProdutos = 0;
}


