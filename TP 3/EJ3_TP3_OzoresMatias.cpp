#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

void mayorMenor(int *arreglo, int *longitud, int *mayor, int *menor);

int main(){
	
	int longitud,x,y,aux,mayor,menor;
	
	printf("Ingrese la longitud de su arreglo: ");
	scanf("%d",&longitud);
	
	
	int arreglo[longitud]; 
	
	for(x = 0; x<=longitud; x++){
		arreglo[x] = 0;
	}
	
	for(x = 0; x<longitud; x++){
		printf("Ingrese el #%d numero de su arreglo: ",x+1);
		scanf("%d",&arreglo[x]);
	}
	
	mayorMenor(arreglo,&longitud,&mayor,&menor);
	printf("El numero mayor es: %d\n",mayor);
	printf("El numero menor es: %d",menor);
	
	return 0;
}

void mayorMenor(int *arreglo, int *longitud, int *mayor, int *menor){
	int x,y,aux;
	*menor = *(arreglo + 0);
	*mayor = *menor;
	
	// buscando menores
	for(x = 0; x<*longitud;x++){
		if(*menor >= *(arreglo + x)){
			*menor = *(arreglo + x);
		}
	}
	
	// buscando mayores
	for(x = 0; x<*longitud;x++){
		if(*mayor <= *(arreglo + x)){
				*mayor = *(arreglo + x);
		}
	}
	
}