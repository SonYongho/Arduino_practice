#include <Led.h>
const int in_pu_sw_pin = 2; // 내부 풀업 스위치 연결핀
Led led(8);

void setup()
{
    pinMode(in_pu_sw_pin, INPUT_PULLUP); // 내부 풀업 Switch 연결핀 입력 설정
}
void loop()
{
    boolean in_pu_sw;
    in_pu_sw = !digitalRead(in_pu_sw_pin);
    led.setValue(in_pu_sw);
}