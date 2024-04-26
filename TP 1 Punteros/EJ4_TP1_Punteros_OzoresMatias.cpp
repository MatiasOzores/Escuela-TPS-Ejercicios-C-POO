#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <math.h>

void esPrimo(int *arreglo, int *longitud, int *contPrimos, int *contNoPrimos);

int main(){
	int longitud = 4, vector[longitud] = {1,6,2,3},contPrimos=0,contNoPrimos=0;
	esPrimo(vector,&longitud,&contPrimos,&contNoPrimos);
	
	printf("La cantidad de numero son: %d\n",longitud);
	printf("La cantidad de numero primos son: %d\n",contPrimos);
	printf("La cantidad de numero NO primos son: %d\n",contNoPrimos);
}

void esPrimo(int *arreglo, int *longitud, int *contPrimos, int *contNoPrimos){
	int x_temp,y_temp,cont;
	
	for(y_temp = 0; y_temp < *longitud; y_temp++){
		cont = 0;
		for(x_temp = 1; x_temp <= *(arreglo + y_temp); x_temp++){
			if(*(arreglo + y_temp) % x_temp == 0){
				cont++;
			}
		}
		
		if(cont == 2){
			(*contPrimos)++;
		}
			
		else{
			(*contNoPrimos)++;
		}			
	}
}