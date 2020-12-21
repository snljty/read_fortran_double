#! /usr/bin/env python3
# -*- Coding: UTF-8 -*-

r"""
This program uses fortran module read_double
"""

import read_double

l = ' 1.23  0.456E+01   0.789D+02   0.1+110 '

for s in l.strip().split():
    print(read_double.read_double_from_string(len(s), s))

