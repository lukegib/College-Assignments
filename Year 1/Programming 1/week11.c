
    #include <stdio.h>
    #include <stdlib.h>
    #include <time.h>
   
    #define x 1000

    int main(void){
       char randChar = " ";
       int counter = 0;
       int randNum = 0;
       int len[26] = {0};
       int freq[26] = {0};
       int i=0, j=0; 
       int max = freq[0];
       int min=freq[0];
    //Random char generator
      srand(time(NULL));
      for (counter = 0; counter < x; counter++)
      {
          randNum = 26 * (rand() / (RAND_MAX + 1.0));
          randNum = randNum + 97;
          randChar = (char) randNum;
          //loop to find frequency of char
          for(i=97, j=0; i<=122, j<=25; i++, j++)
          {
            if (randNum == i){len[j]++; freq[j]++;}
          }
      }
      //loop to find min and max values for scaling
      for(i=1; i<26; i++){
          if(freq[i]>max){max = freq[i];}
          if(freq[i]<min){min = freq[i];}
        }
    //print top line
    printf("Num throws = %d\t Max freq = %d\t Scale = 0-40\n", x, max);
    
    //loop for chars, frequency and scaled *
    for(i=97, j=0; i<=122, j<=25; i++, j++)
         {
            printf("Letter: %c\t Frequency: %d\n", i, len[j]);
         }
     
  }

    
  

