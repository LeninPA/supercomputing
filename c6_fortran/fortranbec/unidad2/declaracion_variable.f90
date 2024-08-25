program declaracion_variables
  implicit none

  ! Declaración de variables
  integer :: numero, cantidad
  real :: decimal
  character(len=20) :: texto

  ! Asignación de valores a las variables
  numero = 10
  cantidad=0
  decimal = 3.14
  texto = "Hola, Fortran!"

  ! Impresión de las variables
  print *, "Numero entero: ", numero
  print *, "Cantidad: ", cantidad
  print *, "Numero decimal: ", decimal
  print *, "Texto: ", texto

end program declaracion_variables