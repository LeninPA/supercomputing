PROGRAM ejemplo_reshape_1
  REAL, DIMENSION(6) :: array1d = (/ 1.0, 2.0, 3.0, 4.0, 5.0, 6.0 /)
  REAL, DIMENSION(2, 3) :: matriz

  ! Reshape del array unidimensional a una matriz 2x3
  matriz = RESHAPE(array1d, SHAPE(matriz))

  ! Imprimir la matriz resultante
  PRINT *, "Matriz 2x3:"
  PRINT *, matriz
  !Imprimir matriz en forma matemática
  
  PRINT *, "Matriz en forma matematica"

    ! Imprimir la matriz
  PRINT *, "Matriz A:"
  DO i = 1, 2
      PRINT *, matriz(i, :)
  END DO

END PROGRAM ejemplo_reshape_1