PROGRAM imprime_matriz3
  REAL, DIMENSION (0:2,-2:3) :: matriz3
  INTEGER :: i, j

  ! Inicializar la matriz para ejemplo (opcional)
  DO i = 0, 2
     DO j = -2, 3
        matriz3(i,j) = i + j
     END DO
  END DO

  ! Imprimir la matriz
  PRINT *, "Valores de matriz3:"
  DO i = 0, 2
     DO j = -2, 3
        PRINT *, "matriz3(", i, ",", j, ") = ", matriz3(i,j)
     END DO
  END DO
END PROGRAM imprime_matriz3