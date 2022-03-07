#include <Minicom.h>
#include <DHT.h>

MiniCom com;
DHT dht11(12, DHT11); // DHT11 객체 생성
void check()
{
    float fh, fc, ff;
    // DHT11 온습도 센서 읽기
    fh = dht11.readHumidity();        // 습도 측정
    fc = dht11.readTemperature();     // 섭씨 온도 측정
    ff = dht11.readTemperature(true); // 화씨 온도 측정
    if (isnan(fh) || isnan(fc) || isnan(ff))
    { // 측정 실패시에는 출력없이 리턴
        com.print(1, "Failed!!");
        return;
    }
    com.print(1, "T:", fc, ", H:", fh);
}

void setup()
{
    com.init();
    com.setInterval(2000, check); // 최소 2초여야 함 
    dht11.begin(); // 빠뜨리는 실수 자주 함
    com.print(0, "[[DHT11]]");
    com.print(1, "Preparing DHT11");
}
void loop()
{
    com.run();
}