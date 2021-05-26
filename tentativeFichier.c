#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    FILE* fichier = NULL;
    FILE* fichierCode = NULL;
 
    fichier = fopen("test.txt", "r");
    fichierCode = fopen("testCode.txt", "w");
 
    if (fichier != NULL && fichierCode != NULL)
    {
        while((fgetc(fichier)) != EOF){
            fseek(fichier, -1, SEEK_CUR);
            fputc(fgetc(fichier), fichierCode);
        }
        fclose(fichier);
        fclose(fichierCode);
    }
 
    return 0;
}