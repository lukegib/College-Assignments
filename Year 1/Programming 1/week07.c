// ConsoleApplication20.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include "string.h"

void main()
{
	int i, j;
	char fullName[100];
	char firstName[30], middleName[30], surname[30];
	char initial;

	printf("enter full name: ");

	gets_s(fullName);
	printf("Thank you %s\n\n", fullName);
	i = 0;
	for (i = 0; i != 32; i++)
	{
		fullName[i] = firstName[i];
		if (fullName[i] == 32)
		{
			fullName[i] = " ";
		}
	}
	
	i = 0;
	for (i = 0; i != 32; i++)
	{
		fullName[i] = middleName[i];
		if (fullName[i] == 32)
		{
			fullName[i] = " ";
		}
		middleName[0] = initial;
	}
	
	i = 0;
	for (i = 0; i != 32; i++)
	{
		fullName[i] = surname[i];
		if (fullName[i] == 32)
		{
			fullName[i] = 0;
		}
	}

		printf("%s %c %s\n", firstName, middleName, surname);

	}