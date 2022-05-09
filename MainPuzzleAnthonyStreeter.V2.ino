const int REED_PIN = 2; // const for the reed switch
const int LED_PIN = 13; // const for LED

void setup() 
{
  Serial.begin(9600);//Creates serial connection
  pinMode(REED_PIN, INPUT_PULLUP);
  pinMode(LED_PIN, OUTPUT);
}

void loop() 
{
  int proximity = digitalRead(REED_PIN); // Read the current state of the switch
  if (proximity == LOW) // If the reed switch pin reads low, the switch is closed. 
  {
    Serial.println("Switch closed"); //Output to SM
    digitalWrite(LED_PIN, HIGH); // Turn the LED on
  }
  else
  {
    digitalWrite(LED_PIN, LOW); // Turn the LED off
  }
}
