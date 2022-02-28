// LED 풀업/풀다운 연결핀 HIGH 출력 확인
const int pu_led_pin = 3; // 풀업 연결핀
const int pd_led_pin = 4; // 풀다운 연결핀
void setup()
{
    pinMode(pu_led_pin, OUTPUT);
    pinMode(pd_led_pin, OUTPUT);
}
void loop()
{
    digitalWrite(pd_led_pin, HIGH); // 풀다운 LED 연결핀 HIGH 출력 ON
    digitalWrite(pu_led_pin, HIGH); // 풀업 LED 연결핀 HIGH 출력 OFF

    // digitalWrite(pd_led_pin, LOW); // 풀다운 LED 연결핀 LOW 출력 OFF
    // digitalWrite(pu_led_pin, LOW); // 풀업 LED 연결핀 LOW 출력 ON
}
