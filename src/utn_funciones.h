#ifndef UTN_FUNCIONES_H_
#define UTN_FUNCIONES_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * \brief 	Pide un numero entero por consola
 * \param intNumber     	Devuelve el numero entero ingresado
 * \ param mensaje      	Mensaje para pedir numero
 * \param mensajeError	Mensaje de error
 * \param minimo 			Numero minimo a ingresar
 * \param maximo			Numero maximo a ingresar
 * \param reintentos		Cantidad de reintentos del usuario
 * \return 0						La funcion valido la informacion recibida segun los parametros
 * \return -1						Hubo un error
 */
int utn_getNumeroInt(int* intNumber, char* mensaje, char* mensajeError,int minimo, int maximo, int reintentos );
/*
 * \brief 	Pide numeros flotantes por consola
 * \param intNumber     	Devuelve el numero flotante ingresado
 * \ param mensaje      	Mensaje para pedir numero
 * \param mensajeError	Mensaje de error
 * \param minimo 			Numero minimo a ingresar
 * \param maximo			Numero maximo a ingresar
 * \param reintentos		Cantidad de reintentos del usuario
 * \return 0						La funcion valido la informacion recibida segun los parametros
 * \return -1						Hubo un error
 */
int utn_getNumeroFloat(float* floatNumber, char* mensaje, char* mensajeError,int minimo, int maximo, int reintentos );
/*
 * breaf Realiza la suma de dos enteros
 * param x Toma un numero entero
 * param y Toma un numero entero
 * return Devuelve la suma de los numeros
 */
int utn_suma(int *pResultado,int operador1, int operador2);

/*
 * breaf Realiza la resta de dos enteros
 * param x Toma un numero entero
 *param y Toma un numero entero
 * return Devuelve la resta de los numeros
 */
int utn_resta(int *pResultado,int x, int y);

/*
 * breaf Realiza la multiplicacion de dos enteros
 * param x Toma un numero entero
 *param y Toma un numero entero
 * return Devuelve la multiplicacion de los numeros
 */
int utn_multiplicacion(int *pResultado,int x, int y);

/*
 * breaf Realiza la division de dos enteros
 * param x Toma un numero flotante
 *param y Toma un numero flotante
 * return Devuelve la division de los numeros
 */
int utn_division(float *pResultado ,int dividendo, int divisor);
/*
 * breaf Pide numeros para la calculadora
 * param x Toma un numero flotante
 *param y Toma un numero flotante
 * return Devuelve la division de los numeros
 */
int utn_getNumeroCalculadora(int* intNumber, char* mensaje);

/*
 * breaf Realiza la division de dos enteros
 * param pResultado devuelve el resultado de la operacion
 *param operador numero ingresado
 * return 0 ok -1 error en la lectura de la variable -2 ingreso un numero negativo
 */
int utn_factorial(int*pResultado,int operador);
/*
 * breaf Pide cargar un array segun el usuario decida
 * param pResultado devuelve el resultado de la operacion
 *param operador numero ingresado
 * return i la cantidad de numeros que ingreso en el array
 */
int getArrayInt(int *pArray, int limite, char *pMensaje,char *pMensajeError, int minimo, int maximo, int reintentos);
/*
 * breaf Imprime un array de enteros
 * param pResultado devuelve el resultado de la operacion
 *param operador numero ingresado
 * return i la cantidad de numeros que ingreso en el array
 */
int printArrayInt(int* arrayInt, int limite);
/*
 * breaf Inicializa un array de enteros
 * param pResultado devuelve el resultado de la operacion
 *param operador numero ingresado
 * return i la cantidad de numeros que ingreso en el array
 */
int initArrayInt(int* pArray, int limite, int valor);
/*
 * breaf Inicializa un array de flotantes
 * param pResultado devuelve el resultado de la operacion
 *param operador numero ingresado
 * return i la cantidad de numeros que ingreso en el array
 */
int initArrayFloat(float* pArray, int limite, int valor);

/*
 * breaf Imprime un array de flotantes
 * param pResultado devuelve el resultado de la operacion
 *param operador numero ingresado
 * return i la cantidad de numeros que ingreso en el array
 */
int printArrayFloat(float* arrayFloat, int limite);

/*
 * breaf Pide cargar un array de flotantes segun el usuario decida
 * param pResultado devuelve el resultado de la operacion
 *param operador numero ingresado
 * return i la cantidad de numeros que ingreso en el array
 */
int getArrayFloat(float *pArray, int limite, char *pMensaje,char *pMensajeError, int minimo, int maximo, int reintentos);
/*
 * breaf pide una respuesta y o n por consolta
 * param pResultado devuelve el resultado de la operacion
 *param operador numero ingresado
 * return i la cantidad de numeros que ingreso en el array
 */
int utn_getAnswer(char* pChar, char message[4069], char errorMessage[4069], int retries);
/*
 * breaf Pide cargar un array de caracteres
 * param pResultado devuelve el resultado de la operacion
 *param operador numero ingresado
 * return i la cantidad de numeros que ingreso en el array
 */

int utn_getAChar(char aChar[], char message[4069], char errorMessage[4069], int retries, int aQty);

#endif /* UTN_FUNCIONES_H_ */
