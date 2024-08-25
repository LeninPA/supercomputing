MODULE aritmetica
        IMPLICIT NONE
        REAL, PARAMETER :: tau = 6.28
        contains
        REAL FUNCTION suma(a, b)
            IMPLICIT NONE
            REAL, INTENT(IN) :: a,b
            suma = a + b
        END FUNCTION suma
        REAL FUNCTION resta(a, b)
            IMPLICIT NONE
            REAL, INTENT(IN) :: a,b
            resta = a - b
        END FUNCTION resta
        REAL FUNCTION multiplicacion(a, b)
            IMPLICIT NONE
            REAL, INTENT(IN) :: a,b
            multiplicacion = a * b
        END FUNCTION multiplicacion
        REAL FUNCTION division(a, b)
            IMPLICIT NONE
            REAL, INTENT(IN) :: a,b
            if ( b == 0.0 ) then
                division = a
            else
                division = a / b
            endif
        END FUNCTION division
END MODULE aritmetica
PROGRAM funciones
        USE aritmetica
        IMPLICIT NONE
        REAL :: a = 0,b = 0 
        PRINT *,"Ingresa un real a:"
        READ(*,'(F5.2)') a 
        PRINT *,"Ingresa un real b:"
        READ(*,'(F5.2)') b 
        PRINT *,"Escribiste"
        PRINT *,"a:", a
        PRINT *,"b:", b
        PRINT *,"---------------------------"
        PRINT *,"a + b :", suma(a,b)
        PRINT *,"a - b :", resta(a,b)
        PRINT *,"a * b :", multiplicacion(a,b)
        PRINT *,"a / b :", division(a,b)
        PRINT *,"---------------------------"
END PROGRAM funciones
