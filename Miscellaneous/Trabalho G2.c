#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

const long double PRECISAO = 10E-4;

int n,vp,vn;
float p[11];
float q[30];
float r;

float f(float x)
{

    int i;
    float y;

    y = 0.0;

    for(i=0; i<n+1; i++){

        y += p[i] * powf(x, n-i);

    }

    return y;

}

/* Funcão para leitura do grau e coeficientes do polinômio */
void readData()
{
	int i;

	printf("Digite o grau do Polinomio(1<= N <= 10) que deseja calcular as raizes.\n\nn= ");
	scanf("%d",&n);
	printf("Digite os coeficientes do Polinomio conforme indicado:\n\n");

	for(i=0;i<=n; i++){
		if(i==0){
            printf("Coeficiente do termo: x^%1d = ",n-i);
        }else if(i==n){
            printf("Termo independente = ");
        }else{
            printf("Coeficiente do termo: x^%1d = ",n-i);
        }
		scanf("%f",&p[i]);
	}
}

void mostraPoli()
{
    int i;

    printf("\np(x) = ");

    for(i=0;i<(n+1);i++){

        if(p[i] > 0){

            if(i==n-1){
                printf("%f * x ",p[i]);
            }else if (i==n){
                printf(" + %f",p[i]);
            }else{
                printf(" + %f * x^%1d ",p[i],n-i);
            }

        }else{

            if(i==n-1){
                printf(" - %f * x ",fabs(p[i]));
            }else if(i==n){
                printf(" - %f", fabs(p[i]));
            }else{
                printf(" - %f * x^%1d ",fabs(p[i]),n-i);
            }

        }

    }

    printf("\n\n");

}

float derivf(float x, float h)
{

    float y;

    y = (f(x + h) - f(x)) / h;

    return y;

}


void descartesP()
{
    float lastc;
    int v,i;

    v = 0;
    lastc = 0.0;

	for(i=1;i<n+1; i++){

        if(p[i-1] != 0.0){

            lastc = p[i-1];
        }

        // Verificando se houve mudança de sinal entre o termo de grau n e o termo de grau n-1 ( não nulo )
        if((p[i] * lastc) < 0.0){

            v++;
        }
	}

    vp = v;

}


void descartesN()
{
    float lastc, tmp[30];
    int v,i;

	for(i=0;i<n+1; i++){

        if((i==0) && (n % 2 != 0)){

            tmp[i] = p[i] * -1.0;

        }else{

            if(i % 2 == 0){

                tmp[i] = tmp[i] * -1.0;

            }else{
                tmp[i] = p[i];
            }

        }
	}

    v = 0;
    lastc = 0.0;

	for(i=1;i<n+1; i++){

        if(tmp[i-1] != 0.0){

            lastc = tmp[i-1];
        }

        if((tmp[i] * lastc) < 0.0){
            v++;
        }
	}

    vn = v;

}

float newtonRaphson(float x0)
{
    float x1, anterior;

    anterior = x0 + 2*PRECISAO;

    while(fabs(x0-anterior) > PRECISAO){

        anterior = x0;

        x1 = x0 - (f(x0) / derivf(x0, PRECISAO));
		x0 = x1;
    }

	return x1;
}

float dicotomia(float xa, float xb)
{
    float xc, anterior;


    anterior = xb;
    xc = xa;

    while(fabs(xc-anterior) > PRECISAO){
        anterior = xc;
        xc = (xa + xb) / 2.0;
        if(f(xa)*f(xc) < 0.0){
			xb = xc;
		}else if(f(xb)*f(xc) < 0.0){
			xa = xc;
		}
    }

	return xc;
}

int main(int argc, char **argv)
{
    int i;
    float raiz,a;

    raiz = 0.0;
    a = 0.0;

    readData();
    do{
        descartesP();
        descartesN();

        raiz = newtonRaphson(0);

        if(isnanf(raiz)){

            printf("Tentando por dicotomia....\n");

            printf("Regra de Sinal de Desccartes:\n");
            printf("Existem até %d raízes POSITIVAS para p(x)\n",vp);
            printf("Existem até %d raízes NEGATIVAS para p(x)\n",vn);

            if(vp>0.0){
                printf("Procurando raízes reais positivas..\n");
                a = 0.0;
                if(p[n] == 0){
                    raiz = dicotomia(a,1.0);
                }else{
                    raiz = dicotomia(a,p[n]*-1.0);
                }

            }else if(vn>0.0){

                printf("Procurando raízes reais negativas..\n");

                a = 0.0;
                if(p[n] == 0){
                    raiz = dicotomia(1,0);
                }else{
                    raiz = dicotomia(p[n]*-1.0,a);
                }
            }
        }

        printf("\n\nRaiz Encontrada = %f\n", raiz);

        for(i=0; i<(n+1); i++){

            if(i==0){
                q[0]=p[0];
            }else{
                q[i] =  (q[i-1] * raiz) + p[i];
            }
        }
        n--;

        for(i=0;i<n+1; i++){
            p[i] = q[i];
        }

        mostraPoli();

    }while(n>0 || isnan(raiz));
	return 0;
}

