#include <stdio.h>
#include "C\src\contato.c"
#include "C\src\menu.c"


int main(){
    int espacos_livre = TAMANHO_VETOR;
    int var_control = 0;
    Contato lista_contatos[32];
    inicializa_lista(lista_contatos);

    while(var_control != 8){
        printar_menu();
        scanf("%i", &var_control);
        //system("cls");

        switch (var_control)
        {

        // Inserir Contato
        case 1:
            printf("\n");
            Contato novo_contato = cria_contato();
            insere_contato(lista_contatos, novo_contato);
            espacos_livre--;
            break;

        // Remover Contato
        case 2:
            deleta_contato(lista_contatos);
            espacos_livre++;
            break;

        // Listar Contato
        case 3:
            if (espacos_livre == 32)
            {
                printf("Sem contatos cadastrados.\n");
                break;
            }
            imprime_contatos(lista_contatos);
            break;

        // Buscar Contato
        case 4:
            buscar_contato(lista_contatos);
            break;

        // Editar Contato
        case 5:
            edita_contato(lista_contatos);
            break;

        // Importar Contatos
        case 6:
            espacos_livre = importar_contatos(lista_contatos, espacos_livre);
            break;

        // Exportar Contatos
        case 7:
            exportar_contatos(lista_contatos);
            break;
        
        // Saída do Programa
        case 8:
            break;

        }
    }
    return 0;
}