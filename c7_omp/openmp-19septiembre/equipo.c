#include <omp.h>
#include <stdio.h>
#include <unistd.h>

int main()
{
    
   #pragma omp parallel 
   {
      int hilo=omp_get_thread_num(); 
      int total=omp_get_num_threads(); 
      printf("%d: Nùmero de hilos %d  \n",hilo, total);
      #pragma omp single
      {
      	#pragma omp task
      	{
	      sleep(3);
	      printf("%d: Realizando reporte de la parte teórica ...   \n", hilo);
      	}
      	#pragma omp task
      	{
	      sleep(1);
	      printf("%d: Reporte de la parte practica ...   \n",hilo);
      	}
      	#pragma omp task
      	{
	      sleep(7);
	      printf("%d: Voy por la comida ...   \n",hilo);
      	}
      }
   } 

   return 0;
}
