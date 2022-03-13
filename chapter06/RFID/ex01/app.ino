#include <SPI.h>
#include <MFRC522.h>
#include <Led.h>
#include <Buzzer.h>
#include <Servo.h>
#include <Minicom.h>
#include <EEPROM.h>

#define button 2

Servo myServo;
MiniCom com;

byte myId[4] = {};

const int servo_pin = 5;

#define RST_PIN 9 // reset핀은 9번으로 설정
#define SS_PIN 10 // SS핀은 10번으로 설정

Buzzer buzzer(6);
// byte myId[] = {67, 250, 203, 49}; // 바이트 배열

Led leds[2] = {Led(7), Led(3)};

// SS핀은 데이터를 주고받는 역할의 핀( SS = Slave Selector )

MFRC522 mfrc(SS_PIN, RST_PIN); // MFR522 객체 생성

const int OPEN = true;
const int CLOSE = false;
bool door_state = CLOSE;

void open_door()
{
    door_state = OPEN;
    Serial.println("Equal");
    com.print(1, "Equal");
    myServo.write(0);
    leds[0].on();
    buzzer.beep(100);
}

void close_door()
{
    door_state = CLOSE;
    leds[0].off();
    myServo.write(90);
    com.print(1, "Waiting");
}

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

void register_id()
{
    // 이미 등록되어 있는 카드라면 문구 출력
    if (mfrc.uid.uidByte[0] == myId[0] || mfrc.uid.uidByte[1] == myId[1] || mfrc.uid.uidByte[2] == myId[2] || mfrc.uid.uidByte[3] == myId[3])
    {
        Serial.println("Already registered");
        com.print(1, "Already registered");
    }
    else
    {
        for (int i = 0; i < 4; i++)
        {
            EEPROM.write(i, mfrc.uid.uidByte[i]);
        }
        Serial.println("saved!");
        com.print(1, "saved!");
    }
}

void read_id()
{
    for (int i = 0; i < 4; i++)
    {
        myId[i] = EEPROM.read(i);
    }
}

void clear_id()
{
    // EEPROM 초기화
    for (int i = 0; i < 4; i++)
    {
        EEPROM.write(i, 0);
    }
}

void setup()
{
    com.init();
    com.print(0, "[[RFID Door]]");
    com.print(1, "Waiting");
    Serial.begin(115200);

    pinMode(button, INPUT_PULLUP);

    SPI.begin();
    mfrc.PCD_Init();
    myServo.attach(servo_pin);

    // clear_id();
    read_id();
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
        com.print(1, "sign up your card");
        register_id();
        delay(5000);
    }
    else
    {
        read_id();
        if (equalId(myId, mfrc.uid.uidByte) == true)
        {
            open_door();
            delay(5000);
            close_door();
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
    }
    com.run();
    buzzer.run();
}