PROGRAM PedirMatriz
    IMPLICIT NONE
    INTEGER :: i, j, filas, columnas
    REAL :: matriz(10, 10)  ! Ajusta el tamaño según necesites
  
    ! Pedir el número de filas y columnas
    PRINT *, 'Introduce el número de filas:'
    READ *, filas
    PRINT *, 'Introduce el número de columnas:'
    READ *, columnas
    PRINT*

    PRINT *, 'La matriz es de (',filas,'X',columnas,')'
    ! Pedir los elementos de la matriz
    DO i = 1, filas
      DO j = 1, columnas
        PRINT *, 'Introduce el elemento (', i, ',', j, '):'
        READ *, matriz(i, j)
      END DO
    END DO
  
    ! Imprimir la matriz para verificar
   
    DO i = 1, filas
      DO j = 1, columnas
        PRINT *, matriz(i, j)
      END DO
      PRINT *  ! Salto de línea
    END DO

    PRINT *, "LA MATRIZ ES:"
    DO I=1,filas
      PRINT *, MATRIZ(I,:)
    END DO
  END PROGRAM PedirMatriz