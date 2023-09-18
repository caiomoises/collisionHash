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
        memset(lista_contatos[i].numero, '\0', 30);
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

void insere_contato(Contato *lista_contatos, int cont_conc, Contato novo_contato){
    int probe = 0;
    int index;
    while (1)
    {
        index = hash_function(cont_conc, probe);
        if ((strcmp(lista_contatos[index].numero, "\0")) == 0)
        {
            lista_contatos[index] = novo_contato;
            break;
        }

        if (lista_contatos[index].numero != 0)
        {
            probe++;
        }

        if (index > TAMANHO_VETOR)
        {
            index = ((TAMANHO_VETOR - index) * -1);
        }
    }
}

void deleta_contato(Contato *lista_contatos){
    char contato_del[30];
    printf("Insira o número do contato que deseja deletar:\n");
    scanf(" %[^\n]", contato_del);
    int cont_conc = concatenacao(contato_del); 
    int probe = 0;
    int index;
    while (1)
    {
        index = hash_function(cont_conc, probe);
        if ((strcmp(lista_contatos[index].numero, contato_del)) == 0)
        {
            strcpy(lista_contatos[index].numero, "\0");
            strcpy(lista_contatos[index].nome, "\0");
            strcpy(lista_contatos[index].email, "\0");
            break;
        }

        if (strcmp(lista_contatos[index].numero, contato_del) != 0)
        {
            probe++;
        }

        if (index > TAMANHO_VETOR)
        {
            index = ((TAMANHO_VETOR - index) * -1);
        }

        if(probe > TAMANHO_VETOR)
        {
            printf("Contato não encontrado.");
            break;
        }
    }
}


//Imprimindo lixo, necessário consertar
void imprime_contatos(Contato *lista_contatos){
    for(int i = 0; i <= TAMANHO_VETOR; i++){
        if(lista_contatos[i].numero[0] != '\0'){
            printf("Nome: %s\nNúmero: %s\nEmail: %s\n\n", lista_contatos[i].nome, lista_contatos[i].numero, lista_contatos[i].email);
        }
    }
}