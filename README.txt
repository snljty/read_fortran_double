Thanks for the help from zjxitcc.

Sometimes, the Fortran double type can be hard to be read by C/C++/Python. e.g.
0.21E+02           C prefers 2.1E+01, but this is Okay.
0.21D+02           use 'D' to express that this is a double (a.k.a. real(kind=8)) instead of 
                   a float (a.k.a. real(kind=4)), but it is not able to be read by C.
0.21+123           when you set the length of the index to be 2, but it contains at least 3
                   digits, the 'D' or 'E' will be missing, which made it impossible to be
                   recognize by C.

In these cases, even if you deal with it carefully like:

char s[] = "0.21D+03";
char *cp = NULL;
double d;
while (cp = strchr(s, 'D'))
    * cp = 'E';
sscanf(s, "%lf", & d);

It may still get messy and it is not elegant at all.

With this function, you can just compile a libread_double.a, 
use the function 
void read_double_from_string_(const int *const str_length, const char *const read_str, double *d_number);
like:

char s[] = "0.21D+03";
int s_len = (int)strlen(s);
double d;
read_double_from_string_(& s_len, s, & d);

And finally, compile your program (e.g. test.c) using
gcc -o test.exe -L . -l read_double test.c

Note that format like 0.21+123 is a really bad expression and can easily lead to bugs, please avoid it.

The suggested usage can be found in test.c

Also, a python usage is provided. you can use f2py to compile it, and then use in python as:
>>> import read_double
>>> s = "0.21D+03"
>>> read_fortran_double = lambda _: read_double.read_double_from_string(len(_), _)
>>> d = read_fortran_double(s)

