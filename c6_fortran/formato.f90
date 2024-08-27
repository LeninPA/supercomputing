PROGRAM formato
        CHARACTER(len = 20) :: nombre
        INTEGER             :: edad, iostat1=1,iostat2=1  &
                            ,iostat3=1,iostat4=1,iostat5=1&
                            ,i=1
        REAL                :: altura, peso, ingresos
        DO WHILE (i < 4 .AND. iostat1 /= 0)
            IF (i > 1) THEN
                PRINT *,"Desafortunadamente, el dato &
ingresado no sigue el formato interno &
solicitado. Se le insta (amablemente) a &
seguir las indicaciones y contestar &
adecuadamente."
            END IF
            PRINT *,"Ingresa tu nombre (20 caracteres):"
            READ(*, 100, iostat = iostat1) nombre
            100 format(A20)
            WRITE(*, "(A)", advance="no") "El nombre es: "
            WRITE(*, '(A)') nombre
            PRINT *, iostat1
            i = i + 1
        END DO
        IF (i == 4 .AND. iostat1 /= 0) THEN
            STOP "Lamentando que no se hayan seguido &
las indicaciones, es necesario terminar &
el código en este momento."
        END IF
        i = 1
        DO WHILE (i < 4 .AND. iostat2 /= 0)
            IF (i > 1) THEN
                PRINT *,"Desafortunadamente, el dato &
ingresado no sigue el formato interno &
solicitado. Se le insta (amablemente) a &
seguir las indicaciones y contestar &
adecuadamente.)"
            END IF
            PRINT *,"Ingresa tu edad:"
            READ(*, 110, iostat = iostat2) edad 
            110 format(I3)
            WRITE(*, "(A)", advance="no") "La edad es: "
            WRITE(*, '(I3)') edad
            i = i + 1
            IF (edad < 0 .OR. edad > 120) THEN
                iostat2 = iostat2 + 1
            END IF
        END DO
        IF (i == 4 .AND. iostat2 /= 0) THEN
            STOP "Lamentando que no se hayan seguido &
            las indicaciones, es necesario terminar &
            el código en este momento."
        END IF
        i = 1
        DO WHILE (i < 4 .AND. iostat3 /= 0)
            IF (i > 1) THEN
                PRINT *,"Desafortunadamente, el dato &
ingresado no sigue el formato interno &
solicitado. Se le insta (amablemente) a &
seguir las indicaciones y contestar &
adecuadamente."
            END IF
            PRINT *,"Ingresa tu altura:"
            READ(*, 111, iostat = iostat3) altura
            111 format(f4.2)
            PRINT '(a, f4.2)',"La altura es ", altura
            i = i + 1
            IF (altura >= 100 .OR. altura < 0) THEN
                iostat3 = iostat3 + 1
            END IF
        END DO
        IF (i == 4 .AND. iostat3 /= 0) THEN
            STOP "Lamentando que no se hayan seguido &
            las indicaciones, es necesario terminar &
            el código en este momento."
        END IF
        i = 1
        DO WHILE (i < 4 .AND. iostat4 /= 0)
            IF (i > 1) THEN
                PRINT *,"Desafortunadamente, el dato &
ingresado no sigue el formato interno &
solicitado. Se le insta (amablemente) a &
seguir las indicaciones y contestar &
adecuadamente."
            END IF
            PRINT *,"Ingresa tu peso:"
            READ(*, 112, iostat = iostat4) peso
            112 format(f3.1)
            PRINT '(a, f3.1)',"El peso es: ", peso
            i = i + 1
            IF (peso >= 100 .OR. peso < 0) THEN
                iostat4 = iostat4 + 1
            END IF
        END DO
        IF (i == 4 .AND. iostat4 /= 0) THEN
            STOP "Lamentando que no se hayan seguido &
            las indicaciones, es necesario terminar &
            el código en este momento."
        END IF
        i = 1
        DO WHILE (i < 4 .AND. iostat5 /= 0)
            IF (i > 1) THEN
                PRINT *,"Desafortunadamente, el dato &
ingresado no sigue el formato interno &
solicitado. Se le insta (amablemente) a &
seguir las indicaciones y contestar &
adecuadamente."
            END IF
            PRINT *,"Ingresa tu ingreso:"
            READ(*, 113, iostat = iostat5) ingresos
            113 format(f6.2)
            PRINT '(a, f6.2)',"El ingreso es: ", ingresos
            i = i + 1
            IF (ingresos >= 1000000 .OR. ingresos < 0) THEN
                iostat5 = iostat5 + 1
            END IF
        END DO
        IF (i == 4 .AND. iostat5 /= 0) THEN
            STOP "Lamentando que no se hayan seguido &
            las indicaciones, es necesario terminar &
            el código en este momento."
        END IF
END PROGRAM formato
