#include <stdio.h>
#include <math.h>
main()
{
    float c, precision, fc, fdc, act_precision, aux_c, g, vel, massa, t;
    g = 9.8;
    precision = 0.000001;
    c = 25.0;

    printf("Informe o valor da velocidade v [m/s]: ");
    scanf ("%f", &vel);
    printf("Informe um valor para massa m [kg]: ");
    scanf ("%f", &massa);
    printf("Informe um valor para tempo t [s]: ");
    scanf ("%f", &t);

    act_precision = 10.0;
    aux_c = 10.0;

    while(precision < act_precision)
    {
        fc = (((g*massa*(1 - (exp(-(c/massa)*t))))-(vel*c)));
        fdc = ((((g*massa*(1 - (exp(-((c+precision)/massa)*t))))-(vel*(c+precision))) - fc )/precision);
        c = (c - (fc/fdc));
        act_precision = fabs(c - aux_c);
        aux_c = c;
    }
    printf ("A raiz da equacao(c) sera: %f [kg/s]",c);
}

