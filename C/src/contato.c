#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define TAMANHO_VETOR 32

typedef struct contato
{
    char nome[50];
    char email[50];
    char numero[30];
} Contato;

// Essa função serve para retirar o lixo da memória
void inicializa_lista(Contato *lista_contatos)
{
    for (int i = 0; i <= TAMANHO_VETOR; i++)
    {
        memset(lista_contatos[i].numero, '\0', 30);
    }
}

// Basicamente cria o contato e retorna
Contato cria_contato()
{
    Contato novo_contato;
    printf("Insira o nome do contato:\n");
    scanf(" %[^\n]", novo_contato.nome);
    if (strlen(novo_contato.nome) > 0)
    {
        novo_contato.nome[0] = toupper(novo_contato.nome[0]); // Verificando se a primeira letra do nome é maiúscula.
    }
    printf("Insira o número de contato de %s:\n", novo_contato.nome);
    scanf(" %[^\n]", novo_contato.numero);
    printf("Insira o email de %s:\n", novo_contato.nome);
    scanf(" %[^\n]", novo_contato.email);
    return (novo_contato);
}

// Função hash para obter o índice onde será armazenado o elemento
int hash_function(int key, int probe)
{
    return (((key % TAMANHO_VETOR) + probe) % TAMANHO_VETOR);
}

// Concatena a string para obter uma key utilizada na função hash
int concatenacao(char c[])
{
    int key = 0, i = 0;
    while (c[i] != '\0')
    {
        key += c[i];
        i++;
    }
    return key;
}

// Função utilizada para procurar um index vazio, caso o index indicado não esteja, a função irá ser repetida, incrementando o probe e obtendo um novo indice
int retorna_index_vazio(Contato *lista_contatos, int numero_conc)
{
    int index, probe = 0;
    while (1)
    {
        index = hash_function(numero_conc, probe);
        if ((strcmp(lista_contatos[index].numero, "\0")) == 0)
        {
            return (index);
        }

        if ((strcmp(lista_contatos[index].numero, "\0")) != 0)
        {
            probe++;
        }

        if (index > TAMANHO_VETOR)
        {
            index = ((TAMANHO_VETOR - index) * -1);
        }
    }
}

// Função utilizada para comparar o elemento do index indicado com o elemento procurado pelo usuário
int retorna_index_comparacao(Contato *lista_contatos, int numero_conc, char *elemento_comparado)
{
    int index, probe = 0;
    while (1)
    {
        index = hash_function(numero_conc, probe);
        if ((strcmp(lista_contatos[index].numero, elemento_comparado)) == 0)
        {
            return (index);
        }

        if ((strcmp(lista_contatos[index].numero, elemento_comparado)) != 0)
        {
            probe++;
        }

        if (index > TAMANHO_VETOR)
        {
            index = ((TAMANHO_VETOR - index) * -1);
        }

        if (probe == TAMANHO_VETOR)
        {
            return (-1);
        }
    }
}

// Irá inserir o contado na lista
void insere_contato(Contato *lista_contatos, Contato novo_contato)
{
    int novo_concatenado = concatenacao(novo_contato.numero);
    int index_vazio = retorna_index_vazio(lista_contatos, novo_concatenado);
    lista_contatos[index_vazio] = novo_contato;
}

// Deletará o contato indicado
void deleta_contato(Contato *lista_contatos)
{
    char numero_deleta[30];
    printf("Insira o número do contato que deseja deletar:\n");
    scanf(" %[^\n]", numero_deleta);
    int cont_conc = concatenacao(numero_deleta);
    int index = retorna_index_comparacao(lista_contatos, cont_conc, numero_deleta);
    if (index != (-1))
    {
        strcpy(lista_contatos[index].numero, "\0");
        strcpy(lista_contatos[index].nome, "\0");
        strcpy(lista_contatos[index].email, "\0");
    }
    else
    {
        printf("Contato não cadastrado.\n");
    }
}

// Irá imprimir todos os elementos do vetor que possuem dados
void imprime_contatos(Contato *lista_contatos)
{
    for (int i = 0; i <= TAMANHO_VETOR; i++)
    {
        if (lista_contatos[i].numero[0] != '\0')
        {
            printf("Nome: %s\nNúmero: %s\nEmail: %s\n\n", lista_contatos[i].nome, lista_contatos[i].numero, lista_contatos[i].email);
        }
    }
}

// Irá buscar o elemento indicado pelo usuário através da função hash
void buscar_contato(Contato *lista_contatos)
{
    char numero_busca[30];
    printf("Insira o número do contato que deseja buscar:\n");
    scanf(" %[^\n]", numero_busca);
    int cont_conc = concatenacao(numero_busca);
    int index = retorna_index_comparacao(lista_contatos, cont_conc, numero_busca);
    if (index != (-1))
    {
        printf("Nome: %s\nNúmero: %s\nEmail: %s\n\n", lista_contatos[index].nome, lista_contatos[index].numero, lista_contatos[index].email);
    }
    else
    {
        printf("Contato não encontrado.\n");
    }
}

