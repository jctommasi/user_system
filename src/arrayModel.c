#include "arrayModel.h"

int employee_clear_all(Model array[], int size)
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

int model_checkIfDbHasEntries(Model array[], int size)
{
	int retorno=-1;
	int i;
	if(array!= NULL && size>=0)
	{
		for(i=0;i<size;i++)
		{
			if(array[i].isEmpty==0)
			{
				retorno=0;
				break;
			}
		}
	}
	return retorno;
}

int employee_findEmpty(Model array[], int size, int* posicion)
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

int employee_findId(Model array[], int size, int valorBuscado, int* posicion)
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

int employee_searchInt(Model array[], int size, int valorBuscado, int* posicion)
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else if(array[i].sector==valorBuscado)
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}

int employee_searchString(Model array[], int size, char* valorBuscado, int* indice)
{
    int retorno=-1;
    int i;
    if(array!=NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else if(strcmp(array[i].lastName,valorBuscado)==0)
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
        if(employee_findEmpty(array,size,&posicion)==-1)
        {
            printf("\nNo hay lugares vacios");
        }
        else
        {
            (*contadorID)++;
            array[posicion].idUnico=*contadorID;
            array[posicion].isEmpty=0;
            utn_getUnsignedInt("\n\n\n\t\t\t\t\t\tSector: ",MSG_DEFAULT_ERROR,1,sizeof(int),1,size,1,&array[posicion].sector);
            utn_getName("\t\t\t\t\t\tApellido: ",MSG_DEFAULT_ERROR,1,TEXT_SIZE,1,array[posicion].lastName);
            utn_getTexto("\t\t\t\t\t\tNombre: ",MSG_DEFAULT_ERROR,1,TEXT_SIZE,1,array[posicion].name);
            utn_getFloat("\t\t\t\t\t\tSalario: ",MSG_DEFAULT_ERROR,1,sizeof(float),0,1,1,&array[posicion].salary);
            stuff_clearScreen();
            stuff_showSignUpBanner();
            printf(	"\n\n\n\t\t\t\t\t\t######################"
            		"\n\t\t\t\t\t\tALTA SATISFACTORIA"
            		"\n\t\t\t\t\t\t######################"
            		"\n\t\t\t\t\t\tPosicion: %d"
            		"\n\t\t\t\t\t\tID: %d"
            		"\n\t\t\t\t\t\tApellido: %s"
            		"\n\t\t\t\t\t\tNombre: %s"
            		"\n\t\t\t\t\t\tSector: %d"
            		"\n\t\t\t\t\t\tSalario: %f"
            		"\n\t\t\t\t\t\t######################\n",
                   posicion,
				   array[posicion].idUnico,
				   array[posicion].lastName,
				   array[posicion].name,
				   array[posicion].sector,
				   array[posicion].salary);
            stuff_sleep(3);
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
        utn_getUnsignedInt("\n\n\n\t\t\t\t\t\tID a cancelar: ","\nError",1,sizeof(int),1,sizeArray,1,&id);

        if(employee_findId(array,sizeArray,id,&posicion)==-1)
        {
            printf("\n\n\n"
            		"\t\t\t\t\t\t##############\n"
            		"\t\t\t\t\t\tID INEXISTENTE\n"
            		"\t\t\t\t\t\t##############\n"
            		"\n\n\t\t\t\t\tvolviendo al menu principal ..\n");
            stuff_sleep(2);
        }
        else
        {
        	//antes del borrado, copio los datos para luego mostrar que es lo que se borro
        	Model arrayAux[sizeArray];
        	arrayAux[posicion].idUnico = array[posicion].idUnico;
        	arrayAux[posicion].sector = array[posicion].sector;
        	arrayAux[posicion].salary = array[posicion].salary;
        	strcpy(arrayAux[posicion].lastName,array[posicion].lastName);
        	strcpy(arrayAux[posicion].name,array[posicion].name);

        	//inicio borrado
            array[posicion].isEmpty=1;
            array[posicion].idUnico=0;
            array[posicion].sector=0;
            array[posicion].salary=0;
            strcpy(array[posicion].lastName,"");
            strcpy(array[posicion].name,"");
            retorno=0;

            //informe de borrado
            stuff_clearScreen();
            stuff_employeeGoneAway();
            printf(	"\n\n\n\t\t\t\t\t\t######################"
            		"\n\t\t\t\t\t\tBORRADO SATISFACTORIO"
            		"\n\t\t\t\t\t\t######################"
            		"\n\t\t\t\t\t\tPosicion: %d"
            		"\n\t\t\t\t\t\tID: %d"
            		"\n\t\t\t\t\t\tApellido: %s"
            		"\n\t\t\t\t\t\tNombre: %s"
            		"\n\t\t\t\t\t\tSector: %d"
            		"\n\t\t\t\t\t\tSalario: %f"
            		"\n\t\t\t\t\t\t######################\n",
                   posicion,
				   arrayAux[posicion].idUnico,
				   arrayAux[posicion].lastName,
				   arrayAux[posicion].name,
				   arrayAux[posicion].sector,
				   arrayAux[posicion].salary);
            stuff_sleep(6);
        }
    }
    return retorno;
}

int employee_destroyMatchedInt(Model array[], int sizeArray, int valorBuscado)
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
                array[i].sector=0;
                array[i].salary=0;
                strcpy(array[i].lastName,"");
                strcpy(array[i].name,"");
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
        utn_getUnsignedInt("\n\t\t\t\t\t Ingrese el ID a modificar: ","\nError",1,sizeof(int),1,sizeArray,1,&id);
        if(employee_findId(array,sizeArray,id,&posicion)==-1)
        {
            printf("\n\n\n"
            		"\033[0;31m"
            		"\t\t\t\t\t\t##############\n"
            		"\t\t\t\t\t\tID INEXISTENTE\n"
            		"\t\t\t\t\t\t##############\n"
            		"\n\n\t\t\t\t\tvolviendo al menu principal ..\n"
            		"\033[0m");
            stuff_sleep(2);
        }
        else
        {
            do
            {
            	stuff_clearScreen();
            	stuff_showModifyBanner();

                printf( "\n\t\t\t\t\tSE HA ENCONTRADO EL EMPLEADO:"
                		"\033[0;31m"
                		"\n\n\t\t\t\t\t\t=================="
                		"\n\t\t\t\t\t\tPosicion: %d"
                		"\n\t\t\t\t\t\tID: %d"
                		"\n\t\t\t\t\t\t=================="
                		"\n\t\t\t\t\t\tA - Sector: %d"
                		"\n\t\t\t\t\t\tB - Salario: %f"
                		"\n\t\t\t\t\t\tC - Apellido: %s"
                		"\n\t\t\t\t\t\tD - Nombre: %s\n"
                		"\033[0m",
                       posicion,
					   array[posicion].idUnico,
					   array[posicion].sector,
					   array[posicion].salary,
					   array[posicion].lastName,
					   array[posicion].name);

                utn_getChar(MSG_MODIFY_CHOOSE, MSG_ERROR_MODIFY_CHOOSE,'A', 'Z', 3, &opcion);

                switch(opcion)
                {
                    case 'A':
                        utn_getUnsignedInt(MSG_MODIFY_SECTOR,MSG_ERROR_MODIFY_SECTOR,1,sizeof(int),1,sizeArray,1,&array[posicion].sector);
                        break;
                    case 'B':
                        utn_getFloat(MSG_MODIFY_SALARY,MSG_ERROR_MODIFY_SALARY,1,sizeof(float),0,1,1,&array[posicion].salary);
                        break;
                    case 'C':
                        utn_getName(MSG_MODIFY_SURNAME,MSG_ERROR_MODIFY_SURNAME,1,TEXT_SIZE,1,array[posicion].lastName);
                        break;
                    case 'D':
                        utn_getTexto(MSG_MODIFY_NAME,MSG_ERROR_MODIFY_NAME,1,TEXT_SIZE,1,array[posicion].name);
                        break;
                    case 'S':
                        break;
                    default:
                        printf(MSG_DEFAULT_ERROR);
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

    char lastnameAux[TEXT_SIZE];
    int idAux;
    int isemptyAux;
    int sectorAux;
    float salaryAux;
    char nameAux[TEXT_SIZE];

    if(array!=NULL && size>=0)
    {
        for (i = 1; i < size; i++)
        {
            strcpy(lastnameAux,array[i].lastName);
            idAux=array[i].idUnico;
            isemptyAux=array[i].isEmpty;

            sectorAux=array[i].sector;
            salaryAux=array[i].salary;
            strcpy(nameAux,array[i].name);


            j = i - 1;
            while ((j >= 0) && sectorAux < array[j].sector)
            {
                strcpy(array[j + 1].lastName,array[j].lastName);
                array[j + 1].idUnico=array[j].idUnico;
                array[j + 1].isEmpty=array[j].isEmpty;

                array[j + 1].sector=array[j].sector;
                array[j + 1].salary=array[j].salary;
                strcpy(array[j + 1].name,array[j].name);

                j--;
            }
            strcpy(array[j + 1].lastName,lastnameAux);
            array[j + 1].idUnico=idAux;
            array[j + 1].isEmpty=isemptyAux;

            array[j + 1].sector=sectorAux;
            array[j + 1].salary=salaryAux;
            strcpy(array[j + 1].name,nameAux);
        }

        for (i = 1; i < size; i++)
        {
            strcpy(lastnameAux,array[i].lastName);
            idAux=array[i].idUnico;
            isemptyAux=array[i].isEmpty;

            sectorAux=array[i].sector;
            salaryAux=array[i].salary;
            strcpy(nameAux,array[i].name);


            j = i - 1;
            while ((j >= 0) && strcmp(lastnameAux,array[j].lastName)<0)
            {
                strcpy(array[j + 1].lastName,array[j].lastName);
                array[j + 1].idUnico=array[j].idUnico;
                array[j + 1].isEmpty=array[j].isEmpty;

                array[j + 1].sector=array[j].sector;
                array[j + 1].salary=array[j].salary;
                strcpy(array[j + 1].name,array[j].name);

                j--;
            }
            strcpy(array[j + 1].lastName,lastnameAux);
            array[j + 1].idUnico=idAux;
            array[j + 1].isEmpty=isemptyAux;

            array[j + 1].sector=sectorAux;
            array[j + 1].salary=salaryAux;
            strcpy(array[j + 1].name,nameAux);
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
    	printf(	"#########################################################################################################################\n"
    			"|\tID\t|\tSECTOR\t|\t\tSALARIO\t\t\t|\tAPELLIDO\t|\tNOMBRE\t\t|\n"
    			"#########################################################################################################################\n");
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else
            	printf("|\t%d\t|\t%d\t|\t\t%f\t\t|\t%s\t\t|\t%s\t\t|\n",
                       array[i].idUnico,
					   array[i].sector,
					   array[i].salary,
					   array[i].lastName,
					   array[i].name);
        }
        retorno=0;
        stuff_sleep(5);
    }
    return retorno;
}

int model_info_getSalaryMedia(Model arrayEmployee[], int size)
{
	int i;

	int employeesUpperMediaSalary = 0;
	float salaryProm = 0;
    int retorno = -1;
    float salaryAcum = 0;
    int contSalary = 0;

    if(arrayEmployee!= NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(arrayEmployee[i].isEmpty==0)
            {
            	salaryAcum = salaryAcum + arrayEmployee[i].salary;
            	contSalary++;
            }
        }

        salaryProm = salaryAcum / contSalary;

        for(i=0;i<size;i++)
        {
        	if(arrayEmployee[i].salary > salaryProm)
        	{
        		employeesUpperMediaSalary++;
        	}
        }
        printf("\n\t\tEl salario promedio es de: %f con un total de %i empleados que superan la media\n\t\tEl total de sueldos a pagar es de: %f", salaryProm, employeesUpperMediaSalary, salaryAcum);
        retorno = 0;
    }
    return retorno;
}
