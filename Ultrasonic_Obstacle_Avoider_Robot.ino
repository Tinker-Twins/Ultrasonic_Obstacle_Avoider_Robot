/*Obstacle Avoiding Robot Program*/

int trig = 13;    // Connect Trigger Pin of Ultrasonic Sensor to Pin Number 13 of Arduino UNO
int echo = 12;    // Connect Echo Pin of Ultrasonic Sensor to Pin Number 12 of Arduino UNO
int motorL= 11;   // Connect Left Motor to Pin Number 11 of Arduino UNO
int motorR=10;    // Connect Right Motor to Pin Number 10 of Arduino UNO
void setup()
{
Serial.begin(9600);
pinMode(trig, OUTPUT);
pinMode(echo, INPUT);
pinMode(motorL, OUTPUT);
pinMode(motorR, OUTPUT);
}
void loop()
{
long t = 0, h = 0;              
digitalWrite(trig, LOW);        // Transmitting Pulse
delayMicroseconds(2);
digitalWrite(trig, HIGH);
delayMicroseconds(10);
digitalWrite(trig, LOW);        
t = pulseIn(echo, HIGH);        // Waiting for Pulse
h = (t/2) / 29.1;               // Calculating Distance
Serial.print(h);                // Sending to Computer
Serial.print("\n");             // Serial.print(" cm\n")
digitalWrite(motorL,HIGH);
digitalWrite(motorR,HIGH);      
if (h<=10)                      // Condition for Motors
{
digitalWrite(motorL,HIGH);      // Turning Right Motor
digitalWrite(motorR,LOW);
delay(1500);                    // Alter for Accurate Turn After Detecting Obstacle
}
}
