#ifndef Boggle_hpp
#define Boggle_hpp

#include <stdio.h>
#include <iostream>
#include <string>
#include "Lexicon.h"

using namespace std;


class Boggle
{
private:
    
    int HumanScore;
    int ComputerScore;
    
    
public:
    Boggle(fstream lexicon, string boardText);
    char b_getLetter(int row, int col)const;
    bool b_checkWord(string word);
    bool b_humanWordSearch(string word);
    string* b_computerWordSearch();
    int b_getScoreHuman()const;
    int b_getScoreComputer();
    ostream& operator<<(ostream& stream);
    
    
};

#endif /* Boggle_hpp */
