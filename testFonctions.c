#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* saisieChaine();
void afficherChaine(const char* string);

int main(){

    char* message = NULL;
    message = saisieChaine();
    afficherChaine(message);

}

char* saisieChaine(){
    char* string = NULL;
    size_t taille = 0;
    int nbCharLu = 0;
    printf("Saisir le texte à coder : ");
    nbCharLu = getline(&string, &taille, stdin); 
    return string;
}

void afficherChaine(const char* string){
    printf("%s\n", string );
}