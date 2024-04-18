#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int x;
int sumado = 0; 
float promediado;

void sumaPromedio(int *vector, int *tamano, int *sumado, float *promediado);



int main(){
	int longitud=0;
	
	printf("Ingrese la longitud de su arreglo: ");
	scanf("%d", &longitud);
	
	int arreglo[longitud];
	
	for(x = 0; x < longitud; x++){
		printf("Ingrese su #%d numero: ",x+1);
		scanf("%d",&arreglo[x]);
	}
	
	sumaPromedio(arreglo,&longitud,&sumado,&promediado);
	printf("El resultado de su suma es: %d\n",sumado);
	printf("El promedio es: %.2f\n",promediado);

	return 0;
}

void sumaPromedio(int *vector, int *tamano, int *sumado, float *promediado){
	*sumado = 0;
	
	for(x = 0; x < *tamano; x++){
		*sumado+=*(vector + x);
	}	
	
	*promediado = (float)*sumado / *tamano;
}
