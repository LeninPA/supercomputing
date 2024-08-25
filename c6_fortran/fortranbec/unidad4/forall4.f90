PROGRAM forall4
  IMPLICIT NONE
  INTEGER, DIMENSION(5) :: C = (/ 1, 2, 3, 4, 5 /)
  INTEGER, DIMENSION(5) :: D
  INTEGER i 

  FORALL (i = 2:4)
    D(i) = C(i-1) + C(i) + C(i+1)
  END FORALL

  PRINT *, D
END PROGRAM forall4