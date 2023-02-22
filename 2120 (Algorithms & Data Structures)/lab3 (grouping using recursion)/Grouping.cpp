/*
 * Name: Noah Nisbet
 * Date Submitted: Feb 12, 2022
 * Lab Section: 004
 * Assignment Name: Finding Groups Using Recursion
 */

#include "Grouping.h"

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

//Implement the (parameterized) constructor and findGroup functions below

/*
 * Grouping constructor
 * Opens the file and finds the groups using recursion
 */
Grouping::Grouping(string filename)
{
  // create fstream object
  fstream file;
  // open fil;e using filename
  file.open(filename, ios::in);

  // loop over the lines in the file
  for (int i=0; i<10; i++){
    string curline;
    getline(file, curline);
    // loop of the characters in the current line
    for (int j=0; j<10; j++)
      {
	// if the character is a period assign the grid at the current position to 0
	if (int(curline[j]) == 46)
	  grid[i][j] = 0;
	else
	  // otherwise assign the current position to 1
	  grid[i][j] = 1;
      }
  }

  // loop over all the cells in grid and use th findGroup function
  for (int i=0; i<10; i++){
    for (int j=0; j<10; j++){
      // create a vector of GridSquares to pass into findGroup by reference
      vector<GridSquare> curGroup;
      findGroup(i,j, curGroup);
      // GridSquares have been added to curGroup push it to groups
      if (curGroup.size() != 0)
	groups.push_back(curGroup);
    }
  }
}

/*
 * findGroup function that uses recursion to find groups
 * Takes the current position in the grid and a vector of GridSquares by reference
 */
void Grouping::findGroup(int r, int c, vector<GridSquare> &curGroup)
{
  // Create a GridSquare object using r and c
  GridSquare curSquare(r,c);

  // base case
  // if the value in grid at the current position is 0 return
  if (grid[r][c] == 0)
    return;

  // otherwise set the current position in grid to 0 and push curSquare to curGroup
  grid[r][c] = 0;
  curGroup.push_back(curSquare);

  // recursively add to curSquare by calling findGroup on every position around r and c
  // need the if statements to make sure I only call findGroup on valid grid positions
  if ((r == 0) and (c == 0))
    {
      findGroup(r+1,c,curGroup);
      findGroup(r,c+1,curGroup);
    }
  else if((r == 9) and (c == 9))
    {
      findGroup(r-1,c,curGroup);
      findGroup(r,c-1,curGroup);
    }
  else if((r == 9) and (c == 0))
    {
      findGroup(r-1,c,curGroup);
      findGroup(r,c+1,curGroup);
    }
  else if((r == 0) and (c == 9))
    {
      findGroup(r+1,c,curGroup);
      findGroup(r,c-1,curGroup);
    }
  else if (r == 0)
    {
      findGroup(r+1,c,curGroup);
      findGroup(r,c+1,curGroup);
      findGroup(r,c-1,curGroup);
    }
  else if (r == 9)
    {
      findGroup(r-1,c,curGroup);
      findGroup(r,c+1,curGroup);
      findGroup(r,c-1,curGroup);
    }
  else if (c == 0)
    {
      findGroup(r+1,c,curGroup);
      findGroup(r-1,c,curGroup);
      findGroup(r,c+1,curGroup);
    }
  else if (c == 9)
    {
      findGroup(r+1,c,curGroup);
      findGroup(r-1,c,curGroup);
      findGroup(r,c-1,curGroup);
    }
  else
    {
      findGroup(r+1,c,curGroup);
      findGroup(r-1,c,curGroup);
      findGroup(r,c+1,curGroup);
      findGroup(r,c-1,curGroup);
    }
}



//Simple main function to test Grouping
//Be sure to comment out main() before submitting
/*
int main()
{
    Grouping input1("input1.txt");
    input1.printGroups();
    
    return 0;
}
*/

//Do not modify anything below

GridSquare::GridSquare() : row(0), col(0) {} //Default constructor, (0,0) square

GridSquare::GridSquare(int r, int c) : row(r), col(c) {} //(r,c) square

//Compare with == operator, used in test cases
bool GridSquare::operator== (const GridSquare r) const
{
    if ((row == r.row) && (col == r.col))
    {
        return true;
    }
    return false;
}

int GridSquare::getRow() //return row value
{
    return row;
}

int GridSquare::getCol() //return column value
{
    return col;
}

//Output using << operator, used in Grouping::printGroups()
//Function definition for <ostream> << <GridSquare>
ostream& operator<< (ostream& os, const GridSquare obj)
{
    os << "(" << obj.row << "," << obj.col << ")";
    return os;
}

Grouping::Grouping() : grid{},groups() {} //Default constructor, no groups

void Grouping::printGroups() //Displays grid's groups of squares
{
    for(int g=0; g<groups.size(); g++)
    {
        cout << "Group " << g+1 << ": ";
        for(int s=0; s<groups[g].size(); s++)
        {
            cout << " " << groups[g][s];
        }
        cout << endl;
    }
}

vector<vector<GridSquare>> Grouping::getGroups() //Needed in unit tests
{
    return groups;
}
