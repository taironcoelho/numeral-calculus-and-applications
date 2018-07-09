#include <stdio.h>
#include <math.h>
#define PREC 0.00001
// ------ funcoes principais

float F (float x, float y, float c)
{
    return c*(pow(0.95,(x-1)))-y;
}

float G (float x, float y)
{
    return (((4*x)+30)/x)-y;
}

float Fx (float x, float y, float c)
{
    return (F(x+0.001, y, c) - F(x, y, c))/0.001;
}

float Fy (float x, float y, float c)
{
    return (F(x, y+0.001, c) - F(x, y, c))/0.001;
}

float Gx (float x, float y)
{
    return (G(x+0.001, y) - G(x,y))/ 0.001;
}

float Gy(float x, float y)
{
    return (G(x,y+0.001) - G(x,y))/ 0.001;
}

// ----- determinante de uma matriz 2x2

float det(float a, float b, float c, float d)
{
    return (a*d)-(b*c);
}

void NewtonRaphson( float x0, float y0, float *xb, float *yb, float precisao, float c)
{
    int fim;
    float x1,y1,nx,ny,den;

    do{
        den = det( Fx(x0,y0,c), Fy(x0,y0, c),Gx(x0,y0), Gy(x0,y0));
        nx = det(F(x0,y0,c),Fy(x0,y0, c), G(x0,y0), Gy(x0,y0));
        ny = det(Fx(x0,y0,c), F(x0,y0,c), Gx(x0,y0), G(x0,y0));
        x1 = x0 - (nx/den);
        y1 = y0 - (ny/den);
        fim = (fabs(x1-x0)<precisao) && (fabs(y1-y0)<precisao);
        x0 = x1;
        y0 = y1;
    } while (!fim);
    *xb = x1;
    *yb = y1;
}

int main(int argc, char* argv[])
{
    float x, y, c;
    printf("Informe o valor de C: ");
    scanf ("%f", &c);
    NewtonRaphson(30.0,5.8,&x, &y, 0.001, c);
    printf("resposta = (%g, %g)\n", x,y);

    getchar();
    return 0;
}
