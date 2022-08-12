Note de version BoumBot 12/01/2020
* Nouveau menu UniBot "commandes" ayant les ordres;
	* deconnecte coupe les ordres vers les servomoteurs et les mets en "roue libre"
	* connecte remet les ordres vers les servos moteurs
	* stop arrette le programme
	Pour ces nouvelles fonctions, je dois encore corriger les images associées
* Le menu expert permet l'acces à des variables internes 
* Mise à jour de keywords.txt
* Bug; ou sur-bug. Si on demande d'enregistrer à la première ouverture de UniBot (donc avec rien affiché) il le fait sans hésiter et donc efface l'exemple en mode bloc, sans possibilité de le récupérer. Par contre, l'IDE Arduino interdit d'écrire dans le répertoire exemple. Pour rétablir les exemples blocs, il faut les télécharger à nouveau ou les copier d'un autre PC.

Note de version BoumBot 12/01/2020 12:13
* Pas de tiret du 6 dans les noms d'exemple non plus !

Note de version BoumBot 12/01/2020
* Bibliothéque sans variables byte, remplacé par int
* Pas de nom d'exemple commençant par un chiffre
* Suis preneur d'exemples par bloc
* Ancienne bibliothéque grille non versionnée
* Bug; Premier appel a Unibot n'affiche pas les blocs. Le deuxième appel, oui.
* Bug; A l'apparition des blocs, le code textuel n'apparait pas, il faut faire une modif bloc pour qu'il apparaisse.
