#include <BtMiniCom.h>
#include <Servo.h>

void receive_msg(String msg);
BtMiniCom com(13, 12, receive_msg);
int count = 0;

Servo myServo;

const int servo_pin = 3;

void receive_msg(String msg)
{
    // char buf[17];
    // sprintf(buf, "%d)%s", ++count, msg.c_str());
    // com.print(1, buf);
    // com.send("input value: " + msg);

    if (msg == "open")
    {
        myServo.write(90);
    }
    if (msg == "close")
    {
        myServo.write(0);
    }
    com.print(1, msg.c_str());
}
void setup()
{
    com.init();
    com.print(0, "[[Bluetooth]]");
    myServo.attach(servo_pin);
    myServo.write(0);
}
void loop()
{
    com.run();
}