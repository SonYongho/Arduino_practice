// 스위치 풀업/풀다운 동작 확인
#include <Led.h>

const int pu_sw_pin = 2; //풀업
Led led1(4);

const int pd_sw_pin = 3; //풀다운
Led led2(5);

void setup()
{
    pinMode(pd_sw_pin, INPUT); // 풀다운 스위치 연결핀 입력 설정
    pinMode(pu_sw_pin, INPUT); // 풀업 스위치 연결핀 입력 설정
}

void loop()
{
    boolean pd_sw, pu_sw;
    pu_sw = digitalRead(pu_sw_pin); // 풀업 스위치 상태 읽기
    led1.setValue(pu_sw);           // 풀업 스위치 상태 LED 출력

    //풀업은 평상시에 high, 누르면 low

    pd_sw = digitalRead(pd_sw_pin); // 풀다운 스위치 상태 읽기
    led2.setValue(pd_sw);           // 풀다운 스위치 상태 LED 출력

    //풀다운은 평상시에 low, 누르면 high
}