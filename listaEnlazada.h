#ifndef LISTA_ENLAZADA_H
#define LISTA_ENLAZADA_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef char tString[40];

typedef struct {
    int id;
    tString nombreApellido;
    char numeroTelefono[20];
    int sexo; // 1-varón, 2-mujer
    tString correoElectronico;
    tString domicilio;
    int edad;
    tString fechaCumple;
} tInfoContacto;

typedef struct nodo {
    tInfoContacto datosContacto;
    struct nodo *siguiente;
} tListaContacto;

// Funciones básicas de la lista
void inicializarLista(tListaContacto **listaContacto);
bool listaVacia(tListaContacto *listaContacto);

void insertarPrimero(tListaContacto **listaContacto, tInfoContacto *infoContacto);
void insertarAdelante(tListaContacto **listaContacto, tInfoContacto *infoContacto);
void insertarElemento(tListaContacto **listaContacto, tInfoContacto *infoContacto);
void eliminarContacto(tListaContacto* );



void visualizarContactos(tListaContacto *listaContacto, tInfoContacto *);



void inicializarLista(tListaContacto **listaContacto) {
    *listaContacto = NULL;
}

bool listaVacia(tListaContacto * listaContacto){
	return (listaContacto == NULL);
}

void insertarPrimero(tListaContacto **listaContacto, tInfoContacto *infoContacto) {
    tListaContacto *nuevoNodo = (tListaContacto *)malloc(sizeof(tListaContacto));
    nuevoNodo->datosContacto = *infoContacto;
    nuevoNodo->siguiente = NULL;
    *listaContacto = nuevoNodo;
	
	/*printf("\nContacto guardado!\n");
	printf("ID: %d\n", infoContacto->id);
	printf("Nombre y apellido: %s\n", infoContacto->nombreApellido);
	printf("Numero de telefono: %s\n", infoContacto->numeroTelefono);
	printf("sexo(1- varon, 2- mujer): %d\n", infoContacto->sexo);
	printf("Edad: %d\n", infoContacto->sexo);
	printf("Correo electronico: %s\n", infoContacto->correoElectronico);
	printf("Domicilio: %s\n", infoContacto->domicilio);
	printf("Fecha de cumple: %s\n", infoContacto->fechaCumple);
	printf("\n");*/
}


void insertarAdelante(tListaContacto **listaContacto, tInfoContacto *infoContacto) {
    tListaContacto *nuevoNodo = (tListaContacto *)malloc(sizeof(tListaContacto));
    nuevoNodo->datosContacto = *infoContacto;
    nuevoNodo->siguiente = *listaContacto;
    *listaContacto = nuevoNodo;
	
	/*printf("\nContacto guardado!\n");
	printf("ID: %d\n", infoContacto->id);
	printf("Nombre y apellido: %s\n", infoContacto->nombreApellido);
	printf("Numero de telefono: %s\n", infoContacto->numeroTelefono);
	printf("sexo(1- varon, 2- mujer): %d\n", infoContacto->sexo);
	printf("Edad: %d\n", infoContacto->sexo);
	printf("Correo electronico: %s\n", infoContacto->correoElectronico);
	printf("Domicilio: %s\n", infoContacto->domicilio);
	printf("Fecha de cumple: %s\n", infoContacto->fechaCumple);
	printf("\n");*/
	
}


void insertarElemento(tListaContacto **listaContacto, tInfoContacto *infoContacto) {
    if (listaVacia(*listaContacto)) {
        insertarPrimero(listaContacto, infoContacto);
    } else {
        insertarAdelante(listaContacto, infoContacto);
    }
}


void visualizarContactos(tListaContacto *listaContacto, tInfoContacto *infoContacto){
    tListaContacto *aux = listaContacto;
	
    if(!listaVacia(aux)){
        printf("\n***Lista de contactos****\n\n");
        while(aux != NULL){
            tInfoContacto *info = &(aux->datosContacto);
            printf("ID: %d\n", info->id);
            printf("Nombre y apellido: %s\n", info->nombreApellido);
            printf("Numero de telefono: %s\n", info->numeroTelefono);
            printf("Sexo(1- varon, 2- mujer): %d\n", info->sexo);
            printf("Edad: %d\n", info->edad);
            printf("Correo electronico: %s\n", info->correoElectronico);
            printf("Domicilio: %s\n", info->domicilio);
            printf("Fecha de cumple: %s\n", info->fechaCumple);
            printf("\n");
            aux = aux->siguiente;
        }
    } else {
        printf("La lista de contactos esta vacia o no ha sido inicializada.\n");
    }
}

void eliminarContacto(tListaContacto* pListaContactosActual){
	if(pListaContactosActual == NULL){
		printf("\nLa lista de contactos esta vacia.\n");
	}else{
		int idEliminar;
		printf("\nIngrese el ID del contacto que desea eliminar: ");
		scanf("%d", &idEliminar);
		
		tListaContacto* actual = pListaContactosActual;
		tListaContacto* anterior = pListaContactosActual;
		
		while(actual != NULL && actual->datosContacto.id != idEliminar){
			anterior = actual;
			actual = actual->siguiente;
		}
		
		if(actual ==  NULL){
			printf("No se encontro al contacto con ID %d\n", idEliminar);
		}else{
			if(anterior == NULL){
				pListaContactosActual = actual->siguiente;
			}else{
				anterior->siguiente = actual->siguiente;
			}
			
			free(actual);
			printf("Contacto con ID %d eliminado correctamente\n", idEliminar);
		}
	}
}

#endif // LISTA_ENLAZADA_H
