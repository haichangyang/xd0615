/*
  Calibration

 Demonstrates one technique for calibrating sensor input.  The
 sensor readings during the first five seconds of the sketch
 execution define the minimum and maximum of expected values
 attached to the sensor pin.

 The sensor minimum and maximum initial values may seem backwards.
 Initially, you set the minimum high and listen for anything
 lower, saving it as the new minimum. Likewise, you set the
 maximum low and listen for anything higher as the new maximum.

 The circuit:
 * Analog sensor (potentiometer will do) attached to analog input 0
 * LED attached from digital pin 9 to ground

 created 29 Oct 2008
 By David A Mellis
 modified 30 Aug 2011
 By Tom Igoe

 http://www.arduino.cc/en/Tutorial/Calibration

 This example code is in the public domain.

 */

// These constants won't change:
const int sensorPin = A0;    // 传感器连接到的针脚A0
const int ledPin = 9;        // LED连接到的引脚9

// variables:
int sensorValue = 0;         // 定义传感器值为0
int sensorMin = 1023;        // 定义最小传感器值为1023
int sensorMax = 0;           // 定义最大传感器值为0；


void setup() {
  // 打开LED指示校准周期开始：
  pinMode(13, OUTPUT);//定义13为输出引脚
  digitalWrite(13, HIGH);//定义引脚13输出高电平

  // 在前5秒内校准
  while (millis() < 5000) {
    sensorValue = analogRead(sensorPin);

    // 记录最大传感器值
    if (sensorValue > sensorMax) {
      sensorMax = sensorValue;
    }

    // 记录最小传感器值
    if (sensorValue < sensorMin) {
      sensorMin = sensorValue;
    }
  }

  // 发出校准周期结束的信
  digitalWrite(13, LOW);//引脚13输出低电平
}

void loop() {
  // 读取传感器：
  sensorValue = analogRead(sensorPin);

  // 对传感器读数进行校准
  sensorValue = map(sensorValue, sensorMin, sensorMax, 0, 255);

  // 如果传感器值超出校准过程中看到的范围
  sensorValue = constrain(sensorValue, 0, 255);

  // 使用校准值使LED变暗：
  analogWrite(ledPin, sensorValue);
}  
