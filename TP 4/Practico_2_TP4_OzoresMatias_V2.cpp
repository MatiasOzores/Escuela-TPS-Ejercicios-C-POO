#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

char cadenaVacia[50] = "";
int numeroVacio = 0;

struct informacion{
	char nombre[50];
	int puntaje;
};

// prototipado 
void menu(int *opcion);
void ingresoDatos(struct informacion *persona, int *x, FILE *archivo);
void busquedaNombreApellido(struct informacion *persona, int *x, FILE *archivo);
void ordenamientoPorPuntaje(struct informacion *persona, int x, FILE *archivo);


int main(){
	
	struct informacion persona[50];
	int opcion,busquedaOpcion,resetear = 1,x = 0;
    FILE *archivo;
 
 
	printf("TP 4 Archivos - Matias Ozores \n\n");
	system("pause");
	system("cls");
	
	archivo = fopen("datos2.txt", "a+");
	
	// bucle para resetear el programa y switch para dirigir al usuario donde quiera
	do{
		// menu 
		menu(&opcion);
		
		switch(opcion){
			case 1:
				ingresoDatos(persona,&x, archivo);
			break;
			
			case 2:
				busquedaNombreApellido(persona, &x, archivo);
			break;
			
			case 3:
				ordenamientoPorPuntaje(persona,x,archivo);
			break;
			
			case 4:
				resetear = 0;
			break;
		
		}		
	}while(resetear == 1);
	
	fclose(archivo);
	return 0;
}

void menu(int *opcion){
	system("cls");
	printf("---- Menu de Opciones ----\n\n");
	printf("1- Ingreso de datos.\n");
	printf("2- Realizar busqueda de un nombre.\n");
	printf("3- Ordenar por puntaje\n");
	printf("4- Salir\n\n");
	printf("Ingrese la opcion deseada: ");
	scanf("%d",opcion);
}

void ingresoDatos(struct informacion *persona, int *x, FILE *archivo) {
    int repDatos, puntajeIngresado;
    char nombreTemp[50];

    system("cls");
    do {
        repDatos = 0;

        printf("Ingrese el nombre: ");
        scanf("%s", nombreTemp);
        fflush(stdin);

        printf("Ingrese el puntaje: ");
        scanf("%d", &puntajeIngresado);
        system("cls");

        rewind(archivo);
        while (fscanf(archivo, "%s %d", (*(persona + *x)).nombre, &(*(persona + *x)).puntaje) != EOF) {
            if (strcmp(nombreTemp, (*(persona + *x)).nombre) == 0) { // Comparación de cadenas
                repDatos = 1;
                break;
            }
        }

        if (repDatos == 1) {
            printf("El nombre ingresado ya existe.\n");
            system("pause");
            system("cls");
        } else {
            fprintf(archivo, "%s %d\n", nombreTemp, puntajeIngresado);
            printf("Datos ingresados con exito.\n");
            strcpy((*(persona + *x)).nombre, nombreTemp); 
            (*(persona + *x)).puntaje = puntajeIngresado;
            (*x)++;
        }

    } while (repDatos == 1);

    system("pause");
    system("cls");
}


void busquedaNombreApellido(struct informacion *persona, int *x, FILE *archivo){
    int encontrado = 0;
    char nombreBusqueda[50];

    system("cls");
    printf("Ingrese el nombre correspondiente: ");
    scanf("%s", nombreBusqueda);
    system("cls");

    rewind(archivo); // Coloca el cursor al principio del archivo

    while(fscanf(archivo, "%s %d", (*(persona + *x)).nombre, &(*(persona + *x)).puntaje) != EOF){
        if(strcmp(nombreBusqueda, (*(persona + *x)).nombre) == 0){
            printf("--- Datos encontrados ---\n");
            printf("Nombre: %s\n", (*(persona + *x)).nombre);
            printf("Puntaje: %d\n", (*(persona + *x)).puntaje);
            encontrado = 1;
        }
    }

    if (!encontrado) {
        printf("No se ha encontrado ningun usuario\n");
    }

    system("pause");
    system("cls");
}


void ordenamientoPorPuntaje(struct informacion *persona, int x, FILE *archivo) {
    int i, j;
    struct informacion temp;
    int contador = 0; // Contador para el número de elementos leídos desde el archivo

    system("cls");

    rewind(archivo); // Coloca el cursor al principio del archivo

    // Leer los datos del archivo y almacenarlos en el arreglo persona
    while (fscanf(archivo, "%s %d", (*(persona + contador)).nombre, &(*(persona + contador)).puntaje) != EOF && contador < 50) {
        contador++;
    }

    // Algoritmo de ordenamiento (método de burbuja)
    for (i = 0; i < contador - 1; i++) {
        for (j = 0; j < contador - i - 1; j++) {
            if ((*(persona + j)).puntaje < (*(persona + j + 1)).puntaje) {
                // Intercambiar los registros
                temp = *(persona + j);
                *(persona + j) = *(persona + j + 1);
                *(persona + j + 1) = temp;
            }
        }
    }

    // Mostrar los registros ordenados por puntaje de mayor a menor
    printf("--- Registros ordenados por puntaje de mayor a menor ---\n");
    for (i = 0; i < contador; i++) {
        printf("Nombre: %s\n", (*(persona + i)).nombre);
        printf("Puntaje: %d\n", (*(persona + i)).puntaje);
        printf("-------------------------\n");
    }

    system("pause");
}
	





