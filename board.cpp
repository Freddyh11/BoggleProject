#include "board.h"

//Default constructor gives random board
Board::Board(){
    result = getRandomLetters(); 
    fillBoard();
    ifstream input("Dictionary.txt");
    string word;
    
    if(!input) {
        cout << "Error reading file" << endl;
        return;
    }
    
    while(input >> word) {
       dict.addWord(word);
    }

    input.close();

}

//Parameterized constructor gives predetermined board.
//If an incorrect amount of charcters are given for the board 
// then the board will default to a random setup.
Board::Board(string& myfile, string _userInput){
    if(_userInput.length() == 16){
        result = _userInput;
        transform(result.begin(), result.end(), result.begin(), ::tolower);
        fillBoard();
    }
    else{
        cout << "You entered the incorrect number of terms. Here is a random board." << endl;
        cout << "End the game early and try again... Or see if you can win! :) " << endl;
        result = getRandomLetters();
        fillBoard();
    }
    ifstream input(myfile);
    string word;
    
    if(!input) {
        cout << "Error reading file" << endl;
        return;
    }
    
    while(input >> word) {
       dict.addWord(word);
    }

    input.close();
}

//Copy constructor
Board::Board(const Board& copy) {
    result = copy.result;
    humanScore = copy.humanScore;
    computerScore = copy.computerScore;
    dict = copy.dict;
    wordsFound = copy.wordsFound;
    computerList = copy.computerList;
    humanList = copy.humanList;
}

//Move constructor
Board::Board(Board&& move) noexcept {
    *this = move;
}

//Copy assignment operator
Board& Board::operator=(const Board& copy) { // Copy = operator
    result = copy.result;
    humanScore = copy.humanScore;
    computerScore = copy.computerScore;
    dict = copy.dict;
    wordsFound = copy.wordsFound;
    computerList = copy.computerList;
    humanList = copy.humanList;
    return *this;
}

//Move assignment operator
 Board& Board::operator=(Board&& move) noexcept { // Move = operator
    *this = move;
    return *this;
}

//Deconstructor
Board::~Board() {
    dict.deleteNodes(dict.root);
    wordsFound.deleteNodes(wordsFound.root);
    dict.root = NULL;
    dict.currNode = NULL;
    wordsFound.currNode = NULL;
    wordsFound.root = NULL;
}

//Generates a random number for use by function 'getRandomLetters'.
//Used specifically to generate random index for cube array.
int Board::getRandomIndex() {
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
    for (int i = 0; i < NUM_CUBES; i++){
        _result.push_back(CUBE_ARRAY[i][getRandomIndex()]);
    }
    return _result;
}

//It... displays the board.
void Board::displayBoard() {
    string temp = result;
    transform(temp.begin(), temp.end(), temp.begin(), ::toupper);
    int counter = 0;
    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 4; j++){
            std::cout << " " << temp[counter] << " ";
            counter++;  
        }
        std::cout <<  std::endl;
    }
}

//Puts the randomly generated string or the user provided string in an 
//array which allows for printing the board to the console, solving the board, 
//and validation of words. 
void Board::fillBoard(){
    int counter = 0;
    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 4; j++){
            boardArray[i][j] = result[counter];
            counter++;  
        }
    }
}

//Begins recursive call to find all words from the lexicon that are on the board.
void Board::solveBoard() {
    string currPrefix;
    for (int row = 0; row < 4; row++) {
        for (int col = 0; col < 4; col++) {
            searchForWord(row, col, currPrefix);
        }
    }
}

//searches the word in dict
void Board::searchForWord(int row, int col, string currPrefix)
{
    if(row >= 4 || col >= 4)
        return;
    
    if(row < 0 || col < 0)
        return;
    
    if(checkedArray[row][col] != false)
        return;
    
    if(!dict.isPrefix(currPrefix))
        return;
    
    if(dict.isWord(currPrefix)) {
        if(!wordsFound.isWord(currPrefix)) {
            wordsFound.addWord(currPrefix);
            computerList.push_back(currPrefix);
        }
    }
    
    currPrefix = currPrefix + boardArray[row][col];
    checkedArray[row][col] = true;
    
    searchForWord(row , col - 1, currPrefix);
    searchForWord(row , col + 1, currPrefix);
    searchForWord(row - 1 , col, currPrefix);
    searchForWord(row + 1 , col, currPrefix);
    searchForWord(row + 1 , col + 1, currPrefix);
    searchForWord(row + 1 , col - 1, currPrefix);
    searchForWord(row - 1 , col + 1, currPrefix);
    searchForWord(row - 1 , col - 1, currPrefix);

    checkedArray[row][col] = false;
}
//prints the array of words
void Board::printArrays(){
    cout << "***Your word list***" << endl;
    int total_hum = humanList.size();

    for (int i = 0; i < total_hum; i++){
        cout << humanList[i] << endl;
    }

    cout << "Press enter to continue..." << endl;
    while ( getchar() != '\n');

    cout << "\n\n" << endl;

    cout << "***Computer found words***" << endl;
    int total_comp = computerList.size();
    for (int i = 0; i < total_comp; i++){
        cout << computerList[i] << endl;
    }
}
//getter for human score
int Board::getHumanScore() {
    humanScore = 0;
    for (int i = 0; i < humanList.size(); i++) {
        humanScore += score(humanList[i].length());
    }
    return humanScore;
}
//getter for comp score
int Board::getComputerScore() {
    computerScore = 0;
    for (int i = 0; i < computerList.size(); i++) {
        computerScore += score(computerList[i].length());
    }
    return computerScore;
}
//point system for words
int Board::score(int word_length){
    if (word_length < 4) { return 0;}
    else if (word_length == 4) { return 1;}
    else if (word_length == 5) { return 2;}
    else if (word_length == 6) { return 3;}
    else if (word_length == 7) { return 4;}
    else if (word_length == 8) { return 5;}
    else if (word_length == 9) { return 6;}
    else if (word_length == 10) { return 7;}
    else if (word_length == 11) { return 8;}
    else { return 9;}
}

//Function checks whether a word is a valid word on the Boggle board
//Return Type:bool
bool Board::checkValidWord(string _word) {
    bool success = false;
    for (int i = 0; i < computerList.size(); i++) {
        if (_word == computerList[i])
            success = true;
        for (int j = 0; j < humanList.size(); j++) {
            if (_word == humanList[j]) {
                success = false;
            }
        }
    }
    return success;
}
 // clears buffer after menu choice so as not to interfere with the following user inputs.
void Board::clearBuffer() {
   
	char c;
	do {
		c = getchar();
	} while (c != '\n' && c != EOF);
}


