#include <omp.h>
#include <stdio.h>


int main ()  
{
   int saldo=1000;
  
   
   printf("Su saldo antes de la region paralela = %d\n", saldo);
  
   #pragma omp parallel 
   { 
      //int deposito = ( omp_get_thread_num() + 1 ) * 10;
      int deposito = 1; 
      int hilo = omp_get_thread_num();

      printf("Deposito %d del hilo %d \n", deposito, hilo);
        
         #pragma omp critical 
         saldo +=  deposito;
   }
  
   printf("Su saldo despues de la region paralela = %d \n", saldo);
}
