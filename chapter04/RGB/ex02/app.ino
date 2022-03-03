// 1초 간격으로 색상을 랜덤하게 변경
// 10가지 색상을 정해서, 1초 간격으로 색상 바꾸기
// 버튼을 누르면 색상 변경 시간 조정
#include <SimpleTimer.h>
#include <ColorLed.h>
#include <Button.h>

SimpleTimer timer;
ColorLed leds(9, 10, 11);
Button btn(2);

const int COLOR_NUM = 10;
int colors[COLOR_NUM][3] = {
    {255, 0, 0}, //단일 색상
    {0, 255, 0},
    {0, 0, 255},
    {255, 255, 0},
    {123, 32, 12},
    {111, 222, 255},
    {10, 110, 210},
    {30, 130, 230},
    {50, 250, 125},
    {1, 101, 201},
};


int color_index = -1;

int INTERVAL_NUM = 3;
int INTERVALS[] = {500, 1000, 2000}; //0.5초, 1초, 2초
int INTERVAL_index = 0;
int timer_id = -1; // 현재 가동 중인 Timer의 ID

void check()
{
   color_index = (color_index + 1) % COLOR_NUM;

   int *pcolor = colors[color_index];
   leds.rgb(pcolor[0], pcolor[1], pcolor[2]);
   //leds.rgb(colors[color_index][0], colors[color_index][1], colors[color_index][2]);
   //  leds.random();
}

void change_interval()
{
   /*
   1. 기존 타이머 제거
   2. interval_index 조정
   3. 타이머 재설정
   */
   timer.deleteTimer(timer_id);
   INTERVAL_index = (INTERVAL_index + 1) % INTERVAL_NUM;
   timer_id = timer.setInterval(INTERVALS[INTERVAL_index], check);
}

void setup()
{
   Serial.begin(115200);
   timer_id = timer.setInterval(INTERVALS[INTERVAL_index], check);
   btn.setCallback(change_interval);
}

void loop()
{
   btn.check();
   timer.run();
}