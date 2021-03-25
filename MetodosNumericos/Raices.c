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

float biseccion(float (*funcion)(float x), float extremo_inferior, float extremo_superior, float precicion) {
    error = 0;

    if (!(multiplicar_funcion(funcion, extremo_inferior, extremo_superior) < 0)) {
        error = 1;
        return INTERVALO_INCORRECTO;
    }

    float punto_medio_anterior = 0;
    float punto_medio_actual = punto_medio(extremo_inferior, extremo_superior);

    while (fabsf(punto_medio_actual - punto_medio_anterior) > precicion) {
        if (multiplicar_funcion(funcion, extremo_inferior, punto_medio_actual) < 0) extremo_superior = punto_medio_actual;
        else extremo_inferior = punto_medio_actual;

        punto_medio_anterior = punto_medio_actual;
        punto_medio_actual = punto_medio(extremo_inferior, extremo_superior);
    }

    return punto_medio_actual;
}

float regla_falsa(float (*funcion)(float x), float extremo_inferior, float extremo_superior, float precicion) {
    error = 0;

    if (!(multiplicar_funcion(funcion, extremo_inferior, extremo_superior) < 0)) {
        error = 1;
        return INTERVALO_INCORRECTO;
    }

    float punto_interseccion_anterior = 0;
    float punto_interseccion_actual = punto_interseccion(funcion, extremo_inferior, extremo_superior);

    while (fabsf(punto_interseccion_actual - punto_interseccion_anterior) > precicion) {
        if (multiplicar_funcion(funcion, extremo_inferior, punto_interseccion_actual) < 0) extremo_superior = punto_interseccion_actual;
        else extremo_inferior = punto_interseccion_actual;

        punto_interseccion_anterior = punto_interseccion_actual;
        punto_interseccion_actual = punto_interseccion(funcion, extremo_inferior, extremo_superior);
    }

    return punto_interseccion_actual;
}

float secante(float (*funcion)(float x), float punto_inicial_x0, float punto_inicial_x1, float precicion) {
    float punto_interseccion_x2 = punto_interseccion(funcion, punto_inicial_x0, punto_inicial_x1);

    while (fabsf(punto_interseccion_x2 - punto_inicial_x1) > precicion) {
        punto_inicial_x0 = punto_inicial_x1;
        punto_inicial_x1 = punto_interseccion_x2;
        punto_interseccion_x2 = punto_interseccion(funcion, punto_inicial_x0, punto_inicial_x1);
    }

    return punto_interseccion_x2;
}
