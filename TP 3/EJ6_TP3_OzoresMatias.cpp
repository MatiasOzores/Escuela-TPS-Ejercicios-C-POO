#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

// programa creado de tal manera de que una ocurrencia significa la repitencia entre 2 numeros, osea, cada 2 numeros iguales es 1 ocurrencia

void ocurrencias(int *vec, int *longitud);

int ocurrencia = 0;

int main(){
	int vector[6] = {1,2,5,2,2,2}; 
	int longitud = sizeof(vector) / sizeof(vector[0]);
	ocurrencias(vector,&longitud);
	printf("El numero de ocurrencia es de: %d",ocurrencia);
}

void ocurrencias(int *vec, int *longitud){
	int x_temp,y_temp;
	ocurrencia = 0;
	for(x_temp = 0; x_temp < *longitud; x_temp++){
		for(y_temp = 0; y_temp < *longitud; y_temp++){
			if((*(vec + x_temp) == *(vec + y_temp)) && (x_temp != y_temp) && (*(vec + x_temp) != 10 && *(vec + y_temp) != 10)){
				ocurrencia++;
				*(vec + x_temp) = 10;
				*(vec + y_temp) = 10;
			}
		}
	}
	
	
}