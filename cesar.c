#include <stdio.h>
#include <string.h>

char* saisieChaine();
void afficherChaine(const char* string);
void getAlphabet(char alphabet[]);
void afficherAlphabet (char alphabet[]);
int chercherOccurence(char lettre, char alphabet[]);
char chercherLettrePosition(int position, char alphabet[]);
void decalageAlphabet(int decalage, char alphabetADecaler[]);
char* codageCesar(char* string, int decalage);

void main() {

    int decalage = 6;
    char* string = NULL;
    char* stringCodee;

    printf("Code César avec un décalage de %d\n\n", decalage);
    string = saisieChaine();
    printf("Avant codage : ");
    afficherChaine(string);
    stringCodee = codageCesar(string, decalage);
    printf("Après codage : ");
    afficherChaine(stringCodee);

}

char* saisieChaine(){
    char* string = NULL;
    size_t taille = 0;
    int nbCharLu = 0;
    printf("Saisir le texte à coder :\n");
    nbCharLu = getline(&string, &taille, stdin);
    return string;
}

void afficherChaine(const char* string){
    printf("%s", string );
}

void afficherAlphabet (char alphabet[]) {
    for(int i =0 ; i<26 ; i++){
        printf("%c", alphabet[i]);
    }
    printf("\n");
}

void getAlphabet(char alphabet[]){
    for(int i=0; i<26; i++) {
            alphabet[i] = 'a'+i;
        }
}

void decalageAlphabet(int decalage, char alphabetADecaler[]) {
    char alphabet[26];
    getAlphabet(alphabet);

    for(int i = 0; i<26-decalage ; i++){
        alphabetADecaler[i] = alphabet[i+decalage];
    }
    for(int i=0 ; i<decalage ; i++){
        alphabetADecaler[26-decalage+i]=alphabet[i];
    }
}

int chercherOccurence(char lettre, char alphabet[]) {
    for(int i = 0 ; i<26; i++){
        if(alphabet[i]==lettre){
            return i;
        }
    }
}

char chercherLettrePosition(int position, char alphabet[]) {
    return alphabet[position];
}

char* codageCesar(char* string, int decalage){
    char alphabet[26];
    char alphabetDecale[26];
    char* stringCodee = string;

    getAlphabet(alphabet);
    decalageAlphabet(decalage, alphabetDecale);

    for(int i= 0 ; i<strlen(string) ; i++){
        stringCodee[i] = chercherLettrePosition(chercherOccurence(string[i], alphabet), alphabetDecale);
    }
    return stringCodee;
}
