#include "game.hpp"
#include <iostream>
#include <cstdlib>
#include <cctype>
#include <random>
using namespace std;

Game::Game()
{
    isFinished = false;
    init();
    unorder();
}

void Game::init()
{
    int number = 1;

    for (size_t i = 0; i < 4; i++)
    {
        for (size_t j = 0; j < 4; j++)
        {
            board[i][j] = number;
            //board.at(i).at(j) = number;
            number++;
        }
    }

    board[3][3] = EMPTY;
}

void Game::unorder()
{
    for (size_t i = 0; i < 1000; i++)
    {
        random_device rd;
        mt19937 generator(rd());

        int randNumber = generator() % 4;

        if      (randNumber == 0) {command = 'w';}
        else if (randNumber == 1) {command = 's';}
        else if (randNumber == 2) {command = 'a';}
        else if (randNumber == 3) {command = 'd';}
        
        logic();
    }
    
}

int Game::play()
{
    while (!isWin())
    {
        print();
        input();
        logic();
    }
    
    print();
    cout << "\n You Win!\n" << endl;
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
    cin >> command;
    command = tolower(command);
}

void Game::logic()
{
    Position empty = findEmpty();

    if(command == 's' && empty.x != 0)
    {
        swap(board[empty.x][empty.y], board[empty.x - 1][empty.y]);
    }
    else if(command == 'w' && empty.x != 3)
    {
        swap(board[empty.x][empty.y], board[empty.x + 1][empty.y]);
    }
    else if(command == 'a' && empty.y != 3)
    {
        swap(board[empty.x][empty.y], board[empty.x][empty.y + 1]);
    }
    else if(command == 'd' && empty.y != 0)
    {
        swap(board[empty.x][empty.y], board[empty.x][empty.y - 1]);
    }
    else if(command == 'q' || command == 'e')
    {
        exit(0);
    }
}

Game::Position Game::findEmpty()
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