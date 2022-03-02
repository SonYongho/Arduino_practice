#include "PWMLed.h"

PWMLed::PWMLed(int pin, int value) : Led(pin), value(value)
// Led(pin)으로 상위 생성자 호출
{
    analogWrite(pin, value);
}

void PWMLed::setValue(int value)
{
    this->value = value;
    analogWrite(pin, value);
}
