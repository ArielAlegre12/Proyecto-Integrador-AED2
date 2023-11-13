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
    int fechaCumple;
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

void eliminarPrimero(tListaContacto **listaContacto, tInfoContacto *infoContacto);
void eliminarEnPosK(int pos, tListaContacto **listaContacto, tInfoContacto *infoContacto);
void insertarEnPosK(int pos, tListaContacto **listaContacto, tInfoContacto *infoContacto);

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
    nuevoNodo->siguiente = *listaContacto;
    *listaContacto = nuevoNodo;
	
	printf("\n¡Contacto guardado!\n");
	printf("ID: %d\n", infoContacto->id);
	printf("Nombre y apellido: %s\n", infoContacto->nombreApellido);
	printf("Numero de telefono: %s\n", infoContacto->numeroTelefono);
	printf("sexo(1- varon, 2- mujer): %d\n", infoContacto->sexo);
	printf("Edad: %d\n", infoContacto->sexo);
	printf("Correo electronico: %s\n", infoContacto->correoElectronico);
	printf("Domicilio: %s\n", infoContacto->domicilio);
	printf("Fecha de cumple: %d\n", infoContacto->fechaCumple);
	printf("\n");
}


void insertarAdelante(tListaContacto **listaContacto, tInfoContacto *infoContacto) {
    tListaContacto *nuevoNodo = (tListaContacto *)malloc(sizeof(tListaContacto));
    nuevoNodo->datosContacto = *infoContacto;
    nuevoNodo->siguiente = *listaContacto;
    *listaContacto = nuevoNodo;
	
	printf("\n¡Contacto guardado!\n");
	printf("ID: %d\n", infoContacto->id);
	printf("Nombre y apellido: %s\n", infoContacto->nombreApellido);
	printf("Numero de telefono: %d", infoContacto->numeroTelefono);
	printf("sexo(1- varon, 2- mujer): %d\n", infoContacto->sexo);
	printf("Edad: %d\n", infoContacto->sexo);
	printf("Correo electronico: %s\n", infoContacto->correoElectronico);
	printf("Domicilio: %s\n", infoContacto->domicilio);
	printf("Fecha de cumpleaños: %d\n", infoContacto->fechaCumple);
	printf("\n");
	
}


void insertarElemento(tListaContacto **listaContacto, tInfoContacto *infoContacto) {
    if (listaVacia(*listaContacto)) {
        insertarPrimero(listaContacto, infoContacto);
    } else {
        insertarAdelante(listaContacto, infoContacto);
    }
}


void visualizarContactos(tListaContacto *listaContacto, tInfoContacto *infoContacto){
	tListaContacto *aux;
	aux = listaContacto;
	
	if(!listaVacia(aux)){
		printf("\n***Lista de contactos****\n");
		while(aux != NULL){
		    printf("ID: %d\n", infoContacto->id);
	printf("Nombre y apellido: %s\n", infoContacto->nombreApellido);
	printf("Numero de telefono: %d", infoContacto->numeroTelefono);
	printf("sexo(1- varon, 2- mujer): %d\n", infoContacto->sexo);
	printf("Edad: %d\n", infoContacto->sexo);
	printf("Correo electronico: %s\n", infoContacto->correoElectronico);
	printf("Domicilio: %s\n", infoContacto->domicilio);
	printf("Fecha de cumpleaños: %d\n", infoContacto->fechaCumple);
	printf("\n");
		}
	}
}

void insertarEnPosK(int pos, tListaContacto **listaContacto, tInfoContacto *infoContacto) {
    int i;
    tListaContacto *aux, *nuevoNodo;
    aux = *listaContacto;

    for (i = 1; i < pos - 1; i++) {
        aux = aux->siguiente;
    }

    nuevoNodo = (tListaContacto *)malloc(sizeof(tListaContacto));
    nuevoNodo->datosContacto = *infoContacto;
    nuevoNodo->siguiente = aux->siguiente;
    aux->siguiente = nuevoNodo;
    
    
	printf("ID: %d\n", infoContacto->id);
	printf("Nombre y apellido: %s\n", infoContacto->nombreApellido);
	printf("Numero de telefono: %d", infoContacto->numeroTelefono);
	printf("sexo(1- varon, 2- mujer): %d\n", infoContacto->sexo);
	printf("Edad: %d\n", infoContacto->sexo);
	printf("Correo electronico: %s\n", infoContacto->correoElectronico);
	printf("Domicilio: %s\n", infoContacto->domicilio);
	printf("Fecha de cumpleaños: %d\n", infoContacto->fechaCumple);
	printf("\n");
}

void eliminarEnPosK(int pos, tListaContacto **listaContacto, tInfoContacto *infoContacto) {
    int i;
    tListaContacto *aux, *nodoSuprimir;

    if (pos == 1) {
        eliminarPrimero(listaContacto, infoContacto);
    } else {
        aux = *listaContacto;
        for (i = 1; i < pos - 1; i++) {
            aux = aux->siguiente;
        }

        nodoSuprimir = aux->siguiente;
        aux->siguiente = nodoSuprimir->siguiente;
		
		printf("\n¡Contacto eliminado!\n");
		printf("ID: %d\n", infoContacto->id);
	    printf("Nombre y apellido: %s\n", infoContacto->nombreApellido);
	    
	    free(nodoSuprimir);
	    nodoSuprimir = NULL;
	}
}

void eliminarPrimero(tListaContacto **listaContacto, tInfoContacto *infoContacto) {
    if (listaVacia(*listaContacto)) {
        printf("No hay contacto para borrar!\n");
    } else {
        tListaContacto *nodoSuprimir = *listaContacto;
        *listaContacto = (*listaContacto)->siguiente;
		
		printf("\n¡Contacto eliminado!\n");
		printf("ID: %d\n", infoContacto->id);
	    printf("Nombre y apellido: %s\n", infoContacto->nombreApellido);
	    
	    free(nodoSuprimir);
	    nodoSuprimir = NULL;
	}
}

#endif // LISTA_ENLAZADA_H