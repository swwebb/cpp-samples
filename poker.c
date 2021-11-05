
// Card shuffling and dealing.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>


#define SUITS 4
#define FACES 13
#define CARDS 52
#define HANDSIZE 5

// prototypes
void shuffle(unsigned int wDeck[][FACES]); // shuffling modifies wDeck
void deal(unsigned int wDeck[][FACES], const char *wFace[], 
   const char *wSuit[]); // dealing doesn't modify the arrays
bool hasPair(unsigned int hand[][FACES]);
bool hasThreeOfAKind(unsigned int hand[][FACES]);
bool hasStraight(unsigned int hand[][FACES]);


int main(void)
{
   // initialize deck array
   unsigned int deck[SUITS][FACES] = { 0 };

   // initialize suit array                       
   const char *suit[SUITS] =            
      {"Hearts", "Diamonds", "Clubs", "Spades"};
   
   // initialize face array                   
   const char *face[FACES] =
      {"Ace", "Deuce", "Three", "Four",         
       "Five", "Six", "Seven", "Eight",         
       "Nine", "Ten", "Jack", "Queen", "King"};
	   
	   
   srand(time(NULL)); // seed random-number generator

   shuffle(deck); // shuffle the deck

   deal(deck, face, suit); // deal the deck
   
   printf("\n");
   
   if(hasPair(deck)) {
       printf("Has pair\n");
   }
   else {
       printf("No pair\n");
   }
   
   if(hasThreeOfAKind(deck)) {
       printf("Has three of a kind\n");
   }
   else {
       printf("No three of a kind\n");
   }
   
   if(hasStraight(deck)) {
       printf("Has straight\n");
   }
   else {
       printf("No straight\n");
   }
   
} 

// shuffle cards in deck
void shuffle(unsigned int wDeck[][FACES])
{
   // for each of the cards, choose slot of deck randomly
   for (size_t card = 1; card <= CARDS; ++card) {
      size_t row; // row number
      size_t column; // column number

      // choose new random location until unoccupied slot found
      do {                                                        
         row = rand() % SUITS;                                   
         column = rand() % FACES;                             
      } while(wDeck[row][column] != 0); // end do...while

      // place card number in chosen slot of deck
      wDeck[row][column] = card;
   } 
}

// deal cards in deck into a hand of 5
void deal(unsigned int wDeck[][FACES], const char *wFace[],
   const char *wSuit[])
{
   // deal 5 of the cards
   for (size_t card = 1; card <= HANDSIZE; ++card) {
      // loop through rows of wDeck
      for (size_t row = 0; row < SUITS; ++row) {
         // loop through columns of wDeck for current row
         for (size_t column = 0; column < FACES; ++column) {
            // if slot contains current card, display card
            if (wDeck[row][column] == card) {
               printf("%5s of %-8s%c", wFace[column], wSuit[row],
                  card % 2 == 0 ? '\n' : '\t'); // 2-column format
            } 
         } 
      } 
   } 
}

// determine if hand has a pair
bool hasPair(unsigned int hand[][FACES]) {
    // initialize array to keep track of the number of occurences of each face
    unsigned int faceCount[FACES] = {0};
   // deal each of the cards
   for (size_t card = 1; card <= HANDSIZE; ++card) {
      // loop through rows of hand
      for (size_t row = 0; row < SUITS; ++row) {
         // loop through columns of hand for current row
         for (size_t column = 0; column < FACES; ++column) {
            // if slot contains current card, increase the count for that face
            if (hand[row][column] == card) {
               faceCount[column] += 1; 
               // if the count for a face is 2, then there is a pair
               if(faceCount[column] == 2) {
                   return true;
               }
            } 
         } 
      } 
   } 
   // no pairs were found
   return false;
}

// determine if hand has a three of a kind
bool hasThreeOfAKind(unsigned int hand[][FACES]) {
    // initialize array to keep track of the number of occurences of each face
    unsigned int faceCount[FACES] = {0};
   // deal each of the cards
   for (size_t card = 1; card <= HANDSIZE; ++card) {
      // loop through rows of hand
      for (size_t row = 0; row < SUITS; ++row) {
         // loop through columns of hand for current row
         for (size_t column = 0; column < FACES; ++column) {
            // if slot contains current card, increase the count for that face
            if (hand[row][column] == card) {
               faceCount[column] += 1; 
               // if the count for a face is 3, then there is a three of a kind
               if(faceCount[column] == 3) {
                   return true;
               }
            } 
         } 
      } 
   } 
   // no three of a kinds were found
   return false;
}
    
    
// determine if hand has a straight
bool hasStraight(unsigned int hand[][FACES]) {
    // initialize array to keep track of the number of occurences of each face
    unsigned int faceCount[FACES] = {0};
   // deal each of the cards
   for (size_t card = 1; card <= HANDSIZE; ++card) {
      // loop through rows of hand
      for (size_t row = 0; row < SUITS; ++row) {
         // loop through columns of hand for current row
         for (size_t column = 0; column < FACES; ++column) {
            // if slot contains current card, increase the count for that face
            if (hand[row][column] == card) {
               faceCount[column] += 1; 
            } 
         } 
      } 
   } 
   
    // keep track of the number of faces in a row
    unsigned int inARow = 0;
    
    // loop through the faces
    for(size_t face = 0; face < FACES; face++) {
        // if there is at least 1 of the current face, then count that for consecutive faces
        if(faceCount[face] >= 1) {
            inARow += 1;
            // if there are 5 consecutive faces, then there is a straight
            if(inARow == 5) {
                return true;
            }
        }
        else {
            // if there are no cards of the current face, then the consecutive count is reset
            inARow = 0;
        }
    }
   
   // no straights were found
   return false;
}
    



