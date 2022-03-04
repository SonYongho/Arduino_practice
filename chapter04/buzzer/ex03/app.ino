#include <Melody.h>
#include <pirates.h> // 연주할 파일

int length = sizeof(notes) / sizeof(int); // 배열의 길이를 구하는 식

//pc에서 int : 4byte, 아두이노에서 int : 2byte

Melody melody(9, notes, durations, length);
void setup() {
    melody.play();
}
void loop() {
    melody.run();
}