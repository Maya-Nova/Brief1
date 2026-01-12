#define M1 7
#define M2 4
#define E1 6
#define E2 5
#include <Servo.h>

Servo myservo1;  
Servo myservo2;

int potpin1 = A0;  
int potpin2 = A1;
int val1;
int val2;    
int actuatorPin1 = 9;  
int actuatorPin2 = 8;

const int button1 = 2 ;
const int button2 = 13 ; 
int buttonState1 = 0 ;
int buttonState2 = 0 ;

const int button3 = 10 ;
const int button4 = 3 ; 
int buttonState3 = 0 ;
int buttonState4 = 0 ;

void setup() {

  Serial.begin(9600);
  pinMode(M1, OUTPUT);
  pinMode(M2, OUTPUT);
  pinMode(button1, INPUT_PULLUP);
  pinMode(button2, INPUT_PULLUP);
  pinMode(button3, INPUT_PULLUP);
  pinMode(button4, INPUT_PULLUP);
  pinMode(actuatorPin1, OUTPUT);
  pinMode(actuatorPin2, OUTPUT);
  myservo1.attach(12);
  myservo2.attach(11);
}

void loop() {
//BUTTONS

  buttonState1 = digitalRead(button1);
  buttonState2 = digitalRead(button2);
  buttonState3 = digitalRead(button3);
  buttonState4 = digitalRead(button4);

//SERVOS

  val1 = analogRead(potpin1);            
  val1 = map(val1, 0, 1023, 0, 180);     
  myservo1.write(val1);

  val2 = analogRead(potpin2);            
  val2 = map(val2, 0, 1023, 0, 180);     
  myservo2.write(val2);

//ACTUATOR ONE

  if (buttonState1 == LOW) { 
    Serial.println("button1 pressed");
    digitalWrite(M1, HIGH);
    digitalWrite(M2, LOW);
    analogWrite(E1, 255);
    analogWrite(E2, 255);
  }
  else if (buttonState2 == LOW) { 
    Serial.println("button2 pressed");
    digitalWrite(M1, LOW);
    digitalWrite(M2, HIGH);
    analogWrite(E1, 255);
    analogWrite(E2, 255);
  }
  else {
    Serial.println("no button pressed");
    digitalWrite(M1, LOW);
    digitalWrite(M2, LOW);
    analogWrite(E1, 0);
    analogWrite(E2, 0);
  }

//ACTUATOR TWO

  if (buttonState3 == LOW) { 
    Serial.println("button3 pressed");
      digitalWrite(actuatorPin1, HIGH);
  digitalWrite(actuatorPin2, LOW);
  }
  else if (buttonState4 == LOW) { 
    Serial.println("button4 pressed");
      digitalWrite(actuatorPin1, LOW);
  digitalWrite(actuatorPin2, HIGH);
  }
  else {
    Serial.println("no button pressed");
      digitalWrite(actuatorPin1, LOW);
    digitalWrite(actuatorPin2, LOW);
  }

  delay (50);
}


   
     
     