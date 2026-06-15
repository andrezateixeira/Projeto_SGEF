#include "database_stub.h"

Database criarDatabaseStub(void)
{
    Database db;
    db.qtdProdutos = 0;
    return db;
}


Database criarDatabaseStubVazio() {
    Database db;
    db.qtdProdutos = 0;
    return db;
}

Database criarDatabaseStubComUmProduto() {
    Database db;

    db.qtdProdutos = 1;

    db.produtos[0].codigo = 11;
    db.produtos[0].nome[0] = 'A';
    db.produtos[0].nome[1] = '\0';
    db.produtos[0].preco = 10;
    db.produtos[0].quantidade = 5;
    db.produtos[0].categoria = 'A';

    return db;
}

Database criarDatabaseStubComDoisProdutos() {
    Database db;

    db.qtdProdutos = 2;

    db.produtos[0].codigo = 1;
    db.produtos[1].codigo = 2;

    return db;
}
