#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "vigenere.h"
#include "fonctionsCommunes.h"

int getDecalageVigenere(char* cle, int position){
    return cle[((position)%strlen(cle))]-97;
}

char codageVigenereChar(char* cle, char c, int decalage) {

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

char deCodageVigenereChar(char* cle, char c, int decalage) {

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

void ecrireEtCoderFichierVigenere (FILE* fichier, FILE* fichierCode, char* cle){
    if (fichier != NULL && fichierCode != NULL)
    {
        char c;
        int i = 0;
        char codee;
        while((fgetc(fichier)) != EOF){
            fseek(fichier, -1, SEEK_CUR);
            c = fgetc(fichier);
            codee = codageVigenereChar(cle, c, getDecalageVigenere(cle, i));
            
            if(getAsciiValueChar(c)>=65 && getAsciiValueChar(c)<=90 || getAsciiValueChar(c)>=97 && getAsciiValueChar(c)<=122){
                i++;

            }
            
            fputc(codee, fichierCode); // essayer de modifier la fonction codageCesar pour qu'elle prenne en entree directement la valeur ascii entière
        }
        fclose(fichier);
        fclose(fichierCode);
    }
}

void ecrireEtDecoderFichierVigenere (FILE* fichier, FILE* fichierCode, char* cle){
    if (fichier != NULL && fichierCode != NULL)
    {
        char c;
        int i = 0;
        char codee;
        while((fgetc(fichier)) != EOF){
            fseek(fichier, -1, SEEK_CUR);
            c = fgetc(fichier);
            codee = deCodageVigenereChar(cle, c, getDecalageVigenere(cle, i));
            
            if(getAsciiValueChar(c)>=65 && getAsciiValueChar(c)<=90 || getAsciiValueChar(c)>=97 && getAsciiValueChar(c)<=122){
                i++;

            }
            
            fputc(codee, fichierCode); // essayer de modifier la fonction codageCesar pour qu'elle prenne en entree directement la valeur ascii entière
        }
        fclose(fichier);
        fclose(fichierCode);
    }
}