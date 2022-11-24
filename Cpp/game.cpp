#include "game.hpp"
#include <iostream>
#include <cstdlib>
using namespace std;

Game::Game()
{
    isFinished = false;
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
    char command;
    cin >> command;

    system("cls || clear");
}

void Game::logic()
{

}