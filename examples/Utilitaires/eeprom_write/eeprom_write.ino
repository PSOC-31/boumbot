/*
   EEPROM Write

   Stores values read from analog input 0 into the EEPROM.
   These values will stay in the EEPROM when the board is
   turned off and may be retrieved later by another sketch.
*/

#include <EEPROM.h>

// the current address in the EEPROM (i.e. which byte
// we're going to write to next)
int addr = 0;

struct Eeprom
{
  int numSerie = 16 ;
  int GaucheBlanc = 143 ;
  int GaucheNoir = 389 ;
  int DroitBlanc = 133 ;
  int DroitNoir = 399 ;
} ;



void setup()
{
  Eeprom MemBoumBot ;

  EEPROM.put ( 0 , MemBoumBot);

//EEPROM.put ( 1023,0 ) ;

  
}

void loop()
{

}
