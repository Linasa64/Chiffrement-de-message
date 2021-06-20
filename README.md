# Chiffrement-de-message
Codage et décodage de fichiers .txt et de phrases en César et Vigenère


Cette application dispose de 8 fonctionnalités distinctes: le codage et décodage en César et Vigenère de saisie de texte ou de fichiers d'extension .txt.

## Utilisation de l'application

Il est nécessaire de compiler les fichiers, et pour cela il faut utiliser le makefile, et taper la commande ``make all``.
Ensuite, pour exécuter le programme, il faut taper la commande ``./main``.

# Documentation des fonctions

## cesar.c

### * int getDecalageCesar()
sortie: (entier) nombre de décalage à appliquer

Permet de demander à l'utilisateur le décalage qu'il désire.

### * char codageCesarChar(int decalage, char c)
entrée : (entier) nombre de décalage à appliquer en avant
         (caractère) caractère à coder

sortie : (caractère) caractère codé

Permet de coder un caractère avec un décalage donné, modulo 26.
Fonctionne à partir des valeurs ascii des caractères.
Code les majuscules en majuscules et les minuscules en minuscules.
Les caractères spéciaux de la table ASCII de base restent intacts, de même que les espaces qui sont conservés.

### * char deCodageCesarChar(int decalage, char c)
entrée : (entier) nombre de décalage à appliquer en arrière
         (caractère) caractère à décoder

sortie : (caractère) caractère décodé

Permet de décoder un caractère avec un décalage connu, modulo 26.
Fonctionne à partir des valeurs ascii des caractères.
Décode les majuscules en majuscules et les minuscules en minuscules.
Les caractères spéciaux de la table ASCII de base restent intacts, de même que les espaces qui sont conservés.

### * char* codageCesarChaine(char* string, int decalage)
entrée : (chaîne) chaîne à coder
         (entier) nombre de décalage à appliquer en avant

sortie : (chaîne) chaîne codée

Permet de coder une chaine de caractères, caractère par caractère, en faisant appel à la fonction codageCesarChar.

### * char* deCodageCesarChaine(char* string, int decalage)
entrée : (chaîne) chaîne à coder
         (entier) nombre de décalage à appliquer en avant

sortie : (chaîne) chaîne codée

Permet de décoder une chaine de caractères, caractère par caractère, en faisant appel à la fonction deCodageCesarChar

### * void ecrireEtCoderFichierCesar (FILE* fichier, FILE* fichierCode, int decalage)
entrée : (fichier txt) fichier contenant le texte à coder
         (fichier txt) fichier dans lequel sera écrit le texte codé
         (entier) nombre de décalage à appliquer en avant

Permet de lire le texte d'un fichier en .txt, d'en lire les caractères un par un, de les coder et d'écrire le résultat codé dans un deuxième fichier texte.

### * void ecrireEtDecoderFichierCesar (FILE* fichier, FILE* fichierCode, int decalage)
entrée : (fichier txt) fichier contenant le texte à décoder
         (fichier txt) fichier dans lequel sera écrit le texte décodé
         (entier) nombre de décalage à appliquer en arrière

Permet de lire le texte d'un fichier en .txt, d'en lire les caractères un par un, de les décoder et d'écrire le résultat décodé dans un deuxième fichier texte.


## vigenere.c

### * int getDecalageVigenere(char* cle, int position)
entrée : (chaîne) mot clé en minuscule
         (entier) position du caractère

sortie : (entier) décalage à appliquer sur le caractère

Permet de déterminer le décalage à appliquer sur le caractère, en fonction de sa position et du mot clé.
La fonction utilise la valeur ASCII des caractères.

### * char codageVigenereChar(char* cle, char c, int decalage)
entrée : (chaîne) mot clé en minuscule
         (caractère) caractère à coder
         (entier) nombre de décalage à appliquer vers l'avant

sortie : (caractère) caractère codé

