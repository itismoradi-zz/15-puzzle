#include "game.hpp"
#include <iostream>
#include <cstdlib>
using namespace std;

Game::Game()
{
    isFinished = false;
    isValid = false;

    cout << "===== 15 puzzle =====" << endl;
    cout << "|  1 |  2 |  3 |  4 |" << endl;
    cout << "---------------------" << endl;
    cout << "|  5 |  6 |  7 |  8 |" << endl;
    cout << "---------------------" << endl;
    cout << "|  9 | 10 | 11 | 12 |" << endl;
    cout << "---------------------" << endl;
    cout << "| 13 | 14 | 15 |    |" << endl;
    cout << "---------------------\n" << endl;

    cout << "(O) " << "Enter a character to play : ";
    cin >> command; 
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
    cout << "---------------------" << endl;



    cout << "---------------------" << endl;
}

void Game::input()
{
    while(!isValid)
    {
        cin >> command;

        if(validate()) 
        {
            isValid = true;
            return;
        }

        cout << "(O) " << "Wrong command!" << endl; 
    }  
}

void Game::logic()
{
    cout << "logic is working..." << endl;
    isValid = false;
}

bool Game::validate()
{
    if(command == 'q' || command == 'Q' || command == 'e' || command == 'E' || cin.eof())
    {
        isFinished = true;
    }
    else if (command == 'w' || command == 'W' || command == 's' || command == 'S' ||
             command == 'a' || command == 'A' || command == 'd' || command == 'D')
    {
        return true;
    }
    else
    {
        return false; 
    }
}