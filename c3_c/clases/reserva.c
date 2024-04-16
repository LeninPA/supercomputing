#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	int *ip = calloc(1,4);
	printf("Ingresa un número: ");
	scanf("%d", ip);
	printf(" ip = %p\n", ip);
	printf("*ip = %d\n",*ip);
	return 0;
}
