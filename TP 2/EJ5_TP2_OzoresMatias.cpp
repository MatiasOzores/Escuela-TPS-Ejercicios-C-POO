#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

int main(){
	char cadena[30],cadena2[30];
	int anagrama,x,y;
	printf("Ingresa su primer cadena de caracteres: ");
	scanf("%s",&cadena);

	system("cls");

	printf("Ingresa su segunda cadena de caracteres: ");
	scanf("%s",&cadena2);
	
	int z = 0;
	if(strlen(cadena) == strlen(cadena2)){
		for(x = 0; x < strlen(cadena); x++){
			for(y = 0; y < strlen(cadena); y++){
				if(cadena[z] == cadena2[y]){
					z++;
				}
			}	
		}
	}
	
	else{
		anagrama = 0;
	}
	
	if(z == strlen(cadena)){
		anagrama = 1;
	}
	
	system("cls");
	
	if(anagrama == 1){
		printf("Su palabra es anagrama de la otra palabra: '%s' y '%s'",cadena,cadena2);
	}

	else{
		printf("Su palabra NO es anagrama de la otra: '%s' y '%s'",cadena,cadena2);
	}
}