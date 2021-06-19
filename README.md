# Chiffrement-de-message
Codage et décodage de fichiers .txt et de phrases en César et Vigenère


Cette application dispose de 8 fonctionnalités distinctes: le codage et décodage en César et Vigenère de saisie de texte ou de fichiers d'extension .txt.

## Utilisation de l'application

Il est nécessaire de compiler les fichiers, et pour cela il faut utiliser le makefile, et taper la commande ``make all``.
Ensuite, pour exécuter le programme, il faut taper la commande ``./main``.

## Documentation des fonctions

### cesar.c

#### int getDecalageCesar()
sortie: (entier) nombre de décalage à appliquer

Permet de demander à l'utilisateur le décalage qu'il désire.

### char codageCesarChar(int decalage, char c)
entrée : (entier) nombre de décalage à appliquer
         (caractère) caractère à coder
sortie : (caractère) caractère codé

Permet de coder un caractère avec un décalage donné, modulo 26

