#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "listaEnlazada.h"
#include "funcionesArchivo.h" 


void menu();

int main() {
    cargarDatosDesdeArchivo();
    menu();
    guardarDatosEnArchivo();
    return 0;
}

void menu() {
    int opcion;

    do {
        printf("\n----MENU----\n");
        printf("1 - Agregar Contacto\n");
        printf("2 - Buscar Contacto\n");
        printf("3 - Borrar Contacto\n");
        printf("4 - Guardar Datos\n");
        printf("5 - Editar un Contacto\n");
        printf("6 - Mostrar Todos los Contactos\n");
        printf("7 - Salir\n");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                ingresarDatos();
                guardarDatosEnArchivo();
                break;
            case 2:
            	buscarContacto();
                break;
            case 3:
                eliminarContacto(listaContacto);
                break;
            case 4:
            	guardarDatosEnArchivo();
            	break;
            case 5:
            	printf("Ingrese el ID del contacto que desea editar: ");
                int idEditar;
                scanf("%d", &idEditar);
                editarContacto(listaContacto, idEditar);
                guardarDatosEnArchivo();
                break;
            case 6:
            	mostrarContactos();
            	break;
            case 7:
                printf("\nSaliendo del gestor....\n");
                break;
            default:
                printf("\nOpción no válida. Por favor, elija una opción del 1 al 5.\n");
                break;
        }
    } while (opcion != 7);
}


