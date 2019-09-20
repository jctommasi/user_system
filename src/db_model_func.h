#ifndef FANTASMA_H_INCLUDED
#define FANTASMA_H_INCLUDED

#define TEXT_SIZE 20

typedef struct
{
    int idUnico;
    int isEmpty;
    //-----------------
    char varString[TEXT_SIZE];
    int varInt;
    float varFloat;
    char varChar;
    char varLongString[TEXT_SIZE];

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
