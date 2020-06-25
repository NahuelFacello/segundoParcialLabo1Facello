#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//Pide enteros por consola
int utn_getNumeroInt(int* intNumber, char* mensaje, char* mensajeError,int minimo, int maximo, int reintentos )
{
	int bufferInt;
	int retorno = -1;
	if(intNumber != NULL && mensaje != NULL && mensajeError != NULL && minimo<=maximo && reintentos >=0)
	{
		do
		{
			printf("%s",mensaje);
			scanf("%d",&bufferInt);
			if(bufferInt >= minimo && bufferInt <= maximo)
			{
				*intNumber = bufferInt;
				retorno=0;
				break;
			}else
			{
				printf("%s", mensajeError);
				reintentos--;
			}
		}while(reintentos >0);
	}
	return retorno;
}
//Pide flotantes por consola
int utn_getNumeroFloat(float* floatNumber, char* mensaje, char* mensajeError,int minimo, int maximo, int reintentos )
{
	int bufferInt;
	int retorno = -1;
	if(floatNumber != NULL && mensaje != NULL && mensajeError != NULL && minimo<=maximo && reintentos >=0)
	{
		do
		{
			printf("%s",mensaje);
			scanf("%d",&bufferInt);
			if(bufferInt >= minimo && bufferInt <= maximo)
			{
				*floatNumber = bufferInt;
				retorno=0;
				break;
			}else
			{
				printf("%s", mensajeError);
				reintentos--;
			}
		}while(reintentos >0);
	}
	return retorno;
}
//Suma de enteros
int utn_suma(int *pResultado,int operador1, int operador2)
{
	int retorno= -1;
	int resultado;

	if(pResultado!= NULL)
	{
		resultado= operador1+operador2;
		*pResultado= resultado;
		retorno=0;
	}
	return retorno;
}
// Resta de enteros
int utn_resta(int *pResultado,int x, int y)
{
	int retorno= -1;
	int resultado;

	if(pResultado!= NULL)
	{
		resultado= x-y;
		*pResultado= resultado;
		retorno=0;
	}
	return retorno;
}
// Multiplicacion de enteros
int utn_multiplicacion(int *pResultado,int x, int y)
{
	int retorno= -1;
	int resultado;

	if(pResultado!= NULL)
	{
		resultado= x*y;
		*pResultado= resultado;
		retorno=0;
	}
	return retorno;
}
//Division
int utn_division(float *pResultado ,int dividendo, int divisor)
{
	float resultado;
	int retorno =-1;
	if(pResultado!= NULL && divisor !=0)
	{
		resultado= (float)dividendo / divisor;
		*pResultado=resultado;
		retorno=0;
	}
	return retorno;
}
//Pide numeros para la calculadora
int utn_getNumeroCalculadora(int* intNumber, char* mensaje)
{
	int bufferInt;
	int retorno = -1;
	if(intNumber != NULL && mensaje != NULL )
	{
		printf("%s",mensaje);
		scanf("%d",&bufferInt);
		*intNumber = bufferInt;
		retorno=0;
	}
	return retorno;
}
//Factorial
int utn_factorial(int*pResultado,int operador)
{
	int resultado=1;
	int i;
	int retorno =-1;
	if(operador<0)
	{
		retorno = -2;
	}
	else
	{
		if(operador==0)
		{
			*pResultado=1;
		}
		else
		{
			for(i=1;i<=operador;i++)
			{
				resultado*=i;
			}
			*pResultado=resultado;
			retorno=0;
		}
	}
	return retorno;
}
//Pide numeros enteros para un Array
int getArrayInt(int *pArray, int limite, char *pMensaje,char *pMensajeError, int minimo, int maximo, int reintentos)
{
	int i=0;
	int buffer;
	char respuesta;
	if(pArray != NULL&&limite>0)
	{
		do
		{
			if(utn_getNumeroInt(&buffer,pMensaje,pMensajeError,minimo,maximo,reintentos)==0)
			{
				pArray[i]=buffer;
				i++;
				if(i==limite)
				{
					printf("Llego al limite del vector\n\n");
					break;
				}
			}
			printf("Continuar (s/n)\n");
			fflush(stdin);
			scanf("%c",&respuesta);
		}while(respuesta!='n');
	}
	return i;
}
//Inicializa array Enteros
int initArrayInt(int* pArray, int limite, int valor)
{
	int retorno=-1;
	int i;

	if(pArray != NULL && limite >0)
	{
		for(i=0; i<limite; i++)
		{
			pArray[i]=valor;
		}
		retorno=0;
	}
	return retorno;
}
//imprime Array Enteros
int printArrayInt(int* arrayInt, int limite)
{
	int i;
	int retorno=-1;
		for(i=0;i<limite;i++)
		{
			printf("Indice: [%d] valor: %d\n",i,arrayInt[i]);
		}
		retorno=0;

	return retorno;
}
//Inicializa array flotantes
int initArrayFloat(float* pArray, int limite, int valor)
{
	int retorno=-1;
	int i;

	if(pArray != NULL && limite >0)
	{
		for(i=0; i<limite; i++)
		{
			pArray[i]=valor;
		}
		retorno=0;
	}
	return retorno;
}
//imprime Array de flotantes
int printArrayFloat(float* arrayFloat, int limite)
{
	int i;
	int retorno=-1;
		for(i=0;i<limite;i++)
		{
			printf("Indice: [%d] valor: %.2f\n",i,arrayFloat[i]);
		}
		retorno=0;

	return retorno;
}
//Pide numeros flotantes para un Array
int getArrayFloat(float *pArray, int limite, char *pMensaje,char *pMensajeError, int minimo, int maximo, int reintentos)
{
	int i=0;
	float buffer;
	char respuesta;
	if(pArray != NULL&&limite>0)
	{
		do
		{
			if(utn_getNumeroFloat(&buffer,pMensaje,pMensajeError,minimo,maximo,reintentos)==0)
			{
				pArray[i]=buffer;
				i++;
				if(i==limite)
				{
					printf("Llego al limite del vector\n\n");
					break;
				}
			}
			printf("Continuar (s/n)\n");
			fflush(stdin);
			scanf("%c",&respuesta);
		}while(respuesta!='n');
	}
	return i;
}int utn_getAnswer(char* pChar, char message[4069], char errorMessage[4069], int retries)
{
	char letter;
	int reply=-1;
	do
	{
		printf("%s",message);
		fflush(stdin);
		scanf("%c",&letter);
		if((letter!='s')&&(letter!='n'))
		{
			printf("%s",errorMessage);
			retries--;
		}else
		{
		   *pChar=letter;
		   reply=0;
			break;
		}
	}while(retries>0);

	return reply;
}

int utn_getAChar(char aChar[], char message[4069], char errorMessage[4069], int retries, int aQty)
{
	char text[aQty];
	int i;
	int reply;

	do
	{
		fflush(stdin);
		printf("%s",message);
		fflush(stdin);
		gets(text);
		reply=0;
		for(i=0 ; text[i] != '\0' && i < aQty; i++)
		{
			if((text[i] < 'A' || text[i] > 'Z' ) && (text[i] < 'a' || text[i] > 'z' ) && text[i]!= ' ')
			{
				reply =-1;
				printf("%s",errorMessage);
				retries--;
				system("cls");
				break;
			}
		}
		if(reply==0)
		{
			strncpy(aChar,text,aQty);
			break;
		}
	}while(retries>0);

	return reply;
}
