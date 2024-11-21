/*


Codigo para aprender a utilizar una pantarra lcd mediate i2c.
*/

//Pantalla 20x4 

//Librerias necesarias
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);



void setup()
{
  //Iniciamos el fondo retroiluminado
  lcd.backlight();
  //Iniciamos la pantalla
//  lcd.init();
}


void loop()
{
  lcd.clear();//Limpiamos la LCD
  lcd.print("WWW.FROSTCODE.ES");//Escribimos en la primera linea
  lcd.setCursor(0,1);//Saltamos a la segunda linea
  lcd.print("WWW.FROSTCODE.ES");//Escribimos en la segunda linea
  
  
  //Tiempo de espera para que reinicie el ciclo
  delay(1000);
  
}
