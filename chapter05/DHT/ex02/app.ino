#include <Minicom.h>
MiniCom com;
const int lm35_pin = A0; // LM35DZ 연결핀
void check()
{
    // LM35DZ 온도센서 측정
    int value = analogRead(lm35_pin); // 온도센서 디지털 값
    float ftp = (float)value / 1024.0 * 5.0; // 온도센서 전압값
    ftp = ftp * 100.0 + 0.5; // 온도값(1도/10mv)
    com.print(1, "T: ", ftp);
}
void setup()
{
    com.init();
    com.setInterval(2000, check);
    com.print(0, "[[LM35]]");
    com.print(1, "Preparing LM35");
}
void loop()
{
    com.run();
}