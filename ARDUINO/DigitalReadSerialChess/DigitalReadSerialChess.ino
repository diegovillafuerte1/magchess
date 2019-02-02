
int A = 2; // output pin
int B = 5; // output pin
int C = 4; // input pin
int D = 3; //input pin

void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  pinMode(A, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(C, INPUT);
  pinMode(D, INPUT);
}

void loop() {
  digitalWrite(A, HIGH);
  digitalWrite(B, LOW);
 
  int CState = digitalRead(C);
  int DState = digitalRead(D);

  if (CState == HIGH) {
    Serial.println("4 is Pressed");
  }
  if (DState == HIGH) {
    Serial.println("3 is Pressed");
  }

  delay(50);        // delay in between reads for stability

  digitalWrite(A, LOW);
  digitalWrite(B, HIGH);
 
  int CState2 = digitalRead(C);
  int DState2 = digitalRead(D);

  if (CState2 == HIGH) {
    Serial.println("2 is Pressed");
  }
  if (DState2 == HIGH) {
    Serial.println("1 is Pressed");
  }
  delay(50);
}
