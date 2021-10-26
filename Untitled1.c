#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
unsigned int getvalue(char entree)      //fonction pour convertir le carctre en un nombre :)
{
  switch(entree)
  {

    case '0' : return 0;
               break;
    case '1' : return 1;
               break;
    case '2' : return 2;
               break;
    case '3' : return 3;
               break;
    case '4' : return 4;
               break;
    case '5' : return 5;
               break;
    case '6' : return 6;
               break;
    case '7' : return 7;
               break;
    case '8' : return 8;
               break;
    case '9' : return 9;
               break;


    case 'A' :
    case 'a' : return 10;
               break;
    case 'B' :
    case 'b' : return 11;
               break;
    case 'C' :
    case 'c' : return 12;
               break;
    case 'D' :
    case 'd' : return 13;
               break;
    case 'E' :
    case 'e' : return 14;
               break;
    case 'F' :
    case 'f' : return 15;
               break;
    case 'G' :
    case 'g' : return 16;
               break;
    case 'H' :
    case 'h' : return 17;
               break;
    case 'I' :
    case 'i' : return 18;
               break;
    case 'J' :
    case 'j' : return 19;
               break;
    case 'K' :
    case 'k' : return 20;
               break;
    case 'L' :
    case 'l' : return 21;
               break;
    case 'M' :
    case 'm' : return 22;
               break;
    case 'N' :
    case 'n' : return 23;
               break;
    case 'O' :
    case 'o' : return 24;
               break;
    case 'P' :
    case 'p' : return 25;
               break;
    case 'Q' :
    case 'q' : return 26;
               break;
    case 'R' :
    case 'r' : return 27;
               break;
    case 'S' :
    case 's' : return 28;
               break;
    case 'T' :
    case 't' : return 29;
               break;
    case 'U' :
    case 'u' : return 30;
               break;
    case 'V' :
    case 'v' : return 31;
               break;
    case 'W' :
    case 'w' : return 32;
               break;
    case 'X' :
    case 'x' : return 33;
               break;
    case 'Y' :
    case 'y' : return 34;
               break;
    case 'Z' :
    case 'z' : return 35;
               break;
    default : return 40;
              //exit(0);
  }
}


int check_string(char T[],int n,int B) {
int check1=0, check2=0,i,D;
for(i=0;i<n;i++) { // incrementation de compteur au cas ou on tape qlqchose bizzare
    D=getvalue(T[i]);
    if(D>=B && D<40) { // des caracteres alphanumeriques mais hors de base origine
        check1++;
    }
    else if (D==40) { // cas ou on saisit des caracteres non alphanumeriques comme (,.'=" ...
        check2++;
    }
}


//Descussion des cas possible d'entree
//1ere cas ===> hors de base
if(check1!=0 && check2==0) {
    return 1;
}

// 2eme cas ===> caractere non alphanumeriques
else if ( check2!=0) {
    return 2;
}

// 3eme cas ===> caractere acceptable ( dans la base origine )
else if ( check1==0 && check2==0) {
    return 3;
}


}


int main() {
    int n ,B ,v,i,j;
    char T[250];
    printf("BONJOUR :) ");
    printf("Saisir la base d'origine ==>  ");
    scanf("%d",&B);
    printf("Veuillez vous svp entrer le numero a convertir  :   ");
    scanf("%s",&T);
    n=strlen(T);
    v=check_string(T,n,B);
    printf("===> %d", v);


while(v==1 || v==2) {
    if(v==1) {
            system("cls");
            printf("!!!!!! ATTENTION [ERREUR COMMIS]\n");
            printf("le chiffre que vous essayez de taper est hors de la base origine \n");
            printf("---------------------------------------------------------------------\n");
            printf("---------------------------------------------------------------------\n");
            printf("Veuillez vous svp retaper seulement les caracters dans la base ==>  %d\n",B);
            printf("Saisir le numero que voulez vous convertir autre fois :  ");
            scanf("%s",&T);
            n=strlen(T);
            v=check_string(T,n,B);
    }
    if(v==2) {
            system("cls");
            printf("!!!!!! ATTENTION [ERREUR COMMIS]\n");
            printf("la valeur erronee , svp tape seulment les caractere alpha numerique\n Exemple: abC1e5\n");
            printf("---------------------------------------------------------------------\n");
            printf("---------------------------------------------------------------------\n");
            printf("Veuillez vous svp retaper seulement les caracters Alphanumeriques dans la base ==>  %d\n",B);
            printf("Saisir le numero que voulez vous convertir autre fois :  ");
            scanf("%s",&T);
            n=strlen(T);
            v=check_string(T,n,B);

    }
}

// ICI NOUS AVONS NOTRE 1ERE OPERATIONS , C'EST LA CONVERSION VERS LA BASE DECIMAL
        system("cls");
        int Decimal=0;
        for(i=0;i<n;i++){
            int res=1;
            // Cette Boucle a pour l'objectif de calculer power(base,longeurTableau t - (i+1) )
            for(j=n-(i+1);j>0;j--){
                res*=B;
            }
           Decimal = Decimal + getvalue(T[i])*res; // decimal <== c'est le resultat
        }


// CETTE INSTUCTIONS POUR L'AFFICHAGE LE RESULTAT DE 1ERE CONVERSION ( BASE D'ORIGINE vers LA BASE DECIMALE)

        printf("la conversion de ce nombre [[ ");
        for(i=0;i<n;i++) {
            printf("%c",T[i]);
        }
        printf(" ]] en decimale est ==> %d\n",Decimal);
}
