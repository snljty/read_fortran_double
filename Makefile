# Makefile for test

CC      = gcc
FC      = gfortran
CLINKER = $(CC)
FLINKER = $(FC)
ARCH   = ar

all: test.exe

test.exe: test.o static_lib
	# you can link with Fortran compiler.
	$(FLINKER) -o $@ $< -L . -l read_double
	# or you can link with C compiler, just add a "-l gfortran" argument.
	# $(CLINKER) -o $@ $< -L . -l read_double -l gfortran

test.o: test.c
	$(CC) -o $@ -c $<

read_double.o: read_double.f90
	$(FC) -o $@ -c $<

static_lib: libread_double.a

libread_double.a: read_double.o
	$(ARCH) -rsc $@ $<

.PHONY: clean
clean:
	# -del test.o read_double.o 2>NUL 1>NUL
	# -del test.exe 2>NUL 1>NUL
	# -del libread_double.a 2>NUL 1>NUL
	-rm test.o read_double.o
	-rm test.exe
	-rm libread_double.a

