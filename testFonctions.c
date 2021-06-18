#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char codageVigenereChar(char* cle, char c, int decalage);
int getAsciiValueChar(char ch);

int main(){

  char cle[26];
  printf("Quelle est la clé ?");
  scanf("%s", cle);

  char message[26];
  printf("Quelle est le message ?");
  scanf("%s", message);
  int taille = strlen(cle);
  //printf("%d/n", taille);
  
  int decalage;

  for(int i=0 ; i<strlen(message) ; i++){
    //printf("%d/n", i);
    //printf("%ld/n", strlen(cle));
    decalage = cle[((i)%strlen(cle))]-97;
    //printf("%d\n", decalage);

    printf("%c", codageVigenereChar(cle, message[i], decalage));
  }

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

int getAsciiValueChar(char ch) {
    return "%d", ch;
}