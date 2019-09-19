/*
 ============================================================================
 Name        : UTN project
 Author      : juan cruz tommasi
 Version     : 1
 ============================================================================
 */

#include "global.h"

int main(void)
{
	int operationNumber;
	Persona database[3];

	stuff_displayBanner();
	stuff_showMenu(&operationNumber);

	return EXIT_SUCCESS;
}
