#include <LiquidCrystal_I2C.h>

uint8_t name_s[8] = {
    0x08,
    0x0E,
    0x04,
    0x1F,
    0x00,
    0x04,
    0x0A,
    0x04};

uint8_t name_d[8] = {
    0x02,
    0x1E,
    0x13,
    0x1E,
    0x02,
    0x0E,
    0x0A,
    0x0E};

uint8_t name_u[8] = {
    0x0E,
    0x02,
    0x06,
    0x1F,
    0x00,
    0x0E,
    0x0A,
    0x0E};

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup()
{
    lcd.init();
    lcd.backlight();

    lcd.createChar(0, name_s);
    lcd.createChar(1, name_d);
    lcd.createChar(2, name_u);
}

void loop()
{
    lcd.setCursor(0, 0);
    lcd.print("Hello, Arduino!");

    lcd.setCursor(0, 1);
    lcd.print("My name is ");

    lcd.write(0);
    lcd.write(1);
    lcd.write(2);
}