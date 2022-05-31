#ifndef BOARD_H
#define BOARD_H
#include <iostream> 
#include <fstream>  
#include <chrono>
#include <cctype> 
#include <random>  
#include <string>
#include <algorithm>
#include <array>
#include "dictionary.h"

using std::string;  
using u32 = uint_least32_t; 
using engine = std::mt19937;
    
static int const NUM_CUBES = 16;
static string const CUBE_ONE = "aaeegn";
static string const CUBE_TWO = "abbjoo";
static string const CUBE_THREE = "achops";
static string const CUBE_FOUR = "affkps";
static string const CUBE_FIVE = "aoottw";
static string const CUBE_SIX = "cimotu";
static string const CUBE_SEVEN = "deilrx";
static string const CUBE_EIGHT = "delrvy";
static string const CUBE_NINE = "distty";
static string const CUBE_TEN = "eeghnw";
static string const CUBE_ELEVEN = "eeinsu";
static string const CUBE_TWELVE = "ehrtvw";
static string const CUBE_THIRTEEN = "eiosst";
static string const CUBE_FOURTEEN = "elrtty";
static string const CUBE_FIFTEEN = "himnqu";
static string const CUBE_SIXTEEN = "hlnnrz";
      
 
class Board {
    public:
        string result;
        int humanScore;
        int computerScore;
        Dictionary dict;
        Dictionary wordsFound;
        vector<string> computerList;
        vector<string> humanList;

        char boardArray[4][4];
        bool checkedArray[4][4] = {{false, false, false, false}, {false, false, false, false}, {false, false, false, false}, {false, false, false, false}};
        std::array<string, 16> CUBE_ARRAY = {CUBE_ONE, CUBE_TWO, CUBE_THREE, 
                CUBE_FOUR, CUBE_FIVE, CUBE_SIX, CUBE_SEVEN, CUBE_EIGHT,
                CUBE_NINE, CUBE_TEN, CUBE_ELEVEN, CUBE_TWELVE, CUBE_THIRTEEN,
                CUBE_FOURTEEN, CUBE_FIFTEEN, CUBE_SIXTEEN};
 
        Board();//default
        Board(string& myfile, string _userInput);//parameterized
        Board(const Board& copy);//copy con
        Board(Board&& move) noexcept;//move con
        Board& operator=(const Board& copy);//copy op
        Board& operator=(Board&& move) noexcept;//move op

        ~Board();//decon

        void fillBoard();//fill the board with char
        void displayBoard();  //displays board
        bool checkValidWord(string _word);//checks to see if word is vaild T or F
        bool inBounds(int row,int col);//checks the bounds of row and col
        string getRandomLetters();//getter
        int getRandomIndex();//creates a random index in cube array

        int getHumanScore();//getter for human score
        void humanPlayersTurn();//lets human play

        int getComputerScore();//getter for comp score
        void solveBoard();//solves the entire board
        void searchForWord(int row, int col, string currPrefix);//searches for word in dict

        int score(int word_length);//gives point for word length
        int score();//point system for word
        void printArrays();//print array
        void clearBuffer();//clears the buffer after menu choice 
};

#endif 
