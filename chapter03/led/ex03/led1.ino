// 4개의 순차점멸(LED 풀다운)
const int led1_pin = 3;
const int led2_pin = 4;
const int led3_pin = 5;
const int led4_pin = 6;

void setup()
{
    pinMode(led1_pin, OUTPUT); // 3번 핀 출력 설정
    pinMode(led2_pin, OUTPUT); // 4번 핀 출력 설정
    pinMode(led3_pin, OUTPUT); // 5번 핀 출력 설정
    pinMode(led4_pin, OUTPUT); // 6번 핀 출력 설정
}

void loop()
{
    // LED1만 ON
    digitalWrite(led1_pin, HIGH); // 3번 핀 HIGH 출력(on)
    digitalWrite(led2_pin, LOW);  // 4번 핀 LOW 출력(off)
    digitalWrite(led3_pin, LOW);  // 5번 핀 LOW 출력(off)
    digitalWrite(led4_pin, LOW);  // 6번 핀 LOW 출력(off)
    delay(1000);

    // LED2만 ON
    digitalWrite(led1_pin, LOW);  // 3번 핀 LOW 출력(off)
    digitalWrite(led2_pin, HIGH); // 4번 핀 HIGH 출력(on)
    digitalWrite(led3_pin, LOW);  // 5번 핀 LOW 출력(off)
    digitalWrite(led4_pin, LOW);  // 6번 핀 LOW 출력(off)
    delay(1000);

    // LED3만 ON
    digitalWrite(led1_pin, LOW);  // 3번 핀 LOW 출력(off)
    digitalWrite(led2_pin, LOW);  // 4번 핀 LOW 출력(off)
    digitalWrite(led3_pin, HIGH); // 5번 핀 HIGH 출력(on)
    digitalWrite(led4_pin, LOW);  // 6번 핀 LOW 출력(off)
    delay(1000);

    // LED4만 ON
    digitalWrite(led1_pin, LOW);  // 3번 핀 LOW 출력(off)
    digitalWrite(led2_pin, LOW);  // 4번 핀 LOW 출력(off)
    digitalWrite(led3_pin, LOW);  // 5번 핀 LOW 출력(off)
    digitalWrite(led4_pin, HIGH); // 6번 핀 HIGH 출력(on)
    delay(1000);
}