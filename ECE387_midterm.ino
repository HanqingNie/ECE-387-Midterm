//pins and variables for voltage detect
float voltage0=0;
float voltage1=0;
float voltage2=0;
float voltage3=0;
int sensorValue0=0;
int sensorValue1=0;
int sensorValue2=0;
int sensorValue3=0;
int analogPin0=A0;
int analogPin1=A1;
int analogPin2=A2;
int analogPin3=A3;
int ledValue0=0;
int ledValue1=0;
int ledValue2=0;
int ledValue3=0;

unsigned long currentTime;
unsigned long currentTime2;
unsigned long startTime=0;

int intervaltime=1000;

//pins and variable for leds
int led0=2;
int led1=4;
int led2=7;
int led3=8;
float randNumber0=0;
float randNumber1=0;
float randNumber2=0;
float randNumber3=0;

int score=0;

void setup()
{
  Serial.begin(9600);
  pinMode(analogPin0,INPUT);
  pinMode(analogPin1,INPUT);
  pinMode(analogPin2,INPUT);
  pinMode(analogPin3,INPUT);
  
  randomSeed(analogRead(0));
  randomSeed(analogRead(1));
  randomSeed(analogRead(2));
  randomSeed(analogRead(3));
  pinMode(led0,OUTPUT);
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);

  unsigned long currentTime=millis();
  
}

void loop()
{ 
  //detect if the botton pressed
  sensorValue0=analogRead(analogPin0);
  voltage0=sensorValue0*5/1023;
  
  sensorValue1=analogRead(analogPin1);
  voltage1=sensorValue1*5/1023;
  
  sensorValue2=analogRead(analogPin2);
  voltage2=sensorValue2*5/1023;
  
  sensorValue3=analogRead(analogPin3);
  voltage3=sensorValue3*5/1023;

//detcct if the user hit the right botton
  if((ledValue0==1)&&(voltage0>1))
  {
    digitalWrite(led0,LOW);
    ledValue0=0;
    score=score+2;
  }

  if((ledValue1==1)&&(voltage1>1))
  {
    digitalWrite(led1,LOW);
    ledValue1=0;
    score=score+2;
  }

  if((ledValue2==1)&&(voltage2>1))
  {
    digitalWrite(led2,LOW);
    ledValue2=0;
    score=score+2;
  }

  if((ledValue3==1)&&(voltage3>1))
  {
    digitalWrite(led3,LOW);
    ledValue3=0;
    score=score+2;
  }
  currentTime= millis();
  if(currentTime-startTime>2000)
  {
    startTime=currentTime;
    someLightON();
  }
  currentTime2=millis();
  if(currentTime2-startTime>1000)
  {
    Serial.println(score);
    allOFF();
  }
  
} 

void someLightON()
{
  //random number to control leds
  randNumber0=random(10);
  randNumber1=random(10);
  randNumber2=random(10);
  randNumber3=random(10);

  //decide if the leds light
  if(randNumber0>5)
  {
    digitalWrite(led0,HIGH);
    ledValue0=1;
    score=score-1;
  }      
  if(randNumber1>5)
  {
    digitalWrite(led1,HIGH);
    ledValue1=1;
    score=score-1;
  }
  if(randNumber2>5)
  {
    digitalWrite(led2,HIGH);
    ledValue2=1;
    score=score-1;
  }
  if(randNumber3>5)
  {
    digitalWrite(led3,HIGH);
    ledValue3=1;
    score=score-1;
  }
}

void allOFF()
{
  digitalWrite(led0,LOW);
  ledValue0=0;
  digitalWrite(led1,LOW);
  ledValue1=0;
  digitalWrite(led2,LOW);
  ledValue2=0;
  digitalWrite(led3,LOW);
  ledValue3=0;
  delay(1000);
}

