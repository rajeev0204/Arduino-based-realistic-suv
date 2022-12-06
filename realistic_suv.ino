// project made by Rajeev R Pandey
// realistic SUV car
// features - Forward movement , Backward movement, Right turn , Left turn, 
int A = 0; // variable to read RF i/p 1
int B = 0; // variable to read RF i/p 2
int C = 0;  // variable to read RF i/p 3
 

// initializing pins
void setup() {
  pinMode(8, INPUT);   // RF i/p 1
  pinMode(9, INPUT);   // RF i/p 2
  pinMode(10,INPUT);  // RF i/p 3
  pinMode(2, OUTPUT);  // motor a1
  pinMode(3, OUTPUT);  // motor a2
  pinMode(4, OUTPUT);  // motor b1
  pinMode(5, OUTPUT);  // motor b2
  pinMode(11, OUTPUT); // Headlight
  pinMode(6, OUTPUT);  // rear indicator
  pinMode(12, OUTPUT); // right indicator
  pinMode(13, OUTPUT); // left indicator
}

// main program

void loop() {

  A = digitalRead(8);
  B = digitalRead(9);
  C = digitalRead(10);
  analogWrite(6, 155);
  analogWrite(11, 155);
  
  // stop condition

 if ((A == 1 && B == 1 && C == 1)) {
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);

  }

  // forward motion

  if (A == 0 && B == 1 && C == 1) {
    digitalWrite(2, LOW);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(5, LOW);
    analogWrite(6, 50);

  }

  // backward motion

  if ((A == 1 && B == 0 && C == 1)) {
    digitalWrite(2, HIGH);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, HIGH);
    analogWrite(11, 155);
    analogWrite(6, 50);

  }

  // RIGHT TURN

  if ((A == 0 && B == 1 && C == 0)) {
    digitalWrite(2, LOW);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(5, LOW);
    analogWrite(6, 50);
    digitalWrite(12, HIGH);
    delay(500);
    digitalWrite(12, LOW);
    delay(500);

  }

  // LEFT TURN

  if ((A == 1 && B == 0 && C == 0)) {
    digitalWrite(2, HIGH);
    digitalWrite(3, LOW);
    digitalWrite(4, HIGH);
    digitalWrite(5, LOW);
    analogWrite(6, 50);
    digitalWrite(13, HIGH);
    delay(500);
    digitalWrite(13, LOW);
    delay(500);
  }
}