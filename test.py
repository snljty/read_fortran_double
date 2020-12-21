#! /usr/bin/env python3
# -*- Coding: UTF-8 -*-

r"""
This program uses fortran module read_double
"""

import read_double

with open('input.txt') as f:
    l = f.readline()

read_fortran_double = lambda _: read_double.read_double_from_string(len(_), _)

for s in l.strip().split():
    print(read_fortran_double(s))

