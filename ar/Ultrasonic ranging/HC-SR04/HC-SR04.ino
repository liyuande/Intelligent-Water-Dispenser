float cm;
int TrigPin = 2;//定义Trig为接口2
int EchoPin = 3;//定义Echo接口为3
void setup() {
  Serial.begin(9600);//定义波特率为9600
  pinMode(TrigPin,OUTPUT);//设置2为输出接口
  pinMode(EchoPin,INPUT);//设置3为输入接口
}

void loop() {
  digitalWrite(TrigPin,LOW);//将2置为低电平
  delay(2);                 //延时
  digitalWrite(TrigPin,HIGH);//将2置为高电平
  delay(10);                 //延时
  digitalWrite(TrigPin,LOW);//将2置为低电平
  cm = pulseIn(EchoPin,HIGH) / 58.0;//计算距离
  cm = (int(cm * 100.0)) / 100.0;//保留两位
  Serial.print(cm);//输出数据
  Serial.println();
  delay(1000);
}
