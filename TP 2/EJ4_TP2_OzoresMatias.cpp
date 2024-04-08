#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

int main(){
	char cadena[50];
	char car,reemp;
	int x;
	printf("Ingrese la cadena de caracteres: ");
	gets(cadena);
	getch();
	system("cls");
	printf("Ingrese la letra que desea cambiar: ");
	scanf("%c",&car);
	fflush(stdin);

	printf("Ingrese la letra por la que se desea cambiar: ");
	scanf("%c",&reemp); 
	
	
	

	system("pause");
	
	for(x = 0; x < strlen(cadena); x++){
		if(cadena[x] == car){
			cadena[x] = reemp;
		}
	}
	system("cls");
	printf("Su palabra modificada queda asi: %s",cadena);
}
