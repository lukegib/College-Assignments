#include <string.h>
#include <stdio.h>
#include <ctype.h>

struct data{
	char fname[20];
	char lname[20];
	char company[50];
	char address[20];
	char city[20];
	char county[20];
	char state[20];
	int zip;
	char ph1[20];
	char ph2[20];
	char email[40];
	char web[40];
};

int main () {
	FILE *myFile; //Pointer to file
    myFile = fopen("C:/Users/Luke/Desktop/us500.txt", "r+"); //Read file
    char str[200]; //string to place lines of file
    const char s[12] = ","; //used for strtok function
    int i=0; int j = 0; int k = 0; int m; //counter variables
    char *token; //token for string seperation
    struct data people[550]; //array to store data
    int userchoice;
    char userinput[50];
    int count1 = 0; int count2 = 0;
    int flag; //alert for finding sub string in string
    char temp[50];
    
   if (myFile == NULL){ 				// displays if invalid file is entered
        printf("Error Reading File\n");
        exit (0);
    }
	//loop to read file line by line and store the data in the data structure arrays
	for(i=0; i<501; i++){
		fgets(str, 200, myFile);
		//read firstname
		token = strtok(str, s);
		strcpy(people[i].fname, token);
		//read lastname
		token = strtok(NULL, s);
		strcpy(people[i].lname, token);
		//read company name
		token=strtok(NULL, s);
		strcpy(people[i].company, token);
		//read address
		token=strtok(NULL, s);
		strcpy(people[i].address, token);
		//read city
		token=strtok(NULL, s);
		strcpy(people[i].city, token);
		//read county etc...
		token=strtok(NULL, s);
		strcpy(people[i].county, token);
		
		token=strtok(NULL, s);
		strcpy(people[i].state, token);
		
		token=strtok(NULL, s);
		people[i].zip = token;
		
		token=strtok(NULL, s);
		strcpy(people[i].ph1, token);
		
		token=strtok(NULL, s);
		strcpy(people[i].ph2, token);
		
		token=strtok(NULL, s);
		strcpy(people[i].email, token);
		
		token=strtok(NULL, s);
		strcpy(people[i].web, token);
		
	}			
	  	
	fclose(myFile); //close file
	  	
	printf("Search by:\n 1. First Name\n 2. Last Name\n 3. Company Name\n 4. City\n 5. Primary Phone Number\n 0. Exit\n"); //user selection
	scanf("%d", &userchoice);
	
	//if user exits
	if(userchoice==0){
		printf("Exiting Program, Thank You.");
	}
	
	//search by first name
	if(userchoice == 1){
		printf("Searching by name --- Enter characters: "); 
		scanf("%s", &userinput);
		//loop through all names
		for(i=0; i<501; i++){
			strcpy(temp, people[i].fname); //copy the name into a temp array, this is so the original is not capitalised
   			count1 = strlen(temp);
    		count2 = strlen(userinput);
    		//loops to convert the array characters in capitals
			for(m=0; m<=count2; m++){
				userinput[m]=toupper(userinput[m]);
			}
			for(m=0; m<=count1; m++){
				temp[m]=toupper(temp[m]);
			}
    		//loop to find if the substring exists in the string
    		for(j=0; j <= count1 - count2; j++){
    			for(k = j; k<j+count2; k++){
    			
    				flag = 1;
    				if(temp[k] != userinput[k-j]){ flag = 0; break;}
				}
    			//returns if true 
				if(flag==1){
    			printf("\nFirst Name: %s\nLast Name: %s\nCompany Name: %s\nAddress: %s\nCity: %s\nCounty: %s\nState: %s\nZip Code: %d\nPhone No.1: %s\nPhone No.2: %s\nWebsite: %s\n", people[i].fname, people[i].lname, people[i].company, people[i].address, people[i].city, people[i].county, people[i].state, people[i].zip, people[i].ph1, people[i].ph2, people[i].email, people[i].web);	
				}	
			
			}
	 	}
	}
	
	//search for last name
	if(userchoice == 2){
		printf("Searching by Last Name --- Enter characters: "); 
		scanf("%s", &userinput);
		//loop through all names
		for(i=0; i<501; i++){
			strcpy(temp, people[i].lname); //copy the name into a temp array, this is so the original is not capitalised
   			count1 = strlen(temp);
    		count2 = strlen(userinput);
    		//loops to convert the array characters in capitals
			for(m=0; m<=count2; m++){
				userinput[m]=toupper(userinput[m]);
			}
			for(m=0; m<=count1; m++){
				temp[m]=toupper(temp[m]);
			}
    		//loop to find if the substring exists in the string
    		for(j=0; j <= count1 - count2; j++){
    			for(k = j; k<j+count2; k++){
    			
    				flag = 1;
    				if(temp[k] != userinput[k-j]){ flag = 0; break;}
				}
    			//returns if true
				if(flag==1){
    			printf("\nFirst Name: %s\nLast Name: %s\nCompany Name: %s\nAddress: %s\nCity: %s\nCounty: %s\nState: %s\nZip Code: %d\nPhone No.1: %s\nPhone No.2: %s\nWebsite: %s\n", people[i].fname, people[i].lname, people[i].company, people[i].address, people[i].city, people[i].county, people[i].state, people[i].zip, people[i].ph1, people[i].ph2, people[i].email, people[i].web);	
				}	
			
			}
	 	}
	}
	
	//loop through all company names 
	if(userchoice == 3){
		printf("Searching by Company Name --- Enter characters: "); 
		scanf("%s", &userinput);
		//loop through all names
		for(i=0; i<501; i++){
			strcpy(temp, people[i].company); //copy the name into a temp array, this is so the original is not capitalised
   			count1 = strlen(temp);
    		count2 = strlen(userinput);
    		//loops to convert the array characters in capitals
			for(m=0; m<=count2; m++){
				userinput[m]=toupper(userinput[m]);
			}
			for(m=0; m<=count1; m++){
				temp[m]=toupper(temp[m]);
			}
    		//loop to find if the substring exists in the string
    		for(j=0; j <= count1 - count2; j++){
    			for(k = j; k<j+count2; k++){
    			
    				flag = 1;
    				if(temp[k] != userinput[k-j]){ flag = 0; break;}
				}
    			//returns if true
				if(flag==1){
    			printf("\nFirst Name: %s\nLast Name: %s\nCompany Name: %s\nAddress: %s\nCity: %s\nCounty: %s\nState: %s\nZip Code: %d\nPhone No.1: %s\nPhone No.2: %s\nWebsite: %s\n", people[i].fname, people[i].lname, people[i].company, people[i].address, people[i].city, people[i].county, people[i].state, people[i].zip, people[i].ph1, people[i].ph2, people[i].email, people[i].web);	
				}	
			
			}
	 	}
	}
	
	//search for the city
	if(userchoice == 4){
		printf("Searching by City --- Enter characters: "); 
		scanf("%s", &userinput);
		//loop through all cities
		for(i=0; i<501; i++){
			strcpy(temp, people[i].city); //copy the name into a temp array, this is so the original is not capitalised
   			count1 = strlen(temp);
    		count2 = strlen(userinput);
    		//loops to convert the array characters in capitals
			for(m=0; m<=count2; m++){
				userinput[m]=toupper(userinput[m]);
			}
			for(m=0; m<=count1; m++){
				temp[m]=toupper(temp[m]);
			}
    		//loop to find if the substring exists in the string
    		for(j=0; j <= count1 - count2; j++){
    			for(k = j; k<j+count2; k++){
    			
    				flag = 1;
    				if(temp[k] != userinput[k-j]){ flag = 0; break;}
				}
    			//returns if true
				if(flag==1){
    			printf("\nFirst Name: %s\nLast Name: %s\nCompany Name: %s\nAddress: %s\nCity: %s\nCounty: %s\nState: %s\nZip Code: %d\nPhone No.1: %s\nPhone No.2: %s\nWebsite: %s\n", people[i].fname, people[i].lname, people[i].company, people[i].address, people[i].city, people[i].county, people[i].state, people[i].zip, people[i].ph1, people[i].ph2, people[i].email, people[i].web);	
				}	
			
			}
	 	}
	}
	
	//search for the primary number
	if(userchoice == 5){
		printf("Searching by Phone Number --- Enter characters: "); 
		scanf("%s", &userinput);
		//loop through all numbers
		for(i=0; i<501; i++){
			strcpy(temp, people[i].ph1); //copy the number into a temp array, this is so the original is not capitalised
   			count1 = strlen(temp);
    		count2 = strlen(userinput);
    		//loop to find if the substring exists in the string
    		for(j=0; j <= count1 - count2; j++){
    			for(k = j; k<j+count2; k++){
    			
    				flag = 1;
    				if(temp[k] != userinput[k-j]){ flag = 0; break;}
				}
    			//returns if true
				if(flag==1){
    			printf("\nFirst Name: %s\nLast Name: %s\nCompany Name: %s\nAddress: %s\nCity: %s\nCounty: %s\nState: %s\nZip Code: %d\nPhone No.1: %s\nPhone No.2: %s\nWebsite: %s\n", people[i].fname, people[i].lname, people[i].company, people[i].address, people[i].city, people[i].county, people[i].state, people[i].zip, people[i].ph1, people[i].ph2, people[i].email, people[i].web);	
				}	
			
			}
	 	}
	}
	
	
}

