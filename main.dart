//15 puzzle console game
bool GameOver = false;
List<int> board = [  1,  2,  3,  4,
                     5,  6,  7,  8,
                     9, 10, 11, 12,
                    13, 14, 15, 16
];
main(){
    setup();
    
    while (GameOver != true) {
        display();
        input();
        logic();
    }
}

/// only call in start of game
void setup(){
    print("#==== 15 puzzle ====#");
}

void display(){
    print("---------------------");   
    print("| ");
    print("---------------------");    
    print("| ");
    print("---------------------");    
    print("| ");
    print("---------------------");    
    print("| ");
    print("---------------------");
}

void input(){

}


void logic(){
    GameOver = true;
}