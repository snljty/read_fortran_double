@echo off

rem use this script to compile a pyd file, which can be used by python.
rem f2py should have been included in module numpy.
rem please note that under windows, you'd better use libpython and mingw within conda.

f2py -m read_double -c read_double.f90

