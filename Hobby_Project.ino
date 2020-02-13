
#include <SoftwareSerial.h>

SoftwareSerial nodemcu(0,1);

int parking1_slot1_ir_s = 10; // parking slot1 infrared sensor connected with pin number 4 of arduino
int parking1_slot2_ir_s = 11;


int parking2_slot1_ir_s = 12;
int parking2_slot2_ir_s = 13;

String sensor1; 
String sensor2; 
String sensor3; 
String sensor4; 

int gr1=2;
int red1=3;

int gr2=4;
int red2=5;

int gr3=6;
int red3=7;

int gr4=8;
int red4=9;



String cdata =""; // complete data, consisting of sensors values

void setup()
{
Serial.begin(9600);
nodemcu.begin(9600);
 
pinMode(parking1_slot1_ir_s, INPUT);
pinMode(parking1_slot2_ir_s, INPUT);


pinMode(parking2_slot1_ir_s, INPUT);
pinMode(parking2_slot2_ir_s, INPUT);
}

void loop()
{
  
p1slot1(); 
p1slot2();


p2slot1();
p2slot2();


  
  
   cdata = cdata + sensor1 +"," + sensor2 + ","+ sensor3 +","+ sensor4 + "," ; // comma will be used a delimeter
   Serial.println(cdata); 
   nodemcu.println(cdata);
   delay(2000); // 2 seconds
   cdata = ""; 
digitalWrite(parking1_slot1_ir_s, HIGH); 
digitalWrite(parking1_slot2_ir_s, HIGH); 


digitalWrite(parking2_slot1_ir_s, HIGH);
digitalWrite(parking2_slot2_ir_s, HIGH);

}

//P1slot1 is a user defined function, it has no return type and it doesn not take any argument as the input.  if there is a car infront of the sensor it gives digital logic 0, and if no car then it give digital logic 1, depending on this, then we store p1s1on or p1s1off.  The same mechanism is used for all the other infrared sensors.

void p1slot1() // parkng 1 slot1
{
  if( digitalRead(parking1_slot1_ir_s) == LOW) 
  {
  sensor1 = "p1s1on"; // parking1 slot1 
 delay(200);
digitalWrite(gr1,0);
 digitalWrite(red1,1); 
  } 
if( digitalRead(parking1_slot1_ir_s) == HIGH)
{
  sensor1 = "p1s1off";  
 delay(200); 
 digitalWrite(gr1,1);
 digitalWrite(red1,0);  
}

}

void p1slot2() // parking 1 slot2
{
  if( digitalRead(parking1_slot2_ir_s) == LOW) 
  {
  sensor2 = "p1s2on"; 
  delay(200);
 digitalWrite(gr2,0);
 digitalWrite(red2,1); 
    
  }
if( digitalRead(parking1_slot2_ir_s) == HIGH)  
  {
  sensor2 = "p1s2off";  
 delay(200);
 digitalWrite(gr2,1);
 digitalWrite(red2,0);
  } 
}




// now for parking 2

void p2slot1() // parking 2 slot1
{
  if( digitalRead(parking2_slot1_ir_s) == LOW) 
  {
  sensor3 = "p2s1on"; 
  delay(200); 
   digitalWrite(gr3,0);
 digitalWrite(red3,1);
  }
if( digitalRead(parking2_slot1_ir_s) == HIGH)  
  {
  sensor3 = "p2s1off";  
 delay(200);
  digitalWrite(gr3,1);
 digitalWrite(red3,0);
  } 
}


void p2slot2() // parking 2 slot2
{
  if( digitalRead(parking2_slot2_ir_s) == LOW) 
  {
  sensor4 = "p2s2on"; 
  delay(200); 
   digitalWrite(gr4,0);
 digitalWrite(red4,1);
  }
if( digitalRead(parking2_slot2_ir_s) == HIGH)  
  {
  sensor4 = "p2s2off";  
 delay(200);
  digitalWrite(gr4,1);
 digitalWrite(red4,0);
  } 
}





