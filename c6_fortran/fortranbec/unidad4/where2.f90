PROGRAM where2
  IMPLICIT NONE
  REAL, DIMENSION(5) :: numerador = (/ 10.0, 20.0, 30.0, 40.0, 50.0 /)
  REAL, DIMENSION(5) :: denominador = (/ 2.0, 0.0, 3.0, 0.0, 5.0 /)
  REAL, DIMENSION(5) :: resultado

  WHERE (denominador /= 0.0)
    resultado = numerador / denominador
  ELSEWHERE
    resultado = 0.0
  END WHERE

  PRINT *, resultado
END PROGRAM where2