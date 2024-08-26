PROGRAM formato
        CHARACTER(len = 20) :: nombre
        INTEGER             :: edad, iostat1=1,iostat2=1  &
                            ,iostat3=1,iostat4=1,iostat5=1&
                            ,i=1
        REAL                :: altura, peso, ingresos
        DO WHILE (i < 4 .AND. iostat1 /= 0)
            PRINT *,"Ingresa tu nombre (20 caracteres):"
            READ(*, 100, iostat = iostat1) nombre
            100 format(A20)
            PRINT *, nombre, iostat1
            i = i + 1
        END DO
        i = 1
        DO WHILE (i < 4 .AND. iostat2 /= 0)
            PRINT *,"Ingresa tu edad:"
            READ(*, 110, iostat = iostat2) edad 
            110 format(I2)
            PRINT *, edad, iostat2
            i = i + 1
        END DO
        !PRINT *,"Ingresa tu altura:"
        !READ(*, *, iostat = iostat3) altura 
        !PRINT *,"Ingresa tu peso:"
        !READ(*, *, iostat = iostat4) peso
        !PRINT *,"Ingresa tu ingresos:"
        !READ(*, *, iostat = iostat5) ingresos
END PROGRAM formato
