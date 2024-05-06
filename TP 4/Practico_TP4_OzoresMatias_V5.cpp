#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

char cadenaVacia[50] = "";
int numeroVacio = 0;

struct informacion{
	char nombre[50];
	char apellido[50];
	int dni;
};

// prototipado 
void menu(int *opcion);
void ingresoDatos(struct informacion *persona, int *x, FILE *archivo);
void busquedaDNI(struct informacion *persona, int *x, FILE *archivo);
void busquedaNombreApellido(struct informacion *persona, int *x, FILE *archivo);
void ordenamiento(struct informacion *persona, int *x);

int main(){
	
	struct informacion persona[50];
	int opcion,busquedaOpcion,resetear = 1,x = 0;
    FILE *archivo;
 
 
	printf("TP 4 Archivos - Matias Ozores \n\n");
	system("pause");
	system("cls");
	
	archivo = fopen("datos.txt", "a+");
	
	// bucle para resetear el programa y switch para dirigir al usuario donde quiera
	do{
		// menu 
		menu(&opcion);
		
		switch(opcion){
			case 1:
				ingresoDatos(persona,&x, archivo);
			break;
			
			case 2:
				system("cls");
				printf("--- Busquedas --- \n");
				printf("1- Busqueda por DNI.\n");
				printf("2- Busqueda por nombre y apellido\n\n");
				printf("Ingrese la opcion deseada: ");
				scanf("%d",&busquedaOpcion);
				
				switch(busquedaOpcion){
					case 1:
						busquedaDNI(persona, &x, archivo);
					break;
					
					case 2:
						busquedaNombreApellido(persona, &x, archivo);
					break;
				}
				
			break;
			
			case 3:
				ordenamiento(persona,&x);
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
	printf("---- Menu de Opciones ----\n\n");
	printf("1- Ingreso de datos.\n");
	printf("2- Realizar busqueda.\n");
	printf("3- Ordenar\n");
	printf("4- Salir\n\n");
	printf("Ingrese la opcion deseada: ");
	scanf("%d",opcion);
}

void ingresoDatos(struct informacion *persona, int *x, FILE *archivo){
    int i, repDatos, dniIngresado;
    char nombreTemp[50], apellidoTemp[50];
    system("cls");
    do {
        repDatos = 0;
        printf("Ingrese el nombre: ");
        scanf("%s", nombreTemp);
        fflush(stdin);
        printf("Ingrese el apellido: ");
        scanf("%s", apellidoTemp);
        fflush(stdin);
        printf("Ingrese el DNI: ");
        scanf("%d", &dniIngresado);
        system("cls");

        // Validar si el DNI ya existe en el archivo
        rewind(archivo);
        while(fscanf(archivo, "%s %s %d", (*(persona + *x)).nombre, (*(persona + *x)).apellido, &(*(persona + *x)).dni) != EOF){
            if(dniIngresado == (*(persona + *x)).dni){
                repDatos = 1;
                break;
            }
        }

        if(repDatos == 1){
            printf("El DNI ingresado ya existe.\n");
            system("pause");
            system("cls");
        } else {
            // Escribir en el archivo solo si el DNI no existe
            fprintf(archivo, "%s %s %d\n", nombreTemp, apellidoTemp, dniIngresado);
            printf("Datos ingresados con exito.\n");
            strcpy((*(persona + *x)).nombre, nombreTemp); // Guardar el nombre ingresado en la estructura
            strcpy((*(persona + *x)).apellido, apellidoTemp); // Guardar el apellido ingresado en la estructura
            (*x)++;
        }

    } while(repDatos == 1);

    system("pause");
    system("cls");
}



void busquedaDNI(struct informacion *persona, int *x, FILE *archivo){
    int dniBusqueda, encontrado = 0;
    rewind(archivo); // Coloca el cursor al principio del archivo

    printf("Ingrese el DNI correspondiente: ");
    scanf("%d",&dniBusqueda);
    system("cls");

    while(fscanf(archivo, "%s %s %d", (*(persona + *x)).nombre, (*(persona + *x)).apellido, &(*(persona + *x)).dni) != EOF){
        if(dniBusqueda == (*(persona + *x)).dni){
            printf("--- Datos encontrados ---\n");
            printf("Nombre: %s\n",(*(persona + *x)).nombre);
            printf("Apellido: %s\n",(*(persona + *x)).apellido);
            encontrado = 1;
            break;
        }
    }

    if(!encontrado){
        printf("No se ha encontrado ningun usuario\n");
    }
    
    system("pause");
    system("cls");
}


void busquedaNombreApellido(struct informacion *persona, int *x, FILE *archivo){
    int encontrado = 0;
    char nombreBusqueda[50], apellidoBusqueda[50];

    system("cls");
    printf("Ingrese el nombre correspondiente: ");
    scanf("%s", nombreBusqueda);
    printf("Ingrese el apellido que coincida con '%s': ", nombreBusqueda);
    scanf("%s", apellidoBusqueda);
    system("cls");

    rewind(archivo); // Coloca el cursor al principio del archivo

    while(fscanf(archivo, "%s %s %d", (*(persona + *x)).nombre, (*(persona + *x)).apellido, &(*(persona + *x)).dni) != EOF){
        if(strcmp(nombreBusqueda, (*(persona + *x)).nombre) == 0 && strcmp(apellidoBusqueda, (*(persona + *x)).apellido) == 0){
            printf("--- Datos encontrados ---\n");
            printf("Nombre: %s\n", (*(persona + *x)).nombre);
            printf("Apellido: %s\n", (*(persona + *x)).apellido);
            printf("DNI: %d\n", (*(persona + *x)).dni);
            encontrado = 1;
        }
    }

    if (!encontrado) {
        printf("No se ha encontrado ningun usuario\n");
    }

    system("pause");
    system("cls");
}


void ordenamiento(struct informacion *persona, int *x){
    int ordenamientoOpcion;
    int x_temp, y_temp;
    struct informacion temp;
       
    system("cls");
    printf("--- Ordenamientos ---\n");
    printf("1- Ordenar por nombre y apellido.\n");
    printf("2- Ordenar por DNI.\n\n");
    printf("Ingrese la opcion deseada: ");
    scanf("%d",&ordenamientoOpcion);
    
    switch(ordenamientoOpcion){
        // ordenar por nombre
        case 1:
            for(x_temp = 0; x_temp < *x - 1; x_temp++) {
                for(y_temp = 0; y_temp < *x - x_temp - 1; y_temp++) {
                    if(strcmp((*(persona + y_temp)).apellido, (*(persona + y_temp + 1)).apellido) > 0) {
                        temp = *(persona + y_temp);
                        *(persona + y_temp) = *(persona + y_temp + 1);
                        *(persona + y_temp + 1) = temp;
                    }
                }
            }
            
            printf("--- Datos ordenados por nombre ---\n");
            for(x_temp = 0; x_temp < *x; x_temp++) {
                printf("Nombre: %s\n",(*(persona + x_temp)).nombre);
                printf("Apellido: %s\n",(*(persona + x_temp)).apellido);
                printf("DNI: %d\n",(*(persona + x_temp)).dni);
                printf("-------------------------\n");
            }
            system("pause");
            system("cls");
            break;
        
        // ordenar por dni
        case 2:
			for(x_temp = 0; x_temp < *x - 1; x_temp++) {
                for(y_temp = 0; y_temp < *x - x_temp - 1; y_temp++) {
                    if((*(persona + y_temp)).dni < (*(persona + y_temp + 1)).dni) {
                        temp = *(persona + y_temp);
                        *(persona + y_temp) = *(persona + y_temp + 1);
                        *(persona + y_temp + 1) = temp;
                    }
                }
            }
            
            printf("--- Datos ordenados por DNI ---\n");
            for(x_temp = 0; x_temp < *x; x_temp++) {
                printf("Nombre: %s\n",(*(persona + x_temp)).nombre);
                printf("Apellido: %s\n",(*(persona + x_temp)).apellido);
                printf("DNI: %d\n",(*(persona + x_temp)).dni);
                printf("-------------------------\n");
            }
            system("pause");
            system("cls");
            break;
            break;
    }
}

