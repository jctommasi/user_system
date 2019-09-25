/*
 ============================================================================
 Name        : usr sys
 Author      : juan cruz tommasi
 Version     : 1.0 beta
 ============================================================================
 */

#include "global.h"

int main(void)
{

	int opNumber;
	int id_autoinc = 0;

	Model arrayModel[QTY_TIPO];
	model_clear_all(arrayModel,QTY_TIPO);

	do
	{
		stuff_displayBanner();
		stuff_showMenu();
		utn_getUnsignedInt(MSG, MSG_ERROR,1,2,1,2,2, &opNumber);
		switch (opNumber)
		{
			case 1:
				model_signup(arrayModel, QTY_TIPO, &id_autoinc);
				break;
			case 2:
				model_destroy(arrayModel, QTY_TIPO);
				break;
			case 3:
				model_modify(arrayModel, QTY_TIPO);
				break;
			case 4:
				model_paginate(arrayModel, QTY_TIPO);
				break;
			case 5:
				model_sortByString(arrayModel,QTY_TIPO);
				break;
			case 6:
				break;
			default:
				printf("Esa opcion no es valida..");
				break;
		}
	}	while (opNumber != 6);

	return EXIT_SUCCESS;
}
