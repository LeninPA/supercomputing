#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	char* s = malloc(9);
	strcpy(s, "Sistemas");
	printf("%s\n", s);
	return 0;
}
