#include "board.h"

//Default constructor gives random board
Board::Board(){
    result = getRandomLetters();
    fillBoard();
}

//Parameterized constructor gives predetermined board.
//If an incorrect amount of charcters are given for the board 
// then the board will default to a random setup.
Board::Board(string& myfile, string _userInput){
    if(_userInput.length() == 16){
        result = _userInput;
        fillBoard();
    }
    else{
        result = getRandomLetters();
    }
    ifstream input(myfile);
    string word;
    
    if(!input) {
        cout << "Error readiing file" << endl;
        return;
    }
    
    while(input >> word) {
        dict.addWord(word);
    }

    input.close();
}

//Generates a random number for use by function 'getRandomLetters'.
//Used specifically to generate random index for cube array.
int Board::getRandom() {
    std::random_device os_seed;
    const uint_least32_t seed = os_seed();
    std::mt19937 generator( seed );
    std::uniform_int_distribution< uint_least32_t > distribute( 0,5 );
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


bool inBounds(int row,int col){

    if((row <= 0 || row >= 4) || (col <= 0 || col >= 4)){

        return false;
    }else{
       return true;
    }
}











