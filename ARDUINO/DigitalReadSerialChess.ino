/*
  DigitalReadSerial

  Reads a digital input on pin 2, prints the result to the Serial Monitor

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/DigitalReadSerial
*/

// digital pin 2 has a pushbutton attached to it. Give it a name:
int A = 2;
int B = 5;
int C = 4;
int D = 3;

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  // make the pushbutton's pin an input:
  Serial.println("hello world");
  pinMode(A, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(C, INPUT);
  pinMode(D, INPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  int i = 0;
  // read the input pin:
  
  digitalWrite(A, HIGH);
  digitalWrite(B, LOW);
 
  int CState = digitalRead(C);
  int DState = digitalRead(D);

  if (CState == HIGH) {
    Serial.println("4 is Pressed");
    i++;
  }
  if (DState == HIGH) {
    i++;
    Serial.println("3 is Pressed");
  }

  delay(50);        // delay in between reads for stability

  digitalWrite(A, LOW);
  digitalWrite(B, HIGH);
 
  int CState2 = digitalRead(C);
  int DState2 = digitalRead(D);

  if (CState2 == HIGH) {
    i++;
    Serial.println("2 is Pressed");
  }
  if (DState2 == HIGH) {
    i++;
    Serial.println("1 is Pressed");
  }
  delay(50);
  Serial.print(i);
  Serial.println(" buttons were pressed.");
  delay(50);
}
