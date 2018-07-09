#include <stdio.h>
#include <math.h>
main()
{
    float xa1, xb1, xc1, precision, act_precision, fxa, fxb, fxc, aux_xc;
    float a,b,c, xa2, xb2, xc2;
    printf("Informe o valor de a: ");
    scanf ("%f", &a);
    printf("Informe o valor de b: ");
    scanf ("%f", &b);
    printf("Informe o valor de c: ");
    scanf ("%f", &c);
    printf("Informe um valor para Xa referente a primeira raíz: ");
    scanf ("%f", &xa1);
    printf("Informe um valor para Xb referente a primeira raíz: ");
    scanf ("%f", &xb1);
    printf("Informe um valor para Xa referente a segunda raíz: ");
    scanf ("%f", &xa2);
    printf("Informe um valor para Xb referente a segunda raíz: ");
    scanf ("%f", &xb2);
    printf("Informe um valor para Precisao:");
    scanf ("%f", &precision);

    act_precision = 10.0;
    aux_xc = 10.0;

    while(precision < act_precision)
    {
        xc1 = (xa1+xb1)/2.0;
        fxa = (a*(pow(xa1,2)) + (b*xa1) + c);
        fxb = (a*(pow(xb1,2)) + (b*xb1) + c);
        fxc = (a*(pow(xc1,2)) + (b*xc1) + c);

        if(fxa*fxc < 0.0)
        {
            xb1 = xc1;
        }else if(fxb*fxc < 0.0){
            xa1 = xc1;
        }
        act_precision = fabs(xc1 - aux_xc);

        aux_xc = xc1;
    }
    printf ("A primeira raiz da equacao com a precisao informada eh: %f",xc1);

    act_precision = 10.0;
    aux_xc = 10.0;

    while(precision < act_precision)
    {
        xc2 = (xa2+xb2)/2.0;
        fxa = (a*(pow(xa2,2)) + (b*xa2) + c);
        fxb = (a*(pow(xb2,2)) + (b*xb2) + c);
        fxc = (a*(pow(xc2,2)) + (b*xc2) + c);

        if(fxa*fxc < 0.0)
        {
            xb2 = xc2;
        }else if(fxb*fxc < 0.0){
            xa2 = xc2;
        }
        act_precision = fabs(xc2 - aux_xc);

        aux_xc = xc2;
    }
    printf ("\n\n\nA segunda raiz da equacao com a precisao informada eh: %f",xc2);
}
