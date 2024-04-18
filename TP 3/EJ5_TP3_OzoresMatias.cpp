#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <iostream>


// programa creado suponiendo que una cadena = palabras (y no una frase) ya que una cadena puede tener o no tener espacios y lo interprete en el caso de que no tenga

using namespace::std;

int x,y,z;

void concatenacion(char *cadena1, char *cadena2, char *cadena3, int *longcadena3);

int main(){
	
	char cadena1[50];
	char cadena2[50];
	printf("Ingrese su primer cadena: ");
	scanf("%s", &cadena1);
	
	printf("Ingrese su segunda cadena: ");
	scanf("%s", &cadena2);
	
	int longcadena3 = strlen(cadena1) + strlen(cadena2);
	char cadena3[longcadena3];
	concatenacion(cadena1,cadena2,cadena3,&longcadena3);

	printf("Su cadena es la siguiente: ");
	for(x = 0; x < longcadena3; x++){
		printf("%c",*(cadena3 + x));
	}
	
	return 0;
}

void concatenacion(char *cadena1, char *cadena2, char *cadena3, int *longcadena3){

	for(x = 0; x < strlen(cadena1); x++){
		*(cadena3 + x) = *(cadena1 + x);
	}
	
	z=0;
	
	for(y = strlen(cadena1); y < *longcadena3; y++){
		*(cadena3 + y) = *(cadena2 + z);
		z++;
	}		
}

