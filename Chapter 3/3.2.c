#include <stdio.h>
#include <math.h>

//Derivadas parciais
float Fx (float x, float y)
{
    return 2*x;
}

float Fy (float x, float y)
{
    return 2*y;
}

float Gx (float x, float y)
{
    return 3*(x*x);
}
float Gy(float x, float y)
{
    return -1;
}
// Funções principais
float F (float x, float y)
{
    return (x*x) + (y*y) -1;
}

float G (float x, float y)
{
    return (pow(x,3)) - y;
}

// ----- determinante de uma matriz 2x2

float det(float a, float b, float c, float d)
{
    return (a*d)-(b*c);
}

void NewtonRaphson( float x0, float y0, float *xb, float *yb, float precisao)
{
    int fim;
    float x1,y1,nx,ny,den;

    do{
        den = det( Fx(x0,y0), Fy(x0,y0),Gx(x0,y0), Gy(x0,y0));
        nx = det(F(x0,y0),Fy(x0,y0), G(x0,y0), Gy(x0,y0));
        ny = det(Fx(x0,y0), F(x0,y0), Gx(x0,y0), G(x0,y0));
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
    float x, y;
    NewtonRaphson(0.5,0.5,&x, &y, 0.001);
    printf("Resposta = (%g, %g)\n", x,y);

    getchar();
    return 0;
}
