#ifndef BOARD_H
#define BOARD_H
#include "dice.h"
#include <iostream> 
#include <chrono>
#include <cctype> 
#include <random>  
#include <string>
#include <algorithm>
#include <array>

using std::string;  
using u32 = uint_least32_t; 
using engine = std::mt19937;

class Board : public Dice{
    public:
    void displayBoard(string _result);  
    string getRandomLetters();
    int getRandom();
    bool inBounds(int row,int col);
};

#endif 
