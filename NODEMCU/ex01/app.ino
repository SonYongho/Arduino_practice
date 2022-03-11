#include <ESP8266WiFi.h>
#include <Minicom.h>

const char *ssid = "";
const char *password = "";
MiniCom com;
void wifi_connect()
{
    WiFi.begin(ssid, password); // 비밀번호가 없는 경우 NULL
    com.print(0, "try to connect");
    Serial.println();
    while (WiFi.status() != WL_CONNECTED)
    {
        delay(500);
        Serial.print(".");
    }
    com.print(0, "WiFi connected");
    com.print(1, WiFi.localIP().toString().c_str());
    Serial.println();
    Serial.println(WiFi.localIP());
}

void setup()
{
    com.init();
    wifi_connect();
}
void loop()
{
    com.run();
}