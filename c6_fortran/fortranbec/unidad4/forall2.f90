PROGRAM forall2
  IMPLICIT NONE
  INTEGER, DIMENSION(5) :: X = (/ 1, 2, 3, 4, 5 /)
  INTEGER, DIMENSION(5) :: Y = (/ 10, 20, 30, 40, 50 /)
  INTEGER i

  FORALL (i = 1:5, X(i) > 3)
    Y(i) = Y(i) + 100
  END FORALL

  PRINT *, Y
END PROGRAM forall2