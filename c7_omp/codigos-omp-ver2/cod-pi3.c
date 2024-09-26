#include <stdio.h> 
#include <omp.h>


#define NTHREADS  4

static long num_pasos = 100;
double paso;

int main()
{
int i,cardinalidad_hilos;
double pi, tiempo_inicial, tiempo_pared;
double sum=0.0,x;

paso = 1 / (double) num_pasos;

omp_set_num_threads(NTHREADS);

tiempo_inicial=omp_get_wtime();

#pragma omp parallel
{
	int identificador_hilo= omp_get_thread_num();
	int num_hilos=omp_get_num_threads();
	double x;

	if (identificador_hilo==0)   cardinalidad_hilos=num_hilos;



	#pragma omp for reduction(+:sum) schedule(static,10)
	for (i=0; i< num_pasos; i ++)
	{
        x=(i+0.5)*paso;
        printf("i es %d en %d hilo: x es %f \n",i,identificador_hilo,x);
        sum += 4.0/ (1.0+x*x);
	}
} //final de regiion paralela
pi=paso*sum;
tiempo_pared=omp_get_wtime()- tiempo_inicial;
printf("pi es %f in %f seconds %d hilos \n",pi,tiempo_pared,cardinalidad_hilos);
}
