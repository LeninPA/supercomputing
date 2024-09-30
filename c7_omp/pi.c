#include <stdio.h>
#include <omp.h>
#define NTHREADS 6

static long num_pasos = 1000000000;
double paso;

int main(){
    int i, j, cardinalidad_hilos;
    double pi=0, tiempo_inicial, tiempo_pared;
    double sum[NTHREADS]={0.0};
    paso = 1 / (double) num_pasos;
    omp_set_num_threads(NTHREADS);
    tiempo_inicial=omp_get_wtime();
    #pragma omp parallel
    {
       int i,identificador_hilo,num_hilos;
       double x;
       identificador_hilo= omp_get_thread_num();
       num_hilos=omp_get_num_threads();
       if (identificador_hilo==0) cardinalidad_hilos=num_hilos;
       for (i=identificador_hilo; i< num_pasos; i += num_hilos)
       {
            x=(i+0.5)*paso;
            sum[identificador_hilo] += 4.0/ (1.0+x*x);
       }
    } //final de regiion paralela
    for (i =0; i< cardinalidad_hilos; i++)
            pi+=sum[i];
    pi=paso*pi;
    tiempo_pared=omp_get_wtime()- tiempo_inicial;
    printf("pi = %f \n",pi);
    printf("Tiempo = %f s, hilos = %d \n",tiempo_pared,cardinalidad_hilos);
}
