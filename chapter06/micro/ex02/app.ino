#include <Minicom.h>
#include <Ultra.h>
MiniCom com;
Ultra ultra(5, 6);
void check()
{
    int distance = ultra.getDistance();
    com.print(1, "Dist.(cm)=", distance);
}
void setup()
{
    com.init();
    com.setInterval(1000, check);
    com.print(0, "[[Distance]]");
}
void loop()
{
    com.run();
}