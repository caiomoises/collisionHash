from contato import *
import os

if __name__ == "__main__":
    lista_contatos = [Contato() for _ in range(TAMANHO_VETOR)]
    espacos_livres = TAMANHO_VETOR

    while True:
        print("\n1) Inserir contato")
        print("2) Deletar contato")
        print("3) Listar contatos")
        print("4) Buscar contato")
        print("5) Editar contato")
        print("6) Importar contatos")
        print("7) Exportar contatos")
        print("8) Sair")
        opcao = int(input("Escolha uma opção: "))

        if opcao == 1:
            os.system('cls')
            novo_contato = cria_contato()
            insere_contato(lista_contatos, novo_contato)
        elif opcao == 2:
            os.system('cls')
            deleta_contato(lista_contatos)
        elif opcao == 3:
            os.system('cls')
            imprime_contatos(lista_contatos)
        elif opcao == 4:
            os.system('cls')
            buscar_contato(lista_contatos)
        elif opcao == 5:
            os.system('cls')
            edita_contato(lista_contatos)
        elif opcao == 6:
            os.system('cls')
            espacos_livres = importar_contatos(lista_contatos, espacos_livres)
        elif opcao == 7:
            os.system('cls')
            exportar_contatos(lista_contatos)
        elif opcao == 8:
            break
        else:
            print("Opção inválida. Tente novamente.")