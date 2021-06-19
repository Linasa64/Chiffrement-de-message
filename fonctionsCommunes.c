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
    printf("Saisir la chaine de caractères à traiter : ");
    nbCharLu = getline(&string, &taille, stdin); 
    return string;
}

int verificationAlphanumeriqueChaine(char* string){
    for(int i = 0 ; i < strlen(string) ; i++){
        if(getAsciiValueChar(string[i]<0 || getAsciiValueChar(string[i]>126))){
            return 1;
        }
    }
    return 0;
}