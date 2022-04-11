/*
 * utn.c
 *
 *  Created on: 10 abr. 2022
 *      Author: Carlo Morici
 */

#include <stdio.h>
#include <stdlib.h>
#include "personalio.h"

void showMenu(float aerolineas, float latam, int kmts)
{

	//marca donde se vuelve a empezar el menu para facilitar la lectura de datos
	printf("\n________________________________________________________________________\n________________________________________________________________________\n");


	//verifica si ya se completo la opcion 1 para determinar si debe mostar los kilometros ingresado
	if (kmts!=-1){
	printf("1. Ingresar Kil�metros: ( km=%d)\n", kmts);
	}
	else
		printf("1) Ingresar Kil�metros: ( km=x)\n");

	//verifica si ya se completo la opcion 2 para determinar si debe mostar los precios ingresados
	if(aerolineas!=-1 && latam!=-1){
		printf("\n2. Ingresar Precio de Vuelos: (Aerol�neas=%.2f, Latam=%.2f)\n", aerolineas, latam);
	}
	else{
		printf("\n2. Ingresar Precio de Vuelos: (Aerol�neas=y, Latam=z)\n");
	}
	printf("\t- Precio vuelo Aerol�neas:\n");
	printf("\t- Precio vuelo Latam:\n");
	printf("\n3. Calcular todos los costos:\n");
	printf("a) Tarjeta de d�bito (descuento 10%%)\n");
	printf("b) Tarjeta de cr�dito (inter�s 25%%)\n");
	printf("c) Bitcoin (1BTC -> 4606954.55 Pesos Argentinos)\n");
	printf("d) Mostrar precio por km (precio unitario)\n");
	printf("e) Mostrar diferencia de precio ingresada (Latam - Aerol�neas)\n");
	printf("\n4. Informar Resultados\n");
	printf("�Latam:\n");
	printf("a) Precio con tarjeta de d�bito: r\n");
	printf("b) Precio con tarjeta de cr�dito: r\n");
	printf("c) Precio pagando con bitcoin : r\n");
	printf("d) Precio unitario: r\n");
	printf("Aerol�neas:\n");
	printf("a) Precio con tarjeta de d�bito: r\n");
	printf("b) Precio con tarjeta de cr�dito: r\n");
	printf("c) Precio pagando con bitcoin : r\n");
	printf("d) Precio unitario: r\n");
	printf("La diferencia de precio es : r �\n");
	printf("\n5. Carga forzada de datos\n");
	printf("\n6. Salir\n");

}

void findResults(float *debitoA, float *debitoL, float *creditoA, float *creditoL, float *BTCA, float *BTCL, float *PPUA, float *PPUL, int kmts, float latam, float aerolineas, float *diferencia, float precioBTC){

	printf("\nopcion 3) Calcular todos los costos:\n");


	if (kmts==-1 || latam==-1 || aerolineas==-1 ){		//si los datos siguen en sus valores de inicializacion, entonces no hay nada para calcular
		printf("aun no ha completado los datos de distancia y precio. Complete dichos datos y reintente\n");
	}
	else{
		//|
		*debitoA= basicMath(aerolineas, 0.9, '*');
		*debitoL= basicMath(latam, 0.9, '*');
		*creditoA= basicMath(aerolineas, 1.25, '*');
		*creditoL= basicMath(latam, 1.25, '*');
		*BTCA= basicMath(aerolineas, precioBTC, '/');
		*BTCL= basicMath(latam, precioBTC, '/');
		*PPUA= basicMath(aerolineas, kmts, '/');
		*PPUL= basicMath(latam, kmts, '/');

		if(aerolineas>=latam)
			*diferencia=basicMath(aerolineas, latam, '-');
		else
			*diferencia=basicMath(latam, aerolineas, '-');

		printf("\nse han hecho los calculos solicitados");

	}

}

void showResults(float debitoA, float debitoL, float creditoA, float creditoL, float BTCA, float BTCL, float PPUA, float PPUL, int kmts, float latam, float aerolineas, float diferencia){

	printf("\nopcion 4) Informar Resultados:\n");

	if(debitoA==-1){		//si debitoA=-1 entonces no ha completado la opcion 3
		printf("\nno puede acceder a la opcion 4 sin completar la opcion 3. Complete dichos datos y reintente");
	}
	else{
		printf("kilometros ingresados = %d \n", kmts);

		printf("\n\tprecio Aerol�neas: %.2f", aerolineas);
		printf("\n a) Precio con tarjeta de d�bito: $%.2f", debitoA);
		printf("\n b) Precio con tarjeta de cr�dito: $%.2f", creditoA);
		printf("\n c) Precio pagando con bitcoin : %f BTC", BTCA);
		printf("\n d) Precio unitario: $%.2f", PPUA);


		printf("\n\tprecio Latam: %.2f", latam);
		printf("\n a) Precio con tarjeta de d�bito: $%.2f", debitoL);
		printf("\n Precio con tarjeta de cr�dito: $%.2f", creditoL);
		printf("\n c) Precio pagando con bitcoin : %f BTC", BTCL);
		printf("\n d) Precio unitario: $%.2f", PPUL);

		printf("\n La diferencia de precio es : $%.2f ", diferencia );
	}

}


void forceData(float precioBTC){


		printf("\nopcion 5) Carga forzada de datos:\n");


		int kmts=7090;
		float aerolineas=162965;
		float latam=159339 ;

		float debitoA=-1;
		float debitoL;
		float creditoA;
		float creditoL;
		float BTCA;
		float BTCL;
		float PPUA;
		float PPUL;
		float diferencia;

		findResults(&debitoA, &debitoL, &creditoA, &creditoL, &BTCA, &BTCL, &PPUA, &PPUL, kmts, latam, aerolineas, &diferencia, precioBTC);
		showResults( debitoA,  debitoL,  creditoA,  creditoL,  BTCA,  BTCL,  PPUA,  PPUL,  kmts,  latam,  aerolineas, diferencia);


}


