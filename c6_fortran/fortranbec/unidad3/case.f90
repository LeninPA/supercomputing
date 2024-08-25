program conditionals
    implicit none
 
    integer :: x
 
  read *, x
 
    select case (x)
    case (1)
        print *, "x = 1"
    case (2)
        print *, "x = 2"
    case (3)
        print *, "x = 3"
    case default
        print *, "I don't know"
    end select
end program conditionals
