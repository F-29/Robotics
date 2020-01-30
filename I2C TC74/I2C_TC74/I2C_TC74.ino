#include <Wire.h>
#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2); // LiquidCrystal lcd(rs, enable, D4, D5, D6, D7);

int tempAddress = 72;

void setup() {
    Serial.begin(9600);
    lcd.begin(16, 2); // (column, row);
    lcd.clear();
    Wire.begin();
}

void loop() {
    Wire.beginTransmission(tempAddress);
    Wire.write(0);
    Wire.endTransmission();

    Wire.requestFrom(tempAddress, 1);

    lcd.setCursor(0, 0);
    lcd.print("Made by Mosich");
    lcd.setCursor(0, 1);
    lcd.print(Wire.available());
    while (Wire.available() == 0);

    int c = Wire.read();

    Serial.print("Temperature: ");
    Serial.print(c);
    Serial.print(" °C");
    lcd.setCursor(0, 1);
    lcd.print("temp :");
    lcd.setCursor(7, 1);
    lcd.print(c);
    delay(1000);
    lcd.clear();
}
