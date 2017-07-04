int ledPin = 3;
int inputPin = 2;
int pirState = 0;
int val = 0;
int timerStep = 0;
int timeOut = 10;

void setup() {
  pinMode(ledPin, OUTPUT); //LED As output
  pinMode(inputPin, INPUT); //Read inputPin
}

void loop() {

  val = digitalRead(inputPin);
  switch ( pirState ) {
    case 0:
    
      if ( val == HIGH ) {
        turnOnLeds();
      }
      
    break;
    case 1:
    
      if ( val == HIGH ) {
        //Reset the counter to ensure lights stay on.
       timerStep = 0; 
      } else {
        timerStep = timerStep + 1; 
      }
      
      if ( timerStep >= timeOut ) {
        turnOffLeds();
      } 
      
      delay(1000);
      
    break;
  }

}

void turnOnLeds() {
  pirState = 1;
  timerStep = 0; 
  digitalWrite(ledPin, HIGH);
}

void turnOffLeds() {
  timerStep = 0;
  pirState = 0;
  digitalWrite(ledPin, LOW);
}
