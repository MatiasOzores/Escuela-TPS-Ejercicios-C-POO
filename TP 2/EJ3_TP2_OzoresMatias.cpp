#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

int main(){
	int cont = 0,x;
	char cadena[50];
	printf("Ingrese la cadena de caracteres: ");
	scanf("%s",&cadena);

	for(x = 0; x<strlen(cadena); x++){
		if(cadena[x] == cadena[strlen(cadena)-x-1]) {
			cont++;
		}
	}
	
	if(cont == strlen(cadena)){
		printf("Su palabra es palindromo");
	}
	
	else{
		printf("Su palabra NO es palindromo");
	}

}
