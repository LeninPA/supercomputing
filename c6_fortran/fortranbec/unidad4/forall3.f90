PROGRAM forall3
  IMPLICIT NONE
  INTEGER, DIMENSION(3, 3) :: A = RESHAPE((/1, 2, 3, 4, 5, 6, 7, 8, 9/), (/3, 3/))
  INTEGER, DIMENSION(3, 3) :: B
  INTEGER i,j

  FORALL (i = 1:3, j = 1:3)
    B(i, j) = A(i, j) * 2
  END FORALL

  PRINT *, B
END PROGRAM forall3