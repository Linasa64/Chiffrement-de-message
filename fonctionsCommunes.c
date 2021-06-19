#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "fonctionsCommunes.h"

void afficherChaine(const char* string){
    printf("%s\n", string );
}

int getAsciiValueChar(char ch) {
    return "%d", ch;
}

char* saisieChaine(){
    char* string = NULL;
    size_t taille = 0;
    int nbCharLu = 0;
    printf("Saisir le texte à coder : ");
    nbCharLu = getline(&string, &taille, stdin); 
    return string;
}