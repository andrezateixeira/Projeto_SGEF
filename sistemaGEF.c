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
            case 1: {
            	if(db.qtdProdutos >= MAX_PRODUTOS) {
                    printf("Limite de produtos atingido!\n");
                    break;
                }          	
                int codigoDigitado;
                char nomeDigitado[30];
                float precoDigitado;
                int quantidadeDigitada;
                char categoriaDigitada;
                
                printf("Codigo: ");
                scanf("%d", &codigoDigitado);
                printf("Nome: ");
                scanf("%29s", nomeDigitado);
                printf("Preco: ");
                scanf("%f", &precoDigitado);
                printf("Quantidade: ");
                scanf("%d", &quantidadeDigitada);
                printf("Categoria (A = Alimento, C = Casa, E= Eletrônicos, H = Higiene ou M = Moda ): ");
                scanf(" %c", &categoriaDigitada);                              
                
                resultado = validarCadastroProduto(codigoDigitado, nomeDigitado, precoDigitado, quantidadeDigitada, categoriaDigitada,db.codigos, db.qtdProdutos);
                printf("%s\n", resultado);         
            	 break;
            	}
            case 2:
                mostrarProdutos();
                break;
            case 3:
                printf("Digite o codigo do produto a excluir: ");
                scanf("%d", &codigo);
				resultado = excluirProduto(codigo);
                printf("%s\n", resultado);
                break;
            case 4:
                printf("Digite o codigo do produto: ");
                scanf("%d", &codigo);
                printf("Digite a quantidade desejada: ");
                scanf("%d", &quantidade);
				resultado = validarCompra(codigo, quantidade);
                printf("%s\n", resultado);
                break;
            case 5:
                printf("Digite o codigo do produto: ");
                scanf("%d", &codigo);
                printf("Digite a quantidade de entrada: ");
                scanf("%d", &quantidade);
				resultado = entradaEstoque(codigo, quantidade);
                printf("%s\n", resultado);
                break;  
            case 6:
                mostrarProdutosEstoqueBaixo(10);
                break;
            default:
                printf("Opcao invalida!\n");
    	}
    } while(opcao != 0);
    
    return 0;
}

