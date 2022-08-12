//Bibliothéque Boum Bot
// GrandTix
// Philippe Martorell
// Pour Planète Sciences
// BoumBot.cpp - Library for flashing BoumBot code.
// version du 22/01/2020

#include <Arduino.h>
#include <EEPROM.h>
#include "BoumBot.h"

BoumBot::BoumBot()
{
    _zeroG = 90;
    _zeroD = 90;
}

void BoumBot::initialise()
{	
    //Lit les valeurs dans l' Eeprom
    EEPROM.get ( debutEeprom , MemBoumBot ) ;
    

    // initialise les servos
    _servoG.attach(pinSG);
    _servoD.attach(pinSD);
    arrete();

    
    // initialise le piezzo
    pinMode(pinSortie, OUTPUT);
    digitalWrite(pinSortie, LOW);
    
    // attente avant depart pour reglages
    while(!obstacle())
    {
        _zeroG = map(analogRead(pinZeroG) , 0, 1023, 80 , 100);
        _zeroD = map(analogRead(pinZeroD) , 0, 1023, 80 , 100);
        arrete();
 	delay(100);
    }
    son(6);
    delay(500);
}	



void BoumBot::_avanceGauche()
 {
    _servoG.write(0);
}

void BoumBot::_avanceDroit() 
{ 
    _servoD.write(180);
}

void BoumBot::_reculeGauche() 
{ 
    _servoG.write(180);
}

void BoumBot::_reculeDroit() 
{
    _servoD.write(0);
}

void BoumBot::_stopGauche() 
{
    _servoG.write(_zeroG);
}

void BoumBot::_stopDroit() 
{
    _servoD.write(_zeroD);
}

void BoumBot::avance() 
{
    _avanceGauche();
    _avanceDroit();
}

void BoumBot::recule() 
{
    _reculeGauche();
    _reculeDroit();
}

void BoumBot::arrete() 
{
    _stopGauche();
    _stopDroit();
}

void BoumBot::tourneDroite() 
{
    _avanceGauche();
    _reculeDroit();
}

void BoumBot::tourneGauche() 
{
    _avanceDroit();
    _reculeGauche();
}

void BoumBot::pasADroite() 
{
    _avanceGauche();
    _stopDroit();
}

void BoumBot::pasAGauche() 
{
    _stopGauche();
    _avanceDroit();
}

int BoumBot::boutonGauche() 
{
	return(map(analogRead(pinZeroG) , 0, 1023, 0 , 100));
 }
 	
  int BoumBot::boutonDroit() 
{
 	return(map(analogRead(pinZeroD) , 0, 1023, 0 , 100));
  }
 
void BoumBot::vitesseGauche(int v) 
{
    int vG = constrain(512 - v, 0, 180);
    _servoG.write(vG);
}

void BoumBot::vitesseDroite(int v) 
{
    int vD = constrain(512 - v, 0, 180);
    _servoD.write(vD);
}

bool BoumBot::obstacle() 
{
    return(distance() < dObst);
}

int BoumBot::distance() 
    { 
    unsigned long mesure = 0 ;
    for ( int compteur = 1 ; compteur <= 8 ; compteur ++ )
        {
        mesure = mesure + analogRead(pinDistance) ;
        }
    mesure = mesure >> 3 ;
    return(100 - map(int (mesure), 0 , 1023, 0, 100));
    }


bool BoumBot::ligneGauche() 
{
    return(capteurGauche() > valLigne);
}

bool BoumBot::ligneDroit() 
{
    return(capteurDroit() > valLigne);
}


int BoumBot::capteurGauche() 
{
    
    return (_limiteCapteur(map(analogRead(pinCapteurG), MemBoumBot.GaucheBlanc , MemBoumBot.GaucheNoir, 0, 100))) ;
}

int BoumBot::capteurDroit() 
{
    return( _limiteCapteur(map(analogRead(pinCapteurD), MemBoumBot.DroitBlanc , MemBoumBot.DroitNoir, 0, 100)));
}

int BoumBot::_limiteCapteur(int capteur) 
{
    if ( capteur < 0 )
    {
        capteur = 0 ;
    }
    if ( capteur > 100 )
    {
        capteur = 100 ;
    }
    return ( capteur ) ;
}   

