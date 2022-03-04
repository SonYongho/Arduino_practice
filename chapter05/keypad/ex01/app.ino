#include <Minicom.h>
#include <Keypad.h>

MiniCom com;

const byte ROWS = 4; // 행(rows) 개수
const byte COLS = 4; // 열(columns) 개수
char keys[ROWS][COLS] = {
    {'1', '2', '3', 'A'},
    {'4', '5', '6', 'B'},
    {'7', '8', '9', 'C'},
    {'*', '0', '#', 'D'}};
byte rowPins[ROWS] = {7, 6, 5, 4};   // R1, R2, R3, R4 단자가 연결된 핀 번호
byte colPins[COLS] = {8, 9, 10, 11}; // C1, C2, C3, C4 단자가 연결된 핀 번호

// Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS );
Keypad keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

String input = "";
bool b_input = false; // 현재 입력 모드

void setup()
{
    com.init();
    com.print(0, "[start by *]");
}
void loop()
{
    char key = keypad.getKey(); // 비동기식
    if (key == '*')
    {
        b_input = true;
        input = "";
    }
    else if (key == '#')
    {
        b_input = false;
        Serial.print("입력 완료: ");
        Serial.println(input);
        com.print(1, "complete");
    }
    else if (key && b_input) // 입력 모드일 때만
    {
        input += key;
        com.print(1, input.c_str());
    }
        
}