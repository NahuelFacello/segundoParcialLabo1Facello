/*
 ============================================================================
 Name        : SegundoParcialLabo1-Facello.c
 Author      : Nahuel Facello
 Version     :
 Copyright   : 
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Articulo.h"

int main(void)
{
	LinkedList* pListaArticulos = ll_newLinkedList();
	int flag = 0;
	int opcionMenu;
	setbuf(stdout,NULL);
	do{
		void menu();
		utn_getNumeroInt(&opcionMenu,"Opcion : ", "\nError, intene nuevamente\n",1,5,3);
		switch(opcionMenu)
		{
		case 1:
			controller_loadFromText("Datos_SP_LABO1.csv",pListaArticulos);
			flag = 1;
			break;

		case 2:
			if(flag != 0)
				controller_imprimirArticulos(pListaArticulos);
			else
				printf("\nNada que imprimir\n");
			break;

		case 3:
			if(flag != 0)
			{
				if(!ll_sort(pListaArticulos, articulo_sortArticulo,1))
				printf("\nOrdenado de forma ascendente\n");
				else
				printf("\nNo se pudo ordernar\n");
			}
			else
				printf("\nNada que ordenar\n");

			break;

		case 4:
			if(flag != 0)
			{
				if(!controller_descuentos(pListaArticulos))
				printf("\nDescuentos aplicados\n");
				else
				prinf("\nNo se pudo aplicar el descuento\n");
			}
			else
				printf("\nSin articulos\n");
			break;

		}

		//printf("%d", retorno);


		controller_imprimirArticulos(pListaArticulos);

		controller_imprimirArticulos(pListaArticulos);
		controller_saveAsText("mapeado.csv", pListaArticulos);
	}while(opcionMenu != 5);
	return EXIT_SUCCESS;
}
