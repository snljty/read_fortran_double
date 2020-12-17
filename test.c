/*  This file uses fortran function read_double_from_string_  */

# ifdef __cplusplus
extern "C" {
# endif

# include <stdio.h>
# include <string.h>

void read_double_from_string_(const int *const str_length, const char *const read_str, double *d_number);

int main()
{
    const char splitter[] = " \r\n\t\v";
    FILE *ifp = fopen("input.txt", "rt");

    char buf[BUFSIZ + 1u] = "";
    double d = 0.0;
    int len = 0;
    char *tok = NULL;

    fgets(buf, BUFSIZ, ifp);
    tok = strtok(buf, splitter);
    while(tok)
    {
        len = (int)strlen(tok);
        read_double_from_string_(& len, tok, & d);
        /*  sscanf(a, "%lf", & d);  */
        printf("%g\n", d);
        tok = strtok(NULL, splitter);
    }

    fclose(ifp);
    ifp = NULL;

    return 0;
}

# ifdef __cplusplus
}
# endif

