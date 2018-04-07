#define ROW_1 2
#define ROW_2 3
#define ROW_3 4
#define ROW_4 5
#define ROW_5 6
#define ROW_6 7
#define ROW_7 8
#define ROW_8 9

#define COL_1 10
#define COL_2 11
#define COL_3 12
#define COL_4 13
#define COL_5 A0
#define COL_6 A1
#define COL_7 A2
#define COL_8 A3

const byte rows[] = {
    ROW_1, ROW_2, ROW_3, ROW_4, ROW_5, ROW_6, ROW_7, ROW_8
};



// Les deux motifs à afficher, ce sont des sourires...
byte EX1[] = {B11111110,B01000001,B01000001,B01000001,B01111110,B01000001,B01000001,B11111110};
byte EX2[] = {B00111100,B01000010,B10000001,B10000001,B10000001,B10000001,B01000010,B00111100};
byte EX3[] = {B10000001,B11000001,B10100001,B10010001,B10001001,B10001001,B10000101,B10000011};
byte EX4[] = {B00000111,B00000010,B00000010,B00000010,B00000010,B10000010,B01000010,B00111100};
byte EX5[] = {B00111100,B01000010,B10000001,B10000001,B10000001,B10000001,B01000010,B00111100};
byte EX6[] = {B10000001,B10000001,B10000001,B10000001,B10000001,B10000001,B01000010,B00111100};
byte EX7[] = {B11111100,B01000010,B01000001,B01111100,B01000100,B01000010,B01000010,B01000001};
byte EX8[] = {B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000};

int ValSortie = 0;        //  0 : EX1, 1 --> EX2
unsigned long timeCount = 0;

void setup() {

    
    // Toutes les broches sont des sorties
    // Obligatoire, sinon les LED ne s'allumeront pas
    for (byte i = 2; i <= 13; i++)    //  Boucle pour les 12 premieres broches
        pinMode(i, OUTPUT);
    pinMode(A0, OUTPUT);
    pinMode(A1, OUTPUT);
    pinMode(A2, OUTPUT);
    pinMode(A3, OUTPUT);
    for ( int i = 0; i < 7; i++ )
      digitalWrite(rows[i], HIGH);    //  Force rangées à 1, LED éteintes
    
}

void loop() {
  if ( millis() > timeCount )         //  Change d'affichage toutes les secondes.
  {
    timeCount = millis() + 1000;
    ValSortie = (ValSortie + 1);
  }
  if ( (ValSortie  & 7)== 1)
  {
    drawScreen(EX1);
  }
  else  if ( (ValSortie  & 7)== 2)
  {
    drawScreen(EX2);
  }
  else  if ( (ValSortie  & 7)== 3)
  {
    drawScreen(EX3);
  }
  else  if ( (ValSortie  & 7)== 4)
  {
    drawScreen(EX4);
  }
  else  if ( (ValSortie  & 7)== 5)
  {
    drawScreen(EX5);
  }
  else  if ( (ValSortie  & 7)== 6)
  {
    drawScreen(EX6);
  }
  else  if ( (ValSortie  & 7)== 7)
  {
    drawScreen(EX7);
  }
  else  if ( (ValSortie  & 7)== 0)
  {
    drawScreen(EX8);
  }
}

//  Affiche les LED correspondant au tableau de 8 caractères passé en paramètre
//  Chaque octet correspond à une ligne.

void  drawScreen(byte buffer2[]){
     
    
   // Balaie toutes les rangées (0..7) 
    for (byte i = 0; i < 8; i++) {
        setColumns(buffer2[i]);       // Positionne les broches pour les colonnes 0..7 avec l'octet du tableau
        digitalWrite(rows[i], LOW);   // Positionne commande rangée à 0. Les LED s'allument
        delay(1);                     // Délai faible pour rendre imperceptible le multiplexage
        digitalWrite(rows[i], HIGH);  //  Désactive la rangée. Le changement pour les colonnes s'effectue alors pour ne pas avoir de faux effets
        
    }
}

//  Positionne les colonnes en fonction de l'octet passé en paramètre
//  Chaque bit à 1 va donner une LED allumée.
void setColumns(byte b) {
    digitalWrite(COL_1, (b >> 7) & 0x01); // Get the 1st bit: 10000000
    digitalWrite(COL_2, (b >> 6) & 0x01); // Get the 2nd bit: 01000000
    digitalWrite(COL_3, (b >> 5) & 0x01); // Get the 3rd bit: 00100000
    digitalWrite(COL_4, (b >> 4) & 0x01); // Get the 4th bit: 00010000
    digitalWrite(COL_5, (b >> 3) & 0x01); // Get the 5th bit: 00001000
    digitalWrite(COL_6, (b >> 2) & 0x01); // Get the 6th bit: 00000100
    digitalWrite(COL_7, (b >> 1) & 0x01); // Get the 7th bit: 00000010
    digitalWrite(COL_8, (b >> 0) & 0x01); // Get the 8th bit: 00000001
}
