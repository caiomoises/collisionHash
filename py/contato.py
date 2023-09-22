from classe import *

def inicializa_lista(lista_contatos):
    for index in range(TAMANHO_VETOR):
        lista_contatos[index].numero = ""

def cria_contato():
    novo_contato = Contato()
    novo_contato.nome = input("Insira o nome do contato: \n")
    print(f"\nInsira o número de contato de {novo_contato.nome}: ")
    novo_contato.numero = input()
    print(f"\nInsira o email de {novo_contato.nome}: ")
    novo_contato.email = input()
    return novo_contato

def hash_function(key, tentativas):
    return ((key % TAMANHO_VETOR) + tentativas) % TAMANHO_VETOR

def concatenacao(c):
    key = 0
    for char in c:
        key += ord(char)
    return key

def retorna_index_vazio(lista_contatos, numero_conc):
    tentativas = 0
    while True:
        index = hash_function(numero_conc, tentativas)
        if lista_contatos[index].numero == "":
            return index

        if lista_contatos[index].numero != "":
            tentativas += 1

        if index > TAMANHO_VETOR:
            index = (TAMANHO_VETOR - index) * -1

def retorna_index_comparacao(lista_contatos, numero_conc, elemento_comparado):
    tentativas = 0
    while True:
        index = hash_function(numero_conc, tentativas)
        if lista_contatos[index].numero == elemento_comparado:
            return index

        if lista_contatos[index].numero != elemento_comparado:
            tentativas += 1

        if index > TAMANHO_VETOR:
            index = (TAMANHO_VETOR - index) * -1

        if tentativas == TAMANHO_VETOR:
            return -1

def insere_contato(lista_contatos, novo_contato):
    novo_concatenado = concatenacao(novo_contato.numero)
    index_vazio = retorna_index_vazio(lista_contatos, novo_concatenado)
    lista_contatos[index_vazio] = novo_contato

def deleta_contato(lista_contatos):
    numero_deleta = input("Insira o número do contato que deseja deletar:\n")
    cont_conc = concatenacao(numero_deleta)
    index = retorna_index_comparacao(lista_contatos, cont_conc, numero_deleta)
    if index != -1:
        lista_contatos[index].numero = ""
        lista_contatos[index].nome = ""
        lista_contatos[index].email = ""

        atualiza_arquivo_contatos(lista_contatos)
    else:
        print("Contato não cadastrado.")

def atualiza_arquivo_contatos(lista_contatos):
    with open("C:\\Users\\caiom\\Desktop\\projeto_AED\\collisionHash\\py\\contatos.txt", "w") as arquivo:
        for contato in lista_contatos:
            if contato.numero:
                arquivo.write(f"Nome: {contato.nome}\nNumero: {contato.numero}\nEmail: {contato.email}\n\n")

def imprime_contatos(contatos):
    try:
        with open("C:\\Users\\caiom\\Desktop\\projeto_AED\\collisionHash\\py\\contatos.txt", "r") as arquivo:
            conteudo = arquivo.read()
            if conteudo:
                print(conteudo)
            else:
                print("A lista de contatos está vazia.")
    except FileNotFoundError:
        print("O arquivo de contatos não foi encontrado.")
def buscar_contato(lista_contatos):
    numero_busca = input("Insira o número do contato que deseja buscar:\n")
    cont_conc = concatenacao(numero_busca)
    index = retorna_index_comparacao(lista_contatos, cont_conc, numero_busca)
    if index != -1:
        print(f"Nome: {lista_contatos[index].nome}\nNúmero: {lista_contatos[index].numero}\nEmail: {lista_contatos[index].email}\n")
    else:
        print("Contato não encontrado.")

def edita_contato(lista_contatos):
    numero_edita = input("Insira o número do contato que deseja editar:\n")
    var_controle = 0
    var_confirma = 0
    cont_conc = concatenacao(numero_edita)
    index = retorna_index_comparacao(lista_contatos, cont_conc, numero_edita)
    if index != -1:
        while var_controle != 4:
            print("Qual alteração você deseja fazer?\n1)Nome\n2)Número\n3)Email\n4)Sair\n")
            var_controle = int(input())
            if var_controle == 1:
                novo_nome = input(f"Insira o novo nome para o atual contato {lista_contatos[index].nome}:\n")
                print(f"Você irá mudar o nome do contato de {lista_contatos[index].nome} para {novo_nome}, tem certeza disso?\n1)Sim\t2)Não\n")
                var_confirma = int(input())
                if var_confirma == 1:
                    lista_contatos[index].nome = novo_nome
            elif var_controle == 2:
                novo_numero = input(f"Insira o novo número para o atual contato de {lista_contatos[index].nome}:\n")
                print(f"Você irá mudar o número de contato de {lista_contatos[index].nome} para {novo_numero}, tem certeza disso?\n1)Sim\t2)Não\n")
                var_confirma = int(input())
                if var_confirma == 1:
                    lista_contatos[index].numero = ""
                    novo_numero_conc = concatenacao(novo_numero)
                    novo_index = retorna_index_vazio(lista_contatos, novo_numero_conc)
                    lista_contatos[novo_index].numero = novo_numero
                    lista_contatos[novo_index].nome = lista_contatos[index].nome
                    lista_contatos[novo_index].email = lista_contatos[index].email
                    lista_contatos[index].nome = ""
                    lista_contatos[index].email = ""
            elif var_controle == 3:
                novo_email = input(f"Insira o novo email para o atual contato {lista_contatos[index].nome}:\n")
                print(f"Você irá mudar o email do contato de {lista_contatos[index].nome} para {novo_email}, tem certeza disso?\n1)Sim\t2)Não\n")
                var_confirma = int(input())
                if var_confirma == 1:
                    lista_contatos[index].email = novo_email
            elif var_controle == 4:
                break
    else:
        print("Contato não encontrado.")

def importar_contatos(lista_contatos, espacos_livres):
    contatos_importados = []
    arquivo_entrada = open("C:\\Users\\caiom\\Desktop\\projeto_AED\\collisionHash\\py\\contatos.txt", "r")
    if arquivo_entrada is None:
        print("Erro ao abrir o arquivo de contatos.")
        exit(1)

    for linha in arquivo_entrada:
        partes = linha.split("\t")
        if len(partes) == 3:
            novo_contato_importado = Contato()
            novo_contato_importado.numero = partes[0].split(": ")[1]
            novo_contato_importado.nome = partes[1].split(": ")[1]
            novo_contato_importado.email = partes[2].split(": ")[1]
            contatos_importados.append(novo_contato_importado)

    arquivo_entrada.close()
    return contatos_importados

def exportar_contatos(lista_contatos):
    with open("C:\\Users\\caiom\\Desktop\\projeto_AED\\collisionHash\\py\\contatos.txt", "w") as saida:
        for contato in lista_contatos:
            if contato.numero:
                saida.write(f"Nome: {contato.nome}\nNumero: {contato.numero}\nEmail: {contato.email}\n\n")