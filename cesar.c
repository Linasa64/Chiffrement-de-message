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
char* deCodageCesar(char* string, int decalage);

void main() {

    int decalage = 6;
    char* string = NULL;
    char* stringCodee;
    char* stringDeCodee;


    printf("Code César avec un décalage de %d\n\n", decalage);
    string = saisieChaine();
    stringCodee = codageCesar(string, decalage);
    printf("Après codage : ");
    afficherChaine(stringCodee);
    stringDeCodee = deCodageCesar(stringCodee, decalage);
    printf("Après décodage : ");
    afficherChaine(stringDeCodee);
}

// Renvoie une string saisie par l'utilisateur
char* saisieChaine(){
    char* string = NULL;
    size_t taille = 0;
    int nbCharLu = 0;
    printf("Saisir le texte à coder : ");
    // il faut les 3 paramètres pour getline, mais ce qui m'intéresse c'est ce qu'on va faire de string 
    //(la fonction est cool parce que elle permet de taper autant qu'on veut jusqu'à ce qu'on tape entrée)
    nbCharLu = getline(&string, &taille, stdin); 
    return string;
}

// Affiche une chaine
void afficherChaine(const char* string){
    printf("%s\n", string );
}

// Affiche un alphabet
//Fonction inutile maintenant, c'était pour vérifier que mon décalage d'alphabet était ok
void afficherAlphabet (char alphabet[]) {
    for(int i =0 ; i<26 ; i++){
        printf("%c", alphabet[i]);
    }
}

//Remplit un tableau avec toutes les lettres de l'alphabet en incrémentant 'a' de i
void getAlphabet(char alphabet[]){
    for(int i=0; i<26; i++) {
            alphabet[i] = 'a'+i;
        }
}

// Décale mon alphabet d'un décalage passé en paramère
void decalageAlphabet(int decalage, char alphabetADecaler[]) {
    char alphabet[26];
    getAlphabet(alphabet);

    //l'alphabet décalé commence à la décalage-ième lettre de l'alphabet normal
    //On va jusqu'à la taille de l'alphabet moins le décalage (parce que après z on a rien)
    for(int i = 0; i<26-decalage ; i++){
        alphabetADecaler[i] = alphabet[i+decalage];
    }
    //On continue ensuite de remplir l'alphabet décalé avec les décalage-ièmes premières lettres de l'alphabet normal
    for(int i=0 ; i<decalage ; i++){
        alphabetADecaler[26-decalage+i]=alphabet[i];
    }
}

//Renvoie la position dde la lettre lettre daans un alphabet
int chercherOccurence(char lettre, char alphabet[]) {
    for(int i = 0 ; i<26; i++){
        if(alphabet[i]==lettre){
            return i;
        }
    }
}

//Renvoie le caractère à la position position d'un alphabet
char chercherLettrePosition(int position, char alphabet[]) {
    return alphabet[position];
}

//Algorithme de codage en César d'une chaine string avec un décalage décalage
char* codageCesar(char* string, int decalage){
    char alphabet[26];
    char alphabetDecale[26];
    char* stringCodee = string;

    //Initilaisation de mes alphabets (normal et décalé)
    getAlphabet(alphabet);
    decalageAlphabet(decalage, alphabetDecale);

    //Pour chaque lettre de ma chaine, je cherche sa position dans l'alphabet normal,
    //et je met la lettre correspondant à cette position de l'alphabet décalé dans la chaine codée
    for(int i= 0 ; i<strlen(string) ; i++){
        stringCodee[i] = chercherLettrePosition(chercherOccurence(string[i], alphabet), alphabetDecale);
    }
    return stringCodee;
}

//Algorithme de décodage en César d'une chaine string avec un décalage décalage
char* deCodageCesar(char* string, int decalage){
    char alphabet[26];
    char alphabetDecale[26];
    char* stringDeCodee = string;

    getAlphabet(alphabet);
    decalageAlphabet(decalage, alphabetDecale);

    //Pareil à l'envers (en inversant l'ordre des alphabets (normal et décalé)
    for(int i= 0 ; i<strlen(string) ; i++){
        stringDeCodee[i] = chercherLettrePosition(chercherOccurence(string[i], alphabetDecale), alphabet);
    }
    return stringDeCodee;
}
