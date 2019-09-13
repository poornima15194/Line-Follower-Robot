#define S1 8      // left sensor
#define S2 9      // right sensor
                             
#define LM1 4       // left motor
#define RM1 6       // right motor

int IR1,IR2;

void setup()
{
  pinMode(S1, INPUT);
  pinMode(S2, INPUT);
  pinMode(LM1, OUTPUT);
  pinMode(RM1, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  IR1=digitalRead(S1);
  IR2=digitalRead(S2);
  //Serial.println(IR1);
  if(IR1==HIGH && IR2==HIGH)  // Move Forward   
  {
    Serial.println("Forward");
    digitalWrite(LM1, LOW);
    digitalWrite(RM1, LOW);
  }
  
 if(IR1==HIGH && IR2==LOW)     // turn right 
  {
    digitalWrite(LM1, LOW);
    digitalWrite(RM1, HIGH);
  }
  if(IR1==LOW && IR2==HIGH)     // Turn left
  {
    digitalWrite(LM1, HIGH);
    digitalWrite(RM1, LOW);
  }
  if(IR1==LOW && IR2==LOW)     // stop
  {
    digitalWrite(LM1, HIGH);
    digitalWrite(RM1, HIGH);
  }
}
