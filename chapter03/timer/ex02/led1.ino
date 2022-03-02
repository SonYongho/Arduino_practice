#include <SimpleTimer.h>
// simple timer

SimpleTimer timer;
// callback 함수
void repeatMe()
{
    Serial.print("Uptime (s): ");
    Serial.println(millis() / 1000);
}
void setup()
{
    Serial.begin(115200);
    timer.setInterval(1000, repeatMe); // 1000ms 간격으로 함수 호출, timer id 리턴
}
void loop()
{
    timer.run();
}