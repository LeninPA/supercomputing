// sample compile command: "gcc -fopenmp -c Fig_6.3_sharedEx.c" to generate *.o object file

#include <omp.h>
#include <stdio.h>


int main ()  
{
   int A=4, B=8, C=42;
  
   
   //remember the value of A before the parallel region
   printf("A before = %d\n", A);
  
   #pragma omp parallel shared(B,C)
   { 
      int A = omp_get_thread_num();
      printf("A en region paralela = %d\n", A);
         #pragma omp critical
         C = B + A;
   }
  
   // A in the parallel region goes out of scope, we revert
   // to the original variable for A
   printf("A al final = %d and C = %d\n", A, C);
}
