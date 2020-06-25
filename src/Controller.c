#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Articulo.h"
#include "parser.h"
#include "Descuentos.h"

//#include "utn_funciones.h"

/** \brief Carga los datos de los articulos desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pListaArticulos LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pListaArticulos)
{
	FILE* pFile;
	int retorno = -1;
	int retornoParser = -1;
	if( path != NULL && pListaArticulos != NULL)
	{
		pFile = fopen(path,"r");
		if(pFile != NULL)
		{

			retornoParser= parser_ArticulosFromText(pFile,pListaArticulos);
			if(retornoParser == 0)
			{
				printf("\nLeido exitoso\n");
				retorno = 0;
			}
			else
				printf("\n Error en la lectura\n");
			//printf("\nRetorno parser: %d\n",retornoParser);
			fclose(pFile);
		}
		else
		{
			printf("El archivo no pudo ser leido\n");
		}
	}
    return retorno;
}

/** \brief Imprime los articulos de la linkedList
 *
 * \param pListaArticulos LinkedList*
 * \return int 0 ok -1 error
 * \
 *
 */
int controller_imprimirArticulos(LinkedList* pListaArticulos)
{
	int retorno = -1;

	if(pListaArticulos != NULL)
	{
		retorno = articulo_printAll(pListaArticulos);
	}
	return retorno;
}

int controller_descuentos(LinkedList* pListaArticulos)
{
	int retorno = -1;
	if(pListaArticulos != NULL)
	{
		ll_map(pListaArticulos,descuento_cuidadoDeRopa);
		ll_map(pListaArticulos,descuento_elementosDeLimpieza);
		retorno = 0;
	}
	return retorno;
}

/** \brief Guarda los datos de los articulos en el archivo mapeado.csv (modo texto).
 *
 * \param path char*
 * \param pListaArticulos LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pListaArticulos)
{
	Articulo* pAuxArticulo;
	FILE* pNewFile;
	int retorno = -1;
	int auxId;
	char auxArticulo[50];
	char auxMedida[10];
	float auxPrecio;
	int auxRubro;
	int i;

	if(path != NULL && pListaArticulos != NULL)
	{
		pNewFile = fopen(path,"w+");

		for(i = 0; i<ll_len(pListaArticulos); i++)
		{
			pAuxArticulo = (Articulo*)ll_get(pListaArticulos,i);

			if(pAuxArticulo !=  NULL && !articulo_getId(pAuxArticulo,&auxId) &&
			 !articulo_getArticulo(pAuxArticulo,auxArticulo) &&
			 !articulo_getMedida(pAuxArticulo,auxMedida) &&
			 !articulo_getPrecio(pAuxArticulo,&auxPrecio) &&
             !articulo_getRubro(pAuxArticulo,&auxRubro))
			{
				fprintf(pNewFile,"%d,%s,%s,%f.2,%d\n",auxId,auxArticulo,auxMedida,auxPrecio,auxRubro);
				retorno =0;
			}
		}
		fclose(pNewFile);
	}
    return retorno;
}

void menu()
{
	printf("\n**************ARTICULOS*******************\n\n");
	prinf("1. Importar de archivo\n"
			"2. Imprimir articulos\n"
			"3. Ordenar articulos de forma ascendete\n"
			"3. Aplicar descuentos\n"
			"4. Exportar archivo a MAPEADO.CSV\n"
			"5. Salir\n");
}
