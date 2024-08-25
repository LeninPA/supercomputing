PROGRAM suma_matrices
    IMPLICIT NONE

    ! Declaración de variables
    INTEGER, PARAMETER :: n = 2, m = 3
    INTEGER :: i, j
    INTEGER :: matrizA(n, m)
    INTEGER :: matrizB(n, m)
    INTEGER :: matrizC(n, m)

    ! Inicialización de las matrices A y B
    matrizA = RESHAPE((/1, 2, 3, 4, 5, 6/), (/n, m/))
    matrizB = RESHAPE((/6, 5, 4, 3, 2, 1/), (/n, m/))

    ! Suma de las matrices A y B, almacenando el resultado en la matriz C
    DO i = 1, n
        DO j = 1, m
            matrizC(i, j) = matrizA(i, j) + matrizB(i, j)
        END DO
    END DO

       PRINT *, matrizA(2,3)

    ! Imprimir la matriz resultante
    PRINT *, "Matriz A:"
    DO i = 1, n
        PRINT *, matrizA(i, :)
    END DO

    PRINT *, "Matriz B:"
    DO i = 1, n
        PRINT *, matrizB(i, :)
    END DO

    PRINT *, "Matriz C (suma de A y B):"
    DO i = 1, n
        PRINT *, matrizC(i, :)
    END DO

END PROGRAM suma_matrices