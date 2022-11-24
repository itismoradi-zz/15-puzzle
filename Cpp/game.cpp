#include "game.hpp"
#include <iostream>
#include <cstdlib>
#include <cctype>
using namespace std;

Game::Game()
{
    isFinished = false;
    isValid = false;
    initBoard();

    print();

    cout << "Game keys : W, S, A, D" << endl;
    cout << ">> " << "Enter a character to play : ";
    cin >> command; 
}

void Game::initBoard()
{
    int number = 1;

    for (size_t i = 0; i < 4; i++)      // Row traversal 
    {
        for (size_t j = 0; j < 4; j++)      // Column traversal
        {
            board.at(i).at(j) = number;
            number++;
        }
    }
    
    board.at(3).at(3) = EMPTY;
}

int Game::play()
{
    while(!isFinished)
    {
        print();
        input();
        logic();
    }

    return 0;
}

void Game::print()
{
    system("cls || clear");

    cout << " ===== 15 puzzle =====" << endl;

    for (size_t i = 0; i < 4; i++)      // Row traversal 
    {        
        for (size_t j = 0; j < 4; j++)      // Column traversal
        {
            cout << " | ";
            int number = board.at(i).at(j);

            if(number == EMPTY)
            {
                cout << "  ";
            }
            else 
            {
                if(number < 10)
                {
                    cout << " ";
                } 
                
                cout << number;
            }

        }

        cout << " |" << endl;
        cout << " ---------------------" << endl;
    }
}

void Game::input()
{
    while(!isValid)
    {
        cin >> command;
        command = tolower(command);

        if(validate()) 
        {
            isValid = true;
            return;
        }

        cout << ">> " << "Wrong command!" << endl; 
    }  
}

void Game::logic()
{
    Position empty = ~*this;

    switch (command)
    {
        case 'w':
        {
            if(empty.x != 3)
                (*this)(empty.x, empty.y, empty.x + 1, empty.y);

            break;
        }
        case 's':
        {
            if(empty.x != 0)
                (*this)(empty.x, empty.y, empty.x - 1, empty.y);

            break;
        }
        case 'd':
        {
            if(empty.y != 0)
                (*this)(empty.x, empty.y, empty.x, empty.y - 1);

            break;
        }
        case 'a':
        {
            if(empty.y != 3)
                (*this)(empty.x, empty.y, empty.x, empty.y + 1);

            break;
        }  
    }
   
    isValid = false;
    isFinished = isWin();
}

bool Game::validate()
{
    if(command == 'q' || command == 'e' || cin.eof())
    {
        isValid = true;
        isFinished = true;
        return true;
    }
    else if (command == 'w' || command == 's' || command == 'a' || command == 'd')
    {
        return true;
    }

    return false;
}

Game::Position Game::operator ~()
{
    Position empty;

    for (size_t i = 0; i < 4; i++)      // Row traversal 
    {
        for (size_t j = 0; j < 4; j++)      // Column traversal
        {
            if(board.at(i).at(j) == EMPTY)
            {
                empty.x = i;
                empty.y = j;
                return empty;
            }
        }
    }

    return empty;
}      

void Game::operator()(int x1, int y1, int x2, int y2)
{
    swap(board[x1][y1], board[x2][y2]);
}

bool Game::isWin()
{
    int number = 1;

    for (size_t i = 0; i < 4; i++)      // Row traversal 
    {
        for (size_t j = 0; j < 4; j++)      // Column traversal
        {
            if(i == 3 && j == 3)
            {
                number = EMPTY;
            }
            if(board.at(i).at(j) != number)
            {
                return false;
            }

            number++;
        }
    }

    return true;
}