// Edita o contato, necessário tratativas para erros
void edita_contato(Contato *lista_contatos)
{
    char numero_edita[30];
    int var_controle = 0, var_confirma;
    printf("Insira o número do contato que deseja editar:\n");
    scanf(" %[^\n]", numero_edita);
    int cont_conc = concatenacao(numero_edita);
    int index = retorna_index_comparacao(lista_contatos, cont_conc, numero_edita);
    if (index != -1)
    {
        printf("Qual alteração você deseja fazer?\n1)Nome\n2)Número\n3)Email\n4)Sair\n");
        scanf("%i", &var_controle);
        while (var_controle != 4)
        {
            printf("Qual alteração você deseja fazer?\n1)Nome\n2)Número\n3)Email\n4)Sair\n");
            scanf("%i", &var_controle);
            switch (var_controle)
            {
            case 1:
                printf("\n");
                char novo_nome[50];
                printf("Insira o novo nome para atual contato %s:\n.", lista_contatos[index].nome);
                scanf(" %[^\n]", novo_nome);
                if (strlen(novo_nome) > 0)
                {
                    novo_nome[0] = toupper(novo_nome[0]); // Verificando se a primeira letra do nome é maiúscula.
                }
                printf("Você irá mudar o nome do contato de %s para %s, tem certeza disso?\n1)Sim\t2)Não\n", lista_contatos[index].nome, novo_nome);
                scanf("%i", &var_confirma);
                if (var_confirma == 1)
                {
                    strcpy(lista_contatos[index].nome, novo_nome);
                }
                break;

            case 2:
                printf("\n");
                char novo_numero[30];
                printf("Insira o novo número para o atual contato de %s:\n", lista_contatos[index].nome);
                scanf(" %[^\n]", novo_numero);
                printf("Você irá mudar o número de contato de %s para %s, tem certeza disso?\n1)Sim\t2)Não\n", lista_contatos[index].nome, novo_numero);
                scanf("%i", &var_confirma);
                if (var_confirma == 1)
                {
                    memset(lista_contatos[index].numero, '\0', 30);
                    int novo_numero_conc = concatenacao(novo_numero);
                    int novo_index = retorna_index_vazio(lista_contatos, novo_numero_conc);
                    strcpy(lista_contatos[novo_index].numero, novo_numero);
                    strcpy(lista_contatos[novo_index].nome, lista_contatos[index].nome);
                    strcpy(lista_contatos[novo_index].email, lista_contatos[index].email);
                    memset(lista_contatos[index].nome, '\0', 49);
                    memset(lista_contatos[index].email, '\0', 49);
                }
                break;

            case 3:
                printf("\n");
                char novo_email[50];
                printf("Insira o novo email para atual contato %s:\n.", lista_contatos[index].nome);
                scanf(" %[^\n]", novo_email);
                printf("Você irá mudar o email do contato de %s para %s, tem certeza disso?\n1)Sim\t2)Não\n", lista_contatos[index].nome, novo_email);
                scanf("%i", &var_confirma);
                if (var_confirma == 1)
                {
                    strcpy(lista_contatos[index].email, novo_email);
                }
                break;

            case 4:
                break;
            }
        }
    }
    else
    {
        printf("Contato não encontrado.\n");
    }
}

// Importa contatos de um arquivo.txt e aloca na nossa lista
int importar_contatos(Contato *lista_contatos, int espacos_livres)
{
    int qnt_novos_contatos = 0;
    char linha[200];
    Contato novo_contato_importado;
    FILE *arquivo_entrada = fopen("contatos.txt", "r");
    if (arquivo_entrada == NULL)
    {
        printf("Erro ao abrir o arquivo de contatos.\n");
        exit(1);
    }

    while (fgets(linha, 199, arquivo_entrada) != NULL)
    {
        sscanf(linha, "Numero: %s\tNome: %s\tEmail: %s", novo_contato_importado.numero, novo_contato_importado.nome, novo_contato_importado.email);
        insere_contato(lista_contatos, novo_contato_importado);
        espacos_livres--;
        if ((espacos_livres = 0))
        {
            printf("Armazenamento cheio.\n");
            break;
        }
    }
    fclose(arquivo_entrada);
    return (espacos_livres);
}

// Exporta contatos da lista para arquivo.txt
void exportar_contatos(Contato *lista_contatos)
{
    FILE *saida = fopen("contatos.txt", "w");
    for (int i = 0; i <= TAMANHO_VETOR; i++)
    {
        if (lista_contatos[i].numero[0] != '\0')
        {
            fprintf(saida, "Numero: %s\tNome: %s\tEmail: %s\n", lista_contatos[i].numero, lista_contatos[i].nome, lista_contatos[i].email);
        }
    }
    fclose(saida);
}