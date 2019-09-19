/*
 * structf.c
 *
 *  Created on: 18 sep. 2019
 *      Author: alumno
 */


int structf_alta()
{
	char nombre[50];
	int edad;
	int dni;
	char msjEdad = "Ingrese la edad:";
	char msjDni = "Ingrese la edad:";
	char msjError = "Error!";

	printf("Ingrese el nombre: ");
	scanf("%s", nombre);
	getInt(&edad,msjEdad,&msjError,0,99,2);
	getInt(&dni,msjDni,&msjError,0,90000000,2);

	return 1;
}
