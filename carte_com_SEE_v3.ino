

// SEE V3 - carte de controle version CMS
// programme version arduino

#include <Servo.h>

// constantes
const int commande = 4;
const int servo = 5;
const int led = 6;
const int position0 = 0;
const int position1 = 2;

// variables
int val0 = 0;
int val1 = 0;



//Servo de découplage
Servo myServo;

void setup() {
  // debug
  Serial.begin(9600); // Init port série
  //
  pinMode(commande, INPUT);
  pinMode(servo, OUTPUT);
  pinMode (led, OUTPUT);

  myServo.attach(servo);
  digitalWrite(led, LOW);
}

void reglages() {
  val0 = analogRead(position0);
  val0 = map(val0, 0, 1023, 0, 180);
  val1 = analogRead(position1);
  val1 = map(val1, 0, 1023, 0, 180);
  Serial.println(val0);
  Serial.println(val1);
}

void loop() {
  reglages();
  Serial.println(digitalRead(commande));
  // 
  if (digitalRead(commande) == HIGH) {
    //ouverture du SEE
    myServo.write(val1);
    digitalWrite(led, HIGH);
  }
  if (digitalRead(commande) == LOW) {
    // position fermee
    myServo.write(val0);
    digitalWrite(led, LOW);
  }
}
