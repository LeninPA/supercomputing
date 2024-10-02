program secuencial_busqueda_numeros
  implicit none
  integer,parameter :: max_rows = 3959
  integer :: filas_validas(max_rows), aux_filas(max_rows)
  integer :: i, j, n_args, counter
  integer :: R(7), aux_R(7)
  integer :: numeros(7), aux_numeros(7)
  real :: bolsa
  integer :: concurso, nproducto
  character(len=10) :: fecha
  integer :: frecuencia(7)
  character(len=50) :: line
  logical :: encontrado
  ! Variables para leer el archivo CSV
  integer :: unit_id

  ! Inicializar las frecuencias en 0
  frecuencia = 0

  ! Leer los argumentos
  n_args = command_argument_count()
  if (n_args > 7) then
     print *, "Error: El programa solo acepta hasta 7 números."
     stop
  endif

  ! Leer los números pasados como argumentos
  do i = 1, n_args
     call get_command_argument(i, line)
     read(line, *) numeros(i)
     if (numeros(i) < 1 .or. numeros(i) > 56) then
        print *, "Error: Los números deben estar entre 1 y 56."
        stop
     endif
  end do

  ! Ordenar los números
  call sort(numeros(1:n_args))


  ! Abrir el archivo CSV
  open(unit=unit_id, file="historico.csv", status="old", action="read")

  ! Inicializar el contador de filas válidas
  counter = 0

  ! Leer el archivo línea por línea
  do i = 1, max_rows
     read(unit_id, *, iostat=j) nproducto, concurso, R(1), R(2), R(3), R(4), R(5), R(6), R(7), bolsa, fecha
     if (j /= 0) exit

     ! Verificar si el primer número aparece en las columnas R1-R6
     encontrado = .false.
     do j = 1, 6
        if (numeros(1) == R(j)) then
           encontrado = .true.
           frecuencia(1) = frecuencia(1) + 1
           aux_filas(counter+1) = i
           counter = counter + 1
           exit
        endif
     end do
  end do

  ! Cerrar el archivo
  close(unit_id)

  ! Continuar la búsqueda con los demás números, si los hay
  do i = 2, n_args
     call filtrar(aux_filas, counter, numeros(i), aux_R, frecuencia(i))
  end do

  ! Imprimir las frecuencias
  print *, "Frecuencia del primer número: ", frecuencia(1)
  if (n_args > 1) then
     do i = 2, n_args
        print *, "Frecuencia del número ", i, ": ", frecuencia(i)
     end do
  endif

contains
  subroutine sort(array)
     integer, intent(inout) :: array(:)
     integer :: i, j, temp
     do i = 1, size(array)-1
        do j = i+1, size(array)
           if (array(i) > array(j)) then
              temp = array(i)
              array(i) = array(j)
              array(j) = temp
           endif
        end do
     end do
  end subroutine sort

  subroutine filtrar(filas_validas, n_filas, numero, aux_R, frecuencia)
     integer, intent(inout) :: filas_validas(:)
     integer, intent(inout) :: n_filas, frecuencia
     integer, intent(in) :: numero
     integer, intent(in) :: aux_R(:)
     integer :: i, j, new_counter
     new_counter = 0
     do i = 1, n_filas
        encontrado = .false.
        do j = 1, 6
           if (numero == aux_R(j)) then
              encontrado = .true.
              frecuencia = frecuencia + 1
              filas_validas(new_counter + 1) = filas_validas(i)
              new_counter = new_counter + 1
              exit
           endif
        end do
     end do
     n_filas = new_counter
  end subroutine filtrar
end program secuencial_busqueda_numeros
