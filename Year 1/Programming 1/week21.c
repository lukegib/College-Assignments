#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Date{
	int day, month, year;
};

struct Time{
	int hour, minute;
};

struct worktime
{
int employeeID;
struct Date date;
struct Time startTime;
struct Time endTime;
};

int fileLines(char *filename); //function to return the number of lines in the file


void main( int argc, char *argv[] )
{ 
	FILE *myFile;
	struct Date dates[5];
	struct worktime datas[10];
	char tempString[50]; //temp place to hold string for delimeters
	char tempString2[50]; //temp string for further delimiters
	char str[50];
	char tempstr1[50];
	char tempstr2[50];
	char tempstr3[50];
	int i=4;
	int j;
	int k = 0;
	char ch;
	const char s[3] = "/"; //delimeter
	const char t[4] = ","; //delimeter
	const char l[1] = ":"; //delimeter
	const char sp[4] = " "; //delimeter
	char *token; //token to split string
	char tempMonth[10]; //temp array to hold the name of the month
	
//The following is for ammending a file 
  if(strcmp("/a", argv[2]) == 0){
	  myFile = fopen(argv[1], "a");
	  char tempMonth[10];
	  
	  for(i=4; i<argc; i+=4){ //loop through all data entered by the user in the coomnd line
	  	
	  	token = strtok(argv[i], s); //begins by breaking up the month in format dd/mm/yyyy and putting it in Month dd yyyy
		dates[0].day = atoi(token);
		token = strtok(NULL, s);
		dates[0].month = atoi(token);
		token = strtok(NULL, s);
		dates[0].year = atoi(token);
		//switch to convert month number to name
		switch(dates[0].month){
			case 1: strcpy(tempMonth, "January"); break;
			case 2: strcpy(tempMonth, "February"); break;
			case 3: strcpy(tempMonth, "March"); break;
			case 4: strcpy(tempMonth, "April"); break;
			case 5: strcpy(tempMonth, "May"); break;
			case 6: strcpy(tempMonth, "June"); break;
			case 7: strcpy(tempMonth, "July"); break;
			case 8: strcpy(tempMonth, "August"); break;
			case 9: strcpy(tempMonth, "September"); break;
			case 10: strcpy(tempMonth, "October"); break;
			case 11: strcpy(tempMonth, "November"); break;
			case 12: strcpy(tempMonth, "December"); break;
			
		}
	  	
	  fprintf(myFile, "%c", 34); //print new line and quote mark
	  fprintf(myFile, "%s %d %d", tempMonth, dates[0].day, dates[0].year);  //print the user date
	  fprintf(myFile, "%c,%c", 34, 34); //print comma and quote mark
	  fprintf(myFile, argv[i-1]); //print the employee ID
	  fprintf(myFile, "%c,%c", 34, 34); //print comma and quote mark
	  fprintf(myFile, argv[i+1]); //print start time
	  fprintf(myFile, "%c,%c", 34, 34); //print comma and quote mark
	  fprintf(myFile, argv[i+2]); // print end time
	  fprintf(myFile, "%c", 34); //print comma and quote mark
	  fprintf(myFile, "\n"); //print new line
	
	}
	
	  
	  printf("Data has been added to file!");
	  fclose(myFile); //closes file
  	
  }
  //The following is for printing the contents of the text file
  else if(strcmp("/p", argv[2]) == 0){
  	char *filename = argv[1];
  	int lines = fileLines(filename); //call function to count the lines of text, this is needed for the loop below
	myFile = fopen(filename, "r"); //open file for reading
  	
  	for(i=0; i<lines; i++){
  	k=0;
		fgets(str, 50, myFile);
			for(j=0; j<50; j++){
				if(str[j]!=34){tempString[k] = str[j]; k++;} //converted string from str to tempString to remove the ""
			}
	//begin to split up the string, starting with the date	
	 token = strtok(tempString, t); 
	 strcpy(tempstr1, token);
	 //the ID
	 token = strtok(NULL, t);
	 datas[i].employeeID = atoi(token);
	 //the startTime
	 token = strtok(NULL, t);
	 strcpy(tempstr2, token);
	 //The endTime
	 token = strtok(NULL, t);
	 strcpy(tempstr3, token);
	 //Now begins breaking up the substrings starting again with the date
	 token = strtok(tempstr1, sp); // converts month name to the number
	 	if(strcmp(token, "January")==0) datas[i].date.month = 1; 
		else if(strcmp(token, "February")==0) datas[i].date.month = 2; 
		else if(strcmp(token, "March")==0) datas[i].date.month = 3; 
		else if(strcmp(token, "April")==0) datas[i].date.month = 4; 
		else if(strcmp(token, "May")==0) datas[i].date.month = 5; 
		else if(strcmp(token, "June")==0) datas[i].date.month = 6; 
		else if(strcmp(token, "July")==0) datas[i].date.month = 7; 
		else if(strcmp(token, "August")==0) datas[i].date.month = 8; 
		else if(strcmp(token, "September")==0) datas[i].date.month = 9; 
		else if(strcmp(token, "October")==0) datas[i].date.month = 10; 
		else if(strcmp(token, "November")==0) datas[i].date.month = 11;
		else if(strcmp(token, "December")==0) datas[i].date.month = 12; 
	 
	 token = strtok(NULL, sp);
	 datas[i].date.day = atoi(token);
	 
	 token = strtok(NULL, sp);
	 datas[i].date.year = atoi(token);
	 //breaks up the startTime
	 token = strtok(tempstr2, l);
	 datas[i].startTime.hour = atoi(token);
	 
	 token = strtok(NULL, l);
	 datas[i].startTime.minute = atoi(token);
	 //finally, breaks up the EndTime
	 token = strtok(tempstr3, l);
	 datas[i].endTime.hour = atoi(token);
	 
	 token = strtok(NULL, l);
	 datas[i].endTime.minute = atoi(token);
	 //prints out the data
	 printf("\nDate: %d/%d/%d Employee: %d started at %d:%d and finished at %d:%d", datas[i].date.day, datas[i].date.month, datas[i].date.year, datas[i].employeeID, datas[i].startTime.hour, datas[i].startTime.minute, datas[i].endTime.hour, datas[i].endTime.minute);
	}
	fclose(myFile); // closes the file
		
}
  //This will allow the user to search by employee Id - approach very similar to /p function above as user may /s without or before doing /p
  else if(strcmp("/s", argv[2]) == 0){
  	
	char *filename = argv[1];
  	int lines = fileLines(filename); //counts the lines used for loop below
	myFile = fopen(argv[1], "r"); // opens file for reading
  	
  	int usercho; //users input search
  	char *idchoice = argv[3];
  	usercho = atoi(idchoice);
  	//identical to loop in printing function
  	for(i=0; i<lines; i++){
  	k=0;
		fgets(str, 50, myFile);
			for(j=0; j<50; j++){
				if(str[j]!=34){tempString[k] = str[j]; k++;} //transfer str to tempString to remove "" in file
			}
	//break up the string in substrings, starting with date	
	 token = strtok(tempString, t);
	 strcpy(tempstr1, token);
	 //then employeeID, NOTE: this does not need to be futher split up
	 token = strtok(NULL, t);
	 datas[i].employeeID = atoi(token);
	 //then StartTime
	 token = strtok(NULL, t);
	 strcpy(tempstr2, token);
	 //then EndTime
	 token = strtok(NULL, t);
	 strcpy(tempstr3, token);
	 //now splits the substrings into smaller parts and places them into the struct, again, starting with the date
	 token = strtok(tempstr1, sp); // converts the word format into number
	 	if(strcmp(token, "January")==0) datas[i].date.month = 1; 
		else if(strcmp(token, "February")==0) datas[i].date.month = 2; 
		else if(strcmp(token, "March")==0) datas[i].date.month = 3; 
		else if(strcmp(token, "April")==0) datas[i].date.month = 4; 
		else if(strcmp(token, "May")==0) datas[i].date.month = 5; 
		else if(strcmp(token, "June")==0) datas[i].date.month = 6; 
		else if(strcmp(token, "July")==0) datas[i].date.month = 7; 
		else if(strcmp(token, "August")==0) datas[i].date.month = 8; 
		else if(strcmp(token, "September")==0) datas[i].date.month = 9; 
		else if(strcmp(token, "October")==0) datas[i].date.month = 10; 
		else if(strcmp(token, "November")==0) datas[i].date.month = 11;
		else if(strcmp(token, "December")==0) datas[i].date.month = 12; 
	 
	 token = strtok(NULL, sp);
	 datas[i].date.day = atoi(token);
	 
	 token = strtok(NULL, sp);
	 datas[i].date.year = atoi(token);
	 //splits the start time into hours and minutes
	 token = strtok(tempstr2, l);
	 datas[i].startTime.hour = atoi(token);
	 
	 token = strtok(NULL, l);
	 datas[i].startTime.minute = atoi(token);
	 //splits the end Time into hours and minutes
	 token = strtok(tempstr3, l);
	 datas[i].endTime.hour = atoi(token);
	 
	 token = strtok(NULL, l);
	 datas[i].endTime.minute = atoi(token);
  	
  }
  //finally a very simple search feature
  for(i=0; i<lines; i++){
  	if(usercho == datas[i].employeeID){printf("\nDate: %d/%d/%d Employee: %d started at %d:%d and finished at %d:%d", datas[i].date.day, datas[i].date.month, datas[i].date.year, datas[i].employeeID, datas[i].startTime.hour, datas[i].startTime.minute, datas[i].endTime.hour, datas[i].endTime.minute);}
  }
  
	}
  //if none of the above command are entered
  else{
  	printf("Unknown command!");
	}

	return;
} 


int fileLines(char *filename){ //function to count the number of lines in the text file
 FILE *fp;
 char ch;
 int linecount, charcount;
 linecount = 0;
 charcount = 0; // character count only used to know if there is at least 1 line
 
 fp = fopen(filename,"r"); //open file to read
//loop to begin counting
   if (fp)
   {	
	   while ((ch=getc(fp)) != EOF) { //Repeats until End Of File character
		    if (ch != ' ' && ch != '\n') { ++charcount; } //count the characters
		    if (ch == '\n') { ++linecount; } //count the lines (most important)
		   
		}

	   if (charcount > 0) { //at least 1 line if theres 1 characters
		++linecount;
	   }
    }
//if it refuses to work
   else
      {
         printf("Failed to read the files lines\n");
        }
    
	//prompt for user    
    printf("Press Enter to Return Results");
        
getchar();
return linecount-1; //returns the number minus 1 aswas returning last line twice
}
