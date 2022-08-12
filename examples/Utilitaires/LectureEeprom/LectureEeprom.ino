//Boum Bot
// Philippe Martorell
// Pour Planète Sciences
// version du 26/2/2018

#include <EEPROM.h>
#include <BoumBot.h>

//declaration des variables
BoumBot boumbot ;


void setup ( )
{
  Serial.begin(9600);
  boumbot.initialise ( ) ;
  EEPROM.get ( boumbot.debutEeprom , boumbot.MemBoumBot ) ;
  Serial.print ( F ( "Num de serie du Boum Bot =\t" ) ) ;
  Serial.println ( "" ) ;
  Serial.print ( F ( "Capteur Gauche Blanc =\t" ) ) ;
  Serial.print ( boumbot.MemBoumBot.GaucheBlanc ) ;
  Serial.println ( "" ) ;
  Serial.print ( F ( "Capteur Droit Blanc =\t" ) ) ;
  Serial.print ( boumbot.MemBoumBot.DroitBlanc ) ;
  Serial.println ( "" ) ;
  Serial.print ( F ( "Capteur Gauche Noir =\t" ) ) ;
  Serial.print ( boumbot.MemBoumBot.GaucheNoir ) ;
  Serial.println ( "" ) ;
  Serial.print ( F ( "Capteur Droit Noir=\t" ) ) ;
  Serial.print ( boumbot.MemBoumBot.DroitNoir ) ;
  Serial.println ( "" ) ;
}

void loop ( )
{
}
