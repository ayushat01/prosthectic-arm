#include <Servo.h> 
// #define THRESHOLD_1 100 //In order to determine the state of the hand (opened/closed)
// #define THRESHOLD_2 400 //In order to determine the state of the hand (opened/closed)
#define EMGPIN A0 //Analog pin connected to Muscle Sensor V3 Board
#define led D7;
int ma=0;
int ma2=0;
int mi=1023;
int thre=0;
int thre1=0;
int done=0;
int ne=0;
int fl=0;
Servo servo;// servo object representing the MG 996R servo
Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;
int count=0;
int flag=0;
int count1=0;
int count2=0;
void setup() {
  Serial.begin(115200);
  pinMode(7,OUTPUT);
  servo.attach(9); // servo is wired to Arduino on digital pin 3
  servo1.attach(10);
servo2.attach(11);
servo3.attach(12);
servo4.attach(13);  
}
int intial_pos=0;
void loop() {
  if(ne==0){
    servo.write(0);
    servo1.write(180);
   servo2.write(0);
   servo3.write(0);
   servo4.write(0);
   ne=1;
  }
  if(fl==0){
    int i=0;
    digitalWrite(7,HIGH);
    while(i<100){
    int value = analogRead(EMGPIN);
     Serial.print("Value=");
 Serial.print(value);
   Serial.print(" count1=");
  Serial.print(count1);
  Serial.print("  count=");
  Serial.print(count);
  Serial.print("  count2=");
  Serial.println(count2);
 delay(100);
 mi=min(mi,value);
 ma=max(ma,value);
 ma2=max(mi+30,ma2);
 thre=(mi+ma)/2;
 thre1=(mi+ma2)/2;
 i++;
    }
      Serial.print("Done Uploading");
      digitalWrite(7,LOW);
    fl=1;
  }
int value = analogRead(EMGPIN); //Sampling analog signal
 Serial.print("Value=");
 Serial.print(value);
   Serial.print(" count1=");
  Serial.print(count1);
  Serial.print("  count=");
  Serial.print(count);
  Serial.print("  count2=");
  Serial.print(count2);
  Serial.print(" done ");
  Serial.println(done);
 delay(100);
 mi=min(mi,value);
 ma=max(ma,value);
 ma2=max(mi+30,ma2);
 thre=(mi+ma)/2;
 thre1=(mi+ma2)/2;
 if(value>thre1){
  count2++;
 }
 if(count2>=10){
   servo1.write(20);
   servo2.write(160);
   servo3.write(160);
   servo4.write(160);
//  delay(1000);
  count2=0;
 }
 
 if(value>thre) 
{
    count ++;
}
if(count>10){
//  Serial.print("Done");
//  Serial,print(" count1=");
//  Serial.print(count1);
//  Serial.print("  count=");
//  Serial.print(count);
//  Serial.print("  count2=");
//  Serial.println(count2);
  servo.write(160);
  done=1;
//  delay(1000);
  count =0;
}
 if(value<thre1) 
{
    count1 ++;
}
if(count1>10){
  // servo.attach(9);
  // servo1.attach(10);
  // servo1.write(0);
  // servo.write(0);
  servo.write(0);
     servo1.write(180);
   servo2.write(0);
   servo3.write(0);
   servo4.write(0);
   if(done==1){       
   servo2.write(160);
   delay(500);
    servo1.write(20);
    delay(500);
   servo3.write(160);
   delay(500);
   servo4.write(160);
   delay(500);
    servo1.write(180);
    delay(500);
   servo2.write(0);
   delay(500);
   servo3.write(0);
   delay(500);
   servo4.write(0);
   done=0;
   }
  count1=0;
}
}
