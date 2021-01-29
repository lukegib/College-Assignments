#include "string.h"
#include "stdarg.h"
#include "stdlib.h"
#include "time.h"
#include <stdbool.h>

typedef enum S {CLUBS, DIAMONDS, HEARTS, SPADES} SUIT; 
char suits[][10] = {"CLUBS", "DIAMONDS", "HEARTS", "SPADES"}; 

typedef enum F {TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING, ACE} FACE;
char faces[][10] = {"TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE", "TEN", "JACK", "QUEEN", "KING", "ACE"};

typedef struct
{
	SUIT suit; 
	FACE face;
} card;

typedef struct
{
	card cards[5];
} hand;

// function deals a random hand of cards - BUT .... same card CANNOT be dealt twice!
// so if same card already in the hand, you would need to draw again
// also, the card cannot appear in another hand either
hand dealHand(hand handsDealt[], int numHandsDealt);

// returns pointer to string containing, for example, "ACE of HEARTS"
char * printCard(card aCard);

// compares the FACE values of two cards (TWO is lowest, ACE is highest)
// returns pointer to string containing name of winner: "You" or "Dealer" (or "Draw" if the face values are the same)
char * compareCards(card yourCard, card dealersCard);

// returns true if the hand contains four ACES
bool fourAces(hand aHand);


void main()
{
	int i = 0;
	hand myHand, dealersHand;
	int seed = time(NULL);
	srand(seed);
	hand hands[10];

	// deal the first hand
	myHand = dealHand(hands, 0);
	
	// add this new hand to the set of dealt hands
	hands[0] = myHand;

	// deal another hand; let dealHand know what has already been dealt
	dealersHand = dealHand(hands, 1);

	// here you are just comparing each card one at a time in the two hands
	while(i<5)
	{
		printf("card#%d: %s (you) vs. %s (dealer). Winner: %s \n", i+1, printCard(myHand.cards[i]), printCard(dealersHand.cards[i]),  compareCards(myHand.cards[i], dealersHand.cards[i]));
		i++;
	}
	
	// now try to deal 4 Aces !
	while(1)
	{
		// deal a new hand; assume new deck every time, so nothing dealt already
		myHand = dealHand(hands,0);
		
		// does it contain 4 ACES?
		if (fourAces(myHand)) break;
		i++; // keep track of number of hands dealt
	}
	// print out how many hands it took to find 4 aces
	printf ("\n\n4 aces found after %d hands \n\n\n", i); 
}

// compares the FACE values of two cards (TWO is lowest, ACE is highest)
// returns pointer to string containing name of winner: "You" or "Dealer" (or "Draw" if the face values are the same)
char * compareCards(card yourCard, card dealersCard)
{
	char * sptr;
	sptr = (char *)malloc(10*sizeof(char));

	if(yourCard.face > dealersCard.face) strcpy(sptr, "You");
	
	else if (dealersCard.face > yourCard.face) strcpy(sptr, "Dealer");
	
	else strcpy(sptr, "Draw");

	return sptr;
}

// returns pointer to string containing, for example, "ACE of HEARTS"
char * printCard(card aCard)
{
	char * sptr;
	sptr = malloc (strlen(faces[aCard.face]) + strlen(suits[aCard.suit]) + 6); //allocate space for pointer to hold string
	
	
	strcpy(sptr, faces[aCard.face]); // copy the face value into string
	strcat(sptr, " of "); //insert middle 'of'
	strcat(sptr, suits[aCard.suit]); //put suit value at end
	
	return sptr;
}

// function deals a random hand of cards - BUT .... same card CANNOT be dealt twice!
// so if same card already in the hand, you would need to draw again
// also, the card cannot appear in another hand either
hand dealHand(hand handsDealt[], int numHands)
{
	int i, n;
	int found = 0; //un used
	hand newHand;
	int ncards = 0;

	SUIT newSuit;
	FACE newFace;
	i=0;
	while(i<5){
		newSuit = rand() % 4; // generate random number for suit between 0-3
		newFace = rand() % 13; // generate random number for face between 0-12
		
		newHand.cards[i].suit = newSuit;
		newHand.cards[i].face = newFace;
		//loop to iterate through the cards dealt before and check if they are the same
		for(n=(i-1); n>=0; n--){
			if(newHand.cards[i].suit == newHand.cards[n].suit && newHand.cards[i].face == newHand.cards[n].face){
			 	i--; 
			 	goto SKIP; //skips to end of loop and iterates i by 1;
			}
		}
		//loop to check the previous hand dealt and make sure card hasnt already been dealt in it
		if(numHands == 1){
			for(ncards=0; ncards<5; ncards++){ //awkward counter - ncards... unsure if had to use given variables
				if(newHand.cards[i].suit == handsDealt[0].cards[ncards].suit && newHand.cards[i].face == handsDealt[0].cards[ncards].face){
					i--;
					break;
				}
			}
		}
		
		SKIP: i++; //goto staement leads here
	}
	return newHand;
}

// returns true if the hand contains four ACES
bool fourAces(hand aHand)
{
	int i, n;
	int numAces = 0;
	bool fourAces = false;

	i=0;
	while(i<5){
		aHand.cards[i].suit = rand() % 4; //gets random number between 0-3 for suit value
		aHand.cards[i].face = rand() % 13; //gets random number between 0-12 for face value
		//almost identical loop as dealCard function to check if card has already been dealt
		for(n=(i-1); n>=0; n--){
			if(aHand.cards[i].suit == aHand.cards[n].suit && aHand.cards[i].face == aHand.cards[n].face){
			 	i--; 
			 	goto SKIP; //goes to end of loop to draw a new card
			}
		}
		
		if(aHand.cards[i].face == 12) numAces++; //iterates by 1 if an ace is found
		if(numAces == 4) fourAces = true; //returns true if 4 aces are found
		
		SKIP: i++;
	}
	
	return fourAces;

}

