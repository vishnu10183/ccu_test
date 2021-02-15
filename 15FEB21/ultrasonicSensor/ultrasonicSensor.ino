const int pingPin = 7; // Trigger Pin of Ultrasonic Sensor
const int echoPin = 6; // Echo Pin of Ultrasonic Sensor
int count = 0;

//int us_2[30], us_30[30], us_60[30], us_90[30], us_120[30], us_150[30];

void setup() {
  Serial.begin(9600); // Starting Serial Terminal
}

void loop() {
  long duration, inches;
  float cm;
  if ( count <= 30 ) {
    pinMode(pingPin, OUTPUT);
    digitalWrite(pingPin, LOW);
    delayMicroseconds(2);
    digitalWrite(pingPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(pingPin, LOW);
    pinMode(echoPin, INPUT);
    duration = pulseIn(echoPin, HIGH);

    cm = microsecondsToCentimeters(duration);

    Serial.print(" | ");
    Serial.print(cm);
    //Serial.print("cm");
    Serial.println();
    count++;
  }
  delay(100);
}

float microsecondsToInches(long microseconds) {
  return microseconds / 74.0 / 2.0;
}

float microsecondsToCentimeters(long microseconds) {
  return microseconds / 29.0 / 2.0;
}
