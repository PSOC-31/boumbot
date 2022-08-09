#ifndef BoumBot_h
#define BoumBot_h

#include <Servo.h>

// reperage des pins

#define pinSG 9
#define pinSD 8

#define pinSortie 12

#define pinZeroG 0
#define pinZeroD 1

#define pinCapteurG 2
#define pinCapteurD 3

#define valLigne 15

#define pinDistance 4
#define dObst 55


class BoumBot
{
  public:
//@initialisation
    //@bloc texte=notre BoumBot png=nouveau.png
    BoumBot();
	//@bloc texte=procédure d'initialisation png=initialise.png
    void initialise();

//@deplacements
    //@bloc texte=fait avancer BoumBot png=avance.png
    void avance();
    //@bloc texte=fait reculer BoumBot png=recule.png
    void recule();
    //@bloc texte=stop BoumBot png=arrete.png
    void arrete();
    //@bloc texte=fait tourner BoumBot à droite png=tourneDroite.png
    void tourneDroite();
    //@bloc texte=fait tourner BoumBot à gauche png=tourneGauche.png
    void tourneGauche();
    //@bloc texte=fait tourner légèrement BoumBot à droite png=PAD.png
    void pasADroite();
    //@bloc texte=fait tourner légèrement BoumBot à gauche png=PAG.png
    void pasAGauche();
    //@bloc texte=fixe la vitesse de la roue gauche png=vitesseGauche.png
    void vitesseGauche(int v);
    //@bloc texte=fixe la vitesse de la roue droite png=vitesseDroite.png
    void vitesseDroite(int v);
    
//@sons
    //@bloc texte=fait emettre un son a BoumBot png=son.png
    void son(int son);
    
//@capteurs
    //@bloc texte=renvoie VRAI si un obstacle est devant BoumBot png=obstacle.png
    bool obstacle();
    //@bloc texte=VRAI si le capteur gauche est sur une ligne noire png=ligneGauche.png
    bool ligneGauche();
    //@bloc texte=VRAI si le capteur droit est sur une ligne noire png=ligneDroit.png
    bool ligneDroit();
    //@bloc texte=renvoie la distance de l'obstacle png=distance.png
    int distance();
    //@bloc texte=renvoie ce que voit BoumBot à gauche png=capteurGauche.png
    int capteurGauche();
    //@bloc texte=renvoie ce que voit BoumBot à droite png=capteurDroit.png
    int capteurDroit();
  private:
    int _zeroG;
    int _zeroD;
    Servo _servoG;
    Servo _servoD;
    void _avanceGauche();
    void _avanceDroit();
    void _reculeGauche();
    void _reculeDroit();
    void _stopGauche();
    void _stopDroit();
};

#endif
