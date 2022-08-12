/*
 code généré pour ARDUINO par UniBot!!! 
*/

// déclaration des librairies utilisées
#include <BoumBot.h>

//declaration des variables
BoumBot boumbot;


//initialisation des données du programme
void setup(){
boumbot.initialise();


}
//methode principale, le programme boucle dessus
void loop()
{
if (boumbot.ligneGauche())
{
boumbot.tourneGauche();
delay( 100 );
}
else
{
if (boumbot.ligneDroit())
{
boumbot.tourneDroite();
delay( 100 );
}
else
{
boumbot.avance();
delay( 100 );
}
}
}
