// 기울기 센서(스위치) : 일반 택 스위치 연결방법과 동일
// 기울어지지 않을때 : OFF, 기울어지질때 : ON

#include <Led.h>

Led led(9);
const int tilt_pin = 4;
void setup()
{
    pinMode(tilt_pin, INPUT);
}
void loop()
{
    bool t_sw;
    t_sw = digitalRead(tilt_pin);
    led.setValue(t_sw);
}