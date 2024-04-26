#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <math.h>

void esPar(int *arreglo, int *longitud, int *contPares, int *contImpares);

int main(){
	int longitud = 4, vector[longitud] = {1,6,13,4},contPares=0,contImpares=0;
	esPar(vector,&longitud,&contPares,&contImpares);
	
	printf("La cantidad de numero son: %d\n",longitud);
	printf("La cantidad de numero pares son: %d\n",contPares);
	printf("La cantidad de numero impares son: %d\n",contImpares);
}

void esPar(int *arreglo, int *longitud, int *contPares, int *contImpares){
	int x_temp;
	
	for(x_temp = 0; x_temp < *longitud; x_temp++){
	
		if(*(arreglo + x_temp) % 2 == 0){
			(*contPares)++;
		}
			
		else{
			(*contImpares)++;
		}			
	}
}