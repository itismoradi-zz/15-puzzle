let squares = [];
let blank = 15;
for (let index = 1; index <= 16; index++) {
    squares.push(index);
}
squares[15] = "";

function setBoard() {
    for (let i = 0; i < 16; i++) {
        document.getElementsByTagName("div")[i].innerHTML = squares[i];
        if (squares[i] == "") {
            document.body.getElementsByTagName("div")[i].style.backgroundColor = "#74a059";
        }
        else{
            document.body.getElementsByTagName("div")[i].style.backgroundColor = "#a5be7d";
        }
    }
}
function checkBoard() {
    let flag = true;
    for (let i = 0; i < 15; i++) {
        if (document.getElementsByTagName("div")[i].innerHTML == i + 1);
        else {
            flag = false;
        }
    }
    if (flag) {
        alert("you won");
    }
}

setBoard();
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
    setBoard();
}
shuffleBoard();
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
