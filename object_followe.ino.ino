const int trigPin = A0;
const int echoPin = A1;

void setup()
{
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  
  pinMode(8, OUTPUT); //pwm for 2,3
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);

  pinMode(9, OUTPUT);// pwm for 4,5
  pinMode(4, OUTPUT);
  
  pinMode(5, OUTPUT);
  
  Serial.begin(9600);
}

void loop()
{
  
digitalWrite(trigPin, LOW);
delayMicroseconds(2);

// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);

// Reads the echoPin, returns the sound wave travel time in microseconds
int duration = pulseIn(echoPin, HIGH);

// Calculating the distance
int distance= duration*0.034/2;

Serial.println(distance);

if (distance <=35)
{
  backword(250, 250);
}
else if (distance <=35 && distance >=40)
{
  forward(0, 0);
}
else if(distance <=80 && distance >= 40)
{
forward(250,250);
}
else
forward(0,0);
}

void forward(int pwma, int pwmb)
{
  analogWrite(8, pwma);
  digitalWrite(2, HIGH);
  digitalWrite(3, LOW);

  analogWrite(9, pwmb);
  digitalWrite(4, HIGH);
  digitalWrite(5, LOW);
}
void backword(int pwma, int pwmb)
{
  analogWrite(8, pwma);
  digitalWrite(2, LOW);
  digitalWrite(3, HIGH);

  analogWrite(9, pwmb);
  digitalWrite(4, LOW);
  digitalWrite(5, HIGH);
}

