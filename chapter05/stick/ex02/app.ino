// 조이스틱 상태 LCD 모니터 출력하기
#include <Minicom.h>
#include <Analog.h>
#include <Button.h>
#include <Servo.h>

MiniCom com;
Servo servo;

Analog x(A0, 180, 0);    // 서브모터 방향제어
Analog y(A1, 0, 180);    // 서브모터 방향제어

// Analog x(A0, -100, 100); // rc 카의 속도 및 좌우 방향제어
// Analog y(A1, 100, -100); // rc 카의 속도 및 상하 방향제어

Button z(A2);

void servo_lock()
{
    com.print(0, "LOCK");
}

void servo_unlock()
{
    com.print(0, "[[Joystick]]");
}

void check()
{
    int dx, dy;
    boolean sw;

    dx = x.read();
    dy = y.read();
    sw = z.read();
    servo.write(dx);

    char buf[17];
    sprintf(buf, "%d, %d [%d]", dx, dy, sw);
    com.print(1, buf);
    

    if (sw == 1){
        servo_lock();
    }
    else
    {
        servo_unlock();
    }
}

void setup()
{
    com.init();
    com.setInterval(100, check);
    com.print(0, "[[Joystick]]");
    servo.attach(3);
    servo.write(0);
}

void loop()
{
    com.run();
}