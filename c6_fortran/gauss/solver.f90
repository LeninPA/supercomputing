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
    end subroutine solve
end module gauss_jordan

program solver
    use gauss_jordan
    implicit none
end program solver
