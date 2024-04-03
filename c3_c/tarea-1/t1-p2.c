#include <stdio.h>

int main(void) {
	int ladoA, ladoB;
	ladoA = 8;
	ladoB = 7;
	printf("El área del rectángulo es: %d cm2\n", ladoA * ladoB);
	printf("El perímetro del rectángulo es: %d cm\n", 2 * (ladoA + ladoB));
	return 0;
}
