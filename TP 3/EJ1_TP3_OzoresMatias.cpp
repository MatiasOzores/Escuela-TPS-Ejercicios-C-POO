#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int num1,num2;

void intercambio(int *a, int *b);

int main(){

	
	printf("Ingresa el primer numero: ");
	scanf("%d",&num1);
	
	printf("Ingresa el segundo numero: ");
	scanf("%d",&num2);

	printf("Los valores iniciales son: %d y %d\n",num1,num2);
	intercambio(&num1, &num2);
	printf("Los valores finales son: %d y %d\n",num1,num2);

	return 0;
}

void intercambio(int *a, int *b){
	int aux;
	aux = *a;
	*a = *b;
	*b = aux;
}