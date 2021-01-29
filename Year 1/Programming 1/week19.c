#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct result
{
char last[40];
char first[40];
int age;
char email[40];
struct result *next;
};


int main(){
	FILE *myFile; 
	myFile = fopen("C:/Users/Luke/Desktop/users.txt", "r");
	char str[50]; //string to place lines of file
    const char s[6] = ","; //used for strtok function
    char *token;
    struct result *first = NULL; //set as NULL to know where list begins\ends
    struct result *new_node; //variable to point to node until its been inserted into list 
    struct result *current; //used for searching through linked list
    int i;
    int usernum = 1; //users entered number, initialised as 1 for loop
    
    
    if (myFile == NULL){ 				// displays if invalid file is entered
        printf("Error Reading File\n");
        exit (0);
    }
    //loop to read all lines of data in the file
    for(i=0; i<101; i++){
	
	new_node = malloc(sizeof(struct result)); //allocates memory to new node
	//begins spltting up data and allocating them into the struct
    fgets(str, 50, myFile);
    token = strtok(str, s);
    strcpy(new_node->last, token);
    
    token = strtok(NULL, s);
    strcpy(new_node->first, token);
    
    token = strtok(NULL, s);
    new_node->age = atoi(token); //converts to int
    
    token = strtok(NULL, s);
    strcpy(new_node->email, token);
    
    new_node->next = first; //puts NULL into struct to symbol end of list at first loop, then crates a list by pointing the new entry to previous one
    first = new_node; //points first to the last node, this moves the node to the front of the list
	
	}
	
	while(usernum !=0){
	printf("Enter which age you want to search for (0=exit): ");
	scanf("%d", &usernum);
	
	//loop through list to find ages same as the usernum, if user enters 0 the program exits
		for(current = first; current!=NULL; current = current->next){
			if(usernum == current->age){printf("%s %s\n", current->first, current->last);}
			else if(usernum == 0){break;}
		}
	}
    
    
}
