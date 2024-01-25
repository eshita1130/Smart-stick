//Defines pin numbers
const int trigPin=9;
const int echoPin=10;
const int buzzer=13;

//Defines variables
long duration;
int distance;
int safetyDistance;

void setup()
{
  pinMode(trigPin, OUTPUT); //Sets the trigPin as an Output
  pinMode(echoPin, INPUT); //Sets the echoPIn as an Input
  pinMode(buzzer, OUTPUT); 
  Serial.begin(9600); //Starts the serial communication
}

void loop()
{
  digitalWrite(trigPin, LOW); //Clears the trigPin
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH); //Sets the trigPin on HIGH state for 10 microseconds
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration=pulseIn(echoPin, HIGH); //Reads the echoPin, returns the soundwave travel time microseconds

  distance=duration*0.034/2; //Calculating the distance

  safetyDistance=distance;
  if(safetyDistance<=150)
  {
    digitalWrite(buzzer, HIGH);
  }
  else{
    digitalWrite(buzzer, LOW);
  }
  Serial.print("Distance:"); //Prints the distance on the serial monitor
  Serial.println(distance);
}
