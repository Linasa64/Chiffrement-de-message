/******************************************************************************
*  ASR => M2101                                                               *
*******************************************************************************
*                                                                             *
*  N° de Sujet : 3                                                            *
*                                                                             *
*******************************************************************************
*                                                                             *
*  Intitulé : Chiffrement de messages                                         *
*                                                                             *
*******************************************************************************
*                                                                             *
*  Nom-prénom1 : Asala Dikra Lakhdar Barka                                    *
*                                                                             *
*  Nom-prénom2 : Lina Borg                                                    *
*                                                                             *
*******************************************************************************
*                                                                             *
*  Nom du fichier : main.c                                                    *
*                                                                             *
******************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "vigenere.h"
#include "cesar.h"
#include "fonctionsCommunes.h"

void main() {


    printf("\n                       *** Bienvenue dans l'application de codage / décodage de messages ! ***\n\n");
    printf("************************************************************************************************************************\n");
    printf("*                                       *            CODAGE CESAR            *           CODAGE VIGENERE               *\n");
    printf("************************************************************************************************************************\n");
    printf("* Saisir une phrase dans le terminal    *  1 : Coder     *   2 :  Décoder    *   3 :  Coder     *   4 :  Décoder       *\n");
    printf("************************************************************************************************************************\n");
    printf("* Texte long (fichier .txt)             *  5 : Coder     *   6 : Décoder     *   7 : Coder      *   8 :  Décoder       *\n");
    printf("************************************************************************************************************************\n\n");


    // Sélection d'un choix
    printf("CHOISISSEZ UNE OPTION: ");
    int choix=0;
    scanf("%d", &choix);
    printf("\n");

    // Ouverture des fichiers .txt à coder/décoder

    FILE* fichier = NULL;
    FILE* fichierCode = NULL;
 
    fichier = fopen("texte.txt", "r");
    fichierCode = fopen("texteCode.txt", "w");

    // Définition des variables qui vont être utiles dans le switch
    int decalage;
    char cle[26];
    char* message = NULL;
    int poubelle;

    // Switch qui réoriente vers les actions correspondant aux choix possibles
    // Vérification et affichage de messages d'erreurs
    switch (choix){
        case 1:; // Codage Cesar chaîne
            poubelle = getchar();
            printf("Saisir la chaine de caractères à traiter : ");
            message = saisieChaine();
            if(verificationAlphanumeriqueChaine(message)==1){
                printf("Erreur : La chaîne saisie n'est pas correcte.\n");
                break;
            }
            printf("Saisissez le décalage du message : ");
            decalage = getDecalageCesar();
            if (decalage <0 || decalage >26){
                do {
                    printf("Le décalage doit être compris entre 0 et 26\n");
                    printf("Saisissez le décalage du message : ");
                    scanf("%d", &decalage);
                } while (decalage <0 || decalage >26);
            }
            printf("Voici le message codé : ");
            afficherChaine(codageCesarChaine(message, decalage));
            break;
        
        case 2:; // Decodage Cesar chaîne
            poubelle = getchar();
            printf("Saisir la chaine de caractères à traiter : ");
            message = saisieChaine();
            if(verificationAlphanumeriqueChaine(message)==1){
                printf("Erreur : La chaîne saisie n'est pas correcte.\n");
                break;
            }
            printf("Saisissez le décalage du message : ");
            decalage = getDecalageCesar();
            if (decalage <0 || decalage >26){
                do {
                    printf("Le décalage doit être compris entre 0 et 26\n");
                    printf("Saisissez le décalage du message : ");
                    scanf("%d", &decalage);
                } while (decalage <0 || decalage >26);
            }
            printf("Voici le message décodé : ");
            afficherChaine(deCodageCesarChaine(message, decalage));
            break;
        
        case 3:; // Codage Vigenere chaîne
            poubelle = getchar();
            printf("Saisir la chaine de caractères à traiter : ");
            message = saisieChaine();
            if(verificationAlphanumeriqueChaine(message)==1){
                printf("Erreur : La chaîne saisie n'est pas correcte.\n");
                break;
            }
            printf("Saisissez la clé : ");
            scanf("%s", cle);
            if(verificationAlphanumeriqueChaine(message)==1){
                printf("\nErreur : La chaîne saisie n'est pas correcte.\n");
                break;
            }
            if(verifierCaracteresMinusculesCle(cle)==1){
                printf("Erreur : La clé saisie n'est pas correcte. Vérifiez qu'elle soit bien en minuscules.\n");
                break;
            }
            printf("Voici le message codé : ");
            afficherChaine(codageVigenereChaine(message, cle));
            break;
        
        case 4:; // Decodage Vigenere chaîne
            poubelle = getchar();
            printf("Saisir la chaine de caractères à traiter : ");
            message = saisieChaine();
            if(verificationAlphanumeriqueChaine(message)==1){
                printf("\nErreur : La chaîne saisie n'est pas correcte.\n");
                break;
            }
            printf("Saisissez la clé : ");
            scanf("%s", cle);
            if(verificationAlphanumeriqueChaine(message)==1){
                printf("\nErreur : La chaîne saisie n'est pas correcte.\n");
                break;
            }
            if(verifierCaracteresMinusculesCle(cle)==1){
                printf("Erreur : La clé saisie n'est pas correcte.\nVérifiez qu'elle soit bien en minuscules.\n");
                break;
            }
            printf("Voici le message décodé : ");
            afficherChaine(deCodageVigenereChaine(message, cle));
            break;
        
        case 5:; // Codage César fichier
            printf("Saisissez le décalage du message : ");
            decalage = getDecalageCesar();
            if (decalage <0 || decalage >26){
                do {
                    printf("Le décalage doit être compris entre 0 et 26\n");
                    printf("Saisissez le décalage du message : ");
                    scanf("%d", &decalage);
                } while (decalage <0 || decalage >26);
            }
            ecrireEtCoderFichierCesar(fichier, fichierCode, decalage);
            break;
        
        case 6:; // Decodage Cesar fichier
            printf("Saisissez le décalage du message : ");
            decalage = getDecalageCesar();
            if (decalage <0 || decalage >26){
                do {
                    printf("Le décalage doit être compris entre 0 et 26\n");
                    printf("Saisissez le décalage du message : ");
                    scanf("%d", &decalage);
                } while (decalage <0 || decalage >26);
            }
            ecrireEtDecoderFichierCesar(fichier, fichierCode, decalage);
            break;
        
        case 7:; // Codage Vigenere fichier
            cle[26];
            printf("Quelle est la clé ? ");
            scanf("%s", cle);
            if(verificationAlphanumeriqueChaine(message)==1){
                printf("\nErreur : La chaîne saisie n'est pas correcte.\n");
                break;
            }
            if(verifierCaracteresMinusculesCle(cle)==1){
                printf("Erreur : La clé saisie n'est pas correcte.\nVérifiez qu'elle soit bien en minuscules.\n");
                break;
            }
            ecrireEtCoderFichierVigenere(fichier, fichierCode, cle);
            break;
        
        case 8:; // Decodage Vigenere fichier
            cle[26];
            printf("Quelle est la clé ? ");
            scanf("%s", cle);
            if(verificationAlphanumeriqueChaine(message)==1){
                printf("\nErreur : La chaîne saisie n'est pas correcte.\n");
                break;
            }
            if(verifierCaracteresMinusculesCle(cle)==1){
                printf("Erreur : La clé saisie n'est pas correcte.\nVérifiez qu'elle soit bien en minuscules.\n");
                break;
            }
            ecrireEtDecoderFichierVigenere(fichier, fichierCode, cle);
            break;
        
        default:;
            printf("Erreur : L'option saisie n'existe pas.");
            break;
    }
}