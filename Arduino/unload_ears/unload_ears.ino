#include <Servo.h>
Servo servo;

void setup() {
    servo.attach(7);
    servo.write(0);
    delay(1000); 
}

void loop() {

}
