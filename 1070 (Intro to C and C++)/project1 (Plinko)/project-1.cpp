/*
Noah Nisbet
September 2022
CPSC 1070
Project-1 Plinko

This program uses random number generation to simulate the Plinko game on the price is right.
*/
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//Menu for starting game
char runMenu(int chips,int winnings){
  // Using string because it helps with input validation
  // if someone inputs 11111111 it would be accepted with a char
  // with a string it will not work, and I simply return the first element of the string to return char
  string userInput;

  //Getting user input
  cout<<"---- CPSC 1070 Plinko Menu ----\n"<<endl;
  cout<<" You have "<<chips<<" Plinko chips to use"<<endl;
  cout<<" Total Winnings $"<<winnings<<"!\n"<<endl;
  cout<<" [1] to bid on items to earn chips"<<endl;
  cout<<" [2] to play PLINKO!"<<endl;
  cout<<" [3] to print out the current board"<<endl;
  cout<<" [Q] to quit\n"<<endl;
  cout<<"Your choice?: ";  
  cin >> userInput;

  //Validate Response is a valid input
  while (userInput != "1" && userInput != "2" && userInput != "3" && userInput != "q" && userInput != "Q"){
      cout<<"You did not enter a valid response!"<<endl;
      cout<<"Enter another choice?: ";
      cin >> userInput;
    }

  // Returns the validated response from the user for use in runGame
  // the user response will let runGame know which functions to run
  return userInput[0];
  }

// Function that returns number of chips won from betting
// This implements a 50/50 chance for each chip
// Not sure if this is how we are supposed to implement it
int bidOnPrizes(void){
  int chips = 0;
  for (int i=0; i<4; i++){
    int result = (rand() % 2) + 1;
    if (result == 1){
      chips += 1;
    }}
  // Returns the number of chips "won" to runGame where it will add the chips to the current players chip balance and let the user know how many chips are won
    return chips;
}

//Function used in playPlinko for the random movement
int puckDirection(int currentRow, int currentColumn){

  //Returns 1 if the puck is going to move right and -1 if the puck is going to move left
  //This value is added to the currentColumn variable in the playPlinko function
  
  if (currentColumn == 0){
    return 1;
  }
  if (currentColumn == 16){
    return -1;
  }

  // 50/50 chance is if the random number is even or odd using mod
  int result = rand()%2;
  
  if (result == 0){
    return 1;
  }
  if (result == 1){
    return -1;
  }
  cout<<"error in puckDirection, value outside of if structure, moving puck right"<<endl;
  return 1;
}

// Displaying the 2D plinkoBoard array
void displayBoard(char plinkoBoard[12][17] , int rows, int columns){

  // printing the slot numbers
  // There is a number/slot for every other column so modulus can be used to print the current slot number for every other column 
  cout<<endl;
  int curSlot = 1;
  for (int i =0; i<(columns+1); i++){
    if (i%2 == 0){
      cout<<curSlot<<"      ";
      curSlot += 1;
    }
    else{
    cout<<"       ";
    }
  }
  cout<<endl;

  // Print the board with nested for loop (one loop for rows and other for columns)
  for (int i = 0; i<rows; i++){
    for (int j = 0; j<columns; j++){
      cout<<plinkoBoard[i][j]<<"      ";
      }
    cout<<endl;
    }
  // Print bottom of board with markers for winnings
  cout<<"$50         $200          $500           $0          $1,000          $0           $500          $200           $50   "<<endl;
  cout<<endl;

  // return void/None when the board is displayed and go back to menu
  return;
}

// Resetting board, removing the path created by the puck
void resetBoard(char plinkoBoard[12][17], int rows, int columns){

  // Fill board with "|" at even sums of i and j in nested for loop                                                                 
  // This essentially alternates the "|" in both rows and columns so they are                                                        
  // Never touching   
  for (int i = 0; i<rows; i++){
    for (int j = 0; j<columns; j++){
      if (((i+1+j+1)%2) == 0){
	plinkoBoard[i][j] = '|';}
      else{
	plinkoBoard[i][j] = ' ';}
      }
  }
  // Return void when board is reset
  // Used to initially fill the board on initial run
  // Also used before playPlinko is called to reset the board before use
  return;
}

