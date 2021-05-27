#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* saisieChaine();
void afficherChaine(const char* string);
int getAsciiValueChar(char ch);
char codageCesarChar(int decalage, char c);
char* codageCesarChaine(char* string, int decalage);

void main() {
    int decalage = 6;

    char* string = NULL;
    char* stringCodee = NULL;
    char* stringDeCodee = NULL;

    

    printf("Code César avec un décalage de %d\n\n", decalage);
    string = saisieChaine();
    stringCodee = codageCesarChaine(string, decalage);
    printf("Après codage : ");
    afficherChaine(stringCodee);

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

int getAsciiValueChar(char ch) {
    return "%d", ch;
}

char codageCesarChar(int decalage, char c) {
    if(getAsciiValueChar(c)>=32 && getAsciiValueChar(c)<=64 || getAsciiValueChar(c)>=91 && getAsciiValueChar(c)<=96 ||getAsciiValueChar(c)>=123 && getAsciiValueChar(c)<=126){
        return c;
    }
    else if(getAsciiValueChar(c)>=65 && getAsciiValueChar(c)<=90){
        if(getAsciiValueChar(c)+decalage<=90){
            return getAsciiValueChar(c)+decalage;
        }
        else{
            return getAsciiValueChar(c)+decalage-26;
        }
    }
    else if (getAsciiValueChar(c)>=97 && getAsciiValueChar(c)<=122){
        if(getAsciiValueChar(c)+decalage<=122){
            return getAsciiValueChar(c)+decalage;
        }
        else{
            return getAsciiValueChar(c)+decalage-26;
        }
    }
}

char* codageCesarChaine(char* string, int decalage){
    char* stringCodee = string;

    for(int i= 0 ; i<strlen(string) ; i++){
        stringCodee[i] = codageCesarChar(decalage, string[i]);
    }
    return stringCodee;
}