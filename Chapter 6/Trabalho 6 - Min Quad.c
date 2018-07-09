#include <stdio.h>
#include <math.h>

int N;
float X[30], Y[30];
float A[2][3]; /* A terceira coluna de A equivale a coluna A[2];

/*Funcao leitura via teclado os pontos X e Y*/

void LeDados()
{
    int i;
    N = 11;
    //printf("Numero de pontos: n= ");
    //scanf("%d", &N);
    //printf("\n\nDigite X e Y separados por espacos.\n\n");
    X[0] = 1971;
    X[1] = 1972;
    X[2] = 1974;
    X[3] = 1978;
    X[4] = 1982;
    X[5] = 1986;
    X[6] = 1989;
    X[7] = 1993;
    X[8] = 1997;
    X[9] = 1999;
    X[10] = 2000;

    Y[0] = log10f(2250);
    Y[1] = log10f(3300);
    Y[2] = log10f(6000);
    Y[3] = log10f(29000);
    Y[4] = log10f(134000);
    Y[5] = log10f(275000);
    Y[6] = log10f(1200000);
    Y[7] = log10f(3100000);
    Y[8] = log10f(7500000);
    Y[9] = log10f(20000000);
    Y[10] = log10f(42000000);
    /*for(i=0; i<N; i++)
    {
        printf("[%3d] ", i+1);
        scanf("%f", &(X[i]));
        scanf("%f", &(Y[i]));
    }*/
}

void MontaSistema()
{
    int i;
    float s;

    A[0][1] = 0;
    A[0][2] = 0;
    A[1][1] = 0;
    A[1][2] = 0;

    for(i=0; i<N; i++)
    {
        A[0][1] += X[i];
        A[1][1] += X[i]*X[i];
        A[0][2] += Y[i];
        A[1][2] += X[i]*Y[i];
    }
    A[0][0] = N;
    A[1][0] = A[0][1];
}

float det(float a, float b, float c, float d)
{
    return (a*d) - (b*c);
}

int main()
{
    float a,b;

    LeDados();
    MontaSistema();

    a = det(A[0][2], A[0][1], A[1][2], A[1][1])/ det(A[0][0], A[0][1], A[1][2], A[1][1]);
    b = det(A[0][0], A[0][2], A[1][0], A[1][2])/ det(A[0][0], A[0][1], A[1][0], A[1][1]);

    printf("g(x) = %10.6f + %10.6f x\n<ENTER> ", a, b*2);
    getch();

    return 0;
}


