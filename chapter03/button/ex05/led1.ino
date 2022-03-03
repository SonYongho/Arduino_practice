const int sw_pin = 2;
int count = 0;

int t1, t2; // 인터럽트 발생 시간 저장

// 외부 인터럽트1 처리 함수
void flash(void)
{
    // 채터링 체크 : 200ms 이내에 스위치가 또 눌려진 상태이면 무시
    t2 = millis(); // 현재 시간 저장

    // 인터럽트 시간 간격 체크
    if ((t2 - t1) < 200)
        return; // 200ms 보다 작으면 무시
    else
        t1 = t2; // 인터럽트 발생 시간 갱신

    count++;
    Serial.println(count);
}
void setup()
{
    Serial.begin(115200);
    pinMode(sw_pin, INPUT_PULLUP);
    // 외부 인터럽트 설정
    attachInterrupt(digitalPinToInterrupt(sw_pin), flash, FALLING);

    t1 = millis(); // 프로그램 시작 시간 저장
}
void loop() {}