#include <stdio.h> 
#include <omp.h>


#define NTHREADS  6

static long num_pasos = 100;
double paso;
int main()
{
int i, j, cardinalidad_hilos;
double pi, tiempo_inicial, tiempo_pared;
double sum[NTHREADS]={0.0};

paso = 1 / (double) num_pasos;

omp_set_num_threads(NTHREADS);

tiempo_inicial=omp_get_wtime();

#pragma omp parallel
{
	int i;
	int identificador_hilo= omp_get_thread_num();
	int num_hilos=omp_get_num_threads();
	double x;

	if (identificador_hilo==0)   cardinalidad_hilos=num_hilos;

	for (i=identificador_hilo; i< num_pasos; i += num_hilos)
	{
        x=(i+0.5)*paso;
        sum[identificador_hilo] += 4.0/ (1.0+x*x);
	 printf("i es %d en %d hilo: x es %f \n",i,identificador_hilo,x);

	}
} //final de regiion paralela
for (i =0; i< cardinalidad_hilos; i++)
	pi+=sum[i];
pi=paso*pi;
tiempo_pared=omp_get_wtime()- tiempo_inicial;
printf("pi es %f in %f seconds %d hilos \n",pi,tiempo_pared,cardinalidad_hilos);
}
