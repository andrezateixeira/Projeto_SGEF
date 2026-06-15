/**
 * @file sistema.c
 * @brief Biblioteca simples de operações matemáticas.
 *
 * @details Este arquivo contém funções básicas para realizar soma e divisão de dois números.
 * @author Malu
 * @date 2026
 * @version 1.0
 *
 */
 
#include <stdio.h>
#include <string.h>
#include "database.h"
#include "functions.h"

/**
 * @brief Executa o Sistema de Gerenciamento de Estoque (SGEF).
 *
 * @details Exibe o menu principal do sistema, recebe a opção escolhida
 * pelo usuário e executa operações como cadastro, listagem, exclusão,
 * validação de compra, entrada em estoque e exibição de produtos com
 * estoque baixo.
 *
 * @return Retorna 0 ao encerrar a execução do sistema.
 */
int sistemaGEF() {
    int opcao;
    int codigo, quantidade;
    char *resultado;
    
    Database db = criarDatabase();
    
    do {
        printf("\nSISTEMA DE ESTOQUE\n");
        printf("0 - Sair\n");
        printf("1 - Cadastrar produto\n");
        printf("2 - Listar produtos\n");
        printf("3 - Excluir produto\n");
        printf("4 - Validar compra\n");
        printf("5 - Entrada em estoque\n");
        printf("6 - Mostrar produtos com estoque baixo\n");
        printf("Opcao: ");
        scanf("%d", &opcao);
        
        switch(opcao) {
            case 0:
                printf("Voce saiu do sistema.\n");
                break;
            case 1:
			{
    			Produto produto;

    			printf("Codigo: ");
    			scanf("%d", &produto.codigo);
    			printf("Nome: ");
    			scanf("%29s", produto.nome);
    			printf("Preco: ");
    			scanf("%f", &produto.preco);
   				printf("Quantidade: ");
    			scanf("%d", &produto.quantidade);
    			printf("Categoria (A = Alimento, C = Casa, E= Eletrônicos, H = Higiene ou M = Moda ): ");
    			scanf(" %c", &produto.categoria);

    			resultado = validarCadastroProduto(&db, produto);

    			printf("%s\n", resultado);

    			break;
			}
            case 2:
    			mostrarProdutos(&db);
    			break;
            case 3:
            	printf("Digite o codigo do produto: ");
    			scanf("%d", &codigo);
    			resultado = excluirProduto(&db, codigo);
    			printf("%s\n", resultado);
    			break;
            case 4:
                printf("Digite o codigo do produto: ");
                scanf("%d", &codigo);
                printf("Digite a quantidade desejada: ");
                scanf("%d", &quantidade);
				resultado =
    			validarCompra(&db, codigo, quantidade);
    			printf("%s\n", resultado);
                break;
            case 5:
                printf("Digite o codigo do produto: ");
                scanf("%d", &codigo);
                printf("Digite a quantidade de entrada: ");
                scanf("%d", &quantidade);
				resultado =
    			entradaEstoque(&db, codigo, quantidade);
                printf("%s\n", resultado);
                break;  
            case 6:
                mostrarProdutosEstoqueBaixo(&db, 10);
                break;
            default:
                printf("Opcao invalida!\n");
    	}
    } while(opcao != 0);
    
    return 0;
}

