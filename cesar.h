#include <stdio.h>

int getDecalageCesar();
char codageCesarChar(int decalage, char c);
char* codageCesarChaine(char* string, int decalage);
char* deCodageCesarChaine(char* string, int decalage);
void ecrireEtCoderFichierCesar (FILE* fichier, FILE* fichierCode, int decalage);
void ecrireEtDecoderFichierCesar (FILE* fichier, FILE* fichierCode, int decalage);