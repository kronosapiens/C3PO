// C3PO

int analogPin = A0;     // potentiometer wiper (middle terminal) connected to analog pin A0
                        // outside leads to ground and +5V

int pressureReading = 0;           // variable to store the value read

int redPin = 11;
int greenPin = 10;
int bluePin = 9;

int fullPot = 900;          // set thresholds for analogRead
int medPot = 300;

//uncomment this line if using a Common Anode LED
//#define COMMON_ANODE

void setup()

{

  Serial.begin(9600);          //  setup serial
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT); 
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

  pressureReading = analogRead(analogPin);    // read the input pin

  Serial.println(pressureReading);             // debug value
  
  if(pressureReading > fullPot){
      setColor(0, 255, 0);  // green
  }else if(pressureReading > medPot && pressureReading < fullPot){
      setColor(255, 255, 0);  // yellow
  }else{
      setColor(255, 0, 0);  // red
  };

  delay(500);                  // waits for a half-second

}
