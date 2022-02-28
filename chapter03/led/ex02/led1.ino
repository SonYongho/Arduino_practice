const int PULLUP_LED = 3;
const int PULLDOWN_LED = 4;
int state = 0;
void setup()
{
    Serial.begin(115200);
    pinMode(PULLDOWN_LED, OUTPUT);
    pinMode(PULLUP_LED, OUTPUT);
}
void loop()
{
    Serial.print("state value : ");
    Serial.println(state); // println은 줄바꿈 추가

    digitalWrite(PULLDOWN_LED, state);
    digitalWrite(PULLUP_LED, state);

    state = !state; // 0 -> 1 toggle
    delay(1000);
}
