var sessionLength = document.getElementById("sessionLength");
var breakLength = document.getElementById("breakLength");
var sessionTime = 60000*(parseInt(sessionLength.textContent));
var breakTime = 60000*(parseInt(breakLength.textContent));
var currentStatus = document.getElementById("currentStatus");
var timerClock = document.getElementById("countdownTimer");
var countdownRunning = false;
var fillColor = "green";
var timerClockFill = document.getElementById("progress");
var time,x;

var handlers = {
  timeConverter: function(timeInMinutes) {
    return parseInt(timeInMinutes)*60000;
  },

  session: function() {
    time = ( fillColor === "green" ) ? 60000*(parseInt(sessionLength.textContent)) : 60000*(parseInt(breakLength.textContent));
    timerClock.textContent = ( fillColor === "green" ) ? sessionLength.textContent : breakLength.textContent;
    x = setInterval( function() {
      if(countdownRunning) {
        currentStatus.textContent = ( fillColor === "green" ) ? "Session" : "break";
        var minutes = ( time % (1000 * 60 * 60)) / (1000 * 60);
        minutes = Math.floor(minutes);
        var seconds = Math.floor(( time % (1000 * 60)) / 1000);
        if( seconds < 10 ) {
          timerClock.textContent = minutes + " : 0" + seconds;
        } else {
          timerClock.textContent = minutes + " : " + seconds;
        }
        time -= 1000;
        debugger;
        var fillPercentage = 0;
        var countdownClock = document.getElementById("countdownClock");
        if( fillColor === "green" ){
          fillPercentage = (( handlers.timeConverter(sessionLength.textContent)-time )/handlers.timeConverter(sessionLength.textContent)) * 100 ;
          fillPercentage = fillPercentage;
          countdownClock.style.background = "linear-gradient(to top, rgba(118,224,15,1) " + (fillPercentage-2) + "%,rgba(118,224,15,0) " + fillPercentage + "%)";
        } else {
          fillPercentage = ( time / handlers.timeConverter(breakLength.textContent )) * 100 ;
          countdownClock.style.background = "linear-gradient(to top, rgba(234,58,15,1) " + ( fillPercentage - 2 ) + "%,rgba(234,58,15,0) " + fillPercentage + "%)";
        }

        if ( time < 0 ) {
          clearInterval( x );
          handlers.session();
        }
      } else {

        currentStatus.textContent = "Timer Paused";
      }
    },1000);
  },

  changeTimer: function( id ){
    if ( id === "breakTimerReduce" ) {
      if ( fillColor === "red" ) {
        if( parseInt(breakLength.textContent) > 1 ) {
          var currentTime = parseInt(breakLength.textContent) - 1;
          breakLength.textContent = currentTime;
          time = this.timeConverter( breakLength.textContent );
          timerClock.textContent = breakLength.textContent;
        }
      } else {
        var currentTime = parseInt(breakLength.textContent) - 1;
          breakLength.textContent = currentTime;
      }
    } else if ( id === "breakTimerIncrease" ) {
      if ( fillColor === "red" ) {
        var currentTime = parseInt(breakLength.textContent) + 1;
        breakLength.textContent = currentTime;
        time = this.timeConverter( breakLength.textContent );
        timerClock.textContent = breakLength.textContent;
      }
    } else if ( id === "sessionTimerReduce" ) {
      if ( fillColor === "green" ) {
        if( parseInt( sessionLength.textContent ) > 1 ) {
          var currentTime = parseInt( sessionLength.textContent ) - 1;
          sessionLength.textContent = currentTime;
          time = this.timeConverter( sessionLength.textContent );
          timerClock.textContent = sessionLength.textContent;
        }
      }
    } else if ( id === "sessionTimerIncrease" ) {
      if ( fillColor === "green" ) {
        var currentTime = parseInt( sessionLength.textContent ) + 1;
        sessionLength.textContent = currentTime;
        time = this.timeConverter( sessionLength.textContent );
        timerClock.textContent = sessionLength.textContent;
        if (( currentTime > 45 ) && ( currentTime % 3 === 0)) {
          alert("Too Big Session Time Is Just Against the Concept of a Pomodoro Clock, Buddy");
        }
      }
    }
  }
};
var view = {
  setUpEventListeners: function() {
  var timers = document.getElementById("timers");
  timers.addEventListener( 'click', function (event) {
    debugger;
    event.preventDefault();
    console.log(event);
    if ( !countdownRunning ) {
      handlers.changeTimer(event.path[1].id);
    }
  });
  timerClock.addEventListener( 'click', function() {
    // debugger;
    console.log( "countdownRunning = " , countdownRunning );
    countdownRunning = !countdownRunning;
  });
 }
}
handlers.session();
view.setUpEventListeners();
