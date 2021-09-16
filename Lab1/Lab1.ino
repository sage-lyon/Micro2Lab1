int greenLED = 24;
int yellowLED = 23;
int redLED = 22;

void setup() {
  // put your setup code here, to run once:
  pinMode(greenLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  pinMode(redLED, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(redLED, HIGH);
  delay(1000);
  digitalWrite(redLED, LOW);
  delay(1000);
}
