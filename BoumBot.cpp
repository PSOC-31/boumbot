/*
  BoumBot.cpp - Library for flashing BoumBot code.
*/

#include <Arduino.h>
#include "BoumBot.h"

BoumBot::BoumBot()
{
  _zeroG = 90;
  _zeroD = 90;
}

void BoumBot::initialise()
{	
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
    //delay(100);
  }
  //}
  son(6);
  delay(500);
}	



void BoumBot::_avanceGauche() {
  _servoG.write(0);
}

void BoumBot::_avanceDroit() {
  _servoD.write(180);
}

void BoumBot::_reculeGauche() {
  _servoG.write(180);
}

void BoumBot::_reculeDroit() {
  _servoD.write(0);
}

void BoumBot::_stopGauche() {
  _servoG.write(_zeroG);
}

void BoumBot::_stopDroit() {
  _servoD.write(_zeroD);
}

void BoumBot::avance() {
    _avanceGauche();
    _avanceDroit();
}

void BoumBot::recule() {
    _reculeGauche();
    _reculeDroit();
}

void BoumBot::arrete() {
    _stopGauche();
    _stopDroit();
}

void BoumBot::tourneDroite() {
    _avanceGauche();
    _reculeDroit();
}

void BoumBot::tourneGauche() {
    _avanceDroit();
    _reculeGauche();
}

void BoumBot::pasADroite() {
    _avanceGauche();
    _stopDroit();
}

void BoumBot::pasAGauche() {
    _stopGauche();
    _avanceDroit();
}


/*
int BoumBot::boutonGauche() {
	return(map(analogRead(pinZeroG) , 0, 1023, 0 , 100));
}
	
int BoumBot::boutonDroit() {
	return(map(analogRead(pinZeroD) , 0, 1023, 0 , 100));
}
*/

void BoumBot::vitesseGauche(int v) {
	int vG = constrain(_zeroG - v, 0, 180);
	_servoG.write(vG);
}

void BoumBot::vitesseDroite(int v) {
	int vD = constrain(_zeroD + v, 0, 180);
	_servoD.write(vD);
}

bool BoumBot::obstacle() {
   return(distance() < dObst);
}

int BoumBot::distance() {
	return(100 - map(analogRead(pinDistance), 0 , 1023, 0, 100));
}


bool BoumBot::ligneGauche() {
  return(capteurGauche() > valLigne);
}

bool BoumBot::ligneDroit() {
  return(capteurDroit() > valLigne);
}


int BoumBot::capteurGauche() {
  return(map(analogRead(pinCapteurG), 0 , 1023, 0, 100));
}

int BoumBot::capteurDroit() {
  return(map(analogRead(pinCapteurD), 0 , 1023, 0, 100));
}


	
void BoumBot::son(int son) {
switch (son) {

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

