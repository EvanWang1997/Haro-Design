int blue1 = 8;
int green1 = 9;
int blue2 = 10;
int green2 = 11;

void setup() {
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
}

void loop() {
  happyBlink2();
  delay(5000);
  happyBlink1();
  delay(4000);
  flusteredBlink();
  delay(4000);
}

// ALL LED RELATED FUNCTIONS
void blue1On() {
  digitalWrite(blue1, HIGH);   
}
void blue2On() {
  digitalWrite(blue2,HIGH);   
}
void green1On() {
  digitalWrite(green1,HIGH);   
}
void green2On() {
  digitalWrite(green2,HIGH);   
}
void blue1Off() {
  digitalWrite(blue1, LOW);   
}
void blue2Off() {
  digitalWrite(blue2,LOW);   
}
void green1Off() {
  digitalWrite(green1,LOW);   
}
void green2Off() {
  digitalWrite(green2,LOW);   
}
void blueAllOff() {
  digitalWrite(blue1, LOW);
  digitalWrite(blue2, LOW);
}
void greenAllOff() {
  digitalWrite(green1, LOW);
  digitalWrite(green2, LOW);
}
void blueAllOn() {
  blue1On();
  blue2On();
}
void greenAllOn() {
  green1On();
  green2On();
}
void eyesAlternate(int time, int loops) {
  blueAllOn();
  greenAllOn();
  int i = 0;

  for (i = 0; i < loops; i++) {
    blue1On();
    green1On();
    blue2Off();
    green2Off();
    delay(time);
    blue1Off();
    green1Off();
    blue2On();
    green2On();
    delay(time);
  }
}
void blink(int time, int loops) {
  blueAllOn();
  greenAllOn();
  int i = 0;

  for (i = 0; i < loops; i++) {
    blue1On();
    green1On();
    blue2On();
    green2On();
    delay(time);
    blue1Off();
    green1Off();
    blue2Off();
    green2Off();
    delay(time/2);
  }
}
void flusteredBlink() {
  eyesAlternate(300,4);
  eyesAlternate(200,2);
  eyesAlternate(100,2);
  blink(500,4);
  blueAllOn();
  greenAllOn();
}
void happyBlink1() {
  blink(1000,2);
  blink(2000,3);
  blueAllOn();
  greenAllOn();
}
void happyBlink2() {
  blink(2000,3);
  blink(1500,2);
  blueAllOn();
  greenAllOn();
}
