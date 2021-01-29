// ConsoleApplication5.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>

void main()
{
	int M;
	int Sci;
	int Ir;
	int En;
	int Fr;
	float average;

	printf("Enter English mark: ");
	scanf_s("%d", &En);
	printf("Enter Math mark: ");
	scanf_s("%d", &M);
	printf("Enter Irish mark: ");
	scanf_s("%d", &Ir);
	printf("Enter French mark: ");
	scanf_s("%d", &Fr);
	printf("Enter Science mark: ");
	scanf_s("%d", &Sci);

	average = ((float)(M + Sci + Ir + En + Fr)) / 5;
	printf("Your average mark is %.2f \n", average);

	printf("You failed: ");

	if (M < 40)
	{
		printf("Maths,");
	}
	if (Sci < 40)
	{
		printf("Science,");
	}
	if (Ir < 40)
	{
		printf("Irish,");
	}
	if (En < 40)
	{
		printf("English,");
	}
	if (Fr < 40)
	{
		printf("French");
	}

	printf("\nYou passed: ");

	if (M >= 40)
	{
		printf("Maths,");
	}
	if (Sci >= 40)
	{
		printf("Science,");
	}
	if (Ir >= 40)
	{
		printf("Irish,");
	}
	if (En >= 40)
	{
		printf("English,");
	}
	if (Fr >= 40)
	{
		printf("French");
	}

	if ((M > Ir) && (M > En) && (M > Sci) && (M > Fr))
	{
		printf("\nYour highest mark is %d in Math\n", M);
	}
	else if ((Ir > M) && (Ir > En) && (Ir > Sci) && (Ir > Fr))
	{
		printf("\nYour highest mark is %d in Irish\n", Ir);
	}
	else if ((Sci > M) && (Sci > En) && (Sci > Fr) && (Sci > Ir))
	{
		printf("\nYour highest mark is %d in Science\n", Sci);
	}
	else if ((En > M) && (En > Fr) && (En > Ir) && (En > Sci))
	{
		printf("\nYour highest mark is %d in English\n", En);
	}
	else if ((Fr > M) && (Fr > Ir) && (Fr > Sci) && (Fr > En))
	{
		printf("\nYour highest mark is %d in French\n", Fr);
	}
}
