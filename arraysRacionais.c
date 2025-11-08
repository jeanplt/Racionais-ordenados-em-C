#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "racionais.h"

/* Funcao que ajusta os parametros para qsort como ordenador */
int compara_QS (const void *a, const void *b) 
{
    struct racional *r1 = (struct racional *)a;
    struct racional *r2 = (struct racional *)b;

    return compara_r(*r1, *r2);
}

int main ()
{
    /* Variaveis para leitura e indice */
    int N, i, j;

    /* Inicializador de valores aleatorios com base no tempo e leitura de dados */
    srand(time(NULL));
    scanf("%d", &N);

    /* Structs para o vetor e a soma */
    struct racional vet[N], Soma;

    /* Sorteia racionais para o vetor e imprime esses racionais */
    for (i = 0; i < N; i++)
    {
        vet[i] = sorteia_r(N);
        imprime_r(vet[i]);
        printf(" ");
    }

    /* Quebra de linha e índice temporário */
    printf("\n");
    j = 0;

    /* Exclui racionais invalidos do vetor e imprime o restante */
    for (i = 0; i < N; i++)
    {
        /* Avalia o racional do indice para exclusao ou nao do vetor */
        if (valido_r(vet[i]))
        {
            imprime_r(vet[i]);
            printf(" ");
            vet[j] = vet[i];
            j++;
        }
    }
    
    N = j;
    printf("\n");

    /* Ordena o vetor de racionais com base no quicksort e seus parametros ajustados */
    qsort(vet, N, sizeof(struct racional), compara_QS);

    /* Imprime o vetor ordenado */
    for (i = 0; i < N; i++)
    {
        imprime_r(vet[i]);
        printf(" ");
    }

    printf("\n");
    
    /* Inicializacao da soma com 0 */
    Soma = cria_r(0, 1);
    i = 0;

    /* Acumula a soma dos elementos do vetor */
    while (i < N - 1)  
    {
        soma_r(vet[i], vet[i + 1], &Soma);
        i += 2;
    }

    /* Verifica se o tamanho do vetor eh impar para somar ultimo elemento */
    if (N % 2 == 1)
        soma_r(vet[N - 1], Soma, &Soma);
    
    /* Espacamento e impressao do racional da soma */
    printf("a soma de todos os elementos eh: ");
    imprime_r(Soma);
    printf("\n");

    return 0;
}
