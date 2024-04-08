#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

int main(){
	char cadena[30];
	int vocal = 0,x;
	printf("Ingrese la cadena de caracteres: ");
	scanf("%s",&cadena);
	
	for(x = 0; x < 30; x++){
		if(cadena[x] == 'a' || cadena[x] == 'e' || cadena[x] == 'i' || cadena[x] == 'o' || cadena[x] == 'u'){
			vocal++;
		}
	}
	
	system("cls");
	printf("Su palabra es: '%s' y tiene un total de '%d' vocal/es",cadena,vocal);}
