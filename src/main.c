/*
 ============================================================================
 Author      : Juan Cruz Tommasi
 ============================================================================
*/


#include "global.h"

int main(void)
{

	int opNumber;
	int id_autoinc = 0;

	Model arrayModel[DB_LENGHT];
	employee_clear_all(arrayModel,DB_LENGHT);

	/*
	Employee arrayEmployee[DB_LENGHT]=
	{
		{ 0, 0, 44, 456.000, "Gabriel", "Peter"},
		{ 1, 0, 51, 36.000, "Bond", "James"},
		{ 2, 0, 44, 133.000, "Doe", "John"},
		{ 3, 0, 13, 405.000, "Patton", "Mike"},
		{ 4, 0, 420, 5.000, "Marley", "Bob"},
		{5, 0, 1, 4445.000, "Presley", "Elvis"},
	};*/

	do
	{
		stuff_displayMainBanner();
		stuff_showMenu();
		utn_getUnsignedInt(MSG, MSG_ERROR,1,2,1,2,2, &opNumber);
		switch (opNumber)
		{
			case 1:
				stuff_clearScreen();
				stuff_showSignUpBanner();
				model_signup(arrayModel, DB_LENGHT, &id_autoinc);
				break;
			case 2:
				if(model_checkIfDbHasEntries(arrayModel, DB_LENGHT) >= 0)
				{
					stuff_clearScreen();
					stuff_showDestroyBanner();
					model_destroy(arrayModel, DB_LENGHT);
				} else {stuff_printAndSleep(2, NO_MODELS_ERROR);}
				break;
			case 3:
				if(model_checkIfDbHasEntries(arrayModel, DB_LENGHT) >= 0)
				{
					stuff_clearScreen();
					stuff_showModifyBanner();
					model_modify(arrayModel, DB_LENGHT);
				} else {stuff_printAndSleep(2, NO_MODELS_ERROR);}
				break;
			case 4:
				if(model_checkIfDbHasEntries(arrayModel, DB_LENGHT) == 0)
				{
					int reportNum;
					stuff_clearScreen();
					stuff_showReportsMenu();
					utn_getUnsignedInt(MSG, MSG_ERROR,1,2,1,2,2, &reportNum);

					switch (reportNum)
					{
					case 1:
						stuff_clearScreen();
						stuff_showPaginateBanner();
						model_sortByString(arrayModel,DB_LENGHT);
						model_paginate(arrayModel, DB_LENGHT);
						break;
					case 2:
						stuff_clearScreen();
						stuff_showReport();
						model_info_getSalaryMedia(arrayModel, DB_LENGHT);
						stuff_printAndSleep(2, MSG_REDIRECT);
						break;
					default:
						printf(MSG_ERROR);
						break;
					}
				}else {stuff_printAndSleep(2, NO_MODELS_ERROR);}
				break;
			case 5:
				break;
			default:
				printf(MSG_ERROR);
				break;
		}
	}	while (opNumber != 5);

	return EXIT_SUCCESS;
}
