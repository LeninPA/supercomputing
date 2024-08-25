program ciclo_do
  implicit none

  ! Declaración de variables
  integer :: suma,i

  ! Inicialización de la variable suma
  suma = 0

  ! Ciclo DO para sumar los números del 1 al 10
  do i = 1, 10
     suma = suma + i
     print *, 'Número actual: ', i
     print *, 'Suma parcial: ', suma
  end do

  ! Impresión del resultado final
  print *, 'La suma de los números del 1 al 10 es: ', suma

end program ciclo_do