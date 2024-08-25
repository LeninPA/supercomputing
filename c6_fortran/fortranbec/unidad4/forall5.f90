PROGRAM forall5
  IMPLICIT NONE
  INTEGER, DIMENSION(2, 2, 2) :: A
  INTEGER :: i, j, k

  ! Asignar valores
  FORALL (i = 1:2, j = 1:2, k = 1:2)
    A(i, j, k) = i + j + k
  END FORALL

  PRINT *, A
END PROGRAM forall5