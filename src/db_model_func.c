#include "db_model_func.h"

int model_clear_all(Model array[], int size)
{
    int retorno=-1;
    if(array != NULL && size>0)
    {
        for(;size>0;size--)
        {
            array[size-1].isEmpty=1;
        }
        retorno=0;
    }
    return retorno;
}

int model_findEmpty(Model array[], int size, int* posicion)
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0 && posicion!=NULL)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}

int model_findId(Model array[], int size, int valorBuscado, int* posicion)
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else if(array[i].idUnico==valorBuscado)
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}

int model_searchInt(Model array[], int size, int valorBuscado, int* posicion)
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else if(array[i].age==valorBuscado)
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}

int model_searchString(Model array[], int size, char* valorBuscado, int* indice)
{
    int retorno=-1;
    int i;
    if(array!=NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else if(strcmp(array[i].surname,valorBuscado)==0)
            {
                *indice=i;
                retorno=0;
                break;
            }
        }
    }
    return retorno;
}

int model_signup(Model array[], int size, int* contadorID)
{
    int retorno=-1;
    int posicion;
    if(array!=NULL && size>0 && contadorID!=NULL)
    {
        if(model_findEmpty(array,size,&posicion)==-1)
        {
            printf("\nNo hay lugares vacios");
        }
        else
        {
            (*contadorID)++;
            array[posicion].idUnico=*contadorID;
            array[posicion].isEmpty=0;
            utn_getUnsignedInt("\nEdad: ","\nError",1,sizeof(int),1,size,1,&array[posicion].age);
            utn_getName("\nApellido: ","\nError",1,TEXT_SIZE,1,array[posicion].surname);
            utn_getTexto("\nNombre completo: ","\nError",1,TEXT_SIZE,1,array[posicion].fullname);
            //utn_getFloat("\nPago a realizar: ","\nError",1,sizeof(float),0,1,1,&array[posicion].payments);
            printf("\n Posicion: %d\n ID: %d\n Apellido: %s\n Nombre Completo: %s\n Edad: %d",
                   posicion, array[posicion].idUnico,array[posicion].surname,array[posicion].fullname,array[posicion].age);
            retorno=0;
        }
    }
    return retorno;
}

int model_destroy(Model array[], int sizeArray)
{
    int retorno=-1;
    int posicion;
    int id;

    if(array!=NULL && sizeArray>0)
    {
        utn_getUnsignedInt("\nID a cancelar: ","\nError",1,sizeof(int),1,sizeArray,1,&id);

        if(model_findId(array,sizeArray,id,&posicion)==-1)
        {
            printf("\nNo existe este ID");
        }
        else
        {
            array[posicion].isEmpty=1;
            array[posicion].idUnico=0;
            array[posicion].age=0;
            array[posicion].payments=0;
            strcpy(array[posicion].surname,"");
            strcpy(array[posicion].fullname,"");
            retorno=0;
            printf("\nEl usuario ha sido eliminado exitosamente.\n");
        }
    }
    return retorno;
}

int model_destroyMatchedInt(Model array[], int sizeArray, int valorBuscado)
{
    int retorno=-1;
    int i;
    if(array!=NULL && sizeArray>0)
    {
        for(i=0;i<sizeArray;i++)
        {
            if(array[i].idUnico==valorBuscado)
            {
                array[i].isEmpty=1;
                array[i].idUnico=0;
                array[i].age=0;
                array[i].payments=0;
                strcpy(array[i].surname,"");
                strcpy(array[i].fullname,"");
            }
        }
        retorno=0;
    }
    return retorno;
}

