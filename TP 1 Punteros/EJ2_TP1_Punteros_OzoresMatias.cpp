#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <math.h>

void calculoPitagoras(float *c1, float *c2, float *hipotenusa);

int main(){
	int continuar;
	float c1,c2,hipotenusa;
	
	do{
		system("cls");
		continuar = 0;
		printf("Ingrese el valor de su cateto 1: ");
		scanf("%f",&c1);
		
		system("cls");
		
		printf("Ingrese el valor de su cateto 2: ");
		scanf("%f",&c2);
		
		system("cls");
		calculoPitagoras(&c1,&c2,&hipotenusa);
		
		printf("El valor de us hipotenusa es: %f\n",hipotenusa);
		system("pause");
		system("cls");
		
		printf("Si desea reiniciar el programa ingrese 1: ");
		scanf("%d",&continuar);
	}while(continuar == 1);
	
	return 0;
}

void calculoPitagoras(float *c1, float *c2, float *hipotenusa){
	*hipotenusa = sqrt((*c1) * (*c1) + (*c2) * (*c2));
}