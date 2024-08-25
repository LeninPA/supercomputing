program escritura
        IMPLICIT NONE
        INTEGER :: i,j, unidad = 1
        INTEGER, DIMENSION(3,4) :: A = 0, B = 0
        INTEGER, DIMENSION(2,3) :: C
        INTEGER, DIMENSION(12)  :: v = (/3, 8, 7, -15, 14, 13, 9, 8, 7, 0, -1, 4/)
        ! Declaración de valores
        A = RESHAPE( v, (/3,4/) )
        B = RESHAPE( v, (/3,4/) )
        ! Inicio programa
        FORALL (i = 1:3, j = 1:4, A(i,j) < 8)
                B(i,j) = 2 * A(i,j)
        END FORALL
        ! Impresión de valores
        print *, "A = ["
        DO i=1,3
                print*, "[", A(i, :), "]"
        END DO
        print *, "]"
        print *, "B = ["
        DO i=1,3
                print*, "[", B(i, :), "]"
        END DO
        print *,"]"
        C = B(2:3, 1:3)
        open(unit = unidad, file = "./escritura.txt", status = 'replace')
        DO i=1,2
                write(unidad,*) C(i,:)
        END DO
        close(unidad)
        print *, "C=["
        DO i=1,2
                print*, "[", C(i, :), "]"
        END DO
        print *,"]"
end program escritura
