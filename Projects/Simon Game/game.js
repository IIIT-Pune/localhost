// ORDER

// START -> SEQ -> MOVE -> CHECKING CORRECTNESS -> CORRECT -> NEW SEQ
//                                              -> INCORRECT -> RESTART



// Color of the Blocks

var buttonColours = ["red", "blue", "green", "yellow"];

var gamePattern = [];
var userPattern = [];

var begin = false; // whether the game has begin or not

var level = 0; // cnt of level

// Sequence

$(document).keypress(function()
{
  if (!begin)
  {
    $("#level-title").text("Level " + level); // Changing text from press a key to level
    nextSequence();
    begin = true;
  }
});

// Pressing Buttons

$(".btn").click(function() {

  var userChosenColour = $(this).attr("id");

  //  To keep Track of the moves that has already performed

  userPattern.push(userChosenColour);

  playSound(userChosenColour);

  animatePress(userChosenColour);

  checkAnswer(userPattern.length-1);
});

// Checking either the move is correct or not

function checkAnswer(currentLevel) {

    var timelimit = 1000;
    if (gamePattern[currentLevel] === userPattern[currentLevel]) {
      if (userPattern.length === gamePattern.length){
        // Correct
        // new seq in 1sec
        
        setTimeout(function () {
          nextSequence();
        }, timelimit);
      }
    } 
    else
    {
      // Incorrect

      playSound("wrong");
      $("body").addClass("game-over");
      $("#level-title").text("Game Over, Press Any Key to Restart");

      // to dispaly game over screen 
      setTimeout(function () {
        $("body").removeClass("game-over");
      }, 200);

      // RESTART
      startAgain();
    }
}

// Restart

function startAgain() {
  level = 0;
  gamePattern = [];
  begin = false;
}

// New Sequence / New Stage (level)

function nextSequence() {
  userPattern = [];
  
  level++;

  $("#level-title").text("Level " + level);
  
  var randomNumber = Math.floor(Math.random() * 4);
  var randomChosenColour = buttonColours[randomNumber];

  gamePattern.push(randomChosenColour);

  $("#" + randomChosenColour).fadeIn(100).fadeOut(100).fadeIn(100);
  playSound(randomChosenColour);

}

// Animations over buttons

function animatePress(currentColor){
  $("#" + currentColor).addClass("pressed");
  setTimeout(function () {
    $("#" + currentColor).removeClass("pressed");
  }, 100);
}

// To play button Audio

function playSound(name) {
  var audio = new Audio("sounds/" + name + ".mp3");
  audio.play();
}