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
*  Nom du fichier : vigenere.h                                                *
*                                                                             *
******************************************************************************/

#include <stdio.h>

int getDecalageVigenere();

char codageVigenereChar(char* cle, char c, int decalage);
char* codageVigenereChaine(char* string, char* cle);

char deCodageVigenereChar(char* cle, char c, int decalage);
char* deCodageVigenereChaine(char* string, char* cle);

int ecrireEtCoderFichierVigenere (FILE* fichier, FILE* fichierCode, char* cle);
int ecrireEtDecoderFichierVigenere (FILE* fichier, FILE* fichierCode, char* cle);

int verifierCaracteresMinusculesCle(char* cle);