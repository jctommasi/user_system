/*
 * db_func.h
 *
 *  Created on: 11 sep. 2019
 *      Author: alumno
 */

#ifndef DB_FUNC_H_
#define DB_FUNC_H_

int sortDb(	int *pLegajo,
			char *pSexo,
			int *pEdad,
			int *nota1p,
			int *nota2p,
			float *promedio,
			int *limite);

int printDbEntry(	int legajo,
					char sexo,
					int edad,
					int nota1p,
					int nota2p,
					float promedio);

int listDb(	int *pLegajo,
			char *pSexo,
			int *pEdad,
			int *nota1p,
			int *nota2p,
			float *promedio,
			int *limite);

int addDbEntry(int legajo,char sexo,int edad,int nota1p,int nota2p,float promedio);

#endif /* DB_FUNC_H_ */
