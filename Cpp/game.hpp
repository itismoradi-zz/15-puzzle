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
        struct Position{int x; int y;};

        void initBoard();
        void print();
        void input();
        void logic();
        bool validate();
        Position operator ~();
        void operator()(int, int, int, int);
        bool isWin();
        void move(char, Position);
};

#endif