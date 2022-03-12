#include <SPI.h>
#include <MFRC522.h>
#include <Led.h>
#include <Buzzer.h>
#include <Servo.h>
#include <Minicom.h>
#include <Button.h>
#include <EEPROM.h>

Servo myServo;
MiniCom com;

const int servo_pin = 5;

#define RST_PIN 9 // reset핀은 9번으로 설정

#define SS_PIN 10 // SS핀은 10번으로 설정

Button btn(2);
Buzzer buzzer(6);
byte myId[] = {67, 250, 203, 49}; // 바이트 배열

Led leds[2] = {Led(7), Led(3)};

// SS핀은 데이터를 주고받는 역할의 핀( SS = Slave Selector )

MFRC522 mfrc(SS_PIN, RST_PIN); // MFR522 객체 생성

bool equalId(byte *id1, byte *id2)
{
    for (byte i = 0; i < 4; i++)
    {
        if (id1[i] != id2[i])
        {
            return false;
        }
    }
    return true;
}

void setup()
{
    com.init();
    com.print(0, "[[RFID Door]]");
    com.print(1, "Waiting");
    Serial.begin(115200);
    SPI.begin();
    mfrc.PCD_Init();
    myServo.attach(servo_pin);
}

void loop()
{
    if (!mfrc.PICC_IsNewCardPresent() || !mfrc.PICC_ReadCardSerial())
    {
        // 태그 접촉이 되지 않았을때 또는 ID가 읽혀지지 않았을때
        delay(500);
        return;
    }

    Serial.print("Card UID:"); // 태그의 ID출력
    // 태그의 ID출력하는 반복문.태그의 ID사이즈(4)까지
    for (byte i = 0; i < 4; i++)
    {
        // mfrc.uid.uidByte[0] ~ mfrc.uid.uidByte[3]까지 출력
        Serial.print(mfrc.uid.uidByte[i]);
        Serial.print(" "); // id 사이의 간격 출력
    }
    Serial.println();
    if (equalId(myId, mfrc.uid.uidByte) == true)
    {
        Serial.println("Equal");
        com.print(1, "Equal");
        myServo.write(0);
        leds[0].on();
        buzzer.beep(100);
        delay(5000);
        leds[0].off();
        myServo.write(90);
        com.print(1, "Waiting");
    }
    else
    {
        Serial.println("Not Equal");
        com.print(1, "Not Equal");
        leds[1].on();
        buzzer.beep(2000);
        leds[1].off();
        com.print(1, "Waiting");
    }

    buzzer.run();
}