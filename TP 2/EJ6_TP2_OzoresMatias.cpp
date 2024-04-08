#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

struct conjunto{
	char palabra[30];

};

int main(){
	struct conjunto palabras[5];
	int x,y,cont=0;
	
	for(x = 0; x < 5; x++){
		printf("Ingrese su #%d palabra: ",x+1);
		scanf("%s",&palabras[x].palabra);
	}
	
	int palabraMasLarga = strlen(palabras[0].palabra);
	
	for(x = 0; x < 4; x++){
		if(palabraMasLarga <= strlen(palabras[x+1].palabra)){
			palabraMasLarga = strlen(palabras[x+1].palabra);
		}
	}
	
	system("cls");
	
	for(x = 0; x < 5; x++){
		if(palabraMasLarga == strlen(palabras[x].palabra)){
			printf("La cadena mas larga es: %s\n",palabras[x].palabra);
			cont++;
			for(y = x+1; y < 5; y++){
				if(palabraMasLarga == strlen(palabras[y].palabra)){
					cont++;
					printf("Aunque tambien existe otra cadena (%d) con la misma cantidad de caracteres: %s\n",cont,palabras[y].palabra);
				}
			}
			
			break;
		}
	}
}