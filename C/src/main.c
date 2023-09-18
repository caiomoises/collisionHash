#include <stdio.h>
#include </home/abner/Desktop/Codes/Projeto Hash/collisionHash/C/src/contato.c>
#include </home/abner/Desktop/Codes/Projeto Hash/collisionHash/C/src/menu.c>


//"1-Inserir Contato\n2-Remover Contato\n3-Listar Contatos\n4-Buscar Contato\n8-Sair do Programa\n"

int main(){
    int var_control = 0;
    Contato lista_contatos[32];
    inicializa_lista(lista_contatos);

    while(var_control != 10){
        printar_menu();
        scanf("%i", &var_control);
        system("cls");
        
        switch(var_control){
            //Inserir Contato
            case 1:
            Contato novo_contato;  
            novo_contato = cria_contato(); //Cria um novo contato e aloca na varíavel novo_contato
            int contato_conc = concatenacao(novo_contato.numero);
            int probe = 0; // Serve para o caso de ocorrência de colisão
            int index; //Index onde será armazenado o novo contato após o hash
            while (1)
            {
                index = hash_function(contato_conc, probe);
                if ((strcmp(lista_contatos[index].numero, "0")) == 0)
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
            lista_contatos[index] = novo_contato;
            break;

            //Remover Contato
            case 2:
            
            break;

            //Listar Contato
            case 3:
            
            break;

            //Buscar Contato
            case 4:
            
            break;

            //Sair do programa
            case 9:

            break;



        }
    }
    return 0;
}