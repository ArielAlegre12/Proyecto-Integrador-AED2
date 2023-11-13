#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#include<stdlib.h>

//PROGRAMA PRINCIPAL

void menuGeneral();


int main(){
	menuGeneral(); //un menu general, y dentro de este podemos ir llamando a los TAD de las funciones
	return 0;
}

void menuGeneral(){
	int opcion;
	
	do{
		printf("\n****BIENVENIDO AL GESTOR DE CONTACTOS****\n");
		printf("\n");
		printf("¿Que desea hacer?\n");
		printf("1- Crear usuario nuevo\n");
		printf("2- Ingresar a usuario existente\n");
		printf("3- borrar usuario\n");
		printf("4- Cerrar el programa\n");
		printf("\n");
		printf("Opcion: ");
		scanf("%d", &opcion);
		
		switch(opcion){
			case 1:
				crearNuevoUsuario();//dentro de esta funcion, podemos llamar otra que abra el archivo para escribir.
				break;                 //y dentro del archivo llamamos a la lista que guarde los datos
			case 2:
				ingresarUsuarioExistente(); //aca podemos pedir 
				break;
			case 3:
				borrarUsuario();
				break;
			case 4:
				break;
			default:
				break;
		}
	}while(opcion != 4);
}
