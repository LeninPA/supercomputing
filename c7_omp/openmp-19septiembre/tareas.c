#include <omp.h>
#include <stdio.h>

int main()
{
   
   
    
   #pragma omp parallel 
   {
      int hilo=omp_get_thread_num(); 
      #pragma omp task
      {
	      printf("%d: Estoy comiendo ...   \n", hilo);
      }
      #pragma omp task
      {
	      printf("%d: Estoy haciendo el proyecto de OpenMP ...   \n",hilo);
      }
      #pragma omp task
      {
	      printf("%d: Estoy realizando proyecto de Plan de becarios ...   \n",hilo);
      }
   } 

   return 0;
}
