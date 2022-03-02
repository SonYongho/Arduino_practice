#ifndef PWMLED_H
#define PWMLED_H

#pragma once

#include <Arduino.h>
#include <Led.h>

class PWMLed : public Led // 상속
{
protected:
    int value;

public:
    PWMLed(int pin, int value = 0); // 생성자
    void setValue(int value); // 오버라이드(재정의)
};