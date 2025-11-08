# Racionais-ordenados-em-C
Este repositório contém um programa modular que realiza operações com racionais de inteiros, sendo estas operações feitas com ponteiros, número aleatórios, ordenação de vetor de racionais  e operações como soma e simplificação de racionais.

Tratando-se de um trabalho acadêmico, segue abaixo seu enunciado adaptado para melhor contextualização.

Este trabalho tem como objetivo operar com o Tipo Abstrato de Dados (TAD) para números racionais utilizando funções recebam parâmetros por ponteiros. Para este trabalho, temos os seguintes arquivos base contidos:
- racionais.h: arquivo de header com todos os protótipos das funções para manipular números racionais;
- racionais.c: um esqueleto do arquivo racionais.c;
- makefile: ferramenta de compilação;

No arquivo racionais.h foi definida uma interface para o tipo abstrato de dados racional que usa uma struct para os números racionais do tipo A/B, com A e B inteiros. Foi implementado o arquivo racionais.c conforme especificado no racionais.h fornecido. A função main inclui o header racionais.h e implementa corretamente em C o seguinte pseudo-código:

```
inicialize a semente randomica, uma unica vez em todo o codigo
- sugestao: use "srand (0)" para facilitar os testes
leia um n tal que 0 < n < 100
crie um vetor de n posicoes contendo numeros racionais aleatorios
imprima este vetor
elimine deste vetor os elementos invalidos
imprima o vetor resultante
ordene este vetor
imprima o vetor ordenado
calcule e imprima a soma de todos os elementos do vetor
retorne 0
```

Por fim, o programa imprime os elementos do vetor em uma única linha usando um único espaço em branco para separar os elementos, e ao final de um vetor é mudado de linha para o próximo, até todos os vetores serem impressos.
