#include "board.h"

int Board::getRandom() {
    std::random_device os_seed;
    const u32 seed = os_seed();
    engine generator( seed );
    std::uniform_int_distribution< u32 > distribute( 0,5 );
    int num = distribute(generator);

    return num;
} 

string Board::getRandomLetters() {
    string result = "";
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    shuffle(CUBE_ARRAY.begin(), CUBE_ARRAY.end(), std::default_random_engine(seed));
    for (int i = 0; i < NUM_CUBES + 1; i++){
        std::cout << CUBE_ARRAY[i] << std::endl;
        result.push_back(CUBE_ARRAY[i][getRandom()]);
    }
    return result;
}

void Board::displayBoard(string _result) {
    int counter = 0;
    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 4; j++){
            std::cout << " " << _result[counter] << " ";
            counter++;  
        }
        std::cout <<  std::endl;
    }
}

bool Board::inBounds(int row,int col){

    if((row <= 0 || row >= 4) || (col <= 0 || col >= 4)){

        return false;
    }else{
       return true;
    }
}

