#include <Analog.h>
#include <Servo.h>
#include <Minicom.h>

MiniCom com;
Analog a_value(A0, 180, 0);
Servo myServo;

const int servo_pin = 5;
void check()
{
  int angle = a_value.read();
  myServo.write(angle);
  com.print(1, "Angle:", angle);
}
void setup()
{
  com.init();
  com.print(0, "Servo Test2");
  myServo.attach(servo_pin);
  com.setInterval(100, check);
}
void loop()
{
  com.run();
}