#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(32,16,2);

int Valor = A1;
void setup()
{
  lcd.begin(16,2);
  lcd.backlight();
  lcd.init();
  lcd.clear();
  pinMode (2,INPUT);
  pinMode (13,OUTPUT);
}

void loop()
{
  Valor = analogRead (A1);
  if (Valor >= 500) {
  if (digitalRead (2) == 0) {
    digitalWrite (13, HIGH) ;
    lcd.setCursor (5,0);
    lcd.print ("Alerta");
    lcd.setCursor (4,1);
    lcd.print ("Entradas");
    delay(3000);
    lcd.clear(); 
  } else {
    digitalWrite (13, LOW) ; }
  if (analogRead (A0) > 1) {
    digitalWrite (13, HIGH) ;
    lcd.setCursor (5,0);
    lcd.print ("Alerta");
    lcd.setCursor (3,1);
    lcd.print ("Atividade!");
    delay(3000);
    lcd.clear(); 
  } else {
    digitalWrite (13, LOW) ; }
  }
  if (Valor < 500) {
    lcd.setCursor (3,0);
    lcd.print ("Inoperante");
    delay(3000);
    lcd.clear();
  }
  if (Valor >= 500) {
    lcd.setCursor (4,0);
    lcd.print ("Operante");
    delay(3000);
    lcd.clear();
  }
}