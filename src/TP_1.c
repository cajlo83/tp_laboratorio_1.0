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


void muestraMenus(int bandera);
int intVerificado(int numero, int minimo, int maximo);
int intPositivo(int numero);
int floatPositivo(float numero);

int main(void) {

	setbuf(stdout, NULL);


	int kmts=-1;
	float aerolineas=-1;
	float latam=-1;

	int menu=0;
	int banderin;




	do
	{

		muestraMenus(menu);



		printf("_______________________________________ \n");


		//verificacion de seleccion en menu
		banderin=2;
		while(banderin)
		{
			fflush(stdin);
			if( banderin==1 )
			{
				printf("\nno ingreso valores validos.\ningrese una opcion del 1 al 6 para proceder: ");
			}
			else
				printf("\ningrese una opcion del 1 al 6 para proceder :");

			scanf("%d", &menu);
			banderin=intVerificado(menu, 1, 6);
		}//fin seleccion menu


		switch (menu)
		{
			case 1:
			{

				/*
				printf("Ingresar Kilómetros: ");
				scanf("%d", &kmts);
				*/

				//verificacion de asignacion de kilometros
				banderin=2;
				while(banderin!=1)
				{
					fflush(stdin);
					if( banderin==0 || banderin==-1 )
					{
						printf("\nno ingreso valores validos.\nopcion 1) ingrese un valor de distancia mayor a 0: ");
					}
					else
						printf("\nopcion 1) ingrese un valor de distancia mayor a 0: ");

					scanf("%d", &kmts);
					banderin=intPositivo(kmts);
				}//fin verificacion de asignacion de kilometros


				break;
			}






			case 2:
			{
				printf("\nopcion 2) Ingresar Precio de Vuelos:");

				//verificacion de - Precio vuelo Aerolíneas:
				banderin=2;
				while(banderin!=1)
				{
					fflush(stdin);
					if( banderin==0 || banderin==-1 )
					{
						printf("\nno ingreso valores validos.\nopcion 2) Ingresar - Precio vuelo Aerolíneas: ");
					}
					else
						printf("\nopcion 2) Ingresar - Precio vuelo Aerolíneas: ");

					scanf("%f", &aerolineas);
					banderin=floatPositivo(aerolineas);
				}//fin verificacion de - Precio vuelo Aerolíneas:



				//verificacion de - Precio vuelo Latam::
				banderin=2;
				while(banderin!=1)
				{
					fflush(stdin);
					if( banderin==0 || banderin==-1 )
					{
						printf("\nno ingreso valores validos.\nopcion 2) Ingresar - Precio vuelo Latam:: ");
					}
					else
						printf("\nopcion 2) Ingresar - Precio vuelo Latam:: ");

					scanf("%f", &latam);
					banderin=floatPositivo(latam);
				}//fin verificacion de - Precio vuelo Latam::




				break;
			}




			case 3:
			{


			}




		}


	}while(menu!=6);





	puts("!!!Hello World !!!"); /* prints !!!Hello World!!! */
	return EXIT_SUCCESS;
}


void muestraMenus(int bandera)
{

	if ( bandera==0 )
	{
		printf("\n1. Ingresar Kilómetros: ( km=x)\n");
		printf("\n2. Ingresar Precio de Vuelos: (Aerolíneas=y, Latam=z)\n");
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
}


int intVerificado(int numero, int minimo, int maximo){

	if (minimo==maximo)
	{
		return 0;
	}
	else if( minimo<=numero && numero<=maximo )
	{
		return 0;
	}
	else
		return 1;
}


int intPositivo(int numero)
{

	if (numero>0)
		return 1;

	else if (numero<0)
		return -1;

	else
		return 0;
}

int floatPositivo(float numero)
{

	if (numero>0)
		return 1;

	else if (numero<0)
		return -1;

	else
		return 0;

}
