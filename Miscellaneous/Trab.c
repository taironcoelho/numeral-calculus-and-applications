 #include <stdio.h>

int N = 5;
float b[N];
float X0[N],X1[N];
float a[N][N];
float r1,r2,r3,r4,r5,r6,r7, v1, v2;
float maxDif;

// Função que le a ordem do sistema, le as linhas da matriz de coeficientes e a matriz de resultados

void readData()
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

void permuteLines()
{
	int i,j,k;
	float m;

	for(i=0;i<N;i++)
	{
		k=i;
		for(j=i;j<5;j++)
			if(fabs(a[j][i])>fabs(a[k][i]))k=j;
		if(k!=i)
		{
			for(j=0;j<5;j++)
			{
				s = a[i][j];
				a[i][j] = a[k][j];
				a[k][j] = s;
			}
			s=b[i];
			b[i]=b[k];
			b[k]=s;

		}

	}
}

// Calcula a maior diferença entre x1 e x0

float max()
{
	int i;
	float d,m=0;

	for(i=0;i<N;i++)
	{
		d = fabs(X1[i]-X0[i]);
		if (d>m) m=d;
	}
	return m;
}

void showResults(float *X, int K, int P)
{
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

	if (K>0)
    {
        printf("\n \n Iteracao %d Maxdif = %g \n\n", K, max());
    }
	if (P==0)
    {
        printf("Problema encerrado.\n");
    }
	printf("<ENTER> ");
	getch();
}
// Faz uma interação do método

void iteration (int k)
{
	int i, j;

	for(i=0;i<5;i++) X1[i]=X0[i];
	for(i=0;i<5;i++)
	{
		X1[i] = b[i];
		for(j=0;j<5;j++)
		if (i!=j)
		X1[i] -= a[i][j]*X1[j];
		X1[i] /= a[i][i];
	}
}

int main()
{
	int i, k=0;
	readData();
	permuteLines();
	//for(i=0;i<N;i++) X0[i]=0.0;
	do
	{
		iteration(k);
		maxDif = max();
		for(i=0;i<N;i++) X0[i]=X1[i];
		k++;
	}
	while (Maxdif > 1.0e-8);
	showResults(X1, k, 0);

	return 0;
}

