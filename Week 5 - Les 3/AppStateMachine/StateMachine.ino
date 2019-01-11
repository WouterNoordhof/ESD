const int state_LedOn = 1;
const int state_LedOff = 2;

int currentState = 0;
boolean stateSwitch = false;

void stateMachine_Setup () {
  currentState = state_LedOff;
  ledOff_Entry();
  
}

void changeCurrentState() {
  if(currentState == state_LedOn) {
    currentState = state_LedOff;
  } else {
    currentState = state_LedOn;    
  }
  stateSwitch = true;
}

void stateMachine_Loop () {
  switch(currentState) {
    case state_LedOn:
      if(stateSwitch) {
        ledOn_Entry();
        stateSwitch = false;
      }
      ledOn_Do();
    break;
    case state_LedOff:
      if(stateSwitch) {
        ledOff_Entry();
        stateSwitch = false;
      }
      ledOff_Do();
    break;
  }
}

/*******************
 *     State On    *
 ******************/
void ledOn_Entry() {
  LIGHT_ON();
}

void ledOn_Do() {

}

void ledOn_Exit() {

}
/*******************
 *    State Off    *
 ******************/

void ledOff_Entry() {
  LIGHT_OFF();
}

void ledOff_Do() {

}

void ledOff_Exit() {

}
