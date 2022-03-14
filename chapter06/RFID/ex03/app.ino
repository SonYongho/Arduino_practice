// 클래스 분리

#include <SPI.h>
#include <MFRC522.h>
#include <Led.h>
#include <Buzzer.h>
#include <Servo.h>
#include <EEPROM.h>
#include <RFIDReader.h>

#define button 2
#define RST_PIN 9 // reset핀은 9번으로 설정
#define SS_PIN 10 // SS핀은 10번으로 설정

MFRC522 mfrc(SS_PIN, RST_PIN);
Buzzer buzzer(6);
byte myId[4] = {};

RFIDReader reader;


void setup()
{
    Serial.begin(115200);
    reader.init();
    mfrc.PCD_Init();
    pinMode(button, INPUT_PULLUP);
    //reader.clear_id();
    reader.read_id(myId);
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

    if (digitalRead(button) == LOW)
    {
        // 이미 등록되어 있는 카드라면 문구 출력
        if (mfrc.uid.uidByte[0] == myId[0] || mfrc.uid.uidByte[1] == myId[1] || mfrc.uid.uidByte[2] == myId[2] || mfrc.uid.uidByte[3] == myId[3])
        {
            Serial.println("Already registered");
        }
        else
        {
            for (int i = 0; i < 4; i++)
            {
                EEPROM.write(i, mfrc.uid.uidByte[i]);
            }
            delay(3000);
            Serial.println("saved!");
        }
    }

    else
    {
        reader.read_id(myId);
        Serial.println();

        if (reader.equalId(myId, mfrc.uid.uidByte) == true)
        {
            reader.open_door();
            delay(5000);
            reader.close_door();
        }

        else
        {
            reader.not_equal();
        }
    }

    reader.run();
    buzzer.run();
}