int model_modify(Model array[], int sizeArray)
{
    int retorno=-1;
    int posicion;
    int id;

    char opcion;
    if(array!=NULL && sizeArray>0)
    {
        utn_getUnsignedInt("\nID a modificar: ","\nError",1,sizeof(int),1,sizeArray,1,&id);
        if(model_findId(array,sizeArray,id,&posicion)==-1)
        {
            printf("\nNo existe este ID");
        }
        else
        {
            do
            {
                printf( "\n=================="
                		"\n Posicion: %d"
                		"\n ID: %d"
                		"\n=================="
                		"\n A - Age: %d"
                		"\n B - Payments: %f"
                		"\n C - Surname: %s"
                		"\n D - Full Name: %s",
                       posicion,
					   array[posicion].idUnico,
					   array[posicion].age,
					   array[posicion].payments,
					   array[posicion].surname,
					   array[posicion].fullname);

                utn_getChar(MSG_MODIFY, MSG_ERROR_MODIFY,'A', 'Z', 3, &opcion);

                switch(opcion)
                {
                    case 'A':
                        utn_getUnsignedInt(MSG_MODIFY_AGE,MSG_ERROR_MODIFY_AGE,1,sizeof(int),1,sizeArray,1,&array[posicion].age);
                        break;
                    case 'B':
                        utn_getFloat(MSG_MODIFY_PAYMENT,MSG_ERROR_MODIFY_PAYMENT,1,sizeof(float),0,1,1,&array[posicion].payments);
                        break;
                    case 'C':
                        utn_getName(MSG_MODIFY_SURNAME,MSG_ERROR_MODIFY_SURNAME,1,TEXT_SIZE,1,array[posicion].surname);
                        break;
                    case 'D':
                        utn_getTexto(MSG_MODIFY_NAME,MSG_ERROR_MODIFY_NAME,1,TEXT_SIZE,1,array[posicion].fullname);
                        break;
                    case 'S':
                        break;
                    default:
                        printf("\nOpcion no valida");
                }
            }while(opcion!='S');
            retorno=0;
        }
    }
    return retorno;
}

int model_sortByString(Model array[],int size)
{
    int retorno=-1;
    int i, j;
    char bufferString[TEXT_SIZE];
    int bufferId;
    int bufferIsEmpty;

    int bufferInt;
    float bufferFloat;
    char bufferLongString[TEXT_SIZE];
    if(array!=NULL && size>=0)
    {
        for (i = 1; i < size; i++)
        {
            strcpy(bufferString,array[i].surname);
            bufferId=array[i].idUnico;
            bufferIsEmpty=array[i].isEmpty;

            bufferInt=array[i].age;
            bufferFloat=array[i].payments;
            strcpy(bufferLongString,array[i].fullname);


            j = i - 1;
            while ((j >= 0) && strcmp(bufferString,array[j].surname)<0)
            {
                strcpy(array[j + 1].surname,array[j].surname);
                array[j + 1].idUnico=array[j].idUnico;
                array[j + 1].isEmpty=array[j].isEmpty;

                array[j + 1].age=array[j].age;
                array[j + 1].payments=array[j].payments;
                strcpy(array[j + 1].fullname,array[j].fullname);

                j--;
            }
            strcpy(array[j + 1].surname,bufferString);
            array[j + 1].idUnico=bufferId;
            array[j + 1].isEmpty=bufferIsEmpty;

            array[j + 1].age=bufferInt;
            array[j + 1].payments=bufferFloat;
            strcpy(array[j + 1].fullname,bufferLongString);
        }
        retorno=0;
    }
    return retorno;
}

int model_paginate(Model array[], int size)
{
    int retorno=-1;
    int i;
    if(array!=NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else
                printf("\n ID: %d\n varInt: %d\n varFloat: %f\n varString: %s\n varLongString: %s",
                       array[i].idUnico,array[i].age,array[i].payments,array[i].surname,array[i].fullname);
        }
        retorno=0;
    }
    return retorno;
}


/*
FUNCIONES DE INFORMES *
FUNCIONES DE INFORMES *
FUNCIONES DE INFORMES *
FUNCIONES DE INFORMES *
FUNCIONES DE INFORMES *
FUNCIONES DE INFORMES *
FUNCIONES DE INFORMES *
FUNCIONES DE INFORMES *
 */


/** \brief Busca un valor y lista los elementos de dos arrays vinculados
* \param arrayA Fantasma Array de Fantasma
* \param arrayB Fantasma Array de Fantasma
* \param sizeI int Tama�o del arrayA
* \param sizeJ int Tama�o del arrayB
* \param criterio char* Puntero al valor que debe contener el elemento del array para que se liste
* \return int Return (-1) si Error [Invalid length or NULL pointer] - (0) Ok
*
*/
int model_info_listarPorCriterio(Model arrayA[], Model arrayB[], int sizeI, int sizeJ, char* criterio)  //Valores de dos arrays. Si es valor repetido se vuelve a imprimir
{
    int retorno=-1;
    int i;
    int j;
    if(arrayA!=NULL && sizeI>=0 && arrayB!=NULL && sizeJ>=0 && criterio!=NULL)
    {
        for(i=0;i<sizeI;i++)                                                                            //Obtengo la posicion de la primer entidad
        {
            if(arrayA[i].isEmpty==1)                 //cambiar campo donde busco el criterio
                continue;                                                                       //si esta vacio o no tiene el criterio > continue
            if(strcmp(arrayA[i].surname,criterio)==0)
            {
                model_findId(arrayB,sizeJ,arrayA[i].idUnico,&j);                            //Obtengo la posicion de la 2da entidad buscando por el campo en comun
                printf("\nID A: %d\nID B: %d",
                       arrayA[i].idUnico,arrayB[j].idUnico);
            }

        }
        retorno=0;
    }
    return retorno;
}

