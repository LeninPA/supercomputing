#include <stdio.h>
#include <omp.h>


void sombrero ( int ID, double *A )
{
	A[ID] = ID;
}

int main ( ) 
{
	double A[10] = {0};
	//omp_set_num_threads(6);
	#pragma omp parallel
	{
		int ID = omp_get_thread_num();
		sombrero(ID, A);
		printf("A de ID(%d) = %lf\n", ID, A[ID]);
	}
	return 0;
}
