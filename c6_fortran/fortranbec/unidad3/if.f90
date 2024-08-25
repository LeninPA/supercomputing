program ejemplo_if
  implicit none

  ! Declaración de variables
  integer :: numero

  ! Solicitar al usuario un número
  print *, 'Introduce un número entero:'
  read *, numero

  ! Estructura IF simple
  if (numero > 0) then
     print *, 'El número es positivo.'
  else if (numero < 0) then
     print *, 'El número es negativo.'
  else
     print *, 'El número es cero.'
  end if

end program ejemplo_if