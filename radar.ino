#include <Servo.h>  //servo library

//defining Trig and Echo pins of the Ultrasonic Sensor
const int trigPin = 10;
const int echoPin = 11;

long duration;
int distance;

Servo myServo; //servo object for controlling the servo motor
void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
  myServo.attach(12); //motor attached pin
}
void loop() {
  for(int i=15;i<=165;i++){  //rotates the servo motor from 15 to 165 degrees
  myServo.write(i);
  delay(30);
  distance = calculateDistance();
  
  Serial.print(i); //sends the current degree into the Serial Port
  Serial.print(","); //sends additional character right next to the previous value needed later in the Processing IDE for indexing
  Serial.print(distance); //sends the distance value into the Serial Port
  Serial.print("."); //sends additional character right next to the previous value needed later in the Processing IDE for indexing
  }
  
  for(int i=165;i>15;i--){  //repeating the previous lines from 165 to 15 degrees
  myServo.write(i);
  delay(30);
  distance = calculateDistance();
  Serial.print(i);
  Serial.print(",");
  Serial.print(distance);
  Serial.print(".");
  }
}

//calculating the distance measured by the Ultrasonic sensor
int calculateDistance(){ 
  
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH); 
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH); // Reads the echoPin, returns the sound wave travel time in microseconds
  distance= duration*0.034/2;
  return distance;
}