PROGRAM ejemplo_allocate_deallocate
    IMPLICIT NONE

    ! Declaración de una matriz de tamaño dinámico
    REAL, ALLOCATABLE :: matriz(:,:)
    INTEGER :: filas, columnas

    ! Definir el tamaño de la matriz
    filas = 3
    columnas = 3

    ! Asignar memoria para la matriz
    ALLOCATE(matriz(filas, columnas))

    ! Llenar la matriz con valores
    matriz = RESHAPE([1.0, 2.0, 3.0, &
                      4.0, 5.0, 6.0, &
                      7.0, 8.0, 9.0], SHAPE(matriz))

    ! Imprimir la matriz
    PRINT *, "Matriz asignada:"
    PRINT *, matriz

    ! Liberar la memoria asignada a la matriz
    DEALLOCATE(matriz)

    ! Verificar que la memoria ha sido liberada
    IF (.NOT. ALLOCATED(matriz)) THEN
        PRINT *, "Memoria liberada con éxito."
    ELSE
        PRINT *, "Error al liberar la memoria."
    END IF

    PRINT *, matriz

END PROGRAM ejemplo_allocate_deallocate