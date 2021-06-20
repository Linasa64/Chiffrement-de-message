# Chiffrement-de-message
Projet réalisé par Asala Dikra Lakhdar Barka et Lina Borg (A1).

Projet disponible ici : https://github.com/Linasa64/Chiffrement-de-message (il est conseillé de lire le readme directement sur la page d'accueil du projet sur GitHub).

Cette application dispose de 8 fonctionnalités distinctes: le codage et décodage en César et Vigenère de saisie de texte ou de fichiers d'extension .txt.

Elle fonctionne avec l'ensemble des caractères, aussi bien lettres que caractères spéciaux de la table ASCII de base, et non étendue.

Cela comprend les lettres majuscules et minuscules que l'application sait distinguer. La casse est donc conservée d'un message à son message codé, et inversement.

Les caractères spéciaux utilisables sont les suivants : ! " # $ % & ' ( ) * + - . / 0 1 2 3 4 5 6 7 8 9 : ; < = > ? @

A noter que les accents ne sont pas pris en compte, et que l'ensemble des textes saisis doivent en être exempts.

## Utilisation de l'application

Il est nécessaire de compiler les fichiers, et pour cela il faut utiliser le makefile fourni, et taper la commande ``make all``.
Ensuite, pour exécuter le programme, il faut taper la commande ``./main``.
Ces commandes nécessitent un terminal sous Linux (bash).

# Documentation des fonctions

## cesar.c

###  •  int getDecalageCesar()
sortie: (entier) nombre de décalage à appliquer

Permet de demander à l'utilisateur le décalage qu'il désire.

###  •  char codageCesarChar(int decalage, char c)
entrée : (entier) nombre de décalage à appliquer en avant
         (caractère) caractère à coder

sortie : (caractère) caractère codé

Permet de coder un caractère avec un décalage donné, modulo 26.
Fonctionne à partir des valeurs ascii des caractères.
Code les majuscules en majuscules et les minuscules en minuscules.
Les caractères spéciaux de la table ASCII de base restent intacts, de même que les espaces qui sont conservés.

###  •  char deCodageCesarChar(int decalage, char c)
entrée : (entier) nombre de décalage à appliquer en arrière
         (caractère) caractère à décoder

sortie : (caractère) caractère décodé

Permet de décoder un caractère avec un décalage connu, modulo 26.
Fonctionne à partir des valeurs ascii des caractères.
Décode les majuscules en majuscules et les minuscules en minuscules.
Les caractères spéciaux de la table ASCII de base restent intacts, de même que les espaces qui sont conservés.

###  •  char* codageCesarChaine(char* string, int decalage)
entrée : (chaîne) chaîne à coder
         (entier) nombre de décalage à appliquer en avant

sortie : (chaîne) chaîne codée

Permet de coder une chaine de caractères, caractère par caractère, en faisant appel à la fonction codageCesarChar.

###  •  char* deCodageCesarChaine(char* string, int decalage)
entrée : (chaîne) chaîne à coder
         (entier) nombre de décalage à appliquer en avant

sortie : (chaîne) chaîne codée

Permet de décoder une chaine de caractères, caractère par caractère, en faisant appel à la fonction deCodageCesarChar

###  •  void ecrireEtCoderFichierCesar (FILE* fichier, FILE* fichierCode, int decalage)
entrée : (fichier txt) fichier contenant le texte à coder
         (fichier txt) fichier dans lequel sera écrit le texte codé
         (entier) nombre de décalage à appliquer en avant

Permet de lire le texte d'un fichier en .txt, d'en lire les caractères un par un, de les coder et d'écrire le résultat codé dans un deuxième fichier texte.

###  •  void ecrireEtDecoderFichierCesar (FILE* fichier, FILE* fichierCode, int decalage)
entrée : (fichier txt) fichier contenant le texte à décoder
         (fichier txt) fichier dans lequel sera écrit le texte décodé
         (entier) nombre de décalage à appliquer en arrière

Permet de lire le texte d'un fichier en .txt, d'en lire les caractères un par un, de les décoder et d'écrire le résultat décodé dans un deuxième fichier texte.


## vigenere.c

###  •  int getDecalageVigenere(char* cle, int position)
entrée : (chaîne) mot clé en minuscule
         (entier) position du caractère

sortie : (entier) décalage à appliquer sur le caractère

Permet de déterminer le décalage à appliquer sur le caractère, en fonction de sa position et du mot clé.
La fonction utilise la valeur ASCII des caractères.

###  •  char codageVigenereChar(char* cle, char c, int decalage)
entrée : (chaîne) mot clé en minuscule
         (caractère) caractère à coder
         (entier) nombre de décalage à appliquer vers l'avant

sortie : (caractère) caractère codé

Permet de coder un caractère avec un décalage donné par une cle, modulo 26.
Fonctionne à partir des valeurs ascii des caractères.
Code les majuscules en majuscules et les minuscules en minuscules.
Les caractères spéciaux de la table ASCII de base restent intacts, de même que les espaces qui sont conservés.

