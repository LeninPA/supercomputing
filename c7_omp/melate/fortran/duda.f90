program lineas
nlines = 0
OPEN (1, file = 'historico.csv')
DO
    READ (1,*, END=10)
    nlines = nlines + 1
END DO
10 CLOSE (1)
OPEN (1, file = 'historico.csv')
PRINT *, "Abierto"
CLOSE(1)
print*, nlines
end program lineas
