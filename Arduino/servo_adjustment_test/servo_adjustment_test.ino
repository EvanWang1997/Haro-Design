#include <Servo.h>

Servo servo;
int angle;
int lowangle = 75;
int highangle = 180;

void setup() {
  servo.attach(7);
  servo.write(lowangle);
}

void loop() {
flusteredFlap();
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
