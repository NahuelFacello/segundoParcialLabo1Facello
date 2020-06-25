#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Articulo.h"

/** \brief Parsea los datos los datos de los articulo desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pListaArticulos LinkedList*
 * \return int
 *
 */
int parser_ArticulosFromText(FILE* pFile , LinkedList* pListaArticulos)
{
	Articulo* pArticulo;
	char id[10];
	char articulo[50];
	char medida[10];
	char precio[7];
	char rubro[2];
	int flag = 0;
	int retorno = -1;

	do
	{	//flag == 0 porque tiene titulo
		if(flag == 0)
		{
			fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",id,articulo,medida,precio,rubro);
			flag = 1;
		}
		if(fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",id,articulo,medida,precio,rubro)==5)
		{
			//printf("%s-%s-%s-%s-%s\n",id,articulo,medida,precio,rubro);
			if (flag != 0)
				pArticulo = articulo_newParametros(id,articulo,medida,precio,rubro);

			if(pArticulo != NULL && flag != 0)
			{
				ll_add(pListaArticulos,(Articulo*)pArticulo);
				retorno = 0;
			}
		}
		else
			break;
	}while(feof(pFile)==0);
    return retorno;
}
