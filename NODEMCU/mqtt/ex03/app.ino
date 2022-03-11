#include <MqttCom.h>
#include <DHT.h>
#include <Analog.h>

const char *ssid = "";
const char *password = "";
const char *mqtt_server = ""; // mqtt broker ip address

MqttCom com;
DHT dht11(D6, DHT11); // DHT11 객체 생성
Analog cds(A0, 0, 100);

void publish()
{
    char msg[50];
    float fh, fc;

    fh = dht11.readHumidity();
    fc = dht11.readTemperature();
    int illu = cds.read();

    // 습도 측정
    // 섭씨 온도 측정 // 조도 측정
    if (isnan(fh) || isnan(fc))
    { // 측정 실패시에는 출력없이 리턴
        Serial.println("DHT11 read failed!!");
        return;
    }
    com.publish("iot/hinana/livingroom/temp", fc);
    com.publish("iot/hinana/livingroom/humi", fh);
    com.publish("iot/hinana/livingroom/illu", illu);
}

void setup()
{
    com.init(ssid, password);
    com.setServer(mqtt_server, NULL, NULL);
    com.setInterval(2000, publish);
    dht11.begin();
}
void loop()
{
    com.run();
}