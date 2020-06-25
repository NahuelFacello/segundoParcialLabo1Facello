/*
 * Articulo.h
 *
 *  Created on: 24 jun. 2020
 *      Author: Nahu
 */

#ifndef ARTICULO_H_
#define ARTICULO_H_
#include "LinkedList.h"

struct{
	int id;
	char articulo[50];
	char medida[10];
	float precio;
	int rubroId;
}typedef Articulo;


Articulo* articulo_new();

Articulo* articulo_newParametros(char* idStr,char* articuloStr,char* medidaStr, char* precioStr, char* rubroStr);

void articulo_delete(Articulo* this);

int articulo_setId(Articulo* this,int id);
int articulo_getId(Articulo* this,int* id);

int articulo_setArticulo(Articulo* this,char* articulo);
int articulo_getArticulo(Articulo* this,char* articulo);

int articulo_setMedida(Articulo* this,char* medida);
int articulo_getMedida(Articulo* this,char* medida);

int articulo_setPrecio(Articulo* this,float precio);
int articulo_getPrecio(Articulo* this,float* precio);

int articulo_setRubro(Articulo* this,int rubroId);
int articulo_getRubro(Articulo* this,int* rubroId);

int articulo_getRubroChar(Articulo* this,char* rubroChar);

int articulo_printOne(Articulo* this);
int articulo_printAll(LinkedList* pListaArticulos);

int articulo_sortArticulo(void* pArticuloA, void* pArticuloB);

#endif /* ARTICULO_H_ */
