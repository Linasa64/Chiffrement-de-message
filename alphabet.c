#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* saisieChaine(FILE* fichier);
void afficherChaine(const char* string);
int getAsciiValueChar(char ch);
char codageCesarChar(int decalage, char c);
char* codageCesarChaine(char* string, int decalage);
void ecrireEtCoderFichier (FILE* fichier, FILE* fichierCode, int decalage);

void main() {
    int decalage = 6;

    char* string = NULL;
    char* stringCodee = NULL;
    char* stringDeCodee = NULL;

    FILE* fichier = NULL;
    FILE* fichierCode = NULL;
 
    fichier = fopen("test.txt", "r+");
    fichierCode = fopen("testCode.txt", "w");

    printf("Code César avec un décalage de %d\n\n", decalage);
    string = saisieChaine(fichier);
    //stringCodee = codageCesarChaine(string, decalage);
    //printf("Après codage : ");
    //afficherChaine(stringCodee);

    ecrireEtCoderFichier(fichier, fichierCode, decalage);

}

char* saisieChaine(FILE* fichier){
    char* string = NULL;
    size_t taille = 0;
    int nbCharLu = 0;
    printf("Saisir le texte à coder : ");
    nbCharLu = getline(&string, &taille, stdin);
    fputs(string, fichier); 
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
            return getAsciiValueChar(c)+decalage-65;
        }
    }
    else if (getAsciiValueChar(c)>=97 && getAsciiValueChar(c)<=122){
        if(getAsciiValueChar(c)+decalage<=122){
            return getAsciiValueChar(c)+decalage;
        }
        else{
            return getAsciiValueChar(c)+decalage-97;
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

void ecrireEtCoderFichier (FILE* fichier, FILE* fichierCode, int decalage){
    if (fichier != NULL && fichierCode != NULL)
    {
        char c;
        char codee;
        while((fgetc(fichier)) != EOF){
            fseek(fichier, -1, SEEK_CUR);
            c = fgetc(fichier);
            codee = codageCesarChar(decalage, c);
            fputc(codee, fichierCode); // essayer de modifier la fonction codageCesar pour qu'elle prenne en entree directement la valeur ascii entière
        }
        fclose(fichier);
        fclose(fichierCode);
    }
}