// 조이스틱 상태 시리얼 모니터 출력하기
const int x_joystick = A2; // X축 아날로그 연결핀
const int y_joystick = A1; // Y축 아날로그 연결핀
const int z_sw = A0;       // Z축 스위치 연결핀
void setup()
{
    Serial.begin(115200);
    pinMode(z_sw, INPUT_PULLUP); // Z축 스위치 연결핀 내부풀업 설정
}

void loop()
{
    int dx, dy;
    boolean sw;
    dx = analogRead(x_joystick); // X축 방향 전압값(좌우)
    dy = analogRead(y_joystick); // Y축 방향 전압값(상하)
    sw = digitalRead(z_sw);
    // X축 방향 조이스틱 전압값 출력
    Serial.print("X-axis = ");
    Serial.println(dx);
    // Y축 방향 조이스틱 전압값 출력
    Serial.print("Y-axis = ");
    Serial.println(dy);
    // Z축 스위치 상태 읽기
    // Z축 스위치 상태 출력
    Serial.print("Z-switch = ");
    if (sw == 0)
        Serial.println("0(ON)");
    else
        Serial.println("1(OFF)");
    delay(2000);
}