// sample compile command: "gcc -fopenmp -c Fig_6.4_wrongPrivate.c" to generate *.o object file

#include <stdio.h>
#include <omp.h>
void main() 
{ 
   int tmp = 0;
   #pragma omp parallel for private(tmp) 
      for (int j = 0; j < 1000; j++)
{ 
         tmp += j;   
         printf("hilo %d: %d\n", omp_get_thread_num(), tmp );  
}
      printf("%d\n", tmp);  
}
