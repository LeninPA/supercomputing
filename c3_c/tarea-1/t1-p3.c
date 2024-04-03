#include <stdio.h>

int main(void) {
	int years,weeks,days,initial_value;
	initial_value = 1329;
	printf("Número de días %d\n", initial_value);
	years = initial_value / 365;
	initial_value -= 365 * years;
	weeks = initial_value / 7;
	days = initial_value - 7 * weeks;
	printf("Años: %d\nSemanas: %d\nDías: %d\n", years, weeks, days);
	return 0;
}
