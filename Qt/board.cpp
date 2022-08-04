#include "board.hpp"
#include <iostream>

Board::Board()
{
    setupCells();
}

Cell &Board::operator ()(usInt x, usInt y)
{
    return cells.at(y).at(x);
}

Cell &Board::operator ~()
{
    for(auto & row : cells)
    {
        for(auto & cell : row)
        {
            if(cell.value == EMPTY)
            {
                return cell;
            }
        }
    }
}

void Board::swapCells(usInt x1, usInt y1, usInt x2, usInt y2)
{
    usInt temp;
    temp = cells.at(y1).at(x1).value;
    cells.at(y1).at(x1).value = cells.at(y2).at(x2).value;
    cells.at(y2).at(x2).value = temp;
}

void Board::setupCells()
{
    unsigned int rowNumber = 0;
    unsigned int cellNumber = 1;

    for(auto & row : cells)
    {
        unsigned int columnNumber = 0;

        for(auto & cell : row)
        {
            cell.value = cellNumber;
            cell.y = rowNumber;
            cell.x = columnNumber;

            std::cout << cell.value << "(" << cell.x << " , " << cell.y << ")" << "\t";
            cellNumber++;
            columnNumber++;
        }

        rowNumber++;
        std::cout << std::endl;
    }
}
