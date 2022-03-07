// 초음파 센서에 따라 서브모터 열림/닫힘

#include <Minicom.h>
#include <Ultra.h>
#include <Servo.h>

MiniCom com;
Ultra ultra(5,6);
Servo myServo;

const int servo_pin = 9;

void notice_in() {
    com.print(1, "NOTICE IN");
    myServo.write(90);
}

void notice_out() {
    com.print(1, "NOTICE_OUT");
    myServo.write(0);
}

void setup() {
    com.init();
    com.print(0, "[[Distance]]");
    ultra.setThreshold(40, notice_in, notice_out);
    myServo.attach(servo_pin);
}

void loop() {
    com.run();
    ultra.run();
}