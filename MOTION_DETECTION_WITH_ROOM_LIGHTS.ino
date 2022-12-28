#include <Servo.h>
#define servoPin1 4
#define servoPin2 5
#define trig 3
#define echo 2
#define light 6

int d = 3000;
int previous=0;
int current=0;
int counter=1;
int distance;

Servo Servo1;
Servo Servo2;

void setup() {
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);
  pinMode(light,OUTPUT);
  Serial.begin(9600);
  Servo1.attach(servoPin1);
  Servo2.attach(servoPin2);
  // put your setup code here, to run once:

}

void loop() {
}
  digitalWrite(trig,LOW);
  delay(2);
  digitalWrite(trig,HIGH);
  delay(10);
  digitalWrite(trig,LOW);
  double duration=pulseIn(echo,HIGH);
  distance = 0.034 * duration;
  distance = distance/2;
  Serial.println(distance);

  if(distance<100)
  {
    current= HIGH;
  }
  else
  {
    current=LOW;
  }
  if(current==HIGH&&current!=previous)
  {
    counter++;
  }
  delay(50);
  previous=current;
  if(counter%2==0)
  {
   lightON();
  }
  else
  {
   lightOFF();
  }

void lightON() {
    digitalWrite(light,HIGH);
    Servo1.write(180);
    delay(d);
    Servo1.write(0);
}

void lightOFF() {
   digitalWrite(light,LOW);
    Servo2.write(180);
    delay(d);
    Servo2.write(0);
}

