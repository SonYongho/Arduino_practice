// 비밀번호를 입력하는 도어락
// 맞으면 문을 열음
// keypad를 라이브러리에 클래스화 시켜서 간편화
// 입력할 때만 백라이트를 킴

#include <Minicom.h>
#include <NumberPad.h>
#include <Servo.h>

MiniCom com;
NumberPad keypad;
Servo servo;

String input = "";
String dumy_input = ""; // 도어락의 비밀번호를 *로 표시하기 위한 변수

bool b_input = false; // 현재 입력 모드

int timer_id = -1;

const String PASSWORD = "1200";

void open_door()
{
    servo.write(90);
}

void close_door()
{
    servo.write(0);
}

void start_input()
{
    com.onLCD();
    com.print(0, "[input...]");
    b_input = true;
    input = "";
    dumy_input = "";

    timer_id = com.getTimer().setTimeout(5000, cancle_input);
    //5초간 입력없으면 타이머에 의해 초기화
}

void end_input()
{
    // 입력완료
    b_input = false;
    Serial.print("입력완료: ");
    Serial.println(input);
    if (input == PASSWORD)
    {
        com.print(0, "complete...!");
        open_door();
        com.getTimer().setTimeout(5000, close_door);
    }

    // 입력이 끝났을 때는 타이머 제거
    com.getTimer().deleteTimer(timer_id);
    timer_id = -1;
    com.offLCD();
}

void cancle_input()
{
    b_input = false;
    input = "";
    dumy_input = "";
    com.print(0, "[cancle...]");
    com.print(1, "");
    com.offLCD();
}

void key_input(char key)
{
    input += key;
    dumy_input += '*';
    com.print(1, dumy_input.c_str());
    com.getTimer().restartTimer(timer_id); // 키를 누를 때마다 타이머 연장
}

void key_process(char key)
{
    if (key == '*')
    {
        start_input();
    }
    else if (key == '#')
    {
        end_input();
    }
    else if (key && b_input) // 입력 모드일 때만
    {
        key_input(key);
    }
}

void setup()
{
    com.init();
    com.offLCD();
    com.print(0, "[start by *]");
    servo.attach(3);
    servo.write(0);
}
void loop()
{
    char key = keypad.getKey(); // 비동기식
    key_process(key);
    com.run(); // Timer run
}