#include <stdio.h>
#include <stdlib.h>



struct data
{
int year;
int month;
float tmax[12];
float tmin[12];
int frostDays[12];
float rain[12];
float sun[12];
};

void tMax(struct data weather[]); //function to find the max temp
void tMin(struct data weather[]); //function to find the minimum temp
void MaxFrost(struct data weather[]); //function to find max frost days
void MaxRain(struct data weather[]); //function to find max rain fall
void MaxSun(struct data weather[]); //function to find max Sun hours
char *monthName(int month); //Function to convert month number to month name


int main(){
    FILE *myFile; //Pointer to file
    myFile = fopen("C:/Users/Luke/Desktop/weather.txt", "r"); //Read file
    struct data weather[50];
    int i, j; //loop variables
    int choice = 1; //user choice

    if (myFile == NULL){ 				// displays if invalid file is entered
        printf("Error Reading File\n");
        exit (0);
    }
	
	//scan function to read all file contents into structured array
	fseek(myFile, 451, SEEK_SET); //set the curser to start of relevant data
	for(j=0; j<50; j++){
		for(i=0; i<12; i++){
		fscanf(myFile, "%d %d %f %f %d %f %f", &weather[j].year, &weather[j].month, &weather[j].tmax[i], &weather[j].tmin[i], &weather[j].frostDays[i], &weather[j].rain[i], &weather[j].sun[i]);
		fseek(myFile, 4, SEEK_CUR);
	}
}	
	fclose(myFile); //Closes file
	
	//loop to allow user choice to be entered more than once
	while(choice!=0){
	printf("Choose Option:\n 1. Temp Max\n 2. Temp Min\n 3. Air Frost Days Max\n 4. Rain Max\n 5. Sun Max\n 0. Exit\n");
	scanf(" %d", &choice);
	if(choice==1){tMax(weather);}
	if(choice==2){tMin(weather);}
	if(choice==3){MaxFrost(weather);}
	if(choice==4){MaxRain(weather);}
	if(choice==5){MaxSun(weather);}
}
}

void tMax(struct data weather[]){ //function to find max temperature
	int i, j;
	float tmaxi = 0;
	int months, years;
	for(i=0; i<50; i++){
		for(j=0; j<12; j++){
			if(weather[i].tmax[j] > tmaxi){ //loop through all contents to find highest number
				tmaxi = weather[i].tmax[j];
				years = weather[i].year; //mark the year
				months = j; //mark the month
			}
		}
	}
	
	printf("The maximum temperature was %g degrees C in %s %d\n\n", tmaxi, monthName(months), years);
}

void tMin(struct data weather[]){ //function to find min temperature
	int i = 0;
	int j = 0;
	float tmini = 0;
	int months, years;
	 for(i=0; i<50; i++){
	 	for(j=0;j<12;j++){
	 		if(weather[i].tmin[j] < tmini){ //loop through all contents to find lowest number
	 			tmini = weather[i].tmin[j];
	 			years = weather[i].year; //mark the year
	 			months = j; //mark the month
			 }
		 }
	 }	
	 printf("The minimum temperature was %g degrees C in %s %d\n\n", tmini, monthName(months), years);
}

void MaxFrost(struct data weather[]){ //Finding the max frost days in the data set
	int i, j;
	int maxF = 0;
	int months, years;
	for(i=0; i<50; i++){
		for(j=0; j<12; j++){
			if(weather[i].frostDays[j] > maxF){ //loop through contents to find highest number
				maxF = weather[i].frostDays[j];
				years = weather[i].year; //mark the year
				months = j; //mark the month
			}
		}
	}
	printf("Max air frost days was %d days in %s %d\n\n", maxF, monthName(months), years);
}

void MaxRain(struct data weather[]){ //fidning the max rain fall
	int i, j;
	int maxR = 0;
	int months, years;
	for(i=0; i<50; i++){
		for(j=0; j<12; j++){
			if(weather[i].rain[j] > maxR){ //loop to find highest value
				maxR = weather[i].rain[j];
				years = weather[i].year; //mark the year
				months = j; //mark the month
			}
		}
	}
	printf("Max rainfall was %d mm in %s %d\n\n", maxR, monthName(months), years);
}

void MaxSun(struct data weather[]){ //finding the max sun hours
	int i, j;
	int maxS = 0;
	int months, years;
	for(i=0; i<50; i++){
		for(j=0; j<12; j++){ 
			if(weather[i].sun[j] > maxS){ //loop to find the highest value
				maxS = weather[i].sun[j];
				years = weather[i].year; //mark the year
				months = j; //mark the month
			}
		}
	}
	printf("Max sun hours was %d hours in %s %d\n\n", maxS, monthName(months), years);
}

char *monthName(int month){ 				// function to convert the int "months" into the Name version and return it back
	if(month == 0){return"January";}
	else if (month == 1){return "February";}
	else if (month == 2){return"March";}
	else if (month==3){return"April";}
	else if (month==4){return"May";}
	else if (month==5){return"June";}
	else if (month==6){return"July";}
	else if (month==7){return"August";}
	else if (month==8){return"September";}
	else if (month==9){return"October";}
	else if (month==10){return"November";}
	else if (month==11){return"December";}
}


