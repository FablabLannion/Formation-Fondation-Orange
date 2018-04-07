#include <DHT.h>


int Hum;
int Temp;

DHT dht_5_DHT11(5,DHT11);


void setup() {
  Serial.begin(115200);
  dht_5_DHT11.begin();


}

void loop() {
    Hum = (int)(dht_5_DHT11.readHumidity());
    Temp = (int)(dht_5_DHT11.readTemperature());
    Serial.print("Température : ");
     Serial.print(Temp);
    Serial.print("   Humidité : ");
     Serial.println(Hum);
    delay(1000);

}
