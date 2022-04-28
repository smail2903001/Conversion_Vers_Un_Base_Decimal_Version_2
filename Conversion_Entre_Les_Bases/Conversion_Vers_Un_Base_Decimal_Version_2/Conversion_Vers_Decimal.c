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
    case 'f' : return 15; // on continue la conversion des caracteres , pour le cas de scalabilite
               break;     // si on veut ajouter des bases > hexadecimale (contient des caracteres comme z,y,t,r)
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



void DecimalVersB(int B, int a){

  	int b, r,q,n = 0 ,i=0;

  	b = a; //b sert sauvgarder la valeur initiale de a

  	do{
  		n++; // c'est la longueur de a on peut utiliser N qu'on a declarer dans main()
    	a = (int)(a/B); // a devient la valeur entiere de a/B a la fin 'a' c'est le dernier quotient non-nul
	  }while(a/B != 0); //tant que a/B differe de 0

  	char T[n]; //declaration d'une chaine de cactere pour conserver le resultats si ka base de conversion est superieur de 10
	int t[n]; //si on a une base de conversion innferieure a 10

  	while(b>=B){//tant que b>=B on va faire
    	r = b % B;// le calcul de reste
    	if(B > 10){//voir si B est superieure a 10 pour remplacer l'entier par son caractere

      		if(r == 10){
        		T[i] = 'A';i++;//incrementation de i et remplacement de b par b/B
      			b = b/B;
      			}
      		else if(r == 11){
        		T[i] = 'B';i++;
      			b = b/B;
      			}
      		else if(r == 12){
        		T[i] = 'C';i++;
      			b = b/B;
      			}
      		else if(r == 13){
        		T[i] = 'D';i++;
      			b = b/B;
      			}
      		else if(r == 14){
        		T[i] = 'E';i++;
      			b = b/B;
      			}
      		else if(r == 15){
        		T[i] = 'F';i++;
      			b = b/B;
      			}
      		else {//si le reste est inferieur a 10 on va utiliser la fonction sprintf qui fait la conversion d'un entier a un caractere
    			sprintf(T+i, "%d", r); i++;
      			b = b/B;
				}
    		}

    	else{
      		t[i] = r; i++; //si B<10 on va prendre t des entiers
      		b = b/B;
    	}
  	}

	//a est le dernier reste non nul on le placer dans t[n] ou T[n] si B>10
  	if(B > 10){
  		// meme chose il faut verifier si a est un caractere das les bases B superieur a 10
      	if(a == 10){
        	T[n] = 'A';
      		}
      	else if(a == 11){
        	T[n] = 'B';
      		}
      	else if(a == 12){
        	T[n] = 'C';
      		}
      	else if(a == 13){
        	T[n] = 'D';
      		}
      	else if(a == 14){
        	T[n] = 'E';
      		}
      	else if(a == 15){
        	T[i] = 'F';
      		}
      	else {
      		sprintf(T+n, "%d", a);
    		}
  		}

	else{
    	t[n] = a;
  		}

	//affichage des resultats sous la for (...)B
 	printf("");
	printf("(");
	if(B > 10){//si B>10 il faut afficher la chaine de caracteres
     	 for(i = n; i>=0; i--){
      	printf("%c",T[i]);
  			}
  		}
  	else {
 	   for(i = n; i>=0; i--){
    	printf("%d",t[i]);
      	}

  	  }
    printf(")%d",B);

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
    int n ,B ,B2 ,v,i,j;
    char T[250];
    printf("BONJOUR :) ");
    printf("Saisir la base d'origine ==>  ");
    scanf("%d",&B);
    while(B<2 || B>16) {
            if ( B<2) {
                system("cls");
                printf(":( C'est pas possible d'utiliser ce Base La !!!!\n");
                printf( "Resaisir la base initiale autre fois svp ==>  ");
                scanf("%d",&B);
            }
            else if(B>16) {
                system("cls");
                printf(":) Nous nous sommes desoles cette base n'est pas encore traite\n");
                printf("Resaisir la base initiale autre fois svp ==> ");
                scanf("%d",&B);
            }
    }
    system("cls");
    printf("Saisir la base de conversion ==>  ");
    scanf("%d",&B2);
    while(B2<2 || B2>16) {
            if ( B2<2) {
                system("cls");
                printf(":( C'est pas possible d'utiliser ce Base La !!!!\n");
                printf( "Resaisir la base de conversion autre fois svp ==>  ");
                scanf("%d",&B2);
            }
            else if(B2>16) {
                system("cls");
                printf(":) Nous nous sommes desoles cette base n'est pas encore traite\n");
                printf("Resaisir la base de conversion autre fois svp ==> ");
                scanf("%d",&B2);
            }
    }
    system("cls");
    printf("Veuillez vous svp entrer le numero a convertir  dans la base %d :   ",B);
    scanf("%s",&T);
    n=strlen(T);
    v=check_string(T,n,B);


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
           Decimal = Decimal + getvalue(T[i])*res; // decimal <== c'est le resultat en decimal
        }


// CETTE INSTUCTIONS POUR L'AFFICHAGE LE RESULTAT DE 1ERE CONVERSION ( BASE D'ORIGINE vers LA BASE DEMANDE)
        int a=Decimal ;
        printf("--------------------------------------------------------------------------------------------\n");
        printf("--------------------------------------------------------------------------------------------\n");
        printf("la conversion de ce nombre [[ ");
        for(i=0;i<n;i++) {
            printf("%c",T[i]);
        }
        printf(" ]] De la base %d vers la base %d est ==> ",B,B2);

        DecimalVersB(B2,a);

        printf("\n");
        printf("--------------------------------------------------------------------------------------------\n");
        printf("---------------------------------------------------------------------------------------------\n");
}




