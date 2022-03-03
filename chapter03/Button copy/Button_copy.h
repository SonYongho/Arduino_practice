#ifndef BUTTON_H
#define BUTTON_H
// 파일이 아두이노 오리지널 라이브러리에 추가되어있음

// 따로 라이브러리를 추가할 때는 include <Arduino.h> 해줘야함
// 이 때 오리지널 아두이노 라이브러리 폴더를 추가해줘야함
// 파일 -> 현재 작업 영역에 폴더 추가 -> 아두이노의 라이브러리즈
#pragma once
#include <Arduino.h>

// 매개변수 없는 void 함수에 대한 포인터를 button_callback_t로 정의(매개변수 정보)
typedef void (*button_callback_t)();
// typedef : 별칭할 때 쓴다, 복잡한 구조를 단순화시킬 수 있다

class Button
{
protected:
    int pin;
    button_callback_t callback; // callback 함수에 대한 포인터
    // void (*callback)(); 과 같다.
    unsigned long t1;

public:
    Button(int pin);
    void setCallback(button_callback_t callback);
    int read();
    void check();
    void attachInterrupt(button_callback_t callback, int mode);
    bool debounce();

private:
};

#endif