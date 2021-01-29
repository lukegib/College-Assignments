// LAB1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdio.h"

void main()
{
	int hours = 0;
	float rate = 15.45;
	float overtime = 30.00;
	float pay = 0.0;

	printf("Enter Hours Worked:");
	scanf_s("%d", &hours);
	printf("You worked %d hours ", hours);

	if (hours <= 40)
	{
		pay = hours*rate;
	}

	else
	{
		pay = 40 * rate + (hours - 40)*overtime;
	}

	printf("and earned %.2f \n", pay);

	return 0;


}

