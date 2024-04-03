#include <stdio.h>

int main(void) {
	float PI, radius, perimeter, area;
	PI = 3.1416;
	radius = 15.5;
	area = PI * radius * radius;
	perimeter = 2 * PI * radius;
	printf("Radio: %f\nÁrea: %f\nPerímetro: %f\n", radius, area, perimeter);
	return 0;
}
