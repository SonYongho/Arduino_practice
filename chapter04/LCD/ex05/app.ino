// 1초에 10번 가변 저항을 읽어서
// 그 값을 lcd로 출력

#include <LiquidCrystal_I2C.h>
#include <SimpleTimer.h>
#include <Analog.h>

SimpleTimer timer;
Analog sensor(A0, 1023, 0);
LiquidCrystal_I2C lcd(0x27, 16, 2);

void check()
{
    // 저항값 읽어서, lcd로 출력
    int value = sensor.read();
    Serial.println(value);

    lcd.setCursor(0, 1);
    // 문자열 포맷팅
    char str[17]; // 1줄에 16글자로 가정하면, NULL 문자 포함해서 17의 크기
    sprintf(str, "value: %4d", value);

    lcd.print(str);
}

void setup()
{
    Serial.begin(115200);
    lcd.init();
    lcd.backlight();
    timer.setInterval(100, check); //1초에 10번
    lcd.setCursor(0, 0);
    lcd.print("[reg. value]");
}

void loop()
{
    timer.run();
}