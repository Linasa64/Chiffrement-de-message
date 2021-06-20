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
*  Nom du fichier : cesar.h                                                   *
*                                                                             *
******************************************************************************/

#include <stdio.h>

int getDecalageCesar();
char codageCesarChar(int decalage, char c);
char* codageCesarChaine(char* string, int decalage);
char* deCodageCesarChaine(char* string, int decalage);
void ecrireEtCoderFichierCesar (FILE* fichier, FILE* fichierCode, int decalage);
void ecrireEtDecoderFichierCesar (FILE* fichier, FILE* fichierCode, int decalage);