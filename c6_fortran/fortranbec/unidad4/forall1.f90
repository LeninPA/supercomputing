PROGRAM forall1
  IMPLICIT NONE
  INTEGER, DIMENSION(5) :: A = (/ 1, 2, 3, 4, 5 /)
  INTEGER, DIMENSION(5) :: B = (/ 10, 20, 30, 40, 50 /)
  INTEGER :: i

  FORALL (i = 1:5)
    B(i) = A(i) * B(i)
  END FORALL

  PRINT *, B
END PROGRAM forall1