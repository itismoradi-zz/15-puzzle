squares = new Array(16);
let blank = 15;
let numberOfMoves = 0;
let win = false;
let game = false;
let numberOfCorrectSquares = 0;

function remove_overlay() {
    game = true;
    document.getElementById("overlay").style.display = "none";
}
function setArray() {
    for (let index = 0; index < 16; index++) {
        squares[index] = index + 1;
    }
    squares[15] = "";
}
function setBoard() {
    for (let i = 0; i < 16; i++) {
        document.getElementsByTagName("div")[i].innerHTML = squares[i];
        if (squares[i] == "") {
            document.body.getElementsByTagName("div")[i].style.backgroundColor = "#d0d081";
        }
        else {
            document.body.getElementsByTagName("div")[i].style.backgroundColor = "#a5be7d";
        }
    }
    document.getElementsByTagName("span")[0].innerHTML = numberOfMoves;
}
function checkBoard() {
    for (let i = 0; i < 15; i++) {
        if (document.getElementsByTagName("div")[i].innerHTML == i + 1) {
            numberOfCorrectSquares++;
        }
    }
    if (numberOfCorrectSquares == 15) {
        win = true;
    }
    else {
        numberOfCorrectSquares = 0;
    }
}
function shuffleBoard() {
    for (let i = 0; i < 100; i++) {
        let randomNum = Math.floor((Math.random() * 4) + 1);
        switch (randomNum) {
            case 1:
                Up();
                break;
            case 2:
                Down();
                break;
            case 3:
                Right();
                break;
            case 4:
                Left();
                break;
        }
    }
    numberOfMoves = 0;
    setBoard();
}
function Left() {
    if (blank % 4 != 3) {
        squares[blank] = squares[blank + 1];
        squares[blank + 1] = "";
        blank++;
        numberOfMoves++;
    }
}
function Right() {
    if (blank % 4 != 0) {
        squares[blank] = squares[blank - 1];
        squares[blank - 1] = "";
        blank--;
        numberOfMoves++;
    }
}
function Up() {
    if (blank != 12 && blank != 13 && blank != 14 && blank != 15) {
        squares[blank] = squares[blank + 4];
        squares[blank + 4] = "";
        blank = blank + 4;
        numberOfMoves++;
    }
}
function Down() {
    if (blank != 0 && blank != 1 && blank != 2 && blank != 3) {
        squares[blank] = squares[blank - 4];
        squares[blank - 4] = "";
        blank = blank - 4;
        numberOfMoves++;
    }
}
function reset() {
    numberOfCorrectSquares = 0;
    blank = 15;
    setArray();
    shuffleBoard();
    numberOfMoves = 0;
    win = false;
    checkBoard();
}
function checkWin() {
    if (win) {
        document.getElementById("overlay").getElementsByTagName("button")[0].innerHTML = "YOU WON";
        document.getElementById("overlay").style.display = "block";
        game = false;
    }
}
document.addEventListener('keydown', function (event) {
    if (!win && game) {
        if (event.keyCode == 37 || event.keyCode == 65) {
            Left();
        }
        else if (event.keyCode == 38 || event.keyCode == 87) {
            Up();
        }
        else if (event.keyCode == 39 || event.keyCode == 68) {
            Right();
        }
        else if (event.keyCode == 40 || event.keyCode == 83) {
            Down();
        }
        setBoard();
        checkBoard();
        checkWin();
    }
});
setArray();
setBoard();
shuffleBoard();
checkBoard();