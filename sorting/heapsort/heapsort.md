# Aula Heapsort

É um algoritmo de ordenação por comparação de chaves.

## Heaps

São estruturas de dados na forma de árvores binárias completas, exceto possivelmente o último nível, sendo preenchido mais à esquerda. Cada nó possui uma chave e segue uma dada propriedade em relação ao seu nó pai. No caso do *heapsort*, onde utilizamos o *max heap*, esta propriedade dita que todo nó tem de ser menor que o seu nó pai.

De modo a economizar espaço, um *heap* pode ser representado como um vetor. Logo, para problemas de ordenação de um vetor $A$, podemos representar o *heap* neste mesmo vetor, usando dois atributos extras: *heap-size* e *length*, que é o tamanho do vetor. Dado que o primeiro dita o tamanho do *heap* que pode ser menor que o vetor, temos:
$$
0 \leq A.heap\text{-}size \leq A.length
$$
Dado que a raíz está no elemento $A[1]$, temos os seguintes três algoritmos para percorrer o *heap*:

**`Parent`: retorna a posição do pai de um nó $i$**

```
Parent(i):
  return bottom(1/2)
```

**`Left`: retorna o filho à esquerda do nó $i$**

```
Left(i):
  return 2i
```

**`Right`: retorna o filho à direita do nó $i$**

```
Right(i):
  return 2i + 1
```

Dado os *max heaps*, observe que:

- O maior nó se encontra na raíz;
- Definimos a altura de um nó $i$, como o tamanho do menor caminho da raíz até este nó;
- Dado que um *heap* de $n$ elementos é um árvore binária, sua altura está em $\Theta(\lg n)$. 

## Mantendo um *Max Heap*

De modo a manter a propriedade um *max heap*, é empregado o algoritmo `MaxHeapify(A, i)`. Quando chamado, assume que as subárvores em `Left(i)` e `Right(i)` seguem a propriedade, mas o elemento $i$ pode ser menor que seus filhos. 

Portanto, o algoritmo checa se o nó $i$ é maior que os seus dois filhos. Caso positivo, o algoritmo não altera a estrutura do *heap* e termina. Caso negativo, o algoritmo troca a posição do elemento $i$ com o maior dentre seus dois filhos. Por fim, aplica-se, recursivamente, o mesmo procedimento na subárvore que foi alvo da troca, garantindo que o elemento trocado seja colocado na posição correta do *heap*.

```
MaxHeapify(A,i):
  l = Left(i)
  r = Right(i)
  if l <= A.heap-size and A[l] > A[i]
	largest = l
  else
  	largest = i
  if r <= A.heap-zie and A[r] > A[i]
    largest = r
  if lagest != i
    exchange A[i] with A[largest]
    MaxHeapify(A,largest)
end
```

**Tempo de Execução**

O custo é dado pelas operações em $\Theta(1)$ para trocar a posição do nó $i$ com algum dos seus filhos, caso estes sejam menores que ele. Se for o caso, computamos também a execução recursiva na subárvore correspondente. Dado que essa subárvore terá no máximo $\frac{2}{3}$ dos elementos do heap, temos a seguinte equação de recorrêcia:
$$
T(n) \leq T(\frac{2n}{3}) + \Theta(1)
$$
Usando o caso 2 do Teorema Mestre, onde $a = 1, b = \frac{3}{2}$ e $f(n) = 1$, temos que $f(n) = \Theta(n^{\log_{3/2}1}) = \Theta(1)$ e, portanto, $T(n) \in O(n^0\lg n) = \Theta(\lg n)$.

## Construindo um *Max Heap*

De modo a converter um vetor em um *max heap* utilizamos o seguinte algoritmo:

## *Heapsort*