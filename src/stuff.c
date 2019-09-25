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

void stuff_showMenu()
{
	printf("\033[0;31m");
	printf("Que operacion desea realizar?\n"
			"\n		1. Alta"
			"\n		2. Baja"
			"\n		3. Modificar"
			"\n		4. Listar"
			"\n		5. Ordenar"
			"\n		6. Salir\n\n");
	printf("\033[0m");
}
