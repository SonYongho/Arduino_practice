// 버튼을 누르면 서브모터를 제어하여 문을 열어줌 90 or 180
// 3초 후에 자동으로 닫힘 -> setTimeout
// 3초 전에 누르면 그 시점에서 3초 후에 닫힘 -> restartTimer
// LCD에 현재 문의 상태(open/close) 출력

#include <Servo.h>
#include <Minicom.h>
#include <Button.h>

MiniCom com;
Servo myServo;
Button btn(2);

const int OPEN = true;
const int CLOSE = false;

bool door_state = CLOSE;
int timer_id = -1;

void close_door()
{
    myServo.write(0);
    door_state = CLOSE;
    com.print(1, "CLOSE");
}

void open_door()
{
    SimpleTimer &timer = com.getTimer();

    if (door_state == OPEN)
    {
        timer.restartTimer(timer_id);
    }

    else
    {
        myServo.write(90);
        timer_id = timer.setTimeout(3000, close_door);
    }
    door_state = OPEN;
    com.print(1, "OPEN");
}

void setup()
{
    com.init();
    myServo.attach(5);
    com.print(0, "AUTO DOOR");
    btn.setCallback(open_door);
    close_door();
}
void loop()
{
    btn.check();
    com.run();
}