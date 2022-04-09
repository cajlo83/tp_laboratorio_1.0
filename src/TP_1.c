/*
 ============================================================================
 Name        : TP_1.c
 Author      : Carlo Morici
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#define P_BTC 4606954.55


void muestraMenus(float a, float l, int k);
void muestraResultados(float debitoA, float debitoL, float creditoA, float creditoL, float BTCA, float BTCL, float PPUA, float PPUL, int kmts, float latam, float aerolineas, float diferencia);
int intVerificado(int numero, int minimo, int maximo);
int floatVerificado(float numero, int minimo, int maximo);
float aritmetica(float a, float b, char operacion);
void cargaForazada();



int main(void) {

	setbuf(stdout, NULL);


	int kmts=-1;
	float aerolineas=-1;
	float latam=-1;

	int menu=0;
	int banderin;


	float debitoA=-1;
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
		//verificacion de seleccion en menu

		do{
			muestraMenus(aerolineas, latam, kmts);
			fflush(stdin);
			printf("ingrese una opcion del 1 al 6 para proceder :");
			scanf("%d", &menu);
			banderin=intVerificado(menu, 1, 6);

		}while(banderin);//fin seleccion menu


		switch (menu)
		{
			case 1:
			{


				//verificacion de asignacion de kilometros
				do{
					fflush(stdin);
					printf("ingrese los kilometros del recorrido (entre 70 y 16700): ");
					scanf("%d", &kmts);
					banderin=intVerificado(kmts, 70, 16700); //las rutas de vuelo mas corta y mas larga del planeta respectivamente segun google.
				}while(banderin);//fin asignacion de kilometros

				printf("kilometros ingresados = %d \n", kmts);
				break;
			}




			case 2:
			{
				printf("\nopcion 2) Ingresar Precio de Vuelos:\n");

				//verificacion de - Precio vuelo Aerolíneas:
				do{
					fflush(stdin);
					printf("ingrese el precio de aerolineas: ");
					scanf("%f", &aerolineas);
					banderin=floatVerificado(aerolineas, 1, 0); //precios deben ser positivos
				}while(banderin);//fin de - Precio vuelo Aerolíneas:

				printf("precio ingresado = %.2f \n", aerolineas);



				//verificacion de - Precio vuelo Latam:

				do{
					fflush(stdin);
					printf("ingrese el precio de latam: ");
					scanf("%f", &latam);
					banderin=floatVerificado(latam, 1, 0); //precios deben ser positivos
				}while(banderin);//fin de - Precio vuelo Latam:

				printf("precio ingresado = %.2f \n", latam);



				break;
			}




			case 3:
			{
				printf("\nopcion 3) Calcular todos los costos:\n");



				if (kmts==-1 || latam==-1 || aerolineas==-1 ){		//no entra a la opcion 3 sin haber completado las opciones 1 y 2
					printf("aun no ha completado los datos de distancia y precio. Complete dichos datos y reintente\n");
				}
				else{
					//|
					debitoA= aritmetica(aerolineas, 0.9, '*');
					debitoL= aritmetica(latam, 0.9, '*');

					creditoA= aritmetica(aerolineas, 1.25, '*');
					creditoL= aritmetica(latam, 1.25, '*');

					BTCA= aritmetica(aerolineas, P_BTC, '/');
					BTCL= aritmetica(latam, P_BTC, '/');

					PPUA= aritmetica(aerolineas, kmts, '/');
					PPUL= aritmetica(latam, kmts, '/');

					if(aerolineas>=latam)
						diferencia=aritmetica(aerolineas, latam, '-');
					else
						diferencia=aritmetica(latam, aerolineas, '-');

					printf("\nse han hecho los calculos solicitados");

				}

				break;
			}



			case 4:
			{
				printf("\nopcion 4) Informar Resultados:\n");

				if(debitoA==-1){		//si debitoA=-1 entonces no ha completado la opcion 3
					printf("\nno puede acceder a la opcion 4 sin completar la opcion 3. Complete dichos datos y reintente");
				}
				else{

					muestraResultados( debitoA,  debitoL,  creditoA,  creditoL,  BTCA,  BTCL,  PPUA,  PPUL,  kmts,  latam,  aerolineas, diferencia);

				}



				break;
			}



			case 5:{

				printf("\nopcion 5) Carga forzada de datos:\n");
				cargaForazada();



				break;
			}





		}


		printf("\n________________________________________________________________________\n"); //imprime fin del bucle


	}while(menu!=6);





	puts("!!!Hello World !!!"); /* prints !!!Hello World!!! */
	return EXIT_SUCCESS;
}


void muestraMenus(float a, float l, int k)	//muestra el menu siempre que bandera sea =0
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


int intVerificado(int numero, int minimo, int maximo){	//devuelve 1 o 0 a un banderin para determinar si debe continuar un bucle

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


int floatVerificado(float numero, int minimo, int maximo){	//devuelve 1 o 0 a un banderin para determinar si debe continuar un bucle

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

float aritmetica(float a, float b, char operacion){		//hace operaciones aritmeticas segun se ingrese los caracteres '*', '/', '+', '-', '%' // @suppress("No return")

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


void muestraResultados(float debitoA, float debitoL, float creditoA, float creditoL, float BTCA, float BTCL, float PPUA, float PPUL, int kmts, float latam, float aerolineas, float diferencia){
	printf("kilometros ingresados = %d \n", kmts);

	printf("\n\tprecio Aerolíneas: %.2f", aerolineas);
	printf("\n a) Precio con tarjeta de débito: $%.2f", debitoA);
	printf("\n b) Precio con tarjeta de crédito: $%.2f", creditoA);
	printf("\n c) Precio pagando con bitcoin : %.2f BTC", BTCA);
	printf("\n d) Precio unitario: $%.2f", PPUA);


	printf("\n\tprecio Latam: %.2f", latam);
	printf("\n a) Precio con tarjeta de débito: $%.2f", debitoL);
	printf("\n Precio con tarjeta de crédito: $%.2f", creditoL);
	printf("\n c) Precio pagando con bitcoin : %.2f BTC", BTCL);
	printf("\n d) Precio unitario: $%.2f", PPUL);

	printf("\n La diferencia de precio es : $%.2f ", diferencia );

}


void cargaForazada(){

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

		debitoA= aritmetica(aerolineas, 0.9, '*');
		debitoL= aritmetica(latam, 0.9, '*');

		creditoA= aritmetica(aerolineas, 1.25, '*');
		creditoL= aritmetica(latam, 1.25, '*');

		BTCA= aritmetica(aerolineas, P_BTC, '/');
		BTCL= aritmetica(latam, P_BTC, '/');

		PPUA= aritmetica(aerolineas, kmts, '/');
		PPUL= aritmetica(latam, kmts, '/');

		if(aerolineas>=latam)
			diferencia=aritmetica(aerolineas, latam, '-');
		else
			diferencia=aritmetica(latam, aerolineas, '-');

		muestraResultados( debitoA,  debitoL,  creditoA,  creditoL,  BTCA,  BTCL,  PPUA,  PPUL,  kmts,  latam,  aerolineas, diferencia);


}

