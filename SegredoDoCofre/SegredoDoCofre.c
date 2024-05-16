#include <stdio.h>
#define MIN_N 2
#define MAX_N 100000
#define MIN_M 2
#define MAX_M 100000

void printTeste( int *array, int tamanho )
{
    for(int i = 0; i < tamanho; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main(void)
{
    
    int n_posicoes;
    int m_movimentos;

    if(scanf("%d", &n_posicoes) != 1)
    {
        printf("falha ao ler inteiro\n");
    }
    
    if( n_posicoes < MIN_N )
    {
        printf("erro posicao menor que MIN_N\n");
        return 1;
    }
    else if( n_posicoes > MAX_N )
    {
        printf("erro posicao maior que MAX_N\n");
        return 2;
    }

    if(scanf("%d", &m_movimentos) != 1)
    {
        printf("falha ao ler inteiro\n");
    }


    if( m_movimentos < MIN_M )
    {
        printf("erro posicao menor que MIN_M\n");
        return 3;
    }
    else if( m_movimentos > MAX_M )
    {
        printf("erro posicao maior que MAX_M\n");
        return 4;
    }

    int posicoes[MAX_N];
    int movimentos[MAX_M];

    for(int i = 0; i < n_posicoes; i++)
    {
        int scan = 0;
        if(scanf("%d", &scan) != 1)
        {
            printf("falha ao ler inteiro\n");
        }

        if( scan < 0 || scan > 9)
        {
            printf("erro numero presente em posicao invalido\n");
            return 5;
        }
        posicoes[i] = scan;
    }

    for(int i = 0; i < m_movimentos; i++)
    {
        int scan = 0;
        if(scanf("%d", &scan) != 1)
        {
            printf("falha ao ler inteiro\n");
        }

        if( scan < 0 || scan > n_posicoes )
        {
            printf("erro movimentacao fora de alcance\n");
            return 6;
        }

        movimentos[i] = scan;
    }

    int resultado[10];

    for(int i = 0; i < m_movimentos - 1; i++)
    {
        if(movimentos[i] < movimentos[i + 1])
        {
            for(int j = movimentos[i] - 1; j < movimentos[i + 1] - 1; j++)
            {
                resultado[posicoes[j]]++;
            }
        }
        else if(movimentos[i] > movimentos[i + 1]) 
        {
            for(int j = movimentos[i] - 1; j >= movimentos[i + 1]; j--)
            {
                resultado[posicoes[j]]++;
            }
        }
    }
    resultado[posicoes[movimentos[m_movimentos-1]-1]]++;

    printTeste(resultado, 10);
    return 0;
}
