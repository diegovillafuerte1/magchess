byte rows[] = {2, 3, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36};
const int ROWCOUNT = sizeof(rows)/sizeof(rows[0]);
byte cols[] = {37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53};
const int COLCOUNT = sizeof(cols)/sizeof(cols[0]);

byte keys[COLCOUNT][ROWCOUNT];

void setup() {
  Serial.begin(9600);
  for(int i = 0; i < ROWCOUNT; i++) {
    Serial.print(rows[i]); Serial.println(" as input");
    pinMode(rows[i], INPUT);
  }
 
  for (int j = 0; j < COLCOUNT; j++) {
    Serial.print(cols[j]); Serial.println(" as output");
    pinMode(cols[j], OUTPUT);
  }
}

void writeFunc(int colIndex) {
  for (int writeIndex = 0; writeIndex < COLCOUNT; writeIndex++) {
    if (colIndex == writeIndex ) {
      digitalWrite(cols[writeIndex], HIGH) ;
    }
    else {
      digitalWrite(cols[writeIndex], LOW);
    }
  }
}

void readFunc(int out[16]) {
  for (int rowIndex = 0; rowIndex < ROWCOUNT; rowIndex++) {
    int pinState = digitalRead(rows[rowIndex]);
    out[rowIndex] = pinState;
  }
}

void sendRowToPi(int pinCheck[]) {
  //send to pi
}

void writeAndRead() {
  for (int colIndex = 0; colIndex < COLCOUNT; colIndex++) {
    writeFunc(colIndex);
    int readOut[16];
    readFunc(readOut);
    sendRowToPi(readOut);
  }
}
void loop() {
  writeAndRead();
}
