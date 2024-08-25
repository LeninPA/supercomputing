program declara_arreglos
    implicit none
    integer, dimension(5) :: vec_int,i,j
    real, dimension(4) :: vec_real
    complex, dimension(3) :: vec_complex
    logical, dimension(3) :: vec_logical
    character(len=7), dimension(3) :: vec_char


    vec_int = (/ 1, 2, 3, 4, 5 /)
    print *, "Vector entero:", vec_int
    print *, "Vector entero:", vec_int(1)
    vec_real = (/ 1.0, 2.5, 3.3, 4.8 /) 
    print *, "Vector real:", vec_real

    vec_complex = (/ (1.0, 2.0), (3.0, 4.0), (5.0, 6.0) /)
    print *, "Vector complejo:", vec_complex

    vec_logical = (/ .true., .false., .true. /)
    print *, "Vector lógico:", vec_logical
    
    vec_char = (/ 'Hola   ', 'Mundo  ', 'Fortran' /)
    print *, "Vector de caracteres:", vec_char

end program declara_arreglos

!gfortran -finput-charset=UTF-8 -o mi_programa mi_programa.f90