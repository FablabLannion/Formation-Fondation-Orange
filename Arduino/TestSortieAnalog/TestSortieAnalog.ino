int ValeurSortie;
int ValSomme;
int ValMax;
int ValMin;
int ValEntree;
int ValMoyenne;

void setup() {
  Serial.begin(115200);

  pinMode(6, OUTPUT);
}

void loop() {
    for (ValeurSortie = 0; ValeurSortie <= 255; ValeurSortie=ValeurSortie+1) {
      analogWrite(6, ValeurSortie);
      delay(10);
      ValSomme = 0;
      ValMax = 0;
      ValMin = 1000;
      for (int count = 0; count < 10; count++) {
        ValEntree = analogRead(0);
        ValEntree = ValEntree / 4;
        if (ValEntree < ValMin) {
          ValMin = ValEntree;

        }
        if (ValEntree > ValMax) {
          ValMax = ValEntree;

        }
        ValSomme = ValSomme + ValEntree;
        delay(29);
      }
      ValMoyenne = ValSomme / 16;
      Serial.print("Sorrtie :");
       Serial.print(ValeurSortie);
      Serial.print(" Min :");
       Serial.print(ValMin);
      Serial.print("  Max :");
       Serial.print(ValMax);
      Serial.print("  Moyenne :");
       Serial.println(ValMoyenne);
      delay(500);
    }

}
