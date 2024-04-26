#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <math.h>

void esPrimo(int *num);

int main(){
	int num;
	printf("Ingrese un numero: ");
	scanf("%d",&num);
	system("cls");
	esPrimo(&num);
}

void esPrimo(int *num){
	int x_temp,cont=0;
	
	for(x_temp = 1; x_temp <= *num; x_temp++){
		if(*num % x_temp == 0){
			cont++;
		}
	}
	
	if(cont == 2){
		printf("'%d' es primo.",*num);
	}
	
	else{
		printf("'%d' NO es primo.",*num);
	}
}