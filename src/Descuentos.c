/*
 * Descuentos.c
 *
 *  Created on: 25 jun. 2020
 *      Author: Nahu
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Articulo.h"

int descuento_cuidadoDeRopa(void* this)
{
	int retorno = -1;
	float auxPrecio;
	float descuento;
	float auxPrecioConDescuento;
	int auxRubro;

	if (this != NULL)
	{
		if(!articulo_getRubro((Articulo*)this,&auxRubro) && auxRubro == 1 &&
		!articulo_getPrecio((Articulo*)this,&auxPrecio) && auxPrecio >= 120)
		{
			descuento = (float)auxPrecio*20/100;
			auxPrecioConDescuento = (float)auxPrecio-descuento;
			if(!articulo_setPrecio((Articulo*)this,(float)auxPrecioConDescuento))
				retorno = 0;
		}

	}
	return retorno;
}
int descuento_elementosDeLimpieza(void* this)
{
	int retorno = -1;
	float auxPrecio;
	float descuento;
	float auxPrecioConDescuento;
	int auxRubro;

	if (this != NULL)
	{
		if(!articulo_getRubro((Articulo*)this,&auxRubro) && auxRubro == 2 &&
		!articulo_getPrecio((Articulo*)this,&auxPrecio) && auxPrecio <= 200)
		{
			descuento = (float)auxPrecio*10/100;
			auxPrecioConDescuento = (float)auxPrecio-descuento;
			if(!articulo_setPrecio((Articulo*)this,(float)auxPrecioConDescuento))
				retorno = 0;
		}

	}
	return retorno;
}