int BoumBot::numSerie() 
{
    return(MemBoumBot.numeroSerie);
}

void BoumBot::deconnecte(void) 
{
    // deconnecte les servos
    arrete();
    _servoG.detach();
    _servoD.detach();
}

void BoumBot::connecte(void) 
{
    // connecte les servos
    _servoG.attach(pinSG);
    _servoD.attach(pinSD);
    arrete();
}

void BoumBot::stop(void) 
{
    // arette le programme
    while (1)
	;
}



void BoumBot::son(int son) 
{
    switch (son) 
{
        
        case 1:
            for(int i=500; i < 1400;i=i+2) {
                digitalWrite(pinSortie, HIGH);
                delayMicroseconds(i);
                digitalWrite(pinSortie, LOW);
                delayMicroseconds(i);
            }
            break;
        case 2:
            for(int i=1400; i > 500;i=i-2) {
                digitalWrite(pinSortie, HIGH);
                delayMicroseconds(i);
                digitalWrite(pinSortie, LOW);
                delayMicroseconds(i);
            }
            break;
        case 3:
            for(int i=1400; i > 500;i=i-2) {
                digitalWrite(pinSortie, HIGH);
                delayMicroseconds(i);
                digitalWrite(pinSortie, LOW);
                delayMicroseconds(i);
            }
            for(int i=500; i < 1400;i=i+2) {
                digitalWrite(pinSortie, HIGH);
                delayMicroseconds(i);
                digitalWrite(pinSortie, LOW);
                delayMicroseconds(i);
            }
            break;
        case 4:
            for(int i=500; i < 1400;i=i+2) {
                digitalWrite(pinSortie, HIGH);
                delayMicroseconds(i);
                digitalWrite(pinSortie, LOW);
                delayMicroseconds(i);
            }
            for(int i=1400; i > 500;i=i-2) {
                digitalWrite(pinSortie, HIGH);
                delayMicroseconds(i);
                digitalWrite(pinSortie, LOW);
                delayMicroseconds(i);
            }
            break;
        case 5:
            for(int i=250; i < 400;i++) {
                digitalWrite(pinSortie, HIGH);
                delayMicroseconds(i*2);
                digitalWrite(pinSortie, LOW);
                delayMicroseconds(i*2);
            }
            for(int i=700; i > 250;i--) {
                digitalWrite(pinSortie, HIGH);
                delayMicroseconds(i);
                digitalWrite(pinSortie, LOW);
                delayMicroseconds(i);
            }
            break;
        case 6:
            for(int i=0; i < 180; i++) {
                digitalWrite(pinSortie, HIGH);
                delayMicroseconds(250);
                digitalWrite(pinSortie, LOW);
                delayMicroseconds(250);
            }
            
            for(int i=250; i < 600; i=i+2) {
                digitalWrite(pinSortie, HIGH);
                delayMicroseconds(i);
                digitalWrite(pinSortie, LOW);
                delayMicroseconds(i);
            }
            for(int i=600; i > 150; i=i-2) {
                digitalWrite(pinSortie, HIGH);
                delayMicroseconds(i);
                digitalWrite(pinSortie, LOW);
                delayMicroseconds(i);
            }  
            break;
        case 7:
            for(int i=1; i < 1000;i=i+1) {
                digitalWrite(pinSortie, HIGH);
                delayMicroseconds(2000);
                digitalWrite(pinSortie, LOW);
                delayMicroseconds(2000);
                digitalWrite(pinSortie, HIGH);
            }
            for(int i=1; i < 1000;i=i+1) {
                delayMicroseconds(1000);
                digitalWrite(pinSortie, LOW);
                delayMicroseconds(1000);
                digitalWrite(pinSortie, HIGH);
            }
            for(int i=1; i < 1000;i=i+1) {
                delayMicroseconds(700);
                digitalWrite(pinSortie, LOW);
                delayMicroseconds(700);
            }
            break;
        case 8:
            for(int i=0; i < 180; i++) {
                digitalWrite(pinSortie, HIGH);
                delayMicroseconds(250);
                digitalWrite(pinSortie, LOW);
                delayMicroseconds(250);
            }
    }
}  

