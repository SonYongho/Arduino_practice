#include <Minicom.h>
#include <Button.h>
#include <Melody.h>
#include <pirates.h>

MiniCom com;
Button btn(2);
int length = sizeof(notes) / sizeof(int);
Melody melody(9, notes, durations, length);

void check() // 버튼 핸들러
{
    bool bplay = melody.toggle(true); // 대기 : 이어서 재생
    if (bplay)
    {
        com.print(0, "play");
    }
    else
    {
        com.print(0, "pause");
    }
}

void setup()
{
    com.init();
    btn.setCallback(check);
    melody.play();
    com.print(0, "play");
}
void loop()
{
    com.run();
    melody.run();
    btn.check();
}