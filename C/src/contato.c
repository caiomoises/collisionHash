#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAMANHO_VETOR 32

typedef struct contato{
    char nome[50];
    char email[50];
    char numero[30];
} Contato;

void inicializa_lista(Contato *lista_contatos){
    for(int i = 0; i < TAMANHO_VETOR; i++){
        strcpy(lista_contatos[i].numero, "0");
    }
}

Contato cria_contato(){
    //Necessário transformar char numero em int numero
    Contato novo_contato;
    printf("Insira o nome do contato:\n");
    scanf(" %[^\n]", novo_contato.nome);
    printf("Insira o número de contato de %s:\n", novo_contato.nome);
    scanf(" %[^\n]", novo_contato.numero);
    printf("Insira o email de %s:\n", novo_contato.nome);
    scanf(" %[^\n]", novo_contato.email);
    return(novo_contato);
}

int hash_function(int key, int probe){
    return(((key % TAMANHO_VETOR)+ probe) % TAMANHO_VETOR);
}

int concatenacao(char c[]){
    int key = 0, i = 0;
    while(c[i] != '\0'){
        key += c[i];
        i++; 
    } 
    return key;
}

Contato insere_contato(Contato *lista_contatos, Contato novo_contato){
    



}

