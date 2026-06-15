#include <stdio.h>
#include <string.h>
#include "minunit.h"
#include "functions.h"
#include "database.h"
#include "database_stub.h"

MU_TEST(test_buscar_produto_existente){
	Database db = criarDatabaseStubComUmProduto();
	
	int resultado = buscarIndiceProduto(&db, 11);
	
	mu_assert(
	resultado == 0,
	"Produto existente deveria retornar indice 0");
}

MU_TEST(test_buscar_produto_inexistente){
	Database db = criarDatabaseStubComUmProduto();
	
	int resultado = buscarIndiceProduto(&db, 99);
	
	mu_assert(
	resultado == -1, 
	"Produto inexistente deveria retornar -1" 
	);
}

MU_TEST(test_excluir_produto_existente){
	Database db = CriarDatabaseStubComUmProduto();
	
	int resultado = excluirProduto(&db, 11);
	
	mu_assert(
	resultado == 0,
	"Produto existente deveria ser excluido com sucesso"
	);
}

MU_TEST(test_excluir_produto_inexistente) {
    Database db = criarDatabaseStubComUmProduto();
    
    int resultado = excluirProduto(&db, 99);
    
    mu_assert(
        resultado == -1,
        "Tentativa de excluir produto inexistente deveria retornar nao encontrado"
    );
}

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

MU_TEST(test_nome_invalido) {

    Database db = criarDatabaseStubVazio();
    Produto p = {1, "", 10, 1, 'E'};

    char *resultado = validarCadastroProduto(&db, p);

    mu_assert(
        strcmp(resultado, "ERRO: nome invalido") == 0,
        "Nome vazio deveria ser rejeitado"
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

MU_TEST(test_quantidade_negativa) {
    Database db = criarDatabaseStubVazio();
    Produto p = {1, "Jarro", 10, -6, 'C'};

    char *resultado = validarCadastroProduto(&db, p);

    mu_assert(
        strcmp(resultado, "ERRO: quantidade invalida") == 0,
        "Quantidade negativa deveria ser invalido"
    );
}

MU_TEST(test_categoria_invalida) {
    Database db = criarDatabaseStubVazio();
    Produto p = {7, "Camisa", 15, 13, 'Z'};

    char *resultado = validarCadastroProduto(&db, p);

    mu_assert(
        strcmp(resultado, "ERRO: categoria invalida") == 0,
        "Categoria inválida deveria ser rejeitada"
    );
}

MU_TEST(test_cadastro_valido) {
    Database db = criarDatabaseStubVazio();
    Produto p = {1, "Arroz", 10, 1, 'A'};
    
    char *resultado = validarCadastroProduto(&db, p);

    mu_assert(
        strcmp(resultado, "Cadastro realizado com sucesso") == 0,
        "Cadastro deveria ser aceito"
    );
}

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
}

int casosTestes(void) {
    printf("\n INICIANDO TESTES UNIT?RIOS\n");    
    MU_RUN_SUITE(test_suite);
    MU_REPORT();
    
    return MU_EXIT_CODE;
}

