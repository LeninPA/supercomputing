#include <stdio.h>
#include <omp.h>

static long numero_pasos=1000000;
double paso;

int main()
{
int i;
double x,pi,sum=0.0, tiempo_inicial, tiempo_pared;

paso=1/(double) numero_pasos;
tiempo_inicial=omp_get_wtime();
for (i=0; i< numero_pasos; i++)
{
	x = (i+0.5)*paso;
        sum+=4/(1+x*x);
}
pi=paso*sum;
tiempo_pared=omp_get_wtime()-tiempo_inicial;
printf("pi = %lf, %ld pasos , %lf secs \n ", pi,numero_pasos,tiempo_pared);
}
