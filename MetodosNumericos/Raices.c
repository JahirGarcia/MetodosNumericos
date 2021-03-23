#include "Raices.h"
#include <math.h>

inline float multiplicar_funcion(float (*funcion)(float x), float a, float b) {
    return funcion(a) * funcion(b);
}

inline float punto_medio(float extremo_inferior, float extremo_superior) {
    return (extremo_superior + extremo_inferior) / 2;
}

float iterar_biseccion(float (*funcion)(float x), float extremo_inferior, float extremo_superior, float precicion, float punto_medio_anterior) {
    float punto_medio_actual = punto_medio(extremo_inferior, extremo_superior);

    if (fabsf(punto_medio_actual - punto_medio_anterior) < precicion) return punto_medio_actual;

    if (multiplicar_funcion(funcion, extremo_inferior, punto_medio_actual) < 0) extremo_superior = punto_medio_actual;
    else extremo_inferior = punto_medio_actual;

    return iterar_biseccion(funcion, extremo_inferior, extremo_superior, precicion, punto_medio_actual);
}

float biseccion(float (*funcion)(float x), float extremo_inferior, float extremo_superior, float precicion)
{
    error = 0;

    if (!(multiplicar_funcion(funcion, extremo_inferior, extremo_superior) < 0)) {
        error = 1;
        return INTERVALO_INCORRECTO;
    }

    return iterar_biseccion(funcion, extremo_inferior, extremo_superior, precicion, 0);
}
