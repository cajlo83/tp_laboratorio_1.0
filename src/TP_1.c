/*
 ============================================================================
 Name        : TP_1.c
 Author      : Carlo Morici
 Version     : 08/04/2022
 Copyright   : Your copyright notice
 Description :

1 Enunciado
Una agencia de viaje necesita calcular costos para sus vuelos de Latam y Aerolíneas Argentinas para ofrecerlos a sus clientes.
Se deberá ingresar por cada vuelo los km totales y el precio total del mismo.  El objetivo de la aplicación es mostrar las diferentes opciones de pagos a sus clientes.
Para ello el programa iniciará y contará con un menú de opciones:
1. Ingresar Kilómetros: ( km=x)

2. Ingresar Precio de Vuelos: (Aerolíneas=y, Latam=z)
- Precio vuelo Aerolíneas:
- Precio vuelo Latam:

3. Calcular todos los costos:
 a) Tarjeta de débito (descuento 10%)
 b) Tarjeta de crédito (interés 25%)
 c) Bitcoin (1BTC -> 4606954.55 Pesos Argentinos)
 d) Mostrar precio por km (precio unitario)
 e) Mostrar diferencia de precio ingresada (Latam - Aerolíneas)
4. Informar Resultados
“Latam:
 a) Precio con tarjeta de débito: r
 b) Precio con tarjeta de crédito: r
 c) Precio pagando con bitcoin : r
 d) Precio unitario: r
 Aerolíneas:
 a) Precio con tarjeta de débito: r
 b) Precio con tarjeta de crédito: r
 c) Precio pagando con bitcoin : r
 d) Precio unitario: r
 La diferencia de precio es : r “
5. *9-+
6. Salir
Aclaraciones del funcionamiento:
El menú se tiene que ver tal cual está descrito en la consigna. Los resultados se tienen que mostrar con el mismo formato. Se puede realizar un submenú para ingresar los km y los precios.
Los resultados se tienen que ver con el formato presentado en el menú. De la siguiente  manera.

La carga forzada se tiene que mostrar exactamente igual a la pantalla de resultados sin ingresar ninguna opción previamente. Tiene que calcular todo al momento de apretar el botón con los siguientes datos:
Km: 7090
Aerolineas Argentinas: $162965
Latam: $ 159339
(solo mostrar los resultados ya calculados)
Se deben realizar todas las validaciones necesarias para que el programa funcione  correctamente. Por ej: no se puede realizar cálculos si no hay vuelos ingresados.
Todas las funciones que realizarán los cálculos del menú se deberán realizar en una biblioteca aparte, que contenga las funciones para realizar todas las operaciones.
En el menú deberán aparecer los valores actuales cargados en los vuelos de Latam y Aerolineas (donde dice “x” e “y” en el ejemplo, se debe mostrar el número cargado)
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#define P_BTC 4606954.55


void showMenu(float a, float l, int k);						//imprime el menu con datos actualizados

void findResults(float *debitoA, float *debitoL, float *creditoA, float *creditoL, float *BTCA, float *BTCL, float *PPUA, float *PPUL,
		int kmts, float latam, float aerolineas, float *diferencia);		//menu 3)hace calculos y guarda los datos por referencia

void showResults(float debitoA, float debitoL, float creditoA, float creditoL, float BTCA, float BTCL, float PPUA, float PPUL,
		int kmts, float latam, float aerolineas, float diferencia);				//menu4) imprime resultados

int intVerify(int numero, int minimo, int maximo); 			//devuelve 1 o 0 a un banderin para determinar si debe continuar un bucle
int floatVerify(float numero, int minimo, int maximo);		//devuelve 1 o 0 a un banderin para determinar si debe continuar un bucle
int intScan(char *mensaje);
int floatScan(char *mensaje);
float basicMath(float a, float b, char operacion);			//hace operaciones aritmeticas segun se ingrese los caracteres '*', '/', '+', '-', '%

void forceData();



void main(void) {

	setbuf(stdout, NULL);

	int kmts=-1;
	float aerolineas=-1;		//inician en -1 para luego verificar si ya se hizo la carga de datos
	float latam=-1;

	int menu;

	float debitoA=-1;	//inicia en -1 para luego verificar si ya se hizo el calculo de datos
	float debitoL;
	float creditoA;
	float creditoL;
	float BTCA;
	float BTCL;
	float PPUA;
	float PPUL;
	float diferencia;



	do
	{
		showMenu(aerolineas, latam, kmts);

		do{
			menu=intScan("\ningrese una opcion del 1 al 6 para proceder: ");
		}while(intVerify(menu, 1, 6));

		switch (menu){
			case 1:
			{
				do{
					kmts=intScan("\ningrese los kilometros del recorrido (entre 70 y 16700): ");		//las rutas de vuelo mas corta y mas larga del planeta respectivamente segun google.
				}while(intVerify(kmts, 70, 16700));
				break;
			}
			case 2:
			{
				do{
					aerolineas=floatScan("\ningrese el precio de aerolineas: ");
				}while(floatVerify(aerolineas, 1, 0));	//precios positivos

				do{
					latam=floatScan("\ningrese el precio de latam");
				}while(floatVerify(latam, 1, 0));		//precios deben ser positivos

				break;
			}
			case 3:
			{
				findResults(&debitoA, &debitoL, &creditoA, &creditoL, &BTCA, &BTCL, &PPUA, &PPUL, kmts, latam, aerolineas, &diferencia);
				break;
			}
			case 4:
			{
				showResults( debitoA,  debitoL,  creditoA,  creditoL,  BTCA,  BTCL,  PPUA,  PPUL,  kmts,  latam,  aerolineas, diferencia);
				break;
			}
			case 5:{
				forceData();
			}
		}
		printf("\n________________________________________________________________________\n"); //imprime fin del bucle
	}while(menu!=6);
}


void showMenu(float a, float l, int k)	//muestra el menu siempre que bandera sea =0
{

	if (k!=-1){
		printf("\n1. Ingresar Kilómetros: ( km=%d)\n", k);
	}
	else
		printf("\n1. Ingresar Kilómetros: ( km=x)\n");


	if(a!=-1 && l!=-1){
		printf("\n2. Ingresar Precio de Vuelos: (Aerolíneas=%.2f, Latam=%.2f)\n", a, l);
	}
	else{
		printf("\n2. Ingresar Precio de Vuelos: (Aerolíneas=y, Latam=z)\n");
	}
		printf("\t- Precio vuelo Aerolíneas:\n");
		printf("\t- Precio vuelo Latam:\n");
		printf("\n3. Calcular todos los costos:\n");
		printf("a) Tarjeta de débito (descuento 10%%)\n");
		printf("b) Tarjeta de crédito (interés 25%%)\n");
		printf("c) Bitcoin (1BTC -> 4606954.55 Pesos Argentinos)\n");
		printf("d) Mostrar precio por km (precio unitario)\n");
		printf("e) Mostrar diferencia de precio ingresada (Latam - Aerolíneas)\n");
		printf("\n4. Informar Resultados\n");
		printf("“Latam:\n");
		printf("a) Precio con tarjeta de débito: r\n");
		printf("b) Precio con tarjeta de crédito: r\n");
		printf("c) Precio pagando con bitcoin : r\n");
		printf("d) Precio unitario: r\n");
		printf("Aerolíneas:\n");
		printf("a) Precio con tarjeta de débito: r\n");
		printf("b) Precio con tarjeta de crédito: r\n");
		printf("c) Precio pagando con bitcoin : r\n");
		printf("d) Precio unitario: r\n");
		printf("La diferencia de precio es : r “\n");
		printf("\n5. Carga forzada de datos\n");
		printf("\n6. Salir\n");



}


int intVerify(int numero, int minimo, int maximo){

	if(minimo==1 && maximo==0)
	{
		if (numero>0)
			return 0;			//si minimo=1 y maximo=0 hay que verificar si el numero es positivo
		else
			printf("\nno ingreso un valor positivo");
	}


	else if(minimo==0 && maximo==-1)
	{
		if (numero<0)
			return 0;			//si minimo=0 y maximo=-1 hay que verificar si el numero es negativo
		else
			printf("\nno ingreso un valor negativo");
	}

	else if( minimo<=numero && numero<=maximo )		//verifica que el numero este en el intervalo dado
	{
		return 0;


	}
	else
	{
		printf("\nno ingreso valores segun lo esperado.");
		return 1;				//anuncia que el valor no esta en el intervalo dado y retorna 1

	}

	return 1; //retorna 1 porque no se cumplieron las condiciones deseadas

}

int floatVerify(float numero, int minimo, int maximo){


	if(minimo==1 && maximo==0)
	{
		if (numero>0)
			return 0;			//si minimo=1 y maximo=0 hay que verificar si el numero es positivo
		else
			printf("\nno ingreso un valor positivo.");
	}


	else if(minimo==0 && maximo==-1)
	{
		if (numero<0)
			return 0;			//si minimo=0 y maximo=-1 hay que verificar si el numero es negativo
		else
			printf("\nno ingreso un valor negativo.");
	}

	else if( minimo<=numero && numero<=maximo )		//verifica que el numero este en el intervalo dado
	{
		return 0;


	}
	else
	{
		printf("\nno ingreso valores segun el intervalo solicitado.");
		return 1;				//anuncia que el valor no esta en el intervalo dado y retorna 1

	}

	return 1; //retorna 1 porque no se cumplieron las condiciones deseadas

}

float basicMath(float a, float b, char operacion){

	switch (operacion){
		case '+':
			return a+b;
		case '-':
			return a-b;
		case '*':
			return a*b;

		case '/':
			return a/b;
	}

return 1;
}

void showResults(float debitoA, float debitoL, float creditoA, float creditoL, float BTCA, float BTCL, float PPUA, float PPUL, int kmts, float latam, float aerolineas, float diferencia){

	printf("\nopcion 4) Informar Resultados:\n");

	if(debitoA==-1){		//si debitoA=-1 entonces no ha completado la opcion 3
		printf("\nno puede acceder a la opcion 4 sin completar la opcion 3. Complete dichos datos y reintente");
	}
	else{
		printf("kilometros ingresados = %d \n", kmts);

		printf("\n\tprecio Aerolíneas: %.2f", aerolineas);
		printf("\n a) Precio con tarjeta de débito: $%.2f", debitoA);
		printf("\n b) Precio con tarjeta de crédito: $%.2f", creditoA);
		printf("\n c) Precio pagando con bitcoin : %f BTC", BTCA);
		printf("\n d) Precio unitario: $%.2f", PPUA);


		printf("\n\tprecio Latam: %.2f", latam);
		printf("\n a) Precio con tarjeta de débito: $%.2f", debitoL);
		printf("\n Precio con tarjeta de crédito: $%.2f", creditoL);
		printf("\n c) Precio pagando con bitcoin : %f BTC", BTCL);
		printf("\n d) Precio unitario: $%.2f", PPUL);

		printf("\n La diferencia de precio es : $%.2f ", diferencia );
	}

}

void forceData(){

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

		findResults(&debitoA, &debitoL, &creditoA, &creditoL, &BTCA, &BTCL, &PPUA, &PPUL, kmts, latam, aerolineas, &diferencia);
		showResults( debitoA,  debitoL,  creditoA,  creditoL,  BTCA,  BTCL,  PPUA,  PPUL,  kmts,  latam,  aerolineas, diferencia);


}

void findResults(float *debitoA, float *debitoL, float *creditoA, float *creditoL, float *BTCA, float *BTCL, float *PPUA, float *PPUL, int kmts, float latam, float aerolineas, float *diferencia){

	printf("\nopcion 3) Calcular todos los costos:\n");


	if (kmts==-1 || latam==-1 || aerolineas==-1 ){		//no entra a la opcion 3 sin haber completado las opciones 1 y 2
		printf("aun no ha completado los datos de distancia y precio. Complete dichos datos y reintente\n");
	}
	else{
		//|
		*debitoA= basicMath(aerolineas, 0.9, '*');
		*debitoL= basicMath(latam, 0.9, '*');
		*creditoA= basicMath(aerolineas, 1.25, '*');
		*creditoL= basicMath(latam, 1.25, '*');
		*BTCA= basicMath(aerolineas, P_BTC, '/');
		*BTCL= basicMath(latam, P_BTC, '/');
		*PPUA= basicMath(aerolineas, kmts, '/');
		*PPUL= basicMath(latam, kmts, '/');

		if(aerolineas>=latam)
			*diferencia=basicMath(aerolineas, latam, '-');
		else
			*diferencia=basicMath(latam, aerolineas, '-');

		printf("\nse han hecho los calculos solicitados");

	}

}

int intScan(char *mensaje){

	int a;
	printf("%s", mensaje);
	fflush(stdin);
	scanf("%d", &a);
	return a;

}

int floatScan(char *mensaje){

	float a;
	printf("%s", mensaje);
	fflush(stdin);
	scanf("%f", &a);
	return a;

}
