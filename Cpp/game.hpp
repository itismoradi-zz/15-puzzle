#ifndef GAME_IG
#define GAME_IG

class Game
{
    public:
        Game();
        int play();
    private:
        bool isFinished;

        void print();
        void input();
        void logic();
};

#endif