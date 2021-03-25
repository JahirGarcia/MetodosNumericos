#pragma once
/*
 * @file Raices.h
 * @author Dylan Luna
 * @date 22/3/2021
 * @brief Funciones para aproximar raices de funciones no lineales.
 */

/*
 * @brief Indica si ocurrio o no un error al ejecutar alguna función de aproximación de raices.
 * Tomará el valor de 1 en caso de error o 0 en caso contrario.
 * No se debería modificar manualmente el valor de esta variable.
 */
int error;

/*
 * @brief Posibles errores al ejecutar alguna función de aproximación de raices.
 */
enum errores {
	INTERVALO_INCORRECTO, /// La función no es continua en el intervalo dado
};

/*
 * @brief Encuentra el valor próximo a la raíz de la función dada utilizando el método de biseccicón.
 *
 * @param funcion Puntero a la función de la cual se desea aproximar su raíz.
 * @param extremo_inferior Extremo inferior del intervalo que contiene la raíz.
 * @param extremo_superior Extremo superior del intervalo que contiene la raíz.
 * @param precicion Precición del valor próximo a la raíz.
 *
 * @return Valor próximo a la raíz de la función dada.
 */
float biseccion(float (*funcion)(float x), float extremo_inferior, float extremo_superior, float precicion);

/*
 * @brief Encuentra el valor próximo a la raíz de la función dada utilizando el método de la regla falsa.
 *
 * @param funcion Puntero a la función de la cual se desea aproximar su raíz.
 * @param extremo_inferior Extremo inferior del intervalo que contiene la raíz.
 * @param extremo_superior Extremo superior del intervalo que contiene la raíz.
 * @param precicion Precición del valor próximo a la raíz.
 *
 * @return Valor próximo a la raíz de la función dada.
 */
float regla_falsa(float (*funcion)(float x), float extremo_inferior, float extremo_superior, float precicion);

/*
 * @brief Encuentra el valor próximo a la raíz de la función dada utilizando el método de la secante.
 *
 * @param funcion Puntero a la función de la cual se desea aproximar su raíz.
 * @param punto_inicial_x0 Punto inicial x sub 0.
 * @param punto_inicial_x1 Punto inicial x sub 1.
 * @param precicion Precición del valor próximo a la raíz.
 *
 * @return Valor próximo a la raíz de la función dada.
 */
float secante(float (*funcion)(float x), float punto_inicial_x0, float punto_inicial_x1, float precicion);
