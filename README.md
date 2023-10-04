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
- [Implementação](#implementação)
- [Testes e resultados](#testes-e-resultados)
- [Desafios e soluções](#desafios-e-soluções)
- [Conclusão](#conclusão)
- [Código fonte](#codigo-fonte)
- [Clonando o código](#clonando-o-código)
- [Referências](#referências)



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


## IMPLEMENTAÇÃO

## TESTES E RESULTADOS

## DESAFIOS E SOLUÇÕES

Durante o desenvolvimento do projeto "Collision Hash", enfrentamos diversos desafios que demandaram criatividade e resolução de problemas. Abaixo, descrevemos alguns desses desafios e as soluções que implementamos para superá-los:

- Gestão de Colisões: Um dos principais desafios foi lidar com colisões, ou seja, situações em que dois ou mais contatos tinham a mesma posição de armazenamento calculada pela função de hash. Para resolver isso, implementamos uma estratégia de sondagem linear, que encontra o próximo slot vazio na lista de contatos e aloca o contato lá, garantindo que não haja sobreposição.

- Eficiência do Hash: Outro desafio foi criar uma função de hash eficiente que distribuísse os contatos de forma equitativa pelos slots disponíveis. Fizemos várias iterações e testes para aprimorar a função de hash, considerando fatores como a distribuição uniforme dos números de contato e o tratamento de possíveis colisões.
- Interação com o Usuário: A interação com o usuário por meio de entradas e saídas de dados era crucial para a utilidade do programa. Garantimos que as mensagens fossem claras e amigáveis, facilitando o uso do programa. Além disso, implementamos validações para garantir que as entradas do usuário fossem adequadas.
- Persistência de Dados: Manter os dados dos contatos após a execução do programa era um desafio. Implementamos funções de importação e exportação de contatos para um arquivo de texto, permitindo que os dados fossem armazenados e recuperados entre as execuções do programa.

- Gerenciamento de Memória: Em linguagens como C, o gerenciamento de memória é crítico. Tivemos que garantir a alocação e desalocação adequada de memória para evitar vazamentos de memória e erros de segmentação. Usamos alocação dinâmica de memória e liberamos a memória quando os contatos eram deletados.

Em suma, ao enfrentar esses desafios, aprendemos a importância da resolução de problemas e da flexibilidade durante o desenvolvimento de software. Cada desafio nos proporcionou uma oportunidade de aprimorar nossas habilidades de programação e encontrar soluções criativas para problemas complexos, resultando em um projeto funcional e eficaz, o "Collision Hash".

## CONCLUSÃO

Em conclusão, o projeto "Collision Hash" apresenta uma solução eficaz para armazenar informações de contato de 32 pessoas, utilizando o método da divisão para encontrar a posição de armazenamento dos contatos. O código foi desenvolvido em linguagens de programação C e Python e possui uma série de funções que permitem a criação, edição, exclusão, importação e exportação de contatos, garantindo a integridade dos dados e evitando colisões na alocação de slots.

Durante o processo de desenvolvimento deste projeto, aprendemos a importância de implementar funções de hash eficientes para evitar colisões e garantir o acesso rápido aos contatos armazenados. Além disso, a manipulação de arquivos de texto para a persistência de dados e a interação com o usuário para entrada e exibição de informações foram habilidades fundamentais adquiridas.

Em resumo, o "Collision Hash" é uma aplicação prática que demonstra a utilidade das funções de hash na organização de dados e nos proporcionou valiosos insights sobre o desenvolvimento de programas que envolvem manipulação de dados e interação com o usuário. Este projeto serve como um exemplo claro de como a programação pode resolver problemas do mundo real de forma eficiente e organizada.

## CODIGO FONTE

- [Link para repositório no GitHub](https://github.com/caiomoises/collisionHash.git)

## CLONANDO O CÓDIGO

- Abra o Visual Studio Code, caso não tenha instalado, clique no [link de download](https://code.visualstudio.com/download) para instalar.

- Com o VsCode aberto, vá na opção ‘Terminal’ e ‘New Terminal’;

- Com o terminal aberto, configure o Git usando os seguintes comandos:

      git config --global user.name “seu nome aqui”
      
      git config --global user.email “seu email aqui”

- Após o Git esta configurado, execute o seguinte comando para clonar o repositório:

      git clone https://github.com/caiomoises/collisionHash.git

Com isso, você terá acesso ao código fonte.

- Para executá-lo, abra novamente o terminal e digite os seguintes comandos:

      gcc main.c -o main

      ./main

## REFERÊNCIAS

- [Tabela hash - endereçamento aberto (parte 1) - YOUTUBE](https://www.youtube.com/watch?v=hSUT1fBIwlk )
- [Hashing - USP](https://www.ime.usp.br/~pf/estruturas-de-dados/aulas/st-hash.html)
- [Função Hashing - UFRJ](https://www.gta.ufrj.br/grad/09_1/versao-final/assinatura/hash.htm)