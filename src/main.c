/*
 ============================================================================
 Name        : UTN project
 Author      : juan cruz tommasi
 Version     : 1
 ============================================================================
 */

#include "global.h"
#define MSG "Por favor, ingrese una opcion:"
#define MSG_ERROR "ERROR, ingrese una opcion valida.."
#define QTY_TIPO 3

int main(void)
{
	int opNumber;
	int id_autoinc = 0;

	Model arrayModel[QTY_TIPO];
	model_clear_all(arrayModel,QTY_TIPO);

	stuff_displayBanner();
	stuff_showMenu();

	do
	{
		utn_getUnsignedInt(MSG, MSG_ERROR,1,4,1,4,2, &opNumber);

		switch (opNumber) {
			case 1:

				break;
			case 2:

				break;
			case 3:

				break;
			case 4:

				break;
			case 5:

				break;
			case 6:

				break;
			default:
				printf("Esa opcion no es valida..")
				break;
		}

	}	while (opNumber != 6);


	return EXIT_SUCCESS;
}
