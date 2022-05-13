squares = new Array(16);
let blankSquare = 15;
let numberOfMoves = 0;
let hasWon = false;
let pressedPlay = false;
let numberOfCorrectSquares = 0;

function remove_overlay() {
    pressedPlay = true;
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
        hasWon = true;
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
    if (blankSquare % 4 != 3) {
        squares[blankSquare] = squares[blankSquare + 1];
        squares[blankSquare + 1] = "";
        blankSquare++;
        numberOfMoves++;
    }
}
function Right() {
    if (blankSquare % 4 != 0) {
        squares[blankSquare] = squares[blankSquare - 1];
        squares[blankSquare - 1] = "";
        blankSquare--;
        numberOfMoves++;
    }
}
function Up() {
    if (blankSquare != 12 && blankSquare != 13 && blankSquare != 14 && blankSquare != 15) {
        squares[blankSquare] = squares[blankSquare + 4];
        squares[blankSquare + 4] = "";
        blankSquare = blankSquare + 4;
        numberOfMoves++;
    }
}
function Down() {
    if (blankSquare != 0 && blankSquare != 1 && blankSquare != 2 && blankSquare != 3) {
        squares[blankSquare] = squares[blankSquare - 4];
        squares[blankSquare - 4] = "";
        blankSquare = blankSquare - 4;
        numberOfMoves++;
    }
}
function reset() {
    numberOfCorrectSquares = 0;
    blankSquare = 15;
    setArray();
    shuffleBoard();
    numberOfMoves = 0;
    hasWon = false;
    checkBoard();
}
function checkhasWon() {
    if (hasWon) {
        document.getElementById("overlay").getElementsByTagName("button")[0].innerHTML = "YOU WON";
        document.getElementById("overlay").style.display = "block";
        pressedPlay = false;
    }
}
document.addEventListener('keydown', function (event) {
    if (!hasWon && pressedPlay) {
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
        checkhasWon();
    }
});
setArray();
setBoard();
shuffleBoard();
checkBoard();