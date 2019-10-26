#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h>


int Hum;
int Temp;

LiquidCrystal_I2C lcd(0x3F, 16, 2);
DHT dht_5_DHT11(5,DHT11);


void setup() {
  Serial.begin(115200);
  lcd.init();
  lcd.backlight();
  lcd.noCursor();
  lcd.noBlink();

  dht_5_DHT11.begin();

    lcd.setCursor(0,0);
  lcd.print("Temperature");
  lcd.setCursor(0,1);
  lcd.print("Humidite");

}

void loop() {
    Hum = (int)(dht_5_DHT11.readHumidity());
    Temp = (int)(dht_5_DHT11.readTemperature());
    Serial.print("Température : ");
     Serial.print(Temp);
    Serial.print("   Humidité : ");
     Serial.println(Hum);
    lcd.setCursor(12,0);
    lcd.print(Temp);
    lcd.setCursor(15,0);
    lcd.print("C");
    lcd.setCursor(12,1);
    lcd.print(Hum);
    lcd.setCursor(15,1);
    lcd.print("%");
    delay(1000);

}
