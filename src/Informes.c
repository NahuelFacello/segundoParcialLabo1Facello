/*
 * Informes.c
 *
 *  Created on: 25 jun. 2020
 *      Author: Nahu
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Articulo.h"
#include "LinkedList.h"

int informes_articulosPrecioMayorA100(void* pArticulo)
{

	float auxPrecio;
	int retorno = 0;
	if(pArticulo != NULL)
	{
		if(!articulo_getPrecio((Articulo*)pArticulo,&auxPrecio) && auxPrecio >100)
		{
			retorno = 1;
		}
	}
	return retorno;
}

int informes_articulosRubro1(void* pArticulo)
{
	int auxRubro;
	int retorno = 0;
	if(pArticulo != NULL)
	{
		if(!articulo_getRubro((Articulo*)pArticulo,&auxRubro) && auxRubro == 1)
		{
			retorno = 1;
		}
	}
	return retorno;
}
