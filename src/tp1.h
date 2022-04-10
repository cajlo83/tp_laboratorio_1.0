/*
 * utn.h
 *
 *  Created on: 10 abr. 2022
 *      Author: Cajlo
 */

#ifndef UTN_H_
#define UTN_H_

/// Recibe el precio de aerolineas@param aerolineas
/// Recibe el precio de latam @param latam
/// Recobe la cantidad de kilometros @param kmts
///
/// Evalua las variables recibidas para decidir como mostrar el menu
///
void showMenu(float aerolineas, float latam, int kmts);						//imprime el menu con datos actualizados






/// Precio debito aerolineas@param debitoA
/// Precio debito latam@param debitoL
/// precio credito aerolineas@param creditoA
/// Precio credito latam@param creditoL
/// Precio bitcoin areolineas@param BTCA
/// Precio bitcoin latam@param BTCL
/// Precio Por Unidad aerolineas@param PPUA
/// Precio Por Unidad latam@param PPUL
/// Kilometros@param kmts
/// Precio base latam@param latam
/// Precio base aerolineas@param aerolineas
/// Diferencia de precios base de aerolineas y latam@param diferencia
/// Precio del bitcoin@param precioBTC
///
/// recibe por valor datos iniciales y guarda los resultados en sus respectivas varaibles por referencia
///
void findResults(float *debitoA, float *debitoL, float *creditoA, float *creditoL, float *BTCA, float *BTCL, float *PPUA, float *PPUL,
		int kmts, float latam, float aerolineas, float *diferencia, float precioBTC);		//menu 3)hace calculos y guarda los datos por referencia





/// Precio debito aerolineas@param debitoA
/// Precio debito latam@param debitoL
/// precio credito aerolineas@param creditoA
/// Precio credito latam@param creditoL
/// Precio bitcoin areolineas@param BTCA
/// Precio bitcoin latam@param BTCL
/// Precio Por Unidad aerolineas@param PPUA
/// Precio Por Unidad latam@param PPUL
/// Kilometros@param kmts
/// Precio base latam@param latam
/// Precio base aerolineas@param aerolineas
/// Diferencia de precios base de aerolineas y latam@param diferencia
///
/// muestra los datos calculados por findResults(...)
///

/**
 *
 * @param debitoA
 * @param debitoL
 * @param creditoA
 * @param creditoL
 * @param BTCA
 * @param BTCL
 * @param PPUA
 * @param PPUL
 * @param kmts
 * @param latam
 * @param aerolineas
 * @param diferencia
 */
void showResults(float debitoA, float debitoL, float creditoA, float creditoL, float BTCA, float BTCL, float PPUA, float PPUL,
		int kmts, float latam, float aerolineas, float diferencia);				//menu4) imprime resultados



/*
/**
 *
 *
 * Precio del bitcoin@param precioBTC
 *
 * Km: 7090
 * Aerolineas Argentinas: $162965
 * Latam: $ 159339
 */
void forceData(float precioBTC);


#endif /* UTN_H_ */
