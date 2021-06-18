#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int getDecalage();
void afficherChaine(const char* string);
int getAsciiValueChar(char ch);
char conversionAccentsCommuns(wchar_t c);
char codageCesarChar(int decalage, char c);
char* codageCesarChaine(char* string, int decalage);
void ecrireEtCoderFichier (FILE* fichier, FILE* fichierCode, int decalage);

void main() {
    int decalage = getDecalage();

    FILE* fichier = NULL;
    FILE* fichierCode = NULL;
 
    fichier = fopen("test.txt", "r");
    fichierCode = fopen("testCode.txt", "w");
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

char conversionAccentsCommuns(wchar_t c){
  switch (c){
  case L'à':
    return 'a';

  default:
    return c;
  }
}

char codageCesarChar(int decalage, char charAccent) {

    char c = conversionAccentsCommuns((wchar_t) charAccent);
    
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
        printf("\nCodage César avec un décalage de %d effectué avec succès.\nConsultez le fichier testCode.txt pour voir le résultat.\n\n", decalage);

    }
}