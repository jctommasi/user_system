#ifndef FANTASMA_H_INCLUDED
#define FANTASMA_H_INCLUDED

#define TEXT_SIZE 20

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"

typedef struct
{
    int idUnico;
    int isEmpty;
    int age;
    float payments;
    char genre; // 1 CHAR TYPE
    char surname[TEXT_SIZE]; // STRING TYPE
    char fullname[TEXT_SIZE]; // LONG STRING TYPE

}Model;


#endif

int model_clear_all(Model array[], int size);
int model_findEmpty(Model array[], int size, int* posicion);
int model_findId(Model array[], int size, int valorBuscado, int* posicion);
int model_searchInt(Model array[], int size, int valorBuscado, int* posicion);
int model_searchString(Model array[], int size, char* valorBuscado, int* indice);
int model_signup(Model array[], int size, int* contadorID);
int model_destroy(Model array[], int sizeArray);
int model_destroyMatchedInt(Model array[], int sizeArray, int valorBuscado);
int model_modify(Model array[], int sizeArray);
int model_sortByString(Model array[],int size);
int model_paginate(Model array[], int size);

int model_info_listarPorCriterio(Model arrayA[], Model arrayB[], int sizeI, int sizeJ, char* criterio);
int model_info_listarCriterioContadorAcumulado(Model arrayA[], Model arrayB[], int sizeI, int sizeJ);
int model_info_maxContadorAcumulado(Model arrayA[], Model arrayB[], int sizeI, int sizeJ);
