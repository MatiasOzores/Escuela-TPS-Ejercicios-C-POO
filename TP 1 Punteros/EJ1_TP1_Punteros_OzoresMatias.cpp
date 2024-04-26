#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

int anioActual = 2024;

struct informacion{
	char nombre[50];
	char apellido[50];
	int dia;
	int mes;
	int anio;
	char dni[8];
};

void ingresoInfo(struct informacion *persona);
void calculoVotaciones(struct informacion *persona);


int main(){
	int continuar;
	struct informacion persona;
	do{
		continuar = 0;
		ingresoInfo(&persona);
		calculoVotaciones(&persona);
		printf("Nombre: %s\n",persona.nombre);
		printf("Apellido: %s\n",persona.apellido);
		printf("Dia: %d\n",persona.dia);
		printf("Mes: %d\n",persona.mes);
		printf("Año: %d\n",persona.anio);
		printf("DNI: %s\n",persona.dni);
		system("pause");
		system("cls");
		
		printf("Si desea reiniciar el programa presione 1: ");
		scanf("%d",&continuar);
		system("cls");
	}while(continuar == 1);

	return 0;
}

void ingresoInfo(struct informacion *persona){
	printf("Ingrese su nombre: ");
	scanf("%s",&persona->nombre);
	system("cls");
	
	printf("Ingrese su apellido: ");
	scanf("%s",&persona->apellido);
	system("cls");
	
	printf("Ingrese su 'dia' de nacimiento: ");
	scanf("%d",&persona->dia);
	system("cls");	

	printf("Ingrese su 'mes' de nacimiento: ");
	scanf("%d",&persona->mes);
	system("cls");
	
	printf("Ingrese su 'año' de nacimiento: ");
	scanf("%d",&persona->anio);
	system("cls");	
	
	printf("Ingrese su dni de nacimiento: ");
	scanf("%s",&persona->dni);
	system("cls");					
}

void calculoVotaciones(struct informacion *persona){
	int edad;
	
	// calculo de edad
	
	if(persona->mes == 9){
		if(persona->dia < 30){
			edad = anioActual - persona->anio;
		}
		
		else{
			edad = anioActual - persona->anio - 1;
		}
	}
	
	else if(persona->mes < 9){
		edad = anioActual - persona->anio;
	}
	
	else{
		edad = anioActual - persona->anio - 1;
	}
	
	// calculo de votacion
	
	if(edad < 16){
		printf("No puede votar.\n");
	}
	
	else if(edad >= 16 && edad < 18){
		printf("Puede votar.\n");
	}
	
	else if(edad >= 18 && edad < 80){	
		printf("Debe votar.\n");
	}
	
	else{
		printf("Puede votar.\n");
	}
}