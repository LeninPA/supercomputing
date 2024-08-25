PROGRAM ejemplo_doble_precision
    IMPLICIT NONE

    REAL(KIND=8) :: x
    DOUBLE PRECISION :: y
    REAL :: z

    ! Inicialización de variables
    x = 3.14159265358979323846_8
    z=3.14159265358979323846_8
    y = 2.71828182845904523536D0

    ! Imprimir valores
    PRINT *, "Valor de x en doble precisión:", x
    PRINT *, "Valor de y en doble precisión:", y
    PRINT *, "Valor de z en precisión simple:", z

END PROGRAM ejemplo_doble_precision