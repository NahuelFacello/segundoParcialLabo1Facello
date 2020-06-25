/*
 * Articulo.c
 *
 *  Created on: 24 jun. 2020
 *      Author: Nahu
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Articulo.h"

Articulo* articulo_new()
{
	return (Articulo*)malloc(sizeof(Articulo));
}

Articulo* articulo_newParametros(char* idStr,char* articuloStr,char* medidaStr, char* precioStr, char* rubroStr)
{
	Articulo* pArticulo = NULL;

	pArticulo = articulo_new();
	setbuf(stdout,NULL);

	if(pArticulo != NULL)
	{
		pArticulo->id = atoi(idStr);
		strcpy(pArticulo->articulo,articuloStr);
		strcpy(pArticulo->medida,medidaStr);
		pArticulo->precio = atof(precioStr);
		pArticulo->rubroId = atoi(rubroStr);
	}
	return pArticulo;
}

void articulo_delete(Articulo* this)
{
	if(this != NULL)
	{
		free(this);
	}
}

int articulo_setId(Articulo* this,int id)
{
	int retorno = -1;
	if(this != NULL && id > 0 )
	{
		this->id = id;
		retorno = 0;
	}
	return retorno;
}

int articulo_getId(Articulo* this,int* id)
{
	int retorno = -1;
	if( this != NULL && id != NULL)
	{
		*id = this->id;
		retorno = 0;
	}
	return retorno;
}

int articulo_setArticulo(Articulo* this,char* articulo)
{
	int retorno = -1;
	if(this != NULL && articulo != NULL )
	{
		strncpy(this->articulo,articulo,50);
		retorno = 0;
	}
	return retorno;
}

int articulo_getArticulo(Articulo* this,char* articulo)
{
	int retorno = -1;
	if(this != NULL && articulo != NULL )
	{
		strncpy(articulo,this->articulo,50);
		retorno = 0;
	}
	return retorno;
}


int articulo_setMedida(Articulo* this,char* medida)
{
	int retorno = -1;
	if(this != NULL && medida != NULL )
	{
		strncpy(this->medida,medida,10);
		retorno = 0;
	}
	return retorno;
}

int articulo_getMedida(Articulo* this,char* medida)
{
	int retorno = -1;
	if(this != NULL && medida != NULL )
	{
		strncpy(medida,this->medida,10);
		retorno = 0;
	}
	return retorno;
}

int articulo_setPrecio(Articulo* this,float precio)
{
	int retorno = -1;
	if(this != NULL && precio >= 0 )
	{
		this->precio = precio;
		retorno = 0;
	}
	return retorno;
}

int articulo_getPrecio(Articulo* this,float* precio)
{
	int retorno = -1;
	if( this != NULL && precio != NULL)
	{
		*precio = this->precio;
		retorno = 0;
	}
	return retorno;
}

int articulo_setRubro(Articulo* this,int rubroId)
{
	int retorno = -1;
	if(this != NULL && rubroId > 0 )
	{
		this->rubroId = rubroId;
		retorno = 0;
	}
	return retorno;
}

int articulo_getRubro(Articulo* this,int* rubroId)
{
	int retorno = -1;
	if( this != NULL && rubroId != NULL)
	{
		*rubroId = this->rubroId;
		retorno = 0;
	}
	return retorno;
}

int articulo_getRubroChar(Articulo* this,char* rubroChar)
{
	int retorno = -1;
	int auxRubroId;
	if( this != NULL && rubroChar != NULL)
	{
		auxRubroId = this->rubroId;
		switch(auxRubroId)
		{
		case 1:
			strcpy(rubroChar, "Cuidado de ropa");
			break;
		case 2:
			strcpy(rubroChar, "Limpieza y desinfeccion");
					break;
		case 3:
			strcpy(rubroChar, "Cuidado personal e higiene");
					break;
		case 4:
		strcpy(rubroChar, "Cuidado del automotor");
					break;
		default:
			strcpy(rubroChar, "No definido");
			break;
		}

		retorno = 0;
	}
	return retorno;
}

int articulo_printOne(Articulo* this)
{
	int retorno = -1;
	int auxId;
	char auxArticulo[50];
	char auxMedida[10];
	float auxPrecio;
	char auxRubroChar[30];
	if(this != NULL)
	{
		if(!articulo_getId(this,&auxId)&&
		 !articulo_getArticulo(this,auxArticulo)&&
		 !articulo_getMedida(this,auxMedida)&&
		 !articulo_getPrecio(this,&auxPrecio)&&
		 !articulo_getRubroChar(this,auxRubroChar))
		{
			printf("%-3.3d   %-40.40s   %-10.10s   %-8.2f   %-40.40s\n",auxId,auxArticulo,auxMedida,auxPrecio,auxRubroChar);
			retorno = 0;
		}

	}
	return retorno;
}
int articulo_printAll(LinkedList* pListaArticulos)
{
	Articulo* auxArticulo;
	int i;
	int retorno = -1;
	printf("\n****************************************LISTA ARTICULOS*******************************************\n\n");
	if(pListaArticulos != NULL)
	{
		printf("ID\tARTICULO\t\t\t\t MEDIDA\t      PRECIO     RUBRO\n");
		for(i = 0; i< ll_len(pListaArticulos);i++)
		{
			auxArticulo = (Articulo*)ll_get(pListaArticulos,i);
			if(auxArticulo != NULL)
			{
				articulo_printOne(auxArticulo);
				retorno = 0;
			}
		}
	}
	return retorno;
}

int articulo_sortArticulo(void* pArticuloA, void* pArticuloB)
{
	char articuloA[60];
	char articuloB[60];
	articulo_getArticulo((Articulo*)pArticuloA,articuloA);
	articulo_getArticulo((Articulo*)pArticuloB,articuloB);

	return strcmp(articuloA,articuloB);
}
