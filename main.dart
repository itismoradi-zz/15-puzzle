//15 puzzle console game
import 'dart:io';

bool gameOver = false;
List board = [ 
    [ 1,  2,  3,  4],
    [ 5,  6,  7,  8],
    [ 9, 10, 11, 12],
    [13, 14, 15, 16]
];

main(){
    setup();
    
    while (gameOver == false) {
        display();
        input();
        logic();
    }
}

// only call in start of game
void setup(){
    print('===== 15 puzzle =====');
}

void display(){
    print('---------------------'); 

    for (var i = 0; i < 4; i++){
        //print a cell wall
        stdout.write('| ');
        //print 4 cells in any row
        for (var j = 0; j < 4; j++) {
            if(board[i][j] < 10){
                stdout.write(' ');
            }
            stdout.write(board[i][j]);
            stdout.write(' | ');
        }

        print('\n---------------------');
    }
}

void input(){
    
}


void logic(){
    gameOver = true;
}