// Where the puck is randomly given a path down the board on a given start
// e.i. where the game is actually played
int playPlinko(char plinkoBoard[12][17], int rows, int columns){

  int curColumn = -9999;
  int curRow = 0;
  int directionToMove;
  int winnings[9] = {50,200,500,0,1000,0,500,200,50};

  // while loop to reprompt player if the input is not an int or between 1-9
  while ((curColumn < 1) || (curColumn > 9)) {
    cout<<"\nWhich slot do you want to drop your puck down (1-9)?: ";
    if (!(cin >> curColumn)){
      cout<<"Invalid Input. Please try again.";
      cin.clear();
      cin.ignore(10000,'\n');
    }
    else if ((curColumn < 1) || (curColumn > 9)) { 
      cout<<"Invalid Input. Please try again.";
    }
  }

  // Convert the final column on the board once the puck has traveled all the way down to a number between 1-9 corresponding to the final bins
  // We want the input to index into the plinkoBoard 2D array so we multiply the input by two then subtract two. This makes sense because every other column
  // in the first row of the plinkoBoard is a slot hence multiplying by 2. We subtract two just to line up the values so the indexing makes sense into the array.
  curColumn = (curColumn*2)-2;
  for (int i=0; i<rows; i++){
    directionToMove = puckDirection(i, curColumn);
    curColumn += directionToMove;
    plinkoBoard[i][curColumn] = '*';
    }

  // Convert the final column on the board once the puck has traveled all the way down to a number between 1-9 corresponding to the final bins  
  // We can do this by undoing the operation at the top of this function
  // This is done by adding 2, dividing by 2, then subtracting 1 because we are indexing into an array
  cout<<"You have won $"<<winnings[((curColumn+2)/2)-1]<<"!\n"<<endl;

  // return the amount won by the player to be added to totalWinnings in runGame
  return winnings[((curColumn+2)/2)-1];
}

// Function that calls elements of the game based on user inputs
void runGame(void){

  int winnings = 0;
  int currentRoundWinnings = 0;
  int chips = 1;
  char userInput;
  int chipsWon;
  char plinkoBoard[12][17];
  bool played = false;

  // Build board in resetBoard
  resetBoard(plinkoBoard,12,17);
  
  // Seed the random number generator using the current time
  srand((unsigned)time(NULL));  
  cout<<"Welcome to the CPSC 1070 Plinko!!!\n"<<endl;

  // Do while loop with switch statement to keep player in game until q input is recieved
  do{
  userInput = runMenu(chips,winnings);

  //Switch statement running different functions depending on user input
  switch (userInput){
    //Bid on prizes
  case '1':
    // check if the player has already bid on prizes
    // if not let bid then add winnings to chips varaible, otherwise back to menu
    if (played == false){
      chipsWon = bidOnPrizes();
      cout<<endl;
      cout<<"You have won "<<chipsWon<<" chips!\n"<<endl;
      chips += chipsWon;
      played = true;
      break;
    }
    else{
      cout<<endl;
      cout<<"You've already bid on prizes!\n"<<endl;
      break;
    }
    //Play plinko
    // If enough chips, subtract chip for playing, reset board, call playPlinko function, and add winnings to total winnings
    // Otherwise back to menu
  case '2':
    if (chips > 0){
      chips -= 1;
      resetBoard(plinkoBoard, 12, 17);
      currentRoundWinnings = playPlinko(plinkoBoard, 12, 17);
      winnings += currentRoundWinnings;
      }
    else {
      cout<<"\nSorry, you don't have any more chips!\n"<<endl;
    }
    break;
    // display Board
  case '3':
    displayBoard(plinkoBoard, 12, 17);
    break;
  case 'q':
    // Quit game
    cout<<endl;
    break; 
  }}
  while (userInput != 'q' && userInput != 'Q');
  
  return;
}

int main(){
  runGame();
  return 0;
}
