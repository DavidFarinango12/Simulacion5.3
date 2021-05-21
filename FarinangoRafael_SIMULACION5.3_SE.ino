/*
 *CAPITULO V: FUNCIONES ESPECIALES
 *CODIGO 21: RUTINA DE REINICIO
 *OBJETIVO: REINICIAR EN DETERMINADO TIEMPO POR MEDIO DE WDT Y EEPROM
 *NOMBRE: RAFAEL FARINANGO
 */

#include <avr/wdt.h>    //librearia wdt
#include <EEPROM.h>

int i;


void setup() {
  Serial.begin(9600);
  Serial.println("DESPIERTO");
  attachInterrupt(0,activacion,LOW);
  i = EEPROM.read(0);

}

void loop() {
  Serial.println(i++);  // aunmento de valor en la variable
  if(i < 255)
    EEPROM.write(0,i);  //almacena en la EEPROM
  else
    i = 0;
  delay(300);
 
}


void activacion(){
  wdt_disable();          //deshabilita wdt
  wdt_enable(WDTO_4S);    //reinicia en 4s    
  
}
