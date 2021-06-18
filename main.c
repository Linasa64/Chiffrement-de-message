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
    printf("***** CODER *****\n");
    printf("\t1: En codage CESAR\n");
    printf("\t2: En codage VIGENERE\n\n");
    printf("***** DECODER *****\n");
    printf("\t3: En codage CESAR\n");
    printf("\t4: En codage VIGENERE\n\n");

    // Sélection d'un choix
    printf("Choisissez une option: ");
    int choix=0;
    scanf("%d", &choix);

    // Ouverture des fichiers .txt à coder/décoder

    FILE* fichier = NULL;
    FILE* fichierCode = NULL;
 
    fichier = fopen("test.txt", "r");
    fichierCode = fopen("testCode.txt", "w");

    int decalage;
    char cle[26];

    switch (choix){
        case 1:;
            decalage = getDecalageCesar();
            ecrireEtCoderFichierCesar(fichier, fichierCode, decalage);
            break;
        case 2:;
            cle[26];
            printf("Quelle est la clé ?");
            scanf("%s", cle);
            ecrireEtCoderFichierVigenere(fichier, fichierCode, cle);
            break;
        case 3:;
            decalage = getDecalageCesar();
            ecrireEtDecoderFichierCesar(fichier, fichierCode, decalage);
            break;
        case 4:;
            cle[26];
            printf("Quelle est la clé ?");
            scanf("%s", cle);
            ecrireEtDecoderFichierVigenere(fichier, fichierCode, cle);
            break;
    }

}