program operaciones_logicas
  implicit none

  ! Declaración de variables
  logical :: x, y, resultado_and, resultado_or, resultado_not

  ! Asignación de valores a las variables
  x = .true.
  y = .false.

  ! Realización de operaciones lógicas
  resultado_and = x .and. y
  resultado_or = x .or. y
  resultado_not = .not. x

  ! Impresión de resultados
  print *, 'Resultado AND: ', resultado_and
  print *, 'Resultado OR: ', resultado_or
  print *, 'Resultado NOT: ', resultado_not

end program operaciones_logicas