#include <LiquidCrystal.h>
double temp,tempC;
LiquidCrystal lcd(12, 11, 5, 4, 3, 2); // LiquidCrystal lcd(rs, enable, D4, D5, D6, D7);

void setup(){
 analogReference(INTERNAL); // 1.1v Vref 
lcd.begin(16,2); // (column, row);

lcd.clear();

  
}

void loop(){
  temp= analogRead(A0);
  tempC = (1.0742 * temp/ 10) - 0.20;
  
  lcd.setCursor(0,0);
  lcd.print("Made by Mosich");
  lcd.setCursor(0,1);
  lcd.print("temp :");
  lcd.setCursor(7, 1);
  lcd.print(tempC);
  lcd.print(" C");
  delay(400);
  lcd.clear();
  
}
