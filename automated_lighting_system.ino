
 #define trigPin 13
 #define echoPin 12
 #define trigPin2 8
 #define echoPin2 9
int relay = 10;
  
 #include <LiquidCrystal.h>
 const int rs =1, e = 2 , d4 = 3, d5 = 4, d6 = 5, d7 = 6 ;
LiquidCrystal lcd(rs, e, d4, d5, d6, d7); 
//LCD CIRCUIT
long i = 0;
int currentState = 0;
int previousState = 0;
int currentState2 = 0;
int previousState2 = 0;



void setup() {
 // initialize I/O pins
lcd.begin(16, 2);
//lcd.setCursor(0, 0);
lcd.print("Persons: ");
lcd.setCursor(8, 0);
if(i==0){
  lcd.print(i);
}

 pinMode(relay,OUTPUT);
 pinMode(trigPin, OUTPUT);
 pinMode(echoPin, INPUT);
 pinMode(trigPin2, OUTPUT);
 pinMode(echoPin2, INPUT);
  digitalWrite(relay, HIGH); 
}

void loop() {

 long duration, distance;
 digitalWrite(trigPin, LOW); 
 delayMicroseconds(2); 
 digitalWrite(trigPin, HIGH);
 delayMicroseconds(10); 
 digitalWrite(trigPin, LOW);
 duration = pulseIn(echoPin, HIGH);
 distance = (duration/2) / 29.1;
 long duration2, distance2;
 digitalWrite(trigPin2, LOW); 
 delayMicroseconds(2); 
 digitalWrite(trigPin2, HIGH);
 delayMicroseconds(10); 
 digitalWrite(trigPin2, LOW);
 duration2 = pulseIn(echoPin2, HIGH);
 distance2 = (duration2/2) / 29.1;
 
 //here
if (distance <= 10){
 currentState = 1;
 }
 else {
 currentState = 0;
 }
 //delay(100);
 if(currentState != previousState){
 while(currentState == 1) {
 long duration2, distance2;
 digitalWrite(trigPin2, LOW); 
 delayMicroseconds(2); 
 digitalWrite(trigPin2, HIGH);
 delayMicroseconds(10); 
 digitalWrite(trigPin2, LOW);
 duration2 = pulseIn(echoPin2, HIGH);
 distance2 = (duration2/2) / 29.1;
 if (distance2 <= 10){
 currentState2 = 1;
 }
 else {
 currentState2 = 0;
 }
 //delay(100);
 if(currentState2 != previousState2){
 if(currentState2 == 1) {
  
 i = i+1;
 if(i>0 && i<10){
  lcd.setCursor(8, 0);
     lcd.print("0");
     
   lcd.setCursor(9, 0);
     lcd.print(i);

 }
 if(i>9){
   lcd.setCursor(8, 0);
    lcd.print(i);   
 }
    
 
  delay(1000);

 }
 
 return;
 
   }
  }

 } 
 
 // object exit from the system 
if (distance2 <= 10){
 currentState2 = 1;
 }
 else {
 currentState2 = 0;
 }
 delay(100);
 if(currentState2 != previousState2){
 while (currentState2 == 1) {
 long duration, distance;
 digitalWrite(trigPin, LOW); 
 delayMicroseconds(2); 
 digitalWrite(trigPin, HIGH);
 delayMicroseconds(10); 
 digitalWrite(trigPin, LOW);
 duration = pulseIn(echoPin, HIGH);
 distance = (duration/2) / 29.1;
 if (distance <= 10){
 currentState = 1;
 }
 else {
 currentState = 0;
 }
 delay(100);
 if(currentState != previousState){
 if(currentState == 1) {
    
  if(i!=0)
{  
   i = i-1; }
if(i>=0 && i<10){
   lcd.setCursor(8, 0);
     lcd.print("0");
  
   lcd.setCursor(9, 0);
     lcd.print(i);

 }
 if(i>9){
   lcd.setCursor(8, 0);
    lcd.print(i);   
 }


   
  delay(1000);
 
 
 }
 
 return;
   }
  }
 }
if(i>0){
digitalWrite(relay, LOW);  
}
if(i==0){
  digitalWrite(relay, HIGH); 
}





 }
 