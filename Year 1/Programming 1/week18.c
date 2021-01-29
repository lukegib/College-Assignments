#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
char *UserName;
char *firstName;
char *lastName;
char *displayName;
char *jobTitle;
char *department;
char *officeNumber;
char *officePhone;
char *mobilePhone;
char *fax;
char *address;
char *city;
char *state;
char *zip;
char *country;
} contact;

void printContact(contact *theContact); //function to print out data

int main(){
	FILE *myFile;
	myFile = fopen("C:/Users/Luke/Desktop/contacts.txt", "r");
	char str[200]; //string to place lines of file
    const char s[15] = ","; //used for strtok function
    contact *theContact = (contact*)malloc(7*sizeof(contact)); //pointer to struct
	char *token;
	int len; int i = 0; //len to measure size of array needed & counter i;
	
	 if (myFile == NULL){ 				// displays if invalid file is entered
        printf("Error Reading File\n");
        exit (0);
    }
    //loop to get value for each line
    for(i=0; i<6; i++){
	//gets username
    fgets(str, 200, myFile);
    token = strtok(str, s);
    len = strlen(token); //get the length of the string
    theContact[i].UserName = (char*)malloc(len); //make the pointer array the size of the username
    strcpy(theContact[i].UserName, token);
    //gets first name
    token = strtok(NULL, s);
    len = strlen(token); //get the length of the string
    theContact[i].firstName = (char*)malloc(len); //dynamically allocate size of string
    strcpy(theContact[i].firstName, token);
    //gets last name
    token = strtok(NULL, s);
    len = strlen(token); //get the length of the string
    theContact[i].lastName = (char*)malloc(len); //dynamically allocate size of string
    strcpy(theContact[i].lastName, token);
    //gets display name
    token = strtok(NULL, s);
    len = strlen(token); //get the length of the string
    theContact[i].displayName = (char*)malloc(len); //dynamically allocate size of string
    strcpy(theContact[i].displayName, token);
    //etc....
    token = strtok(NULL, s);
    len = strlen(token);
    theContact[i].jobTitle = (char*)malloc(len);
    strcpy(theContact[i].jobTitle, token);
    
    token = strtok(NULL, s);
    len = strlen(token);
    theContact[i].department = (char*)malloc(len);
    strcpy(theContact[i].department, token);
    
    token = strtok(NULL, s);
    len = strlen(token);
    theContact[i].officeNumber = (char*)malloc(len);
    strcpy(theContact[i].officeNumber, token);
    
    token = strtok(NULL, s);
    len = strlen(token);
    theContact[i].officePhone = (char*)malloc(len);
    strcpy(theContact[i].officePhone, token);
    
    token = strtok(NULL, s);
    len = strlen(token);
    theContact[i].mobilePhone = (char*)malloc(len);
    strcpy(theContact[i].mobilePhone, token);
    
    token = strtok(NULL, s);
    len = strlen(token);
    theContact[i].fax = (char*)malloc(len);
    strcpy(theContact[i].fax, token);
    
    token = strtok(NULL, s);
    len = strlen(token);
    theContact[i].address = (char*)malloc(len);
    strcpy(theContact[i].address, token);
    
    token = strtok(NULL, s);
    len = strlen(token);
    theContact[i].city = (char*)malloc(len);
    strcpy(theContact[i].city, token);
    
    token = strtok(NULL, s);
    len = strlen(token);
    theContact[i].state = (char*)malloc(len);
    strcpy(theContact[i].state, token);
    
    token = strtok(NULL, s);
    len = strlen(token);
    theContact[i].zip = (char*)malloc(len);
    strcpy(theContact[i].zip, token);
    
    token = strtok(NULL, s);
    len = strlen(token);
    theContact[i].country = (char*)malloc(len);
    strcpy(theContact[i].country, token);
}

	fclose(myFile); //closes file

	printContact(theContact); //call function to print out all data

}

//function to print out the data
void printContact(contact *theContact){
	int i; //counter for loop
	//loop to print out each structure
	for(i=1; i<6; i++){
		printf("User Name: %s\nFirst Name: %s\nLast Name: %s\nDisplay Name: %s\nJob Title: %s\nDepartment: %s\nOffice Number: %s\nOffice Phone: %s\nMobile Phone: %s\nFax: %s\nAddress: %s\nCity: %s\nState: %s\nZip: %s\nCountry: %s\n\n", 
		theContact[i].UserName, theContact[i].firstName, theContact[i].lastName, theContact[i].displayName, theContact[i].jobTitle, theContact[i].department, 
		theContact[i].officeNumber, theContact[i].officePhone, theContact[i].mobilePhone, theContact[i].fax, theContact[i].address, theContact[i].city, theContact[i].state, theContact[i].zip, theContact[i].country);
	}
}


