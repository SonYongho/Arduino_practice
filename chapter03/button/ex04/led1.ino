// Switch 눌려질 때마다 4개의 LED 순차 점멸(1개 LED만 on)
#include <Led.h>
#include <Button.h>
#include <SimpleTimer.h>

Button btn(2);

Led leds[4] = {
    Led(8), Led(9), Led(10), Led(11)};
Led led(7);
SimpleTimer timer;
int out_no = -1; // 출력 패턴 번호(0-3)

void blink()
{
    led.toggle();
}

void move_led()
{
    out_no = (++out_no) % 4; // 다음 출력 패턴 번호 설정
    Serial.println(out_no);
    for (int n = 0; n < 4; n++)
    {
        leds[n].setValue(n == out_no);
    }
}

void setup()
{
    btn.setCallback(move_led);
    timer.setInterval(1000, blink);
}
void loop()
{
    timer.run();
    btn.check();
}
