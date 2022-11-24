#ifndef GAME_IG
#define GAME_IG

#include <array>
#define EMPTY 0

class Game
{
    public:
        Game();
        int play();
    private:
        bool isFinished;
        char command;
        bool isValid;
        std::array<std::array<int, 4>, 4> board;

        void initBoard();
        void print();
        void input();
        void logic();
        bool validate();
};

#endif