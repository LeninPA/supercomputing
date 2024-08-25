PROGRAM Example1
  INTEGER :: x = 42
  REAL :: y = 3.14
  INTEGER :: unitNumber

  unitNumber = 10
  OPEN(UNIT=unitNumber, FILE='output.txt', STATUS='REPLACE')

  WRITE(unitNumber, '(A, I4)') 'The value of x is:', x
  WRITE(unitNumber, '(A, F6.2)') 'The value of y is:', y

  CLOSE(unitNumber)
END PROGRAM Example1