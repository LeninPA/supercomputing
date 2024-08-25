PROGRAM where3
  IMPLICIT NONE
  INTEGER, DIMENSION(5) :: X = (/ -1, 2, 3, -4, 5 /)
  INTEGER, DIMENSION(5) :: Y = (/ 0, 1, 2, 3, 4 /)

  WHERE (X > 0)
    WHERE (Y > 2)
      X = X + 10
    END WHERE
  END WHERE

  PRINT *, X
END PROGRAM where3