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

    //Affichage des choix possibles
    printf("Bienvenue dans l'application de codage-décodage de texte !\n");
    printf("Saisissez l'option que vous souhaitez: \n\n");
    printf("Sur des textes LONGS dans un fichier.txt...\n");
    printf("*********** CODER ***********\n");
    printf("\t1: Coder en CESAR\n");
    printf("\t2: Coder en VIGENERE\n\n");
    printf("********** DECODER *********\n");
    printf("\t3: Décoder en CESAR\n");
    printf("\t4: Décoder en VIGENERE\n\n");
    printf("***************************************************************");
    printf("\n\nSur des textes COURTS à saisir dans le terminal...\n");
    printf("*********** CODER ***********\n");
    printf("\t5: Coder en CESAR\n");
    printf("\t6: Coder en VIGENERE\n\n");
    printf("********** DECODER *********\n");
    printf("\t7: Décoder en CESAR\n");
    printf("\t8: Décoder en VIGENERE\n\n");


    // Sélection d'un choix
    printf("Choisissez une option: ");
    int choix=0;
    scanf("%d", &choix);

    // Ouverture des fichiers .txt à coder/décoder

    FILE* fichier = NULL;
    FILE* fichierCode = NULL;
 
    fichier = fopen("test.txt", "r");
    fichierCode = fopen("testCode.txt", "w");

    // Définition des variables qui vont être utiles dans le switch
    int decalage;
    char cle[26];
    char* message = NULL;

    // Switch qui réoriente vers les actions correspondant aux choix possibles
    switch (choix){
        case 1:; // Codage César fichier
            decalage = getDecalageCesar();
            ecrireEtCoderFichierCesar(fichier, fichierCode, decalage);
            break;
        case 2:; // Codage Vigenere fichier
            cle[26];
            printf("Quelle est la clé ?");
            scanf("%s", cle);
            ecrireEtCoderFichierVigenere(fichier, fichierCode, cle);
            break;
        case 3:; // Decodage Cesar fichier
            decalage = getDecalageCesar();
            ecrireEtDecoderFichierCesar(fichier, fichierCode, decalage);
            break;
        case 4:; // Decodage Vigenere fichier
            cle[26];
            printf("Quelle est la clé ?");
            scanf("%s", cle);
            ecrireEtDecoderFichierVigenere(fichier, fichierCode, cle);
            break;
        case 5:; // Codage Cesar chaîne
            message = saisieChaine(); //WOLA CA MARCHE PAS POURQUOIIIII
            decalage = getDecalageCesar();
            afficherChaine(codageCesarChaine(message, decalage));
    }
}