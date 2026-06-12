const int sensor[8]= {2,3,4,5,6,7,8,9};
const int weight[8]={-7,-5,-3,-1,1,3,5,7};

#define ENA  10
#define ENB  11

const int IN1 = A0;   //PWM
const int IN2 = A1;    //PWM
const int IN3 = 12;
const int IN4 = 13;


void forward(){
  analogWrite(ENA,255);
  analogWrite(ENB,255);

  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,HIGH);
  digitalWrite(IN4,LOW);

}

void reverse(){
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,HIGH);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,HIGH);
  
}

void left(){
  analogWrite(ENA,255);
  analogWrite(ENB,100);

  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,HIGH);
  digitalWrite(IN4,LOW);

}

void right(){
  analogWrite(ENA,100);
  analogWrite(ENB,255);

  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,HIGH);
  digitalWrite(IN4,LOW);
}


void setup(){
  Serial.begin(9600);
  for(int i=0;i<8;i++){
    pinMode(sensor[i],INPUT);
  }
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  pinMode(ENA, OUTPUT);     //control speed
  pinMode(ENB, OUTPUT);     // control speed

}


void loop(){
  int count = 0;
  int sum = 0;
  for(int i =0; i<8; i++){
    int value = digitalRead(sensor[i]);
    Serial.println(value);
    if (value ==1){            //blackline detected
      sum=sum + weight[i];
      count++;
    }
  }
  if (count > 0){
  int position = sum/count;
  Serial.print("Position :");
  Serial.println(position);
  

  if(position > 0){
    right();

  }
  else if(position <0){
    left();
  }
  else{
    forward();
  }
  delay(100);
  }
}



