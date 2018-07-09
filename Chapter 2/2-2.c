#include <stdio.h>
#include <math.h>
main()
{
    float x, precision, fx, fdx, act_precision, aux_x;
    printf("Informe um valor para X0: ");
    scanf ("%f", &x);
    printf("Informe um valor para Precisao: ");
    scanf ("%f", &precision);

    act_precision = 10.0;
    aux_x = 10.0;

    while(precision < act_precision)
    {
        fx = (exp(x) + (x/2.0));
        fdx = (exp(x) + 0.5);
        x = (x - (fx/fdx));

        act_precision = fabs(x - aux_x);
        aux_x = x;
    }
    printf ("A raiz da equacao com a precisao informada eh: %f",x);
}
