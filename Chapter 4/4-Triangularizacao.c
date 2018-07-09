#include <stdio.h>

int N;
float b[30];
float x[30];
float a[30][30];

// Função que le a ordem do sistema, le as linhas da matriz de coeficientes e a matriz de resultados

void LeMatriz()
{
    int i, j;

    printf("Ordem do sistema: n= ");
    scanf("%d", &N);
    printf("\n\nDigite os valores separados por espacos.\n");
    for(i=0; i<N; i++)
    {
        printf("linha %3d:\n", i+1);
        for(j=0; j<N; j++)
        {
            scanf("%f", &(a[i][j]));
        }
        scanf("%f", &(b[i]));
    }
}

float det(float a, float b, float c, float d)
{
    return (a*d)-(b*c);
}

//Função que faz a triangulação

void Triang()
{
    int i, j, k;

    for(k=0; k<(N-1); k++)
    {
        for(i = k+1; i<N; i++)
        {
            for(j=k+1; j<N; j++)
            {
                a[i][j] = det(a[k][k], a[i][k], a[k][j], a[i][j]);
            }
            b[i] = det(a[k][k], a[i][k], b[k], b[i]);
            a[i][k] = 0;
        }
    }
}

//Calcula a matriz das solucoes do sistema ja triangularizado

void Solucao()
{
    int k, j;
    float s;

    x[N-1] = b[N-1]/a[N-1][N-1];
    for(k=N-2; k>=0; k--)
    {
        s=0;
        for(j=k+1; j<N; j++)
        {
            s+=a[k][j]*x[j];
            x[k]=(b[k]-s)/a[k][k];
        }
    }
}
//Mostra o resultado da matriz de solucoes

void Imprime()
{
    int i;

    printf("\n\nSolucao do sistema linear\n");
    for(i=0; i<N; i++)
    {
        printf("x(%3d)=%10.6g\n", i,x[i]);
        printf("\n\n\nProblema encerrado.\n");
    }
}

int main()
{
    LeMatriz();
    Triang();
    Solucao();
    Imprime();
    getch();
}
