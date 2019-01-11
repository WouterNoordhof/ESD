void setup() {
  light_setup();
  serialInput_Setup();
  stateMachine_Setup();
}

void loop() {
  if(serialInput_Received()) {
    changeCurrentState();
  }
  stateMachine_Loop();
}
