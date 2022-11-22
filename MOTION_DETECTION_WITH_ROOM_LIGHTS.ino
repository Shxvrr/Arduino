#include <Servo.h>
#define servoPin1 4
#define servoPin2 5
#define trig 3
#define echo 2
#define light 6
int d = 500;
int previous=0;
int current=0;
int counter=1;
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
  digitalWrite(trig,LOW);
  delay(2);
  digitalWrite(trig,HIGH);
  delay(10);
  digitalWrite(trig,LOW);
  double duration=pulseIn(echo,HIGH);
  int distance = 0.034 * duration/2;
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
    digitalWrite(light,HIGH);
   
 
  }
  else
  {
    digitalWrite(light,LOW);
  }
}
