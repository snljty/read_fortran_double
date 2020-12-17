# Makefile for test

CC      = gcc
FC      = gfortran
FLINKER = $(FC)
FARCH   = ar

all: test.exe

test.exe: test.o static_lib
	$(FLINKER) -o $@ $< -L . -l read_double

test.o: test.c
	$(CC) -o $@ -c $<

read_double.o: read_double.f90
	$(FC) -o $@ -c $<

static_lib: libread_double.a

libread_double.a: read_double.o
	$(FARCH) -rsc $@ $<

.PHONY: clean
clean:
	# -del test.o read_double.o 2>NUL 1>NUL
	# -del test.exe 2>NUL 1>NUL
	# -del libread_double.a 2>NUL 1>NUL
	-rm test.o read_double.o
	-rm test.exe
	-rm libread_double.a

