#include <stdio.h>
#include <math.h>
main()
{
    float xa, xb, xc, precision, act_precision, fxa, fxb, fxc, aux_xc;
    printf("Informe um valor para Xa:");
    scanf ("%f", &xa);
    printf("Informe um valor para Xb:");
    scanf ("%f", &xb);
    printf("Informe um valor para Precisao:");
    scanf ("%f", &precision);

    act_precision = 10.0;
    aux_xc = 10.0;

    while(precision < act_precision)
    {
        xc = (xa+xb)/2.0;
        fxa = (exp(xa) + (xa/2.0));
        fxb = (exp(xb) + (xb/2.0));
        fxc = (exp(xc) + (xc/2.0));

        if(fxa*fxc < 0.0)
        {
            xb = xc;
        }else if(fxb*fxc < 0.0){
            xa = xc;
        }
        act_precision = fabs(xc - aux_xc);

        aux_xc = xc;
    }
    printf ("A raiz da equacao com a precisao informada eh: %f",xc);
}
