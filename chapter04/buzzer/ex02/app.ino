#include <pitches.h>

#define NUM 49

int melody[NUM] = { // 곰 세마리

    NOTE_C4, NOTE_C4, NOTE_C4, NOTE_C4, NOTE_C4,
    NOTE_E4, NOTE_G4, NOTE_G4, NOTE_E4, NOTE_C4,
    NOTE_G4, NOTE_G4, NOTE_E4, NOTE_G4, NOTE_G4, NOTE_E4,
    NOTE_C4, NOTE_C4, NOTE_C4,

    NOTE_G4, NOTE_G4, NOTE_E4, NOTE_C4,
    NOTE_G4, NOTE_G4, NOTE_G4,
    NOTE_G4, NOTE_G4, NOTE_E4, NOTE_C4,
    NOTE_G4, NOTE_G4, NOTE_G4,

    NOTE_G4, NOTE_G4, NOTE_E4, NOTE_C4,
    NOTE_G4, NOTE_G4, NOTE_G4, NOTE_A4, NOTE_G4,
    NOTE_C5, NOTE_G4, NOTE_C5, NOTE_G4,
    NOTE_E4, NOTE_D4, NOTE_C4};

// 음표 길이
int noteDuration[NUM] = {
    4, 8, 8, 4, 4, 4, 8, 8, 4, 4, 8, 8, 4, 8, 8, 4, 4, 4, 2, 4, 4, 4, 4, 4, 4, 2, 4, 4, 4, 4, 4, 4, 2,
    4, 4, 4, 4, 8, 8, 8, 8, 2, 4, 4, 4, 4, 4, 4, 2};

const int speaker_pin = 9;
void setup()
{
    pinMode(speaker_pin, OUTPUT);
}

void loop()
{
    int m, d, dd;
    for (m = 0; m < NUM; m++)
    {
        d = 1000 / noteDuration[m];
        dd = d * 1.3; // 음 출력 시간(4분 음표 325ms)
        tone(speaker_pin, melody[m], d);
        delay(dd);
    }
    delay(1000);
}