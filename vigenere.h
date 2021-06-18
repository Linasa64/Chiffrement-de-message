#include <stdio.h>

int getDecalageVigenere();
char codageVigenereChar(char* cle, char c, int decalage);
char deCodageVigenereChar(char* cle, char c, int decalage);
void ecrireEtCoderFichierVigenere (FILE* fichier, FILE* fichierCode, char* cle);
void ecrireEtDecoderFichierVigenere (FILE* fichier, FILE* fichierCode, char* cle);