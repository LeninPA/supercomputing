MODULE aritmetica
        IMPLICIT NONE
        REAL, PARAMETER :: tau = 6.28, pi = 3.14159265359,&
        phi = 1.168033, euler = 2.71828, square = 1.41421
        contains
        REAL FUNCTION suma(b)
            IMPLICIT NONE
            REAL, INTENT(IN) :: b
            suma = tau + b
        END FUNCTION suma
        REAL FUNCTION resta(b)
            IMPLICIT NONE
            REAL, INTENT(IN) :: b
            resta = tau - b
        END FUNCTION resta
        REAL FUNCTION multiplicacion(b)
            IMPLICIT NONE
            REAL, INTENT(IN) :: b
            multiplicacion = tau * b
        END FUNCTION multiplicacion
        REAL FUNCTION division(b)
            IMPLICIT NONE
            REAL, INTENT(IN) :: b
            if ( b == 0.0 ) then
                division = tau 
            else
                division = tau / b
            endif
        END FUNCTION division
END MODULE aritmetica
PROGRAM funciones
        USE aritmetica
        IMPLICIT NONE
        REAL :: b = 0!,a=0 
        !PRINT *,"Ingresa un real a:"
        !READ(*,'(F5.2)') a 
        PRINT *,"Ingresa un real b:"
        READ(*,'(F5.2)') b 
        PRINT *,"Escribiste"
        !PRINT *,"a:", a
        PRINT *,"b:", b
        PRINT *,"---------------------------"
        PRINT *,"tau + b :", suma(b)
        PRINT *,"tau - b :", resta(b)
        PRINT *,"tau * b :", multiplicacion(b)
        PRINT *,"tau / b :", division(b)
        PRINT *,"---------------------------"
END PROGRAM funciones
