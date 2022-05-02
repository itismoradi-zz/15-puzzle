//15 puzzle console game
import 'dart:io';

bool gameOver = false;

class Board{
    List table = [ 
        [ 1,  2,  3,  4],
        [ 5,  6,  7,  8],
        [ 9, 10, 11, 12],
        [13, 14, 15, 16]
    ];

    Command command = Command.UP;
}

enum Command {
    UP,
    DOWN,
    RIGHT,
    LEFT
}

main(){
    setup();
    Board board = new Board();

    while (gameOver == false) {
        display(board);
        board.command = input();
        logic(board);
    }
}

// only call in start of game
void setup(){
    print('===== 15 puzzle =====');
}

void display(Board board){
    print('---------------------'); 

    for (var i = 0; i < 4; i++){
        //print a cell wall
        stdout.write('| ');
        //print 4 cells in any row
        for (var j = 0; j < 4; j++) {
            if(board.table[i][j] < 10){
                stdout.write(' ');
            }
            stdout.write(board.table[i][j]);
            stdout.write(' | ');
        }

        print('\n---------------------');
    }
}

Command input(){
    String? key = stdin.readLineSync();
    Command command = Command.UP;

    if(key == 'w' || key == 'W'){
        command = Command.UP;
    }
    else if(key == 's' || key == 'S'){
        command = Command.DOWN;
    }
    else if(key == 'd' || key == 'D'){
        command = Command.RIGHT;
    }
    else if(key == 'a' || key == 'A'){
        command = Command.LEFT;
    }

    return command;
}

void logic(Board board){
    gameOver = true;
}