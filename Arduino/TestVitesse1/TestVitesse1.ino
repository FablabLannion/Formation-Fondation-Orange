unsigned long Debut, Fin;
volatile long count;

void setup() {
  // put your setup code here, to run once:

  Serial.begin(115200);
  Serial.println("Debut Test vitesse");
  Debut = millis();
  count = 5000000;
  while ( --count > 0 ) ;
  Fin = millis();
  Serial.print("Fin test vitesse, temps passé ");
  Serial.print(Fin - Debut);
  Serial.println(" ms");
}

void loop() {
  // put your main code here, to run repeatedly:

}
