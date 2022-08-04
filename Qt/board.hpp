#ifndef BOARD_HPP
#define BOARD_HPP

#include <array>
typedef unsigned short int usInt;
#define EMPTY 16

struct Cell
{
    usInt value;
    usInt x;
    usInt y;
};

class Board
{
public:
    Board();
    Cell & operator ()(usInt, usInt);   //returns cell by position
    Cell & operator ~();                //returns the empty cell
    void swapCells(usInt, usInt, usInt, usInt);
private:
    std::array<std::array<Cell, 4>, 4> cells;
    void setupCells();
};

#endif // BOARD_HPP
