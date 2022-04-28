#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
unsigned int getvalue(char entree)      //fonction pour convertir un caractère d'entré en un nombre :)
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



    case '+' : return 10;
               break;

    case '-' : return 11;

    default : return 12;

  }
}
int DecimalVersB(double a, char T[]){

  	int r,n = 0,j; // b==> reserve l'entier a convertir       r ==> pour le reste de division .

  	int b = a;
  	while(a>=2){
  		n++; // compteur qui indique la position de premier quotien null
    	a = (int)(a/2);
	  }

  	for(j=0; j<=n;j++){
    			r = b % 2;
    			sprintf(T+j, "%d", r);
      			b = b/2;
    		}// mettre les valeurs binaire dans le tableau T .

    return n;
}
int main(){
    char e=0;
    while(e!='1'){
    system("cls");

	int i,n, checkNeg = 0, checkInput=0;
	char T[256];

	printf("Veuillez vous svp saisir un nombre decimal: \n");



	do {
		checkInput=0;
    	scanf("%s",&T);
    	n=strlen(T);
    	if(n <=9 ){
        for( i = 1; i<n; i++){
		    if(getvalue(T[i])>9){  // ceci montre l'utilisation des conditions simples avec la fonction "getvalue".
			checkInput ++; // incremention de ce compteur si l'utilisateur entre un caractère bizzare.
			}
		}

    	if(getvalue(T[0])==12){
				checkInput ++; // si il a saisi au 1ere position une caractère que '    +   ou   -  ou   decimal_value '.
			}


		if(checkInput !=0 ){
        system("cls");
		printf(" :( VOUS ESSAYER DE TAPER UN NON ENTIER, SVP! TAPER UN ENTIER: ");
		}


		}
		else {
        system("cls");
		printf(" :( VOUS AVEZ DEPASSE LA TAILLE MAXIMALE, SVP! RETAER VOTRE ENTIER : ");
		}
	}while(checkInput != 0 || n>9);






    // on verifier tout d'abord si l'entier est negatif
    if(T[0]=='-'){
		checkNeg = 1;
	}

    printf("Merci de saisir l\'entier ");
    for(i = 0; i<n; i++){
    		printf("%c", T[i]);
		}

	//on declare un tableau initialiser a une longueur n
    char V[n];

    long long  a = atoi(T); //int atoi(T) Cette fonction permet de transformer une cha�ne de caract�res, repr�sentant une valeur enti�re, en une valeur num�rique de type int
    a = abs(a); //pour obtenir la valeur absolue de a
    int N = DecimalVersB(a,V); // la fonction qui fait la conversion de decimale vers le binaire

    char v[N+1];//on voit si l'entier est negatif ou positif pour conserve un bit pour le signe
    if(checkNeg == 1){
    	V[N+1] = '1';
    	for(i = 0; i<=N+1 ; i++){
    	v[i] = V[N+1-i]; //une table qui va etre utilisee dans le ca2 il sert a faire l'inversion de la table V exemple si V[2] = {0,1,2} ==> v[2] = {2,1,0}
		}
	}
	else{
		V[N+1] = '0';
		for(i = 0; i<=N+1 ; i++){
    	v[i] = V[N+1-i]; //une table qui va etre utilisee dans le ca2 il sert a faire l'inversion de la table V exemple si V[2] = {0,1,2} ==> v[2] = {2,1,0}
		}
	}

	//l'affichage de la valeur signe
	printf("\nla valeur signe: ");
    for(i = N+1; i>=0; i--){
    		printf("%c", V[i]);
	}

    //le calcul on inversont tout sauf le signe (le debut de la boucle de N et non pas N+1) et l'affichage du complemebt a 1 si l'entier est negatif
    if(checkNeg == 1){
    	for(i = N; i>=0 ; i--){
    		if(V[i] == '1'){
    			V[i] = '0';
			}
		else{
			V[i] = '1';
			}
		}
	}
    printf("\n");
    printf("le complement a 1 est: ");
    for(i = N+1; i>=0; i--){
    		printf("%c", V[i]);
	}

    //le calcul ca2 cherchant le premmier 1 et inversant tout on inversont tout sauf le signe dans le cas d'un entier negatif
    if(checkNeg == 1){
    	for(i = N+1; i>=1 ; i--){
    		if(v[i] == '1'){ //au cas ou on a trouve un 1 dans la representation binaire (d'indice i
    			for(int j = i-1; j>=1; j--){//on entre dans une boucle allant de i-1 jusqu'a 1 par decrementation de 1
    				if(v[j] == '1'){
    					v[j] = '0';//et on inverse les 1 par 0 et les 0 par 1
				}
					else{
						v[j] = '1';
				}
			}
			break;

		}
	}
	}
	//l'affichage du complemebt a 2
	printf("\nle complement a 2 est: ");
    for(i = 0; i<=N+1; i++){
    	printf("%c", v[i]);
	}
	printf("\n===========================================\n");
	printf("TAPE N'IMPORTE QUOI POUR CONTINUER \n POUR QUITTER LE PROGRAMME TAPE 1 : ");
	scanf("%s",&e);

    }

}
