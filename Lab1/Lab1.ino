const int Red_LED = 22;
const int Yellow_LED = 24;
const int Green_LED = 26;
const int Buzzer = 28;
const int Buzzer_Frequency = 1750;
const byte interruptPin = 2;
volatile byte state = LOW;

int Button_Pressed = 0;
void setup() {
  pinMode(Red_LED, OUTPUT);
  pinMode(Yellow_LED, OUTPUT);
  pinMode(Green_LED, OUTPUT);                                      

  pinMode(Buzzer, OUTPUT);
  
  pinMode(interruptPin, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(interruptPin), start, RISING);

}

void loop() {
  if(Button_Pressed == 0){
      digitalWrite(Red_LED, HIGH);
      delay(1000);
      digitalWrite(Red_LED, LOW);
      delay(1000);
    }
    else{
      digitalWrite(Red_LED, HIGH);
      delay(17000);
      beep();
      digitalWrite(Red_LED, LOW);
      digitalWrite(Yellow_LED, HIGH);
      beep();
      digitalWrite(Yellow_LED, LOW);
      digitalWrite(Green_LED, HIGH);
      delay(17000);
      beep();
      digitalWrite(Green_LED, LOW);
      }
}


void start(){
    Button_Pressed = 1;
    
  }

void beep(){
  tone(Buzzer, Buzzer_Frequency);
  delay(500);
  noTone(Buzzer);
  delay(500);
  tone(Buzzer, Buzzer_Frequency);
  delay(500);
  noTone(Buzzer);
  delay(500);
  tone(Buzzer, Buzzer_Frequency);
  delay(500);
  noTone(Buzzer);
  delay(500);
}
