  #include <Servo.h>



#define buzz1 6
#define motor1 5
#define motor2 4
#define trigPin 10
#define echoPin 11



void setup() {
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT);
  pinMode(buzz1, OUTPUT);
  pinMode(motor1, OUTPUT);
  pinMode(motor2, OUTPUT);
  
}




void loop() {  
  float duration, distance;
  float speed;
  
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  digitalWrite(buzz1, LOW);
  digitalWrite(motor1, LOW);
  digitalWrite(motor2, LOW);
  
  duration = pulseIn(echoPin, HIGH);
  speed = 331.4 ;
  distance = (duration / 2) * (speed / 10000);
  
  if (distance >=100 || distance <= 2)
    {
    Serial.print("Distance = ");
    Serial.println("Out of range");
    }
  
  else {
    Serial.print("Distance = ");
    Serial.print(distance);
    Serial.println(" cm");
    delay(1000);
      if(distance <= 45 || distance>=5)
      {
      Serial.print("Distance = ");
      Serial.println("Object detected");

      digitalWrite(buzz1, HIGH);
       digitalWrite(motor1, HIGH);
       digitalWrite(motor2, HIGH);

       Serial.print("Buzzer ON");
      Serial.println("Motors ON");
      

       delay(3000);
       
       digitalWrite(buzz1, LOW);
       digitalWrite(motor1, LOW);
       digitalWrite(motor2, LOW);

       Serial.print("Buzzer OFF");
      Serial.println("Motors OFF");


       
       }
    }
  
  }
