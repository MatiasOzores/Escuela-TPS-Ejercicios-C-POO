#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

int main(){
	char nombre[30];
	
	printf("Ingrese su nombre: ");
	scanf("%s",&nombre);
	
	system("cls");
	printf("Su nombre es: %s",nombre);
}
