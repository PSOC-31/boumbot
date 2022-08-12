/*
 code généré pour ARDUINO par UniBot!!! 
*/

// declaration des librairies utilisÃ©es
#include <Servo.h>
#include <EEPROM.h>
#include<BoumBot.h>

//declaration des variables
BoumBot boumbot;


//initialisation des données du programme
void setup(){
boumbot.initialise();

Serial.begin(9600);


}
//methode principale, le programme boucle dessus
void loop()
{
Serial.print(boumbot.numSerie());
Serial.print("   ");
Serial.print(boumbot.capteurGauche());
Serial.print("   ");
Serial.println(boumbot.capteurDroit());
delay ( 1000) ;
}


