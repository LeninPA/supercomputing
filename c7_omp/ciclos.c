#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <omp.h>
void showVector(float *vector, int size)
{
	printf("[\n");
	for ( int i = 0 ; i < size ; i++ ) {
		printf("%f ", vector[i]);
	}
	printf("]\n");
}
void initVector(float *vector, int size)
{
	for ( int i = 0 ; i < size ; i++ ) {
		vector[i] = (float)(rand() % 100 + 1);
	}
}

int main ( ) 
{
	float *arr_a, *arr_b, *arr_c;
	int N = 5;
	arr_a = (float *)malloc(N * sizeof(float));
	arr_b = (float *)malloc(N * sizeof(float));
	arr_c = (float *)malloc(N * sizeof(float));
	initVector(arr_a, N);
	initVector(arr_b, N);
	initVector(arr_c, N);
	printf("-----------------------------------------------------\n");
	printf("Viz of a,b,c\n");
	showVector(arr_a, N);
	showVector(arr_b, N);
	showVector(arr_c, N);
	printf("-----------------------------------------------------\n");
	struct timeval start, end;
	gettimeofday(&start, NULL);
	for ( int i = 0 ; i < N ; i++ ) {
		arr_c[i] = arr_a[i] + arr_b[i];
	}
	gettimeofday(&end, NULL);
	long timeTaken = (end.tv_sec - start.tv_sec) * 1000000 + end.tv_usec - start.tv_usec;
	printf("Viz of a,b,c\n");
	showVector(arr_a, N);
	showVector(arr_b, N);
	showVector(arr_c, N);
	printf("El tiempo que tomó el secuencial es: %ld\n",timeTaken);
	initVector(arr_c, N);
	printf("Iniciando el paralelo\n");
	printf("Viz of a,b,c\n");
	showVector(arr_a, N);
	showVector(arr_b, N);
	showVector(arr_c, N);
	//omp_set_num_threads(6);
	gettimeofday(&start, NULL);
	#pragma omp parallel
	{
		int i,identificador, num_hilos, inicio, final;
		identificador = omp_get_thread_num();
		num_hilos     = omp_get_num_threads();
		inicio = identificador * N / num_hilos;
		final  = ( identificador + 1 ) * N / num_hilos;
		if (identificador == num_hilos - 1) final = N;
		for ( i = inicio ; i < final ; i++ ) 
		{
			arr_c[i] = arr_a[i] + arr_b[i];
		}
	}
	gettimeofday(&end, NULL);
	timeTaken = (end.tv_sec - start.tv_sec) * 1000000 + end.tv_usec - start.tv_usec;
	printf("El tiempo que tomó el paralelo es: %ld\n",timeTaken);
	printf("Viz of a,b,c\n");
	showVector(arr_a, N);
	showVector(arr_b, N);
	showVector(arr_c, N);
	free(arr_a);free(arr_b);free(arr_c);
	return 0;
}
