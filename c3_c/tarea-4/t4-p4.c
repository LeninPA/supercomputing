#include <stdio.h>

void ver_arr ( int arr[] , unsigned int n ) {
	if ( n != 0 ){
		ver_arr(arr, n-1);
	}
	printf("%d ", arr[n]);
}

int main() {
	int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	ver_arr(a, 9);
	printf("\n");
	return 0;
}
