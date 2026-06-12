#include <stdio.h>
#include <string.h>

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
                printf("Categoria (A, B ou C): ");
                scanf(" %c", &categoriaDigitada);
                
				validarCadastroProduto(codigoDigitado, nomeDigitado, precoDigitado, quantidadeDigitada, categoriaDigitada);
                break;
            }
            case 2:
                mostrarProdutos();
                break;
            case 3:
                printf("Digite o codigo do produto a excluir: ");
                scanf("%d", &codigo);
				excluirProduto(codigo);
                break;
            case 4:
                printf("Digite o codigo do produto: ");
                scanf("%d", &codigo);
                printf("Digite a quantidade desejada: ");
                scanf("%d", &quantidade);
				validarCompra(codigo, quantidade);
                break;
            case 5:
                printf("Digite o codigo do produto: ");
                scanf("%d", &codigo);
                printf("Digite a quantidade de entrada: ");
                scanf("%d", &quantidade);
				entradaEstoque(codigo, quantidade);
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

