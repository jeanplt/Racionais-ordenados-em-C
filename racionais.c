#include <stdio.h>
#include <stdlib.h>
#include "racionais.h"

int aleat (int min, int max)
{
    return min + rand() % (max - min + 1);
}

int mdc (int a, int b)
{
    /* Variavel temporaria para possibilitar trocas de a com b */
    int temp;

    /* Laço do MDC, metodo de Euclides */
    while (b != 0)
    {
        a %= b;
        temp = a;
        a = b;
        b = temp;
    }

    return a;
}

int mmc (int a, int b)
{
    return a*b/mdc(a,b);
}

struct racional cria_r (int numerador, int denominador)
{
    struct  racional r;

    /* Propriedades do racional */
    r.num = numerador;
    r.den = denominador;
    /* Verifica se o racional eh valido */
    r.valido = valido_r(r);

    return r;
}

struct racional sorteia_r (int max)
{
    struct racional r;

    /* Gera o numerador e denominador aleatorio para o racional e o valida  */
    r.num = aleat(0, max);
    r.den = aleat(0, max);
    r.valido = valido_r(r);

    /* Verifica se o racional eh valido para simplifica-lo */
    if (r.valido)
        simplifica_r(&r);

    return r;
}

/* Nao utilizada */
int numerador_r (struct racional r)
{
    return r.num;
}

/* Nao utilizada */
int denominador_r (struct racional r)
{
    return r.den;
}

int valido_r (struct racional r)
{
    if (r.den == 0)
        return 0;

    return 1;
}

void imprime_r (struct racional r)
{
    /* Verificações todos os casos especiais do Racional, antes da impressao */
    if (!r.valido)
    {
        printf("INVALIDO");
        return;
	}
	
    if (r.num == 0)
    {
        printf("0");
        return;
    }
    
    if (r.den == 1)
    {
        printf("%d", r.num);
        return;
    }
       
    if (r.num == r.den)
    {
        printf("1");
        return;
    }
    
    if (r.num < 0 && r.den < 0)
    {
        printf("%d/%d", -r.num, -r.den);
        return;
	}
	
    if (r.num < 0 || r.den < 0)
    {
        printf("-%d/%d", abs(r.num), abs(r.den));
        return;    
    }
     
    printf("%d/%d", r.num, r.den);
}

int compara_r (struct racional r1, struct racional r2)
{
    /* Calcula os racionais para valores de ponto flutuante, para comparar ate suas casas decimais */
    double v_r1 = (double)r1.num / r1.den;
    double v_r2 = (double)r2.num / r2.den;

    if (v_r1 < v_r2)
        return -1;
    
    if (v_r1 == v_r2)
        return 0;
    
    return 1;
}

int simplifica_r (struct racional *r)
{
    if (!r->valido)
        return 0;
    
    /* Variavel para receber o MDC de num e den de r */
    int MDC = mdc(r->num, r->den);

    r->num /= MDC;
    r->den /= MDC;

    /* Troca o sinal caso r seja negativo */
    if (r->den < 0)
    {
        r->num = -r->num;
        r->den = -r->den;
    }

    return 1;
}

int soma_r (struct racional r1, struct racional r2, struct racional *r3)
{
    if (!r1.valido || !r2.valido)
        return 0;
    
    /* Propriedades da soma de racionais */
    r3->den = mmc(r1.den, r2.den);

    int Tnum1 = r1.num * (r3->den/r1.den);
    int Tnum2 = r2.num * (r3->den/r2.den);

    r3->num = Tnum1 + Tnum2;
    r3->valido = 1;

    /* Simplificacao de r3 pois r1 e r2 são validos logo r3 tambem sera na soma */
    simplifica_r(r3);

    return 1;
}

/* Nao utilizada */
int subtrai_r (struct racional r1, struct racional r2, struct racional *r3)
{
    if (!r1.valido || !r2.valido)
        return 0;
    
    /* Propriedades da subtracao de racionais */
    r3->den = mmc(r1.den, r2.den);

    int Tnum1 = r1.num * (r3->den/r1.den);
    int Tnum2 = r2.num * (r3->den/r2.den);

    r3->num = Tnum1 - Tnum2;
    r3->valido = 1;

    /* Simplificacao de r3 pois r1 e r2 são validos logo r3 tambem sera na subtracao */
    simplifica_r(r3);

    return 1;
}

/* Nao utilizada */
int multiplica_r (struct racional r1, struct racional r2, struct racional *r3)
{
    if (!r1.valido || !r2.valido)
        return 0;

    /* Propriedades da multiplicacao de racionais */
    r3->num = r1.num * r2.num;
    r3->den = r1.den * r2.den;
    r3->valido = 1;

    /* Simplificacao de r3 pois r1 e r2 são validos logo r3 tambem sera na multiplicacao */
    simplifica_r(r3);

    return 1;
}

/* Nao utilizada */
int divide_r (struct racional r1, struct racional r2, struct racional *r3)
{
    if (!r1.valido || !r2.valido)
        return 0;

    /* Propriedades da divisao de racionais e validacao pela funcao valido_r */
    r3->num = r1.num * r2.den;
    r3->den = r1.den * r2.num;
    r3->valido = valido_r(*r3);

    /* Verifica se o resultado eh valido para confirmar retorno da funcao */
    if (r3->valido == 0)
    	return 0;

    simplifica_r(r3);

    return 1;
}
