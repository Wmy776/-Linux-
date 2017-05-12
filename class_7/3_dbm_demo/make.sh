#!/bin/sh

#gcc -o dbm1 -r /usr/include/gdbm-ndbm.h dbm1.c -lgdbm_compat -lgdbm
gcc -o dbm1 -I/usr/include/gdbm dbm1.c -lgdbm
