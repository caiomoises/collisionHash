# Collision Hash

#### Docente:
- [ Kennedy Reurison Lopes](https://github.com/kennedyufersa)

#### Monitor:
- [Marcos Mikael Lima Vidal](https://github.com/Bazchh)

#### Discentes:
- [Caio Moisés Vieira Cavalcante](https://github.com/caiomoises)
- [Francisco Gerliano de Oliveira Souza](https://github.com/sgerliano)
- [Abner Gama Torres](https://github.com/bnerTT)
- [Vladimyr de Oliveira Guedes](https://github.com/vladguedes)

#### SUMARIO

- [Introdução](#introdução)
- [Descrição geral do código](#descrição-geral-do-código)
- [Funções em C e Python](#funções-em-c-e-python)



## Introdução

Collision Hash é um codigo criado para armazenar o número de contato de 32 pessoas utilizando o metodo da divisão para encontrar o local de armazenamento, quando houver . É calculado o resto de divisão do numero do contato pelo numero total de contatos que serão inseridos, dessa forma encontrando o numero do slot que o contato será armazenado. Os valores de slot neste problema varia de 0 a 31. 

- Exemplo:
    
        Nome: João
        Número: 8496325689
        Email: joao@gmail.com

        Calculando: 8496325689 % 32 = 25

Logo, o contato de João será armazenado na posição/slot de número 25.

## DESCRIÇÃO GERAL DO CÓDIGO

#### VISÃO GERAL

 - O código foi desenvolvido utilizando as linguagens de programação C e Python, os dois códigos possuem as mesmas funções, estas estão descritas abaixo.

#### FUNÇÕES EM C E PYTHON
 - INICIALIZA_LISTA:

       Esta função inicializa uma lista de contatos, percorrendo cada elemento da lista e definindo o número do contato como uma string vazia.

 - CRIA_CONTATO:

       Esta função cria um novo objeto de contato, solicitando ao usuário que insira o nome, número e email do contato e retornando esse novo contato criado.

- HASH_FUNCTION:

      Uma função que implementa uma função de hash, que é usada para determinar a posição de armazenamento de um contato na lista de contatos com base em sua chave (número de contato) e no número de tentativas de colisão.

- CONCATENACAO:

      Esta função calcula um valor de chave (hash) para uma string dada c, somando os valores ASCII de seus caracteres.

- RETORNA_INDEX_VAZIO:

      Esta função retorna o índice vazio (posição de armazenamento) na lista de contatos com base na chave calculada a partir do número do contato.

- RETORNA_INDEX_COMPARACAO:

      Esta função retorna o índice na lista de contatos onde um contato com um número específico (elemento_comparado) está armazenado, com base na chave calculada a partir do número de contato.

- INSERE_CONTATO:

      Esta função insere um novo contato na lista de contatos, calculando sua posição com base na função de hash e garantindo que não haja colisões.

- DELETA_CONTATO:

      Remove um contato da lista de contatos com base no número de contato fornecido pelo usuário.

- ATUALIZA_ARQUIVO_CONTATOS:

      Atualiza um arquivo de texto que contém os contatos, gravando os contatos atuais na lista em formato de texto.

- IMPRIME_CONTATOS:

      Lê o arquivo de contatos e imprime seu conteúdo na tela.

- BUSCAR_CONTATOS:

      Busca um contato na lista com base no número de contato fornecido pelo usuário e imprime os detalhes do contato se encontrado.

- EDITA_CONTATO:

      Permite ao usuário editar as informações de um contato existente na lista, como nome, número ou e-mail.

- IMPORTAR_CONTATOS:

      Lê os contatos de um arquivo de texto e os importa para a lista de contatos.

- EXPORTAR_CONTATOS:

       Exportar os contatos da lista para um arquivo de texto, substituindo o conteúdo existente pelo novo conteúdo da lista.


