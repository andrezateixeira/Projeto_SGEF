/**
 * @file testes.c
 * @brief Casos de teste unitário para as funções do sistema SGEF.
 *
 * @details Utiliza a biblioteca MinUnit para testar as funções
 * de validação de cadastro, busca, exclusão, compra e entrada
 * de estoque de produtos, usando stubs como base de dados simulada.
 *
 * @author Gabrielly e Allisson
 * @date 2026
 * @version 1.0
 */

#include <stdio.h>
#include <string.h>
#include "minunit.h"
#include "functions.h"
#include "database.h"
#include "database_stub.h"

/**
 * @brief Testa se um produto existente é encontrado pelo índice.
 *
 * @details Usa banco com um produto de código 11 e busca por ele.
 * Espera retorno do índice 0.
 */
MU_TEST(test_buscar_produto_existente){
        Database db = criarDatabaseStubComUmProduto();

        int resultado = buscarIndiceProduto(&db, 11);

        mu_assert(
        resultado == 0,
        "Produto existente deveria retornar indice 0");
}

/**
 * @brief Testa se produto inexistente retorna -1 na busca.
 *
 * @details Usa banco com um produto e busca por código 99.
 * Espera retorno -1.
 */
MU_TEST(test_buscar_produto_inexistente){
        Database db = criarDatabaseStubComUmProduto();

        int resultado = buscarIndiceProduto(&db, 99);

        mu_assert(
        resultado == -1, 
        "Produto inexistente deveria retornar -1" 
        );
}

/**
 * @brief Testa se código negativo é rejeitado no cadastro.
 *
 * @details Cria banco vazio e tenta cadastrar produto com código -5.
 * Espera retorno "ERRO: codigo invalido".
 */
MU_TEST(test_codigo_negativo) {
    Database db = criarDatabaseStubVazio();
    Produto p = {-5, "Arroz", 10, 1, 'A'};

    char *resultado = validarCadastroProduto(&db, p);

    mu_assert(
        strcmp(resultado, "ERRO: codigo invalido") == 0,
        "Codigo negativo deveria ser invalido"
    );
}

/**
 * @brief Testa se código duplicado é rejeitado no cadastro.
 *
 * @details Usa banco com produto de código 11 e tenta cadastrar outro igual.
 * Espera retorno "ERRO: codigo ja cadastrado".
 */
MU_TEST(test_codigo_duplicado) {
    Database db = criarDatabaseStubComUmProduto();
    Produto p = {11, "Feijao", 10, 1, 'A'};

    char *resultado = validarCadastroProduto(&db, p);

    mu_assert(
        strcmp(resultado, "ERRO: codigo ja cadastrado") == 0,
        "Codigo duplicado deveria ser rejeitado"
    );
}

/**
 * @brief Testa se nome vazio é rejeitado no cadastro.
 *
 * @details Cria banco vazio e tenta cadastrar produto com nome "".
 * Espera retorno "ERRO: nome invalido".
 */
MU_TEST(test_nome_invalido) {
    Database db = criarDatabaseStubVazio();
    Produto p = {1, "", 10, 1, 'E'};

    char *resultado = validarCadastroProduto(&db, p);

    mu_assert(
        strcmp(resultado, "ERRO: nome invalido") == 0,
        "Nome vazio deveria ser rejeitado"
    );
}

/**
 * @brief Testa se preço negativo é rejeitado no cadastro.
 *
 * @details Cria banco vazio e tenta cadastrar produto com preço -10.
 * Espera retorno "ERRO: preco invalido".
 */
MU_TEST(test_preco_negativo) {
    Database db = criarDatabaseStubVazio();
    Produto p = {1, "Farinha", -10, 25, 'A'};

    char *resultado = validarCadastroProduto(&db, p);

    mu_assert(
        strcmp(resultado, "ERRO: preco invalido") == 0,
        "Preco negativo deveria ser invalido"
    );
}

/**
 * @brief Testa se quantidade negativa é rejeitada no cadastro.
 *
 * @details Cria banco vazio e tenta cadastrar produto com quantidade -6.
 * Espera retorno "ERRO: quantidade invalida".
 */
