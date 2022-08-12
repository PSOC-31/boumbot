//Bibliothéque Boum Bot
// GrandTix
// Philippe Martorell
// Pour Planète Sciences
// version du 22/01/2020

#ifndef BoumBot_h
#define BoumBot_h
#include <Servo.h>

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
    //@bloc texte=renvoie la valeur du potentiometre gauche png=boutonGauche.png
    int boutonGauche();
    //@bloc texte=renvoie la valeur du potentiometre droite png=boutonDroit.png
    int boutonDroit();
    //@bloc texte=renvoie le numero de serie du BoumBot png=numSerie.png
    int numSerie();

    
    //@commandes
    //@bloc texte=deconnecte les moteurs png=obstacle.png
    void deconnecte();
    //@bloc texte=connecte les moteurs png=obstacle.png
    void connecte();
    //@bloc texte=arette le programme png=obstacle.png
    void stop();


    //@expert
    // Reperage des pins
    const int pinSG = 9 ;        // ServoMoteur a rotation continue Gauche
    const int pinSD = 8 ;        // ServoMoteur a rotation continue Droit
    
    const int pinSortie = 12 ;   // Buzzer
    
    const int pinZeroG = 0 ;     // Potentiometre reglage servo Gauche
    const int pinZeroD = 1 ;     // Potentiometre reglage servo Droit
    
    const int pinCapteurG = 2 ;  // Capteur de ligne Gauche
    const int pinCapteurD = 3 ;  // Capteur de ligne Droit
    
    const int pinDistance = 4 ;  // Capteur de distance
    
    
    // Constantes de réglage
    const int valLigne = 50 ;    // Point de basculement blanc/noir des capteurs de ligne
    // 15 valeur sans correction Eeprom
    // 50 valeur pour version du 25/2/2018 et au-dela
    const int dObst = 55 ;       // Distance de detection d'obstacles
    
    
    // Structure Eeprom, pour memoriser les reponses des capteurs et les homogeneiser
    struct Eeprom
    {
        int numeroSerie ; // Numero de serie du Boum Bot
        int GaucheBlanc ; // Valeur lue par le capteur de ligne Gauche sur le Blanc (sur 1024)
        int GaucheNoir ;  // Valeur lue par le capteur de ligne Gauche sur le Noir (sur 1024)
        int DroitBlanc ;  // Valeur lue par le capteur de ligne Droit sur le Blanc (sur 1024)
        int DroitNoir ;   // Valeur lue par le capteur de ligne Droit sur le Noir (sur 1024)
    } ;
    Eeprom MemBoumBot ;  // Creation de l'objet memoire Eeprom
    const int debutEeprom = 0 ; // Debut d'adresse de l'objet Eeprom
     
    
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
    int _limiteCapteur(int);
    
};

#endif
