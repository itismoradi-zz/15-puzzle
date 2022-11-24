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

            if(number == 0)
            {
                cout << "  ";
                break;
            }
            else if(number < 10)
            {
                cout << " ";
            } 
            
            cout << number;
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
    cout << "logic is working..." << endl;
    isValid = false;
}

bool Game::validate()
{
    if(command == 'q' || command == 'e' || cin.eof())
    {
        isFinished = true;
    }
    else if (command == 'w' || command == 's' || command == 'a' || command == 'd')
    {
        return true;
    }
    else
    {
        return false; 
    }
}