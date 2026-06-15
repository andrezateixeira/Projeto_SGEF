#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "database.h"

int buscarIndiceProduto(Database *db, int codigo);
char* validarCadastroProduto(Database *db, Produto produto);
void mostrarProdutos(Database *db);
char* excluirProduto(Database *db, int codigo);
char* validarCompra(Database *db,int codigo,int quantidadeDesejada);
char* entradaEstoque(Database *db, int codigo,int quantidadeEntrada);
void mostrarProdutosEstoqueBaixo(Database *db, int limite);

#endif
