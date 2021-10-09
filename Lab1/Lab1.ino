/* Microprocessor Systems II & Embedded Systems
 *  EECE.4520 (201)
 *  Lab 1
 *  Sage Lyon & Matthew Sylvester
 */

const int redLED = 22;
const int yellowLED = 24;
const int greenLED = 26;
const int buzzer = 28;
const int buzzerFrequency = 1750;
const byte interruptPin = 2;
volatile byte state = LOW;
int buttonPressed = 0;

void setup() {
  // Set LED and buzzer pins to output
  pinMode(redLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  pinMode(greenLED, OUTPUT);                                      
  pinMode(buzzer, OUTPUT);
  // Set button pin to input pullup and attach interupt to pin
  pinMode(interruptPin, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(interruptPin), start, RISING);

}

void loop() {
  // If button is not pressed then turn red LED blinks
  if(buttonPressed == 0){
      digitalWrite(redLED, HIGH);
      delay(1000);
      digitalWrite(redLED, LOW);
      delay(1000);
    }
  // If button is pressed then cycle through R-G-Y LEDs and beep for three seconds before light changes
  else{
      digitalWrite(redLED, HIGH);
      delay(17000);
      beep();
      digitalWrite(redLED, LOW);
      digitalWrite(greenLED, HIGH);
      delay(17000);
      beep();
      digitalWrite(greenLED, LOW);
      digitalWrite(yellowLED, HIGH);
      beep();
      digitalWrite(yellowLED, LOW);
  }
}

// Sets buttonPressed to 1 when button is pressed
void start(){
    buttonPressed = 1;
  }

// Buzzer beeps on and off for three seconds
void beep(){
  tone(buzzer, buzzerFrequency);
  delay(500);
  noTone(buzzer);
  delay(500);
  tone(buzzer, buzzerFrequency);
  delay(500);
  noTone(buzzer);
  delay(500);
  tone(buzzer, buzzerFrequency);
  delay(500);
  noTone(buzzer);
  delay(500);
}
