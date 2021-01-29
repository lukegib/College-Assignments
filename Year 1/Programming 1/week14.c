/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <string.h>
void printShortestName(void);
void printLongestName(void);

int main(){
    int n;
    int i = 1;
    char names [100][100],dummy[100], names2[100][100];
    printf("How many names do you want to enter: ");
    scanf("%d", &n);
    gets(dummy);
    for (i=1; i<=n; i++)
    {
        printf("Enter name %d: ", i);
        gets(names[i]);
        
        if (strlen(names) > strlen(names2))
        {
          strcpy(names2, names);
        }

    }
    printf("longest string <%d characters> = %s",strlen(names2), names2);
    
    

    return 0;
}

//void printShortestName (char names[][100], int num);
//void printLongestName (char names[][100], int num);




