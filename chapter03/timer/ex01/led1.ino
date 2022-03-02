// 타이머 이용한 toggle

#include <Led.h>
#include <MsTimer2.h>

boolean led_val = LOW;
Led led(8);
void setup()
{
    // 타이머2 인터럽트 설정 및 동작 시작
    MsTimer2::set(500, flash); // 500ms 인터럽트 주기 설정, flash() 함수 실행
    MsTimer2::start();         // 타이머2 동작 시작
}
void loop() {}
// 타이머2 인터럽트 함수, 500ms 마다 자동 실행
void flash()
{
    led_val = !led_val;
    led.setValue(led_val);
}