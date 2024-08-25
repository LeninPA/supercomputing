program matrices
        INTEGER, DIMENSION (2,3) :: X = RESHAPE ( (/ (i, i=1, 6) /), (/2,3/)), Y = RESHAPE ( (/ 4, 9, 7, 11, 8, 12 /) , (/2,3/) ) 
        !INTEGER, DIMENSION (3,2) :: Z = X + Y
        print *, X
        print *,"--------------------------------"
        print *, Y
        print *, "X=["
        DO i=1,2
                print *,X(i,:)
        END DO
        print *,"]"
        !INTEGER, DIMENSION (4,4) :: Z = RESHAPE ( (/ 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16 /), (/4,4/) )
        !print *, "Z=["
        !DO i=1,4
        !        print *,"a"
        !END DO
        !print *,"]"
end program
