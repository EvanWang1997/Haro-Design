#include <Servo.h>

Servo servo;
int angle = 90;
int speakerPin = 5;      // connect Red LED to pin 8 (PWM pin)
const int zpin = A0; // z-axis of the accelerometer
const int ypin = A1; // y-axis
const int xpin = A2; // x-axis
 

void setup() {
  servo.attach(7);
  servo.write(angle);
  Serial.begin(9600);   // We'll send debugging information via the Serial monitor

}

void loop() {
  // Checks the LED for eyes
  digitalWrite(8,255);   
  delay(200);              
  digitalWrite(8, LOW);   
  delay(200);     
  
  digitalWrite(9,HIGH);   
  delay(200);              
  digitalWrite(9, LOW);   
  delay(200);   

  digitalWrite(10,HIGH);   
  delay(200);              
  digitalWrite(10, LOW);   
  delay(200);   

  digitalWrite(11,HIGH);   
  delay(200);              
  digitalWrite(11, LOW);   
  delay(200);   

    // now scan back from 180 to 0 degrees
  for(angle = 90; angle < 180; angle++)    
  {                                
    servo.write(angle);           
    delay(1);       
  } 
  
  // scan from 0 to 180 degrees
  for(angle = 180; angle > 90; angle--)  
  {                                  
    servo.write(angle);               
    delay(1);                   
  } 


  // Produces some beeps with the speaker
  tone(speakerPin, 600,1000);
  delay(500);
  
  tone(speakerPin, 700,1000);
  delay(500);

int x = analogRead(xpin); //read from xpin
delay(1); //
int y = analogRead(ypin); //read from ypin
delay(1); 
int z = analogRead(zpin); //read from zpin
 
float zero_G = 512.0; //ADC is 0~1023 the zero g output equal to Vs/2
float scale = 102.3; //ADXL335330 Sensitivity is 330mv/g
//330 * 1024/3.3/1000
Serial.print(((float)x - 331.5)/65*9.8); //print x value on serial monitor
Serial.print("\t");
Serial.print(((float)y - 329.5)/68.5*9.8); //print y value on serial monitor
Serial.print("\t");
Serial.print(((float)z - 340)/68*9.8); //print z value on serial monitor
Serial.print("\n");
delay(1000); //wait for 1 second 

}
