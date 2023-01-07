/*
Noah Nisbet
Project 4 Wordle Assistant
December 5, 2022
CPSC 1070

Wordle.h file that prototypes the functions defined in 
Wordle.c and run in the driver file Project-4.c
*/

#ifndef WORDLE_H
#define WORDLE_H

// Load dictionary gets all possible words from a document and returns
// The number of 5 letter words
// the input array of char pointers is then filled with all 5 letter
// words
int loadDictionary(char *input[]);
// Prompt user for more information about the current wordle standings
char * promptUser();
// Process guess takes in all 5 letter words, the number of words in that
// array and the 5 letters obtained from prompt user.
// It then finds all the possible words for the wordle
void processGuess(char *input[], int num5, char letter1, char letter2,
		  char letter3, char letter4, char letter5);
// prints out all possible words from processGuess
void printResults(char *input[], int);
// "main method" that combines the above functions.
void helpMe();

#endif
