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
        bool isValid;

        void print();
        void input();
        void logic();
        bool validate();
};

#endif