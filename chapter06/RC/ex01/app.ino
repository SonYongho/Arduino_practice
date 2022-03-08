#include <Car.h>
#include <BtMiniCom.h>

// // 왼쪽
// int ENAPin = 3;    // enable 핀 설정
// int in1Pin = 5;    // in1 핀 설정
// int in2Pin = 4;    // in2 핀 설정

// // 오른쪽
// int ENBPin = 9;    // enable 핀 설정
// int in3Pin = 8;    // in1 핀 설정
// int in4Pin = 7;    // in2 핀 설정

void receive_msg(String msg);
BtMiniCom com(13, 12, receive_msg);
Car car(3, 5, 4, 9, 8, 7);

void receive_msg(String msg)
{
    if(msg == "F")
    {
        car.forward();
    }

    else if(msg == "B")
    {
        car.backward();
    }

    else if(msg == "L")
    {
        car.turn_left();
    }

    else if(msg == "R")
    {
        car.turn_right();
    }

    else if(msg == "S")
    {
        car.stop();
    }

}
void setup()
{
    com.init();
    car.stop();
}

void loop()
{
    com.run();
}
