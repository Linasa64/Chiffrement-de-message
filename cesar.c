#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "cesar.h"
#include "fonctionsCommunes.h"

int getDecalageCesar(){
    int decalage;
    scanf("%d", &decalage);
    return decalage;
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
            return ((getAsciiValueChar(c)+decalage)-26);
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

char* codageCesarChaine(char* string, int decalage){
    char* stringCodee = string;

    for(int i= 0 ; i<strlen(string) ; i++){
        stringCodee[i] = codageCesarChar(decalage, string[i]);
    }
    return stringCodee;
}

char* deCodageCesarChaine(char* string, int decalage){
    char* stringCodee = string;
    for(int i=0 ; i<strlen(string) ; i++){
        stringCodee[i] = deCodageCesarChar(decalage, string[i]);
    }
    return stringCodee;
}

void ecrireEtCoderFichierCesar (FILE* fichier, FILE* fichierCode, int decalage){
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
        printf("\nCodage César avec un décalage de %d effectué avec succès.\nConsultez le fichier testCode.txt pour voir le résultat.\n\n", decalage);
    }
}

void ecrireEtDecoderFichierCesar (FILE* fichier, FILE* fichierCode, int decalage){
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