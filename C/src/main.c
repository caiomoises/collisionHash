#include <stdio.h>
#include </home/abner/Desktop/Codes/Projeto Hash/collisionHash/C/src/contato.c>
#include </home/abner/Desktop/Codes/Projeto Hash/collisionHash/C/src/menu.c>


//1-Inserir Contato\n2-Remover Contato\n3-Listar Contatos\n4-Buscar Contato\n5-Editar Contato\n6-Importar Contatos\n7-Exportar Contatos\n8-Sair do Programa

int main(){
    int espacos_livre = TAMANHO_VETOR;
    int var_control = 0;
    Contato lista_contatos[32];
    inicializa_lista(lista_contatos);

    while(var_control != 10){
        printar_menu();
        scanf("%i", &var_control);
        //system("clear");

        switch (var_control)
        {
        // Inserir Contato
        //Transformar em função
        case 1:
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
            if(espacos_livre == 32){
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

        case 9:

            break;
        }
    }
    return 0;
}