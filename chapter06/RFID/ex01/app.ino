// 수행 평가
// 1. 이걸 클래스로 정의해서 올리기(RFID Reader라는 이름), bool read()로 읽음, 매개변수 1개의 equalsId(id)로 체크
// 2. 

#include <SPI.h>
#include <MFRC522.h>
#include <Led.h>
#include <Buzzer.h>
#include <Servo.h>

Servo myServo;

const int servo_pin = 5;

#define RST_PIN 9 // reset핀은 9번으로 설정

#define SS_PIN 10 // SS핀은 10번으로 설정

Buzzer buzzer(3);
byte myId[] = {67, 250, 203, 49}; // 바이트 배열

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
        myServo.write(0);
        buzzer.beep(100);
        delay(3000);
        myServo.write(90);
        
    }
    else
    {
        Serial.println("Not Equal");
        myServo.write(90);
        buzzer.beep(2000);
        
    }

    buzzer.run();
}