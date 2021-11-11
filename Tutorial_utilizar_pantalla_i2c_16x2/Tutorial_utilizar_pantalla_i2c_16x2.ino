/*
conexiones 
scl ---puerto analogico A5
sda ---puerto analogico A4
puero data de la Resistencia --- A0
*/



//Librerias necesarias
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);
float promedio[4];
float medicionprom=0, Filtroprom=0, medicionCMS=0, Medicionmm=0;

void setup()
{
  //Iniciamos el fondo retroiluminado
  lcd.backlight();
  //Iniciamos la pantalla
  lcd.init();
}


void loop()
{

  int i;
  for(i=0;i<3;i++)
      { 
  promedio[i] = analogRead(A0); 
  medicionprom =promedio[i]+medicionprom;
      }
      
  Filtroprom = medicionprom/4;
  medicionCMS= (((Filtroprom*0.00488)-0.0234)/1.625);
  Medicionmm= medicionCMS*10;
    
  lcd.clear();
  lcd.print("Medida de deformacion");
  lcd.setCursor(0,1);
  lcd.print(Medicionmm);
  
  
  delay(1000);
  
}
