//
// Created by caio on 16/04/18.
//

///FALTA CRIAR PIPE E FORK (Chamadas de sistema pipe() e fork())

#include <string.h>
#include "Commander.h"

void entradaArquivo(){
    char nomeArq[100], caminhoArq[100] = "/home/caio/Desktop/TP2SO/";
    char comando;
    FILE *arq;
    ProcessManager processManager;
    printf("Nome do arquivo de entrada: ");
    getchar();
    //fgets(nomeArq, 100, stdin);
    //strcat(caminhoArq,nomeArq);
    //arq = fopen(caminhoArq, "r");
    arq = fopen("/home/caio/Desktop/TP2SO/teste.txt", "r");
    if(arq == NULL){
        printf("Erro ao abrir o arquivo!");
        return;
    }
    //criar pipe
    processManager = iniciarProcessManager(); //criar ProcessManager

    while(1){
        comando = fgetc(arq);
        if(comando == 'Q' || comando == 'U' || comando == 'P' || comando == 'T') {
            leituraCommander(&processManager, comando); //passar comando para o processo ProcessManager
            if(comando == 'T') break;
        }
        else if(comando == '\n');
        else{
            printf("Comando invalido ""%c"", pressione qualquer tecla para continuar...", comando);
            getchar();
        }

    }
    fclose(arq);
}

void entradaPadrao(){
    char comando;
    ProcessManager processManager;
    //criar pipe
    processManager = iniciarProcessManager(); //criar ProcessManager
    printf("Digite um comando (Q, U, P, T).\n");
    while(1){
        getchar();
        scanf("%c", &comando);
        if(comando == 'Q' || comando == 'U' || comando == 'P' || comando == 'T') {
            leituraCommander(&processManager, comando); //passar comando para o processo ProcessManager
            if(comando == 'T') break;
        }
        else{
            printf("Comando invalido, pressione qualquer tecla para continuar...");
            getchar();
            getchar();
        }

    }
}