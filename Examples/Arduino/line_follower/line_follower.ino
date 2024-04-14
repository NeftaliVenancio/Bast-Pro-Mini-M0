int sensorValue,u,pwmi,pwmd;
float prom,pos,sensor,snum,posa,p,pa,d;

//ganancias modificables*********************
float kd=25,kp=35;

void setup() {

  pinMode(12,OUTPUT);//s0
  pinMode(11,OUTPUT);//s1 regleta de sensores
  pinMode(10,OUTPUT);//s2
  pinMode(13,OUTPUT);//s3

  pinMode(3,OUTPUT);//PWMA
  pinMode(4,OUTPUT);//AIN1 motor derecho
  pinMode(5,OUTPUT);//AIN2
  
  pinMode(7,OUTPUT);//BIN2
  pinMode(8,OUTPUT);//BIN1 motor izquierdo
  pinMode(9,OUTPUT);//PWMB
  
  //umbral modificable**********************
  prom=600;
  
}
void loop() {
  
  //velocidad modificable*********************
   pwmi=250;
   pwmd=250;
  
  
  sensor=0;
  snum=0;
  digitalWrite(12,LOW);digitalWrite(11,LOW);digitalWrite(10,LOW);digitalWrite(13,LOW);
  sensorValue = analogRead(A6);
  if(sensorValue>prom){
    sensor-=8;
    snum++;
  }
  digitalWrite(12,HIGH);digitalWrite(11,LOW);digitalWrite(10,LOW);digitalWrite(13,LOW);
  sensorValue = analogRead(A6);
  if(sensorValue>prom){
    sensor-=7;
    snum++;
  }
  digitalWrite(12,LOW);digitalWrite(11,HIGH);digitalWrite(10,LOW);digitalWrite(13,LOW);
  sensorValue = analogRead(A6);
  if(sensorValue>prom){
    sensor-=6;
    snum++;
  }
  digitalWrite(12,HIGH);digitalWrite(11,HIGH);digitalWrite(10,LOW);digitalWrite(13,LOW);
  sensorValue = analogRead(A6);
  if(sensorValue>prom){
    sensor-=5;
    snum++;
  }
  digitalWrite(12,LOW);digitalWrite(11,LOW);digitalWrite(10,HIGH);digitalWrite(13,LOW);
  sensorValue = analogRead(A6);
  if(sensorValue>prom){
    sensor-=4;
    snum++;
  }
  digitalWrite(12,HIGH);digitalWrite(11,LOW);digitalWrite(10,HIGH);digitalWrite(13,LOW);
  sensorValue = analogRead(A6);
  if(sensorValue>prom){
    sensor-=3;
    snum++;
  }
  digitalWrite(12,LOW);digitalWrite(11,HIGH);digitalWrite(10,HIGH);digitalWrite(13,LOW);
  sensorValue = analogRead(A6);
  if(sensorValue>prom){
    sensor-=2;
    snum++;
  }
  digitalWrite(12,HIGH);digitalWrite(11,HIGH);digitalWrite(10,HIGH);digitalWrite(13,LOW);
  sensorValue = analogRead(A6);
  if(sensorValue>prom){
    sensor-=1;
    snum++;
  }
  digitalWrite(12,LOW);digitalWrite(11,LOW);digitalWrite(10,LOW);digitalWrite(13,HIGH);
  sensorValue = analogRead(A6);
  if(sensorValue>prom){
    sensor+=1;
    snum++;
  }
  digitalWrite(12,HIGH);digitalWrite(11,LOW);digitalWrite(10,LOW);digitalWrite(13,HIGH);
  sensorValue = analogRead(A6);
  if(sensorValue>prom){
    sensor+=2;
    snum++;
  }
  digitalWrite(12,LOW);digitalWrite(11,HIGH);digitalWrite(10,LOW);digitalWrite(13,HIGH);
  sensorValue = analogRead(A6);
  if(sensorValue>prom){
    sensor+=3;
    snum++;
  }
  digitalWrite(12,HIGH);digitalWrite(11,HIGH);digitalWrite(10,LOW);digitalWrite(13,HIGH);
  sensorValue = analogRead(A6);
  if(sensorValue>prom){
    sensor+=4;
    snum++;
  }
  digitalWrite(12,LOW);digitalWrite(11,LOW);digitalWrite(10,HIGH);digitalWrite(13,HIGH);
  sensorValue = analogRead(A6);
  if(sensorValue>prom){
    sensor+=5;
    snum++;
  }
  digitalWrite(12,HIGH);digitalWrite(11,LOW);digitalWrite(10,HIGH);digitalWrite(13,HIGH);
  sensorValue = analogRead(A6);
  if(sensorValue>prom){
    sensor+=6;
    snum++;
  }
  digitalWrite(12,LOW);digitalWrite(11,HIGH);digitalWrite(10,HIGH);digitalWrite(13,HIGH);
  sensorValue = analogRead(A6);
  if(sensorValue>prom){
    sensor+=7;
    snum++;
  }
  digitalWrite(12,HIGH);digitalWrite(11,HIGH);digitalWrite(10,HIGH);digitalWrite(13,HIGH);
  sensorValue = analogRead(A6);
  if(sensorValue>prom){
    sensor+=8; 
    snum++;
  }
  if(snum>0){
    pos=sensor/snum;  
  }
  else{
    if(posa>0){
      pos=9;
    }
    if(posa<0){
      pos=-9;
    }
  }


  
  posa=pos;
  
  p=kp*pos;
  d=kd*(p-pa);
  u=p+d;

  
  pa=p;



  pwmi+=u;
  pwmd-=u;
  


  if(pwmi>255){
    pwmi=255;
  }  
  if(pwmi<-255){
    pwmi=-255;
  }
  if(pwmd>255){
    pwmd=255;
  }
  if(pwmd<-255){
    pwmd=-255;
  }

  if(pwmd>=0){
    digitalWrite(7,HIGH);
    digitalWrite(8,LOW);
  }
  if(pwmd<0){
    digitalWrite(7,LOW);
    digitalWrite(8,HIGH);
  }
  if(pwmi>=0){
    digitalWrite(4,HIGH);
    digitalWrite(5,LOW);
  }
  if(pwmi<0){
    digitalWrite(4,LOW);
    digitalWrite(5,HIGH);
  }
  if(analogRead(A7)>500){
    analogWrite(3,(abs(pwmi)));
    analogWrite(9,(abs(pwmd)));
  }
  else{
    analogWrite(3,0);
    analogWrite(9,0);
  }
}