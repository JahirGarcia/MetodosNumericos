#include <stdio.h>
#include <math.h>
#include "Raices.h"

float Fx(float x) {
	return powf(x, 3) - x - 1;
}

int main() {
	float resultado = biseccion(Fx, 1, 2, 0.0001);

	if (error)
		printf("Ocurrió un error: %d", (int)resultado);
	else
		printf("Resultado: %f", resultado);

	return 0;
}
