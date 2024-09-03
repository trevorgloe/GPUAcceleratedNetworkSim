! this is just a test

program calc
    implicit none
    real, dimension(40) :: a
    real :: start
    real :: end
    integer :: numpnts
    integer :: i
    real, allocatable, dimension(:) :: t 
    real :: currtime

    open(unit=10,file='calc_input.in',status='unknown')
    ! read(10,*)a(1), a(2), a(3), a(4), a(5), a(6), a(7), a(8), a(9), a(10) 
    read(10,*) start
    read(10,*) end
    read(10,*) numpnts
    allocate(t(numpnts))

    
    
    do i = 1, numpnts
        currtime = start + (end - start) * i / numpnts
        t(i) = currtime
    end do

    a(11) = 1.0
    print *, start
    print *, end
    print *, numpnts
    print *, t

end program calc