MU_TEST(test_quantidade_negativa) {
    Database db = criarDatabaseStubVazio();
    Produto p = {1, "Jarro", 10, -6, 'C'};

    char *resultado = validarCadastroProduto(&db, p);

    mu_assert(
        strcmp(resultado, "ERRO: quantidade invalida") == 0,
        "Quantidade negativa deveria ser invalido"
    );
}

/**
 * @brief Testa se categoria inválida é rejeitada no cadastro.
 *
 * @details Cria banco vazio e tenta cadastrar produto com categoria 'Z'.
 * Espera retorno "ERRO: categoria invalida".
 */
MU_TEST(test_categoria_invalida) {
    Database db = criarDatabaseStubVazio();
    Produto p = {7, "Camisa", 15, 13, 'Z'};

    char *resultado = validarCadastroProduto(&db, p);

    mu_assert(
        strcmp(resultado, "ERRO: categoria invalida") == 0,
        "Categoria inválida deveria ser rejeitada"
    );
}

/**
 * @brief Testa se um cadastro válido é aceito com sucesso.
 *
 * @details Cria banco vazio e cadastra produto com todos os dados corretos.
 * Espera retorno "Cadastro realizado com sucesso".
 */
MU_TEST(test_cadastro_valido) {
    Database db = criarDatabaseStubVazio();
    Produto p = {1, "Arroz", 10, 1, 'A'};

    char *resultado = validarCadastroProduto(&db, p);

    mu_assert(
        strcmp(resultado, "Cadastro realizado com sucesso") == 0,
        "Cadastro deveria ser aceito"
    );
}

/**
 * @brief Testa se um produto existente é excluído com sucesso.
 *
 * @details Usa banco com um produto de código 11 e exclui ele.
 * Espera retorno "Produto excluido com sucesso".
 */
MU_TEST(test_excluir_produto_existente){
        Database db = criarDatabaseStubComUmProduto();

        char* resultado = excluirProduto(&db, 11);

        mu_assert(
                strcmp(resultado, "Produto excluido com sucesso") == 0,
                "Produto existente deveria ser excluido com sucesso"
        );
}

/**
 * @brief Testa se a exclusão de produto inexistente retorna erro.
 *
 * @details Usa banco com um produto e tenta excluir código 99.
 * Espera retorno "ERRO: Produto nao encontrado".
 */
MU_TEST(test_excluir_produto_inexistente) {
    Database db = criarDatabaseStubComUmProduto();

    char* resultado = excluirProduto(&db, 99);

    mu_assert(
        strcmp(resultado, "ERRO: Produto nao encontrado") == 0,
        "Tentativa de excluir produto inexistente deveria retornar nao encontrado"
    );
}

/**
 * @brief Testa se uma compra válida é realizada com sucesso.
 *
 * @details Usa banco com produto de quantidade 5 e compra 2 unidades.
 * Espera retorno "Compra realizada com sucesso".
 */
MU_TEST(test_compra_sucesso) {
    Database db = criarDatabaseStubComUmProduto();

    char *resultado = validarCompra(&db, 11, 2);

    mu_assert(
        strcmp(resultado, "Compra realizada com sucesso") == 0,
        "Compra deveria ser realizada com sucesso"
    );
}

/**
 * @brief Testa se compra com quantidade maior que o estoque retorna erro.
 *
 * @details Usa banco com produto de quantidade 5 e tenta comprar 999.
 * Espera retorno "ERRO: Quantidade insuficiente em estoque".
 */
MU_TEST(test_compra_quantidade_insuficiente) {
    Database db = criarDatabaseStubComUmProduto();

    char *resultado = validarCompra(&db, 11, 999);

    mu_assert(
        strcmp(resultado, "ERRO: Quantidade insuficiente em estoque") == 0,
        "Compra com quantidade insuficiente deveria retornar erro"
    );
}

/**
 * @brief Testa se compra de produto inexistente retorna erro.
 *
 * @details Usa banco com um produto e tenta comprar código 99.
 * Espera retorno "ERRO: Produto nao encontrado".
 */
MU_TEST(test_compra_produto_inexistente) {
    Database db = criarDatabaseStubComUmProduto();

    char *resultado = validarCompra(&db, 99, 1);

    mu_assert(
        strcmp(resultado, "ERRO: Produto nao encontrado") == 0,
        "Produto inexistente deveria retornar nao encontrado"
    );
}

