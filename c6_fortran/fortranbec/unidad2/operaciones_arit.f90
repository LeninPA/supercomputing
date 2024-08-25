program operaciones_aritmeticas
  implicit none

  ! Declaración de variables
  integer :: a, b, suma, resta, producto, modulo
  real :: division

  ! Asignación de valores a las variables
  a = 10
  b = 3

  ! Realización de operaciones
  suma = a + b
  resta = a - b
  producto = a * b
  modulo = mod(a, b)  ! Operación módulo
  division = a / real(b)  ! Conversión a tipo real para la división exacta

  ! Impresión de resultados
  print *, 'Suma: ', suma
  print *, 'Resta: ', resta
  print *, 'Producto: ', producto
  print *, 'Módulo: ', modulo
  print *, 'División: ', division

end program operaciones_aritmeticas