#include "board.h"

//Default constructor gives random board
Board::Board(){
    result = getRandomLetters();
    fillBoard();
}

//Parameterized constructor gives predetermined board.
//If an incorrect amount of charcters are given for the board 
// then the board will read...
//  O O O O
//  O O O O
//  O O O O
//  O O O O 
//  We will display an error message and prompt user to reenter.
Board::Board(string _userInput){
    if(_userInput.length() == 16){
        result = _userInput;
        fillBoard();
    }
    else{
        result = "OOOOOOOOOOOOOOOO";
        std::cout << std::endl;
        std::cout << "          **Error** Must enter 16 characters." << std::endl;
    }

}

//Generates a random number for use by function 'getRandomLetters'.
//Used specifically to generate random index for cube array.
int Board::getRandom() {
    std::random_device os_seed;
    const u32 seed = os_seed();
    engine generator( seed );
    std::uniform_int_distribution< u32 > distribute( 0,5 );
    int num = distribute(generator);
    return num;
} 

//Generates a random board by shuffling the 'CUBE' array and using a random index.
string Board::getRandomLetters() {
    string _result = "";
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    shuffle(CUBE_ARRAY.begin(), CUBE_ARRAY.end(), std::default_random_engine(seed));
    for (int i = 0; i < NUM_CUBES + 1; i++){
        _result.push_back(CUBE_ARRAY[i][getRandom()]);
    }
    return _result;
}

//It... displays the board.
void Board::displayBoard() {
    int counter = 0;
    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 4; j++){
            std::cout << " " << result[counter] << " ";
            counter++;  
        }
        std::cout <<  std::endl;
    }
}

//Puts the string into an array for computer and human search. 
void Board::fillBoard(){
    int counter = 0;
    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 4; j++){
            boardArray[i][j] = result[counter];
            counter++;  
        }
    }
}

bool Board::inBounds(int row,int col){

    if((row <= 0 || row >= 4) || (col <= 0 || col >= 4)){

        return false;
    }else{
       return true;
    }
}












