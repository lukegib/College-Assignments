/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <math.h>

int main()
{   char calc[5], cont;
    double degrees;
    double ans;
    double radians;
    do{
    printf("Enter calculation using degrees, e.g (cos 45): ");
    scanf("%s %lf", &calc, &degrees);
    radians= degrees* 0.0174532925;
    
    if(calc[0] == 'c'|| calc[0] == 'C'){
        ans = cos(radians);
    }
    else if (calc[0]=='s' || calc[0] == 'S'){
        ans = sin(radians);
    }
    else if (calc[0]=='t' || calc [0]=='T'){
        ans = tan(radians);
    }
    
    printf("%s %.3lf = %.3lf\n",calc, degrees, ans);
    printf ("Do you want to repeat the operation Y/N: ");
    scanf (" %c", &cont);
    } while (cont == 'y' || cont == 'Y');
    return 0;
}




