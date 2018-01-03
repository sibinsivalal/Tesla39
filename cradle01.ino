#define E1 10  // Enable Pin for motor 1
#define E2 11  // Enable Pin for motor 2

#define I1 8  // Control pin 1 for motor 1
#define I2 9  // Control pin 2 for motor 1
#define I3 12  // Control pin 1 for motor 2
#define I4 13  // Control pin 2 for motor 2

const int PushB = 2;
int PushBstate = 0;

const int limitB = 3;
int limitBstate = 0;


void setup() {

  pinMode(E1, OUTPUT);
  pinMode(E2, OUTPUT);

  pinMode(I1, OUTPUT);
  pinMode(I2, OUTPUT);
  pinMode(I3, OUTPUT);
  pinMode(I4, OUTPUT);

  pinMode(PushB, INPUT);
  pinMode(limitB, INPUT);
}

void loop() {

  PushBstate = digitalRead(PushB);
  limitBstate = digitalRead(limitB);


  if (PushBstate == HIGH)
  {
    analogWrite(E1, 153); // Run in half speed
    analogWrite(E2, 255); // Run in full speed

    digitalWrite(I1, HIGH);
    digitalWrite(I2, LOW);
    digitalWrite(I3, HIGH);
    digitalWrite(I4, LOW);
  }
  else
  {
    if (limitB == LOW)
    {
      digitalWrite(E1, 0);
      digitalWrite(E2, 0);

      digitalWrite(I1, LOW);
      digitalWrite(I2, LOW);
      digitalWrite(I3, LOW);
      digitalWrite(I4, LOW);
    }

  }








}
