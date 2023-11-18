#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#include<stdlib.h>
#include "listaEnlazada.h"

//PROGRAMA PRINCIPAL

void menuGeneral();
void menuLista();
void ingresarDatos();

tListaContacto *listaContacto;
tInfoContacto infoContacto;



int main(){
	menuGeneral();
	
	return 0;
}

void menuGeneral(){
	inicializarLista(&listaContacto);	
	menuLista();
}

void ingresarDatos(){
	printf("\n");
	printf("ID: ");
	scanf("%d", &infoContacto.id);
	printf("Nombre y apellido: ");
	fflush(stdin);
	scanf("%[^\n]s", &infoContacto.nombreApellido);
	printf("Numero de telefono: ");
	//fflush(stdin);
	scanf("%s", &infoContacto.numeroTelefono);
	printf("Sexo(1- varon, 2- mujer): ");
	scanf("%d", &infoContacto.sexo);
	printf("Correo electronico: ");
	fflush(stdin);
	scanf("%[^\n]s", &infoContacto.correoElectronico);
	printf("Domicilio: ");
	fflush(stdin);
	scanf("%[^\n]s", &infoContacto.domicilio);;
	printf("Edad: ");
	scanf("%d", &infoContacto.edad);
	printf("Fecha de cumple: ");
	fflush(stdin);
	scanf("%[^\n]s", &infoContacto.fechaCumple);
}

void menuLista(){
	int opcion;
	int posicion;
	do{
		printf("\n");
		printf("1- Ingresar contacto\n");
		printf("2- ver lista de contactos\n");
		printf("3- borrar contacto\n");
		printf("4- salir\n");
		printf("Opcion: ");
		scanf("%d", &opcion);
		
		switch(opcion){
			case 1:
				ingresarDatos();
				insertarElemento(&listaContacto, &infoContacto);
				break;
			case 2:
				printf("\nLISTA DE CONTACTOS\n");
				visualizarContactos(listaContacto, &infoContacto);
				break;
			case 3:
				printf("\nQue elemento desea eliminar: ");
				scanf("%d", posicion);
				eliminarEnPosK(posicion, &listaContacto, &infoContacto);
				break;
			case 4:
				printf("\nSaliendo del menu\n");
				break;
			default:
				printf("\nLa opcion que ingresaste no es correcta, ingresa otra por favor\n");
				break;
		}
	}while(opcion!=4);
}
