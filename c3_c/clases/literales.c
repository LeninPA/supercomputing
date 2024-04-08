#include <stdio.h>

#define true 1
#define false 0

int main() {
	// Literales enteras
	printf("Literales enteras\n");
	int a = 56,    b = 68;               // Enteros base 10
	int c = 045,   d = 076,   e = 06210; // Enteros base 8
	int f = 0x23A, g = 0Xb4C, h = 0xFEA; // Enteros base 16
	int i = 0b101, j = 0B111;            // Enteros base 2
	printf("a = %d\n", a);
	printf("b = %d\n", b);
	printf("c = %o = %d\n", c, c);
	printf("d = %o = %d\n", d, d);
	printf("e = %o = %d\n", e, e);
	printf("f = %x = %d\n", f, f);
	printf("g = %x = %d\n", g, g);
	printf("h = %x = %d\n", h, h);
	printf("i = %X = %d\n", i, i);
	printf("j = %X = %d\n", j, j);
	printf("%lu byte(s)\n", sizeof(123456789));
	printf("%lu byte(s)\n", sizeof(12345678901234));

	// Literales de punto flotante
	printf("Literales de punto flotante\n");
	float k = 10.125, l = 1.215e-10L, m = 10.5E-3;
	double n = 10.0e+0;
	printf("k = %f\n", k);
	printf("l = %f\n", l);
	printf("m = %f\n", m);
	printf("n = %f\n", n);

	// Literales de caracter
	printf("Literales de caracter\n");
	char o = 'o', p = 112;
	printf("o = %c = %d\n", o, o);
	printf("p = %c = %d\n", p, p);
}
