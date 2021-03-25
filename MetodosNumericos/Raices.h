#pragma once
/*
 * @file Raices.h
 * @author Dylan Luna
 * @date 22/3/2021
 * @brief Funciones para aproximar raices de funciones no lineales.
 */

/*
 * @brief Indica si ocurrio o no un error al ejecutar alguna funci�n de aproximaci�n de raices.
 * Tomar� el valor de 1 en caso de error o 0 en caso contrario.
 * No se deber�a modificar manualmente el valor de esta variable.
 */
int error;

/*
 * @brief Posibles errores al ejecutar alguna funci�n de aproximaci�n de raices.
 */
enum errores {
	INTERVALO_INCORRECTO, /// La funci�n no es continua en el intervalo dado
};

/*
 * @brief Encuentra el valor pr�ximo a la ra�z de la funci�n dada utilizando el m�todo de biseccic�n.
 *
 * @param funcion Puntero a la funci�n de la cual se desea aproximar su ra�z.
 * @param extremo_inferior Extremo inferior del intervalo que contiene la ra�z.
 * @param extremo_superior Extremo superior del intervalo que contiene la ra�z.
 * @param precicion Precici�n del valor pr�ximo a la ra�z.
 *
 * @return Valor pr�ximo a la ra�z de la funci�n dada.
 */
float biseccion(float (*funcion)(float x), float extremo_inferior, float extremo_superior, float precicion);

/*
 * @brief Encuentra el valor pr�ximo a la ra�z de la funci�n dada utilizando el m�todo de la regla falsa.
 *
 * @param funcion Puntero a la funci�n de la cual se desea aproximar su ra�z.
 * @param extremo_inferior Extremo inferior del intervalo que contiene la ra�z.
 * @param extremo_superior Extremo superior del intervalo que contiene la ra�z.
 * @param precicion Precici�n del valor pr�ximo a la ra�z.
 *
 * @return Valor pr�ximo a la ra�z de la funci�n dada.
 */
float regla_falsa(float (*funcion)(float x), float extremo_inferior, float extremo_superior, float precicion);

/*
 * @brief Encuentra el valor pr�ximo a la ra�z de la funci�n dada utilizando el m�todo de la secante.
 *
 * @param funcion Puntero a la funci�n de la cual se desea aproximar su ra�z.
 * @param punto_inicial_x0 Punto inicial x sub 0.
 * @param punto_inicial_x1 Punto inicial x sub 1.
 * @param precicion Precici�n del valor pr�ximo a la ra�z.
 *
 * @return Valor pr�ximo a la ra�z de la funci�n dada.
 */
float secante(float (*funcion)(float x), float punto_inicial_x0, float punto_inicial_x1, float precicion);
