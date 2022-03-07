// CdS 조도센서에 걸리는 전압과 A/D 변환값 확인
// 밝으면 저항이 작아지므로 걸리는 전압이 작아지고
// 어두우면 저항이 커지므로 걸리는 전압이 커지게 된다.

#include <Minicom.h>
#include <Analog.h>
#include <Led.h>

MiniCom com;
Analog cds(A0, 0, 100);
Led led(8);

void check()
{
    int value = cds.read();
    led.setValue(value > 50); // 어두어지면 켜짐
    com.print(1, "Illu: ", value);
}
void setup()
{
    com.init();
    com.setInterval(100, check);
    com.print(0, "[[CDS Test]]");
}
void loop()
{
    com.run();
}