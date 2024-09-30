program calcular_pi
  use omp_lib
  implicit none

  integer, parameter :: NTHREADS = 6
  integer(8) :: num_pasos = 1000000000
  real(8) :: paso, pi, tiempo_inicial, tiempo_pared
  real(8), dimension(NTHREADS) :: sum
  integer :: i, identificador_hilo, num_hilos, cardinalidad_hilos
  real(8) :: x
  
  ! Inicializar variables
  paso = 1.0d0 / num_pasos
  pi = 0.0d0
  sum = 0.0d0
  
  ! Establecer el número de hilos
  call omp_set_num_threads(NTHREADS)

  ! Obtener el tiempo inicial
  tiempo_inicial = omp_get_wtime()

  !$omp parallel private(identificador_hilo, num_hilos, i, x)
  identificador_hilo = omp_get_thread_num()  ! Obtener el identificador del hilo
  num_hilos = omp_get_num_threads()  ! Obtener el número total de hilos
  if (identificador_hilo == 0) cardinalidad_hilos = num_hilos  ! Guardar la cantidad de hilos

  ! Cálculo de la suma de cada hilo
  do i = identificador_hilo, num_pasos - 1, num_hilos
    x = (i + 0.5d0) * paso
    sum(identificador_hilo + 1) = sum(identificador_hilo + 1) + 4.0d0 / (1.0d0 + x * x)
  end do
  !$omp end parallel  ! Final de la región paralela

  ! Sumar los resultados de cada hilo
  do i = 1, cardinalidad_hilos
    pi = pi + sum(i)
  end do

  ! Calcular el valor final de pi
  pi = paso * pi

  ! Calcular el tiempo total
  tiempo_pared = omp_get_wtime() - tiempo_inicial

  ! Imprimir los resultados
  print *, "pi = ", pi
  print *, "Tiempo = ", tiempo_pared, " s, hilos = ", cardinalidad_hilos

end program calcular_pi
