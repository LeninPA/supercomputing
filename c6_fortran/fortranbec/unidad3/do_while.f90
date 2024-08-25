program ciclo_do_while
  implicit none

  ! Declaración de variables
  integer :: numero, suma

  ! Inicialización de la variable suma
  suma = 0

  ! Instrucción inicial al usuario
  print *, 'Introduce números positivos para sumar (introduce un número negativo para finalizar):'

  ! Ciclo DO WHILE
  do
     ! Leer el número introducido por el usuario
     read *, numero

     ! Condición de salida del ciclo
     if (numero < 0) exit

     ! Actualizar la suma
     suma = suma + numero

     ! Imprimir la suma parcial
     print *, 'Suma parcial: ', suma
  end do

  ! Impresión del resultado final
  print *, 'La suma total es: ', suma

end program ciclo_do_while