#pragma once

int error;

enum errores {
	INTERVALO_INCORRECTO
};

float biseccion(float (*funcion)(float x), float extremo_inferior, float extremo_superior, float precicion);

float regla_falsa(float (*funcion)(float x), float extremo_inferior, float extremo_superior, float precicion);

float secante(float (*funcion)(float x), float punto_inicial_x0, float punto_inicial_x1, float precicion);
