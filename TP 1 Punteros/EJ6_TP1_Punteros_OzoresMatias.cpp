#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <math.h>

void divisionTerminos(int *arreglo, int *longitud, int *vectorFinal);

int main(){
	int longitud = 5,vector[longitud] = {1,99,13,21,2},vectorFinal[longitud],x;
	divisionTerminos(vector,&longitud,vectorFinal);
	return 0;
}

void divisionTerminos(int *arreglo, int *longitud, int *vectorFinal){
	int x_temp,y_temp,contPrimos=0,contImpares=0,contPares=0,cont,z;
	
	// buscando la longitud del vector resultante (donde se guardaran los numeros no primos) y de paso busco tmb la longitud de pares e impares
	for(y_temp = 0; y_temp < *longitud; y_temp++){
		cont = 0;
		for(x_temp = 1; x_temp <= *(arreglo + y_temp); x_temp++){
			if(*(arreglo + y_temp) % x_temp == 0){
				cont++;
			}
		}
		
		if(cont == 2){
			contPrimos++;
		}
		
		else{
			
			if(*(arreglo + y_temp) % 2 == 0){
				contPares++;
			}
		 	else{
				contImpares++;
			}
		}		
	}
	
	int vectorResultante[*longitud-contPrimos];
	
	for(x_temp = 0; x_temp <= (*longitud-contPrimos); x_temp++){
		vectorResultante[x_temp] = 0;
	}
	
	int vectorPrimos[contPrimos];
	int guardarResultante = 0;
	
	// guardando valores restantes dentro de vector resultante y guardando los primos dentro vector primos
	for(y_temp = 0; y_temp < *longitud; y_temp++){
		cont = 0;
		for(x_temp = 1; x_temp <= *(arreglo + y_temp); x_temp++){
			if(*(arreglo + y_temp) % x_temp == 0){
				cont++;
			}
		}
		
		if(cont != 2){
			*(vectorResultante + guardarResultante ) = *(arreglo + y_temp);
			guardarResultante++;
		}	
	}
	
	int guardarPrimos = 0; // Inicializar el contador de primos
	
	for (y_temp = 0; y_temp < *longitud; y_temp++) {
	    cont = 0; // Reinicializar el contador de divisores
	    for (x_temp = 1; x_temp <= *(arreglo + y_temp); x_temp++) {
	        if (*(arreglo + y_temp) % x_temp == 0) {
	            cont++;
	        }
	    }
	    
	    if (cont == 2) { // Si tiene exactamente 2 divisores (1 y el número mismo), es primo
	        printf("Entra ");
	        vectorPrimos[guardarPrimos] = *(arreglo + y_temp); // Guardar el número primo en la posición correspondiente
	        guardarPrimos++; // Incrementar el contador de primos para la próxima asignación
	    }        
	}

	

	// creando vector pares e impares y guardando los pares/impares en sus respectivos vectores
	
	int vectorPares[contPares], vectorImpares[contImpares];
	
	for(x_temp = 0; x_temp <= contPares; x_temp++){
		vectorPares[x_temp] = 0;
	}
	
	for(x_temp = 0; x_temp <= contImpares; x_temp++){
		vectorImpares[x_temp] = 0;
	}
	
	int guardarPares = 0,guardarImpares = 0;
	
	for(x_temp = 0; x_temp < (*longitud-contPrimos); x_temp++){
		
		if(*(vectorResultante + x_temp) % 2 == 0){
			vectorPares[guardarPares] = vectorResultante[x_temp];
			guardarPares++;
		}
		
		else{
			vectorImpares[guardarImpares] = vectorResultante[x_temp];
			guardarImpares++;			
		}
	}

	printf("Vector primos (antes): ");
	
	for(x_temp = 0; x_temp < contPrimos; x_temp++){
		printf("%d ",vectorPrimos[x_temp]);
	}
	
	printf("\nCont primos: %d\n",contPrimos);
	printf("\nVector primos posicion '0': %d\n",vectorPrimos[0]);
	printf("\n");

	// ordenando los 3 vectores (primos,impares,pares)
	int aux;
	// primos
	for(x_temp = 0; x_temp < contPrimos; x_temp++) {
	    for(y_temp = 0; y_temp < contPrimos - 1; y_temp++) {
	        if(vectorPrimos[y_temp] > vectorPrimos[y_temp + 1]) {
	            aux = vectorPrimos[y_temp];
	            vectorPrimos[y_temp] = vectorPrimos[y_temp + 1];
	            vectorPrimos[y_temp + 1] = aux;
	        }
	    }
	}
	
	printf("Vector primos: ");
	
	for(x_temp = 0; x_temp < contPrimos; x_temp++){
		printf("%d ",vectorPrimos[x_temp]);
	}
	
	printf("\n");
	
	// impares 
	
	for(x_temp = 0; x_temp < contImpares; x_temp++) {
	    for(y_temp = 0; y_temp < contImpares - 1; y_temp++) {
	        if(vectorImpares[y_temp] > vectorImpares[y_temp + 1]) {
	            aux = vectorImpares[y_temp];
	            vectorImpares[y_temp] = vectorImpares[y_temp + 1];
	            vectorImpares[y_temp + 1] = aux;
	        }
	    }
	}
	
	printf("Vector impares: ");
	
	for(x_temp = 0; x_temp < contImpares; x_temp++){
		printf("%d ",vectorImpares[x_temp]);
	}
	
	printf("\n");
	
	// pares
	
	for(x_temp = 0; x_temp < contPares; x_temp++) {
	    for(y_temp = 0; y_temp < contPares - 1; y_temp++) {
	        if(vectorPares[y_temp] > vectorPares[y_temp + 1]) {
	            aux = vectorPares[y_temp];
	            vectorPares[y_temp] = vectorPares[y_temp + 1];
	            vectorPares[y_temp + 1] = aux;
	        }
	    }
	}
	
	printf("Vector pares: ");
	
	for(x_temp = 0; x_temp < contPares; x_temp++){
		printf("%d ",vectorPares[x_temp]);
	}
	
	printf("\n");

	
	// guardando todos los valores de cada vector en el vectorFinal
	
	for(x_temp = 0; x_temp < contPrimos; x_temp++){
		*(vectorFinal + x_temp) = *(vectorPrimos + x_temp);
	}
	
	z=0;
	for(x_temp = contPrimos; x_temp < (contPrimos+contImpares); x_temp++){
		*(vectorFinal + x_temp) = *(vectorImpares + z);
		z++;		
	}
	z=0;
	for(x_temp = (contPrimos+contImpares); x_temp < *longitud; x_temp++){
		*(vectorFinal + x_temp) = *(vectorPares + z);
		z++;		
	}	
	

}