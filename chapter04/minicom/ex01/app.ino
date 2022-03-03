#include <Minicom.h>
#include <Led.h>
#include <Analog.h>

Led led(8);
Analog sensor(A0, 1023, 0);
MiniCom com;

void setup()
{
    com.init();
    com.print(0, "[[MiniCom]]");
    com.setInterval(100, check); // 1초 간격으로
}
void loop()
{
    com.run();
}
void check()
{
    int value = sensor.read();
    com.print(1, "value: ", value);
}
