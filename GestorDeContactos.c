#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#include<stdlib.h>
#include "listaEnlazada.h"

//PROGRAMA PRINCIPAL

void menuGeneral();
void ingresarDatos();

tListaContacto *listaContacto;
tInfoContacto infoContacto;



int main(){
	menuGeneral();
	
	return 0;
}

void menuGeneral(){
	inicializarLista(&listaContacto);	
	ingresarDatos();
	insertarElemento(&listaContacto, &infoContacto);
	
	
}

void ingresarDatos(){
	printf("ID: ");
	scanf("%d", &infoContacto.id);
	printf("\nNombre y apellido: ");
	fflush(stdin);
	scanf("%[^\n]s", &infoContacto.nombreApellido);
	printf("\nNumero de telefono: ");
	//fflush(stdin);
	scanf("%s", &infoContacto.numeroTelefono);
	printf("\nSexo(1- varon, 2- mujer): ");
	scanf("%d", &infoContacto.sexo);
	printf("\nCorreo electronico: ");
	fflush(stdin);
	scanf("%[^\n]s", &infoContacto.correoElectronico);
	printf("\nDomicilio: ");
	fflush(stdin);
	scanf("%[^\n]s", &infoContacto.domicilio);
	printf("\nEdad: ");
	scanf("%d", &infoContacto.edad);
	printf("\nFecha de cumple: ");
	scanf("%d", &infoContacto.fechaCumple);
}