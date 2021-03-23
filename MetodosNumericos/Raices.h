#pragma once

int error;

enum errores {
	INTERVALO_INCORRECTO
};

float biseccion(float (*funcion)(float x), float extremo_inferior, float extremo_superior, float precicion);

