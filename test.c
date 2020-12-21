/**************************************************************
 *  This file uses Fortran function read_double_from_string_  *
 **************************************************************/

# ifdef __cplusplus
extern "C" {
# endif

# include <stdio.h>
# include <string.h>

/*  note  */
/*  for most compilers, Fortran will append a '_' to the name of the function,  */
/*  and uses only lower letters in name of functions.  */
/*  also, please remember that Fortran passes addresses of arguments, but C/C++ passes values,  */
/*  hence if you want to call a Fortran function in a C program, you have to pass pointers for all.  */
void read_double_from_string_(const int *const str_length, const char *const read_str, double *d_number);

void read_fortran_double(const char *const read_str, double *d_number);

int main()
{
    const char splitter[] = " \r\n\t\v";
    FILE *ifp = fopen("input.txt", "rt");

    char buf[BUFSIZ + 1u] = "";
    double d = 0.0;
    char *tok = NULL;

    fgets(buf, BUFSIZ, ifp);
    tok = strtok(buf, splitter);
    while(tok)
    {
        read_fortran_double(tok, & d);
        /*  sscanf(a, "%lf", & d);  */
        printf("%g\n", d);
        tok = strtok(NULL, splitter);
    }

    fclose(ifp);
    ifp = NULL;

    return 0;
}

void read_fortran_double(const char *const read_str, double *d_number)
{
    int len = (int)strlen(read_str);

    read_double_from_string_(& len, read_str, d_number);

    return;
}

# ifdef __cplusplus
}
# endif

