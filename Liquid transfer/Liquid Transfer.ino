#include <LiquidCrystal.h>
 
#define trigger 10
#define echo 11
#define motor 8
#define buzzer 12
 
LiquidCrystal lcd(2,3,4,5,6,7);
 
float time=0,distance=0;
int temp=0; 

void setup() {
 lcd.begin(16,2);
 pinMode(trigger,OUTPUT);
 pinMode(echo,INPUT);
 pinMode(motor, OUTPUT);
 pinMode(buzzer, OUTPUT);
 lcd.print("  Water Level ");
 lcd.setCursor(0,1);
 lcd.print("   Indicator  ");
 delay(2000);

}

void loop() {
 digitalWrite(trigger,LOW);
 delayMicroseconds(2);
 digitalWrite(trigger,HIGH);
 delayMicroseconds(10);
 digitalWrite(trigger,LOW);
 delayMicroseconds(2);
 time=pulseIn(echo,HIGH);
 distance=time*340/20000;
 
 lcd.clear();
 lcd.print("Water Space In  ");
 lcd.setCursor(0,1);
 lcd.print("Tank is: ");
 lcd.print(distance);
 lcd.print("Cm");
 delay(2000);

  if(distance<12 && temp==0)
 {
     digitalWrite(motor, LOW);
     digitalWrite(buzzer, HIGH);
     lcd.clear();
     lcd.print("Water Tank Full ");
     lcd.setCursor(0,1);
     lcd.print("Motor Turned OFF");
     delay(2000);
     digitalWrite(buzzer, LOW);
     delay(3000);
     temp=1;
 }

  else if(distance<12 && temp==1)
 {
     digitalWrite(motor, LOW);
     lcd.clear();
     lcd.print("Water Tank Full ");
     lcd.setCursor(0,1);
     lcd.print("Motor Turned OFF");
     delay(5000);
 }

 else if(distance>13)
 {
   digitalWrite(motor, HIGH);
   lcd.clear();
   lcd.print("LOW Water Level");
   lcd.setCursor(0,1);
   digitalWrite(buzzer, HIGH);
   delay(1000);
   digitalWrite(buzzer, LOW);
   delay(1000);
   digitalWrite(buzzer, HIGH);
   delay(1000);
   digitalWrite(buzzer, LOW);
   lcd.print("Motor Turned ON");
   delay(5000);
   temp=0;
 }
}
