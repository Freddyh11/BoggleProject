//Boggle Project CST136
//

#include "board.h"
  
int main( void ) {
  cout << "Welcome to boggle!" << endl;
  cout << "Press enter to continue..." << endl;
  while ( getchar() != '\n');



  string myfile = "Dictionary.txt";
  Board board1(myfile, "");
  board1.displayBoard();
  board1.SolveBoard();
  int x = board1.getComputerScore();
  cout << "Computer score is: ";
  cout << x << endl;
   if (board1.getComputerScore() > board1.getHumanScore()) {
        cout << "Ha ha ha, I destroyed you. Better luck next time! \n";
    } else {
        cout << "WOW, you defeated me! Congratulations your Good!\n";
    }
  
  return 0;
}

