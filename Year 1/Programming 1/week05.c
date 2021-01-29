// ConsoleApplication14.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <float.h>


void main()
{
	int n, i;
	double num[10], sum = 0.0, average;
	double max = 0;
	double min = DBL_MAX;


	printf("Enter how much numbers you wish to test: ");
	scanf_s("%d", &n);

	while (n <= 0 || n > 10)
	{
		printf("Not valid, number must be between 1 and 10\n");
		printf("Re-enter how much numbers you wish to test: ");
		scanf_s("%d", &n);
	}

	for (i = 0; i < n; ++i)
		{
			printf("Enter number %d: ", i + 1);
			scanf_s("%lf", &num[i]);
			sum += num[i];

			if (num[i] > max)
			{
				max = num[i];
			}
			if (num[i] < min)
			{
				min = num[i];
			}

		}

		average = sum / n;
		printf("Average = %lf\n", average);
		printf("Max = %lf\n", max);
		printf("Min = %lf\n", min);
	}

