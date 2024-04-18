#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int x,y=0,continuar,reset=1;



void copia(int *arreglo, int *longitud, int *arreglo2);
void mensaje(int *arreglo, int longitud, int *y);



int main(){
	
	int longitud;
	int arreglo[longitud];
	int arreglo2[longitud]; 	
	do{	
		system("cls");
		printf("Ingrese la longitud de su arreglo: ");
		scanf("%d",&longitud);
			
		for(x = 0; x < longitud; x++){
			printf("Ingrese el #%d numero de su arreglo: ",x+1);
			scanf("%d",&arreglo[x]);
		}
		
		
		
		copia(arreglo,&longitud,arreglo2);
		mensaje(arreglo,longitud,&y);	
		mensaje(arreglo2,longitud,&y);
		printf("Presione 1 para resetear el programa: ");
		scanf("%d", &continuar);
		
	}while(continuar == 1);
	
	return 0;
}

void copia(int *arreglo, int *longitud, int *arreglo2){

	
	for(x = 0; x<*longitud; x++){
		*(arreglo2 + x) = *(arreglo + x);
		
	}
}

void mensaje(int *arreglo, int longitud, int *y){
	
	printf("\n\tVector %d:\n",*y+1);

	for(x = 0; x<longitud; x++){
		if(x == longitud-1){
			printf("%d\n",arreglo[x]);	
		}
		else{
			printf("%d | ",arreglo[x]);	
		}
		
	}
	
	(*y)++;
}
