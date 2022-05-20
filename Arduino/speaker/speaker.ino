
int speakerPin = 5;      // connect Red LED to pin 8 (PWM pin)
 
void setup(void) {
  Serial.begin(9600);   // We'll send debugging information via the Serial monitor
}
 
void loop(void) {
  
  // we'll need to change the range from the analog reading (0-1023) down to the range
  // used by analogWrite (0-255) with map!
  // LED gets brighter the harder you press
//  speak(700,500);
//  speak(800,500);
//  speak(900,500);
//  speak(1000,500);
//  speak(1100,500);
//  speak(1200,500);

  happyVoice1();
  delay(2000);
  happyVoice2();
  delay(2000);
  flusteredVoice();
  delay(2000);
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
  tone(speakerPin, 0);
}
