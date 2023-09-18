#include <stdio.h>
#include </home/abner/Desktop/Codes/Projeto Hash/collisionHash/C/src/contato.c>
#include </home/abner/Desktop/Codes/Projeto Hash/collisionHash/C/src/menu.c>


//"1-Inserir Contato\n2-Remover Contato\n3-Listar Contatos\n4-Buscar Contato\n8-Sair do Programa\n"

int main(){
    int espacos_livre = TAMANHO_VETOR;
    int var_control = 0;
    Contato lista_contatos[32];
    inicializa_lista(lista_contatos);

    while(var_control != 10){
        printar_menu();
        scanf("%i", &var_control);
        system("clear");

        switch (var_control)
        {
        // Inserir Contato
        case 1:
            if(espacos_livre == 0)
            {
                printf("Agenda cheia.\n");
                break;
            }
            Contato novo_contato;
            novo_contato = cria_contato(); // Cria um novo contato e aloca na varíavel novo_contato
            int contato_conc = concatenacao(novo_contato.numero);
            insere_contato(lista_contatos,contato_conc,novo_contato);
            espacos_livre--;
            break;

        // Remover Contato
        case 2:
            deleta_contato(lista_contatos);
            break;

        // Listar Contato
        case 3:

            break;

        // Buscar Contato
        case 4:

            break;

        // Sair do programa
        case 9:

            break;
        }
    }
    return 0;
}