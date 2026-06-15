/**
 * @file main.c
 * @brief Biblioteca simples de operações matemáticas.
 *
 * @details Este arquivo contém funções básicas para realizar soma e divisão de dois números.
 * @author Malu
 * @date 2026
 * @version 1.0
 *
 */
 
#include <stdio.h>
#include <stdlib.h>
#include "database.h"

int sistemaGEF(void);
int casosTestes(void);

/**
 * @brief Função principal do programa.
 *
 * @details Exibe o menu inicial do Sistema de Gerenciamento de Estoque
 * e Faturamento, permitindo ao usuário acessar o sistema, executar os
 * testes (quando disponíveis) ou encerrar o programa.
 *
 * @param argc Quantidade de argumentos passados pela linha de comando.
 * @param argv Vetor contendo os argumentos da linha de comando.
 *
 * @return Retorna 0 ao finalizar a execução do programa.
 */
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