/** \brief Busca un valor repetido y lo lista una sola vez, junto con otros elementos de dos arrays vinculados
* \param arrayA Fantasma Array de Fantasma
* \param arrayB Fantasma Array de Fantasma
* \param sizeI int Tama�o del arrayA
* \param sizeJ int Tama�o del arrayB
* \return int Return (-1) si Error [Invalid length or NULL pointer] - (0) Ok
*
*/
//Lista un campo que se repite, lo imprime una sola vez y calcula contador y acumulado
int model_info_listarCriterioContadorAcumulado(Model arrayA[], Model arrayB[], int sizeI, int sizeJ)         //cambiar Fantasma
{
    int retorno=-1;
    int i;
    int j;
    int k;
    int auxPosicion;
    int contador=0;
    int acumulado=0;

    if(arrayA!=NULL && sizeI>=0 && arrayB!=NULL && sizeJ>=0)
    {
        for(i=0;i<sizeI;i++)
        {
            model_searchString(arrayA,i,arrayA[i].surname,&auxPosicion);                  //cambiar nombreFuncion y campo      va a analizar hasta <i
            if(arrayA[i].isEmpty==1 && auxPosicion!=-1)
                continue;                                                                 //Si ese valor ya aparecio > continue
            else
            {
                printf("\nCampo: %s",arrayA[i].surname);                                   //Imprimo el valor que voy a listar
                for(k=i,contador=0,acumulado=0;k<sizeI;k++)                                                            //Recorro por segunda vez el mismo array
                {
                    if(arrayA[k].isEmpty!=1 && strcmp(arrayA[k].surname,arrayA[i].surname)==0)     //Busco todas las veces que aparece ese cuit
                    {
                        model_findId(arrayB,sizeJ,arrayA[k].idUnico,&j);                 //cambiar Fantasma, busco por el campo en comun

                        contador++;
                        acumulado+=(arrayA[k].age*arrayB[j].age);

                        printf("\nID A: %d\nID B: %d",
                                arrayA[k].idUnico,arrayB[j].idUnico);
                    }
                }
                printf("\nCantidad: %d \nAcumulado: %d",contador,acumulado);
                //contador=0;
                //acumulado=0;
            }
        }
        retorno=0;
    }
    return retorno;
}

