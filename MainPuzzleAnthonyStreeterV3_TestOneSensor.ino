//Constants
const byte numSensors = 1;
const byte sensorPins[numSensors] = {3};
const byte LEDPin = A5;
int LED1 = 9;
int LED2 = 10;

//Globals
//Array to keep track of last state of each wheel
byte lastState[numSensors] = {0};

void setup() {
  //Debugging only
  Serial.begin(115200);
  Serial.println(__FILE__ __DATE__);

  //Initialise the input pins
  for(int i=0; i<numSensors; i++){
    pinMode(sensorPins[i], INPUT_PULLUP);
  }
  //Initialise the output pins
  pinMode(LED1, OUTPUT);
  digitalWrite(LED1, HIGH);
  pinMode(LED2, OUTPUT);
  digitalWrite(LED2, LOW);

}

void printState() {
  for(int i=0; i<numSensors; i++){
    Serial.print(lastState[i]);
    //Insert semi colon after all but last value
    if(i<numSensors-1) { Serial.print(";");}
  }
  Serial.println("");
}

void loop() {
  //Has state of switch cheanged since last checked?
  bool hasChanged = false;
  //Are all wheels in correcet position?
  bool allCorrect = true;

  //Loop over all sensors
  for(int i=0; i<numSensors; i++){
    //Read the current value
    byte currentState = !digitalRead(sensorPins[i]);
    //Has the wheel changed?
    if(currentState != lastState[i]) {
      hasChanged = true;
      lastState[i] = currentState;
    }
      //Is it wrong?
      if(currentState == 0){
        allCorrect = false;
      }
  }

  //If any wheel has changed
  if(hasChanged) {
    //Print current state of the puzzle
    printState();
  }

  //Activate LED based on whether all symbols are correct
    digitalWrite(LED1, LOW);
    digitalWrite(LED2, HIGH);
}
