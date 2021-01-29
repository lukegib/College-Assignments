/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include "stdio.h"
#include "string.h"
#include "stdlib.h"

struct date
{
	int day, month, year;
};

struct student
{
	char firstName[50];
	char surname[50];
	int ID;
	struct date DOB;
};


int addStudent(struct student students[], int numStudents);
void printStudents(struct student students[], int numStudents);
void sortByID(struct student students[], int numStudents);
void sortBySurname(struct student students[], int numStudents);

int main()
{

	struct student students[100] = { {"Rolando","Gamble", 17560001, {1,1,2000}}, {"Kyra","Eaton", 17973061, {11,10,2016}}, {"Chandler","Humphrey", 17427400, {6,12,1999}}, {"Makayla","Huang", 17127058, {2,2,2000}}, {"Jazmyn","Terrell", 17746780, {29,6,2000}}, {"Erica","Glass", 17058753, {13,8,2000}}, {"Alyvia","Blair", 17599020, {11,9,2000}}, {"Talia","Chen", 17619205, {17,10,2000}}, {"Rebekah","Hopkins", 17912255, {25,11,2000}}, {"Jocelynn","Ware", 17899236, {27,4,1999}}};
	
	int numStudents = 10;

	// use addStudent to add a new student and it returns the updated number of students
	// obviously, numStudents is the number of structures in the array (students[]) that contain data
	numStudents = addStudent (students, numStudents);

	// sort by ID number and print out list
	sortByID (students, numStudents);
	printf ("\n\n%d Students, Sorted by ID: \n", numStudents);
	printStudents (students, numStudents);

	// sort by surname and print out list
	sortBySurname (students, numStudents);
	printf ("\n\n%d Students, Sorted by Surname: \n", numStudents);
	printStudents (students, numStudents);

	return 0;
}

int addStudent(struct student students[], int numStudents)
{
	char first[50], last[50];
	int id, dd, mm, yyyy;

	// Ask user for data for new student and add to the array of students
	printf("Add a new student\nEnter data as follows: FirstName Surname ID dd mm yyyy\n");
	scanf("%s %s %d %d %d %d", &first, &last, &id, &dd, &mm, &yyyy);
	numStudents+=1;
	
	
	return numStudents;
}

void printStudents(struct student students[], int numStudents)
{
	int i;

	printf ("%20s%20s%15s\t\t%10s\n", "First Name", "Surname", "ID Number", "DOB");
	// write a for loop to print out each student structure
	for (i=0; i<=numStudents; i++){
	    printf();
	}
}

void sortByID(struct student students[], int numStudents)
{
	struct student temp;
	int i,j;

	// use the Bubble sort algorithm to sort the students by ID
	for (i=0;i<(n-1);i++)
  {
    for (j = 0 ; j < n-i-1; j++)
    {
      if (array[j] > array[j+1]) 
      {
        temp       = array[j];
        array[j]   = array[j+1];
        array[j+1] = temp;
      
}

void sortBySurname(struct student students[], int numStudents)
{
	struct student temp;
	int i,j;

	// use the Bubble sort algorithm to sort the students by Surname
	// your code here
}



