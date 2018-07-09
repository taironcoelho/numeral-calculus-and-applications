#include <stdio.h>
#include <math.h>

/* Função a Ser Integrada */

float f(float x)
{
    float y;
    y = (4 / (1 + (x*x)));

    return y;
}


float sumAreas(float a, float b, float dx){

    float x, s;

    for(x=a+(dx/2), s=0.0; x<b; x+=dx)
    {
        s += f(x) * dx;
    }

    return s;
}

float integrate(float a, float b, int n, float precision)
{
    float dx, s0, s1;

    dx = (b-a)/n;

    s0 = 0;
    do {
        s1 = s0;
        s0 = sumAreas(a,b,dx);
    } while ( abs(s1 - s0) > precision );

    return s0;
}

int main(int argc, char **argv)
{
    int n;

    float a,b,m;

    printf("\n Informe os limites de integracao: \n\n");
    printf("a= ");
    scanf("%f", &a);
    printf("b= ");
    scanf("%f",&b);

    printf("\n Digite o numero de passos (n):");
    scanf("%d",&n);

    if(a>b)
    {
        m=a;
        a=b;
        b=m;
    }

    printf("\n Resultado: %g\n\n", integrate(a,b,n, 0.0001));

	return 0;
}

