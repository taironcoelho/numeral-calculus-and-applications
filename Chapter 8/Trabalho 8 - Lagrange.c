#include <stdio.h>
#include <math.h>

int N;
float X[30], Y[30];
float interpolator, ret;

/* esta rotina le via teclado os pontos X e Y */
void LerDados()
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
}

float Lagrange ( float interpolator )
{
	float p, num, den;
	int i, j;

	p = 0;
	for(i=0;i<N;i++)
	{
		num = 1;
		den = 1;
		for(j=0; j<N; j++)
		if (j != i)
		{
			num *= interpolator - X[j];
			den *= X[i] - X[j];
		}
		p += num * Y[i] / den;
	}
	return p;
}

void main()
{
	LerDados();
	for(;;)
	{
		printf("\nX = ");
		scanf("%f",&interpolator);
		ret = Lagrange(interpolator);
		printf("\nValor Interpolado pelo polinomio de Lagrange:\n");
		printf("p(%g) = %g\n", interpolator, ret);
	}
	return 0;
}
