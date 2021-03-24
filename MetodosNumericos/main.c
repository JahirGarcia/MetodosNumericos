#include <stdio.h>
#include <math.h>
#include "Raices.h"

float Fx(float x) {
	//return powf(x, 3) - (2 * powf(x, 2)) - 5;
	return (x * log10f(x)) - 10;
}

int main() {
	/*float res_biseccion = biseccion(Fx, 1, 3, 0.05);
	float res_regla_falsa = regla_falsa(Fx, 1, 3, 0.05);

	printf("Resultado biseccion: %.9f\n", res_biseccion);
	printf("Resultado regla falsa: %.9f\n", res_regla_falsa);*/

	float res = secante(Fx, 8, 9, 0.001);
	printf("Resultado: %f", res);

	return 0;
}
