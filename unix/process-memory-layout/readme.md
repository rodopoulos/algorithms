# Gerenciamento de Memória no Linux

Todo processo do Linux possui um espaço de endereçamento na memória composto por 3 segmentos: código, dados e pilha.

### Segmento de Código

O segmento de código é a seção que contém as instruções de máquina do programa, sendo uma região de tamanho fixo e marcado como *readonly*. Logo, é uma região estática.

### Segmento de Dados



### Pilha

A pilha é o segmento localizado na porção superior da memória do programa e irá guardar variáveis locais e parâmetros de cada função chamada. Logo, assim que um programa inicia, os primeiros dados a serem contidos nela são os argumentos iniciais do programa. 

A cada chamada de função, um novo *stack frame* é inserido na pilha e só será removido e destruído quando esta função acabar, ou seja, quando executar sem `return`. Como a política desta área é uma política simples de pilha, não há necessidade de criar uma estrutura complexa para este controle, apenas um ponteiro para o topo da pilha é suficiente e as operações de inserção e remoção da *stack frames* são pouco custosas.

