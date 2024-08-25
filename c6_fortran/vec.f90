program vec
        INTEGER, DIMENSION (4) :: v1 = 0
        INTEGER, DIMENSION (4,4) :: m2 = 0
        INTEGER :: num
        DO num = 1,4
                v1(num) = 2 ** num
                m2(num, num) = 1
        END DO
        print *, v1
        print *, m2
end program
