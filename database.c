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

int stub_buscar_indice_produto(int codigo) {
    if (codigo == 1) return 0;  
    if (codigo == 2) return 1;   
    return -1;                    
}

int stub_codigo_invalido(int codigo) {
    if (codigo < 0) return 1;
    return 0;
}

int stub_codigo_duplicado(int codigo) {
    if (codigo == 1) return 1;  
    if (codigo == 2) return 1;  
    return 0;
}

int stub_nome_invalido(char nome[]) {
    if (strlen(nome) == 0) return 1;
    return 0;
}

int stub_preco_invalido(float preco) {
    if (preco <= 0) return 1;
    return 0;
}