/** \brief Busca un maximo de ocurrencia y acumulado
* \param arrayA Fantasma Array de Fantasma
* \param arrayB Fantasma Array de Fantasma
* \param sizeI int Tama�o del arrayA
* \param sizeJ int Tama�o del arrayB
* \return int Return (-1) si Error [Invalid length or NULL pointer] - (0) Ok
*
*/
int model_info_maxContadorAcumulado(Model arrayA[], Model arrayB[], int sizeI, int sizeJ)
{
    int retorno=-1;
    int i;
    int j;
    int k;
    int auxPosicion;
    int maxAcumulado=0;
    int maxContador=0;
    int acumulador=0;
    int contador=0;
    int iMaxAcumulado [sizeI];
    int iMaxContador [sizeI];

    if(arrayA!=NULL && sizeI>=0 && arrayB!=NULL && sizeJ>=0)
    {
        for(i=0;i<sizeI;i++)
        {
            model_searchString(arrayA,i,arrayA[i].surname,&auxPosicion);                  //cambiar nombreFuncion y campo
            if(arrayA[i].isEmpty==1 && auxPosicion!=-1)
                continue;                                                                 //Si ese valor ya aparecio > continue
            else
            {
                printf("\nCampo: %s",arrayA[i].surname);                                   //Imprimo el valor que voy a listar
                for(k=i;k<sizeI;k++)                                                            //Recorro por segunda vez el mismo array
                {
                    if(arrayA[k].isEmpty!=1 && strcmp(arrayA[k].surname,arrayA[i].surname)==0)     //Busco todas las veces que aparece ese cuit
                    {

                        model_findId(arrayB,sizeJ,arrayA[k].idUnico,&j);                 //cambiar Fantasma, busco por el campo en comun

                        contador++;                                                         //calculos acumulados y contador
                        acumulador+=(arrayA[k].age*arrayB[j].age);

                        printf("\nID A: %d\nID B: %d",                                         //imprimo datos que haya que mostrar
                                arrayA[k].idUnico,arrayB[j].idUnico);
                    }
                }
                //Guardo los max acumulado y contador
                if(acumulador>maxAcumulado)
                {
                    maxAcumulado=acumulador;
                    iMaxAcumulado[i-1]=-1;                       //Si mas de un cuit tiene la mayor facturacion
                    iMaxAcumulado[i]=i;
                }
                else if(acumulador==maxAcumulado)
                    iMaxAcumulado[i]=i;
                else
                    iMaxAcumulado[i]=-2;                         //Para marcar los lugares vacios

                acumulador=0;

                if(contador>maxContador)
                {
                    maxContador=contador;
                    iMaxContador[i-1]=-1;                       //Si mas de un cuit tiene la mayor facturacion
                    iMaxContador[i]=i;
                }
                else if(contador==maxContador)
                    iMaxContador[i]=i;
                else
                    iMaxContador[i]=-2;                         //Para marcar los lugares vacios

                contador=0;
            }
        }

        printf("\nMayor acumulado: %d \nMayor contador: %d \nI: ",maxAcumulado,maxContador);
        for(;iMaxAcumulado[i]!=-1;i--)                                                      //Uno o el otro, sino agregar otro contador que no sea el i
        {
            if(iMaxAcumulado[i]!=-2)                         //Salteo los vacios
            {
                printf("\n          CUIT: %s",arrayA[iMaxAcumulado[i]].surname);
            }
        }
        for(;iMaxContador[i]!=-1;i--)
        {
            if(iMaxContador[i]!=-2)                         //Salteo los vacios
            {
                printf("\n          CUIT: %s",arrayA[iMaxContador[i]].surname);
            }
        }

        retorno=0;
    }
    return retorno;
}

/** \brief Crea una entidad auxiliar para ordenar e informar XXXXX
* \param arrayA Fantasma Array de Fantasma
* \param arrayB Fantasma Array de Fantasma
* \param sizeI int Tama�o del arrayA
* \param sizeJ int Tama�o del arrayB
* \return int Return (-1) si Error [Invalid length or NULL pointer] - (0) Ok
*
*/
int Informes_listarAuxiliarOrdenar(Model arrayA[], Model arrayB[], int sizeI, int sizeJ)         //cambiar Fantasma
{
    int retorno=-1;
    int i;
    int j;
    int k;
    int auxPosicion;
    int contador=0;
    int acumulado=0;

    Model arrayAux[sizeI];                                                           //cambiar Fantasma y size si corresponde

    if(arrayA!=NULL && sizeI>=0 && arrayB!=NULL && sizeJ>=0)
    {
        for(i=0;i<sizeI;i++)
        {
            model_searchString(arrayA,i,arrayA[i].surname,&auxPosicion);                  //cambiar nombreFuncion y campo      va a analizar hasta <i
            if(arrayA[i].isEmpty==1 && auxPosicion!=-1)
                continue;                                                                 //Si ese valor ya aparecio > continue
            else
            {
                strcpy(arrayAux[i].surname,arrayA[i].surname);                              //cambio varstring
                for(k=i;k<sizeI;k++)                                                            //Recorro por segunda vez el mismo array
                {
                    if(arrayA[k].isEmpty!=1 && strcmp(arrayA[k].surname,arrayA[i].surname)==0)     //Busco todas las veces que aparece ese cuit
                    {
                        model_findId(arrayB,sizeJ,arrayA[k].idUnico,&j);                 //cambiar Fantasma, busco por el campo en comun

                        contador++;
                        acumulado+=(arrayA[k].age*arrayB[j].age);

                    }
                }
                arrayAux[i].age=contador;                                    //completo el resto de los campos
                arrayAux[i].age=acumulado;
                arrayAux[i].isEmpty=0;

                contador=0;
                acumulado=0;
            }
        }
        retorno=0;
    }
    return retorno;
}

