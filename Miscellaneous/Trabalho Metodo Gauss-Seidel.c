 #include <stdio.h>

int N = 5;
float b[30];
float x[30];
float a[30][30];
float r1,r2,r3,r4,r5,r6,r7, v1, v2;

// Função que le a ordem do sistema, le as linhas da matriz de coeficientes e a matriz de resultados

void LeDados()
{
    printf("Digite os valores das fontes e resistores. As correntes e tensoes serao calculadas considerando o sentido horario das correntes!");
    printf("\nFonte de tensao V1: ");
    scanf("%f", &v1);
    printf("\nFonte de tensao V2: ");
    scanf("%f", &v2);
    printf("\nResistor R1: ");
    scanf("%f", &r1);
    printf("\nResistor R2: ");
    scanf("%f", &r2);
    printf("\nResistor R3: ");
    scanf("%f", &r3);
    printf("\nResistor R4: ");
    scanf("%f", &r4);
    printf("\nResistor R5: ");
    scanf("%f", &r5);
    printf("\nResistor R6: ");
    scanf("%f", &r6);
    printf("\nResistor R7: ");
    scanf("%f", &r7);

    a[0][0] = r1+r2;
    a[0][1] = -r2;
    a[0][2] = 0;
    a[0][3] = 0;
    a[0][4] = 0;
    a[1][0] = -r2;
    a[1][1] = r2+r3+r5;
    a[1][2] = -r3;
    a[1][3] = 0;
    a[1][4] = -r5;
    a[2][0] = 0;
    a[2][1] = -r3;
    a[2][2] = r3+r4;
    a[2][3] = -r4;
    a[2][4] = 0;
    a[3][0] = 0;
    a[3][1] = 0;
    a[3][2] = -r4;
    a[3][3] = r4+r6;
    a[3][4] = -r6;
    a[4][0] = 0;
    a[4][1] = -r5;
    a[4][2] = 0;
    a[4][3] = -r6;
    a[4][4] = r5+r6+r7;

    b[0] = v1;
    b[1] = 0;
    b[2] = 0;
    b[3] = 0;
    b[4] = v2;

}

float det(float a, float b, float c, float d)
{
    return (a*d)-(b*c);
}

//Função que faz a triangulação

void Triang()
{
    int i, j, k;

    for(k=0; k<(N-1); k++)
    {
        for(i = k+1; i<N; i++)
        {
            for(j=k+1; j<N; j++)
            {
                a[i][j] = det(a[k][k], a[i][k], a[k][j], a[i][j]);
            }
            b[i] = det(a[k][k], a[i][k], b[k], b[i]);
            a[i][k] = 0;
        }
    }
}

//Calcula a matriz das solucoes do sistema ja triangularizado

void Solucao()
{
    int k, j;
    float s;

    x[N-1] = b[N-1]/a[N-1][N-1];
    for(k=N-2; k>=0; k--)
    {
        s=0;
        for(j=k+1; j<N; j++)
        {
            s+=a[k][j]*x[j];
            x[k]=(b[k]-s)/a[k][k];
        }
    }
}
//Mostra o resultado da matriz de solucoes

void Imprime()
{
    int i;
    float ir1, ir2, ir3, ir4, ir5, ir6, ir7;
    ir1 = x[0];
    ir2 = (x[0]-x[1]);
    ir3 = (x[1]-x[2]);
    ir4 = (x[2]-x[3]);
    ir5 = (x[1]-x[4]);
    ir6 = (x[4]-x[3]);
    ir7 = x[4];

    printf("\nSolucao do circuito considerando as correntes no sentido horario:\n");
    printf("\nCorrentes:\n");
    printf("\nCorrente IR1: %f", ir1);
    printf("\nCorrente IR2: %f", ir2);
    printf("\nCorrente IR3: %f", ir3);
    printf("\nCorrente IR4: %f", ir4);
    printf("\nCorrente IR5: %f", ir5);
    printf("\nCorrente IR6: %f", ir6);
    printf("\nCorrente IR7: %f", ir7);
    printf("\nCorrente na fonte V1: %f", x[0]);
    printf("\nCorrente na fonte V2: %f\n", x[4]);
    printf("\nTensoes:\n");
    printf("\nTensao VR1: %f", ir1*r1);
    printf("\nTensao VR2: %f", ir2*r2);
    printf("\nTensao VR3: %f", ir3*r3);
    printf("\nTensao VR4: %f", ir4*r4);
    printf("\nTensao VR5: %f", ir5*r5);
    printf("\nTensao VR6: %f", ir6*r6);
    printf("\nTensao VR7: %f\n", ir7*r7);

    /*printf("\n\nSolucao do sistema linear\n");
    for(i=0; i<N; i++)
    {
        printf("x(%3d)=%10.6g\n", i,x[i]);
        printf("\n\n\nProblema encerrado.\n");
    }*/
}

int main()
{
    LeDados();
    Triang();
    Solucao();
    Imprime();
    getch();
}
