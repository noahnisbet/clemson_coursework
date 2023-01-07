/*
Noah Nisbet
Project 4 Wordle Assistant
December 5, 2022
CPSC 1070

Wordle.h file that prototypes the functions defined in
Wordle.c and run in the driver file Project-4.c
*/

#include "Wordle.h"
#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "ctype.h"

// Load dictionary takes in an array of char pointers and
// returns the number of all 5 letter words in the dictionary
int loadDictionary(char* input[]){

  // file object used to open words documenr
  FILE *wordsfile;
  // setting max length of a word to 30.
  int maxLength = 30;
  // c-string for storing the current word when looping over lines
  // in wordsfile
  char curWord[maxLength];
  // variable to track number of 5 letter words
  int numWords = 0;

  // open words
  wordsfile = fopen("/usr/share/dict/words","r");

  // get each line and set it to current word while the
  // current line is not NULL
  // this goes through the doc line by line until the end.
  while(fgets(curWord, maxLength, wordsfile) != NULL) {

    // Make sure the word is alphanumeric
    // sentinel value
    int alNum = 1;
    // loop over all chars in c-string and find if a character
    // is not alphanumic, if so change sentinel value
    for (int i=0; i<strlen(curWord)-1; i++){
      if(!isalnum(curWord[i])){
	alNum = 0;
      }
    }
    // if the length of the current word is 6 (including '\n' character)
    // and the alphanumic sentinel value is unchanged copy the
    // string too input.
    if ((strlen(curWord) == 6) && (alNum == 1)){
      input[numWords] = (char *)malloc(sizeof(char)*5);
      strncpy(input[numWords], curWord, 5);
      // increment num words
      numWords++;
    }
  }

  // close the file
  fclose(wordsfile);

  // return number of words
  return numWords;
}

// Prompt user takes no parameters and returns a pointer to the
// beginning of a char array with th user's input.
char * promptUser(){

  // User input c-string
  char inputString[30];
  // print out info to the user
  puts("Enter the Wordle clues using the following scheme:");
  puts("\tA-Z for a known letter in the right position");
  puts("\ta-z for a letter that is correct in the wrong position");
  puts("\t* for an unkown letter");
  puts("\tSeperate each with a space (e.g., T * G i R)");
  printf("Enter your query now: ");
  // retrieve the input and set it to inputString 
  fgets(inputString, 30, stdin);

  // create cleanedString which will be returned from this function
  // cleaned string will have no spaces included.
  char * cleanedString = (char *)malloc(sizeof(char)*30);
  int cleanedStringIdx = 0;
  // loop over the input and add the element to cleaned string
  // if the character is not a space.
  for (int i=0; i<strlen(inputString)-1; i++){
    if (inputString[i] != ' '){
      cleanedString[cleanedStringIdx] = inputString[i];
      cleanedStringIdx++;
    }
  }

  // remove terminating character
  cleanedString[cleanedStringIdx++] = '\0';

  // return cleanedString
  return cleanedString;
}

