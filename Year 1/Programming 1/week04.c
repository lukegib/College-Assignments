// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>


void main()
{
	int choice;
	float base;
	float height;
	float area;
	float width;
	float a;
	float b;
	int again;
    
	printf("Area Calculater\n");
	do{
	printf("Enter choice:\n 1 <Triange>\n 2 <Rectangle\n 3 <Trapezoid>\n 4 <Ellipse>\n 5 <Square>\n 6 <Parallelogram>\n 7 <Circle>\n 8 <Sector>\n");
	printf("Choice: ");
	scanf_s("%d", &choice);
	
		if (choice == 1)
		{
			printf("Enter base: ");
			scanf_s("%f", &base);
			printf("Enter vertical height: ");
			scanf_s("%f", &height);
			area = (0.5*(base) *(height));
			printf("Area = %.2f\n", area);
			printf("Go again? 1 = yes 0 = no");
			scanf_s("%d", &again);
		}

		else if (choice == 2)
		{
			printf("Enter width: ");
			scanf_s("%f", &width);
			printf("Enter height: ");
			scanf_s("%f", &height);
			area = width * height;
			printf("Area = %.2f\n", area);
			printf("Go again? 1 = yes 0 = no");
			scanf_s("%d", &again);
		}
		else if (choice == 3)
		{
			printf("Enter base width: ");
			scanf_s("%f", &a);
			printf("Enter top width: ");
			scanf_s("%f", &b);
			printf("Enter vertical height: ");
			scanf_s("%f", &height);
			area = (0.5*(a + b)*(height));
			printf("Area = %.2f\n", area);
			printf("Go again? 1 = yes 0 = no");
			scanf_s("%d", &again);

		}
		else if (choice == 4)
		{
			printf("Enter major radius: ");
			scanf_s("%f", &a);
			printf("Enter minor radius: ");
			scanf_s("%f", &b);
			area = 3.14159 *a *b;
			printf("Area = %.2f\n", area);
			printf("Go again? 1 = yes 0 = no");
			scanf_s("%d", &again);

		}
		else if (choice == 5)
		{
			printf("Enter length: ");
			scanf_s("%f", &a);
			area = a*a;
			printf("Area = %.2f\n", area);
			printf("Go again? 1 = yes 0 = no");
			scanf_s("%d", &again);
		}
		else if (choice == 6)
		{
			printf("Enter base: ");
			scanf_s("%f", &b);
			printf("Enter height: ");
			scanf_s("%f", &height);
			area = b * height;
			printf("Area = %.2f\n", area);
			printf("Go again? 1 = yes 0 = no");
			scanf_s("%d", &again);
		}
		else if (choice == 7)
		{
			printf("Enter radius: ");
			scanf_s("%f", &a);
			area = 3.14159 *(a*a);
			printf("Area = %.2f\n", area);
			printf("Go again? 1 = yes 0 = no");
			scanf_s("%d", &again);
		
		}
		else if (choice == 8)
		{
			printf("Enter radius: ");
			scanf_s("%f", &a);
			printf("Enter angle in radians: ");
			scanf_s("%f", &b);
			area = 0.5 * (a*a) * b;
			printf("Area = %.2f\n", area);
			printf("Go again? (1 = yes 0 = no) ");
			scanf_s("%d", &again);
		}
	} while (again == 1);
}

