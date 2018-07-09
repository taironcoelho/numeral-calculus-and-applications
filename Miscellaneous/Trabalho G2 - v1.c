#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float Coeficients[11],c[11];
float R[10];
float dx,y,x,ret,p,precision;
int r,maxIt,n;

/*
    Esta função implementa o algoritmo de Newton Raphson para encontrar as raizes do polinômio
*/
float newtonRaphson()
{
    x=p;
    xt=x+2*precision;
    maxIt=0;
    while((fabs(xt-x)>precision)&&(maxIt<100))
    {
        y=Coeficients[10]*pow(x,10)+Coeficients[9]*pow(x,9)+Coeficients[8]*pow(x,8)+Coeficients[7]*pow(x,7)+Coeficients[6]*pow(x,6)+Coeficients[5]*pow(x,5)+Coeficients[4]*pow(x,4)+Coeficients[3]*pow(x,3)+Coeficients[2]*pow(x,2)+Coeficients[1]*x+Coeficients[0];
        dx=Coeficients[10]*10*pow(x,9)+Coeficients[9]*9*pow(x,8)+Coeficients[8]*8*pow(x,7)+Coeficients[7]*7*pow(x,6)+Coeficients[6]*6*pow(x,5)+Coeficients[5]*5*pow(x,4)+Coeficients[4]*4*pow(x,3)+Coeficients[3]*3*pow(x,2)+Coeficients[2]*2*x+Coeficients[1];
        ret=x;
        x=x-y/dx;
        maxIt++;
    }
    R[r]=ret;
    r++;
    return (ret);
}

/*
    Esta função implementa o algoritmo de Briot Ruffini
*/
 void briot()
{
	float a;
	a = newtonRaphson();
	int i;
	for (i = 0; i < 11; i++)
	{
		c[i]=Coeficients[i];
	}
	Coeficients[10]=0;
	Coeficients[9]=c[10];
	Coeficients[8]=Coeficients[9]*a+c[9];
	Coeficients[7]=Coeficients[8]*a+c[8];
	Coeficients[6]=Coeficients[7]*a+c[7];
	Coeficients[5]=Coeficients[6]*a+c[6];
	Coeficients[4]=Coeficients[5]*a+c[5];
	Coeficients[3]=Coeficients[4]*a+c[4];
	Coeficients[2]=Coeficients[3]*a+c[3];
	Coeficients[1]=Coeficients[2]*a+c[2];
	Coeficients[0]=Coeficients[1]*a+c[1];
}

/*
    Função que chama a função de Briot Ruffini e incrementa o valor de r
*/
void auxBriot()
{
	int i;
	for (i = 1; i < n; i++)
	{
		briot();
	}
   	R[r]=(-Coeficients[0])/Coeficients[1];
	r++;
}

/*
    Função que mostra as raízes do polinomio ao usuário
*/
void results()
{
	int i;
	printf("\n\nRaizes do Polinomio:\n");

	for (i = 0;i <r ; i++)
	{
		printf("Raiz[%d]: %f\n", i, R[i]);
	}
}
/*
    Função para leitura dos dados referentes ao polinômio
*/
void readData()
{
    int i;

    printf("Digite o grau do Polinomio(1<= N <= 10) que deseja calcular as raizes.\n\nn= ");
	scanf("%d",&n);

	printf("Digite a precisao desejada para as raizes: ");
	scanf("%f",&precision);

	for (i = n; i >= 0; i--)
	{
		printf("\nCoeficiente do termo x^%d: ", i);
		scanf("%f",&Coeficients[i]);
	}
}

int main()
{
    int i;
	p=0;
	r=0;
	for (i = 0; i < 11; i++)
	{
        Coeficients[i]=0;
	}

    readData();
	auxBriot();
    results();
}
