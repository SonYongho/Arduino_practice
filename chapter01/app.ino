// 확장팩 : arduino, arduino-snipset, c++ class creator, c++ helper
// arduino 확장팩 설정에서 path에(command path 아님) 아두이노 설치경로/Arduino.app
// vscode 하단의 네브바에서 포트, 보드 설정

void setup()
{
    Serial.begin(9600);            // 시리얼통신 시작(속도 : 9600 bps)
    Serial.print("Hello, Hinana"); // 시리얼 모니터에 출력
}

void loop()
{
}
