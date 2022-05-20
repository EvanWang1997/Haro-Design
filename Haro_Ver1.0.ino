#include <Servo.h>

Servo servo;
int angle;
int lowangle = 75;
int highangle = 180;

const int ypin = A1; // y-axis
int ystable;
// 0 denotes happy, 1 denotes flustered. 
boolean flustered;

int blue1 = 8;
int green1 = 9;
int blue2 = 10;
int green2 = 11;

int speakerPin = 5;      // connect Red LED to pin 8 (PWM pin)

// INITIAL SET UP FUNCTION
void setup() {
  ystable = analogRead(ypin);
  flustered = false;
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  blueAllOn();
  greenAllOn();
  servo.attach(7);
  servo.write(lowangle);
  Serial.begin(9600);
}

// MAIN LOOP TO RUN THROUGH CODE
void loop() {
  ystable = analogRead(ypin);
  delay(1000);
  flusteredCheck();

  if (flustered == false) {
    happyReactions();  
  } else {
    flusteredReaction();
  }

}

void happyReactions() {
  long randNumber = random(1);

  if (randNumber == 1) {
    happyVoice1();
    happyBlink1();
    happyFlap();
  } else {
    happyVoice2();
    happyBlink2();
    happyFlap();
  }
}


void flusteredReaction() {
  flusteredVoice();
  flusteredBlink();
  flusteredFlap();
}

void flusteredCheck() {
  int y = analogRead(ypin); //read from ypin
  delay(1); 
 
  float zero_G = 512.0; //ADC is 0~1023 the zero g output equal to Vs/2
  float scale = 102.3; //ADXL335330 Sensitivity is 330mv/g
  //330 * 1024/3.3/1000
  
  int diff = abs(ystable - y);
  Serial.print(y);
  Serial.print("\t");
  Serial.print(ystable);
  Serial.print("\t");
  
  if (diff < 15) {
    flustered = false;
  } else {
    flustered = true;
  }
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
  blink(1000,3);
  blink(800,2);
  blueAllOn();
  greenAllOn();
}

// speaks at a certain tone, and then delays at a specified time in seconds
void speak(int freq, int time) {
  tone(speakerPin, freq);
  delay(time);
}
// generates a short range of frequencies going up from the 2nd one, at a rate of 10 ms per frequency
void range(int freq1, int freq2, int gap) {
  int currentfreq = freq1;
  
  if (freq1 > freq2) {
    for (currentfreq = freq1; currentfreq >= freq2; currentfreq--) {
      speak(currentfreq,gap);
    }
  } else if (freq1 < freq2) {
    for (currentfreq = freq1; currentfreq <= freq2; currentfreq++) {
      speak(currentfreq,gap);
    }
  }
}
void flusteredVoice() {
  range(500,600,3);
  range(600,400,5);
  range(400,500,7);
  range(500,300,5);
  range(300,500,2);
  tone(speakerPin, 0);
}
void happyVoice1() {
  range(500,700,3);
  range(600,800,3);
  speak(900,300);
  speak(800,200);
  speak(900,400);
  tone(speakerPin, 0);
}
void happyVoice2() {
  range(600,800,3);
  range(700,900,3);
  speak(400,400);
  speak(600,300);
  speak(350,200);
  speak(1200,200);
  tone(speakerPin, 0);
}

// Below are the functions for ear flapping
void flap(int speedo, int times) {
   int i;
  
  for (i = 0; i < times; i++) {
        for(angle = lowangle; angle < highangle; angle++)  
    {                                  
      servo.write(angle);               
      delay(speedo);                   
    } 
    // now scan back from 180 to 0 degrees
    for(angle = highangle; angle > lowangle; angle--)    
    {                                
      servo.write(angle);           
      delay(speedo);       
    } 
  }
}

void happyFlap() {
  flap(5,2);
  flap(4,3);
}

void flusteredFlap(){
  flap(3,2);
  flap(2,4);
}
