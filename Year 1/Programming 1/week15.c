#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct date
{
int day, month, year;
};

struct students
{
int studentID;
char firstName[20];
char lastName[20];
char courseID[10];
int year;
struct date registrationDate;
struct date dateOfBirth;
int averageGrade;
};

int getRandNum(void); //Fuction to get a random number for Average grade

int main(){
	int i;
    FILE *myFile; //Pointer to file
    myFile = fopen("C:/Users/Luke/Desktop/students.txt", "r"); //Read file
    struct students student[3];
    srand((unsigned) time(NULL));

    if (myFile == NULL){ 				// displays if invalid file is entered
        printf("Error Reading File\n");
        exit (0);
    }
	
	//scan function to read all file contents into structured array
	
	fscanf(myFile, "%d %s %s %s %d %d %d %d %d %d %d\n%d %s %s %s %d %d %d %d %d %d %d", &student[0].studentID, &student[0].firstName, &student[0].lastName, 
	&student[0].courseID, &student[0].year, &student[0].registrationDate.day, &student[0].registrationDate.month, &student[0].registrationDate.year, 
	&student[0].dateOfBirth.day, &student[0].dateOfBirth.month, &student[0].dateOfBirth.year, &student[1].studentID, &student[1].firstName, 
	&student[1].lastName, &student[1].courseID, &student[1].year, &student[1].registrationDate.day, &student[1].registrationDate.month, 
	&student[1].registrationDate.year, &student[1].dateOfBirth.day, &student[1].dateOfBirth.month, &student[1].dateOfBirth.year);
	
	fclose(myFile); //Closes file

	for(i=0; i<2;i++){ //loop to intialise the average grades
		student[i].averageGrade = getRandNum();
	}

	myFile = fopen("C:/Users/Luke/Desktop/students.txt", "w+"); //Open file to overwrite
	
	if (myFile == NULL){						//displays if invalid file is entered
		printf("Error Overwriting File!\n");
		exit(0);
	}
	
	//Long print to write all contents of array back into the txt file
	
	fprintf(myFile, "%d %s %s %s %d %d %d %d %d %d %d %d\n%d %s %s %s %d %d %d %d %d %d %d %d", student[0].studentID, student[0].firstName, student[0].lastName, 
	student[0].courseID, student[0].year, student[0].registrationDate.day, student[0].registrationDate.month, student[0].registrationDate.year, student[0].dateOfBirth.day, 
	student[0].dateOfBirth.month, student[0].dateOfBirth.year, student[0].averageGrade, student[1].studentID, student[1].firstName, student[1].lastName, 
	student[1].courseID, student[1].year, student[1].registrationDate.day, student[1].registrationDate.month, student[1].registrationDate.year, student[1].dateOfBirth.day, 
	student[1].dateOfBirth.month, student[1].dateOfBirth.year, student[1].averageGrade);
	
	fclose(myFile);
    return 0;
}

int getRandNum(void){ 	//Function to generate a random number for the average grade 0-100
	int avgGrade;
	avgGrade = rand() % 100 -1;
	return avgGrade;
}
