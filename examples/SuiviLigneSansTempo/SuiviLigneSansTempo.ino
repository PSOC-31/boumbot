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
boumbot.pasAGauche();
}
else
{
if (boumbot.ligneDroit())
{
boumbot.pasADroite();
}
else
{
boumbot.avance();
}
}
}
