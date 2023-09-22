from contato import *

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
            novo_contato = cria_contato()
            insere_contato(lista_contatos, novo_contato)
        elif opcao == 2:
            deleta_contato(lista_contatos)
        elif opcao == 3:
            imprime_contatos(lista_contatos)
        elif opcao == 4:
            buscar_contato(lista_contatos)
        elif opcao == 5:
            edita_contato(lista_contatos)
        elif opcao == 6:
            espacos_livres = importar_contatos(lista_contatos, espacos_livres)
        elif opcao == 7:
            exportar_contatos(lista_contatos)
        elif opcao == 8:
            break
        else:
            print("Opção inválida. Tente novamente.")