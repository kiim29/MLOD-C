# Description du projet
- quel jeu a été modifié / étendu ou réalisé ?
- quelle(s) modifications, ... ?
Objectif : Créer un nouveau jeu -> "Où est Greeny ?"
Le jeu se décomposerait en niveaux.
Chaque niveau serait constitué d'une grande carte avec plein d'objets colorés, mais un seul petit rond vert.
Il y a un temps limité pour trouver "Greeny", la petite sphère verte.
Si au bout du temps imparti, le joueur n'a pas cliqué sur Greeny, il perd.
Si le joueur trouve Greeny, il passe au niveau suivant.
Le temps donné pour trouver Greeny raccourcit à chaque niveau, le but est de faire le plus grand nombre de niveaux possible.

A faire : une grande carte, plein de petits objets de formes et couleurs différentes, Greeny
La succession des niveaux, la disposition aléatoire des objets et de Greeny, le déplacement de la carte (zoom, drag etc), s'assurer que Greeny n'est jamais complètement caché
Idéalement : superposition partielle des objets pour que Greeny puisse être un petit peu caché.
Eventuellement : high score et score courant (nombre de niveaux passés), décompte du temps qui fait du bruit...

MISE À JOUR DU 13 NOVEMBRE (jour de rendu) :
Le jeu "Où est Greeny ?" fonctionne. Il n'est finalement pas constitué de niveaux.
Il y a 20 secondes pour cliquer sur le petit cercle vert perdu au milieu de tous les autres cercles colorés.

# Comment compiler
gcc -o main main.c -Wall -std=c11 /home/bot/Raylib.git/src/libraylib.a -lm -lrt -ldl -lX11 -lGL -lpthread

# Comment exécuter
./main

# Comment utiliser le projet
Il suffit d'avoir une souris fonctionnelle. Tout est écrit sur le jeu :
On se déplace sur la carte en utilisant le clic droit et en bougeant la souris.
On zoome et on dézoome avec la molette de la souris.
On trouve Greeny en faisant un clic gauche dessus.

# URL vidéo de démo


# Quelques détails sur votre implémentation
Il n'y a qu'un seul fichier, qui contient quelques fonctions utiles (pour le dessin principalement) et le main.
Dans le main, il y a une initialisation, et une boucle principale pour le jeu.
Dans l'initialisation, on fixe aléatoirement les coordonnées de Greeny et de tous les autres objets.
On initialise aussi la "situation" de base : un entier égal à 0, 1 ou 2 qui indique que le joueur est en train de jouer, qu'il a gagné ou qu'il a perdu.
Dans la boucle de jeu, il y a tout d'abord la gestion du déplacement et du zoom (tirée principalement des exemples-types de raylib), puis la gestion du clic sur Greeny. On utilise pour cela une fonction de raylib pour obtenir la position de la souris par rapport au "World", c'est-à-dire à l'ensemble de la carte, et pas juste par rapport à l'écran, ainsi qu'une focntion annexe qui elle même utilise une fonction de collision avec un cercle fournie par la bibliothèque. Je n'avais au début pas utilisé les fonctions prédéfinies par raylib, mais j'en ai découvertes en cours de route qui effecctuaient exactement les actions dont j'avais besoin (notamment la fonction GetScreenToWorld2D).
Il y a également dans la boucle principale la partie qui gère le décompte, et la partie de dessin.
Pour ce qui est du dessin, il s'appuie sur un switch selon la "situation". Les trois cas représentent 1-la victoire, 2-la défaite parr temps écoulé, et 0-default-le jeu de base.

# Extensions / améliorations possibles
Je n'ai pas eu le temps d'implémenter les niveaux avec des temps limites de plus en plus courts, mais ce serait l'amélioration à faire en premier pour moi. J'ai aussi essayé d'afficher un décompte qui descend au fur et à mesure, mais je n'ai pas trouvée de variantes de la fonction "DrawText" qui permettrait d'afficher une variable dans la fenêtre.