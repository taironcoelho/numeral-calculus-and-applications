#include <stdio.h>
#include <math.h>

/* N estabelece quantos pontos tem a tabela
	M estabelce quantos termos tem a função aproximadora */

int N, M;
float X[30], Y[30];
float A[30][30], B[30];

/* esta rotina le via teclado os pontos X e Y */
void readData()
{
    int i;

    printf("Numero de pontos: n= ");
    scanf("%d", &N);
    printf("\nDigite X e Y separados por espacos. \n\n");
    for(i=0;i<N;i++)
    {
        printf("[%3d] ",i+1);
        scanf("%f", &(X[i]));
        scanf("%f", &(Y[i]));
    }

	M = N-1;
}

// Função recursiva que eleva x na n
float pot(float x, int n)
{
	if (n)
	return x*pot(x, n-1);
	else return 1.0;
}

// Função que monta o sistema linear
void linearSystem()
{
	int i, j;

	for (i=0; i<=M; i++)
	{
		for(j=0; j<=M; j++)
		A[i][j] = pot(X[i],j);
		B[i] = Y[i];
	}
}

/* calculo do determinante de uma matriz 2x2 */
float det(float a, float b, float c, float d)
{
	return (a*d)-(b*c);
}

/* faz a triangulação do sistema pelo métodode Gauss */
void TriGauss()
{
	int i, j, k;

	for (k=0; k<=(M-1); k++)
	{
		for ( i=k+1; i<=M; i++)
		{
			for ( j=k+1; j<=M; j++ )
			A[i][j] = det( A[k][k], A[i][k], A[k][j], A[i][j]);
			B[i] = det( A[k][k], A[i][k], B[k], B[i]);
			A[i][k] = 0;
		}
	}
}

/* calcula a matriz das soluções do sistema ja triangularizado */
void SolGauss()
{
	int k, j;
	float s;

	X[M] = B[M]/A[M][M];
	for ( k=M-1; k>=0; k-- )
	{
		s = 0;
		for ( j=k+1; j<=M; j++ )
		s+=A[k][j]*X[j];
		X[k]=(B[k]-s)/A[k][k];
	}
}

// Função exibe os resultados na matriz solução
void results()
{
	int i;

	printf("\n\nPolinomio interpolador:\n");
	printf("p(x)=");
	for ( i=0; i<=M; i++ )
	{
		printf("%g",X[i]);
		if (i) printf("x");
		if (i>1) printf("^%d",i);
		if (i<M) printf(" + ");
	}
}

void 	interpolate()
{
	int i;
	float x, y;

	printf("\n\nValor a ser interpolado: ");
	scanf("%f",&x);
	for ( i=0, y=0; i<=M; i++ )
	y += X[i] * pot(x,i);
	printf("\np(%g) = %g \n\n", x, y);
}

/* programa principal */
void main()
{
	readData();
	linearSystem();
	TriGauss();
	SolGauss();
	results();
	for(;;) interpolate();
	return 0;
}
