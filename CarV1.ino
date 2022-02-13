
#include <SoftwareSerial.h>
SoftwareSerial BTserial(2, 3); // RX | TX
char c;
int pinA1 = 11;    
int pinA2 = 8;    
int pinB1 = 6;    
int pinB2 = 5;
int enA = 10;
int enB = 9;  

void setup() {
BTserial.begin(9600);
 
/*Serial.begin(9600);
 */
pinMode (pinA1, OUTPUT);
pinMode (pinA2, OUTPUT);
pinMode (pinB1, OUTPUT);
pinMode (pinB2, OUTPUT);  
digitalWrite(pinA1, LOW);
digitalWrite(pinA2, LOW);
digitalWrite(pinB1, LOW);
digitalWrite(pinB2, LOW);
}


void loop() {
if (BTserial.available())
    {  
        c = BTserial.read();
    }
if (c == 'f'){
  forward();   
}
else if (c == 'b'){
  reverse();
}
else if (c == 'l'){
  left();
}
else if (c == 'r'){
  right();
}
else if (c == 's'){
  stopcar();
}
else if (c == 'i') {
  roam();
}
else if (c == 'c') {
  circle();
}

delay(100);
}



void forward(){
analogWrite (enA, 255);
analogWrite (enB, 255);
digitalWrite (pinA1, LOW);
digitalWrite (pinA2, HIGH);
digitalWrite (pinB1, HIGH);
digitalWrite (pinB2, LOW);
}

void reverse(){
analogWrite (enA, 127);
analogWrite (enB, 127);
digitalWrite (pinA1, HIGH);
digitalWrite (pinA2, LOW);
digitalWrite (pinB1, LOW);
digitalWrite (pinB2, HIGH);
delay(2000);
  
}

void stopcar(){
  digitalWrite (pinA1, LOW);
  digitalWrite (pinA2, LOW);
  digitalWrite (pinB1, LOW);
  digitalWrite (pinB2, LOW);
}

void right(){
  digitalWrite (pinA1, HIGH);
  digitalWrite (pinA2, LOW);
  digitalWrite (pinB1, HIGH);
  digitalWrite (pinB2, LOW);
  analogWrite (enA, 200);
  analogWrite (enB, 100);
}

void left(){
  digitalWrite (pinA1, LOW);
  digitalWrite (pinA2, HIGH);
  digitalWrite (pinB1, LOW);
  digitalWrite (pinB2, HIGH);
  analogWrite (enA, 100);
  analogWrite (enB, 200);
}

void roam() {
  digitalWrite (pinA1, LOW);
  digitalWrite (pinA2, HIGH);
  digitalWrite (pinB1, HIGH);
  digitalWrite (pinB2, LOW);

  for (int i = 0; i < 256; i++) {
    analogWrite(enA, i);
    analogWrite(enB, i);
    delay(20);
  }

  for (int i = 255; i>=0; --i) {
    analogWrite(enA, i);
    analogWrite(enB, i);
    delay(20);
  }

 digitalWrite(pinA1, LOW);
 digitalWrite(pinA2, LOW);
 digitalWrite(pinB1, LOW);
 digitalWrite(pinB2, LOW);
}

void circle() {
  digitalWrite (pinA1, LOW);
  digitalWrite (pinA2, HIGH);
  digitalWrite (pinB1, LOW);
  digitalWrite (pinB2, HIGH);
  analogWrite(enA, 200);
  analogWrite(enB, 100);
}
