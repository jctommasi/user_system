#ifndef FANTASMA_H_INCLUDED
#define FANTASMA_H_INCLUDED

#define TEXT_SIZE 51

#define MSG_DEFAULT_ERROR "\nError, opcion no valida..\n"

#define MSG_ERROR_MODIFY_CHOOSE  "\nError al elegir"
#define MSG_MODIFY_CHOOSE "\n\t\t\t\t\t(choose: A B C D # S = Salir)\n\n\t\t\t\t\tQue dato desea modificar?:"

#define MSG_ERROR_MODIFY_SECTOR  "\nError al modificar la edad"
#define MSG_MODIFY_SECTOR  "\nIngrese la edad, por favor:"

#define MSG_ERROR_MODIFY_SALARY  "\nError al modificar el pago"
#define MSG_MODIFY_SALARY "\nIngrese el nuevo monto del pago, por favor:"

#define MSG_ERROR_MODIFY_SURNAME  "\nError al modificar el apellido"
#define MSG_MODIFY_SURNAME "\nIngrese el nuevo apellido, por favor:"

#define MSG_ERROR_MODIFY_NAME  "\nError al modificar el nombre"
#define MSG_MODIFY_NAME "\nIngrese el nombre, por favor:"

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "stuff.h"

typedef struct
{
    int idUnico;
    int isEmpty;
    int sector;
    float salary;
    char lastName[TEXT_SIZE]; // STRING TYPE
    char name[TEXT_SIZE]; // LONG STRING TYPE

}Model;

#endif

int employee_clear_all(Model array[], int size);
int model_checkIfDbHasEntries(Model array[], int size);
int employee_findEmpty(Model array[], int size, int* posicion);
int employee_findId(Model array[], int size, int valorBuscado, int* posicion);
int employee_searchInt(Model array[], int size, int valorBuscado, int* posicion);
int employee_searchString(Model array[], int size, char* valorBuscado, int* indice);
int model_signup(Model array[], int size, int* contadorID);
int model_destroy(Model array[], int sizeArray);
int employee_destroyMatchedInt(Model array[], int sizeArray, int valorBuscado);
int model_modify(Model array[], int sizeArray);
int model_sortByString(Model array[],int size);
int model_paginate(Model array[], int size);
int model_info_getSalaryMedia(Model array[], int size);
