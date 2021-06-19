#include <stdio.h>

int getDecalageVigenere();

char codageVigenereChar(char* cle, char c, int decalage);
char* codageVigenereChaine(char* string, char* cle);

char deCodageVigenereChar(char* cle, char c, int decalage);
char* deCodageVigenereChaine(char* string, char* cle);

void ecrireEtCoderFichierVigenere (FILE* fichier, FILE* fichierCode, char* cle);
void ecrireEtDecoderFichierVigenere (FILE* fichier, FILE* fichierCode, char* cle);

int verifierCaracteresMinusculesCle(char* cle);