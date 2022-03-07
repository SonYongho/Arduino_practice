#include <EEPROM.h>

// Id를 여러개 등록할거면 이중 배열, 이중 루프써서 기록
byte myId[] = {67, 250, 203, 49};

void setup()
{
    // myId를 EEPROM에 기록
    for (int i = 0; i < 4; i++)
    {
        Serial.begin(115200);
        EEPROM.write(i, myId[i]);
    }
}

void loop()
{
    // EEPROM에 저장된 ID 읽기
    byte savedId[4];
    for (int i = 0; i < 4; i++)
    {
        savedId[i] = EEPROM.read(i);
        Serial.print(savedId[i]);
        Serial.print(' ');
    }
    Serial.println();
    delay(5000);
}