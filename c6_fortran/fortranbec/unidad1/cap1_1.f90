PROGRAM cap1_1
PRINT*,"Hello world"
!STOP 1
WRITE (*,*) 'HOLA MUNDO' !En Fortran, la sentencia WRITE(unit, format) se utiliza para imprimir
PRINT*,"Hello mundo"
print '(A)', "Hola, world!"
print '(A20)', 'Hello'
!datos en la consola o en un archivo. En este caso, * indica que se está utilizando la unidad de
!salida estándar (normalmente la consola), y * en el formato indica que se debe usar el formato de
!salida predeterminado.
STOP "Goodbye world" ! la sentencia STOP en Fortran es una herramienta para finalizar la
!ejecución de un programa, y opcionalmente se puede proporcionar un código de salida para indicar
!la razón de la detención.
END PROGRAM cap1_1