/**
 * @brief Testa se entrada de estoque válida é realizada com sucesso.
 *
 * @details Usa banco com um produto de código 11 e adiciona 5 unidades.
 * Espera retorno "Entrada realizada com sucesso".
 */
MU_TEST(test_entrada_estoque_sucesso) {
    Database db = criarDatabaseStubComUmProduto(); 

    char *resultado = entradaEstoque(&db, 11, 5);

    mu_assert(
        strcmp(resultado, "Entrada realizada com sucesso") == 0,
        "Deveria somar a quantidade ao estoque com sucesso"
    );
}

/**
 * @brief Testa se entrada com quantidade negativa retorna erro.
 *
 * @details Usa banco com um produto e tenta entrada com quantidade -5.
 * Espera retorno "ERRO: Quantidade invalida para entrada".
 */
MU_TEST(test_entrada_estoque_quantidade_invalida) {
    Database db = criarDatabaseStubComUmProduto();

    char *resultado = entradaEstoque(&db, 11, -5);

    mu_assert(
        strcmp(resultado, "ERRO: Quantidade invalida para entrada") == 0,
        "Quantidade negativa/zero deveria retornar erro"
    );
}

/**
 * @brief Testa se entrada de estoque em produto inexistente retorna erro.
 *
 * @details Usa banco com um produto e tenta entrada no código 99.
 * Espera retorno "ERRO: Produto nao encontrado".
 */
MU_TEST(test_entrada_estoque_produto_inexistente) {
    Database db = criarDatabaseStubComUmProduto();

    char *resultado = entradaEstoque(&db, 99, 10);

    mu_assert(
        strcmp(resultado, "ERRO: Produto nao encontrado") == 0,
        "Produto inexistente deveria retornar nao encontrado"
    );
}

/**
 * @brief Testa se produtos com estoque abaixo do limite são exibidos.
 *
 * @details Usa banco com produto de quantidade 3 e limite 5.
 * Verifica se o produto é identificado como estoque baixo.
 */
MU_TEST(test_mostrar_estoque_baixo) {
    Database db = criarDatabaseStubComUmProduto();

    db.produtos[0].quantidade = 3;

    mostrarProdutosEstoqueBaixo(&db, 5);

    mu_assert(
        db.produtos[0].quantidade < 5,
        "Produto deveria estar com estoque baixo"
    );
}

/**
 * @brief Suíte principal que agrupa e executa todos os testes.
 *
 * @details Registra e executa todos os casos de teste do sistema SGEF,
 * incluindo testes de busca, cadastro, exclusão, compra e entrada de estoque.
 */
MU_TEST_SUITE(test_suite) {
        MU_RUN_TEST(test_buscar_produto_existente);
        MU_RUN_TEST(test_buscar_produto_inexistente);
        MU_RUN_TEST(test_excluir_produto_existente);
        MU_RUN_TEST(test_excluir_produto_inexistente);
        MU_RUN_TEST(test_codigo_negativo);
        MU_RUN_TEST(test_codigo_duplicado);
        MU_RUN_TEST(test_nome_invalido);
        MU_RUN_TEST(test_preco_negativo);
        MU_RUN_TEST(test_quantidade_negativa);
        MU_RUN_TEST(test_categoria_invalida);
        MU_RUN_TEST(test_cadastro_valido);
        MU_RUN_TEST(test_compra_sucesso);
        MU_RUN_TEST(test_compra_quantidade_insuficiente);
        MU_RUN_TEST(test_compra_produto_inexistente);
        MU_RUN_TEST(test_entrada_estoque_sucesso);
        MU_RUN_TEST(test_entrada_estoque_quantidade_invalida);
        MU_RUN_TEST(test_entrada_estoque_produto_inexistente);
        MU_RUN_TEST(test_mostrar_estoque_baixo);
}

/**
 * @brief Função principal de execução dos testes unitários.
 *
 * @details Inicializa e executa a suíte de testes, exibindo
 * o relatório final com resultados.
 *
 * @return int Código de saída dos testes (MU_EXIT_CODE).
 */
int casosTestes(void) {
    printf("\n INICIANDO TESTES UNITARIOS\n");    
    MU_RUN_SUITE(test_suite);
    MU_REPORT();

    return MU_EXIT_CODE;
}
