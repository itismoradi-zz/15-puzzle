//15 puzzle console game
import 'dart:io';
import 'dart:math';
//import 'package:win32/win32.dart';

const bool testMode = false;

class Board{
    List table = [
        [ 1,  2,  3,  4],
        [ 5,  6,  7,  8],
        [ 9, 10, 11, 12],
        [13, 14, 15, 16]
    ];

    bool isRepeated(int number){
        for (int i = 0; i < 4; i++) {   //row traversal
            for (int j = 0; j < 4; j++) {   //column traversal
                if(table[i][j] == number){
                    return true;
                }
            }
        }

        return false;
    }

    Map <int, int> emptyCellPosition(){
        Map <int, int> position = {};
        int i, j;

        for (i = 0; i < 4; i++) {   //row traversal
            for (j = 0; j < 4; j++) {   //column traversal
                if(table[i][j] == 16)
                {
                    position[i] = j;
                }
            }
        }

        return position;
    }

    void swapCells(int x1, int? y1, int x2, int? y2){
        int temp;
        temp = table[x1][y1];
        table[x1][y1] = table[x2][y2];
        table[x2][y2] = temp;
    }

    bool isWin(){
        for (int i = 0; i < 4; i++) {   //row traversal
            for (int j = 0; j < 4; j++) {   //column traversal
                int index = ((i) * 4) + j + 1;
                if(table[i][j] != index)
                {
                    return false;
                }
            }
        }

        return true;
    }
}

enum Command {
    UP,
    DOWN,
    RIGHT,
    LEFT,
    STOP
}

Command command = Command.STOP;

main(){
    Board board = new Board();
    setup(board);

    while (board.isWin() == false) {
        display(board);
        command = input();
        logic(board);
    }

    display(board);
    print("Game Finished!");
}

// only call in start of game
void setup(Board board){
    print('===== 15 puzzle =====');

    // Generate rendom order of cells numbers
    var randomEngine = Random();
    int randomNumber;  // Generated random number

    const int iterationsCount = testMode ? 1 : 100;

    for (int i = 0; i < iterationsCount; i++) {   //row traversal
       randomNumber =  randomEngine.nextInt(4);
       command = intToCommand(randomNumber);
       logic(board);
    }
}

Command intToCommand(int number) {
    switch (number) {
      case 0: return Command.UP;
      case 1: return Command.DOWN;
      case 2: return Command.RIGHT;
      case 3: return Command.LEFT;
      default:  return Command.STOP;
    }
}

void display(Board board){
    //clearScreen();
    print('---------------------'); 

    for (var i = 0; i < 4; i++){
        //print a cell wall
        stdout.write('| ');
        //print 4 cells in any row
        for (var j = 0; j < 4; j++) {
            int cellNumber = board.table[i][j];

            if(cellNumber == 16){   // Empty cell
                stdout.write('  '); 
            }
            else{
                if(cellNumber < 10){
                    stdout.write(' ');
            }

            stdout.write(cellNumber);
            }
            
            stdout.write(' | ');
        }

        print('\n---------------------');
    }
}

Command input(){
    String? key = stdin.readLineSync();
    Command command = Command.STOP;

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
    Map <int, int> position = board.emptyCellPosition();
    int? i = position.keys.first;
    int? j = position[i];

    if(command == Command.UP){
        if(i == 3)  return;
        board.swapCells(i, j, i+1, j);
    }
    else if(command == Command.DOWN){
        if(i == 0)  return;
        board.swapCells(i, j, i-1, j);
    }
    else if(command == Command.RIGHT){
        if(j == 0)  return;
        if (j != null) {
            board.swapCells(i, j, i, j.toInt() - 1);
        }
    }
    else if(command == Command.LEFT){
        if(j == 3)  return;
        if (j != null) {
            board.swapCells(i, j, i, j.toInt() + 1);
        }
    }
}

void clearScreen(){
    if(Platform.isWindows) {
        print(Process.runSync("cls", [], runInShell: true).stdout); 
    } else {
        print(Process.runSync("clear", [], runInShell: true).stdout);
    }
}