#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int n;
float a[20][20];
float b[20];
float x[20];
float sumXi, sumXi2, sumYi, sumXiYi;

void calculateData()
{
     int x1=1971, x2=1972, x3=1974, x4=1978, x5=1982, x6=1986, x7=1989, x8=1993, x9=1997, x10=1999, x11=2000;
     float y1=log10f(2250), y2=log10f(3300), y3=log10f(6000), y4=log10f(29000), y5=log10f(134000), y6=log10f(275000), y7=log10f(1200000), y8=log10f(3100000), y9=log10f(7500000), y10=log10f(9500000), y11=log10f(42000000);

     sumXi=(x1+x2+x3+x4+x5+x6+x7+x8+x9+x10+x11);
     sumXi2=(x1*x1)+(x2*x2)+(x3*x3)+(x4*x4)+(x5*x5)+(x6*x6)+(x7*x7)+(x8*x8)+(x9*x9)+(x10*x10)+(x11*x11);
     sumYi= y1+y2+y3+y4+y5+y6+y7+y8+y9+y10+y11;
     sumXiYi=(x1*y1)+(x2*y2)+(x3*y3)+(x4*y4)+(x5*y5)+(x6*y6)+(x7*y7)+(x8*y8)+(x9*y9)+(x10*y10)+(x11*y11);
}

void readData()
{
	int i;
	printf("\nDigite o ano para saber o numero de transistores: ");
	scanf("%d",&n);
}

void linearSystem()
{

	a[0][0] = 11;
	a[0][1] = sumXi;

	a[1][0] = sumXi;
	a[1][1] = sumXi2;

	b[0] = sumYi;
	b[1] = sumXiYi;
}

float det(float a, float b, float c, float d)
{
	return (a*d)-(b*c);
}

void Triang()
{
	int i,j,k;
	for ( k=0;k<(2-1);k++ )
	{
		for ( i=k+1;i<2;i++ )
		{
			for ( j=k+1;j<2;j++ )
			{
				a[i][j]=det(a[k][k],a[i][k],a[k][j],a[i][j]);
			}
			b[i]=det(a[k][k],a[i][k],b[k],b[i]);
			a[i][k] = 0;
		}
	}
}
/* calcula a matriz das soluções do sistema ja triangularizado */
void solution()
{
	int k,j;
	float s;

	x[1]=b[1]/a[1][1];
	for ( k=1;k>=0; k-- )
	{
		s=0;
		for ( j=k+1;j<2;j++ )
		s+=a[k][j]*x[j];
		x[k]=(b[k]-s)/a[k][k];
	}
}

// Programa principal
int main()
{
    float transistors;

    calculateData();
	linearSystem();
	readData();
	Triang();
	solution();

	//inverso do logaritmo
	transistors = pow(10,((x[1]*n)+x[0]));

	printf ("\nLog(10)(n transistores)= (%f * %d)+(%f) ",x[1],n,x[0]);
	printf ("\nNumero de transistores = %f ",transistors);

	getch();
	return 0;
}
