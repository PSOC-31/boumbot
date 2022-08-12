/*
   EEPROM Read

   Reads the value of each byte of the EEPROM and prints it
   to the computer.
   This example code is in the public domain.
*/

#include <EEPROM.h>


struct Eeprom
{
  int numeroSerie ;
  int GaucheBlanc ;
  int GaucheNoir ;
  int DroitBlanc ;
  int DroitNoir ;
} ;


void setup()
{
  Serial.begin ( 9600 ) ;
  Eeprom MemBoumBot ;
  EEPROM.get ( 0 , MemBoumBot ) ;
  Serial.print ( "numSerie = " ) ;
  Serial.println ( MemBoumBot.numeroSerie ) ;
  Serial.print ( "GaucheBlanc = " ) ;
  Serial.println ( MemBoumBot.GaucheBlanc ) ;
  Serial.print ( "GaucheNoir = " ) ;
  Serial.println ( MemBoumBot.GaucheNoir ) ;
  Serial.print ( "numSerie = " ) ;
  Serial.println ( MemBoumBot.DroitBlanc ) ;
  Serial.print ( "DroitNoir = " ) ;
  Serial.println ( MemBoumBot.DroitNoir ) ;




  for ( byte address = 0 ; address < 30 ; address ++ )
  {
    word value = EEPROM.read ( address ) ;

    Serial.print(address);
    Serial.print("\t");
    Serial.print(value, DEC);
    Serial.println();

  }
}

void loop()
{
}
