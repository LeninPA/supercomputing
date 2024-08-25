PROGRAM ejemplo_reshape_2
  REAL, DIMENSION(4) :: array1d = (/ 1.0, 2.0, 3.0, 4.0 /)
  REAL, DIMENSION(3, 3) :: matriz

  ! Reshape del array unidimensional a una matriz 3x3, con relleno
  matriz = RESHAPE(array1d, SHAPE(matriz), PAD=(/ 0.0 /))

  ! Imprimir la matriz resultante
  PRINT *, "Matriz 3x3 con relleno:"
  PRINT *, matriz
END PROGRAM ejemplo_reshape_2