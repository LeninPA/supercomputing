module gauss_jordan
    implicit none
    contains
    ! Starts gauss-jordan elimination method
    subroutine solve(A, b, n, solution)

        !
        ! Parameters
        !

        integer, intent(in)                 :: n        ! Number of rows
        real, intent(inout), dimension(n,n) :: A        ! Matrix of values
        real, intent(inout), dimension(n)   :: b        ! Vector of results
        logical, intent(out)                :: solution ! Solution exists
        ! Temporal values
        real :: temp, pivot ! Auxiliary variables
        integer :: i,j,k    ! Counters
        ! Initialisations
        solution = .false.

        ! 
        ! Gauss - Jordan elimination
        !
        
        ! Iterate over rows in order to find a no null pivot
        do i = 1,n ! Rows
            ! Naive pivoting
            pivot = A(i,i)
            if ( pivot == 0.0 ) then
                ! Check following rows for a no null pivot
                ! We should not check previous as we would be
                ! risking going backwards on the procedure
                do j = i + 1, n
                    if ( A(j,i) /= 0.0 ) then
                        call swap_rows(A, b, i, j, n)
                        pivot = A(i,i) ! As this value is now different
                        exit ! TODO: Make the selection of pivot more numerically stable
                    end if
                end do
                ! In case no suitable pivot was found
                if ( pivot == 0.0 ) then
                    print *, "No unique solution could be found: Null pivot at row", i
                end if
            end if
            ! Normalization 
            A(i, :) = A(i, :) / pivot ! Can cause problems if naive pivoting
            b(i)    = b(i)    / pivot
            ! Remove coefficients of other rows
            do j = 1, n ! Question: Can where/forall be used?
                ! nth row implies we already did this process
                ! for the (n-1)th row
                if ( j /= i ) then
                    temp = A(j, i) ! Ohhh Toooodles
                    A(j, :) = A(j, :) - temp * A(i, :) ! God bless Fortran
                    b(j)    = b(j)    - temp * b(i)
                end if
            end do
        end do
        ! Check for inconsistency (e.g.: 0x1 = 1)
        do i = 1,n
            if ( all(A(i, :) == 0.0) .and. b(i) /= 0.0 ) then
                solution = .false.
                print *, "No solution could be found: Inconsistent system at row", i
                return
            end if
        end do
        solution = .true.
    end subroutine solve
    subroutine swap_rows(A, b, row1, row2, n)

        !
        ! Parameters
        !

        integer, intent(in)                 :: n         ! Number of rows
        integer, intent(in)                 :: row1,row2 ! Number of rows
        real, intent(inout), dimension(n,n) :: A         ! Matrix of values
        real, intent(inout), dimension(n)   :: b         ! Vector of results
        ! Auxiliary vars
        real, dimension(n)  :: temp_row
        real                :: temp_b

        ! Body
        temp_row = A(row1, :)
        A(row1, :) = A(row2, :)
        A(row2, :) = temp_row

        temp_b = b(row1)
        b(row1) = b(row2)
        b(row2) = b(row1)
    end subroutine swap_rows
end module gauss_jordan

program solver
    use gauss_jordan
    implicit none
    !
    ! Parameters
    !
    integer :: n                        ! Matrix dimension
    integer :: i,j,choice               ! Aux variables
    real, allocatable :: A(:,:), b(:)   ! Matrix and vector of solutions
    logical :: solution                 ! Boolean solution exists
    character(len=100) :: filename      ! Path to matrix file if choice 2
    !
    ! CLI
    !
    print *, "Ax=b solver by Gauss - Jordan"
    print '(A,/,A,/,A)', "1. Interactive", "2. Input from file", "Choice: "
    read *, choice
    if ( choice == 1) then
        ! Interactive mode
        print '(A,/,A)', "You chose interactive CLI", "Enter dimension of the square matrix: "
        read *,n
        if ( n > 0 ) then
            allocate(A(n,n), b(n))
        else
            stop "Non-positive dimension introduced, terminating program"
        end if
        ! Matrix 
        print *, "Input the entries of A (row by row):"
        do i = 1,n
            print *, "Row ", i, ":"
            read *, A(i, :)
            print *, "Row ", i, ":", A(i, :)
        end do
        ! Results
        print *, "Input the entries of b:"
        read *, b
        print *, "b:", b
    elseif( choice == 2 ) then
        ! stop "Not working correctly as of yet"
        ! Input from file
        print '(A,/,A)', "You chose reading from file", "Enter file path: "
        read *, filename
        print *, filename
        ! Reading filename
        open(unit = 10, file = filename, status = 'old', action = 'read')
        read(10, *) n
        allocate( A(n,n) , b(n) )
        do i = 1,n
            read(10, *) A(i,:)
            print *, "Row", i, ":", A(i, :)
        end do
        read(10, *) b
        print *, "b:", b
        close(10)
    else
        stop "Invalid choice"
    end if
    ! Gauss - Jordan
    call solve(A, b, n, solution)
    ! Results
    print *, "Matrix after Gauss - Jordan elimination process:"
    do i = 1,n
        print *, A(i, :)
    end do
    ! Saving matrix
    open(unit = 20, file = 'output.txt', status = 'replace', action = 'write')
        write(20, *) "Matrix after Gauss - Jordan elimination process:"
        do i = 1,n
            write(20, *) A(i, :)
        end do
    if (.not. solution) then
        print *, "No solution could be found"
    else
        print *,"The solution vector x is", b
    end if
    close(20)
    print *, "Output has been saved"
end program solver
