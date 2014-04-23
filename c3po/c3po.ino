// C3PO

int analogPin = A0;     // pressure sensor connected to analog pin A0
                        // outside leads to ground and +5V

int pressureReading1 = 0;           // variable to store the value read
int pressureReading2 = 0;
int pressureReading3 = 0;
int pressureReading4 = 0;
int pressureReading5 = 0;
int pressureAvg = 0;
int lastReading = 0;


int redPin = 11;
int greenPin = 10;
int bluePin = 9;

int led = 13;

int fullPot = 150;          // set thresholds for analogRead
int halfPot = 530;          // not currently being used
int emptyPot = 50;

//uncomment this line if using a Common Anode LED
//#define COMMON_ANODE

void setup()

{

  Serial.begin(9600);          //  setup serial
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  pinMode(led, OUTPUT); 

}

void setColor(int red, int green, int blue)

{
  #ifdef COMMON_ANODE
    red = 255 - red;
    green = 255 - green;
    blue = 255 - blue;
  #endif
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);  
}

void loop()

{

  digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
  
  pressureReading1 = analogRead(analogPin);    // read the input pin
  Serial.println(pressureReading1);             // debug value
  delay(400);
  pressureReading2 = analogRead(analogPin);
  Serial.println(pressureReading2);
  delay(400);
  pressureReading3 = analogRead(analogPin);
  Serial.println(pressureReading3);
  delay(400);
  digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW
  pressureReading4 = analogRead(analogPin);
  Serial.println(pressureReading4);
  delay(400);
  pressureReading5 = analogRead(analogPin);
  Serial.println(pressureReading5);
  
  pressureAvg = ((pressureReading1 + pressureReading2 + pressureReading3 + pressureReading4 + pressureReading5) / 5);
  
  Serial.print(millis()/1000.0);          // print data to screen for debugging
  Serial.print(" - pressureReading: ");
  Serial.println(pressureAvg);
  
  if(abs(lastReading / pressureAvg) > 2){
    return;
  }else if(pressureAvg > fullPot){
      setColor(0, 255, 0);  // green
//  }else if(pressureAvg > halfPot && pressureAvg < fullPot){
//      setColor(255, 123, 0);  // yellow
  }else if(pressureAvg > emptyPot){
      setColor(255, 0, 0);  // red
  }else{
    setColor(0, 0, 255);  // blue
  };
  
  lastReading = pressureAvg;
  
  delay(400);

}
