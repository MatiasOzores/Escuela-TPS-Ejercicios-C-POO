#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

struct conjunto{
	char palabra[100];
};

int main(){
	
	// Declaracion de variables | Esto esta terminado
	
	struct conjunto palabras[5];
	int x,y,letra=0,espaciosCadena=0,mayorCadena=0,ubicacionInicialMayorCadena,longitud=0;
	
	// Ingreso de datos | Esto esta terminado
	
	for(x = 0; x < 5; x++){
		printf("Ingrese su #%d palabra: ",x+1);
		scanf("%s",&palabras[x].palabra);
	}
	
	// Busca la palabra con mas longitud | Esto esta terminado
	for(x = 0; x < 5; x++){
		if(strlen(palabras[x].palabra) >= longitud){
			longitud = strlen(palabras[x].palabra);
		}		
	}

	char cadena[longitud][2];
	
	
	// Inicializa todos los contadores en 0 | Esto esta terminado
	for(x = 0; x<longitud; x++){
		cadena[x][0] = 0;
		cadena[x][1] = 0;
	}
	
	
	// Saca las mayores cantidades | NO TERMINADO falta: que en cualquier parte de la palabra busque la secuencia mas larga que coincida con todas las palabras.
	for(x=0;x<longitud;x++){
		for(y=x;y<longitud;y++){
			if((palabras[0].palabra[y] == palabras[1].palabra[y]) && (palabras[1].palabra[y] == palabras[2].palabra[y]) && (palabras[2].palabra[y] == palabras[3].palabra[y]) && (palabras[3].palabra[y] == palabras[4].palabra[y])){ 
				cadena[espaciosCadena][0]+= 1;
				cadena[espaciosCadena][1] = x;		
			}
			else{
				espaciosCadena++;
				break;
			}		
		}
	}
		
	// Busca la mayor cantidad | Esto esta terminado
	for(x = 0; x<longitud; x++){
		if(cadena[x][0] >= mayorCadena){
			mayorCadena = cadena[x][0];
			ubicacionInicialMayorCadena = x;
		}
	}
		
	// Guarda los valores | Esto esta terminado
	int z = 0;
	char secuencia[mayorCadena];
	
	for(x = ubicacionInicialMayorCadena; x < mayorCadena; x++){
	    secuencia[z] = palabras[0].palabra[x];
	    z++; // Incrementa z para avanzar en el array secuencia
	}
	
	secuencia[z] = '\0';

		
	// Imprime la palabra final | Esto esta terminado
	
	printf("La palabra final: %s",secuencia);

}
