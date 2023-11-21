/*
Aqui colocamos las funciones de la lista enlazada y tambien la estructura de los datos.
pero decidimos no poner algunas funciones basicas de la lista, como por ejemplo la de 
buscar en cierta posicion.
*/

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
	
}


void insertarAdelante(tListaContacto **listaContacto, tInfoContacto *infoContacto) {
    tListaContacto *nuevoNodo = (tListaContacto *)malloc(sizeof(tListaContacto));
    nuevoNodo->datosContacto = *infoContacto;
    nuevoNodo->siguiente = *listaContacto;
    *listaContacto = nuevoNodo;
	
	
}


void insertarElemento(tListaContacto **listaContacto, tInfoContacto *infoContacto) {
    if (listaVacia(*listaContacto)) {
        insertarPrimero(listaContacto, infoContacto);
    } else {
        insertarAdelante(listaContacto, infoContacto);
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