###  •  char* codageVigenereChaine(char* string, char* cle)
entrée : (chaîne) chaîne de caractères à coder
         (chaîne) mot clé en minuscule

sortie : (chaîne) chaîne de caractères codée à partir de la clé donnée

Permet de coder une chaine de caractères, caractère par caractère, en faisant appel à la fonction codageVigenereChar.

###  •  char deCodageVigenereChar(char* cle, char c, int decalage)
entrée : (chaîne) mot clé en minuscule
         (caractère) caractère à décoder
         (entier) nombre de décalage à appliquer vers l'arrière

sortie : (caractère) caractère décodé

Permet de décoder un caractère avec un décalage donné par une cle, modulo 26.
Fonctionne à partir des valeurs ascii des caractères.
Décode les majuscules en majuscules et les minuscules en minuscules.
Les caractères spéciaux de la table ASCII de base restent intacts, de même que les espaces qui sont conservés.

###  •  char* deCodageVigenereChaine(char* string, char* cle)
entrée : (chaîne) chaîne de caractères à décoder
         (chaîne) mot clé en minuscule

sortie : (chaîne) chaîne de caractères décodée à partir de la clé donnée

Permet de décoder une chaine de caractères, caractère par caractère, en faisant appel à la fonction decodageVigenereChar.

###  •  void ecrireEtCoderFichierVigenere (FILE* fichier, FILE* fichierCode, char* cle)
entrée : (fichier txt) fichier contenant le texte à coder
         (fichier txt) fichier dans lequel sera écrit le texte codé
         (chaîne) mot clé en minuscule

Permet de lire le texte d'un fichier en .txt, d'en lire les caractères un par un, de les coder et d'écrire le résultat codé dans un deuxième fichier texte.

###  •  void ecrireEtDecoderFichierVigenere (FILE* fichier, FILE* fichierCode, char* cle)
entrée : (fichier txt) fichier contenant le texte à décoder
         (fichier txt) fichier dans lequel sera écrit le texte décodé
         (chaîne) mot clé en minuscule

Permet de lire le texte d'un fichier en .txt, d'en lire les caractères un par un, de les décoder et d'écrire le résultat décodé dans un deuxième fichier texte.

###  •  int verifierCaracteresMinusculesCle(char* cle)
entrée : (chaîne) mot clé en minuscule

sortie : (entier) valeur de test, 0 si mot clé en minuscule, 1 sinon

Permet de tester si une clé saisie est bien en minuscule.

## fonctionsCommunes.c

###  •  void afficherChaine(const char* string)
entrée : (chaîne) chaîne de caractères à afficher

Permet d'afficher une chaîne de caractères donnée

###  •  int getAsciiValueChar(char ch)
entrée : (caractère) caractère dont on souhaite connaître la valeur ASCII

sortie : (entier) valeur ASCII du caractère

Permet de connaître la valeur ASCII d'un caractère donné

###  •  char* saisieChaine()
sortie : (chaîne) chaîne (son adresse) saisie par l'utilisateur

Permet de demander à l'utilisateur de saisir une chaîne de caractères, et de l'enregistrer.

###  •  int verificationAlphanumeriqueChaine(char* string)
entrée : (chaîne) chaîne de caractères à vérifier

sortie : (entier) 0 si la chaîne est correcte, 1 sinon

Permet de vérifier si une chaîne de caractère ne contient pas de caractères spéciaux qui ne sont pas traités par l'application. 

L'application peut traiter les lettres majuscules et minuscules et sait les distinguer. La casse est donc conservée d'un message à son message codé, et inversement.

Les caractères spéciaux utilisables sont les suivants : ! " # $ % & ' ( ) * + - . / 0 1 2 3 4 5 6 7 8 9 : ; < = > ? @

L'application renvoie 1 (erreur) pour tout autre caractère non mentionné ci-dessus, ce qui comprend nottament les accents.

## main.c et gestion des cas d'erreur
Etant donné qu'il a été demandé de ne pas mettre d'affichage de texte dans les fonctions, il a été choisi de reléguer la gestion des erreurs aux cas du switch, dans le main.

Si une erreur est détectée, alors un message d'information est affichée, puis l'application est arrêtée, ou alors une nouvelle saisie est demandée.

###  • case 1 & 2
- La chaîne saisie contient des caractères spéciaux non traités par l'application (arrêt)
- Le décalage saisi n'est pas compris entre 0 et 26 (nouvelle demande de saisie)

###  • case 3 & 4
- La chaîne saisie contient des caractères spéciaux non traités par l'application (arrêt)
- La clé saisie contient des caractères spéciaux non traités par l'application (arrêt)
- La clé saisie n'est pas entièrement en minuscules (arrêt)

###  • case 5 & 6
 - Le décalage saisi n'est pas compris entre 0 et 26 (nouvelle demande de saisie)

###  • case 7 et 8
- La clé saisie contient des caractères spéciaux non traités par l'application (arrêt)
- La clé saisie n'est pas entièrement en minuscules (arrêt)

###  • default
- Si l'utilisateur saisi un choix qui n'est pas coompris entre 1 et 8, l'application est arrêtée. 