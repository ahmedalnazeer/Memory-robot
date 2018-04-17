#include <Servo.h> 
 
  int start = 3 ;
  int trigPin = 13;
  int echoPin = 12;
 
  int MotorR = 5; 
  int MotorL = 3;
     
  int sag=0 ;
  int sol=0 ;
  int pos = 0;
  int i = 0 ;

  String yon[3] ;
  int a = 0 ;
 unsigned long zaman[3];  
  int b = 0 ;
double time1 ;
double time2 ;

  Servo myservo;  

  void setup() {
  myservo.attach(11);
  Serial.begin(9600);
  pinMode(echoPin, INPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(MotorL, OUTPUT); 
  pinMode(MotorR, OUTPUT);
      
  }
  

  void loop() {
    
    
    myservo.write(90);
    
    long duration, distance;
    digitalWrite(trigPin, LOW);  
    delayMicroseconds(2); 
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10); 
    digitalWrite(trigPin, LOW);
    duration = pulseIn(echoPin, HIGH);
    distance = (duration/2) / 29.1;

if (i>=start)
{
  dur () ; 
  delay(5000);
  for (int say=0 ; say < start ;say++){
  ileri();
  delay(zaman[start-1-say]); 
  dur () ; 
  delay(1000);
  if (yon [start-1-say]== "sol" ) { SOL();  
           delay(900);
           dur();
           delay (500); }
  else { SAG();  
           delay(900);
           dur();
           delay (500);}}}
  
  else if (distance > 20 ) {
        ileri();}

  else {
    
    dur();
    myservo.write(0);
    delay (500);
    duration, distance;
    digitalWrite(trigPin, LOW); 
    delayMicroseconds(2); 
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10); 
    digitalWrite(trigPin, LOW);
    duration = pulseIn(echoPin, HIGH);
    distance = (duration/2) / 29.1;
    sag=distance ;
    delay (100);

    
    myservo.write(180);
    delay (500);
    duration, distance;
    digitalWrite(trigPin, LOW);  
    delayMicroseconds(2); 
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10); 
    digitalWrite(trigPin, LOW);
    duration = pulseIn(echoPin, HIGH);
    distance = (duration/2) / 29.1;
    sol=distance ;
    delay (100);
   
   
    myservo.write(90);

    
        if  (sol > sag){
      
          
          SOL();  
          delay(900);
          dur();
          delay (500);
          yon[a]="sol";
          }
        else {
        
           SAG();  
           delay(900);
           dur();
           delay (500);
           yon[a]="sag";
           }
           i= i+1 ;
           time1 = millis () ; 
           Serial.println (yon[a]);
           time2 = ((time1/(b+1))-3000) ;
           zaman[b]=time2;
           Serial.println (zaman[b]);
           a++ ;
           b++ ;
           }       
   
   delay(500);


  }

void ileri(){  
  analogWrite(MotorR, 100); 
  analogWrite(MotorL, 100); 
}
void dur(){ 
  analogWrite(MotorR, 0);
  analogWrite(MotorL, 0); 
}

void SAG(){
  analogWrite(MotorR, 0); 
  analogWrite(MotorL, 100);
}


void SOL(){ 
  analogWrite(MotorR, 100);
  analogWrite(MotorL, 0); 
}


