let squares = [];
let blank = 15;
for (let index = 1; index <= 16; index++) {
    squares.push(index);
}
squares[15] = "";

function setBoard() {
    for (let i = 0; i < 16; i++) {
        document.getElementsByClassName("square")[i].innerHTML = squares[i];
    }
}
function checkBoard() {
    let flag = true;
    for (let i = 0; i < 15; i++) {
        if (document.getElementsByClassName("square")[i].innerHTML != i + 1) {
            flag = false;
        }
    }
    if (flag == true) {

        console.log("you won");
    }
    else {
        console.log("game is not over");
    }
}
setBoard();
function Left() {
    if (blank % 4 != 3) {
        squares[blank] = squares[blank + 1];
        squares[blank + 1] = "";
        blank++;
    }
}
function Right() {
    if (blank % 4 != 0) {
        squares[blank] = squares[blank - 1];
        squares[blank - 1] = "";
        blank--;
    }
}
function Up() {
    if (blank != 12 && blank != 13 && blank != 14 && blank != 15) {
        squares[blank] = squares[blank + 4];
        squares[blank + 4] = "";
        blank = blank + 4;
    }
}
function Down() {
    if (blank != 0 && blank != 1 && blank != 2 && blank != 3) {
        squares[blank] = squares[blank - 4];
        squares[blank - 4] = "";
        blank = blank - 4;
    }
}
document.addEventListener('keydown', function (event) {
    if (event.keyCode == 37) {
        Left();
    }
    else if (event.keyCode == 38) {
        Up();
    }
    else if (event.keyCode == 39) {
        Right();
    }
    else if (event.keyCode == 40) {
        Down();
    }
    setBoard();
    checkBoard();
});
