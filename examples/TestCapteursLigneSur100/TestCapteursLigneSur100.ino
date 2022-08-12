/*
 code généré pour ARDUINO par UniBot!!! 
*/

// déclaration des librairies utilisées
#include <BoumBot.h>

//declaration des variables
BoumBot boumbot;


//initialisation des données du programme
void setup(){
Serial.begin(9600);

boumbot.initialise();


}
//methode principale, le programme boucle dessus
void loop()
{
Serial.println("Numero de serie");
Serial.println(boumbot.numSerie());
Serial.println("Valeur capteurs Gauche et Droit (sur 100)");
Serial.println(boumbot.capteurGauche());
Serial.println(boumbot.capteurDroit());
delay( 1000 );
}
