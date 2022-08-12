//Boum Bot
// Philippe Martorell
// Pour Planète Sciences
// version du 26/2/2018

#include <EEPROM.h>
#include <BoumBot.h>

//declaration des variables
BoumBot boumbot ;
int reponseClavier = "" ;
boolean reponseEffectuee = false ;
void setup ( )
{
  Serial.begin ( 9600 ) ;
  Serial.println ( F ( "Placez le Boum Bot sur du blanc et presentez un obstacle" ) ) ;
  boumbot.initialise ( ) ;
  Serial.println ( F ( "Validez la mesure blanche en presentant un obstacle" ) ) ;
  do
  {
    boumbot.MemBoumBot.GaucheBlanc = analogRead ( boumbot.pinCapteurG ) ;
    boumbot.MemBoumBot.DroitBlanc = analogRead ( boumbot.pinCapteurD ) ;
    Serial.print ( F ( "Capteur Gauche Blanc =\t" ) ) ;
    Serial.print ( boumbot.MemBoumBot.GaucheBlanc ) ;
    Serial.print ( F ( "\tCapteur Droit Blanc =\t" ) ) ;
    Serial.print ( boumbot.MemBoumBot.DroitBlanc ) ;
    Serial.println ( "" ) ;
    delay ( 1000 ) ;
  }
  while ( ! boumbot.obstacle ( ) ) ;
  boumbot.son ( 6 ) ;
  delay ( 1000 ) ;
  Serial.println ( F ( "Placez le Boum Bot sur du noir" ) ) ;
  Serial.println ( F ( "Validez la mesure noire en presentant un obstacle" ) ) ;
  do
  {
    boumbot.MemBoumBot.GaucheNoir = analogRead ( boumbot.pinCapteurG ) ;
    boumbot.MemBoumBot.DroitNoir = analogRead ( boumbot.pinCapteurD ) ;
    Serial.print ( F ( "Capteur Gauche Noir =\t" ) ) ;
    Serial.print ( boumbot.MemBoumBot.GaucheNoir ) ;
    Serial.print ( F ( "\tCapteur Droit Noir=\t" ) ) ;
    Serial.print ( boumbot.MemBoumBot.DroitNoir ) ;
    Serial.println ( "" ) ;
    delay ( 1000 ) ;
  }
  while ( ! boumbot.obstacle ( ) ) ;
  boumbot.son ( 6 ) ;
  delay ( 1000 ) ;
  if ( ( boumbot.MemBoumBot.GaucheBlanc < boumbot.MemBoumBot.GaucheNoir ) && ( boumbot.MemBoumBot.DroitBlanc < boumbot.MemBoumBot.DroitNoir ) )
  {
    Serial.println ( "" ) ;
    Serial.println ( "" ) ;
    Serial.print ( F ( "Capteur Gauche Blanc =\t" ) ) ;
    Serial.print ( boumbot.MemBoumBot.GaucheBlanc ) ;
    Serial.print ( F ( "\tCapteur Droit Blanc =\t" ) ) ;
    Serial.print ( boumbot.MemBoumBot.DroitBlanc ) ;
    Serial.println ( "" ) ;
    Serial.print ( F ( "Capteur Gauche Noir =\t" ) ) ;
    Serial.print ( boumbot.MemBoumBot.GaucheNoir ) ;
    Serial.print ( F ( "\tCapteur Droit Noir=\t" ) ) ;
    Serial.print ( boumbot.MemBoumBot.DroitNoir ) ;
    Serial.println ( "" ) ;
    Serial.println ( F ( "Vérifiez l'ensemble des mesures" ) ) ;
    Serial.println ( F ( "et tapez le numero de série du Boum Bot" ) ) ;
    Serial.println ( F ( "dans la ligne superieure de cette fenetre" ) ) ;
    Serial.println ( F ( "et tapez sur \"entree\"" ) ) ;

    while ( Serial.available ( ) <= 0 )
    {
      ;
    }
    boumbot.MemBoumBot.numeroSerie =  int ( Serial.parseInt ( ) ) ;
    Serial.print ( F ( "Reponse clavier =>" ) ) ;
    Serial.print ( boumbot.MemBoumBot.numeroSerie ) ;
    Serial.println ( F ( "<=" ) ) ;
    if ( boumbot.MemBoumBot.numeroSerie > 0 && boumbot.MemBoumBot.numeroSerie < 50 )
    {
      EEPROM.put ( boumbot.debutEeprom , boumbot.MemBoumBot);
      boumbot.son ( 6 ) ;
      Serial.println ( F ( "Etalonnage effectue" ) ) ;
      while ( 1 )
      {
        ;
      }
    }
    else
    {
      erreur ( ) ;
    }
  }
  else
  {
    erreur ( ) ;
  }
}

void loop ( )
{
}


void erreur ( void )
{
  boumbot.son ( 1 ) ;
  delay ( 1000 ) ;
  Serial.println ( F ( "Mesures incoherentes, etalonnage a refaire ( reset )" ) ) ;
  while ( 1 ) ;
}

