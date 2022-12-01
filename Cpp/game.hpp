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
        std::array<std::array<int, 4>, 4> board;
        struct Position{int x; int y;};

        void init();
        void unorder();
        void print();
        void input();
        void logic();
        Position operator ~();
        void operator()(int, int, int, int);
        bool isWin();
};

#endif