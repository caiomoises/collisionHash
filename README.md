# Collision Hash

#### Integrantes:
- [Caio Moisés Vieira Cavalcante](https://github.com/caiomoises)
- [Francisco Gerliano de Oliveira Souza](https://github.com/sgerliano)
- [Abner Gama Torres](https://github.com/bnerTT)
- [Vladimyr de Oliveira Guedes](https://github.com/SrVlady)

Collision Hash é um codigo criado para armazenar o número de contato de 32 pessoas utilizando o metodo da divisão para encontrar o local de armazenamento, quando houver . É calculado o resto de divisão do numero do contato pelo numero total de contatos que serão inseridos, dessa forma encontrando o numero do slot que o contato será armazenado. Os valores de slot neste problema varia de 0 a 31. 

- Exemplo:
    
        Nome: João
        Número: 8496325689
        Email: joao@gmail.com

        Calculando: 8496325689 % 32 = 25

Logo, o contato de João será armazenado na posição/slot de número 25.
