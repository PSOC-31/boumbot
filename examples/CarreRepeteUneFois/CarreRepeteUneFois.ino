/*
 code généré pour ARDUINO par UniBot!!! 
*/

// déclaration des librairies utilisées
#include <BoumBot.h>

//declaration des variables
BoumBot boumbot;
long QuartDeTour=1900 ;
long LongueurCote=1000 ;


//initialisation des données du programme
void setup(){
boumbot.initialise();


}
//methode principale, le programme boucle dessus
void loop()
{
for (int inc_1=0; inc_1 < ( 4 ); inc_1++ )
{
LigneCoin();
}

boumbot.deconnecte();
boumbot.stop();
}

void LigneCoin()
{
boumbot.avance();
delay( LongueurCote );
boumbot.pasADroite();
delay( QuartDeTour );
}
