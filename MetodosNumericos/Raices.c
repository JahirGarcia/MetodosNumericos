#include "Raices.h"
#include <math.h>
#include <stdio.h>

inline float multiplicar_funcion(float (*funcion)(float x), float a, float b) {
    return funcion(a) * funcion(b);
}

inline float punto_medio(float extremo_inferior, float extremo_superior) {
    return (extremo_superior + extremo_inferior) / 2;
}

inline float punto_interseccion(float (*funcion)(float x), float extremo_inferior, float extremo_superior) {
    return ((funcion(extremo_superior) * extremo_inferior) - (funcion(extremo_inferior) * extremo_superior)) / (funcion(extremo_superior) - funcion(extremo_inferior));
}

float iterar_biseccion(float (*funcion)(float x), float extremo_inferior, float extremo_superior, float precicion, float punto_medio_anterior) {
    float punto_medio_actual = punto_medio(extremo_inferior, extremo_superior);

    if (fabsf(punto_medio_actual - punto_medio_anterior) < precicion) return punto_medio_actual;

    if (multiplicar_funcion(funcion, extremo_inferior, punto_medio_actual) < 0) extremo_superior = punto_medio_actual;
    else extremo_inferior = punto_medio_actual;

    return iterar_biseccion(funcion, extremo_inferior, extremo_superior, precicion, punto_medio_actual);
}

float iterar_regla_falsa(float (*funcion)(float x), float extremo_inferior, float extremo_superior, float precicion, float punto_intersecion_anterior) {
    float punto_intersecion_actual = punto_interseccion(funcion, extremo_inferior, extremo_superior);

    if (fabsf(punto_intersecion_actual - punto_intersecion_anterior) < precicion) return punto_intersecion_actual;

    if (multiplicar_funcion(funcion, extremo_inferior, punto_intersecion_actual) < 0) extremo_superior = punto_intersecion_actual;
    else extremo_inferior = punto_intersecion_actual;

    return iterar_regla_falsa(funcion, extremo_inferior, extremo_superior, precicion, punto_intersecion_actual);
}

float biseccion(float (*funcion)(float x), float extremo_inferior, float extremo_superior, float precicion) {
    error = 0;

    if (!(multiplicar_funcion(funcion, extremo_inferior, extremo_superior) < 0)) {
        error = 1;
        return INTERVALO_INCORRECTO;
    }

    return iterar_biseccion(funcion, extremo_inferior, extremo_superior, precicion, 0);
}

float regla_falsa(float (*funcion)(float x), float extremo_inferior, float extremo_superior, float precicion) {
    error = 0;

    if (!(multiplicar_funcion(funcion, extremo_inferior, extremo_superior) < 0)) {
        error = 1;
        return INTERVALO_INCORRECTO;
    }

    return iterar_regla_falsa(funcion, extremo_inferior, extremo_superior, precicion, 0);
}

float secante(float (*funcion)(float x), float punto_inicial_x0, float punto_inicial_x1, float precicion) {
    float punto_interseccion_x2 = punto_interseccion(funcion, punto_inicial_x0, punto_inicial_x1);

    if (fabsf(punto_interseccion_x2 - punto_inicial_x1) < precicion) return punto_interseccion_x2;

    return secante(funcion, punto_inicial_x1, punto_interseccion_x2, precicion);
}
