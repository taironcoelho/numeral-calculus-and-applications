#include <iostream>
#include <math.h>
#include <stdio.h>
#define M 2

int N;
float X[30],Y[30];
float A[30][30], B[30];

float g0(float x)
{
	return 1;
}

float g1(float x)
{
	return x;
}

void ledados()
{
	int i;

	printf("Numero de pontos: n= ");
	scanf("%d",&N);
	printf("\n\nDigite X e Y Serapados por espaço.\n\n");
	for (i = 0; i < N; i++)
	{
		printf("[%3d] ",i+1);
		scanf("%f",&(X[i]));
		scanf("%f",&(Y[i]));
	}

}

float funcao(int i,int k)
{
	switch (i)
	{
		case 0:return(g0(X[k]));
		case 1:return(g1(X[k]));
	}
	return 0;
}

void sistemanormal ()
{
	int i,j,k;
	float r,s;

	for (i = 0; i < M; i++)
	{
		for (j=0;j<M;j++)A[i][j]=0;
		B[i]=0;

	}
	for (k = 0; k < N; k++)
	{
		for (i = 0; i < M; i++)
		{

			r=funcao (i,k);
			B[i]+=r*Y[k];
			for (j = 0; j<M; j++)
			{
				s=funcao (j,k);
				A[i][j]+=r*s;

			}
		}
	}
}

float det (float a,float b, float c,float d)
{
	return (a*d)-(b*c);
}

void Show ()
{
	int i,j;
	printf("Ordem do Sistema: N= %d\n\n\n",N);
	for (i = 0; i < M; i++)
	{
		for (j = 0; j < M; j++)printf("  %12.6f",A[i][j]);
		printf("  %12.6f\n",B[i]);
	}
	printf("\n\n\n<ENTER> ");
	std::cin.get();
	std::cin.get();
}

void trigauss()
{
	int i,j,k;
	for (k = 0; k < (M-1); k++)
	{
		for (i = k+1; i < M; i++)
		{
			for (j = k+1; j<M; j++)
			A[i][j]=det(A[k][k],A[i][k],A[k][j],A[i][j]);
			B[i]=det(A[k][k],A[i][k],B[k],B[i]);
			A[i][k]=0;
		}
	}
}

void solgauss()
{
	int k,j;
	float s;
	X[M-1]=B[M-1]/A[M-1][M-1];
	for (k = M-2; k >= 0; k--)
	{
		s=0;
		for (j = k+1; j < M; j++)
		{
			s+=A[k][j]*X[j];
			X[k]=(B[k]-s)/A[k][k];
		}

	}
}

void imprime()
{
	int i;
	printf("\n\nSolução do sistema linear\n");
	for (i = 0; i < M; i++)
		printf("a(%3d)=%10.6g\n",i,X[i]);
	printf("\n\n\nProblema encerrado.\n");
}

int main()
{
	ledados();
	sistemanormal();
	trigauss();
	Show();
	solgauss();
	imprime();
	std::cin.get();
    std::cin.get();
}

