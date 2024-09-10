#include <stdio.h>
#include <omp.h>


int main ( ) 
{
	int cardinalidad;
	// omp_set_num_threads(6);
	#pragma omp parallel
	{
		int identificador_hilo, nhilos;
		identificador_hilo = omp_get_thread_num();
		nhilos = omp_get_num_threads();
		if ( identificador_hilo == 0 ) cardinalidad = nhilos;
	}
	printf("Join de un equipo de tamaño %d\n", cardinalidad);
	return 0;
}
