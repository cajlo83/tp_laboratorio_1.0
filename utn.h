/*
 * utn.h
 *
 *  Created on: 10 abr. 2022
 *      Author: Cajlo
 */

#ifndef UTN_H_
#define UTN_H_

void showMenu(float a, float l, int k);						//imprime el menu con datos actualizados

void findResults(float *debitoA, float *debitoL, float *creditoA, float *creditoL, float *BTCA, float *BTCL, float *PPUA, float *PPUL,
		int kmts, float latam, float aerolineas, float *diferencia, float precioBTC);		//menu 3)hace calculos y guarda los datos por referencia

void showResults(float debitoA, float debitoL, float creditoA, float creditoL, float BTCA, float BTCL, float PPUA, float PPUL,
		int kmts, float latam, float aerolineas, float diferencia);				//menu4) imprime resultados

void forceData(float precioBTC);


#endif /* UTN_H_ */
