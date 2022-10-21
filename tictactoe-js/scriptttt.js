console.log("Welcome to The Game")
let music = new Audio("music.mp3");
let audioTurn = new Audio("click.mp3");
let gameover = new Audio("success-fanfare-trumpets-6185.mp3");
let turn = "X";
let isgameover = false;

const changeTurn = ()=>{
    return turn === "X"? "O": "X"
}

const checkWin = ()=>{
    let boxtext = document.getElementsByClassName('boxtext');
    let wins = [
        [0, 1, 2, 4, 6, 0],
        [3, 4, 5, 5, 19.5, 0],
        [1, 4, 7, 4, 20, 90],
        [6, 7, 8, 5, 32.5, 0],
        [0, 3, 6, -9, 20, 90],
        [2, 4, 6, 5, 18, 135],
        [2, 5, 8, 18, 20, 90],
        [0, 4, 8, 3, 18, 45],
    ]
    wins.forEach(e =>{
        if((boxtext[e[0]].innerText===boxtext[e[1]].innerText) && (boxtext[e[2]].innerText===boxtext[e[1]].innerText) && (boxtext[e[0]].innerText !== "")) {
          document.querySelector('.info').innerText=boxtext[e[0]].innerText + " WON"
          isgameover = true
          document.querySelector( '.imgbox').getElementsByTagName('img')[0].style.width="200px";
          document.querySelector(".line").style.width="31vw";
          document.querySelector(".line").style.transform = `translate(${e[3]}vw, ${e[4]}vw) rotate(${e[5]}deg)`        
        }
        })



}

//game logic
 music.play()

let boxes = document.getElementsByClassName("box");
Array.from(boxes).forEach(element =>{
let boxtext = element.querySelector( '.boxtext');
element.addEventListener('click', ()=>{
    if(boxtext.innerText === ''){
        boxtext.innerText = turn;
       turn = changeTurn();
        audioTurn.play();
        checkWin();
        if(!isgameover){
            document.getElementsByClassName("info")[0].innerText = "Turn For player " + turn;

        }
        
    }
})

})
reset.addEventListener('click', ()=>{
    let boxtexts = document.querySelectorAll('.boxtext');
    Array.from(boxtexts).forEach(element=> {
        element.innerText=""
    });
    turn="X";
    isgameover=false
    document.querySelector(".line").style.width="0vw";
        document.getElementsByClassName("info")[0].innerText = "Turn For player " + turn;
        document.querySelector( '.imgbox').getElementsByTagName('img')[0].style.width="0px"
})