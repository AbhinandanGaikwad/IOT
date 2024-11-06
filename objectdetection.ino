#define IRSensor 2
#define LED 13

void setup() {
  pinMode(IRSensor, INPUT);
  pinMode(LED, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int statusSensor = digitalRead(IRSensor);

  if(statusSensor == 1) {
    digitalWrite(LED, HIGH);
    Serial.println("Object detected");
  }
  else {
    digitalWrite(LED, LOW);
    Serial.println("No object detected");
  }
}