// processGuess takes in a array "dictionary" of all 5 letter words,
// the number of words in dictionary, and each letter of the user's input
// which represents what they know about the wordle word of the day.
void processGuess(char *dictionary[], int num5, char letter1, char letter2,
		  char letter3, char letter4, char letter5){

  // create an array of the 5 input letters
  char word[5] = {letter1, letter2,
		  letter3, letter4,
		  letter5};
  // indicies array that stores the indicies of all the "matches" found
  // I will later count the occurances of each index in indicies
  int indicies[num5];
  // curIndex is used with indicies to keep track of the current index when
  // looping
  int curIndex = 0;
  // array of all lowercase letters
  char lowerCase[5];
  // lowerIdx is the current index of lowercase it also
  int lowerIdx = 0;
  // represents the number of uppercase letters in the input
  int numCaps = 0;
  // represents the number of lowercase letters in the input
  int numLower = 0;

  // fill lowerCase array and update numLower
  for (int i=0; i<5; i++){
    if (islower(word[i])){
      lowerCase[numLower] = word[i];
      numLower++;
    }
  }
  // update numCaps to the number of uppercase letters
  for (int i=0; i<5; i++){
    if (isupper(word[i])){
      numCaps++;
    }
  }

  // if the first letter is uppercase loop over all words and find the
  // number of words that have the input's first letter as its
  // first letter
  if (isupper(word[0])){
    // counter for number of words where the first letters match
    int firstLettersMatch = 0;
    // loop over all 5 letter words
    for(int i=0; i<num5; i++){
      // if the first letter in the current 5 letter word matches
      // the input add that index to indicies
      // (this is only if the dictionary words are uncapitalized because
      // there are repeats)
      if (dictionary[i][0] == tolower(word[0])){
	indicies[curIndex] = i;
	curIndex++;
      }
      // if the first letter in the current 5 letter word matches
      // the input regardless of capitalization increment the
      // firstLettersMatch variable
      if (tolower(dictionary[i][0]) == tolower(word[0])){
	firstLettersMatch++;
      }
    }
    // print however many first letters match.
    printf("Found %d words starting with %c\n",
	   firstLettersMatch, letter1);
  }

  // Same as above just for all the other letters

  // loop over letters in input word from index 1 to 5
  // (not including the first letter)
  for (int i=1; i<5; i++){
    // if the word is uppercase and not a * check for matches
    if ((word[i] != '*') && isupper(word[i])){
      // matches variable for keeping track of the number of words in
      // dictionary that match at that position
      int matches = 0;
      // loop over all words in the dictionary for the current input word index.
      for(int j=0; j<num5; j++){
	// if the current indicies match up add the index of the current word
	// in dictionary to indicies 
	if (dictionary[j][i] == tolower(word[i])){
	  indicies[curIndex] = j;
	  curIndex++;
	}
	// increment the number of matches if the index of the current letter in
	// the input word matches the current iterate in dictionaries
	// (regardless of uppercase or lowercase)
	if (tolower(dictionary[j][i]) == tolower(word[i])){
	  matches++;
	}
      }
      // print out the number of matches for the current letter.
      printf("Found %d words with %c in position %d\n",
	     matches++, word[i], i+1);
    }
  }

  // create an occurance array the same length as the dictionary
  // this array will keep track of the occurances of each index
  // at each index. So if there were 3 matches above at index 100
  // index 100 in occurances would be 3.
  int occurances[num5];
  // multioccurances holds the indecies of occurances where occurances
  // has an accurance of the number of capital letters
  // this would hold our best matches so far.
  int multiOccurances[curIndex];
  int multiOccurancesIdx = 0;

  // initialize occurances to hold only zeros
  for (int i=0; i<num5; i++){
    occurances[i] = 0;
  }

  // loop over all of indicies and increment occurances at the indicies
  // held in indicies.
  for (int i=0; i<curIndex; i++){
    occurances[indicies[i]]++;
  }

  // loop over occurances and if the current occurance index has a count
  // greater than numCaps-1 then add it to multiOccurances.
  for (int i=0; i<num5; i++){
    if(occurances[i]>numCaps-1){
      multiOccurances[multiOccurancesIdx] = i;
      multiOccurancesIdx++;
    }
  }

  // create newDictionary which will replace dictionary with the possible
  // wordle words
  char *newDictionary[num5];
  // newDictionaryIdx keeps track of the current index of newDictionary
  int newDictionaryIdx = 0;

  // This part of the code narrows down possible words with the lowercase letters
  // loop over the multiOccurances matrix
  for (int i=0; i<multiOccurancesIdx; i++){

    // counter for number of the lowercase letters in multiOccurances
    int containsLower = 0;

    // loop over all the lowercase letters in the input.
    for (int k=0; k<numLower; k++){
      // sentinel value that changes when the letter is found
      int letterFound = 0;
      // loop over the letters in the current word in multiOccurances and check if any of those letters are
      // the same letter as that of a lowercase letter in the input.
      // If so increment contains lower and letter found. This way the same letter isn't counted twice for
      // Words in multiOccurance with 2 of the same letter that happen to match up with input lowercase letters
      for (int j=0; j<5; j++){
	if((tolower(lowerCase[k]) == tolower(dictionary[multiOccurances[i]][j])) && (letterFound == 0)){
	  containsLower++;
	  letterFound++;
	}
      }
    }
    // if the current word in multiOccurances has the same number of occurances of the lowercase letters
    // as the number of lowercase letters in the input copy the current word in multiOccuraces to newDictionary
    // newDictionary will replace dictionary since dictionary is passed by reference
    if (containsLower == numLower){
      newDictionary[newDictionaryIdx] = (char *)malloc(sizeof(char)*5);
      strncpy(newDictionary[newDictionaryIdx], dictionary[multiOccurances[i]],5);
      newDictionaryIdx++;
    }
  }
  // loop over dictionary and replace the current index in dictionary with the current index in newDictionary
  // once we run out of values in newDictionary free up the rest of the dictionary pointer array.
  for (int i=0; i<num5; i++){
    if (i < newDictionaryIdx+1){
      dictionary[i] = newDictionary[i];
    }
    else{
      free(dictionary[i]);
    }
  }

  // finished!
  return;
}

// helpMe function that takes no parameters and returns nothing, just connects the functions defined above to get the
// user input and then print out information and helpful words!
void helpMe(){

  // array of char pointers that will hold all 5 letter words
  char* dictionary[10000];
  // num words keeps track of the number of 5 letter words.
  int numWords;
  // char pointer that will be the start of a char pointer array.
  // this is will hold the value returned by promptUser.
  char *userInput;

  // print out information about the number of 5 letter words.
  puts("");
  puts("Welcome to the Wordle Assistant!");
  puts("Processing Dictionary");
  numWords = loadDictionary(dictionary);
  printf("%d out of 102401 words in the dictionary are 5 characters!\n\n", numWords);

  // prompt user
  userInput = promptUser();

  // process guess
  processGuess(dictionary, numWords, userInput[0], userInput[1], userInput[2],
               userInput[3],userInput[4]);

  // printResults.
  printResults(dictionary, numWords);

  return;
}

// printResults takes in a dictionary of all helpful words from wordle assistant and the
// number of all 5 letter words, and prints out the helpful words to the user.
void printResults(char* dictionary[], int numWordsAll){  

  // num words will hold the number of words in dictionary.
  int numWords = 0;
  // loop over dictionary until we get to the end
  while(dictionary[numWords] != NULL){
    // increment numWords at each iteration
    numWords++;
  }

  // if numWords is less than 100 print out helpful words in dictionary
  // otherwise print out that there are too many possibilities.
  if (numWords < 100){
    puts("Viable Options:");
    for (int i=0; i<numWords; i++){
      printf("\t%d: %s\n",i,dictionary[i]);
    }
    puts("");
  }
  else{
    puts("There are too many possibilities!");
  }

  // return
  return;
}
