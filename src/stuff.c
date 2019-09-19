/*
 * stuff.c
 *
 *  Created on: 18 sep. 2019
 *      Author: alumno
 */

#include "stuff.h"

void stuff_clearScreen()
{
  const char *CLEAR_SCREEN_ANSI = "\e[1;1H\e[2J";
  write(STDOUT_FILENO, CLEAR_SCREEN_ANSI, 12);
}

void stuff_displayBanner()
{
	printf("\033[0;32m");
	printf("██╗   ██╗███████╗███████╗██████╗ ███████╗    ███████╗██╗   ██╗███████╗\n");
	printf("██║   ██║██╔════╝██╔════╝██╔══██╗██╔════╝    ██╔════╝╚██╗ ██╔╝██╔════╝\n");
	printf("██║   ██║███████╗█████╗  ██████╔╝███████╗    ███████╗ ╚████╔╝ ███████╗\n");
	printf("██║   ██║╚════██║██╔══╝  ██╔══██╗╚════██║    ╚════██║  ╚██╔╝  ╚════██║\n");
	printf("╚██████╔╝███████║███████╗██║  ██║███████║    ███████║   ██║   ███████║\n");
	printf(" ╚═════╝ ╚══════╝╚══════╝╚═╝  ╚═╝╚══════╝    ╚══════╝   ╚═╝   ╚══════╝\n");
	printf("\033[0m");

}

int stuff_showMenu(int* pOperationNumber)
{
	int operationNumber;
	int traceback = -1;
	printf("\033[0;31m");
	printf("Que operacion desea realizar?\n"
			"\n		1. Alta"
			"\n		2. Baja"
			"\n		3. Modificar"
			"\n		4. Listar"
			"\n		5. Ordenar"
			"\n\n	Opcion: ");
	scanf("%d", &operationNumber);
	printf("\033[0m");

	if(operationNumber >= 1 && operationNumber <= 5)
	{
		*pOperationNumber = operationNumber;
		traceback = 0;
	}
	return traceback;
}
