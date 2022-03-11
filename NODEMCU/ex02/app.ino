#include <WifiMiniCom.h>

const char *ssid = "";
const char *password = "";
WifiMiniCom com;
void setup()
{
    com.init(ssid, password);
}
void loop()
{
    com.run();
}