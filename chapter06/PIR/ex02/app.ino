#include <Minicom.h>
#include <Led.h>
#include <Pir.h>

MiniCom com;
Led led(8);
Pir pir(7);
void detect_on()
{
    com.print(1, "Motion detected!");
    led.on();
}
void detect_off()
{
    com.print(1, "Motion ended!");
    led.off();
}
void setup()
{
    com.init();
    com.print(0, "[[Motion]]");
    pir.setCallback(detect_on, detect_off);
}
void loop()
{
    com.run();
    pir.check();
}