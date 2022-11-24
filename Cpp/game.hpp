#ifndef GAME_IG
#define GAME_IG

class Game
{
    public:
        Game();
        int play();
    private:
        bool isFinished;
        char command;

        void print();
        void input();
        void logic();
};

#endif