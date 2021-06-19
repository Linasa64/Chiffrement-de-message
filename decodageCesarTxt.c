#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int getDecalage();
void afficherChaine(const char* string);
int getAsciiValueChar(char ch);
char deCodageCesarChar(int decalage, char c);
char* deCodageCesarChaine(char* string, int decalage);
void ecrireEtCoderFichier (FILE* fichier, FILE* fichierCode, int decalage);

void main() {
    int decalage = getDecalage();

    FILE* fichier = NULL;
    FILE* fichierCode = NULL;
 
    fichier = fopen("test.txt", "r");
    fichierCode = fopen("testCode.txt", "w");

    printf("décodage céssar avec un décalage de %d effectué avec succès.\nConsultez le fichier testCode.txt pour consulter le résultat.\n\n", decalage);
    ecrireEtCoderFichier(fichier, fichierCode, decalage);
}

int getDecalage(){
    int decalage;
    printf("Quel est le décalage du message ?\n");
    scanf("%d", &decalage);
    if (decalage <0 || decalage >26){
        do{
            printf("Le décalage doit être compris entre 0 et 26\n");
            printf("Quel est le décalage du message ?\n");
            scanf("%d", &decalage);
        }while (decalage <0 || decalage >26);
    }
    return decalage;
}

void afficherChaine(const char* string){
    printf("%s\n", string );
}

int getAsciiValueChar(char ch) {
    return "%d", ch;
}

char deCodageCesarChar(int decalage, char c) {
    if(getAsciiValueChar(c)>=32 && getAsciiValueChar(c)<=64 || getAsciiValueChar(c)>=91 && getAsciiValueChar(c)<=96 ||getAsciiValueChar(c)>=123 && getAsciiValueChar(c)<=126){
        return c;
    }
    else if(getAsciiValueChar(c)>=65 && getAsciiValueChar(c)<=90){
        if(getAsciiValueChar(c)-decalage>=65){
            return getAsciiValueChar(c)-decalage;
        }
        else{
            return ((getAsciiValueChar(c)-decalage)+26);
        }
    }
    else if (getAsciiValueChar(c)>=97 && getAsciiValueChar(c)<=122){
        if(getAsciiValueChar(c)-decalage>=97){
            return getAsciiValueChar(c)-decalage;
        }
        else{
            return getAsciiValueChar(c)-decalage+26;
        }
    }
}

char* deCodageCesarChaine(char* string, int decalage){
    char* stringCodee = string;

    for(int i= 0 ; i<strlen(string) ; i++){
        stringCodee[i] = deCodageCesarChar(decalage, string[i]);
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
            codee = deCodageCesarChar(decalage, c);
            fputc(codee, fichierCode); // essayer de modifier la fonction codageCesar pour qu'elle prenne en entree directement la valeur ascii entière
        }
        fclose(fichier);
        fclose(fichierCode);
    }
}