program anidados
  implicit none

  ! Declaración de variables
  integer :: i, j

  ! Imprimir encabezado
  print *, 'Tabla de multiplicar del 1 al 5:'
  
  ! Bucle para las filas
  do i = 1, 10
     ! Bucle para las columnas
     do j = 1, 10
        ! Imprimir el producto de i y j
        print *, i, 'x', j, '=', i * j
     end do
     ! Salto de línea después de cada fila para mejor formato
     print *
  end do

end program anidados