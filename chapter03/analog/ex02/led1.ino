//ex01을 simple timer로
#include <SimpleTimer.h>

SimpleTimer timer;
const int var_pin = A0; // 가변저항 연결핀
int analog_val;         // 아날로그 값 저장 변수

void check()
{
    int digital_val;
    float ff;

    digital_val = analogRead(var_pin);     // 아날로그 값 디지털 변환
    ff = (float)digital_val / 1023. * 5.0; // 전압값 계산, .은 실수 리터럴(안붙여도됨)

    Serial.print("Input Voltage(0~5V) = "); // 입력 전압값 출력(0~5V)
    Serial.println(ff);

    Serial.print("Digital value(0~1023) = ");
    Serial.println(digital_val); // 변환된 디지털 값 출력(0~1023)
    Serial.println("---------------------------------------------");

    delay(2000);
}

void setup()
{
    Serial.begin(115200);
    timer.setInterval(2000, check);
}

void loop()
{
    timer.run();
}
