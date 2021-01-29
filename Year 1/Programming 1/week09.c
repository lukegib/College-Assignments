/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#define PI 3.14159
double getAreaTriangle (double b, double h){
    double area = 0.5 * b * h;
    return area;
}
double getAreaTrapezoid (double a, double b, double h){
    double area = 0.5*(a+b) *h;
    return area;
}
double getAreaSquare (double a){
    double area = a * a;
    return area;
}
double getAreaRectangle (double w, double h){
    double area = w*h;
    return area;
    
}
double getAreaElipse (double a, double b){
    double area = PI * a *b;
    return area;
}
double getAreaParallelogram (double b, double h){
    double area = b*h;
    return area;
}
double getAreaCircle (double r){
    double area = PI *(r*r);
    return area;
}
double getAreaSector (double r, double theta){
    double area = 0.5 * (r*r) * theta;
    return area;
}



int main()
{
    double area;
    
    area = getAreaTrapezoid(2.0, 3.0, 4.0);
    printf("Area of Trapezoid (a=2, b=3, h=4) = %.3f\n", area);
    area = getAreaTriangle(1.4, 1.6);
    printf("Area of Triangle (b = 1.4, h= 1.6) = %.3f\n", area);
    area = getAreaSquare(2.5);
    printf("Area of square (l=2.5) = %.3f\n", area);
    area = getAreaSector(3, 2);
    printf("Area of Sector (r = 3.0, theta = 2 radians) = %.3f\n", area);
    area = getAreaCircle(6);
    printf("Area of circle (r=6.0) = %.3f\n", area);
    area = getAreaParallelogram(2.5, 1.4);
    printf("Area of Paralelogram (b=2.5, h=1.4) = %.3f\n", area);
    area = getAreaElipse(3, 2);
    printf("Area of Elipse (a=3.0, b=2.0) = %.3f\n", area);
    area = getAreaRectangle(2, 3);
    printf("Area of Rectangle (w=2.0, h=3.0) = %.3f\n", area);
   


    return 0;
}



