include 'magic_square.fh'

program magsq
    use msquare
    implicit none
    integer (kind=4) n,i,ierr,num(100)
    integer (kind=4), allocatable :: magicSquare(:,:)
    character (len=6) :: text
    character (len=100) :: filenam, line

!
! Code for getting values from a file
! 

! TODO: Open the file


! TODO: Allocating a matrix for storing the magic square
! as an array of pointers, where each pointer is a row

!
! TODO: Read in the rows from each line
!

! TODO: Inputting integer data into the matrix
!    do i = 1,n
!       write(6,*) ' Enter the elements in row ',i,' separated by blanks and/or linebreaks'
!       read(5,*) magicSquare(i,:)
!    end do


! TODO: Freeing each row separately before freeing the array of pointers


end program magsq

