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
boumbot.avance();
while ( !( boumbot.obstacle() ) )
{
delay( 1 );
}

boumbot.arrete();
while ( boumbot.obstacle() )
{
delay( 1 );
}

}
