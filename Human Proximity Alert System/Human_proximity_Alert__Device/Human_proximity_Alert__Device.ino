

const int echoPin = 4; // Echo Pin of Ultrasonic Sensor
const int pingPin = 5;// Trigger Pin of Ultrasonic Sensor
const int buzzer= 12;
const int LED = 6;

void setup() 
{
  Serial.begin(9600); // Starting Serial Communication
  pinMode(pingPin, OUTPUT); // initialising pin 7 as output
  pinMode(echoPin, INPUT); // initialising pin 6 as input
  pinMode(buzzer,OUTPUT);
  pinMode(LED,OUTPUT);
}

void loop()
{
  long duration, inches, cm;
  
  digitalWrite(pingPin, LOW);
  delayMicroseconds(2);
  
  digitalWrite(pingPin, HIGH);
  delayMicroseconds(10);
  
  digitalWrite(pingPin, LOW);
 
  duration = pulseIn(echoPin, HIGH); // using pulsin function to determine total time
  inches = microsecondsToInches(duration); // calling method
  cm = microsecondsToCentimeters(duration); // calling method
  
  Serial.print(inches);
  Serial.print("in, ");
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();
  
  if(inches<=30){
    digitalWrite(buzzer, HIGH);
    digitalWrite(LED, HIGH);
  }
  else{
    digitalWrite(buzzer, LOW);
    digitalWrite(LED, LOW);
  }
   
  delay(100);

 
}

long microsecondsToInches(long microseconds)            // method to covert microsec to inches 
{
 return microseconds / 74 / 2;
}

long microsecondsToCentimeters(long microseconds)      // method to covert microsec to centimeters
{
   return microseconds / 29 / 2;
}
