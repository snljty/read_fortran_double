! this file reads a double from a string.

subroutine read_double_from_string(str_length, read_str, d_number)
    implicit none
    integer(kind=4), intent(in) :: str_length
    character(len=str_length), intent(in) :: read_str
    real(kind=8), intent(out) :: d_number

    read(read_str, *) d_number
    return
end subroutine read_double_from_string

