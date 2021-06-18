#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void afficherChaine(const char* string);
int getAsciiValueChar(char ch);


void afficherChaine(const char* string){
    printf("%s\n", string );
}

int getAsciiValueChar(char ch) {
    return "%d", ch;
}