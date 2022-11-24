#include "game.hpp"
#include <iostream>
#include <cstdlib>
using namespace std;

Game::Game()
{
    isFinished = false;

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
    system("cls || clear");
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
    cout << "---------------------" << endl;



    cout << "---------------------" << endl;
}

void Game::input()
{
    cin >> command;

    system("cls || clear");
}

void Game::logic()
{

}