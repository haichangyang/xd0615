#include <MsTimer2.h>     //定时器库的头文件
int income=0;
//中断服务程序
void onTimer()
{
  
  digitalWrite(6,LOW);
  digitalWrite(7,HIGH);
  digitalWrite(8,HIGH);
  digitalWrite(2,income&0x1);
  digitalWrite(3,(income>>1)&0x1);
  digitalWrite(4,(income>>2)&0x1);
  digitalWrite(5,(income>>3)&0x1);
  delay(10);
  income++;
  if(income==10) income=0;
}
 
void setup()
{
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  Serial.begin(9600); //初始化串口
  
  MsTimer2::set(1000, onTimer); //设置中断，每1000ms进入一次中断服务程序 onTimer()
  MsTimer2::start(); //开始计时
}
 
void loop()
{
  
}
