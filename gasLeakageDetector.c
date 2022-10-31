//IOT Project : Gas Leakage Detector                                                                                                                                                                                                                     // IOT PROJECT ON GAS LEAKAGE DETECTOR

int redLed = 12;
int greenLed = 11;
int buzzer = 10;
int smokeA0 = A5;
// Your threshold value
int sensorThreshold = 50;

void setup() {
  pinMode(redLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(smokeA0, INPUT);
  Serial.begin(9600);
}

void loop() {
  int analogSensor = analogRead(smokeA0);

  Serial.print("Pin A0: ");
  Serial.println(analogSensor);
  // Checks if it has reached the threshold value
  if (analogSensor> 40)
  {
    digitalWrite(redLed, HIGH);
    Serial.println("Leakage is High");
    digitalWrite(greenLed, LOW);
    Serial.println("Leakage is not so high");
    digitalWrite(buzzer, HIGH);
  }
  else
  {
    digitalWrite(redLed, LOW);
    Serial.println("Leakage is Low");
    digitalWrite(greenLed, HIGH);
    Serial.println("Leakage is not so low");
    digitalWrite(buzzer, LOW);
  }
  delay(100);
}