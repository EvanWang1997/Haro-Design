
const int ypin = A1; // y-axis
int ystable;

// 0 denotes happy, 1 denotes flustered. 
int flustered;

void setup()
{
  ystable = analogRead(ypin);
  flustered = 0;
  Serial.begin(9600);
}
 
void loop()
{
  int y = analogRead(ypin); //read from ypin
  delay(1); 
 
  float zero_G = 512.0; //ADC is 0~1023 the zero g output equal to Vs/2
  float scale = 102.3; //ADXL335330 Sensitivity is 330mv/g
  //330 * 1024/3.3/1000
  
  float diff = abs(ystable - y);
  
  if (diff > 6) {
    flustered = 1;
  }
}

void flusteredCheck() {
  int y = analogRead(ypin); //read from ypin
  delay(1); 
 
  float zero_G = 512.0; //ADC is 0~1023 the zero g output equal to Vs/2
  float scale = 102.3; //ADXL335330 Sensitivity is 330mv/g
  //330 * 1024/3.3/1000
  
  float diff = abs(ystable - y);
  
  if (diff > 6) {
    flustered = 1;
  }
}
