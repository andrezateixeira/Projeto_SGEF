#include <stdio.h>
#include <stdlib.h>
#include "database.h"

int sistemaGEF(void);
int casosTestes(void);

int main(int argc, char *argv[]) {
    int opcao;
    
    do {
        printf("     BEM VINDO AO Sistema de Gerenciamento de Estoque e Faturamento\n");
        printf("0 - Sair\n");
        printf("1 - Acessar o sistema\n");
        printf("2 - Acessar os testes\n");
        printf("Opcao: ");
        scanf("%d", &opcao);
        
        switch(opcao){
            case 0:
                printf("\nPrograma Finalizado!\n");
                break;
            case 1:
                sistemaGEF();
                break;
            case 2:
                casosTestes();
                break;
            default:
                printf("Opcao invalida!\n");
        }
    } while(opcao != 0);
    
    return 0;
}

