program seq
        implicit none
        integer, allocatable, dimension(:,:) :: lineas, mask
        integer :: nlineas = -1
        OPEN (1, file = 'historico.csv')
        DO
            READ (1,*, END=10)
            nlineas = nlineas + 1
        END DO
        10 CLOSE (1)
        allocate(lineas(nlineas,7))
        allocate(mask(nlineas, 7))
end program seq